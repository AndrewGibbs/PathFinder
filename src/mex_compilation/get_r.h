#ifndef LAPACKE_H
#include <lapacke.h>
#endif
#include "PathFinder.h" // needed for utility functions therein

/* ---------------------------- function prototypes ----------------------------*/
// main functions - in separate file due to extra header file 'lapacke' required
double get_r_given_theta(const double complex *phase_coeffs,
                         const double complex centre,
                         const double cball_over_omega,
                         const double theta,
                         const double imag_thresh,
                         const int phase_coeffs_len);

double get_smallest_supset_ball(const double complex *phase_coeffs,
                                const double freq,
                                const double complex centre,
                                const double cball,
                                const int num_rays,
                                const bool take_max,
                                const double imag_thresh,
                                const int phase_coeffs_len);

// utility subroutines
// roots requires LApack for balancing/eigenvalue solve
void roots(
    const double complex *phase_coeffs,
    const int phase_coeffs_len,
    double complex *root_vals);

void multiply_polynomials(
    const double complex poly1_coeffs[],
    const double complex poly2_coeffs[],
    const int len_coeffs1,
    const int len_coeffs2,
    double complex result[]);

int factorial(const int len_coeffs2);

int nchoosek(const int len_coeffs2, const int k);

// bisection subroutines
int compare_fn(const void *a, const void *b);

double bisec_fn_r(
    const double complex *phase_coeffs,
    const double phase_coeffs_len,
    const double r,
    const double complex centre,
    const double theta,
    const double cball_over_omega);

double bisection_r(
    const double complex *phase_coeffs,
    const double phase_coeffs_len,
    const double complex centre,
    const double theta,
    const double cball_over_omega,
    double a,
    double b,
    double tolerance);

double plan_bisection(const double complex *phase_coeffs,
                      const double complex centre,
                      const double cball_over_omega,
                      const double theta,
                      const double *guesses,
                      const int num_guesses,
                      const int phase_coeffs_len);

/* ---------------------------- function definitions ---------------------------*/
/* ------------------ utility functions for getting ball sizes -----------------*/

/**
 *  Main function for getting roots of polynomial, mimicing Matlab's roots command
by using a balanced companion matrix approach
 *
 * @param phase_coeffs The (double complex) coeficients of the polynomial,
 * highest to lowest degree
 * @param phase_coeffs_len The (integer) length of the coefficients array
 * @param root_vals The (double complex) array of polynomial roots
*/
void roots(const double complex *phase_coeffs,
           const int phase_coeffs_len,
           double complex *root_vals)
{
    // initialise Frobenius/companion matrix
    int n = phase_coeffs_len - 1; // size of matrix
    double complex A[n][n];
    // fill with zeros
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            A[j][k] = 0.0;
        }
    }

    // enter the non-zero elements
    for (int j = 0; j < (n - 1); j++)
    {
        A[j][j + 1] = 1.0;
        A[n - 1][j] = -phase_coeffs[phase_coeffs_len - j - 1] / phase_coeffs[0];
    }

    A[n - 1][n - 1] = -phase_coeffs[1] / phase_coeffs[0];

    // output values of the balancing routine (not used subsequently)
    lapack_int ilo, ihi;
    double scale[n];

    int info_balance; // output info of Lapack balancing routine
    int info_eigs;    // output info of Lapack eivenvalue routine

    // Balance the complex matrix A
    info_balance = LAPACKE_zgebal(LAPACK_COL_MAJOR, 'B', n,
                                  (lapack_complex_double *)A, n, &ilo, &ihi, scale);

    // find eigenvalues of companion matrix A
    info_eigs = LAPACKE_zgeev(LAPACK_COL_MAJOR, 'N', 'N', n,
                              (lapack_complex_double *)A, n, (lapack_complex_double *)root_vals,
                              NULL, 1, NULL, 1);

    // those eigenvalues are the roots of the polynomial, stored in 'root_vals'
}

/**
 * Routine to multiply two polynomials together, given their coefficients
 *
 * @param poly1_coeffs (double complex) Coefficients of first polynomial
 * @param poly3 (double complex) Coefficients of second polynomial
 * @param len_coeffs1 Length of coefficients vector of first polynomial
 * @param len_coeffs2 :ength of coefficients vector of second polynomial
 * @param result_coeffs Coefficients of product of polynomials
 */
