FROM bitnami/elasticsearch:8.15.0

USER root

RUN apt-get update && apt-get install -y curl jq

USER 1001

COPY tools/ /entrypoint/

ENTRYPOINT ["bash", "-c", "source /entrypoint/entrypoint_wrapper.sh"]

CMD ["/opt/bitnami/scripts/elasticsearch/entrypoint.sh", \
	"/opt/bitnami/scripts/elasticsearch/run.sh"]
