#include "mex.h"
#include "complex.h"
#include "interface.h"

void mexFunction(int nlhs, mxArray *plhs[],
                int nrhs, const mxArray *prhs[])
{
    int n;
    // convert_mxsca_to_int(prhs[0], &n);
    // convert_mxsca_to_int2(prhs[0]);
    // n = 1;
    convert_mxsca_to_int(prhs[0],&n);
    plhs[0] = mxCreateDoubleMatrix(1,1,mxCOMPLEX);
    convert_int_to_mxsca(&n, plhs[0]);
}