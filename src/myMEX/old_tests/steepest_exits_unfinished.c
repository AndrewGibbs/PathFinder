// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate n choose k
unsigned long long nchoosek(int n, int k) {
    if (k < 0 || k > n) {
        return 0; // Invalid input, return 0
    } else {
        return factorial(n) / (factorial(k) * factorial(n - k));
    }
}

double complex h_j = get_h_j(int j, int rho, double complex *a, double complex *b)
{
    double complex h_j;
    if(j < rho)
        {h_j = a[rho-j]+1.0I*b[rho-j];}
    else if( j== rho)
        {h_j = 2*a[0];}
    else
        {h_j = a[j-rho]-1.0I*b[j-rho];}
    
    return h_j;
}

void get_stepest_exits_on_ball(g_coeffs,
                                centre,
                                radius,
                                g_coeffs_len,
                                //outputs
                                )
{
    imag_thresh = 0.1;
    rho = g_coeffs_len-1; // order of g'(z)

    //A = complex(zeros(rho+1)); // matrix of indices of double sum
    double complex A[rho+1][rho+1], dA[rho+1][rho+1];
    //dA = complex(zeros(rho+1)); // matrix of indices of double sum, deriv
    // a = (zeros(rho+1,1)); // cosine indices
    // b = (zeros(rho+1,1)); // sine indices
    // da = (zeros(rho+1,1)); // cosine indices, deriv
    // db = (zeros(rho+1,1)); // sine indices, deriv
    double complex a[rho+1], b[rho+1], da[rho+1], db[rho+1];

    double complex d_jk;

    // now initialise everything to zeros
    for(int j=0; j<=rho; j++)
    {
        // perhaps these vectors are uneccessary.
        a[j] = 0.0 + 0.0I;
        b[j] = 0.0 + 0.0I;
        da[j] = 0.0 + 0.0I;
        db[j] = 0.0 + 0.0I;

        // for(int k=0; j<=rho; k++)
        // {
        //     A[j,k] = 0.0 + 0.0I;
        //     dA[j,k] = 0.0 + 0.0I;
        // }

    }

    //  compute Fourier indices (notation as in my notes)
    for(int j=0; j++; j<=rho)
        {
        for(int k=0; k++; k<=rho)
            {
            main_coeff = nchoosek(j,k)*pow(radius,k)*pow(centre,(j-k))*g_coeffs[rho-j];
            A[j, k] = k*main_coeff;
            dA[j, k] = k^2*main_coeff;
            }
        }

    // filtering in this way isolates the imaginary part of g'(z):
    for(int k=0; k<=rho; k++)
    {   
        // d_jk = sum(A(:,k+1));
        double complex d_jk;
        for(int j=0; j<=rho; j++)
        {
            d_jk += A[j,k];
        }

        a[k] = creal(d_jk);
        da[k] = -cimag(d_jk);
        if(k>0)
        {
            b[k] = -cimag(d_jk);
            db[k] = -creal(d_jk);
        }
    }
 
    //  now find zeros of Fourier series using colleague method
    //( notation as in Boyd)
    // construct Frobenius matrix (with zeros in final row)
    // B = complex([ zeros(2*rho-1,1) eye(2*rho-1,2*rho-1) ; zeros(1,2*rho)]);

    // Allocate memory for the complex matrix B
    int rows = 2 * rho;
    int cols = 2 * rho;

    double complex **B = (double complex **)malloc((rows + 1) * sizeof(double complex *));
    for (int i = 0; i <= rows; ++i) {
        B[i] = (double complex *)malloc(cols * sizeof(double complex));
    }

    // Initialize the complex matrix B with zeros and the identity matrix pattern
    for (int i = 0; i < rows - 1; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == j) {
                B[i][j] = 1.0 + 0.0 * I; // Set diagonal elements to 1 (identity matrix)
            } else {
                B[i][j] = 0.0 + 0.0 * I; // Set other elements to 0
            }
        }
    }

    // Set the last row of B to zeros
    for (int j = 0; j < cols; ++j) {
        B[rows][j] = 0.0 + 0.0 * I;
    }

    // now construct final row
    for (int k = 0; k < cols; ++k) //k=1:(2*rho)
        {
            B[rows][k] = -get_h_j(k, rho, a, b)/(a[rows] - 1.0I*b[rows]);
        }

    // ** CURRENTLY CONVERTED CODE UP TO HERE **

    // convert eigenvalues to roots
    [~,E] = eig(B);
    eig_vals = diag(E);
    complex_angular_roots = angle(eig_vals) - 1i*log(abs(eig_vals));
    // now filter out real-valued roots
    turning_points = real(complex_angular_roots(abs(imag(complex_angular_roots))<imag_thresh));

    tp_vals = zeros(size(turning_points));
    for k_=0:rho
        tp_vals = tp_vals+(da(k_+1)*cos(k_*turning_points));
        if k_>0
            tp_vals = tp_vals+(db(k_+1)*sin(k_*turning_points));
        end
    end

    SEs = centre+radius*exp(1i*turning_points(tp_vals<0));
}
end