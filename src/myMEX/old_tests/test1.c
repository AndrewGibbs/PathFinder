#include <stdio.h>
#include "PathFinder.h"

int main()
{
    int order = 2;
    double complex complex_vector[order+1];
    complex_vector[0] = 1.0 + 1.0I;
    complex_vector[1] = -2.0 + 0.0I;
    complex_vector[2] = 0.0 - 0.0I;
    double complex z_in = 3.0 + 1.0I;
    double complex z_out = polyval(complex_vector,z_in,order);
    printf("testing polyval: %f+i%f\n",creal(z_out),cimag(z_out));

    printf("\n\ntesting coeffs diff:\n[");

    double complex dg_coeffs[order];
    diff_poly_coeffs(complex_vector,dg_coeffs,order);
    for(int j=0; j<order; j++)
        {
            printf("%f+i%f,\t",creal(dg_coeffs[j]),cimag(dg_coeffs[j]));
        }
    printf("]\n\n");

    return 0;

}