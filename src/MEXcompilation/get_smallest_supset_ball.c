#include "mex.h"
#include "get_r.h"
#include "interface.h"

/*
r = get_smallest_supset_ball(g_coeffs, freq, xi, Cosc, num_rays, take_max, imag_thresh);
0                               0       1     2    3      4         5          6
*/

void mexFunction(int nlhs, mxArray *plhs[],
                int nrhs, const mxArray *prhs[])
{
    /* check number of inputs is correct*/
    if(nrhs != 7) {
    mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs",
                      "Seven inputs required.");
    }
    
    /* check number of outputs is correct*/
    if(nlhs != 1) {
    mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs",
                      "One output required.");
    }

    int g_coeffs_len = mxGetM(prhs[0]);
    double complex g_coeffs[g_coeffs_len];
    convert_mxvec_to_c(prhs[0],g_coeffs);

    double freq;
    convert_mxsca_to_double(prhs[1], &freq);

    double complex xi;
    convert_mxsca_to_c(prhs[2], &xi);

    double Cosc;
    convert_mxsca_to_double(prhs[3], &Cosc);

    int num_rays;
    convert_mxint_to_int(prhs[4], &num_rays);

    // something about a bool here, input 5...
    bool take_max;
    convert_mxsca_to_bool(prhs[5], &take_max);

    double imag_thresh;
    convert_mxsca_to_double(prhs[6], &imag_thresh);

    double r;
    r = get_smallest_supset_ball(g_coeffs, freq, xi,
                                Cosc, num_rays, take_max,
                                imag_thresh, g_coeffs_len);

    plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
    convert_double_to_mxsca(&r, plhs[0]);
}