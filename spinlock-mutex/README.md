

- spin_lock: 线程A拿了锁，B去拿锁会失败，B就会自旋
- mutex: 线程A拿了锁，B去拿锁会失败，B就会sleep，等A完成了B会Weakup

如果事务很简单，就应该使用spinlock