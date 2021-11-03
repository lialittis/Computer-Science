CC=gcc
CFLAGS=-Wall
LIBS=-lpthread

pthread_example: pthread_example.o
	$(CC) -o pthread_example pthread_example.o $(LIBS)

pthread_exaple.o: pthread_example.c
	$(CC) $(CFLAGS) -c pthread_example.c

clean :
	rm pthread_example *.o

nolock: nolock.o
	$(CC) -o nolock nolock.o $(LIBS)

nolock.o : nolock.c
	$(CC) $(CFLAGS) -c nolock.c
