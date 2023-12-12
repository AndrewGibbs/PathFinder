#include "PathFinder.h"
// #include <stdio.h>
// #include <string.h>
// #include "matrix.h"
#include "mex.h"
#include <math.h>

void mexFunction(
    int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    // Get a pointer to the input complex data
    const mxArray *inputArray1 = prhs[0];
    double *realData1 = mxGetPr(inputArray1);
    double *imagData1 = mxGetPi(inputArray1);
    double complex z1 = *realData1 + (*imagData1 * I);

    plhs[0] = mxCreateDoubleMatrix(1,1,mxCOMPLEX);
    double *H0r, *H0i;
    H0r = mxGetPr(plhs[0]);
    H0i = mxGetPi(plhs[0]);
    H0r[0] = creal(z1);
    H0i[0] = cimag(z1);

}