#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>
#define ELEMENT float

int main (int argc, char *argv[]) {
	
	ELEMENT *a, *b, c, produit;
	int i, n, p, N;
	struct timeval t1, t2;
	
	if (argc != 3) {
		printf ("usage : 1er argument = taille d'un bloc, 2eme argument = nb threads\n");
		n = 1024;
		p = 8;
    }
    else {
		n = atoi(argv[1]);
		p = atoi(argv[2]);
	}
	N = n * p;
    printf ("calcul du produit scalaire de 2 vecteurs de taille %d avec %d threads\n", N, p);
	
	
	a = malloc(N * sizeof(ELEMENT));
	b = malloc(N * sizeof(ELEMENT));  
	for (i=0 ; i<N ; i++) {
		a[i] = 0.5;
		b[i] = 0.5;
	}
	produit = 0.0;
  
	omp_set_num_threads (p);
  
	gettimeofday (&t1, NULL);

	#pragma omp parallel private (c, i) shared (a, b, N) reduction (+:produit)
	{
		c = 0.0;
		#pragma omp for
	    for (i=0 ; i<N ; i++) {
	       c = c + (a[i] * b[i]);
	    }
	    produit = produit + c;
    } 

    
	gettimeofday (&t2, NULL);
	free(a);
	free(b);      

	printf("le produit scalaire vaut %lf\n", produit);
	printf("duree du calcul = %ld micros\n", (t2.tv_sec - t1.tv_sec) * 1000000 + t2.tv_usec - t1.tv_usec);

	return 1;
}

