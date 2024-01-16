#include <lapacke.h>
#include "PathFinder.h" // needed for utility functions therein

/* ---------------------------- function prototypes ----------------------------*/
// main functions - in separate file due to extra header file 'lapacke' required
double get_r_given_theta(   const double complex *g_coeffs,
                            const double complex xi,
                            const double C_over_omega, 
                            const double theta, 
                            const double imag_thresh,
                            const int len_g_coeffs);

double get_smallest_supset_ball(const double complex *g_coeffs,
                                const double freq,
                                const double complex xi,
                                const double Cosc,
                                const int num_rays,
                                const bool take_max,
                                const double imag_thresh,
                                const int g_coeffs_len);

// utility subroutines
// roots requires LApack for balancing/eigenvalue solve
void roots( 
    const double complex *g_coeffs,
    const int g_len,
    double complex *root_vals);

void multiplyPolynomials(   
    const double complex poly1[],
    const double complex poly2[],
    const int m,
    const int n,
    double complex result[]);

int factorial(const int n);

int nchoosek(const int n, const int k);

// bisection subroutines
int compare_fn(const void *a, const void *b);

double bisec_fn_r(
    const double complex *g_coeffs,
    const double g_len,
    const double r,
    const double complex xi,
    const double theta,
    const double C_over_omega);

double bisection_r(
        const double complex *g_coeffs,
        const double g_len,
        const double complex xi,
        const double theta,
        const double C_over_omega,
        double a, double b, double tolerance);

double plan_b_isection( const double complex *g_coeffs,
                        const double complex xi,
                        const double C_over_omega,
                        const double theta,
                        const double *guesses,
                        const int num_guesses,
                        const int g_coeffs_len);



/* ---------------------------- function definitions ---------------------------*/

/* utility functions for getting ball sizes */
void roots( const double complex *g_coeffs,
            const int g_len,
            double complex *root_vals)
{
    // construct Frobenius matrix
    int n = g_len - 1; // size of matrix
    lapack_complex_double A[n][n];
            // fill zeros
    for(int j=0; j<n; j++){
        for(int k=0; k<n; k++){
        A[j][k] = 0.0;
        }
    }

    for(int j=0; j<(n-1); j++)
    {
        A[j][j+1] = 1.0;
        A[n-1][j] = -g_coeffs[g_len-j-1]/g_coeffs[0];
    }

    A[n-1][n-1] = -g_coeffs[1]/g_coeffs[0];

    lapack_int ilo, ihi;
    double scale[n];
    lapack_int info_b;
    int info_balance, info_eigs;
    
    // Balance the complex matrix A
    info_balance = LAPACKE_zgebal(LAPACK_COL_MAJOR, 'B', n,
                          (lapack_complex_double *)A, n, &ilo, &ihi, scale);
        
    // mexPrintf("\ninfo_balance: %d\n",info_balance); /* delete later*/

    info_eigs = LAPACKE_zgeev(LAPACK_COL_MAJOR, 'N', 'N', n,
                        (lapack_complex_double *)A, n, root_vals,
                        NULL, 1, NULL, 1);

    // mexPrintf("\ninfo_eigs: %d\n",info_eigs); /* delete later*/


}

void multiplyPolynomials(   const double complex poly1[],
                            const double complex poly2[],
                            const int m,
                            const int n,
                            double complex result[]) {
    // Initialize the result array with zeros
    for (int i = 0; i < m + n - 1; i++) {
        result[i] = 0;
    }

    // Multiply each term of first polynomial with each term of second polynomial
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }
}

// functions for bisection algorithm
int compare_fn(const void *a, const void *b) {
    double difference = *(const double *)a - *(const double *)b;
    
    if (difference > 0) return 1;
    else if (difference < 0) return -1;
    else return 0;
}

