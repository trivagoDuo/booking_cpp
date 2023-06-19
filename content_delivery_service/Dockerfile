FROM nginx:1.25-alpine
LABEL authors="sirok1"

#RUN apt-get update &&\
#    apt-get install -y nginx
COPY nginx/nginx.conf /etc/nginx/nginx.conf
COPY nginx/general.conf /etc/nginx/nginxconfig.io/general.conf
COPY nginx/000-default.conf /etc/nginx/sites-available/000-default.conf
#RUN ln -s /etc/nginx/sites-available/000-default.conf /etc/nginx/sites-enabled/000-default.conf
##    nginx -t &&\
##    service nginx reload
ENTRYPOINT ["top", "-b"]