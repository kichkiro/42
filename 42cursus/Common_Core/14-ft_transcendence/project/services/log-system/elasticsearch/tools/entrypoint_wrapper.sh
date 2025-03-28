#!/usr/bin/bash

set -ex

# Get Certs and Envs from Vault ----------------------------------------------->
if [ ! "$(ls -A /opt/bitnami/elasticsearch/config/tls)"]; then
	mkdir -p /opt/bitnami/elasticsearch/config/tls

	certs=$(curl -k -s -H "X-Vault-Token: $ELASTICSEARCH_VAULT_TOKEN" -X POST -d '{
			"common_name": "elasticsearch.ft-transcendence.42",
			"ip_sans": "10.0.2.1",
			"ttl": "24h"
		}' https://10.0.0.1:8200/v1/pki_int/issue/elasticsearch)

	echo "$certs" | jq -r '.data.certificate' \
		> /opt/bitnami/elasticsearch/config/tls/elasticsearch.crt
	echo "$certs" | jq -r '.data.private_key' \
		> /opt/bitnami/elasticsearch/config/tls/elasticsearch.key
	echo "$certs" | jq -r '.data.issuing_ca' \
		> /opt/bitnami/elasticsearch/config/tls/ca.crt

	chmod 400 /opt/bitnami/elasticsearch/config/tls/elasticsearch.key
fi

envs=$(curl -k -s -H "X-Vault-Token: ${ELASTICSEARCH_VAULT_TOKEN}" \
	-X GET https://10.0.0.1:8200/v1/secret/elasticsearch)

export ELASTICSEARCH_PASSWORD=$(\
	echo "$envs" | jq -r '.data.ELASTICSEARCH_PASSWORD')
export ELASTICSEARCH_ENABLE_SECURITY=$(\
	echo "$envs" | jq -r '.data.ELASTICSEARCH_ENABLE_SECURITY')
export ELASTICSEARCH_ENABLE_REST_TLS=$(\
	echo "$envs" | jq -r '.data.ELASTICSEARCH_ENABLE_REST_TLS')
export ELASTICSEARCH_TLS_USE_PEM=$(\
	echo "$envs" | jq -r '.data.ELASTICSEARCH_TLS_USE_PEM')
export ELASTICSEARCH_TLS_VERIFICATION_MODE=$(\
	echo "$envs" | jq -r '.data.ELASTICSEARCH_TLS_VERIFICATION_MODE')
export ELASTICSEARCH_HTTP_TLS_USE_PEM=$(\
	echo "$envs" | jq -r '.data.ELASTICSEARCH_HTTP_TLS_USE_PEM')
export ELASTICSEARCH_HTTP_TLS_NODE_CERT_LOCATION=$(\
	echo "$envs" | jq -r '.data.ELASTICSEARCH_HTTP_TLS_NODE_CERT_LOCATION')
export ELASTICSEARCH_HTTP_TLS_NODE_KEY_LOCATION=$(\
	echo "$envs" | jq -r '.data.ELASTICSEARCH_HTTP_TLS_NODE_KEY_LOCATION')
export ELASTICSEARCH_HTTP_TLS_CA_CERT_LOCATION=$(\
	echo "$envs" | jq -r '.data.ELASTICSEARCH_HTTP_TLS_CA_CERT_LOCATION')
export ELASTICSEARCH_SKIP_TRANSPORT_TLS=$(\
	echo "$envs" | jq -r '.data.ELASTICSEARCH_SKIP_TRANSPORT_TLS')

# Run EntryPoint in Background ------------------------------------------------>
exec $0 $@ &

# Wait for Elasticsearch ------------------------------------------------------>
while true; do
	if [ ! "$(curl -k -u elastic:$ELASTICSEARCH_PASSWORD --fail https://10.0.2.1:9200)" ]; then
		echo "waiting for elasticsearch ..."
		sleep 1
	else
		break
	fi
done

sleep 60

# Create ILM Policy ----------------------------------------------------------->
curl -k -s -X PUT 'https://10.0.2.1:9200/_ilm/policy/ft-transcendence-policy' \
     -u elastic:$ELASTICSEARCH_PASSWORD \
     -H 'Content-Type: application/json' \
     -d '{
			"policy": {
				"_meta": {
					"description": "used for ft-transcendence logs",
					"project": {
						"name": "ft-transcendence"
					}
				},
				"phases": {
					"hot": {
						"min_age": "0ms",
						"actions": {
							"set_priority": {
								"priority": 100
							}
						}
					},
					"delete": {
						"min_age": "1h",
						"actions": {
							"delete": {
								"delete_searchable_snapshot": true
							}
						}
					}
				}
			}
		}'

# Create a Index Template ----------------------------------------------------->
curl -k -s -X PUT "https://10.0.2.1:9200/_index_template/ft-transcendence-logs?pretty" \
     -u elastic:$ELASTICSEARCH_PASSWORD \
     -H 'Content-Type: application/json' \
     -d '{
			"index_patterns": [
				"logs-*-*"
			],
			"template": {
				"settings": {
					"index": {
						"lifecycle": {
							"name": "ft-transcendence-policy"
						}
					}
				}
			},
			"composed_of": [
				"logs@mappings",
				"logs@settings",
				"ecs@mappings"
			],
			"priority": 100000,
			"data_stream": {
				"hidden": false,
				"allow_custom_routing": false
			},
			"allow_auto_create": true
	 	}'

# Wait for the Main Process --------------------------------------------------->
wait
