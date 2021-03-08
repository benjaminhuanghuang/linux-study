env:
	docker run --rm -it -v "$$PWD":/root/env my-linux-kernel-lab

download:
	wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.7.5.tar.xz &&\
	xz -d linux-5.7.5.tar.xz &&\
	tar -xvf linux-5.7.5.tar

start:
	qemu-system-x86_64 -kernel linux-5.7.5/arch/x86/boot/bzImage -initrd rootfs.img

startdbg:
	qemu-system-x86_64 -kernel linux-5.7.5/arch/x86/boot/bzImage -initrd rootfs.img -s -S
