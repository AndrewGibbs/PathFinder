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
#include "plan_b_isection.h"
#include "roots.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo g_emlrtRSI = {
    19,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo h_emlrtRSI = {
    22,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo i_emlrtRSI = {
    23,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo j_emlrtRSI = {
    28,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo k_emlrtRSI = {
    29,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo l_emlrtRSI = {
    32,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo m_emlrtRSI = {
    38,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo n_emlrtRSI = {
    43,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo o_emlrtRSI = {
    45,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo p_emlrtRSI = {
    48,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo jb_emlrtRSI = {
    44,                                                          /* lineNo */
    "mpower",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/mpower.m" /* pathName */
};

static emlrtRSInfo kb_emlrtRSI = {
    71,                                                      /* lineNo */
    "power",                                                 /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/ops/power.m" /* pathName */
};

static emlrtRSInfo vc_emlrtRSI = {
    18,                                                      /* lineNo */
    "abs",                                                   /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/elfun/abs.m" /* pathName */
};

static emlrtRSInfo wc_emlrtRSI =
    {
        74,                    /* lineNo */
        "applyScalarFunction", /* fcnName */
        "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
        "applyScalarFunction.m" /* pathName */
};

static emlrtRSInfo xc_emlrtRSI = {
    32,                                                         /* lineNo */
    "sort",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/sort.m" /* pathName */
};

static emlrtBCInfo
    d_emlrtBCI =
        {
            -1,                              /* iFirst */
            -1,                              /* iLast */
            38,                              /* lineNo */
            61,                              /* colNo */
            "roots_with_positive_real_part", /* aName */
            "get_r_given_theta",             /* fName */
            "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
            "get_r_given_theta.m", /* pName */
            0                      /* checkKind */
};

static emlrtBCInfo
    e_emlrtBCI =
        {
            -1,                  /* iFirst */
            -1,                  /* iLast */
            35,                  /* lineNo */
            45,                  /* colNo */
            "r_roots",           /* aName */
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
            23,                  /* lineNo */
            16,                  /* colNo */
            "a_",                /* aName */
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
            22,                  /* lineNo */
            15,                  /* colNo */
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
            17,                  /* lineNo */
            7,                   /* colNo */
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
            22,                  /* lineNo */
            33,                  /* colNo */
            "d",                 /* aName */
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
            18,                  /* lineNo */
            8,                   /* colNo */
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
            23,                  /* lineNo */
            40,                  /* colNo */
            "d",                 /* aName */
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
            29,                  /* lineNo */
            12,                  /* colNo */
            "coeffs",            /* aName */
            "get_r_given_theta", /* fName */
            "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
            "get_r_given_theta.m", /* pName */
            0                      /* checkKind */
};

static emlrtRTEInfo s_emlrtRTEI = {
    11,                  /* lineNo */
    5,                   /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo t_emlrtRTEI = {
    12,                  /* lineNo */
    5,                   /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo u_emlrtRTEI = {
    19,                  /* lineNo */
    5,                   /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo v_emlrtRTEI = {
    1,                   /* lineNo */
    16,                  /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo w_emlrtRTEI = {
    38,                  /* lineNo */
    65,                  /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo x_emlrtRTEI =
    {
        30,                    /* lineNo */
        21,                    /* colNo */
        "applyScalarFunction", /* fName */
        "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
        "applyScalarFunction.m" /* pName */
};

static emlrtRTEInfo y_emlrtRTEI = {
    38,                  /* lineNo */
    61,                  /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    48,                  /* lineNo */
    17,                  /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    43,                  /* lineNo */
    9,                   /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    28,                  /* lineNo */
    5,                   /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo db_emlrtRTEI = {
    35,                  /* lineNo */
    5,                   /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    38,                  /* lineNo */
    5,                   /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

/* Function Definitions */
real_T get_r_given_theta(const emlrtStack *sp, const emxArray_creal_T *g_coeffs,
                         const creal_T xi, real_T C_over_omega, real_T theta,
                         real_T imag_thresh)
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
  emxArray_creal_T *real_and_positive_roots;
  emxArray_creal_T *roots_with_positive_real_part;
  emxArray_real_T *guesses;
  emxArray_real_T *x;
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
  real_T *guesses_data;
  real_T *x_data;
  int32_T i;
  int32_T idx;
  int32_T k;
  int32_T nx;
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
  /* intersects the boundary of the blob |g(\xi)-g(\xi+r*exp(i*theta)|=C/omega
   */
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
    emlrtDynamicBoundsCheckR2012b(1, 1, a->size[0], &h_emlrtBCI, (emlrtCTX)sp);
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
    emlrtDynamicBoundsCheckR2012b(1, 1, a_->size[0], &j_emlrtBCI, (emlrtCTX)sp);
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
  st.site = &g_emlrtRSI;
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
                                      &i_emlrtBCI, (emlrtCTX)sp);
      }
      st.site = &h_emlrtRSI;
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
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, a->size[0], &g_emlrtBCI,
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
                                      &k_emlrtBCI, (emlrtCTX)sp);
      }
      st.site = &i_emlrtRSI;
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
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, a_->size[0], &f_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      a__data[k].re += xi_re * varargout_1_re - xi_im * varargout_1_im;
      if (k + 1 > a_->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, a_->size[0], &f_emlrtBCI,
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
  emxInit_creal_T(sp, &coeffs, 1, &cb_emlrtRTEI);
  /*  multiply the polynomials together, aka Cauchy product */
  st.site = &j_emlrtRSI;
  conv(&st, a, a_, coeffs);
  a_data = coeffs->data;
  emxFree_creal_T(sp, &a_);
  emxFree_creal_T(sp, &a);
  if (1 > coeffs->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, coeffs->size[0], &l_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  st.site = &k_emlrtRSI;
  b_st.site = &jb_emlrtRSI;
  c_st.site = &kb_emlrtRSI;
  a_data[0].re -= C_over_omega * C_over_omega;
  /*     %% filter out the roots we care about */
  st.site = &l_emlrtRSI;
  flip(coeffs);
  st.site = &l_emlrtRSI;
  roots(&st, coeffs, d);
  d_data = d->data;
  /* remove the roots with negative real bits        */
  idx = d->size[0] - 1;
  nx = 0;
  emxFree_creal_T(sp, &coeffs);
  for (i = 0; i <= idx; i++) {
    if (d_data[i].re > 0.0) {
      nx++;
    }
  }
  emxInit_creal_T(sp, &roots_with_positive_real_part, 1, &db_emlrtRTEI);
  i = roots_with_positive_real_part->size[0];
  roots_with_positive_real_part->size[0] = nx;
  emxEnsureCapacity_creal_T(sp, roots_with_positive_real_part, i, &v_emlrtRTEI);
  a__data = roots_with_positive_real_part->data;
  nx = 0;
  for (i = 0; i <= idx; i++) {
    if (d_data[i].re > 0.0) {
      if (i + 1 > d->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, d->size[0], &e_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      a__data[nx].re = d_data[i].re;
      if (i + 1 > d->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, d->size[0], &e_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      a__data[nx].im = d_data[i].im;
      nx++;
    }
  }
  emxFree_creal_T(sp, &d);
  emxInit_real_T(sp, &guesses, &bb_emlrtRTEI);
  emxInit_real_T(sp, &x, &w_emlrtRTEI);
  /*  remove the roots with significant imaginary bits */
  st.site = &m_emlrtRSI;
  i = x->size[0];
  x->size[0] = roots_with_positive_real_part->size[0];
  emxEnsureCapacity_real_T(&st, x, i, &w_emlrtRTEI);
  x_data = x->data;
  nx = roots_with_positive_real_part->size[0];
  for (i = 0; i < nx; i++) {
    x_data[i] = a__data[i].im;
  }
  b_st.site = &vc_emlrtRSI;
  nx = x->size[0];
  i = guesses->size[0];
  guesses->size[0] = x->size[0];
  emxEnsureCapacity_real_T(&b_st, guesses, i, &x_emlrtRTEI);
  guesses_data = guesses->data;
  c_st.site = &wc_emlrtRSI;
  if ((1 <= x->size[0]) && (x->size[0] > 2147483646)) {
    d_st.site = &f_emlrtRSI;
    b_check_forloop_overflow_error(&d_st);
  }
  for (k = 0; k < nx; k++) {
    guesses_data[k] = muDoubleScalarAbs(x_data[k]);
  }
  emxFree_real_T(&b_st, &x);
  emxInit_boolean_T(&b_st, &b_r, &y_emlrtRTEI);
  i = b_r->size[0];
  b_r->size[0] = guesses->size[0];
  emxEnsureCapacity_boolean_T(sp, b_r, i, &y_emlrtRTEI);
  r1 = b_r->data;
  nx = guesses->size[0];
  for (i = 0; i < nx; i++) {
    r1[i] = (guesses_data[i] < imag_thresh);
  }
  idx = b_r->size[0] - 1;
  nx = 0;
  for (i = 0; i <= idx; i++) {
    if (r1[i]) {
      nx++;
    }
  }
  emxInit_creal_T(sp, &real_and_positive_roots, 1, &eb_emlrtRTEI);
  i = real_and_positive_roots->size[0];
  real_and_positive_roots->size[0] = nx;
  emxEnsureCapacity_creal_T(sp, real_and_positive_roots, i, &v_emlrtRTEI);
  a_data = real_and_positive_roots->data;
  nx = 0;
  for (i = 0; i <= idx; i++) {
    if (r1[i]) {
      if (i + 1 > roots_with_positive_real_part->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1,
                                      roots_with_positive_real_part->size[0],
                                      &d_emlrtBCI, (emlrtCTX)sp);
      }
      a_data[nx].re = a__data[i].re;
      if (i + 1 > roots_with_positive_real_part->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1,
                                      roots_with_positive_real_part->size[0],
                                      &d_emlrtBCI, (emlrtCTX)sp);
      }
      a_data[nx].im = a__data[i].im;
      nx++;
    }
  }
  emxFree_boolean_T(sp, &b_r);
  if (real_and_positive_roots->size[0] == 0) {
    /*          print("Warning - no suitable radii found with current 'imag
     * thresh' parameter (default is 1e-8), attempting a bisection") */
    st.site = &n_emlrtRSI;
    i = guesses->size[0];
    guesses->size[0] = roots_with_positive_real_part->size[0];
    emxEnsureCapacity_real_T(&st, guesses, i, &bb_emlrtRTEI);
    guesses_data = guesses->data;
    nx = roots_with_positive_real_part->size[0];
    for (i = 0; i < nx; i++) {
      guesses_data[i] = a__data[i].re;
    }
    b_st.site = &xc_emlrtRSI;
    sort(&b_st, guesses);
    /*  no obvious canditates for roots. */
    st.site = &o_emlrtRSI;
    r = plan_b_isection(&st, g_coeffs, xi, C_over_omega, theta, guesses);
  } else {
    /* take the smallest value */
    st.site = &p_emlrtRSI;
    i = guesses->size[0];
    guesses->size[0] = real_and_positive_roots->size[0];
    emxEnsureCapacity_real_T(&st, guesses, i, &ab_emlrtRTEI);
    guesses_data = guesses->data;
    nx = real_and_positive_roots->size[0];
    for (i = 0; i < nx; i++) {
      guesses_data[i] = a_data[i].re;
    }
    b_st.site = &se_emlrtRSI;
    c_st.site = &te_emlrtRSI;
    d_st.site = &ue_emlrtRSI;
    e_st.site = &ve_emlrtRSI;
    f_st.site = &we_emlrtRSI;
    nx = guesses->size[0];
    if (guesses->size[0] <= 2) {
      if (guesses->size[0] == 1) {
        r = guesses_data[0];
      } else if ((guesses_data[0] > guesses_data[1]) ||
                 (muDoubleScalarIsNaN(guesses_data[0]) &&
                  (!muDoubleScalarIsNaN(guesses_data[1])))) {
        r = guesses_data[1];
      } else {
        r = guesses_data[0];
      }
    } else {
      g_st.site = &he_emlrtRSI;
      if (!muDoubleScalarIsNaN(guesses_data[0])) {
        idx = 1;
      } else {
        idx = 0;
        h_st.site = &ie_emlrtRSI;
        if (guesses->size[0] > 2147483646) {
          i_st.site = &f_emlrtRSI;
          b_check_forloop_overflow_error(&i_st);
        }
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= nx)) {
          if (!muDoubleScalarIsNaN(guesses_data[k - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (idx == 0) {
        r = guesses_data[0];
      } else {
        g_st.site = &ge_emlrtRSI;
        r = guesses_data[idx - 1];
        i = idx + 1;
        h_st.site = &je_emlrtRSI;
        if ((idx + 1 <= guesses->size[0]) && (guesses->size[0] > 2147483646)) {
          i_st.site = &f_emlrtRSI;
          b_check_forloop_overflow_error(&i_st);
        }
        for (k = i; k <= nx; k++) {
          xi_im = guesses_data[k - 1];
          if (r > xi_im) {
            r = xi_im;
          }
        }
      }
    }
  }
  emxFree_real_T(sp, &guesses);
  emxFree_creal_T(sp, &real_and_positive_roots);
  emxFree_creal_T(sp, &roots_with_positive_real_part);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return r;
}

/* End of code generation (get_r_given_theta.c) */
