## Server Side

1. Create key pair
   要用哪个 account SSH, 就用哪个 account log in 到 SSH server

```
  ssh-keygen -f

  ssh-keygen -f ben-ssh   # 指定文件名
```

此命令在 /home/ben/.ssh 目录下生成
私钥 id_rsa
公钥 id_rsa.pub

2. 在 SSH server 上 安装 public key

```
cd ~/.ssh

cat id_rsa.pub >> authorized_keys
```

3. 配置 SSH, 允许 SSH 登录

```
  sudo vim /etc/ssh/sshd_conig

  PubkeyAuthentication yes
```

如果要用 root 登录 SSH, 需要

```
PermitRootLogin yes
```

如果禁用 password 登录

```
PasswordAuthentication no
```

4. Reboot SSH server

```
  service sshd restart
```

## Client side
put 私钥 id_rsa to .ssh folder
```
  # linux
  scp ben@127.0.0.1:/home/ben/.ssh/id_rsa /Users/bhuang/.ssh

  # windows
  scp ben@127.0.0.1:/home/ben/.ssh/id_rsa C:\Users\your_username\.ssh
```