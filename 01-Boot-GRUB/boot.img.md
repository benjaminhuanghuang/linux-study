- How does GNU GRUB work
  - https://0xax.github.io/grub/

所有 boot 相关数据都放在/boot 目录中, 该目录包含:

- 两个 initrd 映像，
- Linux 内核映像
- 包含 GNU GRUB 相关数据的 grub/目录

/boot/grub/i386-pc/ 目录下有两个.img 文件: boot.img 和 core.img

boot.img 是 PC BIOS system 上 bootloader 的入口. boot.img 的内容会被写到磁盘的第一个扇区(Master boot record).

boot.img 的任务是加载 core.img 的 first sector(512bytes)

boot.img 为 512 bytes, 以 0xAA55 结尾

```
$ du -b /boot/grub/i386-pc/boot.img
512 /boot/grub/i386-pc/boot.img

$ hexdump -s 510 /boot/grub/i386-pc/boot.img
00001fe aa55
```

boot.img 中包含 加载 第二阶段 bootloader(可以大于 512 字节) 的代码 和 四个 16 字节条目的 partition table

core.img 包含 file system driver，可以加载配置(/boot/grub/grub.cfg)和 modules.
然后 core.img 把控制权交给 GRUB.

比较磁盘上第二个扇区的内容与 core.img

```
hexdump core.img | more


dd if=/dev/sda of=/tmp/2sect bs=512 count=1 skip=1
hexdump /tmp/2sect | more

```

GRUB 会加载 modules, 绘制菜单
