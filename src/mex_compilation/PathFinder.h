#ifndef COMPLEX_H
#include <complex.h>
#endif

#ifndef MATH_H
#include <math.h>
#endif

#define sqrt2 1.414213562373095

// Define pi if required
#if !defined(PI)
#define PI 3.141592653589793
#endif

// DBL_MAX, which we treat as infinite
#if !defined(DBL_MAX)
#define DBL_MAX 1.79769e+308
#endif

/* ----------------- function prototypes ------------------------*/

// mex functions
void sd_path_ode_euler_extend_coarse_path(
    const int p_length,
    const double complex *phase_coeffs,
    const double complex *stationary_points,
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
    const int max_newton_its,
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
    double *ball_radii,
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
double complex polyval(const double complex *poly_coeffs,
                       const double complex z,
                       int poly_order);

void get_diff_poly_coeffs(const double complex *poly_coeffs,
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
    double *ball_radii,
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
    double *ball_radii,
    const double r_star,
    bool *inball_yn,
    bool *in_no_return_yn,
    int *index);

/* ----------function definitions --------------------------------*/
/* ----------------- utility functions -------------------*/

/**
 * Evaluates a polynomial g(z) at a given point z.
 *
 * @param poly_coeffs The complex coefficients of the polynomial g.
 * @param z The (complex) value of the input.
 * @param order The integer order/degree of the polynomial g.
 * @return The value g(z).
 */
double complex polyval(const double complex *poly_coeffs,
                       const double complex z,
                       int order)
{
    // init with j=0 case, corresponding to constant coefficient
    double complex poly_val;
    int j; // define for loop, within branch
    if (order >= 0)
    {
        // initialise with constant coefficient value
        poly_val = poly_coeffs[order];

        // add each term in polynomial
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

/**
For a polynomial g(z), return the coefficients of g'(z).
 *
 * @param poly_coeffs The coefficients of g.
 * @param diff_poly_coeffs The output coefficients of g'.
 * @param poly_order The order/degree of g.
*/
void get_diff_poly_coeffs(const double complex *poly_coeffs,
                          double complex *diff_poly_coeffs,
                          int poly_order)
{
    int j;
    if (poly_order <= 0)
    {
        // handle special case of zero order
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

/**
 * simple function which takes the max of two integers
 *
 * @param a First integer.
 * @param b Second integer.
 * @return Max value, variable c.
 */
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

/**
 * A small extension of 'pow', which returns a numeric value for 0^0
 *
 * @param x The (double) base.
 * @param p The (double) exponent/power.
 * @param safe_output The special value assigned to 0^0.
 * @return x^p, or safe_output when x=p=0.
 */
double safe_pow(const double x, const double p, const double safe_output)
{
    /* produces a backup value X when 0^0 is called */
    double y;
    if (x == 0 & p == 0)
    {
        y = safe_output;
    }
    else
    {
        y = pow(x, p);
    }
    return y;
}

/*
A version of safe_pow (above) for complex inputs
 *
 * @param x The (complex) base.
 * @param p The (complex) exponent/power.
 * @param safe_output The special value assigned to 0^0.
 * @return x^p, or safe_output when x=p=0.
 */
double complex safe_cpow(const double complex x,
                         const double complex p,
                         const double complex safe_output)
{
    double y;
    if (x == 0 & p == 0)
    {
        y = safe_output;
    }
    else
    {
        y = cpow(x, p);
    }
    return y;
}

/* ------------- mexable functions -----------------------------*/

/**
 * Extends the steepest descent path h(p) induced by phase g(z).
 * This may be required for initial guess of quadrature points.
 *
 * @param p_length (double) Length of parameter points which are stored.
 * @param poly_coeffs Complex double coefficients of polynomial phase.
 * @param stationary_points Complex stationary points of g.
 * @param base_step_size, Positive double parameter which scales ODE steps.
 * @param n_max Maximum (integer) number of ODE steps to try before failing.
 * @param p_new_max Positive double value of p such that h(p) will be final
 *                  quadrature point.
 * @param phase_order Integer order/degree of polynomial phase g.
 * @param p_log (double) Parameter points p at which h(p) is approximated.
 * @param h_log (double complex) approximate values of h(p) at parameter points p.
 * @param success Boolean, output as true when ODE iteration converges for each point.
 * @param n (integer) Number of points approximating h(p).
 */
void sd_path_ode_euler_extend_coarse_path(
    // inputs
    const int p_length,
    const double complex *poly_coeffs,
    const double complex *stationary_points,
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
    double complex diff_poly_coeffs[imax(phase_order, 1)];         // coeffs of g'(z)
    double complex diffdiff_poly_coeffs[imax(phase_order - 1, 1)]; // coeffs of g''(z)
    get_diff_poly_coeffs(poly_coeffs, diff_poly_coeffs, imax(phase_order, 0));
    get_diff_poly_coeffs(diff_poly_coeffs, diffdiff_poly_coeffs, imax(phase_order - 1, 0));

    // start end of path at final coarse point
    double complex h = h_log[p_length - 1];
    *n = p_length - 1;
    *success = true;

    // get the bits for the Forward Euler solve
    double complex dg_h;  // g'(h(p))
    double complex ddg_h; // g''(h(p))
    double complex ode_h; // value of ODE function at h(p)
    double p_step_size;   // incremental step in path parameter p
    double complex diff;  // scaled distance to nearest stationary point

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
            // shrink step size if too close to a stationary point
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

/**
Refines the coarse path approximation of h(p) (induced by g(z))
onto the quadrature nodes
*
* @param p_quad Array of doubles, points 'p_j'
                at which coarse approximation of h(p) is required.
* @param p_coarse Array of doubles, points 'p'
                at which h(p) is approximated (coarsely).
* @param h0 Initial value h(0), complex double.
* @param h_coarse Approximate points h(p), array of complex doubles.
* @param phase_coeffs Complex coefficients of phase function g.
* @param freq *Positive frequency parameter.
* @param newton_thresh *Accuracy required for Newton iteration (double)
* @param max_newton_its *Maximum number of Newton iterations to try (double).
* @param coarse_array_size Integer length of arrays 'p_coarse' and 'h_coarse'.
* @param quad_array_size Integer length of output quadrature points required.
* @param phase_coeffs_len Integer length of coefficients vector of g.
* @param h_quad Complex double array of quadrature points h(p_j).
* @param dhdp_quad Complex double array of Jacobian h'(p_j) at quadrature points.
* @param Newton_success Integer count of points taken for Newton to converge.
*/
void sd_quad_ode_euler_correction( // orig inputs
    double *p_quad,
    double *p_coarse,
    const double complex h0,
    double complex *h_coarse,
    double complex *phase_coeffs,
    const double freq,
    const double newton_thresh,
    // extra inputs for C code
    const int max_newton_its,
    const int coarse_array_size,
    const int quad_array_size,
    const int phase_coeffs_len,
    // outputs
    double complex *h_quad,
    double complex *dhdp_quad,
    int *Newton_success)
{
    int order = phase_coeffs_len - 1; // order of polynomial phase

    // scaled (by frequency/omega) value of phase at exit/endpoint
    double complex freq_times_g_at_se = freq * polyval(phase_coeffs, h0, order);

    double complex diff_phase_coeffs[phase_coeffs_len - 1]; // coeffs of g'(z)
    get_diff_poly_coeffs(phase_coeffs, diff_phase_coeffs, order);

    double dp; // difference between closest coarse path param value
               // and required param value
    double complex Newton_step;
    double complex err; // Residual error after applying Newton step
    double complex F;   // Newton cost function

    for (int N = 0; N < quad_array_size; N++)
    {
        // get the largest coarse value of p that is less than this quad value of p
        // Linearly interpolate coarse solve for initial guess
        int coarse_index; // index of point on coarse path
        double p_below;   // largest param value that is less than param value at point

        // now assign these values:
        for (int i = 1; i < coarse_array_size; ++i)
        {
            if (p_coarse[i] > p_quad[N])
            {
                coarse_index = i - 1;
                p_below = p_coarse[coarse_index];
                break;
            }
        }

        // Get initial guess by interpolation
        dp = p_quad[N] - p_below;
        F = 1.0I / (polyval(diff_phase_coeffs, h_coarse[coarse_index], order - 1) * freq);
        h_quad[N] = h_coarse[coarse_index] + dp * F;

        // Now correct via Newton method
        for (int n = 0; n < max_newton_its; ++n)
        {
            Newton_step = ((-freq_times_g_at_se +
                            freq * polyval(phase_coeffs, h_quad[N], order)) -
                           1.0I * p_quad[N]) /
                          (freq *
                           polyval(diff_phase_coeffs, h_quad[N], order - 1));

            // update quad node at this Newton step
            h_quad[N] = h_quad[N] - Newton_step;
            // also update error measurement
            err = cabs(Newton_step);

            // check if we're below error threshold
            if ((double)err < (double)newton_thresh)
            {
                Newton_success[N] = n + 1;
                break;
                // check if we've exceeded max number of iterations
            }
            else if (n == max_newton_its - 1)
            {
                Newton_success[N] = n + 2;
                break;
            }
        }
    }

    // Now get Jacobian h'(p)
    for (int N = 0; N < quad_array_size; N++)
    {
        dhdp_quad[N] = 1.0I / (polyval(diff_phase_coeffs, h_quad[N], order - 1) * freq);
    }
}

/* -------------------  main codes for the SD path tracing ------------------------- */

/**
Performs a single Newton step, for a path point h(p), induced by phase g(z)
*
* @param p The parameter p at which we are refining. Positive double.
* @param g_h Approximation of g(h(p)), based on approximate h. Complex double.
* @param dg_h Approximation of g'(h(p)), based on approximate h. Complex double.
* @param g_at_se Value of g(h(0)). Complex double.
* @return The complex double Newton step.
*/
double complex get_newton_step(const double p,
                               const double complex g_h,
                               const double complex dg_h,
                               const double complex g_at_se)
{
    double complex step;
    step = (g_h - g_at_se - 1.0I * p) / dg_h;
    return step;
}

/**
 * Determines if point z is in a complex ball
 *
 * @param z The (complex double) point to be tested.
 * @param ball_centres Points (complex doubles) at centres of each ball.
 * @param ball_radii Radii of each ball, doubles.
 * @param ball_centres_len Integer length of 'ball_centres' and 'ball_radii'.
 * @param yn Boolean. This is true if the point z is inside a ball.
 * @param index Integer index of the ball that z is inside of.
 */
void in_a_ball(const double complex z,
               double complex *ball_centres,
               double *ball_radii,
               const int ball_centres_len,
               // outputs
               bool *yn,
               int *index)
{
    // loop over all balls
    for (int n = 0; n < ball_centres_len; n++)
    { // check if point z is inside nth ball
        if (ball_radii[n] > 0 & cabs(z - ball_centres[n]) < ball_radii[n])
        {
            *yn = true;
            *index = n;
            break;
        }
    }
}

/**
 * Determines if a point h is in a 'region of no return', induced by polynomial g(z).
 * Practically, this halts the ODE solve; beyond this point the qualitative
 * understanding of the topology is sufficient. Details and rationale are given in
 * the main paper.
 *
 * @param h Complex point to test
 * @param valleys Complex valleys, stored as points on unit circle
 * @param phase_coeffs Complex coefficients of polynomial g
 * @param phase_order Integer degree/order of polynomial g
 * @param r_star Positive value of $r_*$, described in paper
 * @param in_no_return_yn *Bookean, true when h is in region of no return
 * @param index *Index of valley corresponding to no return region
 */
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

    *in_no_return_yn = false;               // initialise to false
    int phase_coeffs_len = phase_order + 1; // determine coeffs length from the order
    double R = cabs(h);                     // key parameter R, modulus of leading point of SD path
    double complex h_on_circle;             // h(p)/R, i.e. on unit circle
    double h_angle;                         // angle/argument of h(p)
    double v_angle;                         // angle/argument of valley to which we are comparing h(p)
    double theta_diff;                      // difference between angles
    double bounded_poly_val;                // value of upper bound on lower coefficients
    int v_index = 0;                        // initialise valley index for loop
    double v_dist;                          // complex distance from valley to h(p)/R on unit circle

    // Initialising iterators here incase loop never happens.
    int v_count; // loop iterator - index of valley
    int j;       // loop iterator - polynomial coefficient

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

        // get distance on complex unit circle
        double v_min_dist = cabs(cexp(1.0I * carg(valleys[v_index])) - h_on_circle);

        // loop over all valleys, check find which is closest on unit circle
        for (v_count = 1; v_count < phase_order; v_count++)
        {
            v_dist = cabs(cexp(1.0I * carg(valleys[v_count])) - h_on_circle);
            if (v_dist < v_min_dist)
            {
                v_index = v_count;
                v_min_dist = v_dist;
            }
        }

        // now get argument of h(p)
        h_angle = carg(h_on_circle);
        // angle of valley
        v_angle = carg(valleys[v_index]);
        // compare the two angles
        double theta_diff = fmin(fmin(fabs(h_angle - v_angle),
                                      fabs(h_angle - v_angle - 2 * PI)),
                                 fabs(h_angle - v_angle + 2 * PI));

        // if difference in angle is sufficiently small, check polynomial condition
        if (theta_diff < PI / (2 * phase_order))
        {
            // initialise polynomial bound value using highest order term
            bounded_poly_val = phase_order * cabs(phase_coeffs[0]) * safe_pow(R, (phase_order - 1), 0.0) * fmin(1 / sqrt2, cos(phase_order * theta_diff));

            // loop over all coefficients
            for (j = 1; j < phase_order; j++)
            {
                // note that we are only subtracting values
                bounded_poly_val -= j * cabs(phase_coeffs[phase_coeffs_len - j - 1]) * safe_pow(R, (j - 1), 0.0);
                if (bounded_poly_val <= 0)
                {
                    // need bound to be positive, so if negative, can break early
                    break;
                }
            }
            if (bounded_poly_val > 0)
            {
                // both angular and radial conditions satisfied:
                // in region of no return
                *in_no_return_yn = true;
                *index = v_index;
            }
        }
    }
}

/**
 * Combines 'beyond_no_return' and 'in_a_ball' to test if steepest descent
 * contour tracing should be halted at the current point.
 *
 * @param h Complex point to be tested, at the front of the contour
 * @param valleys Complex valleys of the phase function inducing the contour
 * @param phase_coeffs Complex coefficients of the phase function
 * @param order Integer order of the phase function
 * @param stationary_points_len Integer length of 'stationary_points' array
 * @param stationary_points Complex array of stationary points of phase function
 * @param ball_radii Positive real array of radii of balls to test
 * @param r_star Positive constant $r_*>0$, details in paper
 * @param inball_yn Boolean value, true if in ball
 * @param in_no_return_yn Boolean value, true if in no return region
 * @param index Index of ball or valley corresponding to end of path
 */
void halt_euler(const double complex h,
                double complex *valleys,
                double complex *phase_coeffs,
                const int order,
                const int stationary_points_len,
                double complex *stationary_points,
                double *ball_radii,
                const double r_star,
                // output pointers
                bool *inball_yn,
                bool *in_no_return_yn,
                int *index)
{
    in_a_ball(h,
              stationary_points,
              ball_radii,
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

/**
* Main routine for approximating steepest descent contours h(p).
* Regular accuracy checks are performed and Newton iteration is performed
* if the error accumulates. If the path enters a ball, a Newton iteration
* is performed on this 'entrance' to ensure high accuracy, which is important
* later in the algorithm.
*
* @param h0 The (double complex) initial value h(0).
* @param phase_coeffs The (double complex) array of coefficients of the phase function.
* @param stationary_points The (double complex) array of stationary points of the phase.
* @param ball_radii The (double) positive radii of the balls.
* @param valleys The (double complex) array of valleys of the phase g.
* @param base_step_size Positive double, scales step parameter in the ODE solve.
* @param n_max Max integer number of coarse approx values in cache.
* @param r_star Positive constant, property of phase, details in paper.
* @param newton_small_threshold Positive double, minimum accuracy of Newton solve
                                at final point, if it's an 'entrance'.
* @param newton_big_threshold Minimum accuracy of Newton solve at each point.
* @param stationary_points_len Integer length of 'stationary_points' array.
* @param phase_coeffs_len Integer length of 'phase_coeffs' array.
* @param p_log Array of positive doubles corresponding to parameter values p in h(p).
* @param h_log Array of complex doubles corresponding to coarse approximation of h(p).
* @param valley_index Index of valley which contour converges towards.
* @param ball_index Index of ball which contour enters.
* @param n Integer describing length of coarse path approximation.
*/
void sd_path_ode_euler( // inputs
    const double complex h0,
    double complex *phase_coeffs,
    double complex *stationary_points,
    double *ball_radii,
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
        ball_radii[0] = 0.0;
    }

    int phase_order = phase_coeffs_len - 1; // order of polynomial phase g(z)

    // value of g(z) at exit/endpoint, i.e. g(h(0))
    double complex g_at_se = polyval(phase_coeffs, h0, phase_order);

    // derivs of g for ODE:
    double complex diff_phase_coeffs[phase_order];         // g'(z)
    double complex diffdiff_phase_coeffs[phase_order - 1]; // g''(z)
    get_diff_poly_coeffs(phase_coeffs, diff_phase_coeffs, phase_order);
    get_diff_poly_coeffs(diff_phase_coeffs, diffdiff_phase_coeffs, phase_order - 1);

    /* -------------- main loop -------------- */
    double complex h = h0; // initialise leading point of SD path at starting point
    p_log[0] = 0.0;        // initialise parameter value at zero
    h_log[0] = h0;         // initialise h(p(0)) at exit point / endpoint
    *n = 0;                // initalise counter for number of points

    double complex g_h, dg_h, ddg_h; // g(h(p)), g'(h(p)), g''(h(p))
    double complex ode_h;            // ODE evaluated at h(p)
    bool continue_loop = true;
    double p;           // parameter p in h(p)
    double p_step_size; // current increment in p

    // The following three variables will halt the ODE process.
    bool inball_yn = false;       // are we in a ball?
    bool in_no_return_yn = false; // are we sufficiently close to a valley?
    int endex;                    // if yes to either of above, which ball/valley?

    // how far to each stationary point:
    double stationary_point_dists[stationary_points_len];
    double min_stationary_point_dist; // how far to nearest stationary point

    // update g'(h) and g''(h)
    dg_h = polyval(diff_phase_coeffs, h, phase_order - 1);
    ddg_h = polyval(diffdiff_phase_coeffs, h, phase_order - 2);

    while (continue_loop)
    {
        // get ingreidents which will be used multiple times
        (*n)++;

        // Forward Euler step, direction to move SD path at next increment
        ode_h = 1.0I / dg_h;

        // get distance to closest stationary point
        // first get vector of distances to each stationary point
        for (int j = 0; j < stationary_points_len; j++)
        {
            if (ball_radii[j] > 0)
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

        // how much to increase parameter p
        p_step_size = base_step_size * fmin(2 * cabs(dg_h * dg_h / ddg_h), min_stationary_point_dist / cabs(ode_h));
        // move in direction ode_h
        h = h + p_step_size * ode_h;

        // update g(h), g'(h) and g''(h) again in time for Newton check
        g_h = polyval(phase_coeffs, h, phase_order);
        dg_h = polyval(diff_phase_coeffs, h, phase_order - 1);
        ddg_h = polyval(diffdiff_phase_coeffs, h, phase_order - 2);

        // error checking
        p = p_log[*n - 1] + p_step_size;

        // get a single Newton correction
        double complex newton_step = get_newton_step(p, g_h, dg_h, g_at_se);

        // if error is small enough, do multiple Newton steps
        while (cabs(newton_step) > newton_big_threshold)
        {
            // update h(p)
            h = h - newton_step;
            // update g(h(p)) and g'(h(p))
            g_h = polyval(phase_coeffs, h, phase_order);
            dg_h = polyval(diff_phase_coeffs, h, phase_order - 1);
            // get next Newton step
            newton_step = get_newton_step(p, g_h, dg_h, g_at_se);
        }

        // Either way - apply Newton now - as we have the step
        h = h - newton_step;

        // update coarse path vectors
        p_log[*n] = p;
        h_log[*n] = h;

        /* Now check if the ODE solve should be halted */

        halt_euler( // inputs:
            h, valleys, phase_coeffs, phase_order, stationary_points_len, stationary_points, ball_radii, r_star,
            // outputs
            &inball_yn, &in_no_return_yn, &endex);

        // should we continue solving ODE?
        continue_loop = !(inball_yn || in_no_return_yn);

        if (!continue_loop)
        {
            if (inball_yn) // only refine endpoint to fine level if in a ball
            {              // before actually halting the process, refine this endpoint
                newton_step = get_newton_step(p, g_h, dg_h, g_at_se);
                /*note that endpoint is refined to higher accuracy,
                for details, see the paper*/
                while (cabs(newton_step) > newton_small_threshold)
                {
                    // update h(p)
                    h = h - newton_step;
                    // update g(h) and g'(h)
                    g_h = polyval(phase_coeffs, h, phase_order);
                    dg_h = polyval(diff_phase_coeffs, h, phase_order - 1);
                    // get next Newton step
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