/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDpathODEuler_extend_coarse_path_initialize.c
 *
 * Code generation for function 'SDpathODEuler_extend_coarse_path_initialize'
 *
 */

/* Include files */
#include "SDpathODEuler_extend_coarse_path_initialize.h"
#include "SDpathODEuler_extend_coarse_path_data.h"
#include "_coder_SDpathODEuler_extend_coarse_path_mex.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void SDpathODEuler_extend_coarse_path_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (SDpathODEuler_extend_coarse_path_initialize.c) */
