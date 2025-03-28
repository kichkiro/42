#!/usr/bin/bash

set -e

# Get Certs and Secrets from Vault -------------------------------------------->
curl -k -H "X-Vault-Token: $LOGSTASH_VAULT_TOKEN" \
	https://10.0.0.1:8200/v1/pki_int/ca_chain \
	-o /opt/bitnami/logstash/config/ca.crt

envs=$(curl -k -H "X-Vault-Token: ${LOGSTASH_VAULT_TOKEN}" \
	-X GET https://10.0.0.1:8200/v1/secret/logstash)

export LOGSTASH_PIPELINE_CONF_STRING=$(\
	echo "$envs" | jq -r '.data.LOGSTASH_PIPELINE_CONF_STRING')

# Run EntryPoint -------------------------------------------------------------->
exec $0 $@
