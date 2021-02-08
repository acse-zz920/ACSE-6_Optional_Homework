#include <omp.h>

#include <cstdio>
#include <cstdlib>

#define N 50

int main(int argc, const char *argv[]) {
  int i, nthreads, tid;
  double a[N], b[N], c[N], d[N];

  for (i = 0; i < N; i++) {
    a[i] = i * 1.5;
    b[i] = i + 22.35;
    c[i] = d[i] = 0.0;
  }

#pragma omp parallel shared(a, b, c, d, nthreads) private(i, tid)
  {
    tid = omp_get_thread_num();
    if (tid == 0) {
      nthreads = omp_get_num_threads();
      //===================== Start of the Exercise ============================
      printf("Number of threads = %d\n", nthreads);
      //===================== End of the Exercise ==============================
    }
    //===================== Start of the Exercise ==============================
    printf("Thread ID = %d, starting...\n", tid);
    //===================== End of the Exercise ================================
#pragma omp sections nowait
    {
#pragma omp section
      {
        for (i = 0; i < N; i++) {
          c[i] = a[i] + b[i];
          //===================== Start of the Exercise ========================
          printf("tid = %d, i = %d, c[i] = %lf\n", tid, i, c[i]);
          //===================== End of the Exercise ==========================
        }
      }

#pragma omp section
      {
        for (i = 0; i < N; i++) {
          d[i] = a[i] * b[i];
          //===================== Start of the Exercise ========================
          printf("tid = %d, i = %d, d[i] = %lf\n", tid, i, d[i]);
          //===================== End of the Exercise ==========================
        }
      }
    }
    printf("Thread ID = %d, done...\n", tid);
  }  // end of sections
  return EXIT_SUCCESS;
}
