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
#include "abs.h"
#include "conv.h"
#include "eml_int_forloop_overflow_check.h"
#include "flip.h"
#include "get_smallest_supset_ball_data.h"
#include "get_smallest_supset_ball_emxutil.h"
#include "get_smallest_supset_ball_types.h"
#include "mpower.h"
#include "nchoosek.h"
#include "polyval.h"
#include "roots.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo
    emlrtRSI =
        {
            5,                          /* lineNo */
            "get_smallest_supset_ball", /* fcnName */
            "/home/andrew/OneDrive/PathFinder/src/covers/"
            "get_smallest_supset_ball.m" /* pathName */
};

static emlrtRSInfo
    b_emlrtRSI =
        {
            7,                          /* lineNo */
            "get_smallest_supset_ball", /* fcnName */
            "/home/andrew/OneDrive/PathFinder/src/covers/"
            "get_smallest_supset_ball.m" /* pathName */
};

static emlrtRSInfo
    c_emlrtRSI =
        {
            9,                          /* lineNo */
            "get_smallest_supset_ball", /* fcnName */
            "/home/andrew/OneDrive/PathFinder/src/covers/"
            "get_smallest_supset_ball.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    22,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo f_emlrtRSI = {
    25,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo g_emlrtRSI = {
    26,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo h_emlrtRSI = {
    31,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo i_emlrtRSI = {
    32,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo j_emlrtRSI = {
    35,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo k_emlrtRSI = {
    38,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo l_emlrtRSI = {
    44,                  /* lineNo */
    "get_r_given_theta", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pathName
                                                                            */
};

static emlrtRSInfo fb_emlrtRSI = {
    44,                                                          /* lineNo */
    "mpower",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/mpower.m" /* pathName */
};

static emlrtRSInfo gb_emlrtRSI = {
    71,                                                      /* lineNo */
    "power",                                                 /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/ops/power.m" /* pathName */
};

static emlrtRSInfo tc_emlrtRSI = {
    15,                                                        /* lineNo */
    "min",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/min.m" /* pathName */
};

static emlrtRSInfo uc_emlrtRSI = {
    46,         /* lineNo */
    "minOrMax", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                       */
};

static emlrtRSInfo vc_emlrtRSI = {
    92,        /* lineNo */
    "minimum", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                       */
};

static emlrtRSInfo wc_emlrtRSI = {
    204,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m" /* pathName
                                                                            */
};

static emlrtRSInfo xc_emlrtRSI = {
    893,                    /* lineNo */
    "minRealVectorOmitNaN", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m" /* pathName
                                                                            */
};

static emlrtRSInfo yc_emlrtRSI = {
    62,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo ad_emlrtRSI = {
    54,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo bd_emlrtRSI = {
    103,         /* lineNo */
    "findFirst", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo cd_emlrtRSI = {
    120,                        /* lineNo */
    "minOrMaxRealVectorKernel", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo dd_emlrtRSI = {
    15,                                                        /* lineNo */
    "max",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/max.m" /* pathName */
};

static emlrtRSInfo ed_emlrtRSI = {
    44,         /* lineNo */
    "minOrMax", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                       */
};

static emlrtRSInfo fd_emlrtRSI = {
    79,        /* lineNo */
    "maximum", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                       */
};

static emlrtRSInfo gd_emlrtRSI = {
    186,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m" /* pathName
                                                                            */
};

static emlrtRSInfo hd_emlrtRSI = {
    897,                    /* lineNo */
    "maxRealVectorOmitNaN", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m" /* pathName
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

static emlrtDCInfo emlrtDCI =
    {
        3,                          /* lineNo */
        19,                         /* colNo */
        "get_smallest_supset_ball", /* fName */
        "/home/andrew/OneDrive/PathFinder/src/covers/"
        "get_smallest_supset_ball.m", /* pName */
        1                             /* checkKind */
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

static emlrtBCInfo l_emlrtBCI =
    {
        -1,                         /* iFirst */
        -1,                         /* iLast */
        7,                          /* lineNo */
        15,                         /* colNo */
        "radii",                    /* aName */
        "get_smallest_supset_ball", /* fName */
        "/home/andrew/OneDrive/PathFinder/src/covers/"
        "get_smallest_supset_ball.m", /* pName */
        0                             /* checkKind */
};

static emlrtRTEInfo
    q_emlrtRTEI =
        {
            3,                          /* lineNo */
            13,                         /* colNo */
            "get_smallest_supset_ball", /* fName */
            "/home/andrew/OneDrive/PathFinder/src/covers/"
            "get_smallest_supset_ball.m" /* pName */
};

static emlrtRTEInfo r_emlrtRTEI = {
    14,                  /* lineNo */
    5,                   /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo s_emlrtRTEI = {
    15,                  /* lineNo */
    5,                   /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo t_emlrtRTEI = {
    22,                  /* lineNo */
    5,                   /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

static emlrtRTEInfo u_emlrtRTEI = {
    38,                  /* lineNo */
    27,                  /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
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
            7,                          /* lineNo */
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

static emlrtRTEInfo
    y_emlrtRTEI =
        {
            3,                          /* lineNo */
            5,                          /* colNo */
            "get_smallest_supset_ball", /* fName */
            "/home/andrew/OneDrive/PathFinder/src/covers/"
            "get_smallest_supset_ball.m" /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    31,                  /* lineNo */
    5,                   /* colNo */
    "get_r_given_theta", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/get_r_given_theta.m" /* pName
                                                                            */
};

/* Function Definitions */
real_T get_smallest_supset_ball(const emlrtStack *sp,
                                const emxArray_creal_T *g_coeffs, real_T freq,
                                const creal_T xi, real_T Cosc,
                                uint32_T num_rays)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack st;
  emxArray_boolean_T *b_r;
  emxArray_creal_T *a;
  emxArray_creal_T *a_;
  emxArray_creal_T *coeffs;
  emxArray_creal_T *d;
  emxArray_real_T *b_d;
  emxArray_real_T *radii;
  emxArray_real_T *varargin_1;
  const creal_T *g_coeffs_data;
  creal_T dc;
  creal_T *a__data;
  creal_T *a_data;
  creal_T *d_data;
  real_T b;
  real_T b_a;
  real_T d_im;
  real_T d_im_tmp;
  real_T d_re;
  real_T d_re_tmp;
  real_T d_theta;
  real_T r;
  real_T theta;
  real_T y_im;
  real_T y_re;
  real_T y_re_tmp;
  real_T *b_d_data;
  real_T *radii_data;
  int32_T b_i;
  int32_T i;
  int32_T idx;
  int32_T k;
  int32_T last;
  int32_T n;
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
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  g_coeffs_data = g_coeffs->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /* find the smallest ball containing the blob such that freq*|g(z)-g(\xi)|<C
   */
  if ((real_T)num_rays != (int32_T)num_rays) {
    emlrtIntegerCheckR2012b(num_rays, &emlrtDCI, (emlrtCTX)sp);
  }
  emxInit_real_T(sp, &radii, &y_emlrtRTEI);
  i = radii->size[0];
  radii->size[0] = (int32_T)num_rays;
  emxEnsureCapacity_real_T(sp, radii, i, &q_emlrtRTEI);
  radii_data = radii->data;
  d_theta = 6.2831853071795862 / (real_T)num_rays;
  st.site = &emlrtRSI;
  if ((1U <= num_rays) && (num_rays > 4294967294U)) {
    b_st.site = &d_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (int32_T)num_rays;
  emxInit_creal_T(sp, &a, 1, &r_emlrtRTEI);
  emxInit_creal_T(sp, &a_, 1, &s_emlrtRTEI);
  emxInit_creal_T(sp, &d, 1, &t_emlrtRTEI);
  emxInit_creal_T(sp, &coeffs, 1, &ab_emlrtRTEI);
  emxInit_boolean_T(sp, &b_r, &v_emlrtRTEI);
  emxInit_real_T(sp, &varargin_1, &x_emlrtRTEI);
  emxInit_real_T(sp, &b_d, &u_emlrtRTEI);
  for (n = 0; n < i; n++) {
    theta = d_theta * (real_T)num_rays;
    st.site = &b_emlrtRSI;
    b_a = Cosc / freq;
    /* given a ray from \xi, in direction theta, find r at which the ray */
    /* intersects the boundary of the blob |g(\xi)-g(\xi+r*exp(i*theta)|=C */
    /*  threshold for negligable imaginary part */
    /*  set the function g. I could just pass it, but not sure how MEX feels */
    /*  about that. */
    /*  pre-allocate stuff */
    last = g_coeffs->size[0];
    b_i = a->size[0];
    a->size[0] = g_coeffs->size[0];
    emxEnsureCapacity_creal_T(&st, a, b_i, &r_emlrtRTEI);
    a_data = a->data;
    b_i = a_->size[0];
    a_->size[0] = g_coeffs->size[0];
    emxEnsureCapacity_creal_T(&st, a_, b_i, &s_emlrtRTEI);
    a__data = a_->data;
    for (b_i = 0; b_i < last; b_i++) {
      a_data[b_i].re = 0.0;
      a_data[b_i].im = 0.0;
      a__data[b_i].re = 0.0;
      a__data[b_i].im = 0.0;
    }
    /*     %% follow the algorithm, as written in my notes (and soon, the paper)
     */
    /*  remember that the indexing of the polynomial coefficients is the */
    /*  opposite in my notes as in Matlab */
    if (1 > a->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, a->size[0], &e_emlrtBCI, &st);
    }
    dc = polyval(g_coeffs, xi);
    a_data[0].re = -dc.re;
    a_data[0].im = -dc.im;
    if (1 > a_->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, a_->size[0], &c_emlrtBCI, &st);
    }
    a__data[0].re = -dc.re;
    a__data[0].im = dc.im;
    last = g_coeffs->size[0];
    b_i = d->size[0];
    d->size[0] = g_coeffs->size[0];
    emxEnsureCapacity_creal_T(&st, d, b_i, &t_emlrtRTEI);
    d_data = d->data;
    for (b_i = 0; b_i < last; b_i++) {
      d_data[b_i] = g_coeffs_data[b_i];
    }
    b_st.site = &e_emlrtRSI;
    flip(d);
    d_data = d->data;
    b_i = g_coeffs->size[0];
    for (k = 0; k < b_i; k++) {
      last = g_coeffs->size[0] - k;
      for (idx = 0; idx < last; idx++) {
        j = (uint32_T)k + idx;
        if (((int32_T)((real_T)j + 1.0) < 1) ||
            ((int32_T)((real_T)j + 1.0) > d->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((real_T)j + 1.0), 1,
                                        d->size[0], &d_emlrtBCI, &st);
        }
        b_st.site = &f_emlrtRSI;
        b = nchoosek(&b_st, j, k);
        y_re_tmp = theta * 0.0;
        y_im = theta * (real_T)k;
        if (y_im == 0.0) {
          y_re = muDoubleScalarExp(y_re_tmp);
          y_im = 0.0;
        } else {
          r = muDoubleScalarExp(y_re_tmp / 2.0);
          y_re = r * (r * muDoubleScalarCos(y_im));
          y_im = r * (r * muDoubleScalarSin(y_im));
        }
        dc = mpower(xi, (real_T)j - (real_T)k);
        d_re_tmp = d_data[(int32_T)((real_T)j + 1.0) - 1].re;
        d_re = b * d_re_tmp;
        d_im_tmp = d_data[(int32_T)((real_T)j + 1.0) - 1].im;
        d_im = b * d_im_tmp;
        b = d_re * dc.re - d_im * dc.im;
        d_im = d_re * dc.im + d_im * dc.re;
        if (k + 1 > a->size[0]) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, a->size[0], &g_emlrtBCI, &st);
        }
        a_data[k].re += b * y_re - d_im * y_im;
        if (k + 1 > a->size[0]) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, a->size[0], &f_emlrtBCI, &st);
        }
        a_data[k].im += b * y_im + d_im * y_re;
        if (((int32_T)((real_T)j + 1.0) < 1) ||
            ((int32_T)((real_T)j + 1.0) > d->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((real_T)j + 1.0), 1,
                                        d->size[0], &b_emlrtBCI, &st);
        }
        b_st.site = &g_emlrtRSI;
        b = nchoosek(&b_st, j, k);
        y_im = theta * -(real_T)k;
        if (y_im == 0.0) {
          y_re = muDoubleScalarExp(y_re_tmp);
          y_im = 0.0;
        } else {
          r = muDoubleScalarExp(y_re_tmp / 2.0);
          y_re = r * (r * muDoubleScalarCos(y_im));
          y_im = r * (r * muDoubleScalarSin(y_im));
        }
        d_re = b * d_re_tmp;
        d_im = b * -d_im_tmp;
        b = d_re * dc.re - d_im * -dc.im;
        d_im = d_re * -dc.im + d_im * dc.re;
        if (k + 1 > a_->size[0]) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, a_->size[0], &i_emlrtBCI,
                                        &st);
        }
        a__data[k].re += b * y_re - d_im * y_im;
        if (k + 1 > a_->size[0]) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, a_->size[0], &h_emlrtBCI,
                                        &st);
        }
        a__data[k].im += b * y_im + d_im * y_re;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    /*  multiply the polynomials together, aka Cauchy product */
    b_st.site = &h_emlrtRSI;
    conv(&b_st, a, a_, coeffs);
    a_data = coeffs->data;
    if (1 > coeffs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, coeffs->size[0], &emlrtBCI, &st);
    }
    b_st.site = &i_emlrtRSI;
    c_st.site = &fb_emlrtRSI;
    d_st.site = &gb_emlrtRSI;
    a_data[0].re -= b_a * b_a;
    /*     %% filter out the roots we care about */
    b_st.site = &j_emlrtRSI;
    flip(coeffs);
    b_st.site = &j_emlrtRSI;
    roots(&b_st, coeffs, d);
    d_data = d->data;
    /*  remove the roots with significant imaginary bits */
    b_i = b_d->size[0];
    b_d->size[0] = d->size[0];
    emxEnsureCapacity_real_T(&st, b_d, b_i, &u_emlrtRTEI);
    b_d_data = b_d->data;
    last = d->size[0];
    for (b_i = 0; b_i < last; b_i++) {
      b_d_data[b_i] = d_data[b_i].im;
    }
    b_st.site = &k_emlrtRSI;
    b_abs(&b_st, b_d, varargin_1);
    b_d_data = varargin_1->data;
    b_i = b_r->size[0];
    b_r->size[0] = varargin_1->size[0];
    emxEnsureCapacity_boolean_T(&st, b_r, b_i, &v_emlrtRTEI);
    r1 = b_r->data;
    last = varargin_1->size[0];
    for (b_i = 0; b_i < last; b_i++) {
      r1[b_i] = (b_d_data[b_i] < 1.0E-8);
    }
    last = b_r->size[0] - 1;
    trueCount = 0;
    for (b_i = 0; b_i <= last; b_i++) {
      if (r1[b_i]) {
        trueCount++;
      }
    }
    idx = 0;
    for (b_i = 0; b_i <= last; b_i++) {
      if (r1[b_i]) {
        if (b_i + 1 > d->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, d->size[0], &j_emlrtBCI,
                                        &st);
        }
        d_data[idx].re = d_data[b_i].re;
        if (b_i + 1 > d->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, d->size[0], &j_emlrtBCI,
                                        &st);
        }
        d_data[idx].im = d_data[b_i].im;
        idx++;
      }
    }
    b_i = d->size[0];
    d->size[0] = trueCount;
    emxEnsureCapacity_creal_T(&st, d, b_i, &w_emlrtRTEI);
    d_data = d->data;
    /* remove the roots with negative real bits */
    last = trueCount - 1;
    trueCount = 0;
    for (b_i = 0; b_i <= last; b_i++) {
      if (d_data[b_i].re > 0.0) {
        trueCount++;
      }
    }
    idx = 0;
    for (b_i = 0; b_i <= last; b_i++) {
      if (d_data[b_i].re > 0.0) {
        if ((b_i + 1 < 1) || (b_i + 1 > d->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, d->size[0], &k_emlrtBCI,
                                        &st);
        }
        d_data[idx].re = d_data[b_i].re;
        if ((b_i + 1 < 1) || (b_i + 1 > d->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, d->size[0], &k_emlrtBCI,
                                        &st);
        }
        d_data[idx].im = d_data[b_i].im;
        idx++;
      }
    }
    b_i = d->size[0];
    d->size[0] = trueCount;
    emxEnsureCapacity_creal_T(&st, d, b_i, &w_emlrtRTEI);
    d_data = d->data;
    /* take the smallest value */
    b_st.site = &l_emlrtRSI;
    b_i = varargin_1->size[0];
    varargin_1->size[0] = trueCount;
    emxEnsureCapacity_real_T(&b_st, varargin_1, b_i, &x_emlrtRTEI);
    b_d_data = varargin_1->data;
    for (b_i = 0; b_i < trueCount; b_i++) {
      b_d_data[b_i] = d_data[b_i].re;
    }
    c_st.site = &tc_emlrtRSI;
    d_st.site = &uc_emlrtRSI;
    e_st.site = &vc_emlrtRSI;
    if (varargin_1->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }
    f_st.site = &wc_emlrtRSI;
    g_st.site = &xc_emlrtRSI;
    last = varargin_1->size[0];
    if (varargin_1->size[0] <= 2) {
      if (varargin_1->size[0] == 1) {
        if (((int32_T)(n + 1U) < 1) || ((int32_T)(n + 1U) > radii->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(n + 1U), 1, radii->size[0],
                                        &l_emlrtBCI, &g_st);
        }
        radii_data[n] = b_d_data[0];
      } else if ((b_d_data[0] > b_d_data[1]) ||
                 (muDoubleScalarIsNaN(b_d_data[0]) &&
                  (!muDoubleScalarIsNaN(b_d_data[1])))) {
        if (((int32_T)(n + 1U) < 1) || ((int32_T)(n + 1U) > radii->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(n + 1U), 1, radii->size[0],
                                        &l_emlrtBCI, &g_st);
        }
        radii_data[n] = b_d_data[1];
      } else {
        if (((int32_T)(n + 1U) < 1) || ((int32_T)(n + 1U) > radii->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(n + 1U), 1, radii->size[0],
                                        &l_emlrtBCI, &g_st);
        }
        radii_data[n] = b_d_data[0];
      }
    } else {
      h_st.site = &ad_emlrtRSI;
      if (!muDoubleScalarIsNaN(b_d_data[0])) {
        idx = 1;
      } else {
        idx = 0;
        i_st.site = &bd_emlrtRSI;
        if (varargin_1->size[0] > 2147483646) {
          j_st.site = &d_emlrtRSI;
          b_check_forloop_overflow_error(&j_st);
        }
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= last)) {
          if (!muDoubleScalarIsNaN(b_d_data[k - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (idx == 0) {
        if (((int32_T)(n + 1U) < 1) || ((int32_T)(n + 1U) > radii->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(n + 1U), 1, radii->size[0],
                                        &l_emlrtBCI, &g_st);
        }
        radii_data[n] = b_d_data[0];
      } else {
        h_st.site = &yc_emlrtRSI;
        b = b_d_data[idx - 1];
        trueCount = idx + 1;
        i_st.site = &cd_emlrtRSI;
        if ((idx + 1 <= varargin_1->size[0]) &&
            (varargin_1->size[0] > 2147483646)) {
          j_st.site = &d_emlrtRSI;
          b_check_forloop_overflow_error(&j_st);
        }
        for (k = trueCount; k <= last; k++) {
          d_im = b_d_data[k - 1];
          if (b > d_im) {
            b = d_im;
          }
        }
        if (((int32_T)(n + 1U) < 1) || ((int32_T)(n + 1U) > radii->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(n + 1U), 1, radii->size[0],
                                        &l_emlrtBCI, &g_st);
        }
        radii_data[n] = b;
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_real_T(sp, &b_d);
  emxFree_real_T(sp, &varargin_1);
  emxFree_boolean_T(sp, &b_r);
  emxFree_creal_T(sp, &coeffs);
  emxFree_creal_T(sp, &d);
  emxFree_creal_T(sp, &a_);
  emxFree_creal_T(sp, &a);
  st.site = &c_emlrtRSI;
  b_st.site = &dd_emlrtRSI;
  c_st.site = &ed_emlrtRSI;
  d_st.site = &fd_emlrtRSI;
  if (radii->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &gd_emlrtRSI;
  f_st.site = &hd_emlrtRSI;
  last = radii->size[0];
  if (radii->size[0] <= 2) {
    if (radii->size[0] == 1) {
      r = radii_data[0];
    } else if ((radii_data[0] < radii_data[1]) ||
               (muDoubleScalarIsNaN(radii_data[0]) &&
                (!muDoubleScalarIsNaN(radii_data[1])))) {
      r = radii_data[1];
    } else {
      r = radii_data[0];
    }
  } else {
    g_st.site = &ad_emlrtRSI;
    if (!muDoubleScalarIsNaN(radii_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &bd_emlrtRSI;
      if (radii->size[0] > 2147483646) {
        i_st.site = &d_emlrtRSI;
        b_check_forloop_overflow_error(&i_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!muDoubleScalarIsNaN(radii_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      r = radii_data[0];
    } else {
      g_st.site = &yc_emlrtRSI;
      r = radii_data[idx - 1];
      trueCount = idx + 1;
      h_st.site = &cd_emlrtRSI;
      if ((idx + 1 <= radii->size[0]) && (radii->size[0] > 2147483646)) {
        i_st.site = &d_emlrtRSI;
        b_check_forloop_overflow_error(&i_st);
      }
      for (k = trueCount; k <= last; k++) {
        d_im = radii_data[k - 1];
        if (r < d_im) {
          r = d_im;
        }
      }
    }
  }
  emxFree_real_T(&f_st, &radii);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return r;
}

/* End of code generation (get_smallest_supset_ball.c) */
