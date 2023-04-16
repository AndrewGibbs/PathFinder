/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eye.c
 *
 * Code generation for function 'eye'
 *
 */

/* Include files */
#include "eye.h"
#include "eml_int_forloop_overflow_check.h"
#include "get_stepest_exits_on_ball_data.h"
#include "get_stepest_exits_on_ball_emxutil.h"
#include "get_stepest_exits_on_ball_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo ib_emlrtRSI = {
    42,                                                      /* lineNo */
    "eye",                                                   /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/elmat/eye.m" /* pathName */
};

static emlrtRSInfo jb_emlrtRSI = {
    96,                                                      /* lineNo */
    "eye",                                                   /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/elmat/eye.m" /* pathName */
};

static emlrtRSInfo kb_emlrtRSI = {
    21,                           /* lineNo */
    "checkAndSaturateExpandSize", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
    "checkAndSaturateExpandSize.m" /* pathName */
};

static emlrtRTEInfo g_emlrtRTEI =
    {
        58,                   /* lineNo */
        23,                   /* colNo */
        "assertValidSizeArg", /* fName */
        "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
        "assertValidSizeArg.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI =
    {
        64,                   /* lineNo */
        15,                   /* colNo */
        "assertValidSizeArg", /* fName */
        "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
        "assertValidSizeArg.m" /* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = {
    94,                                                      /* lineNo */
    5,                                                       /* colNo */
    "eye",                                                   /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/elmat/eye.m" /* pName */
};

/* Function Definitions */
void eye(const emlrtStack *sp, real_T varargin_1, real_T varargin_2,
         emxArray_real_T *b_I)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T b_t;
  real_T t;
  real_T *I_data;
  int32_T d;
  int32_T i;
  int32_T m;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ib_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (varargin_1 < 0.0) {
    t = 0.0;
  } else {
    t = varargin_1;
  }
  b_st.site = &kb_emlrtRSI;
  if ((t != muDoubleScalarFloor(t)) || muDoubleScalarIsInf(t) ||
      (t > 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &g_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  if (t <= 0.0) {
    b_t = 0.0;
  } else {
    b_t = t;
  }
  if (!(b_t <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  m = (int32_T)t;
  if (varargin_2 < 0.0) {
    t = 0.0;
  } else {
    t = varargin_2;
  }
  b_st.site = &kb_emlrtRSI;
  if ((t != muDoubleScalarFloor(t)) || muDoubleScalarIsInf(t) ||
      (t > 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &g_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  if (t <= 0.0) {
    b_t = 0.0;
  } else {
    b_t = t;
  }
  if (!(b_t <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  i = (int32_T)t;
  d = muIntScalarMin_sint32(m, i);
  i = b_I->size[0] * b_I->size[1];
  b_I->size[0] = m;
  b_I->size[1] = (int32_T)t;
  emxEnsureCapacity_real_T(sp, b_I, i, &mb_emlrtRTEI);
  I_data = b_I->data;
  m *= (int32_T)t;
  for (i = 0; i < m; i++) {
    I_data[i] = 0.0;
  }
  if (d > 0) {
    st.site = &jb_emlrtRSI;
    if (d > 2147483646) {
      b_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (m = 0; m < d; m++) {
      I_data[m + b_I->size[0] * m] = 1.0;
    }
  }
}

/* End of code generation (eye.c) */
