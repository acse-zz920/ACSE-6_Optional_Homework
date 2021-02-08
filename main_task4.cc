#include <omp.h>

#include <cstdio>
#include <cstdlib>

#define N 500

int main(int argc, const char *argv[]) {
  const int num_threads = 8;
  double A[N][N], B[N][N], C[N][N];

  omp_set_num_threads(num_threads);  // set number of threads

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      A[i][j] = j * 1;
      B[i][j] = i * j + 1;
      C[i][j] = j - i * 2;
    }
  }

  double start = omp_get_wtime();  // start time measurement
  double sum(0);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      sum = 0.0;
      for (int k = 0; k < N; k++) {
        sum += A[i][k] * B[k][j];
      }
      C[i][j] = sum;
    }
  }
  double end = omp_get_wtime();  // end time measurement
  printf("Time of computation: %lf seconds\n", end - start);
  return EXIT_SUCCESS;
}
