#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N1 10
#define N2 50
#define N3 100

#define epsilon 0.001

void print_array(float* , int);

void jacobiSeq(int);

int main(int argc, char* argv[]){

  jacobiSeq(N1);

  jacobiSeq(N2);

  jacobiSeq(N3);


  return 0;
}

void jacobiSeq(int N){

  printf("======= N = %d =======\n",N);

  // declaration
  float* r=malloc(N*N*sizeof(float));
  float b[N],d[N],x[N],x_n[N],y[N];

  float e; // distance
  int i,j;

  struct timeval t1,t2;

  // initialization
  for(i=0; i<N;i++){
    for(j=0;j<N;j++){
      //r[i*N+j] = (j%N)==(j/N) ? 0 : 1;
      r[i*N+j] = (i==j) ? 0.: 1.;
    }
    // printf("r is");
    // print_array(&r[i*N],N);
    b[i] = 6.;
    d[i] = 2.*N + 1.;
    x[i] = 1.;
    y[i] = 0.;
    // x_n[i] = 0;
  }

  int count = 0;

  gettimeofday(&t1,NULL);

  // computation
  do{

    e = 0.;
    for(i=0;i<N;i++){
      for(j=0;j<N;j++){
        y[i] += r[i*N+j]*x[j]; // how to initialze y because of here
      }
      x_n[i] = (b[i] - y[i])/d[i];
      e += pow(x_n[i] - x[i],2);

    }
    // printf("y is");
    // print_array(y,N);
    e = sqrt(e);

    // x <- x_n
    for(i=0;i<N;i++){
     x[i] = x_n[i];
    }
    count++;

  }while(e>epsilon);

  gettimeofday(&t2,NULL);

  printf("Computation time is %ld miseco, with count %d\n",(t2.tv_sec-t1.tv_sec)*100000 + t2.tv_usec - t1.tv_usec,count);
  printf("The result of x[0] is %f.\n",x[0]);
}


void print_array(float* array, int size){
  printf("\n");
  for(int i = 0; i< size; i++){
    printf("%f ",array[i]);
  }
  printf("\n");
}
