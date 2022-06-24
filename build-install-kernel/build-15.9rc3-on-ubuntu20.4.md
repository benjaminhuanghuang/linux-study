1. Download srouce code
```
  git clone git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git
```

2. Create configuration file .config
```
  make olddefconfig
```

3. Update .config to enable / disable some kernel configuration
```
  make menuconfig
```
input "/" and search the symbol you want to config

4. Build using as many threads as cpu core count 
```
  make -j $(nproc)
```

Fix error during make:
```
No rule to make target 'debian/canonical-certs.pem', needed by 'certs/x509_certificate_list'.  Stop.
```
- https://askubuntu.com/questions/1329538/compiling-the-kernel-5-11-11

Solution: 
```
  scripts/config --disable SYSTEM_TRUSTED_KEYS
  scripts/config --disable SYSTEM_REVOCATION_KEYS
```

5. Install
```
  make modules_install && make install
```

6. Reboot
```
  reboot
```

7. Validate
check current kernel
```
  uname -r
```
check the modules installed
```
  [ -c /dev/cachefiles ] && echo ok
```


