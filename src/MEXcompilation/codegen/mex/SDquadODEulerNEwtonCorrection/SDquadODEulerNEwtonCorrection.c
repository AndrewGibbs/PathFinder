/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDquadODEulerNEwtonCorrection.c
 *
 * Code generation for function 'SDquadODEulerNEwtonCorrection'
 *
 */

/* Include files */
#include "SDquadODEulerNEwtonCorrection.h"
#include "SDquadODEulerNEwtonCorrection_data.h"
#include "SDquadODEulerNEwtonCorrection_emxutil.h"
#include "SDquadODEulerNEwtonCorrection_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    12,                              /* lineNo */
    "SDquadODEulerNEwtonCorrection", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    15,                              /* lineNo */
    "SDquadODEulerNEwtonCorrection", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    24,                              /* lineNo */
    "SDquadODEulerNEwtonCorrection", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    26,                              /* lineNo */
    "SDquadODEulerNEwtonCorrection", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    7,                                                           /* lineNo */
    "ref/ref",                                                   /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/ref.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    17,                                                        /* lineNo */
    "max",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/max.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    38,         /* lineNo */
    "minOrMax", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                       */
};

static emlrtRSInfo h_emlrtRSI = {
    77,        /* lineNo */
    "maximum", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                       */
};

static emlrtRSInfo i_emlrtRSI = {
    169,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m" /* pathName
                                                                            */
};

