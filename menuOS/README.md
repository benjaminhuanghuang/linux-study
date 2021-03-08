
## Download kernel source code 
```
  cd ~/linuxkernel/

  wget https://www.kernel.org/pub/linux/kernel/v3.x/linux-3.18.6.tar.xz

  xz -d linux-3.18.6.tar.xz

  tar -xvf linux-3.18.6.tar.xz            # 30 minuets

  cd linux-3.18.6

  make i386_defconfig
  # or
  make x86_64_defconfig

  make -j8          #  hours
```

Build kernel with debug information
```
  make x86_64_defconfig

  make menuconfig
    Kernel hacking ->
      Compile-time checks and compiler options ->
        * Complie the kernel with debug info

  make -j8
```

## root file system
Build init module, kernel will load it as #1 process

```
  cd ~/linuxkernel

  mkdir rootfs

  git clone https://github.com/mengning/menu.git

  cd menu

  # build init module, kernel will load init as #1 process
  gcc -o init linktable.c menu.c test.c -m32 -static -lpthread
  # For 64bit build env
  gcc -o init linktable.c menu.c test.c -static -lpthread

  cd ../rootfs

  cp ../menu/init ./

  # package /rootfs/* into an image contains root file system 
  find .| cpio -o -Hnewc | gzip -9 > ../rootfs.img
```

## Start MenuOS
```
  cd ~/linuxkernel

  qemu -kernel linux-3.18.6/arch/x86/boot/bzImage -initrd rootfs.img

```

## gdb debug kernel
start kernel
```
  qemu -kernel linux-3.18.6/arch/x86/boot/bzImage -initrd rootfs.img -s -S
```
gdb
```
(gdb) file linux-3.18.6/vmlinux   # load debug symbol
(gdb) target remote:1234          # connect to qemu gdb server
(gdb) break start_kernel          # set break point
(gdb) c
(gdb) list                        # list source code
(gdb) break rest_init
```

or start gdb with symbol
```
  gdb git/kernel/linux/vmlinux
```

