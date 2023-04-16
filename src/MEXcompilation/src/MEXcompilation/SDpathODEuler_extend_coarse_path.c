/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDpathODEuler_extend_coarse_path.c
 *
 * Code generation for function 'SDpathODEuler_extend_coarse_path'
 *
 */

/* Include files */
#include "SDpathODEuler_extend_coarse_path.h"
#include "SDpathODEuler_extend_coarse_path_data.h"
#include "SDpathODEuler_extend_coarse_path_emxutil.h"
#include "SDpathODEuler_extend_coarse_path_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    34,                                 /* lineNo */
    "SDpathODEuler_extend_coarse_path", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    33,                                 /* lineNo */
    "SDpathODEuler_extend_coarse_path", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    23,                                 /* lineNo */
    "SDpathODEuler_extend_coarse_path", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    8,                                  /* lineNo */
    "SDpathODEuler_extend_coarse_path", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    7,                                  /* lineNo */
    "SDpathODEuler_extend_coarse_path", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    21,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    18,                                                      /* lineNo */
    "abs",                                                   /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/elfun/abs.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI =
    {
        74,                    /* lineNo */
        "applyScalarFunction", /* fcnName */
        "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
        "applyScalarFunction.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    15,                                                        /* lineNo */
    "min",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/min.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    46,         /* lineNo */
    "minOrMax", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                       */
};

static emlrtRSInfo k_emlrtRSI = {
    92,        /* lineNo */
    "minimum", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                       */
};

static emlrtRSInfo l_emlrtRSI = {
    204,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m" /* pathName
                                                                            */
};

static emlrtRSInfo m_emlrtRSI = {
    893,                    /* lineNo */
    "minRealVectorOmitNaN", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m" /* pathName
                                                                            */
};

