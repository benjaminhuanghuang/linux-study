## Week 02, Segment 1: File Descriptors

https://www.youtube.com/watch?v=h5A1OQjuCqk&list=PL0qfF8MrJ-jxMfirAdxDs9zIiBg2Wug0z&index=5

File descriptor (or file handle) is a small, non-negative integer which identifies a file to the kernel

STDIN_FILENO

STDOUT_FILENO

STDERR_FILENO

## Lab: how many files can be opened in Linux system?

```
openmax.c

_SC_OPEN_MAX

getrlimit(2)
sysconfig(3)

grep OPEN_MAX /usr/include/sys/syslimits.h

getconf OPEN_MAX

which getconf

vim /usr/src/usr.bin/getconf/getcong.c

ulimit -n

ulimit -n 64
```
