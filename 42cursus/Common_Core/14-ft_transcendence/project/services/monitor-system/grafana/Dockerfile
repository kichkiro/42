FROM bitnami/grafana:10.4.8

USER root

RUN apt-get update && apt-get install -y curl jq netcat-openbsd && \
	mkdir -p /tls/certs && \
	mkdir -p /tls/private && \
	chown -R 1001:1001 /tls

USER 1001

COPY tools/ /entrypoint/
COPY conf/grafana.ini /opt/bitnami/grafana/conf/
COPY conf/dashboards/ /opt/bitnami/grafana/conf/provisioning/dashboards/

ENTRYPOINT ["bash", "-c", "source /entrypoint/entrypoint_wrapper.sh"]

CMD ["/opt/bitnami/scripts/grafana/entrypoint.sh", \
	"/opt/bitnami/scripts/grafana/run.sh"]
