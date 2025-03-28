#!/usr/bin/bash

set -e

# Get Certs from Vault -------------------------------------------------------->
if [ ! "$(ls -A /tls/certs/)" ]; then
	certs=$(curl -s -k -H "X-Vault-Token: $NGINX_EXPORTER_VAULT_TOKEN" -X POST -d '{
			"common_name": "nginx-exporter.ft-transcendence.42",
			"ip_sans": "10.0.3.3",
			"ttl": "24h"
		}' https://10.0.0.1:8200/v1/pki_int/issue/nginx-exporter)

	echo "$certs" | jq -r '.data.certificate' > /tls/certs/nginx-exporter.crt
	echo "$certs" | jq -r '.data.private_key' > /tls/private/nginx-exporter.key
	echo "$certs" | jq -r '.data.issuing_ca' > /tls/certs/ca.crt
	echo "$certs" | jq -r '.data.ca_chain[]' > /tls/certs/ca_chain.crt

	chmod 400 /tls/private/nginx-exporter.key
fi

# Run EntryPoint -------------------------------------------------------------->
exec $0 $@