// G = @(r) abs(g(xi+r*exp(1i*theta))-g(xi)).^2-C_over_omega^2;
double bisec_fn_r(const double complex *g_coeffs,
                        const double g_len,
                        const double r,
                        const double complex xi,
                        const double theta,
                        const double C_over_omega)
{
    const int order = g_len-1;
    return pow(cabs(polyval(g_coeffs,xi+r*cexp(I*theta),order)-polyval(g_coeffs,xi,order)),2)-pow(C_over_omega,2);
}

double bisection_r(// g eval params:
                        const double complex *g_coeffs,
                        const double g_len,
                        const double complex xi,
                        const double theta,
                        const double C_over_omega,
                        // bisection params@
                        double a, double b, double tolerance) {
    double fa, fb, c, fc;

    fa = bisec_fn_r(g_coeffs, g_len, a, xi, theta, C_over_omega);
    fb = bisec_fn_r(g_coeffs, g_len, b, xi, theta, C_over_omega);

    if (fa * fb >= 0) {
        // printf("The function has the same sign at both ends of the interval.\n");
        return NAN; // Return NaN (Not a Number) to indicate an error
    }

    while ((b - a) >= tolerance) {
        c = (a + b) / 2;
        fc = bisec_fn_r(g_coeffs, g_len, c, xi, theta, C_over_omega);

        if (fc == 0.0) {
            // If the value at c is exactly 0, c is the root
            return c;
        } else if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }

    return (a + b) / 2; // Return the midpoint of the final interval as an approximate root
}


double plan_b_isection( const double complex *g_coeffs,
                        const double complex xi,
                        const double C_over_omega,
                        const double theta,
                        const double *guesses,
                        const int num_guesses,
                        const int g_coeffs_len)
{
    // mexPrintf("plan b"); /* delete later*/
    const double tol = 1e-8;
    bool found_a_root = false;
    double r;
    for(int j=1; j<num_guesses; j++){
        if(bisec_fn_r(g_coeffs, g_coeffs_len,
                        guesses[j], xi, theta, C_over_omega)>0)
        {
            r = bisection_r(g_coeffs, g_coeffs_len,
                            xi, theta, C_over_omega,
                            guesses[j-1], guesses[j], tol);
            break;
        }
    }
    return r;
}

// Function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        int result = 1;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
}

// Function to calculate n choose k
int nchoosek(int n, int k) {
    if (k < 0 || k > n) {
        return 0; // Invalid input, return 0
    }

    return factorial(n) / (factorial(k) * factorial(n - k));
}

