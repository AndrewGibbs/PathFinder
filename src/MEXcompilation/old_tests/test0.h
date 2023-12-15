#include <complex.h>

double complex polyval(double complex g_coeffs[], double const complex z, int order)
{
    double complex g_val = 0.0;
    for(j=0; j<(order+1); j++)
    {
        g_val += g_coeffs[order-j]*cpow(z,j);
    }
    return g_val;
}