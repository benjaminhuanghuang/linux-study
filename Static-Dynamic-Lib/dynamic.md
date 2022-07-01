- name: libxx.so

- create

```
  gcc -shared -fPIC -o libmylist.so mylist.c           # create lib
```

- deploy

```
  /usr/local/include
  /usr/local/lib
```

在 /etc/ld.so.config 中添加 dynamci lib 所在路径

reload: /sbin/ldcofnig

- Non-root user delpy

```
  cp xx.so ~/lib

  export LD_LIBRARY_PATH=~/lib
```

- use

```
  gcc -I/usr/local/include -L/usr/local/lib  -o main.exe main.o -lmylist
```

-L 是 lib 所在路径
-l 是 lib name
