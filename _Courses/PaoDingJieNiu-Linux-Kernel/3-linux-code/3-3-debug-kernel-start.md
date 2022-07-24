```
cd ~/LinuxKernel

qemu -kernel linux-3.18.6/arch/x86/boot/bzImage -initrd rootfs.img -s -S

# -S freeze CPU at startup (use 'c' to start execution)
# -s shorthand for -gdb tcp::1234
```

Open a other shell

```
gdb
(gdb) file linux-3.18.6/vmlinux    # 加载符号表
(gdb) target remote:1234           # connect to gdbserver
(gdb) break start_kernel
(gdb) c
(gdb) list

```
