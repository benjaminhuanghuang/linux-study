# Macos + VM(virtualbox) + ubuntu

1. VM 100G disk space

2. use root build linux kernel

```
sudo passwd

su root

```

3. setup ssh in ubuntu VM

```
  apt-get install openssh-server -y

  ps -e | grep ssh

  sudo etc/init.d/ssh start

  ifconfig
```

修改 ssh 配置允许 root 远程登录

```
  vim /etc/ssh/sshd_config

  #PermitRootLogin without-password
```

方便从 host 机器 操作 unbuntu VM 或 用 vscode 调试

4. install build tools

```
  apt install build-essential flex bison libssl-dev libelf-dev libncurses-dev -y
```
