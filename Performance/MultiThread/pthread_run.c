#include <stdio.h>
#include <pthread.h>

#define NTHREADS 10

void *thread_function(void *arg);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int counter = 0;
int isRunning = 1;

int main(){
  pthread_t p_id[NTHREADS];

  for(int i = 0; i < NTHREADS ; i++) {
   pthread_create( &p_id[i], NULL, thread_function, NULL);
  }

  for(int j = 0; j < NTHREADS ; j++) {
    pthread_join(p_id[j], NULL);
  }

  printf("Final counter value : %d\n", counter);
}

void *thread_function(void *arg){
  while(isRunning==1){
    if(counter <100000){
      ++counter;
    }
    else isRunning = 0;
  }
  return NULL;
}
