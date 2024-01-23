/* -------------------- interface functions ----------------------*/
/* for converting Matlab variables to C variables, and back again */
/* ---------------------------------------------------------------*/

/* --------- function prototypes ---------------------------------*/
void convert_mxsca_to_int(const mxArray *in_z, int *out_z);
void convert_mxint_to_int(const mxArray *in_z, int *out_z);
void convert_int_to_mxsca(int *in_z, const mxArray *out_z);
void convert_double_to_mxsca(double *in_x, const mxArray *out_x);
void convert_int_to_mxsca(int *in_z, const mxArray *out_z);
void convert_intvec_to_mxvec(int *in_z, const mxArray *out_z);
void convert_mxsca_to_c(const mxArray *in_z, complex double *out_z);
void convert_c_to_mxsca(const double complex input_val, mxArray *output_val);
void convert_mxvec_to_c(const mxArray *input_array, double complex *output_array);
void convert_c_to_mxvec(const double complex *input_array, mxArray *output_array);
void convert_double_to_mxvec(const double *input_double, mxArray *output_array);
void convert_mxvec_to_double(const mxArray *input_array, double *output_array);
void convert_mxsca_to_double(const mxArray *in_z, double *out_z);

/* ----------function definitions --------------------------------*/
// convert mx to int
void convert_mxsca_to_int(const mxArray *in_z, int *out_z)
{
    double *real_data = mxGetPr(in_z);
    *out_z = (int)*real_data;
}

// convert mxint to int
void convert_mxint_to_int(const mxArray *in_z, int *out_z)
{
    int *real_data = mxGetData(in_z);
    *out_z = (int)*real_data;
}

void convert_mxsca_to_bool(const mxArray *in_z, bool *out_z)
{
    bool *real_data = mxGetData(in_z);
    if (*real_data != 0)
    {
        *out_z = true;
    }
    else
    {
        *out_z = false;
    }
}

// convert (scalar) double to mx
void convert_double_to_mxsca(double *in_x, const mxArray *out_x)
{
    double *real_data;
    real_data = mxGetPr(out_x);
    double dx = (double)*in_x;
    real_data[0] = creal(dx);
}

// convert int to mx
void convert_int_to_mxsca(int *in_z, const mxArray *out_z)
{
    double *real_data;
    real_data = mxGetPr(out_z);
    double dz = (double)*in_z;
    real_data[0] = creal(dz);
}

// convert int vec to mx vec
void convert_intvec_to_mxvec(int *in_z, const mxArray *out_z)
{
    const int vec_len = mxGetM(out_z);
    double *real_data;
    real_data = mxGetPr(out_z);
    for (int j = 0; j < vec_len; j++)
    {
        real_data[j] = (double)creal(in_z[j]);
    }
}

// function to convert single matlab complex input to C scalar
void convert_mxsca_to_c(const mxArray *in_z, complex double *out_z)
{
    double *real_data = mxGetPr(in_z);
    if (mxIsComplex(in_z))
    {
        double *imagData = mxGetPi(in_z);
        *out_z = *real_data + (*imagData * I);
    }
    else
    {
        *out_z = *real_data + (0.0 * I);
    }
}

// function to convert single matlab complex input to C scalar
void convert_c_to_mxsca(const double complex input_val, mxArray *output_val)
{
    double *real_data, *imag_data;
    real_data = mxGetPr(output_val);
    imag_data = mxGetPi(output_val);
    real_data[0] = creal(input_val);
    imag_data[0] = cimag(input_val);
}

// function to convert matlab vector to complex double C vector
void convert_mxvec_to_c(const mxArray *input_array,
                        double complex *output_array)
{

    // get size of vector
    const int vec_len = mxGetM(input_array);

    // get real parts of mx array
    double *real_data = mxGetPr(input_array);
    // best practice to initialise variables outside of 'if' statements:
    double *imagData;

    if (mxIsComplex(input_array))
    { // matlab data has imaginary parts
        double *imagData = mxGetPi(input_array);
        for (int j = 0; j < vec_len; j++)
        {
            output_array[j] = real_data[j] + (imagData[j] * I);
        }
    }
    else
    { // matlab data is purely real
        for (int j = 0; j < vec_len; j++)
        {
            output_array[j] = ((double)real_data[j]) + 0I;
        }
    }
}

// function to convert c complex double to matlab vector
void convert_c_to_mxvec(const double complex *input_array,
                        mxArray *output_array)
{
    double *real_data, *imag_data;
    int vec_len = mxGetM(output_array);
    real_data = mxGetPr(output_array);
    imag_data = mxGetPi(output_array);
    for (int j = 0; j < vec_len; j++)
    {
        real_data[j] = creal(input_array[j]);
        imag_data[j] = cimag(input_array[j]);
    }
}

// function to convert c double to matlab vector
void convert_double_to_mxvec(const double *input_double,
                             mxArray *output_array)
{
    double *real_data;
    int vec_len = mxGetM(output_array);
    real_data = mxGetPr(output_array);
    for (int j = 0; j < vec_len; j++)
    {
        real_data[j] = creal(input_double[j]);
    }
}

// function to convert matlab vector to double C vector
void convert_mxvec_to_double(const mxArray *input_array,
                             double *output_array)
{

    // get size of vector
    const int vec_len = mxGetM(input_array);

    // get real parts of mx array
    double *real_data = mxGetPr(input_array);

    // matlab data is purely real
    for (int j = 0; j < vec_len; j++)
    {
        output_array[j] = real_data[j];
    }
}

// function to convert single matlab real input to C scalar
void convert_mxsca_to_double(const mxArray *in_z, double *out_z)
{
    double *real_data = mxGetPr(in_z);
    *out_z = *real_data;
}