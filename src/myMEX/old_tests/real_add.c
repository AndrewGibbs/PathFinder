#include "mex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs != 2) {
        mexErrMsgIdAndTxt("AddTwoNumbers:InvalidInput", "Two input arguments are required.");
    }

    if (nlhs != 1) {
        mexErrMsgIdAndTxt("AddTwoNumbers:InvalidOutput", "One output argument is required.");
    }

    // Get pointers to the input data
    double *x = mxGetPr(prhs[0]);
    double *y = mxGetPr(prhs[1]);

    // Create an output mxArray and get a pointer to its data
    plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
    double *result = mxGetPr(plhs[0]);

    // Add the two numbers
    *result = *x + *y;
}