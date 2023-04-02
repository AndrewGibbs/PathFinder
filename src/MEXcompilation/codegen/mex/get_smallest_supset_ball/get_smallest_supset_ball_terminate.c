/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_smallest_supset_ball_terminate.c
 *
 * Code generation for function 'get_smallest_supset_ball_terminate'
 *
 */

/* Include files */
#include "get_smallest_supset_ball_terminate.h"
#include "_coder_get_smallest_supset_ball_mex.h"
#include "get_smallest_supset_ball_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void get_smallest_supset_ball_atexit(void)
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

void get_smallest_supset_ball_terminate(void)
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

/* End of code generation (get_smallest_supset_ball_terminate.c) */
