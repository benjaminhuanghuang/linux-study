How to Boot Ubuntu 20.04 into Text / Command Console

1. backup the configuration file:
```
sudo cp -n /etc/default/grub /etc/default/grub.backup
```
2. Edit the configuration file:
```
sudo gedit /etc/default/grub
```

change
```
GRUB_CMDLINE_LINUX_DEFAULT="quiet splash"
set GRUB_CMDLINE_LINUX="" to GRUB_CMDLINE_LINUX="text"
remove # from the line GRUB_TERMINAL="console" to disable graphical terminal.
```

to
```
#GRUB_CMDLINE_LINUX_DEFAULT="quiet splash"
GRUB_CMDLINE_LINUX="text"
GRUB_TERMINAL="console"
```

3. Save the file and apply changes:
```
  sudo update-grub
```

4. Disable GUI
```
sudo systemctl set-default multi-user.target
```

## Start GUI
```
  startx
```

## How to Restore:
```
sudo mv /etc/default/grub.backup /etc/default/grub

sudo update-grub

# re-enable GUI mode
sudo systemctl set-default graphical.target
```