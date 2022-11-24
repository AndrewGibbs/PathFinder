/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_interior_ball.c
 *
 * Code generation for function 'get_interior_ball'
 *
 */

/* Include files */
#include "get_interior_ball.h"
#include "diff_coeffs.h"
#include "eml_int_forloop_overflow_check.h"
#include "get_interior_ball_data.h"
#include "get_interior_ball_emxutil.h"
#include "get_interior_ball_types.h"
#include "polyval.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    13,                  /* lineNo */
    "get_interior_ball", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/covers/get_interior_ball.m" /* pathName
                                                                         */
};

static emlrtRSInfo b_emlrtRSI = {
    14,                  /* lineNo */
    "get_interior_ball", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/covers/get_interior_ball.m" /* pathName
                                                                         */
};

static emlrtRSInfo c_emlrtRSI = {
    28,                  /* lineNo */
    "get_interior_ball", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/covers/get_interior_ball.m" /* pathName
                                                                         */
};

static emlrtRSInfo
    d_emlrtRSI =
        {
            6,                 /* lineNo */
            "get_derivs_at_x", /* fcnName */
            "/home/andrew/Dropbox/PathFinderInf/src/TaylorApprox/"
            "get_derivs_at_x.m" /* pathName */
};

static emlrtRSInfo
    e_emlrtRSI =
        {
            7,                 /* lineNo */
            "get_derivs_at_x", /* fcnName */
            "/home/andrew/Dropbox/PathFinderInf/src/TaylorApprox/"
            "get_derivs_at_x.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    21,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    44,                                                          /* lineNo */
    "mpower",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/mpower.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    45,                                                         /* lineNo */
    "bisection",                                                /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/covers/bisection.m" /* pathName */
};

static emlrtMCInfo emlrtMCI = {
    27,                                                       /* lineNo */
    5,                                                        /* colNo */
    "error",                                                  /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/lang/error.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                                                          /* iFirst */
    -1,                                                          /* iLast */
    3,                                                           /* lineNo */
    18,                                                          /* colNo */
    "dG_",                                                       /* aName */
    "diff_coeffs",                                               /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/util/diff_coeffs.m", /* pName */
    0                                                            /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                                                          /* iFirst */
    -1,                                                          /* iLast */
    3,                                                           /* lineNo */
    15,                                                          /* colNo */
    "dG_",                                                       /* aName */
    "diff_coeffs",                                               /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/util/diff_coeffs.m", /* pName */
    0                                                            /* checkKind */
};

static emlrtECInfo emlrtECI = {
    2,                                                          /* nDims */
    2,                                                          /* lineNo */
    11,                                                         /* colNo */
    "diff_coeffs",                                              /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/util/diff_coeffs.m" /* pName */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    14,                  /* lineNo */
    71,                  /* colNo */
    "dG_SP",             /* aName */
    "get_interior_ball", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/covers/get_interior_ball.m", /* pName
                                                                          */
    0 /* checkKind */
};

static emlrtDCInfo
    emlrtDCI =
        {
            3,                 /* lineNo */
            5,                 /* colNo */
            "get_derivs_at_x", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/TaylorApprox/"
            "get_derivs_at_x.m", /* pName */
            1                    /* checkKind */
};

static emlrtBCInfo
    d_emlrtBCI =
        {
            -1,                /* iFirst */
            -1,                /* iLast */
            8,                 /* lineNo */
            14,                /* colNo */
            "dG_x",            /* aName */
            "get_derivs_at_x", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/TaylorApprox/"
            "get_derivs_at_x.m", /* pName */
            0                    /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    13,                  /* lineNo */
    34,                  /* colNo */
    "get_interior_ball", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/covers/get_interior_ball.m" /* pName
                                                                         */
};

static emlrtRTEInfo
    c_emlrtRTEI =
        {
            3,                 /* lineNo */
            5,                 /* colNo */
            "get_derivs_at_x", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/TaylorApprox/"
            "get_derivs_at_x.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    2,                                                          /* lineNo */
    16,                                                         /* colNo */
    "diff_coeffs",                                              /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/util/diff_coeffs.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    3,                                                          /* lineNo */
    5,                                                          /* colNo */
    "diff_coeffs",                                              /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/util/diff_coeffs.m" /* pName */
};

