#include <stdio.h>
#include <stab.h>
#include <omp.h>

int main(){

  printf("The number of processors is %d.\n",omp_get_num_procs());
  printf("The max number of threads is %d.\n",omp_get_max_threads());

  #pragma omp parallel
  {
    printf("Say HELLO from thread %d\n",omp_get_thread_num());
  }
}