void multiply_polynomials(const double complex poly1_coeffs[],
                          const double complex poly2_coeffs[],
                          const int len_coeffs1,
                          const int len_coeffs2,
                          double complex result_coeffs[])
{
    // Initialize the result array with zeros
    for (int i = 0; i < len_coeffs1 + len_coeffs2 - 1; i++)
    {
        result_coeffs[i] = 0;
    }

    // Multiply each term of first polynomial with each term of second polynomial
    for (int i = 0; i < len_coeffs1; i++)
    {
        for (int j = 0; j < len_coeffs2; j++)
        {
            result_coeffs[i + j] += poly1_coeffs[i] * poly2_coeffs[j];
        }
    }
}

/*------------------ functions for bisection algorithm -------------------------*/

/**
 * Simple function which compares two numbers a and b, returnining -1,0,1 depending
 * on which is greater.
 */
int compare_fn(const void *a, const void *b)
{
    double difference = *(const double *)a - *(const double *)b;

    if (difference > 0)
        return 1;
    else if (difference < 0)
        return -1;
    else
        return 0;
}

/**
 * Function which determines process of bisection algorithm, measured at endpoints
 * of each interval in sequence, here the variable is 'r'.
 *
 * @param phase_coeffs (double complex) Coefficients ofthe polynomial phase
 * @param phase_coeffs_len (integer) Length of phase coefficients vector
 * @param r (positive double) position at which cost function is evaluated
 * @param centre (double complex) Centre of the ball
 * @param theta (double) Angle of the ray on which we are minimising
 * @param cball_over_omega (double) The cball param divided by the
 * frequency parameter.
 */
double bisec_fn_r(const double complex *phase_coeffs,
                  const double phase_coeffs_len,
                  const double r,
                  const double complex centre,
                  const double theta,
                  const double cball_over_omega)
{
    // deduce the order of the polynomial from the coefficients length:
    const int order = phase_coeffs_len - 1;

    // return the cost function
    return pow(cabs(polyval(phase_coeffs, centre + r * cexp(I * theta), order) - polyval(phase_coeffs, centre, order)), 2) - pow(cball_over_omega, 2);
}

/**
 * Main routine for bisection method, which is called when the colleague approach fails.
 *
 * @param phase_coeffs (double complex) Coefficients ofthe polynomial phase
 * @param phase_coeffs_len (integer) Length of phase coefficients vector
 * @param centre (double complex) Centre of the ball
 * @param theta (double) Angle of the ray
 * @param cball_over_omega (double) The cball param divided by the
 * @param a (double) Left endpoint of initial guess range
 * @param b (double) Right endpoint of initial guess range
 * @param tolerance (double) Accuracy required by bisection method
 */
double bisection_r(
    const double complex *phase_coeffs,
    const double phase_coeffs_len,
    const double complex centre,
    const double theta,
    const double cball_over_omega,
    // bisection params
    double a,
    double b,
    double tolerance)
{
    double c;          // the next guess subdividing [a,b]. typically at the midpoint
    double fa, fb, fc; // cost function 'f' evaluated at a,b,c

    fa = bisec_fn_r(phase_coeffs, phase_coeffs_len, a, centre, theta, cball_over_omega);
    fb = bisec_fn_r(phase_coeffs, phase_coeffs_len, b, centre, theta, cball_over_omega);

    if (fa * fb >= 0)
    {
        // printf("The function has the same sign at both ends of the interval.\n");
        return NAN; // Return NaN (Not a Number) to indicate an error
    }

    // loop until error tolerance is met
    while ((b - a) >= tolerance)
    {
        // assign c as midpoint of [a,b]
        c = (a + b) / 2;
        // get f(c)
        fc = bisec_fn_r(phase_coeffs, phase_coeffs_len, c, centre, theta, cball_over_omega);

        // check if c is a zero, i.e. f(c)=0
        if (fc == 0.0)
        {
            // If the value at c is exactly 0, c is the root
            return c;
        }
        else if (fa * fc < 0) // check if sign change in [a,c]
        {
            // shrink interval [a,b] to [a,c]
            b = c;
            fb = fc;
        }
        else // otherwise must be sign change in [b,c]
        {
            // shrink interval [a,b] to [b,c]
            a = c;
            fa = fc;
        }
    }

    // Return the midpoint of the final interval as an approximate root
    return (a + b) / 2;
}

