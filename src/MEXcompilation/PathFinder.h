#include <complex.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>
#include <lapacke.h>

#define sqrt2 1.414213562373095
#define PI 3.141592653589793

/* ----------------- function prototypes ------------------------*/

// mex functions
void SDpathODEuler_extend_coarse_path(
        int p_length,
        double complex g_coeffs[],
        double complex SPs[],
        double base_step_size,
        int n_max,
        double P_new_max,
        int g_order,
        double* p_log,
        double complex* h_log,
        bool* success,
        int *n);

void SDquadODEulerNEwtonCorrection(
        double *p_quad,
        double *p_coarse,
        double complex h0,
        double complex *h_coarse,
        double complex *gCoeffs,
        double freq,
        double NewtonThresh,
        int NewtonIts,
        int coarse_array_size,
        int quad_array_size,
        int gCoeffs_len,
        double complex *h_quad,
        double complex *dhdp_quad,
        int *Newton_success);

void SDpathODEuler(
        const double complex h0,
        double complex *gCoeffs,
        double complex *SPs,
        double *cover_radii,
        double complex *valleys,
        const double base_step_size,
        const int n_max,
        const double r_star,
        const double Newton_small_threshold,
        const double Newton_big_threshold,
        const int SPs_len,
        const int gCoeffs_len,
        double *p_log,
        double complex *h_log,
        int *valley_index,
        int *ball_index,
        int *n
        );

// utility functions
double complex polyval(const double complex g_coeffs[], const double complex z, int order);
void diff_poly_coeffs(const double complex g_coeffs[], double complex* dg_coeffs, int g_order);
int imax(int a, int b);
double safe_pow(double x, double p, double X);
double complex safe_cpow(const double complex x, const double complex p, const double complex X);

// subroutines used within main path tracing algorithm
double complex get_Newton_step(
    const double p,
    const double complex g_h,
    const double complex dg_h,
    const double complex g_at_se,
    // outputs
    double complex *gCoeffs,
    double complex *dgCoeffs);
void inAball(                   
    double complex h,
    double complex * SPs,
    double * cover_radii,
    int length_SPs,
    bool *yn,
    int *index);
void beyondNoReturn(            
    double complex h,
    double complex *valleys,
    double complex *gCoeffs,
    int order,
    double r_star,
    bool * in_no_return_yn,
    int * index);
void halt_euler(                
    double complex h,
    double complex *valleys,
    double complex *gCoeffs,
    const int order,
    double complex *SPs,
    double *cover_radii,
    const double r_star,
    bool *inball_yn,
    bool *in_no_return_yn,
    int *index);


/* ----------function definitions --------------------------------*/
/* ----------------- utility functions -------------------*/
double complex polyval(const double complex g_coeffs[], const double complex z, int order)
{
    // init with j=0 case, corresponding to constant coefficient
    double complex g_val;
    int j; // define for loop, within branch
    if(order>=0)
    {
        g_val = g_coeffs[order];
        for(j=1; j<=order; j++)
        {
            g_val += g_coeffs[order-j]*cpow(z,j);
        }
    }
    else // account for negative order cases
    {
        g_val = 0.0+0.0I;
    }

    return g_val;
}

void diff_poly_coeffs(const double complex g_coeffs[], double complex* dg_coeffs, int g_order)
{
    int j;
    if(g_order <= 0)
        {
        dg_coeffs[0] = 0.0+0.0I;
        }
    else
        {
        for(j=0; j<g_order; j++)// don't loop to final entry, that gets killed
            {
            // multiply by the power, elementary differentiation
            dg_coeffs[j] = g_coeffs[j]*(g_order-j);
            }
        }
}

// simple function which takes the max of two integers
int imax(int a, int b)
{
    int c;
    if(a<b){c = b;}
    else{c=a;}
    return c;
}

double safe_pow(const double x, const double p, const double X)
{
    /* produces a backup value X when 0^0 is called */
    double y;
    if(p==0)
    {
        y = X;
    }
    else{
        y = pow(x,p);
    }
    return y;
}

double complex safe_cpow(const double complex x, const double complex p, const double complex X)
{
    double y;
    if(p==0)
    {
        y = X;
    }
    else{
        y = cpow(x,p);
    }
    return y;
}

/* ------------- mexable functions -----------------------------*/

