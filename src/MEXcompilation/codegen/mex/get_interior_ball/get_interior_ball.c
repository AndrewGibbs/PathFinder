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
#include "eml_int_forloop_overflow_check.h"
#include "get_interior_ball_data.h"
#include "get_interior_ball_emxutil.h"
#include "get_interior_ball_types.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    12,                  /* lineNo */
    "get_interior_ball", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/covers/get_interior_ball.m" /* pathName
                                                                         */
};

static emlrtRSInfo b_emlrtRSI = {
    13,                  /* lineNo */
    "get_interior_ball", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/covers/get_interior_ball.m" /* pathName
                                                                         */
};

static emlrtRSInfo c_emlrtRSI = {
    25,                  /* lineNo */
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
    3,                                                          /* lineNo */
    "diff_coeffs",                                              /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/util/diff_coeffs.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    44,                                                          /* lineNo */
    "mpower",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/mpower.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    40,                                                         /* lineNo */
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

static emlrtBCInfo c_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    13,                  /* lineNo */
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
    105,                                                     /* lineNo */
    9,                                                       /* colNo */
    "colon",                                                 /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/ops/colon.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    2,                                                          /* lineNo */
    5,                                                          /* colNo */
    "diff_coeffs",                                              /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/util/diff_coeffs.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    1,                   /* lineNo */
    19,                  /* colNo */
    "get_interior_ball", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/covers/get_interior_ball.m" /* pName
                                                                         */
};

static emlrtRTEInfo g_emlrtRTEI = {
    1,                                                          /* lineNo */
    10,                                                         /* colNo */
    "diff_coeffs",                                              /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/util/diff_coeffs.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    2,                                                          /* lineNo */
    16,                                                         /* colNo */
    "diff_coeffs",                                              /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/util/diff_coeffs.m" /* pName */
};

