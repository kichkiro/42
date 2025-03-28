path "secret/postgresql" {
  capabilities = ["read"]
}

path "pki_int/issue/postgresql" {
  capabilities = ["create", "update"]
}
