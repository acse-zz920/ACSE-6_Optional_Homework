#include <omp.h>

#include <cstdio>
#include <cstdlib>

#define CHUNKSIZE 10
#define N 100

int main(int argc, const char *argv[]) {
  int nthreads, tid, i, chunk;
  double a[N], b[N], c[N];
  for (i = 0; i < N; i++) {
    a[i] = b[i] = 1.0 * i;  // initialize array chunk = chunk_size
  }
  chunk = CHUNKSIZE;

#pragma omp parallel shared(a, b, c, nthreads, chunk) private(i, tid)
  {
    tid = omp_get_thread_num();
    if (tid == 0) {
      nthreads = omp_get_num_threads();
      //===================== Start of the Exercise ============================
      printf("Number of threads = %d\n", nthreads);
      //===================== End of the Exercise ==============================
    }
    printf("Thread ID = %d, starting ...\n", tid);

#pragma omp for schedule(static, chunk)
    for (i = 0; i < N; i++) {
      c[i] = a[i] + b[i];
      //===================== Start of the Exercise ============================
      printf("tid = %d, i = %d, c[i] = %lf\n", tid, i, c[i]);
      //===================== End of the Exercise ==============================
    }

  }  // end of parallel section
  return EXIT_SUCCESS;
}
