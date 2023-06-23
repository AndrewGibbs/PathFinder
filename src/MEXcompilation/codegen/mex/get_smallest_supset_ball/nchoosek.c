/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nchoosek.c
 *
 * Code generation for function 'nchoosek'
 *
 */

/* Include files */
#include "nchoosek.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo t_emlrtRSI = {
    45,         /* lineNo */
    "nchoosek", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/specfun/nchoosek.m" /* pathName
                                                                     */
};

static emlrtRSInfo u_emlrtRSI = {
    116,   /* lineNo */
    "nCk", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/specfun/nchoosek.m" /* pathName
                                                                     */
};

static emlrtRTEInfo c_emlrtRTEI = {
    39,                                                             /* lineNo */
    9,                                                              /* colNo */
    "nchoosek",                                                     /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/specfun/nchoosek.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    25,                                                             /* lineNo */
    15,                                                             /* colNo */
    "nchoosek",                                                     /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/specfun/nchoosek.m" /* pName */
};

/* Function Definitions */
real_T nchoosek(const emlrtStack *sp, real_T x, real_T k)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T b_k;
  real_T nmk;
  real_T y;
  int32_T i;
  int32_T j;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (!(k == k)) {
    emlrtErrorWithMessageIdR2018a(sp, &d_emlrtRTEI,
                                  "MATLAB:nchoosek:InvalidArg2",
                                  "MATLAB:nchoosek:InvalidArg2", 0);
  }
  if (k > x) {
    emlrtErrorWithMessageIdR2018a(sp, &c_emlrtRTEI,
                                  "MATLAB:nchoosek:KOutOfRange",
                                  "MATLAB:nchoosek:KOutOfRange", 0);
  } else {
    st.site = &t_emlrtRSI;
    b_k = k;
    if (k > x / 2.0) {
      b_k = x - k;
    }
    if (b_k > 1000.0) {
      y = rtInf;
    } else {
      y = 1.0;
      nmk = x - b_k;
      i = (int32_T)b_k;
      for (j = 0; j < i; j++) {
        y *= (((real_T)j + 1.0) + nmk) / ((real_T)j + 1.0);
      }
      y = muDoubleScalarRound(y);
    }
    if (!(y <= 9.007199254740992E+15)) {
      b_st.site = &u_emlrtRSI;
      warning(&b_st);
    }
  }
  return y;
}

/* End of code generation (nchoosek.c) */
