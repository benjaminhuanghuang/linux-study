env:
	docker run --rm -it -v "$$PWD":/root/env my-linux-kernel-lab

download:
	wget https://www.kernel.org/pub/linux/kernel/v3.x/linux-3.18.6.tar.xz &&\
	xz -d linux-3.18.6.tar.xz &&\
	tar -xvf linux-3.18.6.tar

start:
	qemu -kernel linux-3.18.6/arch/x86/boot/bzImage -initrd rootfs.img

startdbg:
	qemu -kernel linux-3.18.6/arch/x86/boot/bzImage -initrd rootfs.img -s -S
