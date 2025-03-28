#!/usr/bin/bash

set -e

# Get Certs from Vault -------------------------------------------------------->
if [ ! "$(ls -A /tls/certs/)" ]; then
	certs=$(curl -s -k -H "X-Vault-Token: $PROMETHEUS_VAULT_TOKEN" -X POST -d '{
			"common_name": "prometheus.ft-transcendence.42",
			"ip_sans": "10.0.3.1",
			"ttl": "24h"
		}' https://10.0.0.1:8200/v1/pki_int/issue/prometheus)

	echo "$certs" | jq -r '.data.certificate' > /tls/certs/prometheus.crt
	echo "$certs" | jq -r '.data.private_key' > /tls/private/prometheus.key
	echo "$certs" | jq -r '.data.issuing_ca' > /tls/certs/ca.crt

	chmod 400 /tls/private/prometheus.key
fi

# Write Token to file --------------------------------------------------------->
if [ ! "$(ls -A /opt/bitnami/prometheus/conf/vault-token)" ]; then
	echo $PROMETHEUS_VAULT_TOKEN > /opt/bitnami/prometheus/conf/vault-token
fi

# Run EntryPoint -------------------------------------------------------------->
exec $0 $@
