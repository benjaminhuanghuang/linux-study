Linux 内核不区分进程和线程, PCB 和 TCB 的数据结构都是 task_struct

task_struct 中 的 pid 成员值不论进程和线程,都是 unique 的

fork 会生成一个新的进程, 进程会有一个 unique 的 task_struct, 其中的 pid 和 tgid 相同

用 pthread_create 生成一个或 多个 线程时,也会生成一个新的, unique 的 task_struct.
这些线程的 tgid (线程 group id) 是 原始进程 pid

用 ps 命令 或 getpid() 系统调用查到的都是进程或线程的 task_struct 中的 `tgid` 成员
