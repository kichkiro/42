#!/usr/bin/bash

set -e

# Get Certs and Secrets from Vault -------------------------------------------->
if [ ! "$(ls -A /tls/certs/)" ]; then
	certs=$(curl -s -k -H "X-Vault-Token: $GRAFANA_VAULT_TOKEN" -X POST -d '{
			"common_name": "grafana.ft-transcendence.42",
			"ttl": "24h",
			"ip_sans": "10.0.3.2"
		}' https://10.0.0.1:8200/v1/pki_int/issue/grafana)

	echo "$certs" | jq -r '.data.certificate' > /tls/certs/grafana.crt
	echo "$certs" | jq -r '.data.private_key' > /tls/private/grafana.key
	echo "$certs" | jq -r '.data.issuing_ca' > /tls/certs/ca.crt

	chmod 400 /tls/private/grafana.key

	envs=$(curl -s -k -H "X-Vault-Token: ${GRAFANA_VAULT_TOKEN}" \
		-X GET https://10.0.0.1:8200/v1/secret/grafana)

	export GF_SECURITY_ADMIN_USER=$(echo "$envs" | jq -r '.data.GF_SECURITY_ADMIN_USER')
	export GF_SECURITY_ADMIN_PASSWORD=$(echo "$envs" | jq -r '.data.GF_SECURITY_ADMIN_PASSWORD')
fi

# Run EntryPoint in Background ------------------------------------------------>
exec $0 $@ &

# Wait for Grafana ------------------------------------------------------------>
while ! curl -k -o /dev/null -s -H --fail https://10.0.3.2:3000; do
	echo "waiting for grafana ..."
	sleep 1
done

# Set Data Source ------------------------------------------------------------->
auth="$(echo "$envs" | jq -r '.data.GF_SECURITY_ADMIN_USER'):$(echo "$envs" | jq -r '.data.GF_SECURITY_ADMIN_PASSWORD')"
tlsCACert=$(echo "$certs" | jq -r '.data.issuing_ca' | sed ':a;N;$!ba;s/\n/\\n/g')
tlsClientCert=$(echo "$certs" | jq -r '.data.certificate' | sed ':a;N;$!ba;s/\n/\\n/g')
tlsClientKey=$(echo "$certs" | jq -r '.data.private_key' | sed ':a;N;$!ba;s/\n/\\n/g')

curl -k -X POST \
	-H "Content-Type: application/json" \
	-d '{
		"name": "Prometheus",
		"type": "prometheus",
		"url": "https://10.0.3.1:9090",
		"access": "proxy",
		"isDefault": true,
		"basicAuth": true,
		"basicAuthUser": "prometheus",
		"JsonData": {
			"tlsAuthWithCACert": true,
			"tlsAuth": true,
			"serverName": "prometheus.ft-transcendence.42"
		},
		"secureJsonData": {
			"basicAuthPassword": "test",
			"tlsCACert": "'"${tlsCACert}"'",
			"tlsClientCert": "'"${tlsClientCert}"'",
			"tlsClientKey": "'"${tlsClientKey}"'"
		}
	}' \
	https://$auth@10.0.3.2:3000/api/datasources

# Import Dashboards ----------------------------------------------------------->
dashboard_path="/opt/bitnami/grafana/conf/provisioning/dashboards/"
endpoint="https://10.0.3.2:3000/api/dashboards/db"

for FILE in "$dashboard_path"/*.json; do
     dashboard_json=$(cat "$FILE")
     curl -k -X POST "$endpoint" \
          -H "Content-Type: application/json" \
          -u "$auth" \
          -d "{\"dashboard\": $dashboard_json, \"overwrite\": true}"
     sleep 1
done

# Wait for the Main Process --------------------------------------------------->
wait
