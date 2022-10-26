/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mpower.c
 *
 * Code generation for function 'mpower'
 *
 */

/* Include files */
#include "mpower.h"
#include "get_stepest_exits_on_ball_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo r_emlrtRSI = {
    71,                                                      /* lineNo */
    "power",                                                 /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/ops/power.m" /* pathName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    82,                                                      /* lineNo */
    5,                                                       /* colNo */
    "fltpower",                                              /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/ops/power.m" /* pName */
};

/* Function Definitions */
creal_T b_mpower(const creal_T a, real_T b)
{
  creal_T c;
  real_T b_im;
  real_T r;
  real_T ytmp;
  int8_T b_r;
  if ((a.im == 0.0) && (a.re >= 0.0)) {
    c.re = muDoubleScalarPower(a.re, b);
    c.im = 0.0;
  } else if ((a.re == 0.0) && (b == b)) {
    ytmp = muDoubleScalarPower(a.im, b);
    if (b == 0.0) {
      r = 0.0;
    } else {
      r = muDoubleScalarRem(b, 4.0);
      if (r == 0.0) {
        r = 0.0;
      } else if (b < 0.0) {
        r += 4.0;
      }
    }
    b_r = (int8_T)muDoubleScalarRound(r);
    if (b_r == 3) {
      c.re = 0.0;
      c.im = -ytmp;
    } else if (b_r == 2) {
      c.re = -ytmp;
      c.im = 0.0;
    } else if (b_r == 1) {
      c.re = 0.0;
      c.im = ytmp;
    } else {
      c.re = ytmp;
      c.im = 0.0;
    }
  } else if ((a.im == 0.0) && muDoubleScalarIsInf(b) &&
             (muDoubleScalarAbs(a.re) == 1.0)) {
    c.re = 1.0;
    c.im = 0.0;
  } else {
    if (a.im == 0.0) {
      if (a.re < 0.0) {
        ytmp = muDoubleScalarLog(muDoubleScalarAbs(a.re));
        b_im = 3.1415926535897931;
      } else {
        ytmp = muDoubleScalarLog(a.re);
        b_im = 0.0;
      }
    } else if ((muDoubleScalarAbs(a.re) > 8.9884656743115785E+307) ||
               (muDoubleScalarAbs(a.im) > 8.9884656743115785E+307)) {
      ytmp = muDoubleScalarLog(muDoubleScalarHypot(a.re / 2.0, a.im / 2.0)) +
             0.69314718055994529;
      b_im = muDoubleScalarAtan2(a.im, a.re);
    } else {
      ytmp = muDoubleScalarLog(muDoubleScalarHypot(a.re, a.im));
      b_im = muDoubleScalarAtan2(a.im, a.re);
    }
    c.re = b * ytmp;
    c.im = b * b_im;
    if (c.im == 0.0) {
      b_im = c.re;
      c.re = muDoubleScalarExp(b_im);
      c.im = 0.0;
    } else if (muDoubleScalarIsInf(c.im) && muDoubleScalarIsInf(c.re) &&
               (c.re < 0.0)) {
      c.re = 0.0;
      c.im = 0.0;
    } else {
      r = muDoubleScalarExp(c.re / 2.0);
      b_im = c.im;
      ytmp = c.im;
      c.re = r * (r * muDoubleScalarCos(b_im));
      c.im = r * (r * muDoubleScalarSin(ytmp));
    }
  }
  return c;
}

real_T mpower(const emlrtStack *sp, real_T a, real_T b)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &q_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &r_emlrtRSI;
  if ((a < 0.0) && (b != b)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
                                  "Coder:toolbox:power_domainError",
                                  "Coder:toolbox:power_domainError", 0);
  }
  return muDoubleScalarPower(a, b);
}

/* End of code generation (mpower.c) */
