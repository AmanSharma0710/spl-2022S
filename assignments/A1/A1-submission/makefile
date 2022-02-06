SHELL=/bin/sh
CC=gcc
CFLAGS=-Wall
LIBRARIES = -lsplgraph -lsplds
MAKE = make install

graph.out: main.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBRARIES)
	
all:
	$(MAKE) -f makefile.basic; $(MAKE) distclean -f makefile.basic
	$(MAKE) -f makefile.graph; $(MAKE) distclean -f makefile.graph
	make headers -f makefile.basic
	make headers -f makefile.graph
	make graph.out