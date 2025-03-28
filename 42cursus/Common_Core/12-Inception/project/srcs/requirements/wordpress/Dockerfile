FROM debian:oldstable

ARG MARIADB_DB_NAME
ARG MARIADB_DB_USER
ARG MARIADB_DB_PASS

COPY tools/init_wordpress.sh /tmp/init_wordpress.sh

RUN chmod +x /tmp/init_wordpress.sh && /tmp/init_wordpress.sh

COPY conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf

RUN chown -R www-data:www-data /var/www/html && chmod -R 700 /var/www/html

EXPOSE 9000

CMD ["php-fpm7.4", "-F"]
