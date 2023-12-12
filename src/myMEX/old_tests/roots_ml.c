#include <stdio.h>
#include <lapacke.h>
#include <mex.h>

void mexFunction(int nlhs, mxArray *plhs[],
                int nrhs, const mxArray *prhs[])
{
   lapack_int n = 3; // Size of the matrix
    lapack_complex_double A[3][3] = {{0.0 + 1.0 * I, 0.0 + 0.0 * I, -1.0 + 0.0 * I},
                                     {1.0 + 0.0 * I, 0.0 + 0.0 * I, -2.0 + 0.0 * I},
                                     {0.0 + 0.0 * I, 1.0 + 0.0 * I, -1.0 + 0.0 * I}};
    
    lapack_int lda = n;
    lapack_complex_double eigenvalues[n];
    lapack_complex_double work[1];
    double rwork[2 * n - 1];
    lapack_int info;

    // lapack_int lda = n;
    lapack_int ilo, ihi;
    double scale[n];
    lapack_int info_b;

    // Balance the complex matrix A
    info_b = LAPACKE_zgebal(LAPACK_COL_MAJOR, 'B', n,
                          (lapack_complex_double *)A, lda, &ilo, &ihi, scale);

    // get eigenvalues
    info = LAPACKE_zgeev(LAPACK_COL_MAJOR, 'N', 'N', n,
                         (lapack_complex_double *)A, lda, eigenvalues,
                         NULL, 1, NULL, 1);
    if (info == 0) {
        mexPrintf("Eigenvalues:\n");
        for (int i = 0; i < n; ++i) {
            mexPrintf("  (%f, %f)\n", creal(eigenvalues[i]), cimag(eigenvalues[i]));
        }
    } else {
        mexPrintf("Error: Failed to compute eigenvalues.\n");
    }
}