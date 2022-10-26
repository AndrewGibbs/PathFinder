/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * angle.c
 *
 * Code generation for function 'angle'
 *
 */

/* Include files */
#include "angle.h"
#include "SDpathODEuler_data.h"
#include "SDpathODEuler_emxutil.h"
#include "SDpathODEuler_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo p_emlrtRSI = {
    9,                                                         /* lineNo */
    "angle",                                                   /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/elfun/angle.m" /* pathName */
};

/* Function Definitions */
void angle(const emlrtStack *sp, const emxArray_creal_T *x, emxArray_real_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const creal_T *x_data;
  real_T *y_data;
  int32_T k;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  st.site = &p_emlrtRSI;
  nx = x->size[0];
  k = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity_real_T(&st, y, k, &t_emlrtRTEI);
  y_data = y->data;
  b_st.site = &q_emlrtRSI;
  if ((1 <= x->size[0]) && (x->size[0] > 2147483646)) {
    c_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = 0; k < nx; k++) {
    y_data[k] = muDoubleScalarAtan2(x_data[k].im, x_data[k].re);
  }
}

/* End of code generation (angle.c) */