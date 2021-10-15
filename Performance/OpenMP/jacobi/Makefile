CC=gcc
CFLAGS=-c -fopenmp
LDFLAGS=-fopenmp

all:	jacobiSeq
	echo "Done"

jacobiSeq: jacobiSeq.o
	$(CC) $(LDFLAGS) -o jacobiSeq jacobiSeq.o -lm

jacobiSeq.o: jacobiSeq.c
	$(CC) $(CFLAGS) jacobiSeq.c

clean:
	rm *.o jacobiSeq
