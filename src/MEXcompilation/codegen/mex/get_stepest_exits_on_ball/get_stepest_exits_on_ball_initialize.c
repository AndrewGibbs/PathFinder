/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_stepest_exits_on_ball_initialize.c
 *
 * Code generation for function 'get_stepest_exits_on_ball_initialize'
 *
 */

/* Include files */
#include "get_stepest_exits_on_ball_initialize.h"
#include "_coder_get_stepest_exits_on_ball_mex.h"
#include "get_stepest_exits_on_ball_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void get_stepest_exits_on_ball_initialize(void)
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

/* End of code generation (get_stepest_exits_on_ball_initialize.c) */
