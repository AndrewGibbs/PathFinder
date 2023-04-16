/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sumMatrixIncludeNaN.c
 *
 * Code generation for function 'sumMatrixIncludeNaN'
 *
 */

/* Include files */
#include "sumMatrixIncludeNaN.h"
#include "eml_int_forloop_overflow_check.h"
#include "get_stepest_exits_on_ball_data.h"
#include "get_stepest_exits_on_ball_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo bb_emlrtRSI = {
    178,          /* lineNo */
    "sumColumnB", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    182,          /* lineNo */
    "sumColumnB", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo db_emlrtRSI = {
    183,          /* lineNo */
    "sumColumnB", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI = {
    184,          /* lineNo */
    "sumColumnB", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo fb_emlrtRSI = {
    189,          /* lineNo */
    "sumColumnB", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo gb_emlrtRSI = {
    210,         /* lineNo */
    "sumColumn", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

/* Function Definitions */
creal_T b_sumColumnB(const emlrtStack *sp, const emxArray_creal_T *x,
                     int32_T vlen, int32_T vstart)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const creal_T *x_data;
  creal_T y;
  real_T y_im;
  real_T y_re;
  int32_T b_vstart;
  int32_T inb;
  int32_T k;
  int32_T nfb;
  int32_T y_re_tmp;
  int32_T y_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  if (vlen <= 1024) {
    st.site = &bb_emlrtRSI;
    y = x_data[vstart - 1];
    b_st.site = &gb_emlrtRSI;
    if ((1 <= vlen - 1) && (vlen - 1 > 2147483646)) {
      c_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 0; k <= vlen - 2; k++) {
      y_tmp = vstart + k;
      y.re += x_data[y_tmp].re;
      y.im += x_data[y_tmp].im;
    }
  } else {
    nfb = vlen / 1024;
    inb = nfb << 10;
    st.site = &cb_emlrtRSI;
    y = x_data[vstart - 1];
    b_st.site = &gb_emlrtRSI;
    for (k = 0; k < 1023; k++) {
      y_tmp = vstart + k;
      y.re += x_data[y_tmp].re;
      y.im += x_data[y_tmp].im;
    }
    st.site = &db_emlrtRSI;
    for (k = 2; k <= nfb; k++) {
      st.site = &eb_emlrtRSI;
      b_vstart = vstart + ((k - 1) << 10);
      y_re = x_data[b_vstart - 1].re;
      y_im = x_data[b_vstart - 1].im;
      b_st.site = &gb_emlrtRSI;
      for (y_tmp = 0; y_tmp < 1023; y_tmp++) {
        y_re_tmp = b_vstart + y_tmp;
        y_re += x_data[y_re_tmp].re;
        y_im += x_data[y_re_tmp].im;
      }
      y.re += y_re;
      y.im += y_im;
    }
    if (vlen > inb) {
      y_tmp = vlen - inb;
      b_vstart = vstart + inb;
      st.site = &fb_emlrtRSI;
      y_re = x_data[b_vstart - 1].re;
      y_im = x_data[b_vstart - 1].im;
      b_st.site = &gb_emlrtRSI;
      if ((1 <= y_tmp - 1) && (y_tmp - 1 > 2147483646)) {
        c_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (k = 0; k <= y_tmp - 2; k++) {
        y_re_tmp = b_vstart + k;
        y_re += x_data[y_re_tmp].re;
        y_im += x_data[y_re_tmp].im;
      }
      y.re += y_re;
      y.im += y_im;
    }
  }
  return y;
}

creal_T sumColumnB(const emlrtStack *sp, const emxArray_creal_T *x,
                   int32_T vlen)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const creal_T *x_data;
  creal_T y;
  real_T y_im;
  real_T y_re;
  int32_T b_k;
  int32_T inb;
  int32_T k;
  int32_T nfb;
  int32_T vstart;
  int32_T y_re_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  if (vlen <= 1024) {
    st.site = &bb_emlrtRSI;
    y = x_data[0];
    b_st.site = &gb_emlrtRSI;
    if ((1 <= vlen - 1) && (vlen - 1 > 2147483646)) {
      c_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 0; k <= vlen - 2; k++) {
      y.re += x_data[k + 1].re;
      y.im += x_data[k + 1].im;
    }
  } else {
    nfb = vlen / 1024;
    inb = nfb << 10;
    st.site = &cb_emlrtRSI;
    y = x_data[0];
    b_st.site = &gb_emlrtRSI;
    for (k = 0; k < 1023; k++) {
      y.re += x_data[k + 1].re;
      y.im += x_data[k + 1].im;
    }
    st.site = &db_emlrtRSI;
    for (k = 2; k <= nfb; k++) {
      st.site = &eb_emlrtRSI;
      vstart = (k - 1) << 10;
      y_re = x_data[vstart].re;
      y_im = x_data[vstart].im;
      b_st.site = &gb_emlrtRSI;
      for (b_k = 0; b_k < 1023; b_k++) {
        y_re_tmp = (vstart + b_k) + 1;
        y_re += x_data[y_re_tmp].re;
        y_im += x_data[y_re_tmp].im;
      }
      y.re += y_re;
      y.im += y_im;
    }
    if (vlen > inb) {
      nfb = vlen - inb;
      st.site = &fb_emlrtRSI;
      y_re = x_data[inb].re;
      y_im = x_data[inb].im;
      b_st.site = &gb_emlrtRSI;
      if ((1 <= nfb - 1) && (nfb - 1 > 2147483646)) {
        c_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (k = 0; k <= nfb - 2; k++) {
        y_re_tmp = (inb + k) + 1;
        y_re += x_data[y_re_tmp].re;
        y_im += x_data[y_re_tmp].im;
      }
      y.re += y_re;
      y.im += y_im;
    }
  }
  return y;
}

creal_T sumColumnB4(const emxArray_creal_T *x, int32_T vstart)
{
  const creal_T *x_data;
  creal_T y;
  real_T psum1_im;
  real_T psum1_re;
  real_T psum2_im;
  real_T psum2_re;
  real_T psum3_im;
  real_T psum3_re;
  real_T psum4_im;
  real_T psum4_re;
  int32_T k;
  int32_T psum1_re_tmp;
  x_data = x->data;
  psum1_re = x_data[vstart - 1].re;
  psum1_im = x_data[vstart - 1].im;
  psum2_re = x_data[vstart + 1023].re;
  psum2_im = x_data[vstart + 1023].im;
  psum3_re = x_data[vstart + 2047].re;
  psum3_im = x_data[vstart + 2047].im;
  psum4_re = x_data[vstart + 3071].re;
  psum4_im = x_data[vstart + 3071].im;
  for (k = 0; k < 1023; k++) {
    psum1_re_tmp = vstart + k;
    psum1_re += x_data[psum1_re_tmp].re;
    psum1_im += x_data[psum1_re_tmp].im;
    psum2_re += x_data[psum1_re_tmp + 1024].re;
    psum2_im += x_data[psum1_re_tmp + 1024].im;
    psum3_re += x_data[psum1_re_tmp + 2048].re;
    psum3_im += x_data[psum1_re_tmp + 2048].im;
    psum4_re += x_data[psum1_re_tmp + 3072].re;
    psum4_im += x_data[psum1_re_tmp + 3072].im;
  }
  y.re = (psum1_re + psum2_re) + (psum3_re + psum4_re);
  y.im = (psum1_im + psum2_im) + (psum3_im + psum4_im);
  return y;
}

/* End of code generation (sumMatrixIncludeNaN.c) */
