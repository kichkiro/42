#!/bin/bash

set -e

apt-get update
apt-get install -y nginx openssl
apt-get clean
rm -rf /var/lib/apt/lists/*
rm -rf /etc/nginx/sites-enabled
rm -rf /etc/nginx/sites-available
openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/kichkiro.42.fr.key \
    -out /etc/ssl/certs/kichkiro.42.fr.crt \
    -subj "/C=IT/ST=Umbria/L=Perugia/O=42/CN=kichkiro.42.fr"
