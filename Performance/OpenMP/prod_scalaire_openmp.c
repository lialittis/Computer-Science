#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>
#define ELEMENT float

int main (int argc, char *argv[]) {
  
  ELEMENT *a, *b, *partiels, c, produit;
  int i, thread_num, n, p, N;
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
  partiels = malloc(p * sizeof(ELEMENT)); 
  for (i=0 ; i<N ; i++) {
    a[i] = 0.5;
    b[i] = 0.5;
  }
  for (i=0 ; i<p ; i++) {
    partiels[i] = 0.0;
  }  
  produit = 0.0;
  
  omp_set_num_threads (p);
  
  gettimeofday (&t1, NULL);
        
#pragma omp parallel private (c, i, thread_num) shared (a, b, N, partiels)
  {
    c = 0.0;
#pragma omp for
    for (i=0 ; i<N ; i++) {
      c = c + (a[i] * b[i]);
    }
    thread_num = omp_get_thread_num ();
    partiels [thread_num] = c;
  } 
  /* partie sequentielle */
  for (i = 0; i < p; i++) {
    produit = produit + partiels [i] ;
  }
  
  gettimeofday (&t2, NULL);      
  
  printf("le produit scalaire vaut %f\n", produit);
  printf("duree du calcul = %ld micros\n", (t2.tv_sec - t1.tv_sec) * 1000000 + t2.tv_usec - t1.tv_usec);
  
  free(a);
  free(b);
  free(partiels);

  return 1;
}

