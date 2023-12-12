#include <stdio.h>
#include <lapacke.h>

int main ()
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

    // Workspace query
    info = LAPACKE_zgeev(LAPACK_COL_MAJOR, 'N', 'N', n,
                         (lapack_complex_double *)A, lda, eigenvalues,
                         NULL, 1, NULL, 1);
    if (info == 0) {
        printf("Eigenvalues:\n");
        for (int i = 0; i < n; ++i) {
            printf("  (%f, %f)\n", creal(eigenvalues[i]), cimag(eigenvalues[i]));
        }
    } else {
        printf("Error: Failed to compute eigenvalues.\n");
    }
}