/* Routine which extends the path*/
void SDpathODEuler_extend_coarse_path(
        //inputs
        int p_length,
        double complex g_coeffs[],
        double complex SPs[],
        double base_step_size,
        int n_max,
        double P_new_max,
        int g_order,
        //outputs (as pointers)
        double* p_log,
        double complex* h_log,
        bool* success,
        int *n) 
    {
    double complex dg_coeffs[imax(g_order,1)];
    double complex ddg_coeffs[imax(g_order-1,1)];
    diff_poly_coeffs(g_coeffs,  dg_coeffs,  imax(g_order,0));
    diff_poly_coeffs(dg_coeffs,  ddg_coeffs,  imax(g_order-1,0));

    double complex h = h_log[p_length-1];
    *n = p_length-1;
    *success = true;

    // get the bits for the Forward Euler solve
    double complex dg_h; // g'(z)
    double complex ddg_h; // g''(z)
    double complex F_h;
    double p_step_size;
    double complex diff;

    while (p_log[*n] < P_new_max) {
        // increment counter:
        (*n)++;
        // set up the ODE
        dg_h = polyval(dg_coeffs, h, g_order - 1);
        ddg_h = polyval(ddg_coeffs, h, g_order - 2);
        F_h = 1.0I / dg_h;
        p_step_size = base_step_size * cabs(dg_h * dg_h / ddg_h);
        // double complex diff;
        for (int i = 0; i < g_order-1; i++) {
            diff = cabs(SPs[i] - h) / cabs(F_h);
            p_step_size = fmin(p_step_size, diff);
        }
        // forward Euler step
        h = h + p_step_size * F_h;
        // store the details
        p_log[*n] = p_log[*n - 1] + p_step_size;
        h_log[*n] = h;

        // check if its time to give up:
        if (*n == n_max) {
            *success = false;
            break;
        }
    }
}

// Routine which refines the path, onto the quadrature nodes

void SDquadODEulerNEwtonCorrection(// orig inputs
                                double *p_quad,
                                double *p_coarse,
                                double complex h0,
                                double complex *h_coarse,
                                double complex *gCoeffs,
                                double freq,
                                double NewtonThresh,
                                // extra inputs for C code
                                int NewtonIts,
                                int coarse_array_size,
                                int quad_array_size,
                                int gCoeffs_len,
                                // outputs
                                double complex *h_quad,
                                double complex *dhdp_quad,
                                int *Newton_success) 
{
    int order = gCoeffs_len - 1;
    double complex freq_times_g_at_se = freq * polyval(gCoeffs, h0, order);
    double complex dgCoeffs[gCoeffs_len - 1];
    diff_poly_coeffs(gCoeffs, dgCoeffs, order);

    double dp, dh_N;
    double complex Newton_step, err, F;

    for (int N = 0; N < quad_array_size; N++) {
        
        // get the largest coarse value of p that is less than this quad value of p
        // Linearly interpolate coarse solve for initial guess
        int coarse_index;
        double p_below;
        for (int i = 1; i < coarse_array_size; ++i){
            if (p_coarse[i] > p_quad[N]){
                coarse_index = i-1;
                p_below = p_coarse[coarse_index];
                break;
            }
        }

        // Get intermediate step size
        dp = p_quad[N] - p_below;
        F = 1.0I/(polyval(dgCoeffs,h_coarse[coarse_index],order-1)*freq);
        h_quad[N] = h_coarse[coarse_index] + dp * F;

        // Newton corrector step
        for (int n = 0; n < NewtonIts; ++n) {
            Newton_step = ((-freq_times_g_at_se + freq * polyval(gCoeffs, h_quad[N], order)) - 1.0I * p_quad[N]) / (freq * polyval(dgCoeffs, h_quad[N], order-1));

            // update quad node at this Newton step
            h_quad[N] = h_quad[N] - Newton_step;
            err = cabs(Newton_step);

            // check if we're below error threshold
            if ((double) err < (double) NewtonThresh) {
                Newton_success[N] = n + 1;
                break;
            // check if we've exceeded max number of iterations
            } else if (n == NewtonIts - 1) {
                Newton_success[N] = n + 2;
                break;
            }
        }
    }

    // Now get Jacobian
    for (int N = 0; N < quad_array_size; N++) {
        dhdp_quad[N] = 1.0I/(polyval(dgCoeffs,h_quad[N],order-1)*freq);
    }
}

