#!/bin/bash

set -e

# Defines --------------------------------------------------------------------->
WHITE_B='\033[1;37m'
BLUE='\033[0;34m'
NC='\033[0m'

# Create Setup Container ------------------------------------------------------>
echo -e "\n$BLUE[+] Creating a container for vault setup"
# Create TMP Directory ------------------------------------------------------->>
mkdir -p setup/.tmp
echo -e "$BLUE    - Created$WHITE_B .tmp$BLUE directoy"

# Create Network ------------------------------------------------------------->>
docker network inspect secrets >/dev/null 2>&1 || docker network create \
	--driver bridge \
	--subnet 10.0.0.0/24 \
	--gateway 10.0.0.254 \
	secrets > /dev/null

echo -e "$BLUE    - Created$WHITE_B secrets$BLUE network"

# Create Volume -------------------------------------------------------------->>
docker volume create vault > /dev/null
echo -e "$BLUE    - Created$WHITE_B vault$BLUE volume"

# Create Container ----------------------------------------------------------->>
docker create \
	--name vault-setup \
	--env VAULT_ADDR=http://10.0.0.1:8200 \
	--cap-add IPC_LOCK \
	--network secrets \
	--ip 10.0.0.1 \
	-p 8200:8200 \
	--mount source=vault,target=/bitnami/vault \
	--entrypoint "vault" \
	bitnami/vault:1.17.5 server -config=/tmp/setup_vault.json > /dev/null 2>&1

echo -e "$BLUE    - Created$WHITE_B vault-setup$BLUE container"

# Copy Configfile ------------------------------------------------------------>>
docker cp setup/setup_vault.json vault-setup:/tmp/setup_vault.json > /dev/null
echo -e "$BLUE    - Copy$WHITE_B setup/setup_vault.json$BLUE to$WHITE_B vault-setup:/tmp/setup_vault.json"

# Start Container ------------------------------------------------------------>>
docker start vault-setup > /dev/null
echo -e "$BLUE    - Started$WHITE_B vault-setup$BLUE container"

# Change Ownership of Volume ------------------------------------------------->>
docker exec --user=root vault-setup chown -R vault:root /bitnami/vault \
	> /dev/null

echo -e "$BLUE    - Changed ownership of$WHITE_B vault-setup$BLUE container to$WHITE_B vault:root"

# Install Utilities ---------------------------------------------------------->>
docker exec --user=root vault-setup apt-get update > /dev/null 2>&1 \
	&& apt-get install -y jq > /dev/null 2>&1

echo -e "$BLUE    - Installed utilities to$WHITE_B vault-setup$BLUE container"

# Initialize Vault ------------------------------------------------------------>
echo -e "\n$BLUE[+] Vault initialization"
# Get Unseal Keys and Root Token --------------------------------------------->>
keys=$(docker exec vault-setup vault operator init)
key1=$(echo "$keys" | grep 'Unseal Key 1:' | awk '{print $4}')
key2=$(echo "$keys" | grep 'Unseal Key 2:' | awk '{print $4}')
key3=$(echo "$keys" | grep 'Unseal Key 3:' | awk '{print $4}')
key4=$(echo "$keys" | grep 'Unseal Key 4:' | awk '{print $4}')
key5=$(echo "$keys" | grep 'Unseal Key 5:' | awk '{print $4}')
root_token=$(echo "$keys" | grep 'Initial Root Token:' | awk '{print $4}')

echo -e "$BLUE    - Vault initialized. Here are the keys and the root token:"
echo -e "$BLUE        - UNSEAL KEY 1: $WHITE_B$key1"
echo -e "$BLUE        - UNSEAL KEY 2: $WHITE_B$key2"
echo -e "$BLUE        - UNSEAL KEY 3: $WHITE_B$key3"
echo -e "$BLUE        - UNSEAL KEY 4: $WHITE_B$key4"
echo -e "$BLUE        - UNSEAL KEY 5: $WHITE_B$key5"
echo -e "$BLUE        - ROOT TOKEN:   $WHITE_B$root_token"

# Unseal Vault --------------------------------------------------------------->>
docker exec vault-setup vault operator unseal $key1 > /dev/null 2>&1
docker exec vault-setup vault operator unseal $key2 > /dev/null 2>&1
docker exec vault-setup vault operator unseal $key3 > /dev/null 2>&1
echo -e "$BLUE    - The vault has been unsealed"

