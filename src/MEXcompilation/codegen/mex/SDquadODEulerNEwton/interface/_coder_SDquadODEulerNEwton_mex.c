/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_SDquadODEulerNEwton_mex.c
 *
 * Code generation for function '_coder_SDquadODEulerNEwton_mex'
 *
 */

/* Include files */
#include "_coder_SDquadODEulerNEwton_mex.h"
#include "SDquadODEulerNEwton_data.h"
#include "SDquadODEulerNEwton_initialize.h"
#include "SDquadODEulerNEwton_terminate.h"
#include "_coder_SDquadODEulerNEwton_api.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void SDquadODEulerNEwton_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                     int32_T nrhs, const mxArray *prhs[4])
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
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        19, "SDquadODEulerNEwton");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 19,
                        "SDquadODEulerNEwton");
  }
  /* Call the function. */
  SDquadODEulerNEwton_api(prhs, nlhs, outputs);
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
  mexAtExit(&SDquadODEulerNEwton_atexit);
  /* Module initialization. */
  SDquadODEulerNEwton_initialize();
  /* Dispatch the entry-point. */
  SDquadODEulerNEwton_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  SDquadODEulerNEwton_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_SDquadODEulerNEwton_mex.c) */
