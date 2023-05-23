/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_r_given_theta.c
 *
 * Code generation for function 'get_r_given_theta'
 *
 */

/* Include files */
#include "get_r_given_theta.h"
#include "conv.h"
#include "eml_int_forloop_overflow_check.h"
#include "flip.h"
#include "get_smallest_supset_ball_data.h"
#include "get_smallest_supset_ball_emxutil.h"
#include "get_smallest_supset_ball_types.h"
#include "mpower.h"
#include "nchoosek.h"
#include "roots.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo f_emlrtRSI = {
    22,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo g_emlrtRSI = {
    25,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo h_emlrtRSI = {
    26,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo i_emlrtRSI = {
    31,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo j_emlrtRSI = {
    32,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo k_emlrtRSI = {
    35,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo l_emlrtRSI = {
    38,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo m_emlrtRSI = {
    44,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo gb_emlrtRSI = {
    44,                                                          /* lineNo */
    "mpower",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/mpower.m" /* pathName */
};

static emlrtRSInfo hb_emlrtRSI = {
    71,                                                      /* lineNo */
    "power",                                                 /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/ops/power.m" /* pathName */
};

static emlrtRSInfo sc_emlrtRSI = {
    18,                                                      /* lineNo */
    "abs",                                                   /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/elfun/abs.m" /* pathName */
};

static emlrtRSInfo tc_emlrtRSI =
    {
        74,                    /* lineNo */
        "applyScalarFunction", /* fcnName */
        "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
        "applyScalarFunction.m" /* pathName */
};

static emlrtBCInfo
    b_emlrtBCI =
        {
            -1,                  /* iFirst */
            -1,                  /* iLast */
            32,                  /* lineNo */
            12,                  /* colNo */
            "coeffs",            /* aName */
            "get_r_given_theta", /* fName */
            "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
            "get_r_given_theta.m", /* pName */
            0                      /* checkKind */
};

static emlrtBCInfo
    c_emlrtBCI =
        {
            -1,                  /* iFirst */
            -1,                  /* iLast */
            26,                  /* lineNo */
            40,                  /* colNo */
            "d",                 /* aName */
            "get_r_given_theta", /* fName */
            "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
            "get_r_given_theta.m", /* pName */
            0                      /* checkKind */
};

static emlrtBCInfo
    d_emlrtBCI =
        {
            -1,                  /* iFirst */
            -1,                  /* iLast */
            21,                  /* lineNo */
            8,                   /* colNo */
            "a_",                /* aName */
            "get_r_given_theta", /* fName */
            "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
            "get_r_given_theta.m", /* pName */
            0                      /* checkKind */
};

static emlrtBCInfo
    e_emlrtBCI =
        {
            -1,                  /* iFirst */
            -1,                  /* iLast */
            25,                  /* lineNo */
            33,                  /* colNo */
            "d",                 /* aName */
            "get_r_given_theta", /* fName */
            "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
            "get_r_given_theta.m", /* pName */
            0                      /* checkKind */
};

static emlrtBCInfo
    f_emlrtBCI =
        {
            -1,                  /* iFirst */
            -1,                  /* iLast */
            20,                  /* lineNo */
            7,                   /* colNo */
            "a",                 /* aName */
            "get_r_given_theta", /* fName */
            "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
            "get_r_given_theta.m", /* pName */
            0                      /* checkKind */
};

static emlrtBCInfo
    g_emlrtBCI =
        {
            -1,                  /* iFirst */
            -1,                  /* iLast */
            25,                  /* lineNo */
            24,                  /* colNo */
            "a",                 /* aName */
            "get_r_given_theta", /* fName */
            "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
            "get_r_given_theta.m", /* pName */
            0                      /* checkKind */
};

static emlrtBCInfo
    h_emlrtBCI =
        {
            -1,                  /* iFirst */
            -1,                  /* iLast */
            25,                  /* lineNo */
            15,                  /* colNo */
            "a",                 /* aName */
            "get_r_given_theta", /* fName */
            "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
            "get_r_given_theta.m", /* pName */
            0                      /* checkKind */
};

static emlrtBCInfo
    i_emlrtBCI =
        {
            -1,                  /* iFirst */
            -1,                  /* iLast */
            26,                  /* lineNo */
            26,                  /* colNo */
            "a_",                /* aName */
            "get_r_given_theta", /* fName */
            "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
            "get_r_given_theta.m", /* pName */
            0                      /* checkKind */
};

static emlrtBCInfo
    j_emlrtBCI =
        {
            -1,                  /* iFirst */
            -1,                  /* iLast */
            26,                  /* lineNo */
            16,                  /* colNo */
            "a_",                /* aName */
            "get_r_given_theta", /* fName */
            "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
            "get_r_given_theta.m", /* pName */
            0                      /* checkKind */
};

static emlrtBCInfo
    k_emlrtBCI =
        {
            -1,                  /* iFirst */
            -1,                  /* iLast */
            38,                  /* lineNo */
            23,                  /* colNo */
            "r_roots",           /* aName */
            "get_r_given_theta", /* fName */
            "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
            "get_r_given_theta.m", /* pName */
            0                      /* checkKind */
};

static emlrtBCInfo
    l_emlrtBCI =
        {
            -1,                  /* iFirst */
            -1,                  /* iLast */
            41,                  /* lineNo */
            23,                  /* colNo */
            "r_roots",           /* aName */
            "get_r_given_theta", /* fName */
            "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
            "get_r_given_theta.m", /* pName */
            0                      /* checkKind */
};

static emlrtRTEInfo s_emlrtRTEI = {
    14,                  /* lineNo */
    5,                   /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo t_emlrtRTEI = {
    15,                  /* lineNo */
    5,                   /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo u_emlrtRTEI = {
    22,                  /* lineNo */
    5,                   /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo v_emlrtRTEI = {
    38,                  /* lineNo */
    27,                  /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo w_emlrtRTEI =
    {
        30,                    /* lineNo */
        21,                    /* colNo */
        "applyScalarFunction", /* fName */
        "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
        "applyScalarFunction.m" /* pName */
};

static emlrtRTEInfo x_emlrtRTEI = {
    38,                  /* lineNo */
    23,                  /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo y_emlrtRTEI = {
    1,                   /* lineNo */
    16,                  /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    44,                  /* lineNo */
    13,                  /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    31,                  /* lineNo */
    5,                   /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

/* Function Definitions */
real_T get_r_given_theta(const emlrtStack *sp, const emxArray_creal_T *g_coeffs,
                         const creal_T xi, real_T C_over_omega, real_T theta)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  emxArray_boolean_T *b_r;
  emxArray_creal_T *a;
  emxArray_creal_T *a_;
  emxArray_creal_T *coeffs;
  emxArray_creal_T *d;
  emxArray_real_T *x;
  emxArray_real_T *y;
  const creal_T *g_coeffs_data;
  creal_T dc;
  creal_T *a__data;
  creal_T *a_data;
  creal_T *d_data;
  real_T d_im_tmp;
  real_T d_re;
  real_T d_re_tmp;
  real_T r;
  real_T varargout_1_im;
  real_T varargout_1_re;
  real_T varargout_1_re_tmp;
  real_T xi_im;
  real_T xi_re;
  real_T *x_data;
  real_T *y_data;
  int32_T i;
  int32_T idx;
  int32_T k;
  int32_T nx;
  int32_T trueCount;
  uint32_T j;
  boolean_T exitg1;
  boolean_T *r1;
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
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  g_coeffs_data = g_coeffs->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_creal_T(sp, &a, 1, &s_emlrtRTEI);
  /* given a ray from \xi, in direction theta, find r at which the ray */
  /* intersects the boundary of the blob |g(\xi)-g(\xi+r*exp(i*theta)|=C */
  /*  threshold for negligable imaginary part */
  /*  set the function g. I could just pass it, but not sure how MEX feels */
  /*  about that. */
  /*  pre-allocate stuff */
  i = a->size[0];
  a->size[0] = g_coeffs->size[0];
  emxEnsureCapacity_creal_T(sp, a, i, &s_emlrtRTEI);
  a_data = a->data;
  nx = g_coeffs->size[0];
  for (i = 0; i < nx; i++) {
    a_data[i].re = 0.0;
    a_data[i].im = 0.0;
  }
  emxInit_creal_T(sp, &a_, 1, &t_emlrtRTEI);
  i = a_->size[0];
  a_->size[0] = g_coeffs->size[0];
  emxEnsureCapacity_creal_T(sp, a_, i, &t_emlrtRTEI);
  a__data = a_->data;
  nx = g_coeffs->size[0];
  for (i = 0; i < nx; i++) {
    a__data[i].re = 0.0;
    a__data[i].im = 0.0;
  }
  /*     %% follow the algorithm, as written in my notes (and soon, the paper)
   */
  /*  remember that the indexing of the polynomial coefficients is the */
  /*  opposite in my notes as in Matlab */
  if (1 > a->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, a->size[0], &f_emlrtBCI, (emlrtCTX)sp);
  }
  if (g_coeffs->size[0] != 0) {
    varargout_1_re = g_coeffs_data[0].re;
    varargout_1_im = g_coeffs_data[0].im;
    i = g_coeffs->size[0];
    for (k = 0; k <= i - 2; k++) {
      xi_re = xi.re * varargout_1_re - xi.im * varargout_1_im;
      xi_im = xi.re * varargout_1_im + xi.im * varargout_1_re;
      varargout_1_re = xi_re + g_coeffs_data[k + 1].re;
      varargout_1_im = xi_im + g_coeffs_data[k + 1].im;
    }
  }
  a_data[0].re = -varargout_1_re;
  a_data[0].im = -varargout_1_im;
  if (1 > a_->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, a_->size[0], &d_emlrtBCI, (emlrtCTX)sp);
  }
  if (g_coeffs->size[0] != 0) {
    varargout_1_re = g_coeffs_data[0].re;
    varargout_1_im = g_coeffs_data[0].im;
    i = g_coeffs->size[0];
    for (k = 0; k <= i - 2; k++) {
      xi_re = xi.re * varargout_1_re - xi.im * varargout_1_im;
      xi_im = xi.re * varargout_1_im + xi.im * varargout_1_re;
      varargout_1_re = xi_re + g_coeffs_data[k + 1].re;
      varargout_1_im = xi_im + g_coeffs_data[k + 1].im;
    }
  }
  emxInit_creal_T(sp, &d, 1, &u_emlrtRTEI);
  a__data[0].re = -varargout_1_re;
  a__data[0].im = varargout_1_im;
  i = d->size[0];
  d->size[0] = g_coeffs->size[0];
  emxEnsureCapacity_creal_T(sp, d, i, &u_emlrtRTEI);
  d_data = d->data;
  nx = g_coeffs->size[0];
  for (i = 0; i < nx; i++) {
    d_data[i] = g_coeffs_data[i];
  }
  st.site = &f_emlrtRSI;
  flip(d);
  d_data = d->data;
  i = g_coeffs->size[0];
  for (k = 0; k < i; k++) {
    nx = g_coeffs->size[0] - k;
    for (idx = 0; idx < nx; idx++) {
      j = (uint32_T)k + idx;
      if (((int32_T)((real_T)j + 1.0) < 1) ||
          ((int32_T)((real_T)j + 1.0) > d->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((real_T)j + 1.0), 1, d->size[0],
                                      &e_emlrtBCI, (emlrtCTX)sp);
      }
      st.site = &g_emlrtRSI;
      xi_im = nchoosek(&st, j, k);
      varargout_1_re_tmp = theta * 0.0;
      varargout_1_im = theta * (real_T)k;
      if (varargout_1_im == 0.0) {
        varargout_1_re = muDoubleScalarExp(varargout_1_re_tmp);
        varargout_1_im = 0.0;
      } else {
        r = muDoubleScalarExp(varargout_1_re_tmp / 2.0);
        varargout_1_re = r * (r * muDoubleScalarCos(varargout_1_im));
        varargout_1_im = r * (r * muDoubleScalarSin(varargout_1_im));
      }
      dc = mpower(xi, (real_T)j - (real_T)k);
      d_re_tmp = d_data[(int32_T)((real_T)j + 1.0) - 1].re;
      d_re = xi_im * d_re_tmp;
      d_im_tmp = d_data[(int32_T)((real_T)j + 1.0) - 1].im;
      xi_im *= d_im_tmp;
      xi_re = d_re * dc.re - xi_im * dc.im;
      xi_im = d_re * dc.im + xi_im * dc.re;
      if (k + 1 > a->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, a->size[0], &h_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      a_data[k].re += xi_re * varargout_1_re - xi_im * varargout_1_im;
      if (k + 1 > a->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, a->size[0], &g_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      a_data[k].im += xi_re * varargout_1_im + xi_im * varargout_1_re;
      if (((int32_T)((real_T)j + 1.0) < 1) ||
          ((int32_T)((real_T)j + 1.0) > d->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((real_T)j + 1.0), 1, d->size[0],
                                      &c_emlrtBCI, (emlrtCTX)sp);
      }
      st.site = &h_emlrtRSI;
      xi_im = nchoosek(&st, j, k);
      varargout_1_im = theta * -(real_T)k;
      if (varargout_1_im == 0.0) {
        varargout_1_re = muDoubleScalarExp(varargout_1_re_tmp);
        varargout_1_im = 0.0;
      } else {
        r = muDoubleScalarExp(varargout_1_re_tmp / 2.0);
        varargout_1_re = r * (r * muDoubleScalarCos(varargout_1_im));
        varargout_1_im = r * (r * muDoubleScalarSin(varargout_1_im));
      }
      d_re = xi_im * d_re_tmp;
      xi_im *= -d_im_tmp;
      xi_re = d_re * dc.re - xi_im * -dc.im;
      xi_im = d_re * -dc.im + xi_im * dc.re;
      if (k + 1 > a_->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, a_->size[0], &j_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      a__data[k].re += xi_re * varargout_1_re - xi_im * varargout_1_im;
      if (k + 1 > a_->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, a_->size[0], &i_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      a__data[k].im += xi_re * varargout_1_im + xi_im * varargout_1_re;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxInit_creal_T(sp, &coeffs, 1, &bb_emlrtRTEI);
  /*  multiply the polynomials together, aka Cauchy product */
  st.site = &i_emlrtRSI;
  conv(&st, a, a_, coeffs);
  a_data = coeffs->data;
  emxFree_creal_T(sp, &a_);
  emxFree_creal_T(sp, &a);
  if (1 > coeffs->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, coeffs->size[0], &b_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  emxInit_real_T(sp, &y, &x_emlrtRTEI);
  emxInit_real_T(sp, &x, &v_emlrtRTEI);
  st.site = &j_emlrtRSI;
  b_st.site = &gb_emlrtRSI;
  c_st.site = &hb_emlrtRSI;
  a_data[0].re -= C_over_omega * C_over_omega;
  /*     %% filter out the roots we care about */
  st.site = &k_emlrtRSI;
  flip(coeffs);
  st.site = &k_emlrtRSI;
  roots(&st, coeffs, d);
  d_data = d->data;
  /*  remove the roots with significant imaginary bits */
  st.site = &l_emlrtRSI;
  i = x->size[0];
  x->size[0] = d->size[0];
  emxEnsureCapacity_real_T(&st, x, i, &v_emlrtRTEI);
  x_data = x->data;
  nx = d->size[0];
  emxFree_creal_T(&st, &coeffs);
  for (i = 0; i < nx; i++) {
    x_data[i] = d_data[i].im;
  }
  b_st.site = &sc_emlrtRSI;
  nx = x->size[0];
  i = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity_real_T(&b_st, y, i, &w_emlrtRTEI);
  y_data = y->data;
  c_st.site = &tc_emlrtRSI;
  if ((1 <= x->size[0]) && (x->size[0] > 2147483646)) {
    d_st.site = &e_emlrtRSI;
    b_check_forloop_overflow_error(&d_st);
  }
  for (k = 0; k < nx; k++) {
    y_data[k] = muDoubleScalarAbs(x_data[k]);
  }
  emxFree_real_T(&b_st, &x);
  emxInit_boolean_T(&b_st, &b_r, &x_emlrtRTEI);
  i = b_r->size[0];
  b_r->size[0] = y->size[0];
  emxEnsureCapacity_boolean_T(sp, b_r, i, &x_emlrtRTEI);
  r1 = b_r->data;
  nx = y->size[0];
  for (i = 0; i < nx; i++) {
    r1[i] = (y_data[i] < 1.0E-8);
  }
  nx = b_r->size[0] - 1;
  trueCount = 0;
  for (i = 0; i <= nx; i++) {
    if (r1[i]) {
      trueCount++;
    }
  }
  idx = 0;
  for (i = 0; i <= nx; i++) {
    if (r1[i]) {
      if (i + 1 > d->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, d->size[0], &k_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      d_data[idx].re = d_data[i].re;
      if (i + 1 > d->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, d->size[0], &k_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      d_data[idx].im = d_data[i].im;
      idx++;
    }
  }
  emxFree_boolean_T(sp, &b_r);
  i = d->size[0];
  d->size[0] = trueCount;
  emxEnsureCapacity_creal_T(sp, d, i, &y_emlrtRTEI);
  d_data = d->data;
  /* remove the roots with negative real bits */
  nx = trueCount - 1;
  trueCount = 0;
  for (i = 0; i <= nx; i++) {
    if (d_data[i].re > 0.0) {
      trueCount++;
    }
  }
  idx = 0;
  for (i = 0; i <= nx; i++) {
    if (d_data[i].re > 0.0) {
      if ((i + 1 < 1) || (i + 1 > d->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, d->size[0], &l_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      d_data[idx].re = d_data[i].re;
      if ((i + 1 < 1) || (i + 1 > d->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, d->size[0], &l_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      d_data[idx].im = d_data[i].im;
      idx++;
    }
  }
  i = d->size[0];
  d->size[0] = trueCount;
  emxEnsureCapacity_creal_T(sp, d, i, &y_emlrtRTEI);
  d_data = d->data;
  /* take the smallest value */
  st.site = &m_emlrtRSI;
  i = y->size[0];
  y->size[0] = trueCount;
  emxEnsureCapacity_real_T(&st, y, i, &ab_emlrtRTEI);
  y_data = y->data;
  for (i = 0; i < trueCount; i++) {
    y_data[i] = d_data[i].re;
  }
  emxFree_creal_T(&st, &d);
  b_st.site = &uc_emlrtRSI;
  c_st.site = &vc_emlrtRSI;
  d_st.site = &wc_emlrtRSI;
  if (y->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &xc_emlrtRSI;
  f_st.site = &yc_emlrtRSI;
  nx = y->size[0];
  if (y->size[0] <= 2) {
    if (y->size[0] == 1) {
      r = y_data[0];
    } else if ((y_data[0] > y_data[1]) || (muDoubleScalarIsNaN(y_data[0]) &&
                                           (!muDoubleScalarIsNaN(y_data[1])))) {
      r = y_data[1];
    } else {
      r = y_data[0];
    }
  } else {
    g_st.site = &bd_emlrtRSI;
    if (!muDoubleScalarIsNaN(y_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &cd_emlrtRSI;
      if (y->size[0] > 2147483646) {
        i_st.site = &e_emlrtRSI;
        b_check_forloop_overflow_error(&i_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= nx)) {
        if (!muDoubleScalarIsNaN(y_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      r = y_data[0];
    } else {
      g_st.site = &ad_emlrtRSI;
      r = y_data[idx - 1];
      trueCount = idx + 1;
      h_st.site = &dd_emlrtRSI;
      if ((idx + 1 <= y->size[0]) && (y->size[0] > 2147483646)) {
        i_st.site = &e_emlrtRSI;
        b_check_forloop_overflow_error(&i_st);
      }
      for (k = trueCount; k <= nx; k++) {
        xi_im = y_data[k - 1];
        if (r > xi_im) {
          r = xi_im;
        }
      }
    }
  }
  emxFree_real_T(&f_st, &y);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return r;
}

/* End of code generation (get_r_given_theta.c) */
