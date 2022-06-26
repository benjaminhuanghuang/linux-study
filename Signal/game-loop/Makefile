CC=gcc
CFLAGS+=-c -Wall -g
OBJS=main.c


# $^ is the dependenies
# $@ is the target 
main.exe:$(OBJS)
	$(CC) $^ -o $@

%.o:%.c
	$(CC) $^ $(CFLAGES) -o $@

clean:
	rm -rf *.o *.exe


