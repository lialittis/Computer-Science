#include <stdio.h>
#include <stab.h>
#include <omp.h>

int main(int argc, char *argv[]) {

  int n,p,N;

  if(argc !=3){
    printf ("usage : 1st argument = size of one bloc, 2nd argument = nb threads\n");
    n = 1024;
    p = 8;
  }else {
    n = atoi(argv[1]);
    p = atoi(argv[2]);
  }
  N = n * p;

  // set the number of threads
  omp_set_num_threads(p);

  int i,thread_num;

  float *v1,*v2;
  v1 = calloc(N,sizeof(float));
  v2 = calloc(N,sizeof(float));

  // set the initial value for vecteurs
  for (i=0 ; i<N ; i++) {
    v1[i] = 0.5;
    v2[i] = 0.5;
  }

#pragma omp parallel private (i,thread_num) shared(v1,v2,N)
  {
    thread_num = omp_get_thread_num ();
#pragma omp for
    for(i=0;i<N;i++){
      v1[i] = v1[i] + v2[i];
      printf("Current thread is %d, and v1[%d] is add to %f, and current time is%f\n",thread_num,i,v1[i], omp_get_wtime());
    }
  }

  free(v1);
}
