path "secret/kibana" {
  capabilities = ["read"]
}

path "pki_int/issue/kibana" {
  capabilities = ["create", "update"]
}
