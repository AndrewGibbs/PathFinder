#include <complex.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>
#include <lapacke.h>

#define sqrt2 1.414213562373095
#define PI 3.141592653589793

/* ----------------- function prototypes ------------------------*/

// mex functions
void sd_path_ode_euler_extend_coarse_path(
    const int p_length,
    const double complex phase_coeffs[],
    const double complex stationary_points[],
    const double base_step_size,
    const int n_max,
    const double p_new_max,
    const int g_order,
    double *p_log,
    double complex *h_log,
    bool *success,
    int *n);

void sd_quad_ode_euler_correction(
    double *p_quad,
    double *p_coarse,
    const double complex h0,
    double complex *h_coarse,
    double complex *phase_coeffs,
    const double freq,
    const double newton_thresh,
    const int newton_its,
    const int coarse_array_size,
    const int quad_array_size,
    const int phase_coeffs_len,
    double complex *h_quad,
    double complex *dhdp_quad,
    int *newton_success);

void sd_path_ode_euler(
    const double complex h0,
    double complex *phase_coeffs,
    double complex *stationary_points,
    double *cover_radii,
    double complex *valleys,
    const double base_step_size,
    const int n_max,
    const double r_star,
    const double newton_small_threshold,
    const double newton_big_threshold,
    const int stationary_points_len,
    const int phase_coeffs_len,
    double *p_log,
    double complex *h_log,
    int *valley_index,
    int *ball_index,
    int *n);

// utility functions
double complex polyval(const double complex poly_coeffs[],
                       const double complex z,
                       int poly_order);

void get_diff_poly_coeffs(const double complex poly_coeffs[],
                      double complex *diff_poly_coeffs,
                      int poly_order);

int imax(const int a,
         const int b);

double safe_pow(const double x,
                const double p,
                const double X);

double complex safe_cpow(const double complex x,
                         const double complex p,
                         const double complex X);

// subroutines used within main path tracing algorithm
double complex get_newton_step(
    const double p,
    const double complex g_h,
    const double complex dg_h,
    const double complex g_at_se);

void in_a_ball(
    const double complex h,
    double complex *stationary_points,
    double *cover_radii,
    const int stationary_points_len,
    bool *yn,
    int *index);

void beyond_no_return(
    const double complex h,
    const double complex *valleys,
    const double complex *phase_coeffs,
    const int order,
    const double r_star,
    bool *in_no_return_yn,
    int *index);

void halt_euler(
    const double complex h,
    double complex *valleys,
    double complex *phase_coeffs,
    const int order,
    const int stationary_points_len,
    double complex *stationary_points,
    double *cover_radii,
    const double r_star,
    bool *inball_yn,
    bool *in_no_return_yn,
    int *index);

/* ----------function definitions --------------------------------*/
/* ----------------- utility functions -------------------*/
double complex polyval(const double complex poly_coeffs[],
                       const double complex z,
                       int order)
{
    // init with j=0 case, corresponding to constant coefficient
    double complex poly_val;
    int j; // define for loop, within branch
    if (order >= 0)
    {
        poly_val = poly_coeffs[order];
        for (j = 1; j <= order; j++)
        {
            poly_val += poly_coeffs[order - j] * cpow(z, j);
        }
    }
    else // account for negative order cases
    {
        poly_val = 0.0 + 0.0I;
    }

    return poly_val;
}

void get_diff_poly_coeffs(const double complex poly_coeffs[],
                      double complex *diff_poly_coeffs,
                      int poly_order)
{
    int j;
    if (poly_order <= 0)
    {
        diff_poly_coeffs[0] = 0.0 + 0.0I;
    }
    else
    {
        for (j = 0; j < poly_order; j++) // don't loop to final entry, that gets killed
        {
            // multiply by the power, elementary differentiation
            diff_poly_coeffs[j] = poly_coeffs[j] * (poly_order - j);
        }
    }
}

// simple function which takes the max of two integers
int imax(const int a, const int b)
{
    int c;
    if (a < b)
    {
        c = b;
    }
    else
    {
        c = a;
    }
    return c;
}

double safe_pow(const double x, const double p, const double X)
{
    /* produces a backup value X when 0^0 is called */
    double y;
    if (x == 0 & p == 0)
    {
        y = X;
    }
    else
    {
        y = pow(x, p);
    }
    return y;
}

double complex safe_cpow(const double complex x,
                         const double complex p,
                         const double complex X)
{
    double y;
    if (x == 0 & p == 0)
    {
        y = X;
    }
    else
    {
        y = cpow(x, p);
    }
    return y;
}

/* ------------- mexable functions -----------------------------*/