# Generate Root CA ------------------------------------------------------------>
echo -e "\n$BLUE[+] Creating Root CA"
# Enable PKI Engine for Root CA Certificate ---------------------------------->>
docker exec -e VAULT_TOKEN=$root_token vault-setup \
	vault secrets enable -path=pki pki > /dev/null

docker exec -e VAULT_TOKEN=$root_token vault-setup \
	vault secrets tune -max-lease-ttl=87600h pki > /dev/null

echo -e "$BLUE    - Enabled the pki secrets engine for root CA at:$WHITE_B pki/"

# Generate Root CA Certificate ----------------------------------------------->>
docker exec -e VAULT_TOKEN=$root_token vault-setup \
	vault write -field=certificate pki/root/generate/internal \
	common_name="ft-transcendence.42" issuer_name="root-2024" ttl=87600h \
	> /dev/null

echo -e "$BLUE    - Generated root CA certificate"

# Create a Role for the Root CA ---------------------------------------------->>
docker exec -e VAULT_TOKEN=$root_token vault-setup \
	vault write pki/roles/2024-servers allow_any_name=true > /dev/null

echo -e "$BLUE    - Created a role for the root CA"

# Set Endpoint for CA and CRL ------------------------------------------------>>
docker exec -e VAULT_TOKEN=$root_token vault-setup \
	vault write pki/config/urls \
	issuing_certificates="https://10.0.0.1:8200/v1/pki/ca" \
	crl_distribution_points="https://10.0.0.1:8200/v1/pki/crl" > /dev/null

echo -e "$BLUE    - Configured endpoints for CA certificates:\n \
       - crl_distribution_points:$WHITE_B https://10.0.0.1:8200/v1/pki/crl$BLUE\n \
       - issuing_certificates:$WHITE_B    https://10.0.0.1:8200/v1/pki/ca"

# Generate Intermediate CA ---------------------------------------------------->
echo -e "\n$BLUE[+] Creating Intermediate CA"
# Create TLS and Config Directories ------------------------------------------>>
docker exec vault-setup mkdir -p /bitnami/vault/tls
docker exec vault-setup mkdir -p /bitnami/vault/config

# Enable PKI Engine for Intermediate CA Certificate -------------------------->>
docker exec -e VAULT_TOKEN=$root_token vault-setup \
	vault secrets enable -path=pki_int pki > /dev/null

docker exec -e VAULT_TOKEN=$root_token vault-setup \
	vault secrets tune -max-lease-ttl=43800h pki_int > /dev/null

echo -e "$BLUE    - Enabled the pki secrets engine for intermediate CA at:$WHITE_B pki_int/"

# Generate CSR for Intermediate CA Certificate ------------------------------->>
docker exec -e VAULT_TOKEN=$root_token vault-setup \
	vault write -format=json pki_int/intermediate/generate/internal \
	common_name="ft-transcendence.42 Intermediate Authority" \
	issuer_name="ft-transcendence-42-intermediate" \
	| jq -r '.data.csr' > setup/.tmp/pki_intermediate.csr

docker cp setup/.tmp/pki_intermediate.csr \
	vault-setup:/tmp/pki_intermediate.csr > /dev/null

echo -e "$BLUE    - Generated CSR for intermediate CA certificate"

# Sign the Intermediate Certificate with the Root CA ------------------------->>
docker exec -e VAULT_TOKEN=$root_token vault-setup \
	vault write -format=json pki/root/sign-intermediate \
	issuer_ref="root-2024" \
	csr=@/tmp/pki_intermediate.csr \
	format=pem_bundle ttl="43800h" \
	| jq -r '.data.certificate' > setup/.tmp/intermediate.cert.pem

docker cp setup/.tmp/intermediate.cert.pem \
	vault-setup:/bitnami/vault/tls/intermediate.cert.pem > /dev/null

echo -e "$BLUE    - Signed intermediate CA with root CA private key"

# Set Endpoint for CA and CRL ------------------------------------------------>>
docker exec -e VAULT_TOKEN=$root_token vault-setup \
	vault write pki_int/config/urls \
	issuing_certificates="https://10.0.0.1:8200/v1/pki_int/ca" \
	crl_distribution_points="https://10.0.0.1:8200/v1/pki_int/crl" > /dev/null

