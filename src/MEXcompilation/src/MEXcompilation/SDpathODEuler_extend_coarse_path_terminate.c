/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDpathODEuler_extend_coarse_path_terminate.c
 *
 * Code generation for function 'SDpathODEuler_extend_coarse_path_terminate'
 *
 */

/* Include files */
#include "SDpathODEuler_extend_coarse_path_terminate.h"
#include "SDpathODEuler_extend_coarse_path_data.h"
#include "_coder_SDpathODEuler_extend_coarse_path_mex.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void SDpathODEuler_extend_coarse_path_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void SDpathODEuler_extend_coarse_path_terminate(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (SDpathODEuler_extend_coarse_path_terminate.c) */
