#include <stdio.h>
#include <stab.h>
#include <omp.h>

int main(int argc, char *argv[]) {

  if(argc<2) { printf("Offer an number please!\n"); return 0;}

  int n = atoi(argv[1]);
  omp_set_num_threads(n);
  #pragma omp parallel
  {
    printf("The number of threads is %d\n", omp_get_num_threads());
  }
}
