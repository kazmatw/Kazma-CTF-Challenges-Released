FROM ubuntu:latest

LABEL maintainer="Kazma"

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -qy xinetd && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*
RUN useradd -m bread -d /home/bread/
RUN chown -R bread:bread /home/bread && \
    chmod -R 755 /home/bread
RUN chmod 1777 /tmp /var/tmp /dev/shm
USER bread
CMD ["/usr/sbin/xinetd", "-dontfork"]

