1. download linux code

```
wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.0.1.tar.xz

xz -d linux-5.0.1.tar.xz

tar -xvf linux-5.0.1.tar

cd linux-5.0.1
```

2. config kernel

```
  make menuconfig

  Kernel hacking  --->
    [*] Kernel debugging
    Compile-time checks and compiler options  --->
         [*] Compile the kernel with debug info
         [*]     Provide GDB scripts for kernel debugging


  Processor type and features  --->
    [] Randomize the address of the kernel image (KASLR)      # 关闭地址随机化，不然断点处无法停止


  make -j4          # N = core * 2
```

最终生成 linux/vmlinux
