KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $$(shell pwd)


all: 
	make -C $(KERNELDIR) M=$(PED) modules

clean: 
	rm -rf *.o *.depend