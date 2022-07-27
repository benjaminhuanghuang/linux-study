```
cd ~/LinuxKernel

qemu -kernel linux-3.18.6/arch/x86/boot/bzImage -initrd rootfs.img -s -S


```

在 /arch/x86/syscalls/syscall_32.tbl 中可以看到

```
13i386  time sys_time
```

表明 13 号系统调用对应的内核处理函数为 sys_time

```
(gdb) b sys_time
```

在 MenuOS 中执行 time 会中断到 kernel/time/time.c

给 system_call()加断点

```
(gdb) b system_call
```

会中断到 arch/x86/kernel/entry_32.S
