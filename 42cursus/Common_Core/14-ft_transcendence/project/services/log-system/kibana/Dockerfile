FROM bitnami/kibana:8.15.0

USER root

RUN apt-get update && apt-get install -y curl jq && \
	mkdir -p /tls/certs && \
	mkdir -p /tls/private && \
	chown -R 1001:1001 /tls

USER 1001

COPY tools/ /entrypoint/

ENTRYPOINT ["bash", "-c", "source /entrypoint/entrypoint_wrapper.sh"]

CMD ["/opt/bitnami/scripts/kibana/entrypoint.sh", \
	"/opt/bitnami/scripts/kibana/run.sh"]
