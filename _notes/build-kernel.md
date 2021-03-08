Check building env
```
  sudo cat /proc/version
```

Download
```
	wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.7.5.tar.xz &&\
	xz -d linux-5.7.5.tar.xz &&\
	tar -xvf linux-5.7.5.tar
```
文件最好压到 /usr/src 这个目录，编译驱动时这是默认到内核搜索路径



Inall dependencies
```
  sudo apt-get update

  sudo apt-get intall libncurses5-dev build-essential openssl -y

  sudo apt-get intall flex bison libssl-dev -y
```



## Config
```
  make menuconfig
```
- CPU

- File type




将内核代码还原到刚解压的状态
```
  sudo make mrproper

  sudo make clean
```



Build kernel
```
  sudo make bzImage
```

Build and Install modules
```
  sudo make modules
  sudo make modules_install
```

Install kernal
```
  sudo make install
```

Using new kenrnl
```
  cp bzImagee /boot/bzImage
  GRUB            # config /boot/grub/grub.conf
```