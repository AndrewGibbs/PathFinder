/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_smallest_supset_ball.c
 *
 * Code generation for function 'get_smallest_supset_ball'
 *
 */

/* Include files */
#include "get_smallest_supset_ball.h"
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
static emlrtRSInfo
    emlrtRSI =
        {
            8,                          /* lineNo */
            "get_smallest_supset_ball", /* fcnName */
            "/home/andrew/OneDrive/PathFinder/src/covers/"
            "get_smallest_supset_ball.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    22,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo c_emlrtRSI = {
    25,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo d_emlrtRSI = {
    26,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo e_emlrtRSI = {
    31,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo f_emlrtRSI = {
    32,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo g_emlrtRSI = {
    35,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo h_emlrtRSI = {
    38,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo i_emlrtRSI = {
    44,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo db_emlrtRSI = {
    44,                                                          /* lineNo */
    "mpower",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/mpower.m" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI = {
    71,                                                      /* lineNo */
    "power",                                                 /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/ops/power.m" /* pathName */
};

static emlrtRSInfo pc_emlrtRSI = {
    18,                                                      /* lineNo */
    "abs",                                                   /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/elfun/abs.m" /* pathName */
};

static emlrtRSInfo qc_emlrtRSI =
    {
        74,                    /* lineNo */
        "applyScalarFunction", /* fcnName */
        "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
        "applyScalarFunction.m" /* pathName */
};

static emlrtRSInfo rc_emlrtRSI = {
    15,                                                        /* lineNo */
    "min",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/min.m" /* pathName */
};

static emlrtRSInfo sc_emlrtRSI = {
    46,         /* lineNo */
    "minOrMax", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                       */
};

static emlrtRSInfo tc_emlrtRSI = {
    92,        /* lineNo */
    "minimum", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                       */
};

static emlrtRTEInfo emlrtRTEI = {
    130,             /* lineNo */
    27,              /* colNo */
    "unaryMinOrMax", /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m" /* pName
                                                                            */
};

static emlrtBCInfo
    emlrtBCI =
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
    b_emlrtBCI =
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
    c_emlrtBCI =
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
    d_emlrtBCI =
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
    e_emlrtBCI =
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
    f_emlrtBCI =
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
    g_emlrtBCI =
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
    h_emlrtBCI =
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
    i_emlrtBCI =
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
    j_emlrtBCI =
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
    k_emlrtBCI =
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

static emlrtRTEInfo q_emlrtRTEI = {
    14,                  /* lineNo */
    5,                   /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo r_emlrtRTEI = {
    15,                  /* lineNo */
    5,                   /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo s_emlrtRTEI = {
    22,                  /* lineNo */
    5,                   /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo t_emlrtRTEI = {
    38,                  /* lineNo */
    27,                  /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo u_emlrtRTEI =
    {
        30,                    /* lineNo */
        21,                    /* colNo */
        "applyScalarFunction", /* fName */
        "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
        "applyScalarFunction.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    38,                  /* lineNo */
    23,                  /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo
    w_emlrtRTEI =
        {
            8,                          /* lineNo */
            20,                         /* colNo */
            "get_smallest_supset_ball", /* fName */
            "/home/andrew/OneDrive/PathFinder/src/covers/"
            "get_smallest_supset_ball.m" /* pName */
};

static emlrtRTEInfo x_emlrtRTEI = {
    44,                  /* lineNo */
    13,                  /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo y_emlrtRTEI = {
    31,                  /* lineNo */
    5,                   /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

/* Function Definitions */
real_T get_smallest_supset_ball(const emlrtStack *sp,
                                const emxArray_creal_T *g_coeffs, real_T freq,
                                const creal_T xi, real_T Cosc)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_boolean_T *b_r;
  emxArray_creal_T *a_;
  emxArray_creal_T *b_a;
  emxArray_creal_T *coeffs;
  emxArray_creal_T *d;
  emxArray_real_T *x;
  emxArray_real_T *y;
  const creal_T *g_coeffs_data;
  creal_T dc;
  creal_T *a__data;
  creal_T *a_data;
  creal_T *d_data;
  real_T radii[16];
  real_T a;
  real_T d_im_tmp;
  real_T d_re;
  real_T d_re_tmp;
  real_T r;
  real_T varargout_1_im;
  real_T varargout_1_re;
  real_T xi_im;
  real_T xi_re;
  real_T *x_data;
  real_T *y_data;
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T i;
  int32_T k;
  int32_T last;
  int32_T loop_ub;
  int32_T n;
  int32_T nx;
  uint32_T j;
  boolean_T b;
  boolean_T b1;
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
  g_coeffs_data = g_coeffs->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &y, &v_emlrtRTEI);
  /* find the smallest ball containing the blob such that freq*|g(z)-g(\xi)|<C
   */
  a = Cosc / freq;
  loop_ub = g_coeffs->size[0];
  b = (g_coeffs->size[0] == 0);
  b1 = (g_coeffs->size[0] == 0);
  b_loop_ub = g_coeffs->size[0];
  i = g_coeffs->size[0];
  emxInit_creal_T(sp, &b_a, 1, &q_emlrtRTEI);
  emxInit_creal_T(sp, &a_, 1, &r_emlrtRTEI);
  emxInit_creal_T(sp, &d, 1, &s_emlrtRTEI);
  emxInit_creal_T(sp, &coeffs, 1, &y_emlrtRTEI);
  emxInit_boolean_T(sp, &b_r, &v_emlrtRTEI);
  emxInit_real_T(sp, &x, &t_emlrtRTEI);
  for (n = 0; n < 16; n++) {
    st.site = &emlrtRSI;
    /* given a ray from \xi, in direction theta, find r at which the ray */
    /* intersects the boundary of the blob |g(\xi)-g(\xi+r*exp(i*theta)|=C */
    /*  threshold for negligable imaginary part */
    /*  set the function g. I could just pass it, but not sure how MEX feels */
    /*  about that. */
    /*  pre-allocate stuff */
    b_i = b_a->size[0];
    b_a->size[0] = g_coeffs->size[0];
    emxEnsureCapacity_creal_T(&st, b_a, b_i, &q_emlrtRTEI);
    a_data = b_a->data;
    b_i = a_->size[0];
    a_->size[0] = g_coeffs->size[0];
    emxEnsureCapacity_creal_T(&st, a_, b_i, &r_emlrtRTEI);
    a__data = a_->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      a_data[b_i].re = 0.0;
      a_data[b_i].im = 0.0;
      a__data[b_i].re = 0.0;
      a__data[b_i].im = 0.0;
    }
    /*     %% follow the algorithm, as written in my notes (and soon, the paper)
     */
    /*  remember that the indexing of the polynomial coefficients is the */
    /*  opposite in my notes as in Matlab */
    if (1 > b_a->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, b_a->size[0], &e_emlrtBCI, &st);
    }
    if (!b) {
      varargout_1_re = g_coeffs_data[0].re;
      varargout_1_im = g_coeffs_data[0].im;
      b_i = g_coeffs->size[0];
      for (k = 0; k <= b_i - 2; k++) {
        xi_re = xi.re * varargout_1_re - xi.im * varargout_1_im;
        xi_im = xi.re * varargout_1_im + xi.im * varargout_1_re;
        varargout_1_re = xi_re + g_coeffs_data[k + 1].re;
        varargout_1_im = xi_im + g_coeffs_data[k + 1].im;
      }
    }
    a_data[0].re = -varargout_1_re;
    a_data[0].im = -varargout_1_im;
    if (1 > a_->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, a_->size[0], &c_emlrtBCI, &st);
    }
    if (!b1) {
      varargout_1_re = g_coeffs_data[0].re;
      varargout_1_im = g_coeffs_data[0].im;
      b_i = g_coeffs->size[0];
      for (k = 0; k <= b_i - 2; k++) {
        xi_re = xi.re * varargout_1_re - xi.im * varargout_1_im;
        xi_im = xi.re * varargout_1_im + xi.im * varargout_1_re;
        varargout_1_re = xi_re + g_coeffs_data[k + 1].re;
        varargout_1_im = xi_im + g_coeffs_data[k + 1].im;
      }
    }
    a__data[0].re = -varargout_1_re;
    a__data[0].im = varargout_1_im;
    b_i = d->size[0];
    d->size[0] = g_coeffs->size[0];
    emxEnsureCapacity_creal_T(&st, d, b_i, &s_emlrtRTEI);
    d_data = d->data;
    for (b_i = 0; b_i < b_loop_ub; b_i++) {
      d_data[b_i] = g_coeffs_data[b_i];
    }
    b_st.site = &b_emlrtRSI;
    flip(d);
    d_data = d->data;
    for (k = 0; k < i; k++) {
      b_i = g_coeffs->size[0] - k;
      for (nx = 0; nx < b_i; nx++) {
        j = (uint32_T)k + nx;
        if (((int32_T)((real_T)j + 1.0) < 1) ||
            ((int32_T)((real_T)j + 1.0) > d->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((real_T)j + 1.0), 1,
                                        d->size[0], &d_emlrtBCI, &st);
        }
        b_st.site = &c_emlrtRSI;
        xi_im = nchoosek(&b_st, j, k);
        varargout_1_im = 6.2831853071795862 * (real_T)k;
        if (varargout_1_im == 0.0) {
          varargout_1_re = 1.0;
          varargout_1_im = 0.0;
        } else {
          varargout_1_re = muDoubleScalarCos(varargout_1_im);
          varargout_1_im = muDoubleScalarSin(varargout_1_im);
        }
        dc = mpower(xi, (real_T)j - (real_T)k);
        d_re_tmp = d_data[(int32_T)((real_T)j + 1.0) - 1].re;
        d_re = xi_im * d_re_tmp;
        d_im_tmp = d_data[(int32_T)((real_T)j + 1.0) - 1].im;
        xi_im *= d_im_tmp;
        xi_re = d_re * dc.re - xi_im * dc.im;
        xi_im = d_re * dc.im + xi_im * dc.re;
        if (k + 1 > b_a->size[0]) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, b_a->size[0], &g_emlrtBCI,
                                        &st);
        }
        a_data[k].re += xi_re * varargout_1_re - xi_im * varargout_1_im;
        if (k + 1 > b_a->size[0]) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, b_a->size[0], &f_emlrtBCI,
                                        &st);
        }
        a_data[k].im += xi_re * varargout_1_im + xi_im * varargout_1_re;
        if (((int32_T)((real_T)j + 1.0) < 1) ||
            ((int32_T)((real_T)j + 1.0) > d->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((real_T)j + 1.0), 1,
                                        d->size[0], &b_emlrtBCI, &st);
        }
        b_st.site = &d_emlrtRSI;
        xi_im = nchoosek(&b_st, j, k);
        varargout_1_im = 6.2831853071795862 * -(real_T)k;
        if (varargout_1_im == 0.0) {
          varargout_1_re = 1.0;
          varargout_1_im = 0.0;
        } else {
          varargout_1_re = muDoubleScalarCos(varargout_1_im);
          varargout_1_im = muDoubleScalarSin(varargout_1_im);
        }
        d_re = xi_im * d_re_tmp;
        xi_im *= -d_im_tmp;
        xi_re = d_re * dc.re - xi_im * -dc.im;
        xi_im = d_re * -dc.im + xi_im * dc.re;
        if (k + 1 > a_->size[0]) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, a_->size[0], &i_emlrtBCI,
                                        &st);
        }
        a__data[k].re += xi_re * varargout_1_re - xi_im * varargout_1_im;
        if (k + 1 > a_->size[0]) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, a_->size[0], &h_emlrtBCI,
                                        &st);
        }
        a__data[k].im += xi_re * varargout_1_im + xi_im * varargout_1_re;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    /*  multiply the polynomials together, aka Cauchy product */
    b_st.site = &e_emlrtRSI;
    conv(&b_st, b_a, a_, coeffs);
    a_data = coeffs->data;
    if (1 > coeffs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, coeffs->size[0], &emlrtBCI, &st);
    }
    b_st.site = &f_emlrtRSI;
    c_st.site = &db_emlrtRSI;
    d_st.site = &eb_emlrtRSI;
    a_data[0].re -= a * a;
    /*     %% filter out the roots we care about */
    b_st.site = &g_emlrtRSI;
    flip(coeffs);
    b_st.site = &g_emlrtRSI;
    roots(&b_st, coeffs, d);
    d_data = d->data;
    /*  remove the roots with significant imaginary bits */
    b_st.site = &h_emlrtRSI;
    b_i = x->size[0];
    x->size[0] = d->size[0];
    emxEnsureCapacity_real_T(&b_st, x, b_i, &t_emlrtRTEI);
    x_data = x->data;
    nx = d->size[0];
    for (b_i = 0; b_i < nx; b_i++) {
      x_data[b_i] = d_data[b_i].im;
    }
    c_st.site = &pc_emlrtRSI;
    nx = x->size[0];
    b_i = y->size[0];
    y->size[0] = x->size[0];
    emxEnsureCapacity_real_T(&c_st, y, b_i, &u_emlrtRTEI);
    y_data = y->data;
    d_st.site = &qc_emlrtRSI;
    if ((1 <= x->size[0]) && (x->size[0] > 2147483646)) {
      e_st.site = &m_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    for (k = 0; k < nx; k++) {
      y_data[k] = muDoubleScalarAbs(x_data[k]);
    }
    b_i = b_r->size[0];
    b_r->size[0] = y->size[0];
    emxEnsureCapacity_boolean_T(&st, b_r, b_i, &v_emlrtRTEI);
    r1 = b_r->data;
    nx = y->size[0];
    for (b_i = 0; b_i < nx; b_i++) {
      r1[b_i] = (y_data[b_i] < 1.0E-8);
    }
    nx = b_r->size[0] - 1;
    k = 0;
    for (b_i = 0; b_i <= nx; b_i++) {
      if (r1[b_i]) {
        k++;
      }
    }
    last = 0;
    for (b_i = 0; b_i <= nx; b_i++) {
      if (r1[b_i]) {
        if (b_i + 1 > d->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, d->size[0], &j_emlrtBCI,
                                        &st);
        }
        d_data[last].re = d_data[b_i].re;
        if (b_i + 1 > d->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, d->size[0], &j_emlrtBCI,
                                        &st);
        }
        d_data[last].im = d_data[b_i].im;
        last++;
      }
    }
    b_i = d->size[0];
    d->size[0] = k;
    emxEnsureCapacity_creal_T(&st, d, b_i, &w_emlrtRTEI);
    d_data = d->data;
    /* remove the roots with negative real bits */
    nx = k - 1;
    k = 0;
    for (b_i = 0; b_i <= nx; b_i++) {
      if (d_data[b_i].re > 0.0) {
        k++;
      }
    }
    last = 0;
    for (b_i = 0; b_i <= nx; b_i++) {
      if (d_data[b_i].re > 0.0) {
        if ((b_i + 1 < 1) || (b_i + 1 > d->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, d->size[0], &k_emlrtBCI,
                                        &st);
        }
        d_data[last].re = d_data[b_i].re;
        if ((b_i + 1 < 1) || (b_i + 1 > d->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, d->size[0], &k_emlrtBCI,
                                        &st);
        }
        d_data[last].im = d_data[b_i].im;
        last++;
      }
    }
    b_i = d->size[0];
    d->size[0] = k;
    emxEnsureCapacity_creal_T(&st, d, b_i, &w_emlrtRTEI);
    d_data = d->data;
    /* take the smallest value */
    b_st.site = &i_emlrtRSI;
    b_i = y->size[0];
    y->size[0] = k;
    emxEnsureCapacity_real_T(&b_st, y, b_i, &x_emlrtRTEI);
    y_data = y->data;
    for (b_i = 0; b_i < k; b_i++) {
      y_data[b_i] = d_data[b_i].re;
    }
    c_st.site = &rc_emlrtRSI;
    d_st.site = &sc_emlrtRSI;
    e_st.site = &tc_emlrtRSI;
    if (y->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }
    last = y->size[0];
    if (y->size[0] <= 2) {
      if (y->size[0] == 1) {
        radii[n] = y_data[0];
      } else if ((y_data[0] > y_data[1]) ||
                 (muDoubleScalarIsNaN(y_data[0]) &&
                  (!muDoubleScalarIsNaN(y_data[1])))) {
        radii[n] = y_data[1];
      } else {
        radii[n] = y_data[0];
      }
    } else {
      if (!muDoubleScalarIsNaN(y_data[0])) {
        nx = 1;
      } else {
        nx = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= last)) {
          if (!muDoubleScalarIsNaN(y_data[k - 1])) {
            nx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (nx == 0) {
        radii[n] = y_data[0];
      } else {
        xi_im = y_data[nx - 1];
        b_i = nx + 1;
        for (k = b_i; k <= last; k++) {
          xi_re = y_data[k - 1];
          if (xi_im > xi_re) {
            xi_im = xi_re;
          }
        }
        radii[n] = xi_im;
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_real_T(sp, &x);
  emxFree_real_T(sp, &y);
  emxFree_boolean_T(sp, &b_r);
  emxFree_creal_T(sp, &coeffs);
  emxFree_creal_T(sp, &d);
  emxFree_creal_T(sp, &a_);
  emxFree_creal_T(sp, &b_a);
  if (!muDoubleScalarIsNaN(radii[0])) {
    nx = 1;
  } else {
    nx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 17)) {
      if (!muDoubleScalarIsNaN(radii[k - 1])) {
        nx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (nx == 0) {
    r = radii[0];
  } else {
    r = radii[nx - 1];
    i = nx + 1;
    for (k = i; k < 17; k++) {
      xi_re = radii[k - 1];
      if (r > xi_re) {
        r = xi_re;
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return r;
}

/* End of code generation (get_smallest_supset_ball.c) */
