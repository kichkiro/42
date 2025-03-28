path "secret/postgres-exporter" {
  capabilities = ["read"]
}

path "pki_int/issue/postgres-exporter" {
  capabilities = ["create", "update"]
}
