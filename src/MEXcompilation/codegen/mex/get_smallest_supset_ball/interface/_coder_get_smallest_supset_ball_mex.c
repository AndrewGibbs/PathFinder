/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_get_smallest_supset_ball_mex.c
 *
 * Code generation for function '_coder_get_smallest_supset_ball_mex'
 *
 */

/* Include files */
#include "_coder_get_smallest_supset_ball_mex.h"
#include "_coder_get_smallest_supset_ball_api.h"
#include "get_smallest_supset_ball_data.h"
#include "get_smallest_supset_ball_initialize.h"
#include "get_smallest_supset_ball_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void get_smallest_supset_ball_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                          int32_T nrhs, const mxArray *prhs[5])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        24, "get_smallest_supset_ball");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 24,
                        "get_smallest_supset_ball");
  }
  /* Call the function. */
  get_smallest_supset_ball_api(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&get_smallest_supset_ball_atexit);
  /* Module initialization. */
  get_smallest_supset_ball_initialize();
  /* Dispatch the entry-point. */
  get_smallest_supset_ball_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  get_smallest_supset_ball_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_get_smallest_supset_ball_mex.c) */
