/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_SDpathODEuler_extend_coarse_path_mex.c
 *
 * Code generation for function '_coder_SDpathODEuler_extend_coarse_path_mex'
 *
 */

/* Include files */
#include "_coder_SDpathODEuler_extend_coarse_path_mex.h"
#include "SDpathODEuler_extend_coarse_path_data.h"
#include "SDpathODEuler_extend_coarse_path_initialize.h"
#include "SDpathODEuler_extend_coarse_path_terminate.h"
#include "_coder_SDpathODEuler_extend_coarse_path_api.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void SDpathODEuler_extend_coarse_path_mexFunction(int32_T nlhs,
                                                  mxArray *plhs[3],
                                                  int32_T nrhs,
                                                  const mxArray *prhs[7])
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
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4,
                        32, "SDpathODEuler_extend_coarse_path");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 32,
                        "SDpathODEuler_extend_coarse_path");
  }
  /* Call the function. */
  c_SDpathODEuler_extend_coarse_p(prhs, nlhs, outputs);
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
  mexAtExit(&SDpathODEuler_extend_coarse_path_atexit);
  /* Module initialization. */
  SDpathODEuler_extend_coarse_path_initialize();
  /* Dispatch the entry-point. */
  SDpathODEuler_extend_coarse_path_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  SDpathODEuler_extend_coarse_path_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_SDpathODEuler_extend_coarse_path_mex.c) */
