/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "sum.h"
#include "get_stepest_exits_on_ball_types.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"

/* Variable Definitions */
static emlrtRSInfo s_emlrtRSI = {
    20,                                                        /* lineNo */
    "sum",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/sum.m" /* pathName */
};

static emlrtRSInfo t_emlrtRSI = {
    99,        /* lineNo */
    "sumprod", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/private/sumprod.m" /* pathName
                                                                            */
};

static emlrtRSInfo u_emlrtRSI = {
    74,                      /* lineNo */
    "combineVectorElements", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

static emlrtRSInfo v_emlrtRSI = {
    107,                /* lineNo */
    "blockedSummation", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

static emlrtRSInfo w_emlrtRSI = {
    22,                    /* lineNo */
    "sumMatrixIncludeNaN", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo x_emlrtRSI = {
    42,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo ab_emlrtRSI = {
    57,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

/* Function Definitions */
creal_T sum(const emlrtStack *sp, const emxArray_creal_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  creal_T dc;
  creal_T y;
  int32_T ib;
  int32_T inb;
  int32_T nfb;
  int32_T nleft;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &s_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  b_st.site = &t_emlrtRSI;
  c_st.site = &u_emlrtRSI;
  if (x->size[0] == 0) {
    y.re = 0.0;
    y.im = 0.0;
  } else {
    d_st.site = &v_emlrtRSI;
    e_st.site = &w_emlrtRSI;
    if (x->size[0] < 4096) {
      f_st.site = &x_emlrtRSI;
      y = sumColumnB(&f_st, x, x->size[0]);
    } else {
      nfb = x->size[0] / 4096;
      inb = nfb << 12;
      nleft = x->size[0] - inb;
      y = sumColumnB4(x, 1);
      for (ib = 2; ib <= nfb; ib++) {
        dc = sumColumnB4(x, ((ib - 1) << 12) + 1);
        y.re += dc.re;
        y.im += dc.im;
      }
      if (nleft > 0) {
        f_st.site = &ab_emlrtRSI;
        dc = b_sumColumnB(&f_st, x, nleft, inb + 1);
        y.re += dc.re;
        y.im += dc.im;
      }
    }
  }
  return y;
}

/* End of code generation (sum.c) */
