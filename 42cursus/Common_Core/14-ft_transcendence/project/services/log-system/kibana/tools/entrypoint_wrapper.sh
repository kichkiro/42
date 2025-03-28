#!/usr/bin/bash

set -ex

# Get Certs and Envs from Vault ----------------------------------------------->
if [ ! "$(ls -A /opt/bitnami/kibana/config/tls)"]; then
	mkdir -p /opt/bitnami/kibana/config/tls

	certs=$(curl -k -s -H "X-Vault-Token: $KIBANA_VAULT_TOKEN" -X POST -d '{
			"common_name": "kibana.ft-transcendence.42",
			"ttl": "24h",
			"ip_sans": "10.0.2.3"
		}' https://10.0.0.1:8200/v1/pki_int/issue/kibana)

	echo "$certs" | jq -r '.data.certificate' \
		> /opt/bitnami/kibana/config/tls/kibana.crt
	echo "$certs" | jq -r '.data.private_key' \
		> /opt/bitnami/kibana/config/tls/kibana.key
	echo "$certs" | jq -r '.data.issuing_ca' \
		> /opt/bitnami/kibana/config/tls/ca.crt

	chmod 400 /opt/bitnami/kibana/config/tls/kibana.key
fi

envs=$(curl -k -s -H "X-Vault-Token: $KIBANA_VAULT_TOKEN" \
	-X GET https://10.0.0.1:8200/v1/secret/kibana)

export KIBANA_PASSWORD=$(echo "$envs" | jq -r '.data.KIBANA_PASSWORD')
export KIBANA_HOST=$(echo "$envs" | jq -r '.data.KIBANA_HOST')
export KIBANA_CREATE_USER=$(echo "$envs" | jq -r '.data.KIBANA_CREATE_USER')
export KIBANA_CERTS_DIR=$(echo "$envs" | jq -r '.data.KIBANA_CERTS_DIR')
export KIBANA_SERVER_ENABLE_TLS=$(\
	echo "$envs" | jq -r '.data.KIBANA_SERVER_ENABLE_TLS')
export KIBANA_SERVER_TLS_USE_PEM=$(\
	echo "$envs" | jq -r '.data.KIBANA_SERVER_TLS_USE_PEM')
export KIBANA_SERVER_CERT_LOCATION=$(\
	echo "$envs" | jq -r '.data.KIBANA_SERVER_CERT_LOCATION')
export KIBANA_SERVER_KEY_LOCATION=$(\
	echo "$envs" | jq -r '.data.KIBANA_SERVER_KEY_LOCATION')
export KIBANA_ELASTICSEARCH_URL=$(\
	echo "$envs" | jq -r '.data.KIBANA_ELASTICSEARCH_URL')
export KIBANA_ELASTICSEARCH_PASSWORD=$(\
	echo "$envs" | jq -r '.data.KIBANA_ELASTICSEARCH_PASSWORD')
export KIBANA_ELASTICSEARCH_ENABLE_TLS=$(\
	echo "$envs" | jq -r '.data.KIBANA_ELASTICSEARCH_ENABLE_TLS')
export KIBANA_ELASTICSEARCH_TLS_VERIFICATION_MODE=$(\
	echo "$envs" | jq -r '.data.KIBANA_ELASTICSEARCH_TLS_VERIFICATION_MODE')
export KIBANA_ELASTICSEARCH_TLS_USE_PEM=$(\
	echo "$envs" | jq -r '.data.KIBANA_ELASTICSEARCH_TLS_USE_PEM')
export KIBANA_ELASTICSEARCH_CA_CERT_LOCATION=$(\
	echo "$envs" | jq -r '.data.KIBANA_ELASTICSEARCH_CA_CERT_LOCATION')

# Run EntryPoint in Background ------------------------------------------------>
exec $0 $@ &

# Wait for Kibana ------------------------------------------------------------->
while true; do
	if [ ! "$(curl -k -s --fail https://10.0.2.3:5601)" ]; then
		echo "waiting for kibana ..."
		sleep 1
	else
		break
	fi
done

sleep 60

# Create a DataView ----------------------------------------------------------->
curl -k -s -X POST https://10.0.2.3:5601/api/data_views/data_view \
	-u elastic:$KIBANA_ELASTICSEARCH_PASSWORD \
	-H "Content-Type: application/json;" \
	-H "kbn-xsrf: true" \
	-d '{
		"data_view": {
			"name": "ft-transcendence",
			"title": "logstash-*",
			"timeFieldName": "@timestamp"
		}
	}'

# Wait for the Main Process --------------------------------------------------->
wait
