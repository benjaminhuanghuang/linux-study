## install qume in the ubuntu

```
apt install qemu
```

## Create a rootfs

启动内核需要一个具有根文件系统的磁盘镜像文件

```
mkdir rootfs

cd rootfs

git clone https://github.com/mengning/menu.git

cd menu

apt install libc6-dev-i386

vim Makefile


```

start qemu

```
qemu-system-x86_64 -kernel ~/workspace/linux/arch/x86/boot/bzImage \
  -initrd ~/workspace/rootfs/rootfs.img \
  -append "root=/dev/sda console=ttyS0" \
  -nographic \
  nokaslr -s

-kernel # 指定编译好的内核镜像

-hda # 指定硬盘

-append "root=/dev/sda" 指示根文件系统 "console=ttyS0" 把 QEMU 的输入输出定向到当前终端上

-nographic 不使用图形输出窗口

-s 是-gdb tcp::1234 缩写，监听 1234 端口，在 GDB 中可以通过 target remote localhost:1234 连接

nokaslr 关闭地址随机化，不然断点处无法停止
```

```
cd ../linux-5.0.1

# 发现低版本的 gdb 调试出现问题，需要升级。
gdb ./vmlinux

```