static emlrtRTEInfo
    g_emlrtRTEI =
        {
            7,                 /* lineNo */
            9,                 /* colNo */
            "get_derivs_at_x", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/TaylorApprox/"
            "get_derivs_at_x.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    1,                   /* lineNo */
    19,                  /* colNo */
    "get_interior_ball", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/covers/get_interior_ball.m" /* pName
                                                                         */
};

static emlrtRTEInfo
    i_emlrtRTEI =
        {
            5,                 /* lineNo */
            5,                 /* colNo */
            "get_derivs_at_x", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/TaylorApprox/"
            "get_derivs_at_x.m" /* pName */
};

static emlrtRTEInfo
    j_emlrtRTEI =
        {
            7,                 /* lineNo */
            23,                /* colNo */
            "get_derivs_at_x", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/TaylorApprox/"
            "get_derivs_at_x.m" /* pName */
};

static emlrtRSInfo j_emlrtRSI = {
    27,                                                       /* lineNo */
    "error",                                                  /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/lang/error.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    2,                                                          /* lineNo */
    "diff_coeffs",                                              /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/util/diff_coeffs.m" /* pathName */
};

/* Function Declarations */
static void b_error(const emlrtStack *sp, const mxArray *m,
                    emlrtMCInfo *location);

/* Function Definitions */
static void b_error(const emlrtStack *sp, const mxArray *m,
                    emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = m;
  emlrtCallMATLABR2012b((emlrtCTX)sp, 0, NULL, 1, &pArray,
                        (const char_T *)"error", true, location);
}

