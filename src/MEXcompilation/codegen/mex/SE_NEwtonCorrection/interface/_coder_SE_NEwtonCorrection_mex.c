/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_SE_NEwtonCorrection_mex.c
 *
 * Code generation for function '_coder_SE_NEwtonCorrection_mex'
 *
 */

/* Include files */
#include "_coder_SE_NEwtonCorrection_mex.h"
#include "SE_NEwtonCorrection_data.h"
#include "SE_NEwtonCorrection_initialize.h"
#include "SE_NEwtonCorrection_terminate.h"
#include "_coder_SE_NEwtonCorrection_api.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void SE_NEwtonCorrection_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                     int32_T nrhs, const mxArray *prhs[8])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[2];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 8) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 8, 4,
                        19, "SE_NEwtonCorrection");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 19,
                        "SE_NEwtonCorrection");
  }
  /* Call the function. */
  SE_NEwtonCorrection_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&SE_NEwtonCorrection_atexit);
  /* Module initialization. */
  SE_NEwtonCorrection_initialize();
  /* Dispatch the entry-point. */
  SE_NEwtonCorrection_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  SE_NEwtonCorrection_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_SE_NEwtonCorrection_mex.c) */
