FROM bitnami/nginx-exporter:1.3.0

USER root

RUN apt-get update && apt-get install -y curl jq && \
	mkdir -p /tls/certs && \
	mkdir -p /tls/private && \
	chown -R 1001:1001 /tls

USER 1001

COPY tools/ /entrypoint/
COPY conf/ /opt/bitnami/nginx-exporter/conf/

ENTRYPOINT ["bash", "-c", "source /entrypoint/entrypoint_wrapper.sh"]

CMD ["nginx-prometheus-exporter", \
	"--web.config.file=/opt/bitnami/nginx-exporter/conf/web_config.yml", \
	"--nginx.scrape-uri=https://10.0.4.1:8443/nginx_status", \
	"--nginx.ssl-ca-cert=/tls/certs/ca_chain.crt", \
	"--nginx.ssl-client-cert=/tls/certs/nginx-exporter.crt", \
	"--nginx.ssl-client-key=/tls/private/nginx-exporter.key", \
	"--nginx.ssl-verify"]
