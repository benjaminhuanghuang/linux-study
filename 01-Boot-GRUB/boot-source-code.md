https://0xax.github.io/grub/
https://www.bilibili.com/video/BV1yf4y137Vz

BIOS 从磁盘读取第一个扇区（前 512 个字节）并加载到 0x0000:0x7c000
MBR 代码在 grub-core/boot/i386/pc/boot.S 汇编源代码文件中实现.
MBR 引导代码的任务是从磁盘加载第二个第二扇区并将控制转移到它。

boot.S 会加载 diskboot.img(core.img 的前 512 字节),
diskboot.img 会加载 core.img 的剩余部分, 然后 jump 到 grub-core/boot/i386/pc/startup_raw.S. 这段代码的任务是为执行 C 语言代码做准备

调用在 grub-core/kern/i386/realmode.S 中的 real_to_prot 函数。

GRUB 内核位于 grub-core/kern/i386/pc/startup.S
