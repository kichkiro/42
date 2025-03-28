#!/usr/bin/bash

set -e

# Get Certs from Vault -------------------------------------------------------->
if [ ! "$(ls -A /tls/certs/)" ]; then
	certs=$(curl -k -H "X-Vault-Token: $NGINX_VAULT_TOKEN" -X POST -d '{
			"common_name": "ft-transcendence.42",
			"ip_sans": "10.0.4.1",
			"ttl": "24h"
		}' https://10.0.0.1:8200/v1/pki_int/issue/nginx)

	echo "$certs" | jq -r '.data.certificate' > /tls/certs/nginx.crt
	echo "$certs" | jq -r '.data.private_key' > /tls/private/nginx.key
	echo "$certs" | jq -r '.data.issuing_ca' > /tls/certs/ca.crt
	echo "$certs" | jq -r '.data.ca_chain[]' > /tls/certs/ca_chain.crt

	chmod 400 /tls/private/nginx.key
fi

# Run EntryPoint -------------------------------------------------------------->
exec nginx -g 'daemon off;'