double get_r_given_theta(   const double complex *g_coeffs,
                            const double complex xi,
                            const double C_over_omega, 
                            const double theta, 
                            const double imag_thresh,
                            // extra stuff for C
                            const int len_g_coeffs)
{
    // preallocations
    const int N = len_g_coeffs-1;
    double complex d[len_g_coeffs];
    double complex a[N+1];
    double complex a_[N+1];
    int coeffs_len = 2*(N+1)-1;
    double complex coeffs[coeffs_len];
    double complex coeffs_flip[coeffs_len];
    double complex r_roots[coeffs_len-1];
    double complex inc;

    // initialise vector a and a_
    a[0] = -1*polyval(g_coeffs,xi,N);
    a_[0] = conj(a[0]);
    for(int k=1; k<N+1; k++){
        a[k] = 0.0;
        a_[k] = 0.0;
    }

    // d is the reversed g
    for(int j=0; j<len_g_coeffs; j++)
    {
        d[j] = g_coeffs[len_g_coeffs-j-1];
    }

    // construct the polynomial coefficients
   for(int k=0; k<N+1; k++)
   {
        for(int j=k; j<N+1; j++)
        {
            // need to add the nchoosek function
            if(j==k){
                inc = d[j]*cexp(I*k*theta);
            }
            else{
            inc = d[j]*nchoosek(j,k)*cpow(xi,(double)(j-k))*cexp(I*k*theta);
            }
            a[k] = a[k] + inc;
            // a_[k] = a_[k] + conj(inc);
        }
        a_[k] = conj(a[k]);
   }

    // convolve polynomials with coeffs a and a_
    multiplyPolynomials(a, a_, N+1, N+1, coeffs);
    // add the constant term
    coeffs[0] -= pow(C_over_omega,2);
    for(int j=0; j<coeffs_len; j++)
    {
        coeffs_flip[j] = coeffs[coeffs_len-j-1];
    }

    // get roots of polynomial, possible candidates for 'r'
    roots(coeffs_flip, coeffs_len, r_roots);
    // now filter out the roots we care about
    int num_valid_roots = 0;
    int num_guesses = 0;
    double complex *valid_roots = (double complex *)malloc((coeffs_len-1) * sizeof(double complex));
    double *real_guesses = (double *)malloc((coeffs_len+1) * sizeof(double));

    // loop over all roots
    for(int j=0; j<(coeffs_len-1); j++)
    {   // filter out positive and (mostly) real roots
        if(creal(r_roots[j])>0 && fabs(cimag(r_roots[j]))<imag_thresh)
        {
            valid_roots[num_valid_roots] = r_roots[j];
            // mexPrintf("\n%.4f+%.4fi",creal(valid_roots[num_valid_roots]));
            num_valid_roots++;
        }
    }

    // choose r as the smallest of these valid roots, if one exists
    double r;
    if(num_valid_roots==0){
        // if no valid roots exist, use bisection to find one
        // add a zero at the beginning
        num_guesses++;
        real_guesses[0] = 0.0;
        for(int j=0; j< coeffs_len-1; j++)
            if(creal(r_roots[j])>0)
            {
                num_guesses++;
                real_guesses[num_guesses-1] = r_roots[j];
            }
        qsort(real_guesses, num_guesses, sizeof(double), compare_fn);
        // add double at the end, (assuming no realloc happens in the above sort)
        num_guesses++;
        real_guesses[num_guesses-1] = 2*real_guesses[num_guesses-2];

        // need to add plan b-section in here
        r = plan_b_isection(g_coeffs, xi, C_over_omega, 
                            theta, real_guesses, num_guesses,
                            len_g_coeffs);
        
    }
    else{
        r = creal(valid_roots[0]);
        for(int j=1; j<num_valid_roots; j++){
            r = fmin(r,creal(valid_roots[j]));
        }
    }

    /* deallocate memory */
    free(valid_roots);
    valid_roots = NULL;
    free(real_guesses);
    real_guesses = NULL;

    // mexPrintf("\n%.4f+%.4fi",creal(r),cimag(r));
    return r;

}
//function r = get_smallest_supset_ball(g_coeffs, freq, xi, Cosc,num_rays, take_max, imag_thresh)
double get_smallest_supset_ball(const double complex *g_coeffs,
                                const double freq,
                                const double complex xi,
                                const double Cosc,
                                const int num_rays,
                                const bool take_max,
                                const double imag_thresh,
                                // extra inputs
                                const int g_coeffs_len)
{
    double radii[num_rays];
    double r;
    const double d_theta = 2*PI/((double) num_rays);
    double theta;
    // loop over all rays
    for(int n=0; n<num_rays; n++)// starting from one to match matlab version
    {
        theta = d_theta*((double) n);
        // get radius for that ray
        radii[n] = get_r_given_theta(g_coeffs, xi, Cosc/freq, theta, imag_thresh, g_coeffs_len);
    }

    // choose biggest/smallest radius
    r = radii[0];
    // mexPrintf("tmval: %d\n",take_max);
    // mexPrintf("%f\n",r);
    for(int n=1; n<num_rays; n++)
    {
        if(take_max){
            r = fmax(r,radii[n]);
        }
        else{
            r = fmin(r,radii[n]);
        }
        // mexPrintf("%f\n",r);
    }
    // mexPrintf("\n");
    // mexPrintf("%f\n",r);
    return r;
}