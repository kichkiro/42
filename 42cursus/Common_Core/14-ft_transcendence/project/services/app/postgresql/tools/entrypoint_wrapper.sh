#!/usr/bin/bash

set -e

# Get Certs and Envs from Vault ----------------------------------------------->
if [ ! "$(ls -A /tls/certs/)" ]; then
	certs=$(curl -k -H "X-Vault-Token: $POSTGRESQL_VAULT_TOKEN" -X POST -d '{
			"common_name": "postgresql.ft-transcendence.42",
			"ip_sans": "10.0.1.2",
			"ttl": "24h"
		}' https://10.0.0.1:8200/v1/pki_int/issue/postgresql)

	echo "$certs" | jq -r '.data.certificate' > /tls/certs/postgresql.crt
	echo "$certs" | jq -r '.data.private_key' > /tls/private/postgresql.key
	echo "$certs" | jq -r '.data.issuing_ca' > /tls/certs/ca.crt
	echo "$certs" | jq -r '.data.ca_chain[]' > /tls/certs/ca_chain.crt

	chmod 400 /tls/private/postgresql.key
fi

envs=$(curl -k -H "X-Vault-Token: ${POSTGRESQL_VAULT_TOKEN}" \
	-X GET https://10.0.0.1:8200/v1/secret/postgresql)

export POSTGRESQL_USERNAME=$(echo "$envs" | jq -r '.data.POSTGRESQL_USERNAME')
export POSTGRESQL_PASSWORD=$(echo "$envs" | jq -r '.data.POSTGRESQL_PASSWORD')
export POSTGRESQL_DATABASE=$(echo "$envs" | jq -r '.data.POSTGRESQL_DATABASE')
export POSTGRESQL_ENABLE_TLS=$(echo "$envs" | jq -r '.data.POSTGRESQL_ENABLE_TLS')
export POSTGRESQL_TLS_CERT_FILE=$(echo "$envs" | jq -r '.data.POSTGRESQL_TLS_CERT_FILE')
export POSTGRESQL_TLS_KEY_FILE=$(echo "$envs" | jq -r '.data.POSTGRESQL_TLS_KEY_FILE')
export POSTGRESQL_TLS_CA_FILE=$(echo "$envs" | jq -r '.data.POSTGRESQL_TLS_CA_FILE')
export POSTGRESQL_EXTRA_FLAGS=$(echo "$envs" | jq -r '.data.POSTGRESQL_EXTRA_FLAGS')

# Run EntryPoint -------------------------------------------------------------->
exec $0 $@
