#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <math.h>


int
main (int argc, char *argv[])
{
  static long num_step = 10000;
  double step;
  int i;
  double x, pi, *sum, error;
  int nbthread;

  if (argc != 2)
    {
      printf (" Usage : %s <nb_threads> \n", argv[0]);
      return 2;
    }

  if (atoi (argv[1]) < 2)
    nbthread = 2;
  else if (atoi (argv[1]) > 8)
    nbthread = 8;
  else
    nbthread = atoi (argv[1]);

  sum = (double *) calloc (nbthread, sizeof (double));

  step = 1.0 / (double) num_step;

  omp_set_num_threads (nbthread);

  printf (" PI computation with : %d threads, step = %f \n", nbthread, step);

#pragma omp parallel
  {
    double x;
    int th_id, i, nbth;

    th_id = omp_get_thread_num ();
    nbth = omp_get_num_threads ();

    for (i = th_id; i < num_step; i = i + nbth)
      {
	x = (i + 0.5) * step;
	*(sum + th_id) += 4.0 / (1.0 + (x * x));
	printf (" Computation : TH%d , i = %d , value = %f \n", th_id, i,
		*(sum + th_id));
      }
  }

  printf (" Join ,Master task, end of parallel region, SUM \n");
  pi = 0.0;
  for (i = 0; i < nbthread; i++)
    pi += (*(sum + i)) * step;

  printf (" PI = %20.19f \n", pi);
  error = M_PI - pi;
  if (error < 0)
    error = -1.0 * error;
  printf (" error = %20.19f \n", error);
  free (sum);
  return 0;
}