/* -------------------  main code for the SD path tracing ------------------------- */

// ex-indented functions
double complex get_Newton_step(const double p,
                                const double complex g_h,
                                const double complex dg_h,
                                const double complex g_at_se,
                                // outputs
                                double complex *gCoeffs,
                                double complex *dgCoeffs)
{   double complex step;
    step = (g_h-g_at_se-1.0I*p)/dg_h;
    return step;
}

void inAball(double complex h,
            double complex * SPs,
            double * cover_radii,
            int length_SPs,
            // outputs
            bool *yn,
            int *index)
{
    // loop over all balls
    for(int n=0; n<length_SPs; n++)
    {   // check if point h is inside nth ball
        if(cover_radii[n]>0 & cabs(h-SPs[n])<cover_radii[n])
        {
            *yn = true;
            break;
        }

    }
}

void beyondNoReturn(double complex h,
                    double complex *valleys,
                    double complex *gCoeffs,
                    int order,
                    double r_star,
                    // outputs
                    bool * in_no_return_yn,
                    int * index)
{
    /*function corresponding to an event which would halt ODE solve, because SD
    path is at 'point of no return'.*/

    // the 'no return test'
    *in_no_return_yn = false;
    int gCoeffs_len = order+1;
    double R = cabs(h);
    double complex h_on_circle;
    double h_angle;
    double v_angle;
    double G;
    if(R>r_star) // first test, based on length of z

        // now check that path is sufficiently close to monomial SD path
        if(R==0)
            {h_on_circle = 0.0+0.0I;}
        else
            {h_on_circle = h/R;}

        /* my feeling is that the following could be sped up,
        if there is some standard ordering of the valleys?*/
        int v_index = 0;
        double v_dist;
        double v_min_dist = cabs(cexp(1.0I*carg(valleys[v_index]))-h_on_circle);
        for(int v_count = 1; v_count<order; v_count++)
        {
            v_dist = cabs(cexp(1.0I*carg(valleys[v_count]))-h_on_circle);
            if(v_dist<v_min_dist)
            {
                v_index = v_count;
                v_min_dist = v_dist;
            }

        }

        h_angle = carg(h_on_circle);
        v_angle = carg(valleys[v_index]);
        double theta_diff = fmin(fmin(fabs(h_angle-v_angle),fabs(h_angle-v_angle-2*PI)),fabs(h_angle-v_angle+2*PI));

        if(theta_diff < PI/(2*order))
        { // now check Dave's refined polynomial condition
            G = order*cabs(gCoeffs[0])*safe_pow(R,(order-1),0.0)*fmin(1/sqrt2,cos(order*theta_diff));
            for (int j=1; j <order; j++)
                {G -= j*cabs(gCoeffs[gCoeffs_len-j-1])*safe_pow(R,(j-1),0.0);
                if(G<=0) // G isn't getting any bigger
                    {break;}
                }
            if(G>0)
                {*in_no_return_yn = true;
                *index = v_index;}
        }
}

void halt_euler(double complex h,
            double complex *valleys,
            double complex *gCoeffs,
            const int order,
            double complex *SPs,
            double *cover_radii,
            const double r_star,
            // output pointers
            bool *inball_yn,
            bool *in_no_return_yn,
            int *index) 
    {int length_SPs = order-1;
    inAball(h, SPs, cover_radii, length_SPs, inball_yn, index);
    if (*inball_yn)
        {*in_no_return_yn = false;}
    else
        {beyondNoReturn(h,
                        valleys,
                        gCoeffs,
                        order,
                        r_star,
                        in_no_return_yn,
                        index);}
    }



