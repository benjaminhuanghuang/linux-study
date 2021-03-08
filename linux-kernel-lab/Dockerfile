FROM ubuntu:20.04

# copy source code to vm
ENV DEBIAN_FRONTEND=nointeractive


RUN  apt-get update \
     && apt-get install build-essential libncurses5-dev dpkg-dev -y \
     && apt-get install gcc libssl-dev grub2 bison flex libelf-dev -y \
     && apt-get install wget qemu git -y \
     && ln -sf /usr/bin/qeum-system-x86_64 /usr/bin/qeum

VOLUME /root/env
WORKDIR /root/env
