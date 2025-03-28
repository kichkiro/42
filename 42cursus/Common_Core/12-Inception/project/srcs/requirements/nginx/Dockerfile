FROM debian:oldstable

COPY tools/init_nginx.sh /tmp/

RUN chmod +x /tmp/init_nginx.sh && /tmp/init_nginx.sh

COPY conf/kichkiro.42.fr.conf /etc/nginx/conf.d/kichkiro.42.fr.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
