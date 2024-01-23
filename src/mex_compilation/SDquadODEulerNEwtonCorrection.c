#include "mex.h"
#include "PathFinder.h"
#include "interface.h"

// [h_quad, dhdp_quad, newton_success] =
// SDquadODEulerNEwtonCorrection(p_quad, p_coarse, h0, h_coarse, phase_coeffs, freq, newton_thresh, newton_its)
//                                  0       1       2   3           4       5       6           7

void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[])
{
    /* check number of inputs is correct*/
    if (nrhs != 8)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs",
                          "Eight inputs required.");
    }

    /* check number of outputs is correct*/
    if (nlhs != 3)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs",
                          "Three outputs required.");
    }

    /* -------------- initialise input variables ---------------- */
    // convert inputs to appropriate types
    int quad_size = mxGetM(prhs[0]);
    double *p_quad = malloc(quad_size * sizeof(double));
    convert_mxvec_to_double(prhs[0], p_quad);

    int coarse_size = mxGetM(prhs[1]);
    double *p_coarse = malloc(coarse_size * sizeof(double));
    convert_mxvec_to_double(prhs[1], p_coarse);

    complex double h0;
    convert_mxsca_to_c(prhs[2], &h0);

    double complex *h_coarse = malloc(coarse_size * sizeof(double complex));
    convert_mxvec_to_c(prhs[3], h_coarse);

    int phase_coeffs_len = mxGetM(prhs[4]);
    double complex phase_coeffs[phase_coeffs_len];
    convert_mxvec_to_c(prhs[4], phase_coeffs);

    double freq;
    convert_mxsca_to_double(prhs[5], &freq);

    double newton_thresh;
    convert_mxsca_to_double(prhs[6], &newton_thresh);

    int newton_its;
    convert_mxint_to_int(prhs[7], &newton_its);

    /* --------------- initialise outputs, as C variables ----------------- */
    // outputs (as pointers)
    int newton_success[quad_size];
    double complex h_quad[quad_size];
    double complex dhdp_quad[quad_size];

    /* -------------- call the main C function ------------------------ */
    sd_quad_ode_euler_correction( // orig inputs
        p_quad,
        p_coarse,
        h0,
        h_coarse,
        phase_coeffs,
        freq,
        newton_thresh,
        // extra inputs for C code
        newton_its,
        coarse_size,
        quad_size,
        phase_coeffs_len,
        // outputs
        h_quad,
        dhdp_quad,
        newton_success);

    /* ------------- create output variables ------------- */

    plhs[0] = mxCreateDoubleMatrix(quad_size, 1, mxCOMPLEX);
    plhs[1] = mxCreateDoubleMatrix(quad_size, 1, mxCOMPLEX);
    plhs[2] = mxCreateDoubleMatrix(quad_size, 1, mxREAL);

    convert_c_to_mxvec(h_quad, plhs[0]);
    convert_c_to_mxvec(dhdp_quad, plhs[1]);
    convert_intvec_to_mxvec(newton_success, plhs[2]);

    /* deallocate memory */
    free(p_quad);
    p_quad = NULL;
    free(p_coarse);
    p_coarse = NULL;
    free(h_coarse);
    h_coarse = NULL;
}