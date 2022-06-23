- https://dev.to/yassineselllami/how-to-ssh-into-ubuntu-vm-virtualbox-from-host-machine-1kii


## server side: Ubuntu virtual box
Install install openssh-server
```
sudo apt install openssh-server
```


Start (or stop, restart) the service manually via command:
```
 sudo service ssh start
```

Verify that ssh service running
```
 sudo systemctl status ssh
```

configure your firewall to allow incoming SSH connections
```
  sudo ufw allow ssh
```

enable UFW firewall
```
  sudo ufw enable
  
```

check the status of UFW
```
  sudo ufw status
```

Setup VirtualBox
```
  Network -> Port Forwarding
```

Add Port Forwarding Rules
```
  Host IP 127.0.0.1 2222 

  Guest IP 10.0.2.15 22
```

To get Guest IP, type the following command in you VM ubuntu
```
  sudo ip a
```


## Client Side
```
  ssh -p 2222 [user]@127.0.0.1
```