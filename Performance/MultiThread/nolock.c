#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/* Two possibilities of producing problems :
** 1. a big t;
** 2. using usleep
*/

int counter = 0;

int t = 100000;


void *increase(void*arg){
  for(int i=0; i< t;i++){
    // usleep(1000); //millisecond
    counter++;
  }
}

int main(int argc, char **argv){
  pthread_t t1, t2;

  pthread_create(&t1,NULL,increase,NULL);
  pthread_create(&t2,NULL,increase,NULL);
  pthread_join(t1,0);
  pthread_join(t2,0);

  printf("Final counter is : %d\n",counter);

  return 0;
}
