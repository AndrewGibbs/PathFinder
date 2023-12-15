#include <stdio.h>
#include <stdlib.h>
#include <lapacke.h>
#include <complex.h>

void balanceComplexMatrix() {
    lapack_int n = 3; // Size of the matrix
    lapack_complex_double A[3][3] = {{1.0 + 2.0 * I, 20000.0 + 3.0 * I, 3.0 + 4.0 * I},
                                     {4.0 + 5.0 * I, 5.0 + 600.0 * I, 600.0 + 7.0 * I},
                                     {700.0 + 8.0 * I, 8.0 + 9.0 * I, 9.0 + 10.0 * I}};
    
    lapack_int lda = n;
    lapack_int ilo, ihi;
    double scale[n];
    lapack_int info;

    // Balance the complex matrix A
    info = LAPACKE_zgebal(LAPACK_COL_MAJOR, 'B', n,
                          (lapack_complex_double *)A, lda, &ilo, &ihi, scale);

    // Check for successful computation
    if (info == 0) {
        printf("Balanced Complex Matrix A:\n");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("(%8.3f + %8.3f*i) ", creal(A[i][j]), cimag(A[i][j]));
            }
            printf("\n");
        }

        printf("\nRow and Column Scaling Factors:\n");
        for (int i = 0; i < n; ++i) {
            printf("%12.5f ", scale[i]);
        }
    } else {
        printf("Error: Failed to balance the complex matrix.\n");
    }
}

int main() {
    balanceComplexMatrix();
    return 0;
}