static emlrtRSInfo j_emlrtRSI = {
    62,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    54,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo l_emlrtRSI = {
    103,         /* lineNo */
    "findFirst", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    21,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    120,                        /* lineNo */
    "minOrMaxRealVectorKernel", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                                              /* iFirst */
    -1,                                              /* iLast */
    51,                                              /* lineNo */
    82,                                              /* colNo */
    "p_quad",                                        /* aName */
    "SDquadODEulerNEwtonCorrection/get_Newton_step", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m", /* pName */
    0                                  /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                                              /* iFirst */
    -1,                                              /* iLast */
    51,                                              /* lineNo */
    65,                                              /* colNo */
    "h_quad",                                        /* aName */
    "SDquadODEulerNEwtonCorrection/get_Newton_step", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m", /* pName */
    0                                  /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    130,             /* lineNo */
    27,              /* colNo */
    "unaryMinOrMax", /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m" /* pName
                                                                            */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    25,                              /* lineNo */
    44,                              /* colNo */
    "h_quad",                        /* aName */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m", /* pName */
    0                                  /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    21,                              /* lineNo */
    60,                              /* colNo */
    "h_coarse",                      /* aName */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m", /* pName */
    0                                  /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    20,                              /* lineNo */
    21,                              /* colNo */
    "p_quad",                        /* aName */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m", /* pName */
    0                                  /* checkKind */
};

static emlrtECInfo emlrtECI = {
    2,                               /* nDims */
    9,                               /* lineNo */
    16,                              /* colNo */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m" /* pName */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    9,                               /* lineNo */
    27,                              /* colNo */
    "gCoeffs",                       /* aName */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m", /* pName */
    0                                  /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    9,                               /* lineNo */
    24,                              /* colNo */
    "gCoeffs",                       /* aName */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m", /* pName */
    0                                  /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    15,                              /* lineNo */
    64,                              /* colNo */
    "p_quad",                        /* aName */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m", /* pName */
    0                                  /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    15,                              /* lineNo */
    47,                              /* colNo */
    "p_coarse",                      /* aName */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m", /* pName */
    0                                  /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    21,                              /* lineNo */
    30,                              /* colNo */
    "h_coarse",                      /* aName */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m", /* pName */
    0                                  /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    21,                              /* lineNo */
    16,                              /* colNo */
    "h_quad",                        /* aName */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m", /* pName */
    0                                  /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    27,                              /* lineNo */
    32,                              /* colNo */
    "h_quad",                        /* aName */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m", /* pName */
    0                                  /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    27,                              /* lineNo */
    20,                              /* colNo */
    "h_quad",                        /* aName */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m", /* pName */
    0                                  /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    31,                              /* lineNo */
    32,                              /* colNo */
    "Newton_success",                /* aName */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m", /* pName */
    0                                  /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    34,                              /* lineNo */
    32,                              /* colNo */
    "Newton_success",                /* aName */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m", /* pName */
    0                                  /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = {
    5,                               /* lineNo */
    5,                               /* colNo */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    6,                               /* lineNo */
    5,                               /* colNo */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    9,                               /* lineNo */
    37,                              /* colNo */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    9,                               /* lineNo */
    5,                               /* colNo */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    33,                                                            /* lineNo */
    20,                                                            /* colNo */
    "polyval",                                                     /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/polyval.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    15,                              /* lineNo */
    47,                              /* colNo */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    10,                              /* lineNo */
    19,                              /* colNo */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m" /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    1,                               /* lineNo */
    48,                              /* colNo */
    "SDquadODEulerNEwtonCorrection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m" /* pName */
};

static emlrtRSInfo o_emlrtRSI = {
    9,                               /* lineNo */
    "SDquadODEulerNEwtonCorrection", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDquadODEulerNEwtonCorrection.m" /* pathName */
};

/* Function Declarations */
static void binary_expand_op(const emlrtStack *sp, emxArray_creal_T *dgCoeffs,
                             const emxArray_creal_T *gCoeffs, int32_T i1,
                             const emxArray_real_T *r1);

/* Function Definitions */
static void binary_expand_op(const emlrtStack *sp, emxArray_creal_T *dgCoeffs,
                             const emxArray_creal_T *gCoeffs, int32_T i1,
                             const emxArray_real_T *r1)
{
  const creal_T *gCoeffs_data;
  creal_T *dgCoeffs_data;
  const real_T *r;
  real_T d;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  r = r1->data;
  gCoeffs_data = gCoeffs->data;
  i = dgCoeffs->size[0] * dgCoeffs->size[1];
  dgCoeffs->size[0] = 1;
  if (r1->size[1] == 1) {
    dgCoeffs->size[1] = i1 + 1;
  } else {
    dgCoeffs->size[1] = r1->size[1];
  }
  emxEnsureCapacity_creal_T(sp, dgCoeffs, i, &g_emlrtRTEI);
  dgCoeffs_data = dgCoeffs->data;
  stride_0_1 = (i1 + 1 != 1);
  stride_1_1 = (r1->size[1] != 1);
  if (r1->size[1] == 1) {
    loop_ub = i1 + 1;
  } else {
    loop_ub = r1->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    d = r[i * stride_1_1];
    dgCoeffs_data[i].re = d * gCoeffs_data[i * stride_0_1].re;
    dgCoeffs_data[i].im = d * gCoeffs_data[i * stride_0_1].im;
  }
}

void SDquadODEulerNEwtonCorrection(
    const emlrtStack *sp, const emxArray_real_T *p_quad,
    const emxArray_real_T *p_coarse, const creal_T h0,
    const emxArray_creal_T *h_coarse, const emxArray_creal_T *gCoeffs,
    real_T freq, real_T NewtonThresh, uint32_T NewtonIts,
    emxArray_creal_T *h_quad, emxArray_creal_T *dhdp_quad,
    emxArray_real_T *Newton_success)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  emxArray_boolean_T *r2;
  emxArray_creal_T *dgCoeffs;
  emxArray_int32_T *r3;
  emxArray_real_T *r;
  const creal_T *gCoeffs_data;
  const creal_T *h_coarse_data;
  creal_T *dgCoeffs_data;
  creal_T *dhdp_quad_data;
  creal_T *h_quad_data;
  const real_T *p_coarse_data;
  const real_T *p_quad_data;
  real_T Newton_step_im;
  real_T Newton_step_re;
  real_T brm;
  real_T ex;
  real_T freq_times_g_at_se_contents_im;
  real_T freq_times_g_at_se_contents_re;
  real_T h0_im;
  real_T h0_re;
  real_T h_coarse_re;
  real_T im;
  real_T re;
  real_T *Newton_success_data;
  real_T *r1;
  int32_T N;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T last;
  int32_T loop_ub;
  int32_T *r5;
  uint32_T qY;
  boolean_T exitg1;
  boolean_T *r4;
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
  gCoeffs_data = gCoeffs->data;
  h_coarse_data = h_coarse->data;
  p_coarse_data = p_coarse->data;
  p_quad_data = p_quad->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &emlrtRSI;
  b_st.site = &e_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &e_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &e_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &e_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &e_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &e_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &e_emlrtRSI;
  /*      p_coarse = p_coarse*freq; */
  i = h_quad->size[0];
  h_quad->size[0] = p_quad->size[0];
  emxEnsureCapacity_creal_T(sp, h_quad, i, &d_emlrtRTEI);
  h_quad_data = h_quad->data;
  loop_ub = p_quad->size[0];
  for (i = 0; i < loop_ub; i++) {
    h_quad_data[i].re = 0.0;
    h_quad_data[i].im = 2.2204460492503131E-16;
  }
  i = Newton_success->size[0];
  Newton_success->size[0] = p_quad->size[0];
  emxEnsureCapacity_real_T(sp, Newton_success, i, &e_emlrtRTEI);
  Newton_success_data = Newton_success->data;
  loop_ub = p_quad->size[0];
  for (i = 0; i < loop_ub; i++) {
    Newton_success_data[i] = 1.0;
  }
  if (gCoeffs->size[1] != 0) {
    Newton_step_re = gCoeffs_data[0].re;
    Newton_step_im = gCoeffs_data[0].im;
    i = gCoeffs->size[1];
    for (k = 0; k <= i - 2; k++) {
      h0_re = h0.re * Newton_step_re - h0.im * Newton_step_im;
      h0_im = h0.re * Newton_step_im + h0.im * Newton_step_re;
      Newton_step_re = h0_re + gCoeffs_data[k + 1].re;
      Newton_step_im = h0_im + gCoeffs_data[k + 1].im;
    }
  }
  freq_times_g_at_se_contents_re = freq * Newton_step_re;
  freq_times_g_at_se_contents_im = freq * Newton_step_im;
  if (1 > gCoeffs->size[1] - 1) {
    loop_ub = 0;
  } else {
    if (1 > gCoeffs->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, gCoeffs->size[1], &g_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if ((gCoeffs->size[1] - 1 < 1) ||
        (gCoeffs->size[1] - 1 > gCoeffs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(gCoeffs->size[1] - 1, 1, gCoeffs->size[1],
                                    &f_emlrtBCI, (emlrtCTX)sp);
    }
    loop_ub = gCoeffs->size[1] - 1;
  }
  emxInit_real_T(sp, &r, 2, &k_emlrtRTEI);
  r1 = r->data;
  if (gCoeffs->size[1] - 1 < 1) {
    r->size[0] = 1;
    r->size[1] = 0;
  } else {
    i = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = (int32_T) - (1.0 - ((real_T)gCoeffs->size[1] - 1.0)) + 1;
    emxEnsureCapacity_real_T(sp, r, i, &f_emlrtRTEI);
    r1 = r->data;
    last = (int32_T) - (1.0 - ((real_T)gCoeffs->size[1] - 1.0));
    for (i = 0; i <= last; i++) {
      r1[i] = ((real_T)gCoeffs->size[1] - 1.0) - (real_T)i;
    }
  }
  if ((loop_ub != r->size[1]) && ((loop_ub != 1) && (r->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(loop_ub, r->size[1], &emlrtECI, (emlrtCTX)sp);
  }
  emxInit_creal_T(sp, &dgCoeffs, 2, &g_emlrtRTEI);
  if (loop_ub == r->size[1]) {
    i = dgCoeffs->size[0] * dgCoeffs->size[1];
    dgCoeffs->size[0] = 1;
    dgCoeffs->size[1] = loop_ub;
    emxEnsureCapacity_creal_T(sp, dgCoeffs, i, &g_emlrtRTEI);
    dgCoeffs_data = dgCoeffs->data;
    for (i = 0; i < loop_ub; i++) {
      dgCoeffs_data[i].re = r1[i] * gCoeffs_data[i].re;
      dgCoeffs_data[i].im = r1[i] * gCoeffs_data[i].im;
    }
  } else {
    st.site = &o_emlrtRSI;
    binary_expand_op(&st, dgCoeffs, gCoeffs, loop_ub - 1, r);
    dgCoeffs_data = dgCoeffs->data;
  }
  emxFree_real_T(sp, &r);
  i = p_quad->size[0];
  emxInit_boolean_T(sp, &r2, &i_emlrtRTEI);
  emxInit_int32_T(sp, &r3, &i_emlrtRTEI);
  for (N = 0; N < i; N++) {
    /*  linearly interpolate coarse solve for initial guess */
    if (N + 1 > p_quad->size[0]) {
      emlrtDynamicBoundsCheckR2012b(N + 1, 1, p_quad->size[0], &h_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = r2->size[0];
    r2->size[0] = p_coarse->size[0];
    emxEnsureCapacity_boolean_T(sp, r2, i1, &i_emlrtRTEI);
    r4 = r2->data;
    loop_ub = p_coarse->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      r4[i1] = (p_coarse_data[i1] <= p_quad_data[N]);
    }
    loop_ub = r2->size[0] - 1;
    last = 0;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      if (r4[b_i]) {
        last++;
      }
    }
    i1 = r3->size[0];
    r3->size[0] = last;
    emxEnsureCapacity_int32_T(sp, r3, i1, &k_emlrtRTEI);
    r5 = r3->data;
    last = 0;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      if (r4[b_i]) {
        r5[last] = b_i + 1;
        last++;
      }
    }
    st.site = &b_emlrtRSI;
    loop_ub = r3->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      if (r5[i1] > p_coarse->size[0]) {
        emlrtDynamicBoundsCheckR2012b(r5[i1], 1, p_coarse->size[0], &i_emlrtBCI,
                                      &st);
      }
    }
    b_st.site = &f_emlrtRSI;
    c_st.site = &g_emlrtRSI;
    d_st.site = &h_emlrtRSI;
    if (r3->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }
    e_st.site = &i_emlrtRSI;
    last = r3->size[0];
    if (r3->size[0] <= 2) {
      if (r3->size[0] == 1) {
        ex = p_coarse_data[r5[0] - 1];
        b_i = 1;
      } else {
        h0_im = p_coarse_data[r5[1] - 1];
        ex = p_coarse_data[r5[0] - 1];
        if ((ex < h0_im) || (muDoubleScalarIsNaN(p_coarse_data[r5[0] - 1]) &&
                             (!muDoubleScalarIsNaN(h0_im)))) {
          ex = h0_im;
          b_i = 2;
        } else {
          b_i = 1;
        }
      }
    } else {
      f_st.site = &k_emlrtRSI;
      ex = p_coarse_data[r5[0] - 1];
      if (!muDoubleScalarIsNaN(ex)) {
        b_i = 1;
      } else {
        b_i = 0;
        g_st.site = &l_emlrtRSI;
        if (r3->size[0] > 2147483646) {
          h_st.site = &m_emlrtRSI;
          b_check_forloop_overflow_error(&h_st);
        }
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= last)) {
          if (!muDoubleScalarIsNaN(p_coarse_data[r5[k - 1] - 1])) {
            b_i = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (b_i == 0) {
        b_i = 1;
      } else {
        f_st.site = &j_emlrtRSI;
        ex = p_coarse_data[r5[b_i - 1] - 1];
        loop_ub = b_i + 1;
        g_st.site = &n_emlrtRSI;
        if ((b_i + 1 <= r3->size[0]) && (r3->size[0] > 2147483646)) {
          h_st.site = &m_emlrtRSI;
          b_check_forloop_overflow_error(&h_st);
        }
        for (k = loop_ub; k <= last; k++) {
          h0_im = p_coarse_data[r5[k - 1] - 1];
          if (ex < h0_im) {
            ex = h0_im;
            b_i = k;
          }
        }
      }
    }
    /* p_coarse should always contain a zero, so this shouldn't return a */
    /* blank. */
    /*  get intermediate step size */
    if (N + 1 > p_quad->size[0]) {
      emlrtDynamicBoundsCheckR2012b(N + 1, 1, p_quad->size[0], &e_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if ((b_i < 1) || (b_i > h_coarse->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, h_coarse->size[0], &d_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (dgCoeffs->size[1] != 0) {
      Newton_step_re = dgCoeffs_data[0].re;
      Newton_step_im = dgCoeffs_data[0].im;
      i1 = dgCoeffs->size[1];
      for (k = 0; k <= i1 - 2; k++) {
        h0_im = h_coarse_data[b_i - 1].re;
        h0_re = h_coarse_data[b_i - 1].im;
        h_coarse_re = h0_im * Newton_step_re - h0_re * Newton_step_im;
        h0_im = h0_im * Newton_step_im + h0_re * Newton_step_re;
        Newton_step_re = h_coarse_re + dgCoeffs_data[k + 1].re;
        Newton_step_im = h0_im + dgCoeffs_data[k + 1].im;
      }
    }
    if (Newton_step_im == 0.0) {
      re = 0.0;
      im = 1.0 / Newton_step_re;
    } else if (Newton_step_re == 0.0) {
      re = 1.0 / Newton_step_im;
      im = 0.0;
    } else {
      brm = muDoubleScalarAbs(Newton_step_re);
      h0_im = muDoubleScalarAbs(Newton_step_im);
      if (brm > h0_im) {
        brm = Newton_step_im / Newton_step_re;
        h0_im = Newton_step_re + brm * Newton_step_im;
        re = brm / h0_im;
        im = (1.0 - brm * 0.0) / h0_im;
      } else if (h0_im == brm) {
        if (Newton_step_re > 0.0) {
          h0_re = 0.5;
        } else {
          h0_re = -0.5;
        }
        if (Newton_step_im > 0.0) {
          h0_im = 0.5;
        } else {
          h0_im = -0.5;
        }
        re = (0.0 * h0_re + h0_im) / brm;
        im = (h0_re - 0.0 * h0_im) / brm;
      } else {
        brm = Newton_step_re / Newton_step_im;
        h0_im = Newton_step_im + brm * Newton_step_re;
        re = (brm * 0.0 + 1.0) / h0_im;
        im = brm / h0_im;
      }
    }
    if (im == 0.0) {
      re /= freq;
      im = 0.0;
    } else if (re == 0.0) {
      re = 0.0;
      im /= freq;
    } else {
      re /= freq;
      im /= freq;
    }
    if (N + 1 > h_quad->size[0]) {
      emlrtDynamicBoundsCheckR2012b(N + 1, 1, h_quad->size[0], &k_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (b_i > h_coarse->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, h_coarse->size[0], &j_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    h0_im = p_quad_data[N] - ex;
    h_quad_data[N].re = h_coarse_data[b_i - 1].re + h0_im * re;
    if (b_i > h_coarse->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, h_coarse->size[0], &j_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (N + 1 > h_quad->size[0]) {
      emlrtDynamicBoundsCheckR2012b(N + 1, 1, h_quad->size[0], &k_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    h_quad_data[N].im = h_coarse_data[b_i - 1].im + h0_im * im;
    /*  Newton corrector step */
    st.site = &c_emlrtRSI;
    if ((1U <= NewtonIts) && (NewtonIts > 4294967294U)) {
      b_st.site = &m_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    last = 0;
    exitg1 = false;
    while ((!exitg1) && (last <= (int32_T)NewtonIts - 1)) {
      if (N + 1 > h_quad->size[0]) {
        emlrtDynamicBoundsCheckR2012b(N + 1, 1, h_quad->size[0], &c_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (dgCoeffs->size[1] != 0) {
        re = dgCoeffs_data[0].re;
        im = dgCoeffs_data[0].im;
        i1 = dgCoeffs->size[1];
        for (k = 0; k <= i1 - 2; k++) {
          h_coarse_re = h_quad_data[N].re;
          brm = h_quad_data[N].im;
          h0_re = h_coarse_re * re - brm * im;
          h0_im = h_coarse_re * im + brm * re;
          re = h0_re + dgCoeffs_data[k + 1].re;
          im = h0_im + dgCoeffs_data[k + 1].im;
        }
      }
      st.site = &d_emlrtRSI;
      /*          s = (-freq_times_g_at_se - 1i*p_quad(N) +
       * freq*polyval(gCoeffs,h_quad(N)))/(freq*dh_N); */
      if (N + 1 > h_quad->size[0]) {
        emlrtDynamicBoundsCheckR2012b(N + 1, 1, h_quad->size[0], &b_emlrtBCI,
                                      &st);
      }
      if (gCoeffs->size[1] != 0) {
        Newton_step_re = gCoeffs_data[0].re;
        Newton_step_im = gCoeffs_data[0].im;
        i1 = gCoeffs->size[1];
        for (k = 0; k <= i1 - 2; k++) {
          h_coarse_re = h_quad_data[N].re;
          brm = h_quad_data[N].im;
          h0_re = h_coarse_re * Newton_step_re - brm * Newton_step_im;
          h0_im = h_coarse_re * Newton_step_im + brm * Newton_step_re;
          Newton_step_re = h0_re + gCoeffs_data[k + 1].re;
          Newton_step_im = h0_im + gCoeffs_data[k + 1].im;
        }
      }
      if (N + 1 > p_quad->size[0]) {
        emlrtDynamicBoundsCheckR2012b(N + 1, 1, p_quad->size[0], &emlrtBCI,
                                      &st);
      }
      Newton_step_re =
          (-freq_times_g_at_se_contents_re + freq * Newton_step_re) -
          0.0 * p_quad_data[N];
      ex = (-freq_times_g_at_se_contents_im + freq * Newton_step_im) -
           p_quad_data[N];
      h0_re = freq * re;
      h_coarse_re = freq * im;
      if (h_coarse_re == 0.0) {
        if (ex == 0.0) {
          re = Newton_step_re / h0_re;
          im = 0.0;
        } else if (Newton_step_re == 0.0) {
          re = 0.0;
          im = ex / h0_re;
        } else {
          re = Newton_step_re / h0_re;
          im = ex / h0_re;
        }
      } else if (h0_re == 0.0) {
        if (Newton_step_re == 0.0) {
          re = ex / h_coarse_re;
          im = 0.0;
        } else if (ex == 0.0) {
          re = 0.0;
          im = -(Newton_step_re / h_coarse_re);
        } else {
          re = ex / h_coarse_re;
          im = -(Newton_step_re / h_coarse_re);
        }
      } else {
        brm = muDoubleScalarAbs(h0_re);
        h0_im = muDoubleScalarAbs(h_coarse_re);
        if (brm > h0_im) {
          brm = h_coarse_re / h0_re;
          h0_im = h0_re + brm * h_coarse_re;
          re = (Newton_step_re + brm * ex) / h0_im;
          im = (ex - brm * Newton_step_re) / h0_im;
        } else if (h0_im == brm) {
          if (h0_re > 0.0) {
            h0_re = 0.5;
          } else {
            h0_re = -0.5;
          }
          if (h_coarse_re > 0.0) {
            h0_im = 0.5;
          } else {
            h0_im = -0.5;
          }
          re = (Newton_step_re * h0_re + ex * h0_im) / brm;
          im = (ex * h0_re - Newton_step_re * h0_im) / brm;
        } else {
          brm = h0_re / h_coarse_re;
          h0_im = h_coarse_re + brm * h0_re;
          re = (brm * Newton_step_re + ex) / h0_im;
          im = (brm * ex - Newton_step_re) / h0_im;
        }
      }
      if (N + 1 > h_quad->size[0]) {
        emlrtDynamicBoundsCheckR2012b(N + 1, 1, h_quad->size[0], &m_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      h_quad_data[N].re -= re;
      if (N + 1 > h_quad->size[0]) {
        emlrtDynamicBoundsCheckR2012b(N + 1, 1, h_quad->size[0], &l_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      h_quad_data[N].im -= im;
      /*              err = abs(freq_times_g_at_se+ 1i*p_quad(N) -
       * freq*polyval(gCoeffs,h_quad(N))); */
      if (muDoubleScalarHypot(re, im) < NewtonThresh) {
        if (N + 1 > Newton_success->size[0]) {
          emlrtDynamicBoundsCheckR2012b(N + 1, 1, Newton_success->size[0],
                                        &n_emlrtBCI, (emlrtCTX)sp);
        }
        Newton_success_data[N] = last + 1U;
        exitg1 = true;
      } else if (last + 1U == NewtonIts) {
        if (N + 1 > Newton_success->size[0]) {
          emlrtDynamicBoundsCheckR2012b(N + 1, 1, Newton_success->size[0],
                                        &o_emlrtBCI, (emlrtCTX)sp);
        }
        qY = last + 2U;
        if (last + 2U < last + 1U) {
          qY = MAX_uint32_T;
        }
        Newton_success_data[N] = qY;
        /*                  n = uint32(inf); */
        exitg1 = true;
      } else {
        last++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtCTX)sp);
        }
      }
    }
    /*          if newton_fail */
    /*              Newton_success(N) = uint32(inf); */
    /*          else */
    /*              Newton_success(N) = n; */
    /*          end */
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_int32_T(sp, &r3);
  emxFree_boolean_T(sp, &r2);
  /*  now get Jacobian */
  i = dhdp_quad->size[0];
  dhdp_quad->size[0] = h_quad->size[0];
  emxEnsureCapacity_creal_T(sp, dhdp_quad, i, &h_emlrtRTEI);
  dhdp_quad_data = dhdp_quad->data;
  if ((h_quad->size[0] != 0) && (dgCoeffs->size[1] != 0)) {
    i = dhdp_quad->size[0];
    dhdp_quad->size[0] = h_quad->size[0];
    emxEnsureCapacity_creal_T(sp, dhdp_quad, i, &j_emlrtRTEI);
    dhdp_quad_data = dhdp_quad->data;
    loop_ub = h_quad->size[0];
    for (i = 0; i < loop_ub; i++) {
      dhdp_quad_data[i] = dgCoeffs_data[0];
    }
    i = dgCoeffs->size[1];
    for (k = 0; k <= i - 2; k++) {
      loop_ub = h_quad->size[0];
      i1 = dhdp_quad->size[0];
      dhdp_quad->size[0] = h_quad->size[0];
      emxEnsureCapacity_creal_T(sp, dhdp_quad, i1, &j_emlrtRTEI);
      dhdp_quad_data = dhdp_quad->data;
      for (i1 = 0; i1 < loop_ub; i1++) {
        h_coarse_re = h_quad_data[i1].re;
        brm = dhdp_quad_data[i1].im;
        h0_im = h_quad_data[i1].im;
        h0_re = dhdp_quad_data[i1].re;
        dhdp_quad_data[i1].re =
            (h_coarse_re * h0_re - h0_im * brm) + dgCoeffs_data[k + 1].re;
        dhdp_quad_data[i1].im =
            (h_coarse_re * brm + h0_im * h0_re) + dgCoeffs_data[k + 1].im;
      }
    }
  }
  emxFree_creal_T(sp, &dgCoeffs);
  loop_ub = dhdp_quad->size[0];
  for (i = 0; i < loop_ub; i++) {
    h0_re = dhdp_quad_data[i].re;
    h_coarse_re = dhdp_quad_data[i].im;
    if (h_coarse_re == 0.0) {
      re = 0.0;
      im = 1.0 / h0_re;
    } else if (h0_re == 0.0) {
      re = 1.0 / h_coarse_re;
      im = 0.0;
    } else {
      brm = muDoubleScalarAbs(h0_re);
      h0_im = muDoubleScalarAbs(h_coarse_re);
      if (brm > h0_im) {
        brm = h_coarse_re / h0_re;
        h0_im = h0_re + brm * h_coarse_re;
        re = brm / h0_im;
        im = (1.0 - brm * 0.0) / h0_im;
      } else if (h0_im == brm) {
        if (h0_re > 0.0) {
          h0_re = 0.5;
        } else {
          h0_re = -0.5;
        }
        if (h_coarse_re > 0.0) {
          h0_im = 0.5;
        } else {
          h0_im = -0.5;
        }
        re = (0.0 * h0_re + h0_im) / brm;
        im = (h0_re - 0.0 * h0_im) / brm;
      } else {
        brm = h0_re / h_coarse_re;
        h0_im = h_coarse_re + brm * h0_re;
        re = (brm * 0.0 + 1.0) / h0_im;
        im = brm / h0_im;
      }
    }
    if (im == 0.0) {
      dhdp_quad_data[i].re = re / freq;
      dhdp_quad_data[i].im = 0.0;
    } else if (re == 0.0) {
      dhdp_quad_data[i].re = 0.0;
      dhdp_quad_data[i].im = im / freq;
    } else {
      dhdp_quad_data[i].re = re / freq;
      dhdp_quad_data[i].im = im / freq;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (SDquadODEulerNEwtonCorrection.c) */
