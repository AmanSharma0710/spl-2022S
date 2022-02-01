SHELL=/bin/sh
CC=gcc
CFLAGS=-Wall
LIBRARIES = -lsplgraph -lsplds
MAKE = make install

graph.out: main.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBRARIES)
all:
	cd ../dynamic-library/; $(MAKE) -f makefile.basic; $(MAKE) distclean -f makefile.basic
	cd ../static-library/; $(MAKE) -f makefile.graph; $(MAKE) distclean -f makefile.graph
	cd ../main-testing/ ; make graph.out