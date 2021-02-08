#include <omp.h>

#include <cstdio>
#include <cstdlib>

int main(int argc, const char *argv[]) {
  const int num_threads = 32;
  int nthreads, tid;

  // set the number of threads to 32
  omp_set_num_threads(num_threads);

  // fork a team of threads giving them their own copies of variables
#pragma omp parallel private(nthreads, tid)
  {
    tid = omp_get_thread_num();  // obtain thread number
    // print Hello world from thread tid

    //===================== Start of the Exercise ==============================
    printf("Hello world\n");
    //===================== End of the Exercise ================================

    if (tid == 0) {
      // only master thread does this
      nthreads = omp_get_num_threads();
      // print number of threads
      //==================== Start of the Exercise =============================
      printf("Number of threads = %d\n", nthreads);
      //==================== End of the Exercise ===============================
    }
  }  // all threads join master thread and disband
  return EXIT_SUCCESS;
}
