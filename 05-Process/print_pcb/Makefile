obj-m:=module_example.o 
CURRENT_PATH:=$(shell pwd)
LINUX_KERNEL:=5.4.0-66-generic #$(shell uname -r)
LINUX_KERNEL_PATH:=/usr/src/linux-headers-$(LINUX_KERNEL)


env:
	docker run --rm -it -v "$$PWD":/root/env my-linux-kernel-lab

all:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) modules

clean:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) clean

install:
	insmod module_example.ko

uninstall:
	rmmod module_example

