
#include <complex.h>
#include <math.h>
// #include "mex.h"
#include "PathFinder.h"
// #include "interface.h"

/*
Values were chosen by running
    PathFinder(-1,1,[],[1 0 0],10,10);
and putting breakpoints in l46/l53 of getQuad.m
*/

int main()
{
    //inputs - need to allocate these, find an example using matlab
    int n_max = 50000;
    double *p_log = calloc(n_max, sizeof(double));
        p_log[0] = 0.0;
        p_log[1] = 0.2;
    int p_length = 2;
    double complex *h_log = calloc(n_max, sizeof(double complex));
    // =  {-1.0 + 0I, -1.004950495049505-0.099504950495050I};
        h_log[0] = -1.0 + 0I;
        h_log[1] = -1.004950495049505-0.099504950495050I;

    double complex gCoeffs[3] = {1.0+0I, 0.0+0I, 0.0+0I};
    double complex SPs[1] = {0.0+0.0I};
    double base_step_size = 0.1;
    double P_new_max = 2.992069701227389;
    int g_order = 2;
    //outputs (as pointers)
    bool success;
    int output_length;

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

        printf("\nfinal length:\t%d",output_length+1); // 11
        printf("\nfinal p:\t%.4f",p_log[output_length]); // 3.215433895880963
        printf("\nfinal h:\t%.4f+i%.4f\n",creal(h_log[output_length]),cimag(h_log[output_length])); // -1.477518161634158 - 1.126730006000000i

}