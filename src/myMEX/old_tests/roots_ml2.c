#include <stdio.h>
#include <lapacke.h>
#include <mex.h>

void roots( const double complex *g_coeffs,
            const int g_len,
            double complex *root_vals)
{
    // construct Frobenius matrix

    int n = g_len - 1; // size of matrix
    lapack_complex_double A[n][n];
    for(int j=0; j<(n-1); j++)
    {
        A[j][j+1] = 1.0;
        A[n-1][j] = -g_coeffs[g_len-j-1]/g_coeffs[g_len-1];
    }
    A[n-1][n-1] = -g_coeffs[g_len-2];

    // lapack_int lda = n;
    // lapack_complex_double eigenvalues[n];
    // lapack_complex_double work[1];
    // double rwork[2 * n - 1];
    // lapack_int info;
    lapack_int ilo, ihi;
    double scale[n];
    lapack_int info_b;
    int info_balance, info_eigs;
    
    // Balance the complex matrix A
    info_balance = LAPACKE_zgebal(LAPACK_COL_MAJOR, 'B', n,
                          (lapack_complex_double *)A, n, &ilo, &ihi, scale);

    info_eigs = LAPACKE_zgeev(LAPACK_COL_MAJOR, 'N', 'N', n,
                        (lapack_complex_double *)A, n, root_vals,
                        NULL, 1, NULL, 1);


}

void mexFunction(int nlhs, mxArray *plhs[],
                int nrhs, const mxArray *prhs[])
{
    double complex g[3] = {1.0+0.0I,0.0+0.0I,1.0+0.0I};
    // double complex g[3];
    // g[0] = 1.0+1.0I;
    // g[1] = 0.0+1.0I;
    // g[2] = 1.0+1.0I;
    lapack_complex_double eigenvalues[2];
    roots(g,3,eigenvalues);

    // if (info == 0) {
    mexPrintf("Eigenvalues:\n");
    for (int i = 0; i < 2; ++i) {
        mexPrintf("  (%f, %f)\n", creal(eigenvalues[i]), cimag(eigenvalues[i]));
        }
    // } else {
    //     mexPrintf("Error: Failed to compute eigenvalues.\n");
    // }
}