/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDquadODEulerNEwtonCorrection_terminate.c
 *
 * Code generation for function 'SDquadODEulerNEwtonCorrection_terminate'
 *
 */

/* Include files */
#include "SDquadODEulerNEwtonCorrection_terminate.h"
#include "SDquadODEulerNEwtonCorrection_data.h"
#include "_coder_SDquadODEulerNEwtonCorrection_mex.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void SDquadODEulerNEwtonCorrection_atexit(void)
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

void SDquadODEulerNEwtonCorrection_terminate(void)
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

/* End of code generation (SDquadODEulerNEwtonCorrection_terminate.c) */
