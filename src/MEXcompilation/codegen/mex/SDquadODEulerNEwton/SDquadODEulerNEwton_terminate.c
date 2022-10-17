/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDquadODEulerNEwton_terminate.c
 *
 * Code generation for function 'SDquadODEulerNEwton_terminate'
 *
 */

/* Include files */
#include "SDquadODEulerNEwton_terminate.h"
#include "SDquadODEulerNEwton_data.h"
#include "_coder_SDquadODEulerNEwton_mex.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void SDquadODEulerNEwton_atexit(void)
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

void SDquadODEulerNEwton_terminate(void)
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

/* End of code generation (SDquadODEulerNEwton_terminate.c) */
