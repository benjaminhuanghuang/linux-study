
0. Install the required compilers and other tools

- Debian/Ubuntu
```
  sudo apt-get install build-essential libncurses-dev bison flex libssl-dev libelf-dev
```

- CentOS/RHEL
```
  $ sudo yum group install "Development Tools"
```

- Fedora
```
  $ sudo dnf group install "Development Tools"
  $ sudo dnf install ncurses-devel bison flex elfutils-libelf-devel openssl-devel
```

1. Donwload source code
```
$ wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.16.9.tar.xz

$ unxz -v linux-5.16.9.tar.xz
```

Verify Linux kernel tartball with pgp
```
$ wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.16.9.tar.sign
$ gpg --verify linux-5.16.9.tar.sign
```

```
$ tar xvf linux-5.16.9.tar
```


2. Configuring the kernel
```
$ make menuconfig – Text based color menus, radiolists & dialogs. This option also useful on remote server if you wanna compile kernel remotely.

$ make xconfig – X windows (Qt) based configuration tool, works best under KDE desktop

$ make gconfig – X windows (Gtk) based configuration tool, works best under Gnome Dekstop.
```

3. Compile
```
  $ make -j $(nproc) 
```



4. Update grub config




100. Verify new Linux kernel version after reboot:
```
$ uname -mrs
```