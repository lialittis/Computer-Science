#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NCLIENTS 5

void * fn_clients (void *);
void * fn_store (void * p_data);
int get_random (int max);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int items;

int main()
{
   pthread_t thread_store;
   pthread_t thread_client[NCLIENTS];
   pthread_create( &thread_store, NULL, fn_store, NULL );
   pthread_join( thread_store, NULL);

   int add[] = {0,1,2,3,4};
   for(int i = 0; i < NCLIENTS; i++)
   {
      pthread_create( &thread_client[i], NULL, fn_clients, &add[i] );
      // pthread_join( thread_client[i], NULL);
   }

   // printf("the value of i is %d\n",*add);

   for(int j=0; j < NCLIENTS; j++)
   {
      pthread_join( thread_client[j], NULL);
   }
   printf("Remains %d in stock!\n", items);

   return 0;
}

void *fn_store(void *p_data)
{
  items = 20;
  printf("Creation of the store thread!\n");
  printf("%d in stock\n", items);
  return NULL;
}

void *fn_clients(void *p_data)
{

  int id = *(int *) p_data;
  printf("Creation of customer thread %d!\n", id);
  int b = get_random((3)); 
  while(1) {
    sleep(get_random(3));
    if (items > 0) {
      pthread_mutex_lock(&mutex1);
      items -= b;
      printf("Customer %d takes %d of stock in stock, remains %d in stock!\n", id, b, items);
      pthread_mutex_unlock(&mutex1);

    }
    else {
      printf("No stock!\n");
      break;
    }

  }
  return NULL;


}

int get_random (int max)
{
   double val;
   val = (double) max * rand ();
   val = val / (RAND_MAX + 1.0);

   return ((int) val);
}

