/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SE_NEwtonCorrection_initialize.c
 *
 * Code generation for function 'SE_NEwtonCorrection_initialize'
 *
 */

/* Include files */
#include "SE_NEwtonCorrection_initialize.h"
#include "SE_NEwtonCorrection_data.h"
#include "_coder_SE_NEwtonCorrection_mex.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void SE_NEwtonCorrection_initialize(void)
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

/* End of code generation (SE_NEwtonCorrection_initialize.c) */
