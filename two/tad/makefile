CC=gcc
CFLAGS=-I.
DEPS = tree.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tad: main.c tree.c
	$(CC) -o tad main.c tree.c
