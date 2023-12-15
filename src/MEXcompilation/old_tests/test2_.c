#include "PathFinder.h"
#include "mex.h"
#include "interface.h"
// #include <math.h>

/* tests (most of) the interface functions,
    my polyval implementation,
    and my understanding of pointers*/

void mexFunction(
    int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    // get length of vector 
    const int vec_len = mxGetM(prhs[0]);
    int order = vec_len-1;
    double complex inputArray_c[vec_len];
    // convert to c
    convert_mxvec_to_c(prhs[0], inputArray_c);
    
    // complex double z_in;
    double complex z_in;
    convert_mxsca_to_c(prhs[1],&z_in);
    
    // double complex z_out;
    double complex z_out = polyval(inputArray_c,z_in,order);
    plhs[0] = mxCreateDoubleMatrix(1,1,mxCOMPLEX);
    
    // convert to mx output
    convert_c_to_mxsca(z_out, plhs[0]);
    /**/
    
}