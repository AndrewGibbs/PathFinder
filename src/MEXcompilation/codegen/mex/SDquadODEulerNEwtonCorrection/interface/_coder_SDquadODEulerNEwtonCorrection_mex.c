/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_SDquadODEulerNEwtonCorrection_mex.c
 *
 * Code generation for function '_coder_SDquadODEulerNEwtonCorrection_mex'
 *
 */

/* Include files */
#include "_coder_SDquadODEulerNEwtonCorrection_mex.h"
#include "SDquadODEulerNEwtonCorrection_data.h"
#include "SDquadODEulerNEwtonCorrection_initialize.h"
#include "SDquadODEulerNEwtonCorrection_terminate.h"
#include "_coder_SDquadODEulerNEwtonCorrection_api.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void SDquadODEulerNEwtonCorrection_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                               int32_T nrhs,
                                               const mxArray *prhs[8])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[3];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 8) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 8, 4,
                        29, "SDquadODEulerNEwtonCorrection");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 29,
                        "SDquadODEulerNEwtonCorrection");
  }
  /* Call the function. */
  c_SDquadODEulerNEwtonCorrection(prhs, nlhs, outputs);
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
  mexAtExit(&SDquadODEulerNEwtonCorrection_atexit);
  /* Module initialization. */
  SDquadODEulerNEwtonCorrection_initialize();
  /* Dispatch the entry-point. */
  SDquadODEulerNEwtonCorrection_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  SDquadODEulerNEwtonCorrection_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_SDquadODEulerNEwtonCorrection_mex.c) */