echo -e "$BLUE    - Configured endpoints for CA certificates:\n \
       - crl_distribution_points:$WHITE_B https://10.0.0.1:8200/v1/pki_int/crl$BLUE\n \
       - issuing_certificates:$WHITE_B    https://10.0.0.1:8200/v1/pki_int/ca"

# Import signed Intermediate CA Certificate into vault ----------------------->>
docker exec -e VAULT_TOKEN=$root_token vault-setup \
	vault write pki_int/intermediate/set-signed \
	certificate=@/bitnami/vault/tls/intermediate.cert.pem > /dev/null

echo -e "$BLUE    - Import signed intermediate CA certificate"

# Create a Role for the Intermediate CA -------------------------------------->>
docker exec -e VAULT_TOKEN=$root_token vault-setup \
	vault write pki_int/roles/ft-transcendence-42 \
	allowed_domains="ft-transcendence.42" \
	allow_subdomains=true\
	max_ttl="720h" > /dev/null

echo -e "$BLUE    - Created a role for the intermediate CA"

# Create TLS Certificates for vault ------------------------------------------->
docker exec -e VAULT_TOKEN=$root_token vault-setup \
	vault write -format=json pki_int/issue/ft-transcendence-42 \
	common_name="vault.ft-transcendence.42" ip_sans="10.0.0.1" ttl="24h"\
	> setup/.tmp/vault-cert.json

jq -r '.data.certificate' setup/.tmp/vault-cert.json > setup/.tmp/vault.crt
jq -r '.data.private_key' setup/.tmp/vault-cert.json > setup/.tmp/vault.key
docker cp setup/.tmp/vault.crt vault-setup:/bitnami/vault/tls/vault.crt > /dev/null
docker cp setup/.tmp/vault.key vault-setup:/bitnami/vault/tls/vault.key > /dev/null
echo -e "\n$BLUE[+] Created certificates for vault-setup"

docker cp services/secrets/vault/conf/vault.hcl \
	vault-setup:/bitnami/vault/config/vault.hcl > /dev/null

# Import Secrets -------------------------------------------------------------->
echo -e "\n$BLUE[+] Import secrets" 
# Enable KV Secrets Engine --------------------------------------------------->>
docker exec -e VAULT_TOKEN=$root_token vault-setup \
	vault secrets enable -path=secret kv >/dev/null 2>&1

echo -e "$BLUE    - Enabled the kv secrets engine at:$WHITE_B secret/"

# Import Secrets to Vault ---------------------------------------------------->>
containers=("python" "postgresql" "elasticsearch" "logstash" "kibana" "grafana" 
	"postgres-exporter" "nginx-exporter")

echo -e "$BLUE - Import secrets to vault:"