void SDpathODEuler( //inputs
                    const double complex h0,
                    double complex *gCoeffs,
                    double complex *SPs,
                    double *cover_radii,
                    double complex *valleys,
                    const double base_step_size,
                    const int n_max,
                    const double r_star,
                    const double Newton_small_threshold,
                    const double Newton_big_threshold,
                    // extra inputs required to make this code work
                    const int SPs_len,
                    const int gCoeffs_len,
                    //outputs
                    double *p_log,
                    double complex *h_log,
                    int *valley_index,
                    int *ball_index,
                    int *n
                    )
{
    //version three adds error checking at each step
    //computes NSD path h(p) and h'(p)

    if(SPs_len==0)
    {
        cover_radii[0] = 0.0;
    }

    int order = gCoeffs_len - 1;
    double complex g_at_se = polyval(gCoeffs,h0,order); // value of g at steepest exit

    // derivs of g for ODE:
    double complex dgCoeffs[order];
    double complex ddgCoeffs[order-1];
    diff_poly_coeffs(gCoeffs, dgCoeffs, order);
    diff_poly_coeffs(dgCoeffs, ddgCoeffs, order-1);

    //main loop
    double complex h = h0;
    p_log[0] = 0.0;
    h_log[0] = h0;
    *n = 0;

    double complex g_h, dg_h, ddg_h, F_h;
    bool continue_loop = true;
    double p,p_step_size;
    bool inball_yn;
    bool in_no_return_yn;
    int endex;
    double SP_dists[SPs_len];
    double min_SP_dist;

    while(continue_loop)
    {
        // update g(h), g'(h) and g''(h)
        dg_h = polyval(dgCoeffs, h, order-1);
        ddg_h = polyval(ddgCoeffs, h, order-2);
        
        // get ingreidents which will be used multiple times
        (*n)++;


        // Forward Euler step
        F_h = 1.0I/dg_h;

        // get distance to closest stationary point
        // first get vector of distances to each stationary point
        for(int j=0; j<SPs_len; j++)
        {
            if(cover_radii[j]>0)
            {SP_dists[j] = cabs(SPs[j]-h);}
            else // don't care about endpoints
            {SP_dists[j] = DBL_MAX;}
        }
        // now find the smallest distance
        min_SP_dist = SP_dists[0];
        for(int j=1; j<SPs_len; j++)
        {
            if(SP_dists[j]<min_SP_dist)
            {min_SP_dist = SP_dists[j];}
        }

        p_step_size = base_step_size*fmin(2*cabs(dg_h*dg_h/ddg_h),min_SP_dist/cabs(F_h));
        h = h + p_step_size*F_h;

        // update g(h), g'(h) and g''(h)
        g_h = polyval(gCoeffs, h, order);
        dg_h = polyval(dgCoeffs, h, order-1);
        ddg_h = polyval(ddgCoeffs, h, order-2);
        
        // error checking
        p = p_log[*n-1]+p_step_size;

        double complex Newton_step = get_Newton_step(p,g_h,dg_h,g_at_se,gCoeffs,dgCoeffs);

        while(cabs(Newton_step)>Newton_big_threshold)
            {h = h-Newton_step;
            g_h = polyval(gCoeffs, h, order);
            dg_h = polyval(dgCoeffs, h, order-1);
            Newton_step = get_Newton_step(p,g_h,dg_h,g_at_se,gCoeffs,dgCoeffs);}


        // might as well apply Newton once more, as we have the step
        h = h-Newton_step;

        p_log[*n] = p;
        h_log[*n] = h;

        inball_yn = false;
        in_no_return_yn = false;
        halt_euler(//inputs:
                    h,valleys,gCoeffs,order,SPs,cover_radii,r_star,
                    // outputs
                    &inball_yn, &in_no_return_yn, &endex);

        continue_loop = !(inball_yn || in_no_return_yn);

        if(!continue_loop)
        {    if(inball_yn) // only refine endpoint to fine level if in a ball
                {// before actually halting the process, refine this endpoint
                Newton_step = get_Newton_step(p,g_h,dg_h,g_at_se,gCoeffs,dgCoeffs);
                while(cabs(Newton_step)>Newton_small_threshold)
                    {// update g(h) and g'(h)
                    h = h-Newton_step;
                    g_h = polyval(gCoeffs, h, order);
                    dg_h = polyval(dgCoeffs, h, order-1);
                    Newton_step = get_Newton_step(p,g_h,dg_h,g_at_se,gCoeffs,dgCoeffs);}
                // might as well apply Newton once more
                h_log[*n] = h-Newton_step;
                *ball_index = endex;
                }
            else
                {*valley_index = endex;}
        }

        // if we've reached the end of the buffer, extend it
        if (*n%n_max==0)
            {
            p_log = realloc(p_log,sizeof(double)*(*n+n_max));
            h_log = realloc(h_log,sizeof(double complex)*(*n+n_max));
            }
    }

    // delete excess memory that was allocated
    p_log = realloc(p_log,sizeof(double)*(*n+1));
    h_log = realloc(h_log,sizeof(double complex)*(*n+1));

}