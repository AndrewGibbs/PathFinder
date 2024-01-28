#include "mex.h"
#include "get_r.h"
#include "interface.h"
#ifndef COMPLEX_H
    #include <complex.h>
#endif

/*
Matlab MEX function:
r = getSmallestSupsetBallMex(phase_coeffs, freq, centre, cball, num_rays,
                                0           1     2        3      4     
                                take_max, imag_thresh);
                                5          6
*/

// the mex gateway
void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[])
{
    /* ---------- check number of inputs / outputs ----------*/
    if (nrhs != 7)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs",
                          "Seven inputs required.");
    }

    if (nlhs != 1)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs",
                          "One output required.");
    }

    /* ----- intialise Matlab inputs as C variables ------ */

    int phase_coeffs_len = mxGetM(prhs[0]);
    double complex phase_coeffs[phase_coeffs_len];
    convert_mxvec_to_c(prhs[0], phase_coeffs);

    double freq;
    convert_mxsca_to_double(prhs[1], &freq);

    double complex centre;
    convert_mxsca_to_c(prhs[2], &centre);

    double cball;
    convert_mxsca_to_double(prhs[3], &cball);

    int num_rays;
    convert_mxint_to_int(prhs[4], &num_rays);

    bool take_max;
    convert_mxsca_to_bool(prhs[5], &take_max);

    double imag_thresh;
    convert_mxsca_to_double(prhs[6], &imag_thresh);

    /* ---------- run main subroutine to get ball radius ----------*/

    double r;
    r = get_smallest_supset_ball(phase_coeffs, freq, centre,
                                 cball, num_rays, take_max,
                                 imag_thresh, phase_coeffs_len);

    /* ---------- convert outputs to Matlab variables ---------- */

    plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
    convert_double_to_mxsca(&r, plhs[0]);
}