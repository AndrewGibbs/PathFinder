#include "mex.h"
#include "PathFinder.h"
#include "interface.h"

/*
function [p_log_out, h_log_out, valley_index, ball_index] = ...
            0           1           2              3
    SDpathODEuler_v4(h0, gCoeffs, SPs, cover_radii, valleys, base_step_size, n_max, r_star,...
                      0     1       2   3           4           5               6       7
    Newton_small_threshold, Newton_big_threshold, Newton_point_count_max) %#codegen
            8                       9                   10              
*/

// the mex gateway to SDpathODEEuler_extend_coarse_path
void mexFunction(int nlhs, mxArray *plhs[],
                int nrhs, const mxArray *prhs[])
{
    // convert matlab inputs to C variables

    double complex h0;
    convert_mxsca_to_c(prhs[0],&h0);

    int gCoeffs_len = mxGetM(prhs[1]);
    double complex gCoeffs[gCoeffs_len];
    convert_mxvec_to_c(prhs[1],gCoeffs);

    int order = gCoeffs_len-1;

    // Note that here 'SPs' also include endpoints
    int SPs_len = mxGetM(prhs[2]);
    double complex SPs[SPs_len];
    convert_mxvec_to_c(prhs[2],SPs);

    double cover_radii[SPs_len];
    convert_mxvec_to_double(prhs[3],cover_radii);

    double complex valleys[order];
    convert_mxvec_to_c(prhs[4],valleys);

    double base_step_size;
    convert_mxsca_to_double(prhs[5],&base_step_size);

    int n_max;
    convert_mxint_to_int(prhs[6],&n_max);

    double r_star;
    convert_mxsca_to_double(prhs[7],&r_star);

    double Newton_small_threshold;
    convert_mxsca_to_double(prhs[8],&Newton_small_threshold);

    double Newton_big_threshold;
    convert_mxsca_to_double(prhs[9],&Newton_big_threshold);

    // int Newton_point_count_max;
    // convert_mxint_to_int(prhs[10],&Newton_point_count_max);

    // prep output variables, as C variables

    double *p_out = (double*) malloc(sizeof(double)*n_max);

    double complex *h_out = (double complex*) malloc(sizeof(double complex)*n_max);

    int valley_index = -1;
    int ball_index = -1;
    int output_length;

    SDpathODEuler( //inputs
                    h0, gCoeffs, SPs, cover_radii, valleys, base_step_size,
                    n_max, r_star, Newton_small_threshold, Newton_big_threshold,
                    // extra inputs required to make this code work
                    SPs_len, gCoeffs_len,
                    //outputs
                    p_out,
                    h_out,
                    &valley_index,
                    &ball_index,
                    &output_length
                    );

    /* check number of inputs is correct*/
    if(nrhs != 11) {
    mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs",
                      "Eleven inputs required.");
    }

    /* check number of outputs is correct*/
    if(nlhs != 4) {
    mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs",
                      "Four outputs required.");
    }

    
    plhs[0] = mxCreateDoubleMatrix(output_length+1, 1, mxREAL);
    /* need to deal with the fact this isn't complex */
    convert_double_to_mxvec(p_out, plhs[0]);

    plhs[1] = mxCreateDoubleMatrix(output_length+1, 1, mxCOMPLEX);
    convert_c_to_mxvec(h_out, plhs[1]);

    int valley_len, ball_len;
    if (valley_index==-1)
        {valley_len = 0;
        ball_len = 1;}
    else
        {valley_len = 1;
        ball_len = 0;}

    plhs[2] = mxCreateDoubleMatrix(valley_len, valley_len, mxREAL);
    plhs[3] = mxCreateDoubleMatrix(ball_len, ball_len, mxREAL);
    /* need to deal with the fact this isn't complex */
    if(ball_index == -1)
        // add one to convert to matlab's indexing
        {valley_index++;
        convert_int_to_mxsca(&valley_index, plhs[2]);}
    else
        // add one to convert to matlab's indexing
        {ball_index++;
        convert_int_to_mxsca(&ball_index, plhs[3]);}

    /* deallocate memory - I'm sure this would happen anyway*/
    free(p_out);
    p_out = NULL;
    free(h_out);
    h_out = NULL;
    // free(gCoeffs);
    // gCoeffs = NULL;
    // free(SPs);
    // SPs = NULL;


}