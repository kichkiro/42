FROM owasp/modsecurity-crs:nginx

USER root

RUN apt-get update && apt-get install -y curl jq && \
	mkdir -p /tls/certs && \
	mkdir -p /tls/private && \
	chown -R nginx:nginx /tls

USER nginx

COPY conf/ /etc/nginx/conf.d/
COPY tools/ /entrypoint/

ENTRYPOINT ["bash", "-c", "source /entrypoint/entrypoint_wrapper.sh"]
