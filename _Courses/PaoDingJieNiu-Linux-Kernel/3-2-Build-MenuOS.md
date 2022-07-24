# 构造一个简单的 Linux 系统 MenuOS

- 下载,编译内核源代码

```
cd ~/LinuxKernel

wget https://www.kernel.org/pub/linux/kernel/v3.x/linux-3.18.6.tar.xz
xz -d linux-3.18.6.tar.xz
tar -xvf linux-3.18.6.tar

cd linux-3.18.6
make i386_defconfig
make
```

如果需要让 linux 携带 debug 信息

```
  make menuconfig

  kernel hacking ->
    [*] compile the kernel with debug info

  make
```

- 制作根文件系统

```
cd ~/LinuxKernel

mkdir rootfs

git clone https:/github.com/mengning/menu.git
cd menu
gcc pthread -o init linkable.c menu.c test.c -m32 -static

cd ../rootfs
cp ../menu/init ./     # 将init复制到rootfs下

# 把当前rootfs下的所有文件打包成一个镜像文件
find . | cpio -o -Hnewc | gzip -9 > ../rootfs.img
```

build 的结果

```
  LinuxKernel/
    linux-3.18.6/
    rootfs.img
```

- 启动 MenuOS

```
cd ~/LinuxKernel

qemu -kernel linux-3.18.6/arch/x86/boot/bzImage -initrd rootfs.img

```

initrd:是 initial ramdisk 简写，普通用户一般感受不到这个内存根文件系统的存在，因为普通 Linux 在启动时，是 boot loader 将存储介质中的 initrd 文件加载到内存，内核启动时先访问 initrd 文件系统（内存根文件系统），然后再切换到磁盘文件系统。
