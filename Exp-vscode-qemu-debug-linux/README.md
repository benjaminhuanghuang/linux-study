https://blog.csdn.net/weixin_44465434/article/details/121194613


1. Inatall qemu


check qemu
```
  qemu-system-x86_64 -version
```

2. get nova source code
```
  git clone https://github.com/NVSL/linux-nova.git
```

3. 配置编译选项
```
  ce linux-nova

  make menuconfig

  [x] NVDIMM

```

4.   