static emlrtRSInfo l_emlrtRSI = {
    27,                                                       /* lineNo */
    "error",                                                  /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/lang/error.m" /* pathName */
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
  emxArray_real_T *y;
  const mxArray *b_y;
  const mxArray *m;
  const creal_T *g_coeffs_data;
  creal_T *dG_SP_data;
  creal_T *dG__data;
  real_T ray_intervals[32];
  real_T ray_mins[16];
  real_T SP_re;
  real_T a;
  real_T b;
  real_T b_y_im;
  real_T b_y_re;
  real_T c;
  real_T c_err;
  real_T count;
  real_T guess_radius;
  real_T radius;
  real_T thresh;
  real_T y_im;
  real_T y_re;
  real_T *y_data;
  int32_T b_g_coeffs[2];
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T loop_ub;
  int32_T n;
  uint32_T b_n;
  uint32_T qY;
  uint16_T x;
  uint16_T x_tmp;
  uint16_T z;
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
  qY = order + 1U;
  if (order + 1U < order) {
    qY = MAX_uint32_T;
  }
  emxInit_creal_T(sp, &dG_SP, 1, &f_emlrtRTEI);
  /*  Initial guess: */
  st.site = &emlrtRSI;
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
  emxInit_real_T(&st, &y, &h_emlrtRTEI);
  y_data = y->data;
  if (0 <= (int32_T)qY - 1) {
    if (g_coeffs->size[0] - 1 < 0) {
      y->size[0] = 1;
      y->size[1] = 0;
    } else {
      i1 = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = (int32_T) - (0.0 - ((real_T)g_coeffs->size[0] - 1.0)) + 1;
      emxEnsureCapacity_real_T(&st, y, i1, &d_emlrtRTEI);
      y_data = y->data;
      b_i = (int32_T) - (0.0 - ((real_T)g_coeffs->size[0] - 1.0));
      for (i1 = 0; i1 <= b_i; i1++) {
        y_data[i1] = ((real_T)g_coeffs->size[0] - 1.0) - (real_T)i1;
      }
    }
    loop_ub = y->size[1];
  }
  emxInit_creal_T(&st, &dG_, 2, &g_emlrtRTEI);
  for (n = 0; n < i; n++) {
    b_st.site = &e_emlrtRSI;
    i1 = dG_->size[0] * dG_->size[1];
    dG_->size[0] = g_coeffs->size[0];
    dG_->size[1] = y->size[1];
    emxEnsureCapacity_creal_T(&b_st, dG_, i1, &e_emlrtRTEI);
    dG__data = dG_->data;
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_i = g_coeffs->size[0];
      for (k = 0; k < b_i; k++) {
        dG__data[k + dG_->size[0] * i1].re = y_data[i1] * g_coeffs_data[k].re;
        dG__data[k + dG_->size[0] * i1].im = y_data[i1] * g_coeffs_data[k].im;
      }
    }
    count = (real_T)(dG_->size[0] * dG_->size[1]) - 1.0;
    if (1.0 > count) {
      k = 0;
    } else {
      i1 = dG_->size[0] * dG_->size[1];
      if (1 > i1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i1, &b_emlrtBCI, &b_st);
      }
      k = (int32_T)count;
      if (k > i1) {
        emlrtDynamicBoundsCheckR2012b((int32_T)count, 1, i1, &emlrtBCI, &b_st);
      }
    }
    b_g_coeffs[0] = 1;
    b_g_coeffs[1] = k;
    c_st.site = &g_emlrtRSI;
    indexShapeCheck(&c_st, *(int32_T(*)[2])dG_->size, b_g_coeffs);
    if (k != 0) {
      y_re = dG__data[0].re;
      y_im = dG__data[0].im;
      i1 = k - 2;
      for (k = 0; k <= i1; k++) {
        SP_re = SP.re * y_re - SP.im * y_im;
        c_err = SP.re * y_im + SP.im * y_re;
        y_re = SP_re + dG__data[k + 1].re;
        y_im = c_err + dG__data[k + 1].im;
      }
    }
    if (((int32_T)(n + 1U) < 1) || ((int32_T)(n + 1U) > dG_SP->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(n + 1U), 1, dG_SP->size[0],
                                    &d_emlrtBCI, &st);
    }
    dG_SP_data[n].re = y_re;
    if (((int32_T)(n + 1U) < 1) || ((int32_T)(n + 1U) > dG_SP->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(n + 1U), 1, dG_SP->size[0],
                                    &d_emlrtBCI, &st);
    }
    dG_SP_data[n].im = y_im;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  emxFree_real_T(&st, &y);
  emxFree_creal_T(&st, &dG_);
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
  b_st.site = &i_emlrtRSI;
  /* make sure this isn't too ridiculous */
  guess_radius = muDoubleScalarMin(
      muDoubleScalarPower(
          muDoubleScalarAbs(
              (real_T)b_n * C /
              (freq * muDoubleScalarHypot(dG_SP_data[(int32_T)qY - 1].re,
                                          dG_SP_data[(int32_T)qY - 1].im))),
          1.0 / (real_T)qY),
      2.0 / freq);
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
      a = ray_intervals[n];
      b = ray_intervals[n + 16];
      if (muDoubleScalarSign(a) != muDoubleScalarSign(b)) {
        no_sign_change = false;
        st.site = &c_emlrtRSI;
        /*  L = abs(b-a); */
        /*  rayDir = (b-a)/L; */
        /*  ray = @(s) a + s*(b-a); */
        c = rtNaN;
        /* inside contour f is negative, outside contour f is positive */
        /*  err = @(a,b) min(abs(f(a)),abs(f(b))); */
        x_tmp = (uint16_T)muDoubleScalarRound(6.2831853071795862 *
                                              ((real_T)n + 1.0));
        z = (uint16_T)((uint32_T)x_tmp >> 4);
        x = (uint16_T)((uint32_T)x_tmp - (z << 4));
        if ((x > 0) && (x >= 8)) {
          z++;
        }
        if (z == 0) {
          y_re = 1.0;
          y_im = 0.0;
        } else {
          y_re = muDoubleScalarCos(z);
          y_im = muDoubleScalarSin(z);
        }
        y_re *= a;
        y_im *= a;
        if (g_coeffs->size[0] != 0) {
          b_y_re = g_coeffs_data[0].re;
          b_y_im = g_coeffs_data[0].im;
          i = g_coeffs->size[0];
          for (k = 0; k <= i - 2; k++) {
            c_err = y_re * b_y_re - y_im * b_y_im;
            b_y_im = y_re * b_y_im + y_im * b_y_re;
            b_y_re = c_err + g_coeffs_data[k + 1].re;
            b_y_im += g_coeffs_data[k + 1].im;
          }
        }
        if (g_coeffs->size[0] != 0) {
          y_re = g_coeffs_data[0].re;
          y_im = g_coeffs_data[0].im;
          i = g_coeffs->size[0];
          for (k = 0; k <= i - 2; k++) {
            SP_re = SP.re * y_re - SP.im * y_im;
            c_err = SP.re * y_im + SP.im * y_re;
            y_re = SP_re + g_coeffs_data[k + 1].re;
            y_im = c_err + g_coeffs_data[k + 1].im;
          }
        }
        y_re = b_y_re - y_re;
        y_im = b_y_im - y_im;
        count = freq * muDoubleScalarHypot(y_re, y_im) - C;
        if (count == 0.0) {
          c = a;
        } else {
          z = (uint16_T)((uint32_T)x_tmp >> 4);
          x = (uint16_T)((uint32_T)x_tmp - (z << 4));
          if ((x > 0) && (x >= 8)) {
            z++;
          }
          if (z == 0) {
            y_re = 1.0;
            y_im = 0.0;
          } else {
            y_re = muDoubleScalarCos(z);
            y_im = muDoubleScalarSin(z);
          }
          y_re *= b;
          y_im *= b;
          if (g_coeffs->size[0] != 0) {
            b_y_re = g_coeffs_data[0].re;
            b_y_im = g_coeffs_data[0].im;
            i = g_coeffs->size[0];
            for (k = 0; k <= i - 2; k++) {
              c_err = y_re * b_y_re - y_im * b_y_im;
              b_y_im = y_re * b_y_im + y_im * b_y_re;
              b_y_re = c_err + g_coeffs_data[k + 1].re;
              b_y_im += g_coeffs_data[k + 1].im;
            }
          }
          if (g_coeffs->size[0] != 0) {
            y_re = g_coeffs_data[0].re;
            y_im = g_coeffs_data[0].im;
            i = g_coeffs->size[0];
            for (k = 0; k <= i - 2; k++) {
              SP_re = SP.re * y_re - SP.im * y_im;
              c_err = SP.re * y_im + SP.im * y_re;
              y_re = SP_re + g_coeffs_data[k + 1].re;
              y_im = c_err + g_coeffs_data[k + 1].im;
            }
          }
          y_re = b_y_re - y_re;
          y_im = b_y_im - y_im;
          if (freq * muDoubleScalarHypot(y_re, y_im) - C == 0.0) {
            c = b;
          } else {
            if (count > 0.0) {
              /* f = @(x) -f(x); */
              b_i = -1;
            } else {
              b_i = 1;
            }
            c_err = rtInf;
            count = 0.0;
            exitg1 = false;
            while ((!exitg1) && (c_err > thresh)) {
              c = a + (b - a) / 2.0;
              z = (uint16_T)((uint32_T)x_tmp >> 4);
              x = (uint16_T)((uint32_T)x_tmp - (z << 4));
              if ((x > 0) && (x >= 8)) {
                z++;
              }
              if (z == 0) {
                y_re = 1.0;
                y_im = 0.0;
              } else {
                y_re = muDoubleScalarCos(z);
                y_im = muDoubleScalarSin(z);
              }
              y_re *= c;
              y_im *= c;
              if (g_coeffs->size[0] != 0) {
                b_y_re = g_coeffs_data[0].re;
                b_y_im = g_coeffs_data[0].im;
                i = g_coeffs->size[0];
                for (k = 0; k <= i - 2; k++) {
                  c_err = y_re * b_y_re - y_im * b_y_im;
                  b_y_im = y_re * b_y_im + y_im * b_y_re;
                  b_y_re = c_err + g_coeffs_data[k + 1].re;
                  b_y_im += g_coeffs_data[k + 1].im;
                }
              }
              if (g_coeffs->size[0] != 0) {
                y_re = g_coeffs_data[0].re;
                y_im = g_coeffs_data[0].im;
                i = g_coeffs->size[0];
                for (k = 0; k <= i - 2; k++) {
                  SP_re = SP.re * y_re - SP.im * y_im;
                  c_err = SP.re * y_im + SP.im * y_re;
                  y_re = SP_re + g_coeffs_data[k + 1].re;
                  y_im = c_err + g_coeffs_data[k + 1].im;
                }
              }
              y_re = b_y_re - y_re;
              y_im = b_y_im - y_im;
              guard1 = false;
              if ((real_T)b_i * (freq * muDoubleScalarHypot(y_re, y_im) - C) >
                  0.0) {
                b = c;
                guard1 = true;
              } else {
                z = (uint16_T)((uint32_T)x_tmp >> 4);
                x = (uint16_T)((uint32_T)x_tmp - (z << 4));
                if ((x > 0) && (x >= 8)) {
                  z++;
                }
                if (z == 0) {
                  y_re = 1.0;
                  y_im = 0.0;
                } else {
                  y_re = muDoubleScalarCos(z);
                  y_im = muDoubleScalarSin(z);
                }
                y_re *= c;
                y_im *= c;
                if (g_coeffs->size[0] != 0) {
                  b_y_re = g_coeffs_data[0].re;
                  b_y_im = g_coeffs_data[0].im;
                  i = g_coeffs->size[0];
                  for (k = 0; k <= i - 2; k++) {
                    c_err = y_re * b_y_re - y_im * b_y_im;
                    b_y_im = y_re * b_y_im + y_im * b_y_re;
                    b_y_re = c_err + g_coeffs_data[k + 1].re;
                    b_y_im += g_coeffs_data[k + 1].im;
                  }
                }
                if (g_coeffs->size[0] != 0) {
                  y_re = g_coeffs_data[0].re;
                  y_im = g_coeffs_data[0].im;
                  i = g_coeffs->size[0];
                  for (k = 0; k <= i - 2; k++) {
                    SP_re = SP.re * y_re - SP.im * y_im;
                    c_err = SP.re * y_im + SP.im * y_re;
                    y_re = SP_re + g_coeffs_data[k + 1].re;
                    y_im = c_err + g_coeffs_data[k + 1].im;
                  }
                }
                y_re = b_y_re - y_re;
                y_im = b_y_im - y_im;
                if ((real_T)b_i * (freq * muDoubleScalarHypot(y_re, y_im) - C) <
                    0.0) {
                  a = c;
                  guard1 = true;
                } else {
                  exitg1 = true;
                }
              }
              if (guard1) {
                c_err = muDoubleScalarAbs(b - a);
                count++;
                if (count > 1000.0) {
                  b_st.site = &k_emlrtRSI;
                  b_y = NULL;
                  m = emlrtCreateCharArray(2, &iv[0]);
                  emlrtInitCharArrayR2013a(&b_st, 16, m, &varargin_1[0]);
                  emlrtAssign(&b_y, m);
                  c_st.site = &l_emlrtRSI;
                  b_error(&c_st, b_y, &emlrtMCI);
                }
                if (*emlrtBreakCheckR2012bFlagVar != 0) {
                  emlrtBreakCheckR2012b(&st);
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
      count = ray_mins[k - 1];
      if (radius > count) {
        radius = count;
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return radius;
}

/* End of code generation (get_interior_ball.c) */
