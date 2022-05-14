PROJECT=asm65
CC=gcc
DEFS=
INDIR=
INCS=
LIBDIR=
LIBS=
OBJS=\
	main.o

$(PROJECT): $(OBJS)
	$(CC) $(DEFS) $(LIBDIR) $(OBJS) $(LIBS) -o $(PROJECT)

.c.o:
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c $<

test:
	./asm65 -l test.asm

clean:
	-rm *.o
	-rm $(PROJECT)

install:
	cp asm65 /usr/local/bin
	chmod a+x /usr/local/bin/asm65

main.o:                header.h main.c

