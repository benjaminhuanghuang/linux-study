# Linux kernel Lab in Docker
Build a linux kernel debug/tract environment in Docker

- Docker + Ubuntu work as the host. Build and run linux kernel in it.
- qeum + dgb debug the linux kernel


0. Build docker
```
  docker build . -t my-linux-kernel-lab
```


1. connect to docker
```
  docker run --rm -it -v "$$PWD":/root/env my-linux-kernel-lab
```


2. Build linux in docker
```
make x86_64_defconfig

make menuconfig
  Kernel hacking ->
    Compile-time checks and compiler options ->
      * Complie the kernel with debug info

make -j8
```


3. Run linux kernel in qemu
```
  qemu -kernel ./arch/x86_64/boot/bzImage -s -S -append "console=ttyS0" -nographic
```

Debug options:
```
  -s: shorthand for -gdb tcp::1234
  -S: freeze CPU at startup
```

Linux/Multiboot boot specific:
```
  -kernel bzImage use 'bzImage' as kernel image
  -append cmdline use 'cmdline' as kernel command line
  -initrd file    use 'file' as initial ram disk
```

4. GDB

Start gdb with symbol
```
  gdb git/kernel/linux/vmlinux
```
connect to qemu
```
  (gdb) target remote :1234

  (gdb) hb start_kernel

  (gdb) c

  (gdb) disass start_kernel

  (gdb) tui enable          # enable text UI

  (gdb) disass kernel_init

```
      