/* Routine which extends the path*/
void sd_path_ode_euler_extend_coarse_path(
    // inputs
    const int p_length,
    const double complex poly_coeffs[],
    const double complex stationary_points[],
    const double base_step_size,
    const int n_max,
    const double p_new_max,
    const int phase_order,
    // outputs (as pointers)
    double *p_log,
    double complex *h_log,
    bool *success,
    int *n)
{
    double complex diff_poly_coeffs[imax(phase_order, 1)];
    double complex diffdiff_poly_coeffs[imax(phase_order - 1, 1)];
    get_diff_poly_coeffs(poly_coeffs, diff_poly_coeffs, imax(phase_order, 0));
    get_diff_poly_coeffs(diff_poly_coeffs, diffdiff_poly_coeffs, imax(phase_order - 1, 0));

    double complex h = h_log[p_length - 1];
    *n = p_length - 1;
    *success = true;

    // get the bits for the Forward Euler solve
    double complex dg_h;  // g'(h(p))
    double complex ddg_h; // g''(h(p))
    double complex ode_h;
    double p_step_size;
    double complex diff;

    while (p_log[*n] < p_new_max)
    {
        // increment counter:
        (*n)++;
        // set up the ODE
        dg_h = polyval(diff_poly_coeffs, h, phase_order - 1);
        ddg_h = polyval(diffdiff_poly_coeffs, h, phase_order - 2);
        ode_h = 1.0I / dg_h;
        p_step_size = base_step_size * cabs(dg_h * dg_h / ddg_h);
        // double complex diff;
        for (int i = 0; i < phase_order - 1; i++)
        {
            diff = cabs(stationary_points[i] - h) / cabs(ode_h);
            p_step_size = fmin(p_step_size, diff);
        }
        // forward Euler step
        h = h + p_step_size * ode_h;
        // store the details
        p_log[*n] = p_log[*n - 1] + p_step_size;
        h_log[*n] = h;

        // check if its time to give up:
        if (*n == n_max)
        {
            *success = false;
            break;
        }
    }
}

// Routine which refines the path, onto the quadrature nodes

void sd_quad_ode_euler_correction( // orig inputs
    double *p_quad,
    double *p_coarse,
    const double complex h0,
    double complex *h_coarse,
    double complex *phase_coeffs,
    const double freq,
    const double newton_thresh,
    // extra inputs for C code
    const int newton_its,
    const int coarse_array_size,
    const int quad_array_size,
    const int phase_coeffs_len,
    // outputs
    double complex *h_quad,
    double complex *dhdp_quad,
    int *Newton_success)
{
    int order = phase_coeffs_len - 1;
    double complex freq_times_g_at_se = freq * polyval(phase_coeffs, h0, order);
    double complex diff_phase_coeffs[phase_coeffs_len - 1];
    get_diff_poly_coeffs(phase_coeffs, diff_phase_coeffs, order);

    double dp, dh_N;
    double complex Newton_step, err, F;

    for (int N = 0; N < quad_array_size; N++)
    {

        // get the largest coarse value of p that is less than this quad value of p
        // Linearly interpolate coarse solve for initial guess
        int coarse_index;
        double p_below;
        for (int i = 1; i < coarse_array_size; ++i)
        {
            if (p_coarse[i] > p_quad[N])
            {
                coarse_index = i - 1;
                p_below = p_coarse[coarse_index];
                break;
            }
        }

        // Get intermediate step size
        dp = p_quad[N] - p_below;
        F = 1.0I / (polyval(diff_phase_coeffs, h_coarse[coarse_index], order - 1) * freq);
        h_quad[N] = h_coarse[coarse_index] + dp * F;

        // Newton corrector step
        for (int n = 0; n < newton_its; ++n)
        {
            Newton_step = ((-freq_times_g_at_se + freq * polyval(phase_coeffs, h_quad[N], order)) - 1.0I * p_quad[N]) / (freq * polyval(diff_phase_coeffs, h_quad[N], order - 1));

            // update quad node at this Newton step
            h_quad[N] = h_quad[N] - Newton_step;
            err = cabs(Newton_step);

            // check if we're below error threshold
            if ((double)err < (double)newton_thresh)
            {
                Newton_success[N] = n + 1;
                break;
                // check if we've exceeded max number of iterations
            }
            else if (n == newton_its - 1)
            {
                Newton_success[N] = n + 2;
                break;
            }
        }
    }

    // Now get Jacobian
    for (int N = 0; N < quad_array_size; N++)
    {
        dhdp_quad[N] = 1.0I / (polyval(diff_phase_coeffs, h_quad[N], order - 1) * freq);
    }
}

