## 8 个通用寄存器 (32 bits)

- EAX：一般用作累加器。
- EBX：一般用作基址寄存器（Base）。
- ECX：一般用来计数（Count）。
- EDX：一般用来存放数据（Data）。
- EBP：一般用作堆栈指针（Stack Pointer）。
- EBP：一般用作基址指针（Base Pointer）。
- ESI：一般用作源变址（Source Index）。
- EDI：一般用作目标变址（Destination Index）。

## 6 个段寄存器

段寄存器中存放的不再是某个段的基地址，而是某个段的选择符（Selector）
因为 16 位的寄存器无法存放 32 位的段基地址，段基地址存放在一个叫做描述符表（Descriptor）的表中。

- CS：代码段寄存器。
- DS：数据段寄存器。
- SS：堆栈段寄存器。
- ES、FS 及 GS：附加数据段寄存器。

## 状态和控制寄存器

- EFLAGS: 标志寄存器
- EIP: 指令指针
- CR0 中包含了 6 个预定义标志
- CR1 是未定义的控制寄存器，供将来的处理器使用。
- CR2 是页故障线性地址寄存器，保存最后一次出现页故障的全 32 位线性地址。
- CR3 是页目录基址寄存器，保存页目录表的物理地址。页目录表总是放在以 4KB

## 系统地址寄存器

- 全局描述符表寄存器 GDTR（Global Descriptor Table Register ），是 48 位寄存器，
  用来保存全局描述符表（GDT）的 32 位基地址和 16 位 GDT 的界限。

- 中断描述符表寄存器 IDTR（Interrupt Descriptor Table Register），是 48 位寄存
  器，用来保存中断描述符表（IDT）的 32 位基地址和 16 位 IDT 的界限。

- 局部描述符表寄存器 LDTR（Global Descriptor Table Register ），是 16 位寄存器，
  保存局部描述符表 LDT 段的选择符。

- 任务状态寄存器 TR（Task State Register）是 16 位寄存器，用于保存任务状态段
  TSS 段的 16 位选择符。