/**
 * Wrapper for bisection method, which is called when the colleague approach fails.
 *
 * @param phase_coeffs (double complex) Coefficients ofthe polynomial phase
 * @param centre (double complex) Centre of the ball
 * @param cball_over_omega (double) The cball param divided by the
 * @param theta (double) Angle of the ray
 * @param guesses (double) Array of guesses of zeros for bisection method,
 * these are the positive real parts of the failed colleague method
 * @param num_guesses (integer) Length of the guesses vector
 * @param phase_coeffs_len (integer) Length of phase coefficients vector
 */
double plan_bisection(const double complex *phase_coeffs,
                      const double complex centre,
                      const double cball_over_omega,
                      const double theta,
                      const double *guesses,
                      const int num_guesses,
                      const int phase_coeffs_len)
{
    const double tol = 1e-8;
    bool found_a_root = false;
    double r;
    for (int j = 1; j < num_guesses; j++)
    {
        // try lowest guesses first
        if (bisec_fn_r(phase_coeffs, phase_coeffs_len,
                       guesses[j], centre, theta, cball_over_omega) > 0)
        {
            r = bisection_r(phase_coeffs, phase_coeffs_len,
                            centre, theta, cball_over_omega,
                            guesses[j - 1], guesses[j], tol);
            break;
        }
    }
    return r;
}

// Subroutine to calculate factorial of n
int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        int result = 1;
        for (int i = 2; i <= n; ++i)
        {
            result *= i;
        }
        return result;
    }
}

// Subroutine to calculate binomail coefficient, n choose k
int nchoosek(int n, int k)
{
    if (k < 0 || k > n)
    {
        return 0; // Invalid input, return 0
    }

    return factorial(n) / (factorial(k) * factorial(n - k));
}

/**
 * Details are given in rootfinding_notes.md, here we construct a polynomial
 * which has roots at the optimal length of the ray. A companion approach is
 * tried, if this fails, we use a bisection approach.
 *
 * @param phase_coeffs (double complex) Coefficients ofthe polynomial phase
 * @param centre (double complex) Centre of the ball
 * @param cball_over_omega (double) The cball param divided by the
 * @param theta (double) Angle of the ray
 * @param imag_thresh (double) Max permitted value of erronious imaginary part
 * of real roots
 * @param phase_coeffs_len (integer) length of phase coefficients vector
 */
