FROM bitnami/python:3.12.6

COPY conf/ ./
COPY tools/ /entrypoint/

RUN apt-get update && apt-get install -y curl jq netcat-openbsd && \
	pip install --no-cache-dir --upgrade pip && \
	pip install --no-cache-dir -r requirements.txt && \
	mkdir -p /tls/certs && \
	mkdir -p /tls/private

ENTRYPOINT ["bash", "-c", "source /entrypoint/entrypoint_wrapper.sh"]

CMD ["gunicorn", \
	"--workers", "3", \
	"--bind", "0.0.0.0:8000", \
	"--certfile=${TLS_CERT_FILE}", \
	"--keyfile=${TLS_KEY_FILE}", \
	"--ca-certs=${TLS_CA_FILE}", \
	"pong_project.wsgi:application"]
