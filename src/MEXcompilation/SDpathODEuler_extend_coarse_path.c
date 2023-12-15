#include "mex.h"
#include "PathFinder.h"
#include "interface.h"

//SDpathODEuler_extend_coarse_path(p_init, h_init, gCoeffs, SPs, base_step_size, n_max, P_new_max)
//                                  0    ,  1    ,  2     , 3  ,    4          ,    5 ,   6           
// the mex gateway to SDpathODEEuler_extend_coarse_path
void mexFunction(int nlhs, mxArray *plhs[],
                int nrhs, const mxArray *prhs[])
{
    /* --------------- set inputs, by converting to C variables ----------------- */
//     number of entries in main vectors, so far
    int n_max;
    convert_mxsca_to_int(prhs[5], &n_max);

    // p so far
    double *p_log = malloc(n_max * sizeof(double));
    convert_mxvec_to_double(prhs[0],p_log);

    int p_length = mxGetM(prhs[0]);

    // path h(p) so far
    double complex *h_log = malloc(n_max * sizeof(double complex));
    convert_mxvec_to_c(prhs[1],h_log);

    // phase coefficients
    int g_coeffs_len = mxGetM(prhs[2]);
    double complex gCoeffs[g_coeffs_len];
    convert_mxvec_to_c(prhs[2],gCoeffs);

    //deduce order of polynomial from length of coeffs vector
    int g_order = g_coeffs_len-1;

    // stationary points
    int SPs_len = mxGetM(prhs[3]);
    double complex SPs[SPs_len];
    convert_mxvec_to_c(prhs[3],SPs);
    
    // base step size
    double base_step_size;
    convert_mxsca_to_double(prhs[4],&base_step_size);

    // new val of max p that must be exceeded
    double P_new_max;
    convert_mxsca_to_double(prhs[6],&P_new_max);
    

    /* --------------- initialise outputs, as C variables ----------------- */
    //outputs (as pointers)
    bool success; // turns to fail when we exceed max number of steps
    int output_length; // length of p_init and h_init vectors which will be truncated at the end

//     /* -------------- Run main C routine, in PathFinder.h ------------------- */
    SDpathODEuler_extend_coarse_path(
        //inputs
        p_length,
        gCoeffs,
        SPs,
        base_step_size,
        n_max,
        P_new_max,
        g_order,
        //outputs (as pointers)
        p_log,
        h_log,
        &success,
        &output_length);

//     /* ------------------ make the outputs for matlab ------------------------------- */
//     // matlab outputs: [p_log_out, h_log_out, success]
    plhs[0] = mxCreateDoubleMatrix(output_length,1,mxCOMPLEX);
    plhs[1] = mxCreateDoubleMatrix(output_length,1,mxCOMPLEX);
    convert_double_to_mxvec(p_log,plhs[0]);
    convert_c_to_mxvec(h_log,plhs[1]);

    plhs[2] =  mxCreateDoubleMatrix(1,1,mxCOMPLEX);
    int yn;
    if(success){yn = 1;}
    else {yn = 0;}
    convert_int_to_mxsca(&yn, plhs[2]);

    free(p_log);
    free(h_log);

}