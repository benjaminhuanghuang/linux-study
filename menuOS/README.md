
## Download kernel source code 
```
  cd ~/linuxkernel/

  wget https://www.kernel.org/pub/linux/kernel/v3.x/linux-3.18.6.tar.xz

  xz -d linux-3.18.6.tar.xz

  tar -xvf linux-3.18.6.tar.xz            # 30 minuets

  cd linux-3.18.6

  make i386_defconfig
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
```
  cd ~/linuxkernel

  mkdir rootfs

  git clone https://github.com/mengning/menu.git

  cd menu

  gcc -o init linktable.c menu.c test.c -m32 static -lpthread

  cd ../rootfs

  cd ../menu/init ./

  # 
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

