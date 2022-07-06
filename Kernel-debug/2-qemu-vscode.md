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

## start qemu

```
qemu-system-x86_64 -kernel ~/workspace/linux/arch/x86/boot/bzImage \
  -initrd ~/workspace/rootfs/rootfs.img \
  -append "root=/dev/sda console=ttyS0 nokaslr" \
  -nographic \
  -s -S

-kernel # 指定编译好的内核镜像

-hda # 指定硬盘

-append "root=/dev/sda" 指示根文件系统 "console=ttyS0" 把 QEMU 的输入输出定向到当前终端上, nokaslr 关闭地址随机化，不然断点处无法停止

-nographic 不使用图形输出窗口

-s 是-gdb tcp::1234 缩写，监听 1234 端口，在 GDB 中可以通过 target remote localhost:1234 连接

-S 在启动时并不启动CPU，需要在monitor中运行 "c"（或cont）命令才能继续运行。配合“-gdb”参数一起使用，启动后，让GDB远程连接到QEMU上，然后再继续运行。
```

## VS code

在 VScode 中 使用 remote-ssh 插件, ssh 到 Ubuntu VM, 打开 linux 代码所在的 folder

然后再安装插件 ms-vscode.cpp-tools

然后 在 vscode 中生成配置文件 .vscode\launch.json

vscode 会连接到 qeum 开启的 端口(1234) 进行 debug

```
{
  "version": "0.2.0",
  "configurations": [
    {
        "name": "kernel-debug",
        "type": "cppdbg",
        "request": "launch",
        "miDebuggerServerAddress": "127.0.0.1:1234",
        "program": "${workspaceFolder}/vmlinux",
        "args": [],
        "stopAtEntry": false,
        "cwd": "${workspaceFolder}",
        "environment": [],
        "externalConsole": false,
        "logging": {
            "engineLogging": false
        },
        "MIMode": "gdb",
    }
  ]
}
```

add break point in eventpool.c
