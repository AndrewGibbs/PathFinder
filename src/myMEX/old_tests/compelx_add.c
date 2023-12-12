#include "mex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs != 2 || nlhs != 1) {
        mexErrMsgIdAndTxt("MyToolbox:complex_add:invalidInputOutput",
            "Two complex input arguments required, one complex output argument.");
    }

    // Get pointers to the input complex numbers
    double *real1 = mxGetPr(prhs[0]);
    double *imag1 = mxGetPi(prhs[0]);
    double *real2 = mxGetPr(prhs[1]);
    double *imag2 = mxGetPi(prhs[1]);

    // Get the size of the input arrays
    mwSize numElements = mxGetNumberOfElements(prhs[0]);

    // Create output complex number arrays
    plhs[0] = mxCreateDoubleMatrix(1, numElements, mxCOMPLEX);
    double *real_result = mxGetPr(plhs[0]);
    double *imag_result = mxGetPi(plhs[0]);

    // Add the complex numbers element-wise
    for (mwSize i = 0; i < numElements; i++) {
        real_result[i] = real1[i] + real2[i];
        imag_result[i] = imag1[i] + imag2[i];
    }
}