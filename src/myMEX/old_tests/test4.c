#include <complex.h>
#include "mex.h"
#include "interface.h"

/* Test code which takes matlab vector,
    converts it to complex C vector,
                        and back again.*/

/* The main point is to test the interface.h
        header file.*/

void mexFunction(int nlhs, mxArray *plhs[],
                int nrhs, const mxArray *prhs[])
{
    const mxArray *inputArray_mx = prhs[0];

    // get length of vector 
    const int vec_len = mxGetM(prhs[0]);
    double complex inputArray_c[vec_len];

    // convert to c
    convert_mxvec_to_c(inputArray_mx, inputArray_c);
    
    // convert back to mx
    plhs[0] = mxCreateDoubleMatrix(vec_len,1,mxCOMPLEX);
    convert_c_to_mxvec(inputArray_c,plhs[0]);
}