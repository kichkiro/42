FROM bitnami/prometheus:2.54.1

USER root

RUN apt-get update && apt-get install -y curl jq && \
	mkdir -p /tls/certs && \
	mkdir -p /tls/private && \
	chown -R 1001:1001 /tls

USER 1001

COPY tools/ /entrypoint/
COPY conf/ /opt/bitnami/prometheus/conf/

ENTRYPOINT ["bash", "-c", "source /entrypoint/entrypoint_wrapper.sh"]

CMD ["/opt/bitnami/prometheus/bin/prometheus", \
	"--config.file=/opt/bitnami/prometheus/conf/prometheus.yml", \
	"--web.config.file=/opt/bitnami/prometheus/conf/web.yml", \
	"--web.console.libraries=/opt/bitnami/prometheus/conf/console_libraries", \
	"--web.console.templates=/opt/bitnami/prometheus/conf/consoles", \
	"--storage.tsdb.path=/opt/bitnami/prometheus/data", \
	"--storage.tsdb.retention.time=30d"]
