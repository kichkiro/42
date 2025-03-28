path "secret/elasticsearch" {
  capabilities = ["read"]
}

path "pki_int/issue/elasticsearch" {
  capabilities = ["create", "update"]
}
