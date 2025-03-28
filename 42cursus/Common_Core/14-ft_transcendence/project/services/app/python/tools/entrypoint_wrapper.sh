#!/usr/bin/bash

# Get Certs and Envs from Vault ----------------------------------------------->
if [ ! "$(ls -A /tls/certs)"]; then
    certs=$(curl -k -H "X-Vault-Token: $PYTHON_VAULT_TOKEN" -X POST -d '{
            "common_name": "python.ft-transcendence.42",
            "ip_sans": "10.0.1.1",
            "ttl": "24h"
        }' https://10.0.0.1:8200/v1/pki_int/issue/python)

    echo "$certs" | jq -r '.data.certificate' > /tls/certs/python.crt
    echo "$certs" | jq -r '.data.private_key' > /tls/private/python.key
    echo "$certs" | jq -r '.data.issuing_ca' > /tls/certs/ca.crt
    echo "$certs" | jq -r '.data.ca_chain[]' > /tls/certs/ca_chain.crt

    chmod 400 /tls/private/python.key
fi

envs=$(curl -k -H "X-Vault-Token: ${PYTHON_VAULT_TOKEN}" \
    -X GET https://10.0.0.1:8200/v1/secret/python)

export PYTHONPATH=$(echo "$envs" | jq -r '.data.PYTHONPATH')
export DB_HOST=$(echo "$envs" | jq -r '.data.DB_HOST')
export DB_PORT=$(echo "$envs" | jq -r '.data.DB_PORT')
export DB_NAME=$(echo "$envs" | jq -r '.data.DB_NAME')
export DB_USER=$(echo "$envs" | jq -r '.data.DB_USER')
export DB_PASSWORD=$(echo "$envs" | jq -r '.data.DB_PASSWORD')
export DB_TLS=$(echo "$envs" | jq -r '.data.DB_TLS')
export TLS_CERT_FILE=$(echo "$envs" | jq -r '.data.TLS_CERT_FILE')
export TLS_KEY_FILE=$(echo "$envs" | jq -r '.data.TLS_KEY_FILE')
export TLS_CA_FILE=$(echo "$envs" | jq -r '.data.TLS_CA_FILE')

# Waiting for the availability of Postgresql ---------------------------------->
success_msg="Connection to $DB_HOST $DB_PORT port [tcp/*] succeeded!"

while true; do
    out=$(nc -zv $DB_HOST $DB_PORT 2>&1)
    if [[ "$out" == *"$success_msg"* ]]; then
        echo "$success_msg"
        break
    else
        echo "Connection to $DB_HOST $DB_PORT port [tcp/*] failed. Retry ..."
    fi
    sleep 1
done

# Collect static files -------------------------------------------------------->
python pong_project/manage.py makemigrations
python pong_project/manage.py migrate
python pong_project/manage.py collectstatic --noinput

# Start Gunicorn server ------------------------------------------------------->
eval exec $0 $@
