FROM ubuntu:16.04

LABEL maintainer="Kazma"

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -qy xinetd && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*
RUN useradd -m inception -d /home/inception/
RUN chown -R inception:inception /home/inception && \
    chmod -R 755 /home/inception
RUN chmod 1777 /tmp /var/tmp /dev/shm
USER inception
CMD ["/usr/sbin/xinetd", "-dontfork"]
