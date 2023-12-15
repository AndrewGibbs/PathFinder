#include "PathFinder.h"
// #include <stdio.h>
// #include <string.h>
// #include "matrix.h"
#include "mex.h"
// #include <math.h>

void mexFunction(
    int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    // convert input to complex double type
    // double complex z = plhs[1]
    const int order = mxGetNumberOfDimensions(prhs[0])-1;
    
    // Get a pointer to the input complex data
    const mxArray *inputArray = prhs[0];
    // double complex *inputArray_ = mxGetComplexDoubles(inputArray);
    double *realData = mxGetPr(inputArray);
    double *imagData = mxGetPi(inputArray);
    // double *complex Z = CMPLX(realData, imagData);
    double complex coeffs[order+1];
    for(int j=0; j<=order; j++)
    {
        coeffs[j] = realData[j] + (imagData[j] * I);
        // coeffs[j] = 1.0 + (1.0 * I);
    }

    // double complex g_coeffs = mxGetComplexDoubles(prhs[0]);
    // int order = 3;
    // double complex complex_vector[order+1];
    // complex_vector[0] = 1.0 + 2.0I;
    // complex_vector[1] = 2.0 + -1.5I;
    // complex_vector[2] = 1.0 - 2.0I;
    // complex_vector[3] = 1.0 - 0.0I;
    // double complex z_in = 1.0-1.0I;

    // Get a pointer to the input complex data
    const mxArray *inputArray1 = prhs[1];
    double *realData1 = mxGetPr(inputArray1);
    double *imagData1 = mxGetPi(inputArray1);
    double complex z_in;
    z_in = *realData1 + (*imagData1 * I);

    
    double complex z_out;
    z_out = polyval(coeffs,z_in,order);

    // sort the output
    plhs[0] = mxCreateDoubleMatrix(1,1,mxCOMPLEX);
    double *H0r, *H0i;
    H0r = mxGetPr(plhs[0]);
    H0i = mxGetPi(plhs[0]);
    H0r[0] = creal(z_out);
    H0i[0] = cimag(z_out);
    // plhs[0] = mxCreateDoubleScalar(ToyFunction(mxGetScalar(prhs[0])));

}