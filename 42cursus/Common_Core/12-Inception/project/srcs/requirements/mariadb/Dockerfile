FROM debian:oldstable

ARG MARIADB_ROOT_PASS
ARG MARIADB_DB_NAME
ARG MARIADB_DB_USER
ARG MARIADB_DB_PASS

COPY tools/init_mariadb.sh /tmp/init_mariadb.sh

RUN chmod +x /tmp/init_mariadb.sh && /tmp/init_mariadb.sh

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

EXPOSE 3306

CMD ["mysqld_safe"]
