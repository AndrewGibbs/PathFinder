#include <complex.h>
#include "mex.h"
#include "interface.h"

/* Test code which tests scalar inputs & outputs
    and checking that I finally understand how pointers work*/

void mexFunction(int nlhs, mxArray *plhs[],
                int nrhs, const mxArray *prhs[])
{

    double complex z_in;
    // double complex* z_in_ptr = &z_in;
    convert_mxsca_to_c(prhs[0], &z_in);
    
    // convert back to mx
    plhs[0] = mxCreateDoubleMatrix(1,1,mxCOMPLEX);
    convert_c_to_mxsca(z_in, plhs[0]);
}