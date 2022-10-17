/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDpathODEuler_v2_terminate.c
 *
 * Code generation for function 'SDpathODEuler_v2_terminate'
 *
 */

/* Include files */
#include "SDpathODEuler_v2_terminate.h"
#include "SDpathODEuler_v2_data.h"
#include "_coder_SDpathODEuler_v2_mex.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void SDpathODEuler_v2_atexit(void)
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

void SDpathODEuler_v2_terminate(void)
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

/* End of code generation (SDpathODEuler_v2_terminate.c) */
