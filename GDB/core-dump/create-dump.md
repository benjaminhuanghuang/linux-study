
## create dump for a process
```
  ps aux | grep <app-name>        # find pid

  gdb attach <pid>


  (gdb) gcore  test.core         # generate a dump
```  



## create dupm when app crash
Ubuntu 20.04
```
  ulimit -c unlimited             # set ulimit, 0: do no create dump

  cat /proc/sys/kernel/core_pattern       # name of the dump file

  # Modify dump file anme pattern
  echo -e "%e-%p-%t" > /proc/sys/kernel/core_pattern    # appname-pid-time
```

有些系统配置用 /lib/systemd/systemd-coredump 生成 dump, 如 Ubuntu 18.04
```
  cat /proc/sys/kernel/core_pattern  
```






