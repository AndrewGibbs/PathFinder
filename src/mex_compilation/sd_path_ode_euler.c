#include "mex.h"
#include "PathFinder.h"
#include "interface.h"
#ifndef COMPLEX_H
    #include <complex.h>
#endif

/*
function [p_log_out, h_log_out, valley_index, ball_index] = ...
            0           1           2              3
    SDpathODEuler_v4(h0, phase_coeffs, SPs, cover_radii, valleys, base_step_size, n_max, r_star,...
                      0     1       2   3           4           5               6       7
    newton_small_threshold, newton_big_threshold) %#codegen
            8                       9
*/

// the mex gateway to SDpathODEEuler_extend_coarse_path
void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[])
{
    /* check number of inputs is correct*/
    if (nrhs != 10)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs",
                          "Ten inputs required.");
    }

    /* check number of outputs is correct*/
    if (nlhs != 4)
    {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs",
                          "Four outputs required.");
    }

    // convert matlab inputs to C variables

    double complex h0;
    convert_mxsca_to_c(prhs[0], &h0);

    int phase_coeffs_len = mxGetM(prhs[1]);
    double complex phase_coeffs[phase_coeffs_len];
    convert_mxvec_to_c(prhs[1], phase_coeffs);

    int order = phase_coeffs_len - 1;

    // Note that here 'SPs' also include endpoints
    int other_stationary_points_len = mxGetM(prhs[2]);

    /* need to account for case where there are no other SPs -
    can't initialise blank vector in C */
    int max_1_or_other_SPs_len = imax(other_stationary_points_len, 1);

    // initialise these two vectors which may be blank in Matlab version
    double complex otherSPs[max_1_or_other_SPs_len];
    double otherSPs_radii[other_stationary_points_len];

    if (otherSPs == 0)
    {
        // in the case where there are no other SPs, add fictitious SP at infinity,
        // to keep things simple later on.
        otherSPs[0] = DBL_MAX + 0I;
        otherSPs_radii[0] = 0.0;
    }
    else
    {
        convert_mxvec_to_c(prhs[2], otherSPs);
        convert_mxvec_to_double(prhs[3], otherSPs_radii);
    }

    double complex valleys[order];
    convert_mxvec_to_c(prhs[4], valleys);

    double base_step_size;
    convert_mxsca_to_double(prhs[5], &base_step_size);

    int n_max;
    convert_mxint_to_int(prhs[6], &n_max);

    double r_star;
    convert_mxsca_to_double(prhs[7], &r_star);

    double newton_small_threshold;
    convert_mxsca_to_double(prhs[8], &newton_small_threshold);

    double newton_big_threshold;
    convert_mxsca_to_double(prhs[9], &newton_big_threshold);

    // prep output variables, as C variables

    double *p_out = (double *)malloc(sizeof(double) * n_max);

    double complex *h_out = (double complex *)malloc(sizeof(double complex) * n_max);

    int valley_index = -1;
    int ball_index = -1;
    int output_length;

    sd_path_ode_euler( // inputs
        h0, phase_coeffs, otherSPs, otherSPs_radii, valleys, base_step_size,
        n_max, r_star, newton_small_threshold, newton_big_threshold,
        // extra inputs required to make this code work
        other_stationary_points_len, phase_coeffs_len,
        // outputs
        p_out,
        h_out,
        &valley_index,
        &ball_index,
        &output_length);

    plhs[0] = mxCreateDoubleMatrix(output_length + 1, 1, mxREAL);
    /* need to deal with the fact this isn't complex */
    convert_double_to_mxvec(p_out, plhs[0]);

    plhs[1] = mxCreateDoubleMatrix(output_length + 1, 1, mxCOMPLEX);
    convert_c_to_mxvec(h_out, plhs[1]);

    int valley_len, ball_len;
    if (valley_index == -1)
    {
        valley_len = 0;
        ball_len = 1;
    }
    else
    {
        valley_len = 1;
        ball_len = 0;
    }

    plhs[2] = mxCreateDoubleMatrix(valley_len, valley_len, mxREAL);
    plhs[3] = mxCreateDoubleMatrix(ball_len, ball_len, mxREAL);
    /* need to deal with the fact this isn't complex */
    if (ball_index == -1)
    // add one to convert to matlab's indexing
    {
        valley_index++;
        convert_int_to_mxsca(&valley_index, plhs[2]);
    }
    else
    // add one to convert to matlab's indexing
    {
        ball_index++;
        convert_int_to_mxsca(&ball_index, plhs[3]);
    }

    /* deallocate memory - I'm sure this would happen anyway*/
    free(p_out);
    p_out = NULL;
    free(h_out);
    h_out = NULL;
}