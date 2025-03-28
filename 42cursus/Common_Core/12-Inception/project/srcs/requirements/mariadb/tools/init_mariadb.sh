#!/bin/bash

set -e

apt-get update
apt-get install -y mariadb-server
apt-get clean
rm -rf /var/lib/apt/lists/*

mkdir -p /var/run/mysqld
chown -R mysql:mysql /var/run/mysqld
chmod 700 /var/run/mysqld

service mariadb start

echo "DELETE FROM mysql.user WHERE User='';" | mariadb -u root
echo "DROP DATABASE IF EXISTS test;" | mariadb -u root
echo "DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');" | mariadb -u root
echo "FLUSH PRIVILEGES;" | mariadb -u root
echo "CREATE DATABASE IF NOT EXISTS ${MARIADB_DB_NAME};" | mariadb -u root
echo "\
    GRANT SELECT, INSERT, UPDATE, DELETE, CREATE, ALTER, INDEX, CREATE TEMPORARY TABLES, LOCK TABLES, EXECUTE \
    ON ${MARIADB_DB_NAME}.* \
    TO '${MARIADB_DB_USER}'@'10.0.0.2' \
    IDENTIFIED BY '${MARIADB_DB_PASS}';" \
    | mariadb -u root
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARIADB_ROOT_PASS}';FLUSH PRIVILEGES;" | mariadb -u root
