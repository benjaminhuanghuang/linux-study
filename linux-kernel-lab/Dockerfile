FROM ubuntu:20.04

# copy source code to vm
ENV DEBIAN_FRONTEND=nointeractive


RUN  apt-get update \
     && apt-get install wget gcc gdb qemu make git -y \
     && apt-get install build-essential kernel-package libncurses5-dev -y \
     && ln -sf /usr/bin/qeum-system-x86_64 /usr/bin/qeum


VOLUME /root/env
WORKDIR /root/env
