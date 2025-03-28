#!/bin/bash

set -e

apt-get update
apt-get install -y php7.4-fpm php7.4-mysql wget
apt-get clean
rm -rf /var/lib/apt/lists/*

wget https://wordpress.org/wordpress-6.5.5.tar.gz
tar -xzf wordpress-6.5.5.tar.gz
mkdir -p /var/www/html
mv wordpress/* /var/www/html/
rm -rf wordpress wordpress-6.5.5.tar.gz

mkdir -p /run/php
chown -R www-data:www-data /run/php
chmod -R 600 /run/php
chown -R www-data:www-data /var/www/html/
chmod -R 600 /var/www/html

sed -i "s/database_name_here/${MARIADB_DB_NAME}/g" "/var/www/html/wp-config-sample.php"
sed -i "s/username_here/${MARIADB_DB_USER}/g" "/var/www/html/wp-config-sample.php"
sed -i "s/password_here/${MARIADB_DB_PASS}/g" "/var/www/html/wp-config-sample.php"
sed -i "s/localhost/10.0.0.3:3306/g" "/var/www/html/wp-config-sample.php"
mv /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
