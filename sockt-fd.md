cd /proc/$$/fd           # $$ is pid of current process, fd is file descriptor 文件描述符

ll  
可以看到至少三个文件描述符
```
  0 ->/dev/pts/2         # stdin
  1 ->/dev/pts/2         # stdout
  2 ->/dev/pts/2         # stderror
```


建立一个socket， Linux中一切都可以被当成文件
```
  exec 8<>   /dev/tcp/www.baidu.com/80

  type exec        # exec is a shell builtin
  help exec
```

向这个socket 连接发送请求
```
  echo -e "GET / HTTP/1.0\n" >& 8
```
从socket读取response
```
  cat 0<& 8
``` 

关闭 socket
```
  cat 0<& -
``` 