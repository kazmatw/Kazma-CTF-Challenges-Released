#!/bin/bash

service rsyslog start
service ssh start

touch /var/log/auth.log
chmod +r /var/log/auth.log

exec "$@"