/* -------------------  main code for the SD path tracing ------------------------- */

// ex-indented functions
double complex get_newton_step(const double p,
                               const double complex g_h,
                               const double complex dg_h,
                               const double complex g_at_se)
{
    double complex step;
    step = (g_h - g_at_se - 1.0I * p) / dg_h;
    return step;
}

void in_a_ball(const double complex h,
               double complex *stationary_points,
               double *cover_radii,
               const int stationary_points_len,
               // outputs
               bool *yn,
               int *index)
{
    // loop over all balls
    for (int n = 0; n < stationary_points_len; n++)
    { // check if point h is inside nth ball
        if (cover_radii[n] > 0 & cabs(h - stationary_points[n]) < cover_radii[n])
        {
            *yn = true;
            *index = n;
            break;
        }
    }
}

void beyond_no_return(const double complex h,
                      const double complex *valleys,
                      const double complex *phase_coeffs,
                      const int phase_order,
                      const double r_star,
                      // outputs
                      bool *in_no_return_yn,
                      int *index)
{
    /*function corresponding to an event which would halt ODE solve, because SD
    path is at 'point of no return'.*/

    // the 'no return test'
    *in_no_return_yn = false;
    int phase_coeffs_len = phase_order + 1;
    double R = cabs(h);
    double complex h_on_circle;
    double h_angle, v_angle, theta_diff;
    double bounded_poly_val;
    int v_index = 0;
    double v_dist;
    int v_count, j;

    if (R > r_star) // first test, based on length of z
    {
        // now check that path is sufficiently close to monomial SD path
        if (R == 0)
        {
            h_on_circle = 0.0 + 0.0I;
        }
        else
        {
            h_on_circle = h / R;
        }

        /* my feeling is that the following could be sped up,
        if there is some standard ordering of the valleys?*/
        double v_min_dist = cabs(cexp(1.0I * carg(valleys[v_index])) - h_on_circle);
        
        for (v_count = 1; v_count < phase_order; v_count++)
        {
            v_dist = cabs(cexp(1.0I * carg(valleys[v_count])) - h_on_circle);
            if (v_dist < v_min_dist)
            {
                v_index = v_count;
                v_min_dist = v_dist;
            }
        }

        h_angle = carg(h_on_circle);
        v_angle = carg(valleys[v_index]);
        double theta_diff = fmin(fmin(fabs(h_angle - v_angle), fabs(h_angle - v_angle - 2 * PI)), fabs(h_angle - v_angle + 2 * PI));

        if (theta_diff < PI / (2 * phase_order))
        { // now check Dave's refined polynomial condition
            bounded_poly_val = phase_order * cabs(phase_coeffs[0]) * safe_pow(R, (phase_order - 1), 0.0) * fmin(1 / sqrt2, cos(phase_order * theta_diff));
            for (j = 1; j < phase_order; j++)
            {
                bounded_poly_val -= j * cabs(phase_coeffs[phase_coeffs_len - j - 1]) * safe_pow(R, (j - 1), 0.0);
                if (bounded_poly_val <= 0) // G isn't getting any bigger
                {
                    break;
                }
            }
            if (bounded_poly_val > 0)
            {
                *in_no_return_yn = true;
                *index = v_index;
            }
        }
    }
}

void halt_euler(const double complex h,
                double complex *valleys,
                double complex *phase_coeffs,
                const int order,
                const int stationary_points_len,
                double complex *stationary_points,
                double *cover_radii,
                const double r_star,
                // output pointers
                bool *inball_yn,
                bool *in_no_return_yn,
                int *index)
{
    in_a_ball(h,
              stationary_points,
              cover_radii,
              stationary_points_len,
              inball_yn,
              index);
    if (*inball_yn)
    {
        *in_no_return_yn = false;
    }
    else
    {
        beyond_no_return(h,
                         valleys,
                         phase_coeffs,
                         order,
                         r_star,
                         in_no_return_yn,
                         index);
    }
}

