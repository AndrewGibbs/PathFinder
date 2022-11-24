/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * beyondNoReturn.c
 *
 * Code generation for function 'beyondNoReturn'
 *
 */

/* Include files */
#include "beyondNoReturn.h"
#include "SDpathODEuler_v2_data.h"
#include "SDpathODEuler_v2_emxutil.h"
#include "SDpathODEuler_v2_types.h"
#include "abs.h"
#include "angle.h"
#include "eml_int_forloop_overflow_check.h"
#include "exp.h"
#include "mod.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo nb_emlrtRSI = {
    13,               /* lineNo */
    "beyondNoReturn", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn.m" /* pathName
                                                                        */
};

static emlrtRSInfo ob_emlrtRSI = {
    16,               /* lineNo */
    "beyondNoReturn", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn.m" /* pathName
                                                                        */
};

static emlrtBCInfo x_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    14,               /* lineNo */
    21,               /* colNo */
    "V",              /* aName */
    "beyondNoReturn", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn.m", /* pName
                                                                         */
    0 /* checkKind */
};

static emlrtRTEInfo u_emlrtRTEI = {
    13,               /* lineNo */
    27,               /* colNo */
    "beyondNoReturn", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn.m" /* pName
                                                                        */
};

static emlrtRTEInfo v_emlrtRTEI = {
    13,               /* lineNo */
    34,               /* colNo */
    "beyondNoReturn", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn.m" /* pName
                                                                        */
};

