## Program Design

https://en.wikipedia.org/wiki/Unix_philosophy

UNIX programs...

- ...are simple
- ...follow the element of least surprise
- ...accept input from stdin
- ...generate output to stdout
- ...generate meaningful error messages to stderr
- ...have meaningful exit codes
- ...have a manual page

What is the longest word found on the ten most frequently retrieved English Wikipedia pages?

```
$ for f in $(curl -L https://is.gd/c6F2fs | zgrep -i "^en " | sort -k3 -n | tail -10 |
sed -e 's/en \(.*\) [0-9]* [0-9]*/\1/'); do
links -dump https://en.wikipedia.org/wiki/${f};
done |
tr '[:punct:]' ' ' |
tr '[:space:]' '\n' |
tr '[:upper:]' '[:lower:]' | egrep '^[a-z]+$' |
awk '{ print length() " " $0; }' | sort |
uniq |
sort -n |
tail -1
```

## Unix Time Values

Calendar time: measured in seconds since the UNIX epoch (Jan 1, 00:00:00, 1970,
GMT). Stored in a variable of type time_t

```
  date +%s
```

## Standard I/O

- file descriptors: Small, nonnegative integers which identify a file to the kernel.
  The shell can redirect any file descriptor.

- unbuffered I/O
  open(2),
  read(2),
  write(2),
  lseek(2),
  close(2)

- buffered I/O
  fopen(3),
  fread(3),
  fwrite(3),
  getc(3),
  putc(3)