static emlrtRSInfo n_emlrtRSI = {
    62,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    54,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    103,         /* lineNo */
    "findFirst", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo q_emlrtRSI = {
    120,                        /* lineNo */
    "minOrMaxRealVectorKernel", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRTEInfo emlrtRTEI = {
    130,             /* lineNo */
    27,              /* colNo */
    "unaryMinOrMax", /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m" /* pName
                                                                            */
};

static emlrtBCInfo emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    7,                                  /* lineNo */
    24,                                 /* colNo */
    "gCoeffs",                          /* aName */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    0                                     /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    7,                                  /* lineNo */
    27,                                 /* colNo */
    "gCoeffs",                          /* aName */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    0                                     /* checkKind */
};

static emlrtECInfo emlrtECI = {
    2,                                  /* nDims */
    7,                                  /* lineNo */
    16,                                 /* colNo */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m" /* pName */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    8,                                  /* lineNo */
    26,                                 /* colNo */
    "dgCoeffs",                         /* aName */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    0                                     /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    8,                                  /* lineNo */
    29,                                 /* colNo */
    "dgCoeffs",                         /* aName */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    0                                     /* checkKind */
};

static emlrtECInfo b_emlrtECI = {
    2,                                  /* nDims */
    8,                                  /* lineNo */
    17,                                 /* colNo */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m" /* pName */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    15,                                 /* lineNo */
    11,                                 /* colNo */
    "p_log",                            /* aName */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    0                                     /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    15,                                 /* lineNo */
    13,                                 /* colNo */
    "p_log",                            /* aName */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    0                                     /* checkKind */
};

static emlrtECInfo c_emlrtECI = {
    -1,                                 /* nDims */
    15,                                 /* lineNo */
    5,                                  /* colNo */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m" /* pName */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    33,                                 /* lineNo */
    23,                                 /* colNo */
    "p_log",                            /* aName */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    0                                     /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    33,                                 /* lineNo */
    25,                                 /* colNo */
    "p_log",                            /* aName */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    0                                     /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    16,                                 /* lineNo */
    11,                                 /* colNo */
    "h_log",                            /* aName */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    0                                     /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    16,                                 /* lineNo */
    13,                                 /* colNo */
    "h_log",                            /* aName */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    0                                     /* checkKind */
};

static emlrtECInfo d_emlrtECI = {
    -1,                                 /* nDims */
    16,                                 /* lineNo */
    5,                                  /* colNo */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m" /* pName */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    34,                                 /* lineNo */
    23,                                 /* colNo */
    "h_log",                            /* aName */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    0                                     /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    34,                                 /* lineNo */
    25,                                 /* colNo */
    "h_log",                            /* aName */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    0                                     /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    11,                                 /* lineNo */
    16,                                 /* colNo */
    "h_init",                           /* aName */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    0                                     /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    12,                                 /* lineNo */
    5,                                  /* colNo */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    1                                     /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    12,                                 /* lineNo */
    5,                                  /* colNo */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    4                                     /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    13,                                 /* lineNo */
    5,                                  /* colNo */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    1                                     /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    13,                                 /* lineNo */
    5,                                  /* colNo */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    4                                     /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    18,                                 /* lineNo */
    17,                                 /* colNo */
    "p_log",                            /* aName */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    0                                     /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    26,                                 /* lineNo */
    26,                                 /* colNo */
    "p_log",                            /* aName */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    0                                     /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    26,                                 /* lineNo */
    15,                                 /* colNo */
    "p_log",                            /* aName */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    0                                     /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                                 /* iFirst */
    -1,                                 /* iLast */
    27,                                 /* lineNo */
    15,                                 /* colNo */
    "h_log",                            /* aName */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m", /* pName */
    0                                     /* checkKind */
};

static emlrtRTEInfo e_emlrtRTEI = {
    7,                                  /* lineNo */
    37,                                 /* colNo */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    7,                                  /* lineNo */
    5,                                  /* colNo */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    8,                                  /* lineNo */
    39,                                 /* colNo */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    8,                                  /* lineNo */
    5,                                  /* colNo */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    12,                                 /* lineNo */
    5,                                  /* colNo */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    13,                                 /* lineNo */
    5,                                  /* colNo */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m" /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    33,                                 /* lineNo */
    5,                                  /* colNo */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m" /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = {
    34,                                 /* lineNo */
    5,                                  /* colNo */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    23,                                 /* lineNo */
    68,                                 /* colNo */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m" /* pName */
};

static emlrtRTEInfo n_emlrtRTEI =
    {
        30,                    /* lineNo */
        21,                    /* colNo */
        "applyScalarFunction", /* fName */
        "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
        "applyScalarFunction.m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    2,                                  /* lineNo */
    5,                                  /* colNo */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    23,                                 /* lineNo */
    64,                                 /* colNo */
    "SDpathODEuler_extend_coarse_path", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/"
    "SDpathODEuler_extend_coarse_path.m" /* pName */
};

/* Function Declarations */
static void binary_expand_op(const emlrtStack *sp, emxArray_creal_T *ddgCoeffs,
                             const emxArray_creal_T *dgCoeffs, int32_T i1,
                             const emxArray_real_T *r1);

/* Function Definitions */
static void binary_expand_op(const emlrtStack *sp, emxArray_creal_T *ddgCoeffs,
                             const emxArray_creal_T *dgCoeffs, int32_T i1,
                             const emxArray_real_T *r1)
{
  const creal_T *dgCoeffs_data;
  creal_T *ddgCoeffs_data;
  const real_T *r;
  real_T d;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  r = r1->data;
  dgCoeffs_data = dgCoeffs->data;
  i = ddgCoeffs->size[0] * ddgCoeffs->size[1];
  ddgCoeffs->size[0] = 1;
  if (r1->size[1] == 1) {
    ddgCoeffs->size[1] = i1 + 1;
  } else {
    ddgCoeffs->size[1] = r1->size[1];
  }
  emxEnsureCapacity_creal_T(sp, ddgCoeffs, i, &h_emlrtRTEI);
  ddgCoeffs_data = ddgCoeffs->data;
  stride_0_1 = (i1 + 1 != 1);
  stride_1_1 = (r1->size[1] != 1);
  if (r1->size[1] == 1) {
    loop_ub = i1 + 1;
  } else {
    loop_ub = r1->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    d = r[i * stride_1_1];
    ddgCoeffs_data[i].re = d * dgCoeffs_data[i * stride_0_1].re;
    ddgCoeffs_data[i].im = d * dgCoeffs_data[i * stride_0_1].im;
  }
}

void SDpathODEuler_extend_coarse_path(
    const emlrtStack *sp, const emxArray_real_T *p_init,
    const emxArray_creal_T *h_init, const emxArray_creal_T *gCoeffs,
    const emxArray_creal_T *SPs, real_T base_step_size, int64_T n_max,
    real_T P_new_max, emxArray_real_T *p_log_out, emxArray_creal_T *h_log_out,
    boolean_T *success)
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
  emxArray_creal_T *ddgCoeffs;
  emxArray_creal_T *dgCoeffs;
  emxArray_creal_T *h_log;
  emxArray_creal_T *x;
  emxArray_real_T *p_log;
  emxArray_real_T *r;
  emxArray_real_T *varargin_1;
  const creal_T *SPs_data;
  const creal_T *gCoeffs_data;
  const creal_T *h_init_data;
  creal_T *ddgCoeffs_data;
  creal_T *dgCoeffs_data;
  creal_T *h_log_data;
  creal_T *h_log_out_data;
  const real_T *p_init_data;
  real_T F_h_im;
  real_T F_h_re;
  real_T b_dg_h_re;
  real_T b_h_re;
  real_T brm;
  real_T ddg_h_im;
  real_T ddg_h_re;
  real_T dg_h_im;
  real_T dg_h_re;
  real_T h_im;
  real_T h_re;
  real_T p_step_size;
  real_T *p_log_data;
  real_T *p_log_out_data;
  int32_T iv[2];
  int32_T a;
  int32_T exitg1;
  int32_T k;
  int32_T last;
  int32_T nx;
  uint32_T n;
  boolean_T exitg2;
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
  SPs_data = SPs->data;
  gCoeffs_data = gCoeffs->data;
  h_init_data = h_init->data;
  p_init_data = p_init->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /* computes NSD path h(p) and h'(p) */
  /* ODE for path of steepest descent: */
  if (1 > gCoeffs->size[1] - 1) {
    nx = 0;
  } else {
    if (1 > gCoeffs->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, gCoeffs->size[1], &emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if ((gCoeffs->size[1] - 1 < 1) ||
        (gCoeffs->size[1] - 1 > gCoeffs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(gCoeffs->size[1] - 1, 1, gCoeffs->size[1],
                                    &b_emlrtBCI, (emlrtCTX)sp);
    }
    nx = gCoeffs->size[1] - 1;
  }
  st.site = &e_emlrtRSI;
  emxInit_real_T(&st, &r, 2, &o_emlrtRTEI);
  p_log_out_data = r->data;
  if (gCoeffs->size[1] - 1 < 1) {
    r->size[0] = 1;
    r->size[1] = 0;
  } else {
    a = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = (int32_T) - (1.0 - ((real_T)gCoeffs->size[1] - 1.0)) + 1;
    emxEnsureCapacity_real_T(&st, r, a, &e_emlrtRTEI);
    p_log_out_data = r->data;
    last = (int32_T) - (1.0 - ((real_T)gCoeffs->size[1] - 1.0));
    for (a = 0; a <= last; a++) {
      p_log_out_data[a] = ((real_T)gCoeffs->size[1] - 1.0) - (real_T)a;
    }
  }
  if ((nx != r->size[1]) && ((nx != 1) && (r->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(nx, r->size[1], &emlrtECI, (emlrtCTX)sp);
  }
  emxInit_creal_T(sp, &dgCoeffs, 2, &f_emlrtRTEI);
  if (nx == r->size[1]) {
    a = dgCoeffs->size[0] * dgCoeffs->size[1];
    dgCoeffs->size[0] = 1;
    dgCoeffs->size[1] = nx;
    emxEnsureCapacity_creal_T(sp, dgCoeffs, a, &f_emlrtRTEI);
    dgCoeffs_data = dgCoeffs->data;
    for (a = 0; a < nx; a++) {
      dgCoeffs_data[a].re = p_log_out_data[a] * gCoeffs_data[a].re;
      dgCoeffs_data[a].im = p_log_out_data[a] * gCoeffs_data[a].im;
    }
  } else {
    st.site = &e_emlrtRSI;
    binary_expand_op(&st, dgCoeffs, gCoeffs, nx - 1, r);
    dgCoeffs_data = dgCoeffs->data;
  }
  if (1 > dgCoeffs->size[1] - 1) {
    nx = 0;
  } else {
    if (1 > dgCoeffs->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, dgCoeffs->size[1], &c_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if ((dgCoeffs->size[1] - 1 < 1) ||
        (dgCoeffs->size[1] - 1 > dgCoeffs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(dgCoeffs->size[1] - 1, 1, dgCoeffs->size[1],
                                    &d_emlrtBCI, (emlrtCTX)sp);
    }
    nx = dgCoeffs->size[1] - 1;
  }
  st.site = &d_emlrtRSI;
  if (gCoeffs->size[1] - 2 < 1) {
    r->size[0] = 1;
    r->size[1] = 0;
  } else {
    a = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] =
        (int32_T) - (1.0 - (((real_T)gCoeffs->size[1] - 1.0) - 1.0)) + 1;
    emxEnsureCapacity_real_T(&st, r, a, &g_emlrtRTEI);
    p_log_out_data = r->data;
    last = (int32_T) - (1.0 - (((real_T)gCoeffs->size[1] - 1.0) - 1.0));
    for (a = 0; a <= last; a++) {
      p_log_out_data[a] = (((real_T)gCoeffs->size[1] - 1.0) - 1.0) - (real_T)a;
    }
  }
  if ((nx != r->size[1]) && ((nx != 1) && (r->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(nx, r->size[1], &b_emlrtECI, (emlrtCTX)sp);
  }
  emxInit_creal_T(sp, &ddgCoeffs, 2, &h_emlrtRTEI);
  if (nx == r->size[1]) {
    a = ddgCoeffs->size[0] * ddgCoeffs->size[1];
    ddgCoeffs->size[0] = 1;
    ddgCoeffs->size[1] = nx;
    emxEnsureCapacity_creal_T(sp, ddgCoeffs, a, &h_emlrtRTEI);
    ddgCoeffs_data = ddgCoeffs->data;
    for (a = 0; a < nx; a++) {
      ddgCoeffs_data[a].re = p_log_out_data[a] * dgCoeffs_data[a].re;
      ddgCoeffs_data[a].im = p_log_out_data[a] * dgCoeffs_data[a].im;
    }
  } else {
    st.site = &d_emlrtRSI;
    binary_expand_op(&st, ddgCoeffs, dgCoeffs, nx - 1, r);
    ddgCoeffs_data = ddgCoeffs->data;
  }
  emxFree_real_T(sp, &r);
  /*  main loop */
  if (h_init->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(h_init->size[0], 1, h_init->size[0],
                                  &m_emlrtBCI, (emlrtCTX)sp);
  }
  h_re = h_init_data[h_init->size[0] - 1].re;
  if (h_init->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(h_init->size[0], 1, h_init->size[0],
                                  &m_emlrtBCI, (emlrtCTX)sp);
  }
  emxInit_real_T(sp, &p_log, 1, &i_emlrtRTEI);
  h_im = h_init_data[h_init->size[0] - 1].im;
  if (!(n_max >= 0.0)) {
    emlrtNonNegativeCheckR2012b((real_T)n_max, &b_emlrtDCI, (emlrtCTX)sp);
  }
  p_step_size = (real_T)(int64_T)muDoubleScalarFloor((real_T)n_max);
  if (p_step_size != (int32_T)muDoubleScalarFloor(p_step_size)) {
    emlrtIntegerCheckR2012b(p_step_size, &emlrtDCI, (emlrtCTX)sp);
  }
  a = p_log->size[0];
  p_log->size[0] = (int32_T)(int64_T)muDoubleScalarFloor(p_step_size);
  emxEnsureCapacity_real_T(sp, p_log, a, &i_emlrtRTEI);
  p_log_data = p_log->data;
  if (!(n_max >= 0.0)) {
    emlrtNonNegativeCheckR2012b((real_T)n_max, &b_emlrtDCI, (emlrtCTX)sp);
  }
  if (p_step_size != (int32_T)muDoubleScalarFloor(p_step_size)) {
    emlrtIntegerCheckR2012b(p_step_size, &emlrtDCI, (emlrtCTX)sp);
  }
  nx = (int32_T)(int64_T)muDoubleScalarFloor(p_step_size);
  for (a = 0; a < nx; a++) {
    p_log_data[a] = 0.0;
  }
  emxInit_creal_T(sp, &h_log, 1, &j_emlrtRTEI);
  if (!(n_max >= 0.0)) {
    emlrtNonNegativeCheckR2012b((real_T)n_max, &d_emlrtDCI, (emlrtCTX)sp);
  }
  if (p_step_size != (int32_T)muDoubleScalarFloor(p_step_size)) {
    emlrtIntegerCheckR2012b(p_step_size, &c_emlrtDCI, (emlrtCTX)sp);
  }
  a = h_log->size[0];
  h_log->size[0] = (int32_T)(int64_T)muDoubleScalarFloor(p_step_size);
  emxEnsureCapacity_creal_T(sp, h_log, a, &j_emlrtRTEI);
  h_log_data = h_log->data;
  if (!(n_max >= 0.0)) {
    emlrtNonNegativeCheckR2012b((real_T)n_max, &d_emlrtDCI, (emlrtCTX)sp);
  }
  if (p_step_size != (int32_T)muDoubleScalarFloor(p_step_size)) {
    emlrtIntegerCheckR2012b(p_step_size, &c_emlrtDCI, (emlrtCTX)sp);
  }
  nx = (int32_T)(int64_T)muDoubleScalarFloor(p_step_size);
  for (a = 0; a < nx; a++) {
    h_log_data[a].re = 0.0;
    h_log_data[a].im = 2.2204460492503131E-16;
  }
  n = (uint32_T)p_init->size[0];
  if (1 > p_init->size[0]) {
    nx = 0;
  } else {
    if (1 > (int32_T)n_max) {
      emlrtDynamicBoundsCheckR2012b(1, 1, (int32_T)n_max, &e_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (p_init->size[0] > (int32_T)n_max) {
      emlrtDynamicBoundsCheckR2012b(p_init->size[0], 1, (int32_T)n_max,
                                    &f_emlrtBCI, (emlrtCTX)sp);
    }
    nx = p_init->size[0];
  }
  if (nx != p_init->size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(nx, p_init->size[0], &c_emlrtECI,
                                    (emlrtCTX)sp);
  }
  for (a = 0; a < nx; a++) {
    p_log_data[a] = p_init_data[a];
  }
  if (1 > p_init->size[0]) {
    nx = 0;
  } else {
    if (1 > h_log->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, h_log->size[0], &i_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (p_init->size[0] > h_log->size[0]) {
      emlrtDynamicBoundsCheckR2012b(p_init->size[0], 1, h_log->size[0],
                                    &j_emlrtBCI, (emlrtCTX)sp);
    }
    nx = p_init->size[0];
  }
  if (nx != h_init->size[0]) {
    emlrtSubAssignSizeCheck1dR2017a(nx, h_init->size[0], &d_emlrtECI,
                                    (emlrtCTX)sp);
  }
  for (a = 0; a < nx; a++) {
    h_log_data[a] = h_init_data[a];
  }
  *success = true;
  emxInit_real_T(sp, &varargin_1, 1, &p_emlrtRTEI);
  emxInit_creal_T(sp, &x, 1, &m_emlrtRTEI);
  do {
    exitg1 = 0;
    if (((int32_T)n < 1) || ((int32_T)n > p_log->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)n, 1, p_log->size[0], &n_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (p_log_data[(int32_T)n - 1] < P_new_max) {
      n++;
      if (dgCoeffs->size[1] != 0) {
        dg_h_re = dgCoeffs_data[0].re;
        dg_h_im = dgCoeffs_data[0].im;
        a = dgCoeffs->size[1];
        for (k = 0; k <= a - 2; k++) {
          b_h_re = h_re * dg_h_re - h_im * dg_h_im;
          p_step_size = h_re * dg_h_im + h_im * dg_h_re;
          dg_h_re = b_h_re + dgCoeffs_data[k + 1].re;
          dg_h_im = p_step_size + dgCoeffs_data[k + 1].im;
        }
      }
      if (ddgCoeffs->size[1] != 0) {
        ddg_h_re = ddgCoeffs_data[0].re;
        ddg_h_im = ddgCoeffs_data[0].im;
        a = ddgCoeffs->size[1];
        for (k = 0; k <= a - 2; k++) {
          b_h_re = h_re * ddg_h_re - h_im * ddg_h_im;
          p_step_size = h_re * ddg_h_im + h_im * ddg_h_re;
          ddg_h_re = b_h_re + ddgCoeffs_data[k + 1].re;
          ddg_h_im = p_step_size + ddgCoeffs_data[k + 1].im;
        }
      }
      if (dg_h_im == 0.0) {
        F_h_re = 0.0;
        F_h_im = 1.0 / dg_h_re;
      } else if (dg_h_re == 0.0) {
        F_h_re = 1.0 / dg_h_im;
        F_h_im = 0.0;
      } else {
        brm = muDoubleScalarAbs(dg_h_re);
        p_step_size = muDoubleScalarAbs(dg_h_im);
        if (brm > p_step_size) {
          p_step_size = dg_h_im / dg_h_re;
          b_h_re = dg_h_re + p_step_size * dg_h_im;
          F_h_re = p_step_size / b_h_re;
          F_h_im = (1.0 - p_step_size * 0.0) / b_h_re;
        } else if (p_step_size == brm) {
          if (dg_h_re > 0.0) {
            p_step_size = 0.5;
          } else {
            p_step_size = -0.5;
          }
          if (dg_h_im > 0.0) {
            b_h_re = 0.5;
          } else {
            b_h_re = -0.5;
          }
          F_h_re = (0.0 * p_step_size + b_h_re) / brm;
          F_h_im = (p_step_size - 0.0 * b_h_re) / brm;
        } else {
          p_step_size = dg_h_re / dg_h_im;
          b_h_re = dg_h_im + p_step_size * dg_h_re;
          F_h_re = (p_step_size * 0.0 + 1.0) / b_h_re;
          F_h_im = p_step_size / b_h_re;
        }
      }
      b_dg_h_re = dg_h_re * dg_h_re - dg_h_im * dg_h_im;
      p_step_size = dg_h_re * dg_h_im;
      dg_h_im = p_step_size + p_step_size;
      if (ddg_h_im == 0.0) {
        if (dg_h_im == 0.0) {
          dg_h_re = b_dg_h_re / ddg_h_re;
          dg_h_im = 0.0;
        } else if (b_dg_h_re == 0.0) {
          dg_h_re = 0.0;
          dg_h_im /= ddg_h_re;
        } else {
          dg_h_re = b_dg_h_re / ddg_h_re;
          dg_h_im /= ddg_h_re;
        }
      } else if (ddg_h_re == 0.0) {
        if (b_dg_h_re == 0.0) {
          dg_h_re = dg_h_im / ddg_h_im;
          dg_h_im = 0.0;
        } else if (dg_h_im == 0.0) {
          dg_h_re = 0.0;
          dg_h_im = -(b_dg_h_re / ddg_h_im);
        } else {
          dg_h_re = dg_h_im / ddg_h_im;
          dg_h_im = -(b_dg_h_re / ddg_h_im);
        }
      } else {
        brm = muDoubleScalarAbs(ddg_h_re);
        p_step_size = muDoubleScalarAbs(ddg_h_im);
        if (brm > p_step_size) {
          p_step_size = ddg_h_im / ddg_h_re;
          b_h_re = ddg_h_re + p_step_size * ddg_h_im;
          dg_h_re = (b_dg_h_re + p_step_size * dg_h_im) / b_h_re;
          dg_h_im = (dg_h_im - p_step_size * b_dg_h_re) / b_h_re;
        } else if (p_step_size == brm) {
          if (ddg_h_re > 0.0) {
            p_step_size = 0.5;
          } else {
            p_step_size = -0.5;
          }
          if (ddg_h_im > 0.0) {
            b_h_re = 0.5;
          } else {
            b_h_re = -0.5;
          }
          dg_h_re = (b_dg_h_re * p_step_size + dg_h_im * b_h_re) / brm;
          dg_h_im = (dg_h_im * p_step_size - b_dg_h_re * b_h_re) / brm;
        } else {
          p_step_size = ddg_h_re / ddg_h_im;
          b_h_re = ddg_h_im + p_step_size * ddg_h_re;
          dg_h_re = (p_step_size * b_dg_h_re + dg_h_im) / b_h_re;
          dg_h_im = (p_step_size * dg_h_im - b_dg_h_re) / b_h_re;
        }
      }
      st.site = &c_emlrtRSI;
      b_st.site = &c_emlrtRSI;
      a = x->size[0];
      x->size[0] = SPs->size[0];
      emxEnsureCapacity_creal_T(&b_st, x, a, &m_emlrtRTEI);
      h_log_out_data = x->data;
      nx = SPs->size[0];
      for (a = 0; a < nx; a++) {
        h_log_out_data[a].re = SPs_data[a].re - h_re;
        h_log_out_data[a].im = SPs_data[a].im - h_im;
      }
      c_st.site = &g_emlrtRSI;
      nx = x->size[0];
      a = varargin_1->size[0];
      varargin_1->size[0] = x->size[0];
      emxEnsureCapacity_real_T(&c_st, varargin_1, a, &n_emlrtRTEI);
      p_log_out_data = varargin_1->data;
      d_st.site = &h_emlrtRSI;
      if ((1 <= x->size[0]) && (x->size[0] > 2147483646)) {
        e_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      for (k = 0; k < nx; k++) {
        p_log_out_data[k] =
            muDoubleScalarHypot(h_log_out_data[k].re, h_log_out_data[k].im);
      }
      b_st.site = &i_emlrtRSI;
      c_st.site = &j_emlrtRSI;
      d_st.site = &k_emlrtRSI;
      if (varargin_1->size[0] < 1) {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
            "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }
      e_st.site = &l_emlrtRSI;
      f_st.site = &m_emlrtRSI;
      last = varargin_1->size[0];
      if (varargin_1->size[0] <= 2) {
        if (varargin_1->size[0] == 1) {
          b_h_re = p_log_out_data[0];
        } else if ((p_log_out_data[0] > p_log_out_data[1]) ||
                   (muDoubleScalarIsNaN(p_log_out_data[0]) &&
                    (!muDoubleScalarIsNaN(p_log_out_data[1])))) {
          b_h_re = p_log_out_data[1];
        } else {
          b_h_re = p_log_out_data[0];
        }
      } else {
        g_st.site = &o_emlrtRSI;
        if (!muDoubleScalarIsNaN(p_log_out_data[0])) {
          nx = 1;
        } else {
          nx = 0;
          h_st.site = &p_emlrtRSI;
          if (varargin_1->size[0] > 2147483646) {
            i_st.site = &f_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          k = 2;
          exitg2 = false;
          while ((!exitg2) && (k <= last)) {
            if (!muDoubleScalarIsNaN(p_log_out_data[k - 1])) {
              nx = k;
              exitg2 = true;
            } else {
              k++;
            }
          }
        }
        if (nx == 0) {
          b_h_re = p_log_out_data[0];
        } else {
          g_st.site = &n_emlrtRSI;
          b_h_re = p_log_out_data[nx - 1];
          a = nx + 1;
          h_st.site = &q_emlrtRSI;
          if ((nx + 1 <= varargin_1->size[0]) &&
              (varargin_1->size[0] > 2147483646)) {
            i_st.site = &f_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          for (k = a; k <= last; k++) {
            p_step_size = p_log_out_data[k - 1];
            if (b_h_re > p_step_size) {
              b_h_re = p_step_size;
            }
          }
        }
      }
      p_step_size =
          base_step_size *
          muDoubleScalarMin(muDoubleScalarHypot(dg_h_re, dg_h_im),
                            b_h_re / muDoubleScalarHypot(F_h_re, F_h_im));
      h_re += p_step_size * F_h_re;
      h_im += p_step_size * F_h_im;
      if (((int32_T)n - 1 < 1) || ((int32_T)n - 1 > p_log->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)n - 1, 1, p_log->size[0],
                                      &o_emlrtBCI, (emlrtCTX)sp);
      }
      if (((int32_T)n < 1) || ((int32_T)n > p_log->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)n, 1, p_log->size[0],
                                      &p_emlrtBCI, (emlrtCTX)sp);
      }
      p_log_data[(int32_T)n - 1] = p_log_data[(int32_T)n - 2] + p_step_size;
      if (((int32_T)n < 1) || ((int32_T)n > h_log->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)n, 1, h_log->size[0],
                                      &q_emlrtBCI, (emlrtCTX)sp);
      }
      h_log_data[(int32_T)n - 1].re = h_re;
      if (((int32_T)n < 1) || ((int32_T)n > h_log->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)n, 1, h_log->size[0],
                                      &q_emlrtBCI, (emlrtCTX)sp);
      }
      h_log_data[(int32_T)n - 1].im = h_im;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
      if (n_max == n) {
        *success = false;
        exitg1 = 1;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  emxFree_creal_T(sp, &x);
  emxFree_real_T(sp, &varargin_1);
  emxFree_creal_T(sp, &ddgCoeffs);
  emxFree_creal_T(sp, &dgCoeffs);
  if (1 > p_log->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, p_log->size[0], &g_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (((int32_T)n < 1) || ((int32_T)n > p_log->size[0])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)n, 1, p_log->size[0], &h_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  iv[0] = 1;
  iv[1] = (int32_T)n;
  st.site = &b_emlrtRSI;
  indexShapeCheck(&st, p_log->size[0], iv);
  nx = (int32_T)n;
  a = p_log_out->size[0];
  p_log_out->size[0] = (int32_T)n;
  emxEnsureCapacity_real_T(sp, p_log_out, a, &k_emlrtRTEI);
  p_log_out_data = p_log_out->data;
  for (a = 0; a < nx; a++) {
    p_log_out_data[a] = p_log_data[a];
  }
  emxFree_real_T(sp, &p_log);
  if (1 > h_log->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, h_log->size[0], &k_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (((int32_T)n < 1) || ((int32_T)n > h_log->size[0])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)n, 1, h_log->size[0], &l_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  iv[0] = 1;
  iv[1] = (int32_T)n;
  st.site = &emlrtRSI;
  indexShapeCheck(&st, h_log->size[0], iv);
  nx = (int32_T)n;
  a = h_log_out->size[0];
  h_log_out->size[0] = (int32_T)n;
  emxEnsureCapacity_creal_T(sp, h_log_out, a, &l_emlrtRTEI);
  h_log_out_data = h_log_out->data;
  for (a = 0; a < nx; a++) {
    h_log_out_data[a] = h_log_data[a];
  }
  emxFree_creal_T(sp, &h_log);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (SDpathODEuler_extend_coarse_path.c) */