/* Function Definitions */
void beyondNoReturn(const emlrtStack *sp, const creal_T h, real_T Cnr,
                    real_T argBeta, const emxArray_creal_T *V, boolean_T *value,
                    real_T *v_index)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  emxArray_creal_T *b_r;
  emxArray_real_T *b;
  const creal_T *V_data;
  creal_T *r1;
  real_T varargin_1[3];
  real_T R;
  real_T r;
  real_T theta;
  real_T theta_L;
  real_T theta_L_tmp;
  real_T theta_diff;
  real_T theta_tmp;
  real_T v;
  real_T *b_data;
  int32_T a;
  int32_T idx;
  int32_T k;
  int32_T last;
  boolean_T exitg1;
  boolean_T guard1 = false;
  st.prev = sp;
  st.tls = sp->tls;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  V_data = V->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b, 1, &v_emlrtRTEI);
  /* function corresponding to an event which would halt ODE solve, because SD
   */
  /* path is at 'point of no return'. */
  /*  wiggle_room = 0.95; */
  /*  the 'no return test' */
  R = muDoubleScalarHypot(h.re, h.im);
  theta_tmp = muDoubleScalarAtan2(h.im, h.re);
  theta = b_mod(theta_tmp);
  /*      theta_diff = wiggle_room*pi/(2*order); */
  st.site = &nb_emlrtRSI;
  angle(&st, V, b);
  b_data = b->data;
  theta_L = theta_tmp * 0.0;
  st.site = &nb_emlrtRSI;
  if (theta_tmp == 0.0) {
    theta_L = muDoubleScalarExp(theta_L);
    theta_tmp = 0.0;
  } else {
    r = muDoubleScalarExp(theta_L / 2.0);
    theta_L = r * (r * muDoubleScalarCos(theta_tmp));
    theta_tmp = r * (r * muDoubleScalarSin(theta_tmp));
  }
  emxInit_creal_T(&st, &b_r, 1, &u_emlrtRTEI);
  idx = b_r->size[0];
  b_r->size[0] = b->size[0];
  emxEnsureCapacity_creal_T(&st, b_r, idx, &u_emlrtRTEI);
  r1 = b_r->data;
  last = b->size[0];
  for (idx = 0; idx < last; idx++) {
    r1[idx].re = b_data[idx] * 0.0;
    r1[idx].im = b_data[idx];
  }
  b_st.site = &nb_emlrtRSI;
  b_exp(&b_st, b_r);
  r1 = b_r->data;
  last = b_r->size[0];
  for (idx = 0; idx < last; idx++) {
    r1[idx].re -= theta_L;
    r1[idx].im -= theta_tmp;
  }
  b_st.site = &nb_emlrtRSI;
  b_abs(&b_st, b_r, b);
  b_data = b->data;
  b_st.site = &w_emlrtRSI;
  c_st.site = &x_emlrtRSI;
  d_st.site = &y_emlrtRSI;
  emxFree_creal_T(&d_st, &b_r);
  if (b->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &b_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &ab_emlrtRSI;
  last = b->size[0];
  if (b->size[0] <= 2) {
    if (b->size[0] == 1) {
      idx = 1;
    } else if ((b_data[0] > b_data[1]) || (muDoubleScalarIsNaN(b_data[0]) &&
                                           (!muDoubleScalarIsNaN(b_data[1])))) {
      idx = 2;
    } else {
      idx = 1;
    }
  } else {
    f_st.site = &cb_emlrtRSI;
    if (!muDoubleScalarIsNaN(b_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      g_st.site = &db_emlrtRSI;
      if (b->size[0] > 2147483646) {
        h_st.site = &k_emlrtRSI;
        check_forloop_overflow_error(&h_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!muDoubleScalarIsNaN(b_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      idx = 1;
    } else {
      f_st.site = &bb_emlrtRSI;
      theta_tmp = b_data[idx - 1];
      a = idx + 1;
      g_st.site = &eb_emlrtRSI;
      if ((idx + 1 <= b->size[0]) && (b->size[0] > 2147483646)) {
        h_st.site = &k_emlrtRSI;
        check_forloop_overflow_error(&h_st);
      }
      for (k = a; k <= last; k++) {
        r = b_data[k - 1];
        if (theta_tmp > r) {
          theta_tmp = r;
          idx = k;
        }
      }
    }
  }
  emxFree_real_T(&e_st, &b);
  *v_index = idx;
  if ((idx < 1) || (idx > V->size[0])) {
    emlrtDynamicBoundsCheckR2012b(idx, 1, V->size[0], &x_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  v = b_mod(muDoubleScalarAtan2(V_data[idx - 1].im, V_data[idx - 1].re));
  st.site = &ob_emlrtRSI;
  theta_tmp = theta - v;
  varargin_1[0] = muDoubleScalarAbs(theta_tmp);
  varargin_1[1] = muDoubleScalarAbs(theta_tmp - 6.2831853071795862);
  varargin_1[2] = muDoubleScalarAbs(theta_tmp + 6.2831853071795862);
  b_st.site = &fb_emlrtRSI;
  c_st.site = &gb_emlrtRSI;
  d_st.site = &hb_emlrtRSI;
  e_st.site = &ib_emlrtRSI;
  f_st.site = &jb_emlrtRSI;
  if (!muDoubleScalarIsNaN(varargin_1[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!muDoubleScalarIsNaN(varargin_1[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    theta_tmp = varargin_1[0];
  } else {
    g_st.site = &bb_emlrtRSI;
    theta_tmp = varargin_1[idx - 1];
    a = idx + 1;
    for (k = a; k < 4; k++) {
      r = varargin_1[k - 1];
      if (theta_tmp > r) {
        theta_tmp = r;
      }
    }
  }
  theta_diff = muDoubleScalarMax(theta_tmp, 3.1415926535897931 /
                                                (4.0 * (real_T)V->size[0]));
  /*  if theta_diff is less than this optimal value, truncate it there */
  /*      for v = mod(angle(V),2*pi) */
  /*          first check if theta_end is pointing sufficiently close to valley
   */
  theta_L_tmp = v - theta_diff;
  theta_L = b_mod(theta_L_tmp - 2.2204460492503131E-15);
  theta_tmp = v + theta_diff;
  r = b_mod(theta_tmp + 2.2204460492503131E-15);
  guard1 = false;
  if (theta_L < r) {
    if ((theta_L < theta) && (theta < r)) {
      guard1 = true;
    } else {
      *value = false;
    }

    /*  arc endpoints are either side of zero=2pi */
  } else if ((theta_L < theta) || (theta < r)) {
    /*  case where theta_L is to left of zero=2pi */
    /*  case where theta_L is to right of zero=2pi */
    guard1 = true;
  } else {
    *value = false;
  }
  if (guard1) {
    if (R > 1.0) {
      theta_tmp = muDoubleScalarSin((real_T)V->size[0] *
                                    (theta_tmp + argBeta / (real_T)V->size[0]));
      r = muDoubleScalarCos((real_T)V->size[0] *
                            (theta_L_tmp + argBeta / (real_T)V->size[0]));
      if ((theta_tmp > r) ||
          (muDoubleScalarIsNaN(theta_tmp) && (!muDoubleScalarIsNaN(r)))) {
        theta_tmp = r;
      }
      if ((R * theta_tmp > Cnr) &&
          (theta_diff < 3.1415926535897931 / (2.0 * (real_T)V->size[0]))) {
        *value = true;
      } else {
        *value = false;
      }
    } else {
      *value = false;
    }
  }
  /*      end */
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (beyondNoReturn.c) */