for container in "${containers[@]}"; do
	docker exec -e VAULT_TOKEN=$root_token -i vault-setup \
		vault kv put secret/$container - \
		<<< "$(jq -r ".${container//-/_}" ./.env.json)" > /dev/null
    echo -e "$BLUE    - Add$WHITE_B ${container//-/_}$BLUE secrets at $WHITE_B/secret/$container"
done

# Create Roles ---------------------------------------------------------------->
declare -A roles
roles=(
    ["python"]="python.ft-transcendence.42"
    ["postgresql"]="postgresql.ft-transcendence.42"
    ["elasticsearch"]="elasticsearch.ft-transcendence.42"
    ["kibana"]="kibana.ft-transcendence.42"
    ["prometheus"]="prometheus.ft-transcendence.42"
    ["grafana"]="grafana.ft-transcendence.42"
    ["postgres-exporter"]="postgres-exporter.ft-transcendence.42"
    ["nginx-exporter"]="nginx-exporter.ft-transcendence.42"
    ["nginx"]="ft-transcendence.42"
)

echo -e "\n$BLUE[+] Creating roles:"

for role in "${!roles[@]}"; do
    allowed_domain="${roles[$role]}"
    docker exec -e VAULT_TOKEN=$root_token vault-setup \
        vault write pki_int/roles/$role \
        allowed_domains="$allowed_domain" \
        allow_subdomains=false allow_bare_domains=true \
        max_ttl="24h" > /dev/null
	echo -e "$BLUE    - Created role for$WHITE_B $role$BLUE with domain$WHITE_B $allowed_domain"
done

# Create Policies ------------------------------------------------------------->
echo -e "\n$BLUE[+] Creating policies:"

for policy_file in services/secrets/vault/conf/*-policy.hcl; do
	file_name=$(basename "$policy_file")
	docker cp "$policy_file" vault-setup:/bitnami/vault/config/"$file_name" \
		> /dev/null
	docker exec -e VAULT_TOKEN=$root_token vault-setup \
		vault policy write ${file_name::-4} /bitnami/vault/config/$file_name \
		> /dev/null
	echo -e "$BLUE    - add$WHITE_B ${file_name::-4}"   
done

# Create Tokens --------------------------------------------------------------->
declare -A policies=(
    ["python"]="python-policy"
    ["postgresql"]="postgresql-policy"
    ["elasticsearch"]="elasticsearch-policy"
    ["logstash"]="logstash-policy"
    ["kibana"]="kibana-policy"
    ["prometheus"]="prometheus-policy"
    ["grafana"]="grafana-policy"
    ["postgres-exporter"]="postgres-exporter-policy"
    ["nginx-exporter"]="nginx-exporter-policy"
    ["nginx"]="nginx-policy"
)

declare -A tokens

echo -e "\n$BLUE[+] Creating tokens with access to:"

for service in "${!policies[@]}"; do
    policy="${policies[$service]}"
    tokens[$service]=$(docker exec -e VAULT_TOKEN=$root_token vault-setup \
        vault token create -policy="$policy" -format=json | jq -r .auth.client_token)
    echo -e "    $WHITE_B/secret/$service$BLUE: $WHITE_B${tokens[$service]}"
	service_format="${service//-/_}"
	service_format="${service_format^^}"
    echo -e "${service_format}_VAULT_TOKEN=${tokens[$service]}" >> .env
done

# Create Client Certificate for host------------------------------------------->
echo -e "\n$BLUE[+] Creating certificate for host"
## Create role for host ------------------------------------------------------>>
docker exec -e VAULT_TOKEN=$root_token vault-setup \
	vault write pki_int/roles/host-client \
	allow_any_name=true \
	max_ttl="24h" > /dev/null

echo -e "$BLUE    - Created role for$WHITE_B host-client $NC"

## Create certificate for host ----------------------------------------------->>
response=$(curl -k -s -o -X POST \
	-H "X-Vault-Token: $root_token" \
	-H "Content-Type: application/json" \
	-d '{
		"common_name": "host-client",
		"ttl": "24h"
	}' http://10.0.0.1:8200/v1/pki_int/issue/host-client)

echo -e "$BLUE    - Created certifcate for$WHITE_B host-client$NC"

## Create a keystore --------------------------------------------------------->>
echo "$response" | jq -r '.data.certificate' > setup/.tmp/host-client.crt
echo "$response" | jq -r '.data.private_key' > setup/.tmp/host-client.key
echo "$response" | jq -r '.data.ca_chain[0]' > setup/.tmp/host-client-ca.crt

openssl pkcs12 \
	-export \
    -in setup/.tmp/host-client.crt \
    -inkey setup/.tmp/host-client.key \
    -out client_host.p12 \
    -name ft-transcendence-host-client \
    -CAfile setup/.tmp/host-client-ca.crt \
    -caname root

echo -e "$BLUE    - Created keystore at$WHITE_B project/client_host.p12"

# Cleanup --------------------------------------------------------------------->
echo -e "\n$BLUE[+] Clenaup"

docker container stop vault-setup >/dev/null
docker container rm vault-setup >/dev/null
docker network rm secrets >/dev/null
rm -rf setup/.tmp

# Create Vault Container ------------------------------------------------------>
echo -e "\n$BLUE[+] Compose$WHITE_B SECRETS$BLUE profile ..."
docker compose -p "ft_transcendence" --profile secrets up -d

# Unseal Vault ---------------------------------------------------------------->
docker exec vault vault operator unseal $key1 >/dev/null
docker exec vault vault operator unseal $key2 >/dev/null
docker exec vault vault operator unseal $key3 >/dev/null

echo -e "\n$BLUE[+] The vault has been unsealed"
