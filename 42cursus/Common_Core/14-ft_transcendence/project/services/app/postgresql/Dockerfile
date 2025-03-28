FROM bitnami/postgresql:15.8.0

USER root

RUN apt-get update && apt-get install -y curl jq && \
	mkdir -p /tls/certs && \
	mkdir -p /tls/private && \
	chown -R 1001:1001 /tls

USER 1001

COPY conf/ /tmp/
COPY tools/entrypoint_wrapper.sh /entrypoint/

ENTRYPOINT ["bash", "-c", "source /entrypoint/entrypoint_wrapper.sh"]

CMD [ "/opt/bitnami/scripts/postgresql/entrypoint.sh", \
	"/opt/bitnami/scripts/postgresql/run.sh" ]
