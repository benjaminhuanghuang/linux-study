all:
	make -C /lib/modules/`uname -r`/build M=$(PWD) modules
obj-m += printk-example.o printk-float.o
clean:
	rm -rf *.o *.ko *.mod.c .an* .lab* .tmp_versions Module.symvers Module.markers modules.order .*.cmd *.mod
