- name: libxx.a

- create

```
  gcc -c mylist.c           # create object file

  ar -cr libmylist.a mylist.o     # create lib
```

- deploy

```
  /usr/local/include
  /usr/local/lib
```

- use

```
  gcc -L/usr/local/lib -o main.exe main.o -lxx
```

-L 是 lib 所在路径
-l 是 lib name
