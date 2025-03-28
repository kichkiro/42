FROM bitnami/postgres-exporter:0.15.0

USER root

RUN apt-get update && apt-get install -y curl jq && \
	mkdir -p /tls/certs && \
	mkdir -p /tls/private && \
	chown -R 1001:root /tls

USER 1001

COPY tools/ /entrypoint/
COPY conf/ /opt/bitnami/postgres-exporter/conf/

ENTRYPOINT ["bash", "-c", "source /entrypoint/entrypoint_wrapper.sh"]

CMD ["postgres_exporter",\
	"--web.config.file=/opt/bitnami/postgres-exporter/conf/web_config.yml"]
