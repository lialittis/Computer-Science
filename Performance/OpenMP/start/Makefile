CC=gcc
CFLAGS=-fopenmp
LDFLAGS=-fopenmp

all:	hello manipulation vecteur prod_sca
	echo "Done"

hello: 	hello.o
	$(CC) $(LDFLAGS) -o hello hello.o

hello.o: hello.c
	$(CC) $(CFLAGS) -c hello.c

manipulation: manipulations.o
	$(CC) $(LDFLAGS) -o manipulation manipulations.o

manipulations.o : manipulations.c
	$(CC) $(CFLAGS) -c manipulations.c

vecteur : vecteurs_addition.o
	$(CC) $(LDFLAGS) -o vecteur vecteurs_addition.o

vecteurs_addition.o : vecteurs_addition.c
	$(CC) $(CFLAGS) -c vecteurs_addition.c

prod_sca : prod_scalaire_openmp.o
	$(CC) $(LDFLAGS) -o prod_sca prod_scalaire_openmp.o

prod_scalaire_openmp.o : prod_scalaire_openmp.c
	$(CC) $(CFLAGS) -c prod_scalaire_openmp.c

clean:
	rm hello *.o

