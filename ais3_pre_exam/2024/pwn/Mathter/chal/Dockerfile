FROM ubuntu:latest

LABEL maintainer="Kazma"

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -qy xinetd && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*
RUN useradd -m mathter -d /home/mathter/
RUN chown -R mathter:mathter /home/mathter && \
    chmod -R 755 /home/mathter
RUN chmod 1777 /tmp /var/tmp /dev/shm
USER mathter
CMD ["/usr/sbin/xinetd", "-dontfork"]

