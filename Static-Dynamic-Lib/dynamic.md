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

在 /etc/ld.so.config 中添加 /sbin/ldconfig

- use

```
  gcc -L/usr/local/lib -o main.exe main.o -lmylist
```

-L 是 lib 所在路径
-l 是 lib name