real_T get_interior_ball(const emlrtStack *sp, const emxArray_creal_T *g_coeffs,
                         real_T freq, const creal_T SP, uint32_T order,
                         real_T C)
{
  static const int32_T iv[2] = {1, 16};
  static const uint32_T uv[12] = {1U,      2U,       6U,        24U,
                                  120U,    720U,     5040U,     40320U,
                                  362880U, 3628800U, 39916800U, 479001600U};
  static const char_T varargin_1[16] = {'f', 'a', 'i', 'l', 'e', 'd', ' ', 't',
                                        'o', ' ', 'b', 'i', 's', 'e', 'c', 't'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_creal_T *dG_;
  emxArray_creal_T *dG_SP;
  emxArray_creal_T *d_coeffs;
  emxArray_real_T *r;
  const mxArray *m;
  const mxArray *y;
  const creal_T *g_coeffs_data;
  creal_T b_SP;
  creal_T dc;
  creal_T dc1;
  creal_T *dG_SP_data;
  creal_T *dG__data;
  creal_T *d_coeffs_data;
  real_T ray_intervals[32];
  real_T ray_mins[16];
  real_T SP_re;
  real_T SP_tmp;
  real_T b_SP_tmp;
  real_T c;
  real_T c_SP_tmp;
  real_T c_err;
  real_T count;
  real_T d_SP_tmp;
  real_T e_SP_tmp;
  real_T guess_radius;
  real_T radius;
  real_T theta;
  real_T thresh;
  real_T *r1;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T n;
  uint32_T b_n;
  uint32_T qY;
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T no_sign_change;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  g_coeffs_data = g_coeffs->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /* MEX-able code to efficiently determine interior ball of the */
  /* \omega|g(z)-g(\xi)|=C$ contours */
  thresh = 0.05 / freq;
  /* F = @(r,theta) freq*abs(G{1}(r*exp(1i*theta))-G{1}(SP)) - C; */
  qY = order + 1U;
  if (order + 1U < order) {
    qY = MAX_uint32_T;
  }
  emxInit_creal_T(sp, &d_coeffs, 2, &i_emlrtRTEI);
  /*  Initial guess: */
  st.site = &emlrtRSI;
  i = d_coeffs->size[0] * d_coeffs->size[1];
  d_coeffs->size[0] = 1;
  d_coeffs->size[1] = g_coeffs->size[0];
  emxEnsureCapacity_creal_T(&st, d_coeffs, i, &b_emlrtRTEI);
  d_coeffs_data = d_coeffs->data;
  b_i = g_coeffs->size[0];
  for (i = 0; i < b_i; i++) {
    d_coeffs_data[i] = g_coeffs_data[i];
  }
  emxInit_creal_T(&st, &dG_SP, 1, &h_emlrtRTEI);
  /*  copied out of AsHu for now */
  if ((real_T)qY != (int32_T)qY) {
    emlrtIntegerCheckR2012b(qY, &emlrtDCI, &st);
  }
  i = dG_SP->size[0];
  dG_SP->size[0] = (int32_T)qY;
  emxEnsureCapacity_creal_T(&st, dG_SP, i, &c_emlrtRTEI);
  dG_SP_data = dG_SP->data;
  if ((real_T)qY != (int32_T)qY) {
    emlrtIntegerCheckR2012b(qY, &emlrtDCI, &st);
  }
  b_i = (int32_T)qY;
  for (i = 0; i < b_i; i++) {
    dG_SP_data[i].re = 0.0;
    dG_SP_data[i].im = 0.0;
  }
  b_st.site = &d_emlrtRSI;
  if (qY > 4294967294U) {
    c_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  i = (int32_T)qY;
  emxInit_creal_T(&st, &dG_, 2, &j_emlrtRTEI);
  emxInit_real_T(&st, &r, &h_emlrtRTEI);
  r1 = r->data;
  for (n = 0; n < i; n++) {
    b_st.site = &e_emlrtRSI;
    if (d_coeffs->size[1] - 1 < 0) {
      r->size[0] = 1;
      r->size[1] = 0;
    } else {
      i1 = r->size[0] * r->size[1];
      r->size[0] = 1;
      r->size[1] = (int32_T) - (0.0 - ((real_T)d_coeffs->size[1] - 1.0)) + 1;
      emxEnsureCapacity_real_T(&b_st, r, i1, &d_emlrtRTEI);
      r1 = r->data;
      b_i = (int32_T) - (0.0 - ((real_T)d_coeffs->size[1] - 1.0));
      for (i1 = 0; i1 <= b_i; i1++) {
        r1[i1] = ((real_T)d_coeffs->size[1] - 1.0) - (real_T)i1;
      }
    }
    if ((d_coeffs->size[1] != r->size[1]) &&
        ((d_coeffs->size[1] != 1) && (r->size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(d_coeffs->size[1], r->size[1], &emlrtECI,
                                  &b_st);
    }
    if (d_coeffs->size[1] == r->size[1]) {
      i1 = dG_->size[0] * dG_->size[1];
      dG_->size[0] = 1;
      dG_->size[1] = d_coeffs->size[1];
      emxEnsureCapacity_creal_T(&b_st, dG_, i1, &e_emlrtRTEI);
      dG__data = dG_->data;
      b_i = d_coeffs->size[1];
      for (i1 = 0; i1 < b_i; i1++) {
        dG__data[i1].re = r1[i1] * d_coeffs_data[i1].re;
        dG__data[i1].im = r1[i1] * d_coeffs_data[i1].im;
      }
    } else {
      c_st.site = &k_emlrtRSI;
      times(&c_st, dG_, d_coeffs, r);
    }
    if (1 > dG_->size[1] - 1) {
      b_i = 0;
    } else {
      if (1 > dG_->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, dG_->size[1], &b_emlrtBCI, &b_st);
      }
      if ((dG_->size[1] - 1 < 1) || (dG_->size[1] - 1 > dG_->size[1])) {
        emlrtDynamicBoundsCheckR2012b(dG_->size[1] - 1, 1, dG_->size[1],
                                      &emlrtBCI, &b_st);
      }
      b_i = dG_->size[1] - 1;
    }
    i1 = dG_->size[0] * dG_->size[1];
    dG_->size[1] = b_i;
    emxEnsureCapacity_creal_T(&b_st, dG_, i1, &f_emlrtRTEI);
    dG__data = dG_->data;
    i1 = d_coeffs->size[0] * d_coeffs->size[1];
    d_coeffs->size[0] = 1;
    d_coeffs->size[1] = b_i + 1;
    emxEnsureCapacity_creal_T(&st, d_coeffs, i1, &g_emlrtRTEI);
    d_coeffs_data = d_coeffs->data;
    d_coeffs_data[0].re = 0.0;
    d_coeffs_data[0].im = 0.0;
    for (i1 = 0; i1 < b_i; i1++) {
      d_coeffs_data[i1 + 1] = dG__data[i1];
    }
    count = d_coeffs_data[0].re;
    theta = d_coeffs_data[0].im;
    i1 = d_coeffs->size[1];
    for (k = 0; k <= i1 - 2; k++) {
      SP_re = SP.re * count - SP.im * theta;
      theta = SP.re * theta + SP.im * count;
      count = SP_re + d_coeffs_data[k + 1].re;
      theta += d_coeffs_data[k + 1].im;
    }
    if (((int32_T)(n + 1U) < 1) || ((int32_T)(n + 1U) > dG_SP->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(n + 1U), 1, dG_SP->size[0],
                                    &d_emlrtBCI, &st);
    }
    dG_SP_data[n].re = count;
    if (((int32_T)(n + 1U) < 1) || ((int32_T)(n + 1U) > dG_SP->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(n + 1U), 1, dG_SP->size[0],
                                    &d_emlrtBCI, &st);
    }
    dG_SP_data[n].im = theta;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  emxFree_real_T(&st, &r);
  emxFree_creal_T(&st, &dG_);
  emxFree_creal_T(&st, &d_coeffs);
  if (qY > 12U) {
    b_n = MAX_uint32_T;
  } else {
    b_n = uv[(int32_T)qY - 1];
  }
  if (((int32_T)qY < 1) || ((int32_T)qY > dG_SP->size[0])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)qY, 1, dG_SP->size[0], &c_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  st.site = &b_emlrtRSI;
  b_st.site = &g_emlrtRSI;
  /*      guess_radius =
   * double(abs(double(factorial(nu))*C/(freq*abs(G{nu}(SP))))^(1/double(nu)));
   */
  /* make sure this isn't too ridiculous */
  guess_radius = muDoubleScalarMin(
      muDoubleScalarPower(
          muDoubleScalarAbs(
              (real_T)b_n * C /
              (freq * muDoubleScalarHypot(dG_SP_data[(int32_T)qY - 1].re,
                                          dG_SP_data[(int32_T)qY - 1].im))),
          1.0 / (real_T)qY),
      10.0 / freq);
  /*  solve problem on each ray */
  emxFree_creal_T(sp, &dG_SP);
  for (b_i = 0; b_i < 16; b_i++) {
    ray_mins[b_i] = rtInf;
    ray_intervals[b_i] = 0.0;
    ray_intervals[b_i + 16] = guess_radius;
  }
  no_sign_change = true;
  while (no_sign_change) {
    for (n = 0; n < 16; n++) {
      theta = 6.2831853071795862 * ((real_T)n + 1.0) / 16.0;
      SP_tmp = ray_intervals[n];
      b_SP_tmp = muDoubleScalarCos(theta);
      c_SP_tmp = SP.re + SP_tmp * b_SP_tmp;
      b_SP.re = c_SP_tmp;
      d_SP_tmp = muDoubleScalarSin(theta);
      SP_re = SP.im + SP_tmp * d_SP_tmp;
      b_SP.im = SP_re;
      dc = polyval(g_coeffs, b_SP);
      dc1 = polyval(g_coeffs, SP);
      e_SP_tmp = ray_intervals[n + 16];
      theta = SP.re + e_SP_tmp * b_SP_tmp;
      b_SP.re = theta;
      count = SP.im + e_SP_tmp * d_SP_tmp;
      b_SP.im = count;
      b_SP = polyval(g_coeffs, b_SP);
      if (muDoubleScalarSign(
              freq * muDoubleScalarHypot(dc.re - dc1.re, dc.im - dc1.im) - C) !=
          muDoubleScalarSign(
              freq * muDoubleScalarHypot(b_SP.re - dc1.re, b_SP.im - dc1.im) -
              C)) {
        no_sign_change = false;
        st.site = &c_emlrtRSI;
        /*  L = abs(b-a); */
        /*  rayDir = (b-a)/L; */
        /*  ray = @(s) a + s*(b-a); */
        c = rtNaN;
        /* inside contour f is negative, outside contour f is positive */
        /*  err = @(a,b) min(abs(f(a)),abs(f(b))); */
        c_err = muDoubleScalarAbs(e_SP_tmp - SP_tmp);
        if (c_err <= thresh) {
          /*  take midpoint if no bisection is required */
          c = (e_SP_tmp + SP_tmp) / 2.0;
        } else {
          b_SP.re = c_SP_tmp;
          b_SP.im = SP_re;
          dc = polyval(g_coeffs, b_SP);
          SP_re =
              freq * muDoubleScalarHypot(dc.re - dc1.re, dc.im - dc1.im) - C;
          if (SP_re == 0.0) {
            c = SP_tmp;
          } else {
            b_SP.re = theta;
            b_SP.im = count;
            dc = polyval(g_coeffs, b_SP);
            if (freq * muDoubleScalarHypot(dc.re - dc1.re, dc.im - dc1.im) -
                    C ==
                0.0) {
              c = e_SP_tmp;
            } else {
              if (SP_re > 0.0) {
                /* f = @(x) -f(x); */
                b_i = -1;
              } else {
                b_i = 1;
              }
              count = 0.0;
              exitg1 = false;
              while ((!exitg1) && (c_err > thresh)) {
                c = SP_tmp + (e_SP_tmp - SP_tmp) / 2.0;
                c_SP_tmp = SP.re + c * b_SP_tmp;
                b_SP.re = c_SP_tmp;
                SP_re = SP.im + c * d_SP_tmp;
                b_SP.im = SP_re;
                dc = polyval(g_coeffs, b_SP);
                guard1 = false;
                if ((real_T)b_i * (freq * muDoubleScalarHypot(dc.re - dc1.re,
                                                              dc.im - dc1.im) -
                                   C) >
                    0.0) {
                  e_SP_tmp = c;
                  guard1 = true;
                } else {
                  b_SP.re = c_SP_tmp;
                  b_SP.im = SP_re;
                  dc = polyval(g_coeffs, b_SP);
                  if ((real_T)b_i *
                          (freq * muDoubleScalarHypot(dc.re - dc1.re,
                                                      dc.im - dc1.im) -
                           C) <
                      0.0) {
                    SP_tmp = c;
                    guard1 = true;
                  } else {
                    exitg1 = true;
                  }
                }
                if (guard1) {
                  c_err = muDoubleScalarAbs(e_SP_tmp - SP_tmp);
                  count++;
                  if (count > 1000.0) {
                    b_st.site = &i_emlrtRSI;
                    y = NULL;
                    m = emlrtCreateCharArray(2, &iv[0]);
                    emlrtInitCharArrayR2013a(&b_st, 16, m, &varargin_1[0]);
                    emlrtAssign(&y, m);
                    c_st.site = &j_emlrtRSI;
                    b_error(&c_st, y, &emlrtMCI);
                  }
                  if (*emlrtBreakCheckR2012bFlagVar != 0) {
                    emlrtBreakCheckR2012b(&st);
                  }
                }
              }
            }
          }
        }
        ray_mins[n] = c;
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    if (no_sign_change) {
      /* increase the range */
      for (i = 0; i < 32; i++) {
        ray_intervals[i] += guess_radius;
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  if (!muDoubleScalarIsNaN(ray_mins[0])) {
    b_i = 1;
  } else {
    b_i = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 17)) {
      if (!muDoubleScalarIsNaN(ray_mins[k - 1])) {
        b_i = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (b_i == 0) {
    radius = ray_mins[0];
  } else {
    radius = ray_mins[b_i - 1];
    i = b_i + 1;
    for (k = i; k < 17; k++) {
      SP_re = ray_mins[k - 1];
      if (radius > SP_re) {
        radius = SP_re;
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return radius;
}

/* End of code generation (get_interior_ball.c) */
