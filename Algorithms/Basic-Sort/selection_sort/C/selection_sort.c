#include <stdio.h>

int main(){

  int a[10] = {7,8,5,9,20,19,1,201,5,58};

  /* Observation */
  for(int i = 0; i < (int)(sizeof(a)/sizeof(int)); i++){
    int target = i;
    /* Comparation */
    for(int j = i+1 ; j < (int)(sizeof(a)/sizeof(int));j++ ){
      if(a[j] < a[target]) {
        target = j;
      }
    }

    /* swap */
    int temp;
    temp = a[target];
    a[target] = a[i];
    a[i] = temp;
  }

  /* print out */
  printf("[");
  for(int i = 0; i < (int)(sizeof(a)/sizeof(int)); i++) {
    printf("%d ",a[i]);
  }
  printf("]\n");
  return 0;
}