void sd_path_ode_euler( // inputs
    const double complex h0,
    double complex *phase_coeffs,
    double complex *stationary_points,
    double *cover_radii,
    double complex *valleys,
    const double base_step_size,
    const int n_max,
    const double r_star,
    const double newton_small_threshold,
    const double newton_big_threshold,
    // extra inputs required to make this code work
    const int stationary_points_len,
    const int phase_coeffs_len,
    // outputs
    double *p_log,
    double complex *h_log,
    int *valley_index,
    int *ball_index,
    int *n)
{
    // version three adds error checking at each step
    // computes NSD path h(p) and h'(p)

    if (stationary_points_len == 0)
    {
        cover_radii[0] = 0.0;
    }

    int phase_order = phase_coeffs_len - 1;
    double complex g_at_se = polyval(phase_coeffs, h0, phase_order); // value of g at steepest exit

    // derivs of g for ODE:
    double complex diff_phase_coeffs[phase_order];
    double complex diffdiff_phase_coeffs[phase_order - 1];
    get_diff_poly_coeffs(phase_coeffs, diff_phase_coeffs, phase_order);
    get_diff_poly_coeffs(diff_phase_coeffs, diffdiff_phase_coeffs, phase_order - 1);

    // main loop
    double complex h = h0;
    p_log[0] = 0.0;
    h_log[0] = h0;
    *n = 0;

    double complex g_h, dg_h, ddg_h, ode_h;
    bool continue_loop = true;
    double p, p_step_size;
    bool inball_yn;
    bool in_no_return_yn;
    int endex;
    double stationary_point_dists[stationary_points_len];
    double min_stationary_point_dist;

    while (continue_loop)
    {
        // update g(h), g'(h) and g''(h)
        dg_h = polyval(diff_phase_coeffs, h, phase_order - 1);
        ddg_h = polyval(diffdiff_phase_coeffs, h, phase_order - 2);

        // get ingreidents which will be used multiple times
        (*n)++;

        // Forward Euler step
        ode_h = 1.0I / dg_h;

        // get distance to closest stationary point
        // first get vector of distances to each stationary point
        for (int j = 0; j < stationary_points_len; j++)
        {
            if (cover_radii[j] > 0)
            {
                stationary_point_dists[j] = cabs(stationary_points[j] - h);
            }
            else // don't care about endpoints
            {
                stationary_point_dists[j] = DBL_MAX;
            }
        }
        // now find the smallest distance
        min_stationary_point_dist = stationary_point_dists[0];
        for (int j = 1; j < stationary_points_len; j++)
        {
            if (stationary_point_dists[j] < min_stationary_point_dist)
            {
                min_stationary_point_dist = stationary_point_dists[j];
            }
        }

        p_step_size = base_step_size * fmin(2 * cabs(dg_h * dg_h / ddg_h), min_stationary_point_dist / cabs(ode_h));
        h = h + p_step_size * ode_h;

        // update g(h), g'(h) and g''(h)
        g_h = polyval(phase_coeffs, h, phase_order);
        dg_h = polyval(diff_phase_coeffs, h, phase_order - 1);
        ddg_h = polyval(diffdiff_phase_coeffs, h, phase_order - 2);

        // error checking
        p = p_log[*n - 1] + p_step_size;

        double complex newton_step = get_newton_step(p, g_h, dg_h, g_at_se);

        while (cabs(newton_step) > newton_big_threshold)
        {
            h = h - newton_step;
            g_h = polyval(phase_coeffs, h, phase_order);
            dg_h = polyval(diff_phase_coeffs, h, phase_order - 1);
            newton_step = get_newton_step(p, g_h, dg_h, g_at_se);
        }

        // might as well apply Newton once more, as we have the step
        h = h - newton_step;

        p_log[*n] = p;
        h_log[*n] = h;

        inball_yn = false;
        in_no_return_yn = false;
        halt_euler( // inputs:
            h, valleys, phase_coeffs, phase_order, stationary_points_len, stationary_points, cover_radii, r_star,
            // outputs
            &inball_yn, &in_no_return_yn, &endex);

        continue_loop = !(inball_yn || in_no_return_yn);

        if (!continue_loop)
        {
            if (inball_yn) // only refine endpoint to fine level if in a ball
            {              // before actually halting the process, refine this endpoint
                newton_step = get_newton_step(p, g_h, dg_h, g_at_se);
                while (cabs(newton_step) > newton_small_threshold)
                { // update g(h) and g'(h)
                    h = h - newton_step;
                    g_h = polyval(phase_coeffs, h, phase_order);
                    dg_h = polyval(diff_phase_coeffs, h, phase_order - 1);
                    newton_step = get_newton_step(p, g_h, dg_h, g_at_se);
                }
                // might as well apply Newton once more
                h_log[*n] = h - newton_step;
                *ball_index = endex;
            }
            else
            {
                *valley_index = endex;
            }
        }

        // if we've reached the end of the buffer, extend it
        if (*n % n_max == 0)
        {
            p_log = realloc(p_log, sizeof(double) * (*n + n_max));
            h_log = realloc(h_log, sizeof(double complex) * (*n + n_max));
        }
    }

    // delete excess memory that was allocated
    p_log = realloc(p_log, sizeof(double) * (*n + 1));
    h_log = realloc(h_log, sizeof(double complex) * (*n + 1));
}