path "secret/grafana" {
  capabilities = ["read"]
}

path "pki_int/issue/grafana" {
  capabilities = ["create", "update"]
}
