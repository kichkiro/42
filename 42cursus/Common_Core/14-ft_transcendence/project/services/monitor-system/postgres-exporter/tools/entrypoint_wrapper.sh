#!/usr/bin/bash

set -e

# Get Certs and Envs from Vault ----------------------------------------------->
if [ ! "$(ls -A /tls/certs/)" ]; then
	certs=$(curl -k -H "X-Vault-Token: $POSTGRES_EXPORTER_VAULT_TOKEN" -X POST -d '{
			"common_name": "postgres-exporter.ft-transcendence.42",
			"ip_sans": "10.0.3.4",
			"ttl": "24h"
		}' https://10.0.0.1:8200/v1/pki_int/issue/postgres-exporter)

	echo "$certs" | jq -r '.data.certificate' > /tls/certs/postgres-exporter.crt
	echo "$certs" | jq -r '.data.private_key' > /tls/private/postgres-exporter.key
	echo "$certs" | jq -r '.data.issuing_ca' > /tls/certs/ca.crt
	echo "$certs" | jq -r '.data.ca_chain[]' > /tls/certs/ca_chain.crt

	chmod 400 /tls/private/postgres-exporter.key

	envs=$(curl -k -H "X-Vault-Token: ${POSTGRES_EXPORTER_VAULT_TOKEN}" \
		-X GET https://10.0.0.1:8200/v1/secret/postgres-exporter)

	export DATA_SOURCE_URI=$(echo "$envs" | jq -r '.data.DATA_SOURCE_URI')
	export DATA_SOURCE_USER=$(echo "$envs" | jq -r '.data.DATA_SOURCE_USER')
	export DATA_SOURCE_PASS=$(echo "$envs" | jq -r '.data.DATA_SOURCE_PASS')
fi

# Run EntryPoint -------------------------------------------------------------->
exec $0 $@
