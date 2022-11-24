/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SE_NEwtonCorrection_terminate.c
 *
 * Code generation for function 'SE_NEwtonCorrection_terminate'
 *
 */

/* Include files */
#include "SE_NEwtonCorrection_terminate.h"
#include "SE_NEwtonCorrection_data.h"
#include "_coder_SE_NEwtonCorrection_mex.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void SE_NEwtonCorrection_atexit(void)
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

void SE_NEwtonCorrection_terminate(void)
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

/* End of code generation (SE_NEwtonCorrection_terminate.c) */
