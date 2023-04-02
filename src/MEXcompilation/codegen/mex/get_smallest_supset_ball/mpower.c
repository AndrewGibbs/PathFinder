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
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
creal_T mpower(const creal_T a, real_T b)
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

/* End of code generation (mpower.c) */
