#include <stdlib.h>
#include <stdio.h>

#define LEN 9

int nums[LEN] = {2,3,4,3,2,4,5,6,6};


int main(int argc, char *argv[]) {
  int target = 0;

  for(int i = 0 ; i < LEN; i++){
    target ^= nums[i];
  }

  printf("The target is %d.\n",target);

  return 0;
}
