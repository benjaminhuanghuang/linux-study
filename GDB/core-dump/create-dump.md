
## create dump for a process
```
  ps aux | grep <app-name>        # find pid

  gdb attach <pid>


  (gdb) gcore  test.core         # generate a dump
```  



## create dupm when app crash
```
  ulimit -c unlimited             # set ulimit, 0: no dump

  cat /proc/sys/kernel/core_pattern       # name of the dump file

  # Modify dump file anme pattern
  echo -e "%e-%p-%t" > /proc/sys/kernel/core_pattern    # appname-pid-time
```



