boot/head.s 汇编成目标代码，将用 C 语言编写的内核程序编译成目标代码，然后链接成 system 模块

head 程序在内存中占有 25 KB+184 B 的空间。
system 模块加载到内存后，setup 将 system 模块复制到 0x00000 位置，由于 head 程序在 system 的前面，所以实际上，head 程序就在 0x00000 这个位置

head 程序将跳转至 setup_paging 执行，开始创建分页机制

head 程序在 0x000000 的位置创建了页目录表、页表、缓冲区、GDT、IDT，并将 head 程序已经执行过的代码所占内存空间覆盖
