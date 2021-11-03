
#include <stdio.h>
#include <pthread.h>

#define NTHREADS 10

/* pthread_mutex_t mutex  = PTHREAD_MUTEX_INITIALIZER */
pthread_mutex_t mutex;

int count = 0;
int isRunning = 1;


void *thread_run(void *arg)
{
  pthread_mutex_lock(&mutex);
  while(isRunning){
    if(count<20000){
      count ++;
      //printf("[%#lx] value of count:%d\n",pthread_self(), ++count);
    }
    else isRunning=0;
  }
  pthread_mutex_unlock(&mutex);
  return 0;
}

int main(int argc, char* argv[])
{

  // pthread_t t_1, t_2;
  pthread_mutex_init(&mutex,0);
  pthread_t p_id[NTHREADS];

  for(int i = 0; i < NTHREADS ; i++) {
   pthread_create(&p_id[i], NULL, thread_run, NULL);
  }

  for(int j = 0; j < NTHREADS ; j++) {
    pthread_join(p_id[j], NULL);
  }

  /*
  pthread_create(&t_1, NULL, thread_run,0);
  pthread_create(&t_2, NULL, thread_run,0);

  pthread_join(t_1,0);
  pthread_join(t_2,0);
  */

  printf("Final count value : %d\n", count);

  pthread_mutex_destroy(&mutex);

  return 0;
}
