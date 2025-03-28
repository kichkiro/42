path "pki_int/issue/prometheus" {
  capabilities = ["create", "update"]
}

path "/sys/metrics" {
  capabilities = ["read"]
}
