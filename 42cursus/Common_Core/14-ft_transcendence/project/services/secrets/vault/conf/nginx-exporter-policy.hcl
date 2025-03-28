path "secret/nginx-exporter" {
  capabilities = ["read"]
}

path "pki_int/issue/nginx-exporter" {
  capabilities = ["create", "update"]
}
