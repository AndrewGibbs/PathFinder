/* ----------------- interface functions -------------------*/

// convert mx to int
void convert_mxsca_to_int(const mxArray *in_z, int * out_z)
{
    // *out_z = (int) mxGetPr(in_z);
    double *realData = mxGetPr(in_z);
    *out_z = (int) *realData;
}

// convert mxint to int
void convert_mxint_to_int(const mxArray *in_z, int * out_z)
{
    // *out_z = (int) mxGetPr(in_z);
    int *realData = mxGetData(in_z);
    *out_z = (int) *realData;
}

void convert_mxsca_to_bool(const mxArray *in_z, bool * out_z)
{
    double *realData = mxGetData(in_z);
    if(*realData!=0)
        {*out_z = true;}
    else{
        *out_z = false;}
}


// convert (scalar) double to mx
void convert_double_to_mxsca(double *in_x, const mxArray * out_x)
{
    double *H0r;
    H0r = mxGetPr(out_x);
    double dx = (double) *in_x;
    H0r[0] = creal(dx);
}

// convert int to mx
void convert_int_to_mxsca(int *in_z, const mxArray * out_z)
{
    double *H0r;
    H0r = mxGetPr(out_z);
    double dz = (double) *in_z;
    H0r[0] = creal(dz);
}

// convert int vec to mx vec
void convert_intvec_to_mxvec(int *in_z, const mxArray * out_z)
{
    const int vec_len = mxGetM(out_z);
    double *H0r;
    H0r = mxGetPr(out_z);
    // double dz = (double) *in_z;
    // H0r[0] = creal(dz);

    // H0r = mxGetPr(outputArray);
    for(int j=0;j<vec_len;j++)
    {
        H0r[j] =(double) creal(in_z[j]);
    }
}

// function to convert single matlab complex input to C scalar
void convert_mxsca_to_c(const mxArray *in_z, complex double * out_z)
{
    double *realData = mxGetPr(in_z);
    if(mxIsComplex(in_z))
        {
        double *imagData = mxGetPi(in_z);
        *out_z = *realData + (*imagData * I);
        }
    else
        {*out_z = *realData + (0.0 * I);}
}


// function to convert single matlab complex input to C scalar
void convert_c_to_mxsca(const double complex input_val, mxArray *output_val)
{
    // mxArray output_val = mxCreateDoubleMatrix(1,1,mxCOMPLEX);
    double *H0r, *H0i;
    H0r = mxGetPr(output_val);
    H0i = mxGetPi(output_val);
    H0r[0] = creal(input_val);
    H0i[0] = cimag(input_val);
    // return output_val;
}

// function to convert matlab vector to complex double C vector
void convert_mxvec_to_c(const mxArray *inputArray,
                        double complex *outputArray)
{

    // get size of vector
    const int vec_len = mxGetM(inputArray);
    
    // get real parts of mx array
    double *realData = mxGetPr(inputArray);

    if(mxIsComplex(inputArray)){// matlab data has imaginary parts
        double *imagData = mxGetPi(inputArray);
        for(int j=0; j<vec_len; j++)
            {
            outputArray[j] = realData[j] + (imagData[j] * I);
            }
        }
    else{ // matlab data is purely real
        for(int j=0; j<vec_len; j++)
            {
            outputArray[j] = realData[j] + (0.0 * I);
            }
        }
}

// function to convert c complex double to matlab vector
void convert_c_to_mxvec(const double complex *inputArray,
                        mxArray *outputArray)
{
    double *H0r, *H0i;
    int vec_len = mxGetM(outputArray);
    H0r = mxGetPr(outputArray);
    H0i = mxGetPi(outputArray);
    for(int j=0;j<vec_len;j++)
    {
        H0r[j] = creal(inputArray[j]);
        H0i[j] = cimag(inputArray[j]);
    }
}

// function to convert c double to matlab vector
void convert_double_to_mxvec(const double *input_double,
                        mxArray *outputArray)
{
    double *H0r;
    int vec_len = mxGetM(outputArray);
    H0r = mxGetPr(outputArray);
    for(int j=0;j<vec_len;j++)
    {
        H0r[j] = creal(input_double[j]);
    }
}


// function to convert matlab vector to double C vector
void convert_mxvec_to_double(const mxArray *inputArray,
                        double *outputArray)
{

    // get size of vector
    const int vec_len = mxGetM(inputArray);
    
    // get real parts of mx array
    double *realData = mxGetPr(inputArray);

    // matlab data is purely real
    for(int j=0; j<vec_len; j++)
        {
        outputArray[j] = realData[j];
        }
}

// function to convert single matlab real input to C scalar
void convert_mxsca_to_double(const mxArray *in_z, double * out_z)
{
    double *realData = mxGetPr(in_z);
    *out_z = *realData;
}