/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * anyNonFinite.c
 *
 * Code generation for function 'anyNonFinite'
 *
 */

/* Include files */
#include "anyNonFinite.h"
#include "eml_int_forloop_overflow_check.h"
#include "get_smallest_supset_ball_data.h"
#include "get_smallest_supset_ball_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo v_emlrtRSI = {
    29,             /* lineNo */
    "anyNonFinite", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/anyNonFinite.m" /* pathName
                                                                           */
};

static emlrtRSInfo w_emlrtRSI = {
    44,          /* lineNo */
    "vAllOrAny", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/vAllOrAny.m" /* pathName
                                                                        */
};

static emlrtRSInfo x_emlrtRSI = {
    103,                  /* lineNo */
    "flatVectorAllOrAny", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/vAllOrAny.m" /* pathName
                                                                        */
};

/* Function Definitions */
boolean_T anyNonFinite(const emlrtStack *sp, const emxArray_creal_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  const creal_T *x_data;
  int32_T k;
  int32_T nx;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  x_data = x->data;
  st.site = &v_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  nx = x->size[0];
  p = true;
  c_st.site = &x_emlrtRSI;
  if ((1 <= x->size[0]) && (x->size[0] > 2147483646)) {
    d_st.site = &d_emlrtRSI;
    b_check_forloop_overflow_error(&d_st);
  }
  for (k = 0; k < nx; k++) {
    if ((!p) || (muDoubleScalarIsInf(x_data[k].re) ||
                 muDoubleScalarIsInf(x_data[k].im) ||
                 (muDoubleScalarIsNaN(x_data[k].re) ||
                  muDoubleScalarIsNaN(x_data[k].im)))) {
      p = false;
    }
  }
  return !p;
}

boolean_T b_anyNonFinite(const emlrtStack *sp, const emxArray_creal_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  const creal_T *x_data;
  int32_T k;
  int32_T nx;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  x_data = x->data;
  st.site = &v_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  nx = x->size[0] * x->size[1];
  p = true;
  c_st.site = &x_emlrtRSI;
  if ((1 <= nx) && (nx > 2147483646)) {
    d_st.site = &d_emlrtRSI;
    b_check_forloop_overflow_error(&d_st);
  }
  for (k = 0; k < nx; k++) {
    if ((!p) || (muDoubleScalarIsInf(x_data[k].re) ||
                 muDoubleScalarIsInf(x_data[k].im) ||
                 (muDoubleScalarIsNaN(x_data[k].re) ||
                  muDoubleScalarIsNaN(x_data[k].im)))) {
      p = false;
    }
  }
  return !p;
}

/* End of code generation (anyNonFinite.c) */
