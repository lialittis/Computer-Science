#include<stdio.h>

int main(){
  int a[10] = {20,5,61,3,5,24,103,1,265,34};

  /* target is the rightest position */
  for(int i = (int)(sizeof(a)/sizeof(int)); i >= 0; i--) {
    /* comparation*/
    for(int j = 0; j < i - 1; j++) {
      if(a[j] > a[j+1]) {
        /* a better way of swap */
        a[j] = a[j] ^ a[j+1];
        a[j+1] = a[j] ^ a[j+1];
        a[j] = a[j] ^ a[j+1];
      }
    }
  }

  /* print out */
  printf("[");
  for(int i = 0; i < (int)(sizeof(a)/sizeof(int)); i++) {
    printf("%d ",a[i]);
  }
  printf("]\n");
  return 0;
}
