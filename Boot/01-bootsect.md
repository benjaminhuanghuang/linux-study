Linux 0.11 的 bootsect.s 会把 其后的 4 个扇区, 和随后的 240 个扇区加载到内存

bootsect.s 首先要对 实模式下 1MB 的内存空间做出规划

bootsect 首先把它自己从 0x7C00 (BootSeg) DS:SI(0x7C0:0x0) 复制到 0x90000(InitSeg) ES:DI(0x9000:0x0)

然后 jump go, INITSEG 到 0x90000 继续执行

调用 BIOS INT 0x13 读磁盘从第二扇区开始的 4 个扇区(0C-0H-2S ~ 0C-0H-5S), 将 setup.s 加载到 0x90200, 紧挨着加载到 0x90000 的 bootsect.s

bootsect.s 调用 read_it 子程序 把 0C-0H-6S 开始的 240 个扇区上的 system 模块加载到 SysSeg(0x10000)开始的 120KB 空间

bootsect.s 执行 jmpi 0，SETUPSEG 跳转至 0x90200 处，即 setup 位置。CS: IP 指向
setup 程序的第一条指令，
