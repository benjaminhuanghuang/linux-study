Understanding UNIX/LINUX Programming ch 4

## How does that work

Unix  文件系统的 3 个主要部: Superblock, i-node Table, data region

- 读取目录

```
stat(fname, &info),
```

- 沿目录树向上追踪
