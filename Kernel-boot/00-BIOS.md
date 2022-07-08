CPU 在加电时强行把 CS(Code Segment Register) 置为 0xF000, IP(Instruction Pointer) 置为 0xFFF0, 此时 CS:IP 指向 0xFFFF0

0xFFFF0 正好就是 BIOS 程序的入口地址

BIOS 完成自检, 设置好中断向量表(Interrupt Vector Table)后会产生 INT 0x19 中断, BIOS INT 0x19 把 第一扇区 512 bytes 加载到内存 0x7C00

INT 0x19 的中断服务程序(Interrupt Service)入口为 0xE6F2