double get_r_given_theta(const double complex *phase_coeffs,
                         const double complex centre,
                         const double cball_over_omega,
                         const double theta,
                         const double imag_thresh,
                         // extra stuff for C
                         const int phase_coeffs_len)
{
    // preallocations
    const int N = phase_coeffs_len - 1; // degree of phase polynomial
    double complex d[phase_coeffs_len];
    double complex a[N + 1];          // coefficients of polynomial g(\xi+r*exp(i*theta))-g(\xi)
    double complex a_[N + 1];         // conjugate coefficiients
    int coeffs_len = 2 * (N + 1) - 1; // length of coefficients of unknown polynomial
    // ( to be determined ) which has zeros where we want to choose r
    double complex coeffs[coeffs_len];      // coefficients of unknown polynomial
    double complex coeffs_flip[coeffs_len]; // we will flip to simplify indexing
    double complex r_roots[coeffs_len - 1]; // roots of polynomial
    double complex inc;                     // temporary variable to sum within loop

    // initialise vector a and a_
    a[0] = -1 * polyval(phase_coeffs, centre, N);
    a_[0] = conj(a[0]);
    for (int k = 1; k < N + 1; k++)
    {
        a[k] = 0.0;
        a_[k] = 0.0;
    }

    // d is the reversed g
    for (int j = 0; j < phase_coeffs_len; j++)
    {
        d[j] = phase_coeffs[phase_coeffs_len - j - 1];
    }

    // construct the polynomial coefficients
    for (int k = 0; k < N + 1; k++)
    {
        for (int j = k; j < N + 1; j++)
        {
            // need to add the nchoosek function
            if (j == k)
            {
                inc = d[j] * cexp(I * k * theta);
            }
            else
            {
                inc = d[j] * nchoosek(j, k) * cpow(centre, (double)(j - k)) * cexp(I * k * theta);
            }
            a[k] = a[k] + inc;
            // a_[k] = a_[k] + conj(inc);
        }
        a_[k] = conj(a[k]);
    }

    // convolve polynomials with coeffs a and a_
    multiply_polynomials(a, a_, N + 1, N + 1, coeffs);
    // add the constant term
    coeffs[0] -= pow(cball_over_omega, 2);
    for (int j = 0; j < coeffs_len; j++)
    {
        coeffs_flip[j] = coeffs[coeffs_len - j - 1];
    }

    // get roots of polynomial, possible candidates for 'r'
    roots(coeffs_flip, coeffs_len, r_roots);
    // now filter out the roots we care about
    int num_valid_roots = 0;
    int num_guesses = 0;
    double complex *valid_roots = (double complex *)malloc((coeffs_len - 1) * sizeof(double complex));
    double *real_guesses = (double *)malloc((coeffs_len + 1) * sizeof(double));

    // loop over all roots
    for (int j = 0; j < (coeffs_len - 1); j++)
    { // filter out positive and (mostly) real roots
        if (creal(r_roots[j]) > 0 && fabs(cimag(r_roots[j])) < imag_thresh)
        {
            valid_roots[num_valid_roots] = r_roots[j];
            num_valid_roots++;
        }
    }

    // choose r as the smallest of these valid roots, if one exists
    double r;
    if (num_valid_roots == 0)
    {
        // if no valid roots exist, use bisection to find one
        // add a zero at the beginning
        num_guesses++;
        real_guesses[0] = 0.0;
        for (int j = 0; j < coeffs_len - 1; j++)
            if (creal(r_roots[j]) > 0)
            {
                num_guesses++;
                real_guesses[num_guesses - 1] = r_roots[j];
            }
        qsort(real_guesses, num_guesses, sizeof(double), compare_fn);
        // add double at the end, (assuming no realloc happens in the above sort)
        num_guesses++;
        real_guesses[num_guesses - 1] = 2 * real_guesses[num_guesses - 2];

        // need to add plan b-section in here
        r = plan_bisection(phase_coeffs, centre, cball_over_omega,
                           theta, real_guesses, num_guesses,
                           phase_coeffs_len);
    }
    else
    {
        // if there is at least one valid root, take the smallest one.
        r = creal(valid_roots[0]);
        for (int j = 1; j < num_valid_roots; j++)
        {
            r = fmin(r, creal(valid_roots[j]));
        }
    }

    // deallocate memory
    free(valid_roots);
    valid_roots = NULL;
    free(real_guesses);
    real_guesses = NULL;

    return r;
}

/**
 * Details are given in main paper. We define a ball by firing rays in multiple
 * directions, and (in some sense) truncating the ray after a fixed number of
 * oscillations. The ball radius is the length of the smallest ray.
 *
 * @param phase_coeffs (double complex) Coefficients ofthe polynomial phase
 * @param freq Frequency parameter, often referred to as 'omega' elsewhere
 * @param centre (double complex) Centre of the ball
 * @param cball (double) The cball param divided by the
 * @param num_rays (integer) The number of rays we use to determine the ball
 * @param take_max (boolean) If true, choose radius of ball to be length of
 * largest ray instead (contrary to what is in paper)
 * @param imag_thresh (double) Max permitted value of erronious imaginary part
 * of real roots
 * @param phase_coeffs_len (integer) length of phase coefficients vector
 */
double get_smallest_supset_ball(const double complex *phase_coeffs,
                                const double freq,
                                const double complex centre,
                                const double cball,
                                const int num_rays,
                                const bool take_max,
                                const double imag_thresh,
                                // extra inputs
                                const int phase_coeffs_len)
{
    double radii[num_rays];                             // vector of multiple ray lengths
    double r;                                           // return value, radius of ball
    const double d_theta = 2 * PI / ((double)num_rays); // angular difference
    double theta;                                       // angle of each ray (effectively a for loop variable)

    // loop over all rays
    for (int n = 0; n < num_rays; n++) // starting from one to match matlab version
    {
        // get angle of ray
        theta = d_theta * ((double)n);
        // get radius for that ray
        radii[n] = get_r_given_theta(phase_coeffs, centre, cball / freq, theta, imag_thresh, phase_coeffs_len);
    }

    // choose biggest/smallest radius (as required)
    r = radii[0];
    for (int n = 1; n < num_rays; n++)
    {
        if (take_max)
        {
            r = fmax(r, radii[n]);
        }
        else
        {
            r = fmin(r, radii[n]);
        }
    }
    return r;
}
