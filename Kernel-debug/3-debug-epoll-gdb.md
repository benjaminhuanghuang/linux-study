https://zhuanlan.zhihu.com/p/445453676

## Create a rootfs

下载内核测试源码

```
cd /<linux-sourcecode>

git clone https://github.com/wenfh2020/kernel_test.git

cd kernel_test/test_epoll_thundering_herd

make

make rootfs           # make rootfs and launch qemu, 详细配置在 Makefile

# 在 qemu 窗口输入小写字符 's', 启动测试用例服务程序。
s
# 在 qemu 窗口输入小写字符 'c', 启动测试用例客户端程序。
c

```

只有第一次需要执行 make 来生成 rootfs, 以后的调试只要执行

```
cd kernel_test/test_epoll_thundering_herd

qemu-system-x86_64 -kernel ../../arch/x86/boot/bzImage -initrd ../rootfs.img -append "nokaslr console=ttyS0" -S -s -nographic
```

## GDB remote debug

```
  cd linux-sourcecode

  gdb vmlinux-debug

  target remove 1234        # remote connect to qemu

  b start_kernel            # add break point

  b tecp_v4_connect

  c                         # continue

  focus                     # show source code

  bt



```
