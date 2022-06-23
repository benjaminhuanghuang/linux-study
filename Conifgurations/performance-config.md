0. Stop services
Search Startup Applications

1. Modify grub
```
sudo vi /etc/default/grub
sudo update-grub

change 
GRUB_TIMEOUT=10 to GRUB_TIMEOUT=2
```


2. clean apt
```
sudo apt clean
sudo apt autoremove
```

remove language package
```
sudo gedit /etc/apt/apt.conf.d/00aptituderoot234


add
Acquire::Languages "none";
```

3. 优化笔记本电池
```
sudo add-apt-repository ppa:linrunner/tlp
sudo apt update
sudo apt install tlp tlp-rdw
sudo tlp start
```