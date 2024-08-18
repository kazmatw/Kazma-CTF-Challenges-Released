FROM php:7.4.33-apache

RUN apt-get update && \
    apt-get install -y openssh-server rsyslog cron

RUN mkdir /var/run/sshd
RUN echo 'root:change_this_password' | chpasswd
RUN sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN sed -i 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' /etc/pam.d/sshd

RUN sed -i 's/module(load="imklog")/# module(load="imklog")/g' /etc/rsyslog.conf

RUN chown -R www-data:www-data /var/www/html && \
    chmod -R 555 /var/www/html

ARG FLAG
RUN echo $FLAG > /flag_$(cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w 8 | head -n 1)

COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

RUN echo "0 0 * * * root truncate -s 0 /var/log/auth.log" > /etc/cron.d/log-cleanup
RUN chmod 0644 /etc/cron.d/log-cleanup
RUN crontab /etc/cron.d/log-cleanup

RUN service cron start

ENTRYPOINT ["/entrypoint.sh"]
CMD ["apache2-foreground"]

