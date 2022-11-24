/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDpathODEuler_v2.c
 *
 * Code generation for function 'SDpathODEuler_v2'
 *
 */

/* Include files */
#include "SDpathODEuler_v2.h"
#include "SDpathODEuler_v2_data.h"
#include "SDpathODEuler_v2_emxutil.h"
#include "SDpathODEuler_v2_types.h"
#include "abs.h"
#include "angle.h"
#include "beyondNoReturn.h"
#include "eml_int_forloop_overflow_check.h"
#include "exp.h"
#include "indexShapeCheck.h"
#include "mod.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    65,                 /* lineNo */
    "SDpathODEuler_v2", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pathName
                                                                          */
};

static emlrtRSInfo b_emlrtRSI = {
    63,                 /* lineNo */
    "SDpathODEuler_v2", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pathName
                                                                          */
};

static emlrtRSInfo c_emlrtRSI = {
    62,                 /* lineNo */
    "SDpathODEuler_v2", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pathName
                                                                          */
};

static emlrtRSInfo d_emlrtRSI = {
    59,                 /* lineNo */
    "SDpathODEuler_v2", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pathName
                                                                          */
};

static emlrtRSInfo e_emlrtRSI = {
    58,                 /* lineNo */
    "SDpathODEuler_v2", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pathName
                                                                          */
};

static emlrtRSInfo f_emlrtRSI = {
    48,                 /* lineNo */
    "SDpathODEuler_v2", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pathName
                                                                          */
};

static emlrtRSInfo g_emlrtRSI = {
    43,                 /* lineNo */
    "SDpathODEuler_v2", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pathName
                                                                          */
};

static emlrtRSInfo h_emlrtRSI = {
    32,                 /* lineNo */
    "SDpathODEuler_v2", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pathName
                                                                          */
};

static emlrtRSInfo i_emlrtRSI = {
    24,                 /* lineNo */
    "SDpathODEuler_v2", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pathName
                                                                          */
};

static emlrtRSInfo j_emlrtRSI = {
    23,                 /* lineNo */
    "SDpathODEuler_v2", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    l_emlrtRSI =
        {
            63,                               /* lineNo */
            "function_handle/parenReference", /* fcnName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
            "function_handle.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    34, /* lineNo */
    "@(h)inAball(h,SPs,cover_radii)||beyondNoReturn_v2(h,valleys,gCoeffs,r_"
    "star)", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pathName
                                                                          */
};

static emlrtRSInfo n_emlrtRSI = {
    12,                  /* lineNo */
    "beyondNoReturn_v2", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn_v2.m" /* pathName
                                                                           */
};

static emlrtRSInfo o_emlrtRSI = {
    16,                  /* lineNo */
    "beyondNoReturn_v2", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn_v2.m" /* pathName
                                                                           */
};

static emlrtRSInfo p_emlrtRSI = {
    21,                  /* lineNo */
    "beyondNoReturn_v2", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn_v2.m" /* pathName
                                                                           */
};

static emlrtRSInfo q_emlrtRSI = {
    23,                  /* lineNo */
    "beyondNoReturn_v2", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn_v2.m" /* pathName
                                                                           */
};

static emlrtRSInfo kb_emlrtRSI = {
    44,                                                          /* lineNo */
    "mpower",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/mpower.m" /* pathName */
};

static emlrtRSInfo lb_emlrtRSI = {
    71,                                                      /* lineNo */
    "power",                                                 /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/ops/power.m" /* pathName */
};

static emlrtBCInfo
    emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            9,                     /* lineNo */
            27,                    /* colNo */
            "coeffs",              /* aName */
            "getNoReturnConstant", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "getNoReturnConstant.m", /* pName */
            0                        /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    23,                 /* lineNo */
    24,                 /* colNo */
    "gCoeffs",          /* aName */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    23,                 /* lineNo */
    27,                 /* colNo */
    "gCoeffs",          /* aName */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtECInfo emlrtECI = {
    2,                  /* nDims */
    23,                 /* lineNo */
    16,                 /* colNo */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pName
                                                                          */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    24,                 /* lineNo */
    26,                 /* colNo */
    "dgCoeffs",         /* aName */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    24,                 /* lineNo */
    29,                 /* colNo */
    "dgCoeffs",         /* aName */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtECInfo b_emlrtECI = {
    2,                  /* nDims */
    24,                 /* lineNo */
    17,                 /* colNo */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pName
                                                                          */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    31,                 /* lineNo */
    29,                 /* colNo */
    "gCoeffs",          /* aName */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    40,                 /* lineNo */
    11,                 /* colNo */
    "p_log",            /* aName */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    58,                 /* lineNo */
    23,                 /* colNo */
    "p_log",            /* aName */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    58,                 /* lineNo */
    25,                 /* colNo */
    "p_log",            /* aName */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    41,                 /* lineNo */
    11,                 /* colNo */
    "h_log",            /* aName */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    59,                 /* lineNo */
    23,                 /* colNo */
    "h_log",            /* aName */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    59,                 /* lineNo */
    25,                 /* colNo */
    "h_log",            /* aName */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    15,                 /* lineNo */
    24,                 /* colNo */
    "cover_radii",      /* aName */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    16,                 /* lineNo */
    17,                 /* colNo */
    "SPs",              /* aName */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo
    o_emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            7,                     /* lineNo */
            30,                    /* colNo */
            "coeffs",              /* aName */
            "getNoReturnConstant", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "getNoReturnConstant.m", /* pName */
            0                        /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    38,                 /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m", /* pName
                                                                           */
    1 /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    38,                 /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m", /* pName
                                                                           */
    4 /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    39,                 /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m", /* pName
                                                                           */
    1 /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    39,                 /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m", /* pName
                                                                           */
    4 /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                                                          /* iFirst */
    -1,                                                          /* iLast */
    6,                                                           /* lineNo */
    32,                                                          /* colNo */
    "cover_centres",                                             /* aName */
    "inAball",                                                   /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/topology/inAball.m", /* pName */
    0                                                            /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                                                          /* iFirst */
    -1,                                                          /* iLast */
    6,                                                           /* lineNo */
    52,                                                          /* colNo */
    "cover_radii",                                               /* aName */
    "inAball",                                                   /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/topology/inAball.m", /* pName */
    0                                                            /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    51,                 /* lineNo */
    26,                 /* colNo */
    "p_log",            /* aName */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    51,                 /* lineNo */
    15,                 /* colNo */
    "p_log",            /* aName */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    52,                 /* lineNo */
    15,                 /* colNo */
    "h_log",            /* aName */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    13,                  /* lineNo */
    25,                  /* colNo */
    "V",                 /* aName */
    "beyondNoReturn_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn_v2.m", /* pName
                                                                            */
    0 /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    21,                  /* lineNo */
    36,                  /* colNo */
    "g_coeffs",          /* aName */
    "beyondNoReturn_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn_v2.m", /* pName
                                                                            */
    0 /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    23,                  /* lineNo */
    40,                  /* colNo */
    "g_coeffs",          /* aName */
    "beyondNoReturn_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn_v2.m", /* pName
                                                                            */
    0 /* checkKind */
};

static emlrtRTEInfo e_emlrtRTEI = {
    9,                  /* lineNo */
    9,                  /* colNo */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pName
                                                                          */
};

static emlrtRTEInfo f_emlrtRTEI = {
    10,                 /* lineNo */
    9,                  /* colNo */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pName
                                                                          */
};

static emlrtRTEInfo g_emlrtRTEI = {
    23,                 /* lineNo */
    37,                 /* colNo */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pName
                                                                          */
};

static emlrtRTEInfo h_emlrtRTEI = {
    23,                 /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pName
                                                                          */
};

static emlrtRTEInfo i_emlrtRTEI = {
    24,                 /* lineNo */
    39,                 /* colNo */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pName
                                                                          */
};

static emlrtRTEInfo j_emlrtRTEI = {
    24,                 /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pName
                                                                          */
};

static emlrtRTEInfo k_emlrtRTEI = {
    38,                 /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pName
                                                                          */
};

static emlrtRTEInfo l_emlrtRTEI = {
    39,                 /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pName
                                                                          */
};

static emlrtRTEInfo m_emlrtRTEI = {
    58,                 /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pName
                                                                          */
};

static emlrtRTEInfo n_emlrtRTEI = {
    59,                 /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pName
                                                                          */
};

static emlrtRTEInfo o_emlrtRTEI = {
    48,                 /* lineNo */
    68,                 /* colNo */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pName
                                                                          */
};

static emlrtRTEInfo p_emlrtRTEI = {
    2,                  /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pName
                                                                          */
};

static emlrtRTEInfo q_emlrtRTEI = {
    48,                 /* lineNo */
    64,                 /* colNo */
    "SDpathODEuler_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v2.m" /* pName
                                                                          */
};

static emlrtRTEInfo r_emlrtRTEI = {
    12,                  /* lineNo */
    31,                  /* colNo */
    "beyondNoReturn_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn_v2.m" /* pName
                                                                           */
};

static emlrtRTEInfo s_emlrtRTEI = {
    12,                  /* lineNo */
    38,                  /* colNo */
    "beyondNoReturn_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn_v2.m" /* pName
                                                                           */
};

/* Function Declarations */
static boolean_T SDpathODEuler_v2_anonFcn3(const emlrtStack *sp,
                                           const emxArray_creal_T *SPs,
                                           const emxArray_real_T *cover_radii,
                                           const emxArray_creal_T *valleys,
                                           const emxArray_creal_T *gCoeffs,
                                           real_T r_star, const creal_T h);

static void binary_expand_op(const emlrtStack *sp, emxArray_creal_T *ddgCoeffs,
                             const emxArray_creal_T *dgCoeffs, int32_T i1,
                             const emxArray_real_T *r1);

/* Function Definitions */
static boolean_T SDpathODEuler_v2_anonFcn3(const emlrtStack *sp,
                                           const emxArray_creal_T *SPs,
                                           const emxArray_real_T *cover_radii,
                                           const emxArray_creal_T *valleys,
                                           const emxArray_creal_T *gCoeffs,
                                           real_T r_star, const creal_T h)
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
  emxArray_creal_T *r;
  emxArray_real_T *b;
  const creal_T *SPs_data;
  const creal_T *gCoeffs_data;
  const creal_T *valleys_data;
  creal_T *r1;
  real_T varargin_1[3];
  const real_T *cover_radii_data;
  real_T R;
  real_T b_r;
  real_T x_re;
  real_T x_re_tmp;
  real_T *b_data;
  int32_T a;
  int32_T idx;
  int32_T k;
  int32_T last;
  boolean_T exitg1;
  boolean_T value;
  boolean_T varargout_1;
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
  gCoeffs_data = gCoeffs->data;
  valleys_data = valleys->data;
  cover_radii_data = cover_radii->data;
  SPs_data = SPs->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &m_emlrtRSI;
  /* returns 1 if SD path is in a ball, 0 otherwise */
  value = false;
  last = 1;
  exitg1 = false;
  while ((!exitg1) && (last - 1 <= SPs->size[0] - 1)) {
    if ((last < 1) || (last > SPs->size[0])) {
      emlrtDynamicBoundsCheckR2012b(last, 1, SPs->size[0], &p_emlrtBCI, &st);
    }
    if (last > SPs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(last, 1, SPs->size[0], &p_emlrtBCI, &st);
    }
    if (last > cover_radii->size[0]) {
      emlrtDynamicBoundsCheckR2012b(last, 1, cover_radii->size[0], &q_emlrtBCI,
                                    &st);
    }
    if (muDoubleScalarHypot(h.re - SPs_data[last - 1].re,
                            h.im - SPs_data[last - 1].im) <
        cover_radii_data[last - 1]) {
      value = true;
      exitg1 = true;
    } else {
      last++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
  }
  emxInit_real_T(sp, &b, 1, &s_emlrtRTEI);
  emxInit_creal_T(sp, &r, 1, &r_emlrtRTEI);
  if (value) {
    varargout_1 = true;
  } else {
    st.site = &m_emlrtRSI;
    /* function corresponding to an event which would halt ODE solve, because SD
     */
    /* path is at 'point of no return'. */
    /*  the 'no return test' */
    value = false;
    R = muDoubleScalarHypot(h.re, h.im);
    if (R > r_star) {
      /*  first test, based on length of z */
      /*  now check that path is sufficiently close to monomial SD path */
      b_st.site = &n_emlrtRSI;
      angle(&b_st, valleys, b);
      b_data = b->data;
      x_re_tmp = muDoubleScalarAtan2(h.im, h.re);
      x_re = x_re_tmp * 0.0;
      b_st.site = &n_emlrtRSI;
      if (x_re_tmp == 0.0) {
        x_re = muDoubleScalarExp(x_re);
        b_r = 0.0;
      } else {
        b_r = muDoubleScalarExp(x_re / 2.0);
        x_re = b_r * (b_r * muDoubleScalarCos(x_re_tmp));
        b_r *= b_r * muDoubleScalarSin(x_re_tmp);
      }
      a = r->size[0];
      r->size[0] = b->size[0];
      emxEnsureCapacity_creal_T(&b_st, r, a, &r_emlrtRTEI);
      r1 = r->data;
      last = b->size[0];
      for (a = 0; a < last; a++) {
        r1[a].re = b_data[a] * 0.0;
        r1[a].im = b_data[a];
      }
      c_st.site = &n_emlrtRSI;
      b_exp(&c_st, r);
      r1 = r->data;
      last = r->size[0];
      for (a = 0; a < last; a++) {
        r1[a].re -= x_re;
        r1[a].im -= b_r;
      }
      c_st.site = &n_emlrtRSI;
      b_abs(&c_st, r, b);
      b_data = b->data;
      c_st.site = &w_emlrtRSI;
      d_st.site = &x_emlrtRSI;
      e_st.site = &y_emlrtRSI;
      if (b->size[0] < 1) {
        emlrtErrorWithMessageIdR2018a(
            &e_st, &b_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
            "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }
      f_st.site = &ab_emlrtRSI;
      last = b->size[0];
      if (b->size[0] <= 2) {
        if (b->size[0] == 1) {
          idx = 1;
        } else if ((b_data[0] > b_data[1]) ||
                   (muDoubleScalarIsNaN(b_data[0]) &&
                    (!muDoubleScalarIsNaN(b_data[1])))) {
          idx = 2;
        } else {
          idx = 1;
        }
      } else {
        g_st.site = &cb_emlrtRSI;
        if (!muDoubleScalarIsNaN(b_data[0])) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &db_emlrtRSI;
          if (b->size[0] > 2147483646) {
            i_st.site = &k_emlrtRSI;
            check_forloop_overflow_error(&i_st);
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
          g_st.site = &bb_emlrtRSI;
          b_r = b_data[idx - 1];
          a = idx + 1;
          h_st.site = &eb_emlrtRSI;
          if ((idx + 1 <= b->size[0]) && (b->size[0] > 2147483646)) {
            i_st.site = &k_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          for (k = a; k <= last; k++) {
            x_re = b_data[k - 1];
            if (b_r > x_re) {
              b_r = x_re;
              idx = k;
            }
          }
        }
      }
      if ((idx < 1) || (idx > valleys->size[0])) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, valleys->size[0], &u_emlrtBCI,
                                      &st);
      }
      b_st.site = &o_emlrtRSI;
      b_r = b_mod(x_re_tmp) -
            b_mod(muDoubleScalarAtan2(valleys_data[idx - 1].im,
                                      valleys_data[idx - 1].re));
      varargin_1[0] = muDoubleScalarAbs(b_r);
      varargin_1[1] = muDoubleScalarAbs(b_r - 6.2831853071795862);
      varargin_1[2] = muDoubleScalarAbs(b_r + 6.2831853071795862);
      c_st.site = &fb_emlrtRSI;
      d_st.site = &gb_emlrtRSI;
      e_st.site = &hb_emlrtRSI;
      f_st.site = &ib_emlrtRSI;
      g_st.site = &jb_emlrtRSI;
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
        b_r = varargin_1[0];
      } else {
        h_st.site = &bb_emlrtRSI;
        b_r = varargin_1[idx - 1];
        a = idx + 1;
        for (k = a; k < 4; k++) {
          x_re = varargin_1[k - 1];
          if (b_r > x_re) {
            b_r = x_re;
          }
        }
      }
      /*          theta_diff = max(theta_in_diff,pi/(4*order)); */
      if (b_r < 3.1415926535897931 / (2.0 * (real_T)valleys->size[0])) {
        /*  now check Dave's refined polynomial condition */
        if (1 > gCoeffs->size[1]) {
          emlrtDynamicBoundsCheckR2012b(1, 1, gCoeffs->size[1], &v_emlrtBCI,
                                        &st);
        }
        b_st.site = &p_emlrtRSI;
        c_st.site = &kb_emlrtRSI;
        d_st.site = &lb_emlrtRSI;
        b_r = (real_T)valleys->size[0] *
              muDoubleScalarHypot(gCoeffs_data[0].re, gCoeffs_data[0].im) *
              muDoubleScalarPower(R, (real_T)valleys->size[0] - 1.0) *
              muDoubleScalarMin(
                  0.70710678118654746,
                  muDoubleScalarCos((real_T)valleys->size[0] * b_r));
        last = 0;
        exitg1 = false;
        while ((!exitg1) && (last <= valleys->size[0] - 2)) {
          a = (gCoeffs->size[1] - last) - 1;
          if ((a < 1) || (a > gCoeffs->size[1])) {
            emlrtDynamicBoundsCheckR2012b(a, 1, gCoeffs->size[1], &w_emlrtBCI,
                                          &st);
          }
          idx = (gCoeffs->size[1] - last) - 1;
          if ((idx < 1) || (idx > gCoeffs->size[1])) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, gCoeffs->size[1], &w_emlrtBCI,
                                          &st);
          }
          b_st.site = &q_emlrtRSI;
          c_st.site = &kb_emlrtRSI;
          d_st.site = &lb_emlrtRSI;
          b_r -= ((real_T)last + 1.0) *
                 muDoubleScalarHypot(gCoeffs_data[a - 1].re,
                                     gCoeffs_data[idx - 1].im) *
                 muDoubleScalarPower(R, ((real_T)last + 1.0) - 1.0);
          if (b_r <= 0.0) {
            /*  G isn't getting any bigger */
            exitg1 = true;
          } else {
            last++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(&st);
            }
          }
        }
        value = (b_r > 0.0);
      }
    }
    if (value) {
      varargout_1 = true;
    } else {
      varargout_1 = false;
    }
  }
  emxFree_creal_T(sp, &r);
  emxFree_real_T(sp, &b);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return varargout_1;
}

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
  emxEnsureCapacity_creal_T(sp, ddgCoeffs, i, &j_emlrtRTEI);
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

void SDpathODEuler_v2(const emlrtStack *sp, const creal_T h0,
                      const emxArray_creal_T *gCoeffs, emxArray_creal_T *SPs,
                      emxArray_real_T *cover_radii,
                      const emxArray_creal_T *valleys, real_T base_step_size,
                      int64_T n_max, real_T r_star, emxArray_real_T *p_log_out,
                      emxArray_creal_T *h_log_out, real_T valley_index_data[],
                      int32_T valley_index_size[2], real_T ball_index_data[],
                      int32_T ball_index_size[2], boolean_T *success)
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
  emxArray_creal_T *b_SPs;
  emxArray_creal_T *ddgCoeffs;
  emxArray_creal_T *dgCoeffs;
  emxArray_creal_T *h_log;
  emxArray_real_T *p_log;
  emxArray_real_T *r;
  emxArray_real_T *varargin_1;
  const creal_T *gCoeffs_data;
  creal_T h;
  creal_T *SPs_data;
  creal_T *b_SPs_data;
  creal_T *ddgCoeffs_data;
  creal_T *dgCoeffs_data;
  creal_T *h_log_data;
  real_T Cnr;
  real_T F_h_im;
  real_T F_h_re;
  real_T b_dg_h_re;
  real_T brm;
  real_T ddg_h_im;
  real_T ddg_h_re;
  real_T dg_h_im;
  real_T dg_h_re;
  real_T h_re;
  real_T p_step_size;
  real_T *cover_radii_data;
  real_T *p_log_data;
  real_T *p_log_out_data;
  int32_T iv[2];
  int32_T exitg1;
  int32_T i;
  int32_T idx;
  int32_T j;
  int32_T k;
  int32_T last;
  uint32_T n;
  boolean_T exitg2;
  boolean_T varargout_1;
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
  cover_radii_data = cover_radii->data;
  SPs_data = SPs->data;
  gCoeffs_data = gCoeffs->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /* computes NSD path h(p) and h'(p) */
  /* excluded_SPs_indices */
  valley_index_size[0] = 0;
  valley_index_size[1] = 0;
  ball_index_size[0] = 0;
  ball_index_size[1] = 0;
  *success = true;
  if (SPs->size[0] == 0) {
    i = SPs->size[0];
    SPs->size[0] = 1;
    emxEnsureCapacity_creal_T(sp, SPs, i, &e_emlrtRTEI);
    SPs_data = SPs->data;
    SPs_data[0].re = rtInf;
    SPs_data[0].im = 0.0;
    /*  bodge to speed things up further down */
    i = cover_radii->size[0];
    cover_radii->size[0] = 1;
    emxEnsureCapacity_real_T(sp, cover_radii, i, &f_emlrtRTEI);
    cover_radii_data = cover_radii->data;
    cover_radii_data[0] = 0.0;
  }
  i = SPs->size[0];
  for (last = 0; last < i; last++) {
    /*  another bodge to stop stationary points being treated like critical */
    /*  points */
    if (last + 1 > cover_radii->size[0]) {
      emlrtDynamicBoundsCheckR2012b(last + 1, 1, cover_radii->size[0],
                                    &m_emlrtBCI, (emlrtCTX)sp);
    }
    if (cover_radii_data[last] == 0.0) {
      /*  || ismember(n,excluded_SPs_indices) */
      if (last + 1 > SPs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(last + 1, 1, SPs->size[0], &n_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SPs_data[last].re = rtInf;
      if (last + 1 > SPs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(last + 1, 1, SPs->size[0], &n_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SPs_data[last].im = 0.0;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  /*      n_max = 1000; */
  /* ODE for path of steepest descent: */
  if (1 > gCoeffs->size[1] - 1) {
    last = 0;
  } else {
    if (1 > gCoeffs->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, gCoeffs->size[1], &b_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if ((gCoeffs->size[1] - 1 < 1) ||
        (gCoeffs->size[1] - 1 > gCoeffs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(gCoeffs->size[1] - 1, 1, gCoeffs->size[1],
                                    &c_emlrtBCI, (emlrtCTX)sp);
    }
    last = gCoeffs->size[1] - 1;
  }
  st.site = &j_emlrtRSI;
  emxInit_real_T(&st, &r, 2, &p_emlrtRTEI);
  p_log_out_data = r->data;
  if (gCoeffs->size[1] - 1 < 1) {
    r->size[0] = 1;
    r->size[1] = 0;
  } else {
    i = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = (int32_T) - (1.0 - ((real_T)gCoeffs->size[1] - 1.0)) + 1;
    emxEnsureCapacity_real_T(&st, r, i, &g_emlrtRTEI);
    p_log_out_data = r->data;
    idx = (int32_T) - (1.0 - ((real_T)gCoeffs->size[1] - 1.0));
    for (i = 0; i <= idx; i++) {
      p_log_out_data[i] = ((real_T)gCoeffs->size[1] - 1.0) - (real_T)i;
    }
  }
  if ((last != r->size[1]) && ((last != 1) && (r->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(last, r->size[1], &emlrtECI, (emlrtCTX)sp);
  }
  emxInit_creal_T(sp, &dgCoeffs, 2, &h_emlrtRTEI);
  if (last == r->size[1]) {
    i = dgCoeffs->size[0] * dgCoeffs->size[1];
    dgCoeffs->size[0] = 1;
    dgCoeffs->size[1] = last;
    emxEnsureCapacity_creal_T(sp, dgCoeffs, i, &h_emlrtRTEI);
    dgCoeffs_data = dgCoeffs->data;
    for (i = 0; i < last; i++) {
      dgCoeffs_data[i].re = p_log_out_data[i] * gCoeffs_data[i].re;
      dgCoeffs_data[i].im = p_log_out_data[i] * gCoeffs_data[i].im;
    }
  } else {
    st.site = &j_emlrtRSI;
    binary_expand_op(&st, dgCoeffs, gCoeffs, last - 1, r);
    dgCoeffs_data = dgCoeffs->data;
  }
  if (1 > dgCoeffs->size[1] - 1) {
    last = 0;
  } else {
    if (1 > dgCoeffs->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, dgCoeffs->size[1], &d_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if ((dgCoeffs->size[1] - 1 < 1) ||
        (dgCoeffs->size[1] - 1 > dgCoeffs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(dgCoeffs->size[1] - 1, 1, dgCoeffs->size[1],
                                    &e_emlrtBCI, (emlrtCTX)sp);
    }
    last = dgCoeffs->size[1] - 1;
  }
  st.site = &i_emlrtRSI;
  if (gCoeffs->size[1] - 2 < 1) {
    r->size[0] = 1;
    r->size[1] = 0;
  } else {
    i = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] =
        (int32_T) - (1.0 - (((real_T)gCoeffs->size[1] - 1.0) - 1.0)) + 1;
    emxEnsureCapacity_real_T(&st, r, i, &i_emlrtRTEI);
    p_log_out_data = r->data;
    idx = (int32_T) - (1.0 - (((real_T)gCoeffs->size[1] - 1.0) - 1.0));
    for (i = 0; i <= idx; i++) {
      p_log_out_data[i] = (((real_T)gCoeffs->size[1] - 1.0) - 1.0) - (real_T)i;
    }
  }
  if ((last != r->size[1]) && ((last != 1) && (r->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(last, r->size[1], &b_emlrtECI, (emlrtCTX)sp);
  }
  emxInit_creal_T(sp, &ddgCoeffs, 2, &j_emlrtRTEI);
  if (last == r->size[1]) {
    i = ddgCoeffs->size[0] * ddgCoeffs->size[1];
    ddgCoeffs->size[0] = 1;
    ddgCoeffs->size[1] = last;
    emxEnsureCapacity_creal_T(sp, ddgCoeffs, i, &j_emlrtRTEI);
    ddgCoeffs_data = ddgCoeffs->data;
    for (i = 0; i < last; i++) {
      ddgCoeffs_data[i].re = p_log_out_data[i] * dgCoeffs_data[i].re;
      ddgCoeffs_data[i].im = p_log_out_data[i] * dgCoeffs_data[i].im;
    }
  } else {
    st.site = &i_emlrtRSI;
    binary_expand_op(&st, ddgCoeffs, dgCoeffs, last - 1, r);
    ddgCoeffs_data = ddgCoeffs->data;
  }
  emxFree_real_T(sp, &r);
  /*  may not need this yet - but it's the local error est */
  /*  get parameters for halting zones */
  if (1 > gCoeffs->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, gCoeffs->size[1], &f_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  st.site = &h_emlrtRSI;
  /*  computes the constant which determines how large / narrow the SD path */
  /*  must be before it cannot leave the complex segment */
  Cnr = 0.0;
  i = gCoeffs->size[1];
  for (j = 0; j <= i - 3; j++) {
    last = (gCoeffs->size[1] - j) - 1;
    if ((last < 1) || (last > gCoeffs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(last, 1, gCoeffs->size[1], &o_emlrtBCI,
                                    &st);
    }
    idx = (gCoeffs->size[1] - j) - 1;
    if ((idx < 1) || (idx > gCoeffs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, gCoeffs->size[1], &o_emlrtBCI, &st);
    }
    Cnr += muDoubleScalarHypot(((real_T)j + 1.0) * gCoeffs_data[last - 1].re,
                               ((real_T)j + 1.0) * gCoeffs_data[idx - 1].im);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  if (1 > gCoeffs->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, gCoeffs->size[1], &emlrtBCI, &st);
  }
  emxInit_real_T(&st, &p_log, 1, &k_emlrtRTEI);
  Cnr /= ((real_T)gCoeffs->size[1] - 1.0) *
         muDoubleScalarHypot(gCoeffs_data[0].re, gCoeffs_data[0].im);
  /*  C =
   * norm(sum(fliplr(1:(deg-1)).*abs(coeffs(1:(deg-1))))/(deg*abs(coeffs(1))));
   */
  /* beyondNoReturn_v2(h,Cnr,argBeta,valleys); */
  /*  main loop */
  h = h0;
  if (!(n_max >= 0.0)) {
    emlrtNonNegativeCheckR2012b((real_T)n_max, &b_emlrtDCI, (emlrtCTX)sp);
  }
  p_step_size = (real_T)(int64_T)muDoubleScalarFloor((real_T)n_max);
  if (p_step_size != (int32_T)muDoubleScalarFloor(p_step_size)) {
    emlrtIntegerCheckR2012b(p_step_size, &emlrtDCI, (emlrtCTX)sp);
  }
  i = p_log->size[0];
  p_log->size[0] = (int32_T)(int64_T)muDoubleScalarFloor(p_step_size);
  emxEnsureCapacity_real_T(sp, p_log, i, &k_emlrtRTEI);
  p_log_data = p_log->data;
  if (!(n_max >= 0.0)) {
    emlrtNonNegativeCheckR2012b((real_T)n_max, &b_emlrtDCI, (emlrtCTX)sp);
  }
  if (p_step_size != (int32_T)muDoubleScalarFloor(p_step_size)) {
    emlrtIntegerCheckR2012b(p_step_size, &emlrtDCI, (emlrtCTX)sp);
  }
  last = (int32_T)(int64_T)muDoubleScalarFloor(p_step_size);
  for (i = 0; i < last; i++) {
    p_log_data[i] = 0.0;
  }
  emxInit_creal_T(sp, &h_log, 1, &l_emlrtRTEI);
  if (!(n_max >= 0.0)) {
    emlrtNonNegativeCheckR2012b((real_T)n_max, &d_emlrtDCI, (emlrtCTX)sp);
  }
  if (p_step_size != (int32_T)muDoubleScalarFloor(p_step_size)) {
    emlrtIntegerCheckR2012b(p_step_size, &c_emlrtDCI, (emlrtCTX)sp);
  }
  i = h_log->size[0];
  h_log->size[0] = (int32_T)(int64_T)muDoubleScalarFloor(p_step_size);
  emxEnsureCapacity_creal_T(sp, h_log, i, &l_emlrtRTEI);
  h_log_data = h_log->data;
  if (!(n_max >= 0.0)) {
    emlrtNonNegativeCheckR2012b((real_T)n_max, &d_emlrtDCI, (emlrtCTX)sp);
  }
  if (p_step_size != (int32_T)muDoubleScalarFloor(p_step_size)) {
    emlrtIntegerCheckR2012b(p_step_size, &c_emlrtDCI, (emlrtCTX)sp);
  }
  last = (int32_T)(int64_T)muDoubleScalarFloor(p_step_size);
  for (i = 0; i < last; i++) {
    h_log_data[i].re = 0.0;
    h_log_data[i].im = 2.2204460492503131E-16;
  }
  if (1 > (int32_T)n_max) {
    emlrtDynamicBoundsCheckR2012b(1, 1, (int32_T)n_max, &g_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  p_log_data[0] = 0.0;
  if (1 > h_log->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, h_log->size[0], &j_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  h_log_data[0] = h0;
  n = 1U;
  emxInit_real_T(sp, &varargin_1, 1, &q_emlrtRTEI);
  emxInit_creal_T(sp, &b_SPs, 1, &o_emlrtRTEI);
  do {
    exitg1 = 0;
    st.site = &g_emlrtRSI;
    b_st.site = &l_emlrtRSI;
    varargout_1 = SDpathODEuler_v2_anonFcn3(&b_st, SPs, cover_radii, valleys,
                                            gCoeffs, r_star, h);
    if (!varargout_1) {
      n++;
      if (dgCoeffs->size[1] != 0) {
        dg_h_re = dgCoeffs_data[0].re;
        dg_h_im = dgCoeffs_data[0].im;
        i = dgCoeffs->size[1];
        for (k = 0; k <= i - 2; k++) {
          h_re = h.re * dg_h_re - h.im * dg_h_im;
          p_step_size = h.re * dg_h_im + h.im * dg_h_re;
          dg_h_re = h_re + dgCoeffs_data[k + 1].re;
          dg_h_im = p_step_size + dgCoeffs_data[k + 1].im;
        }
      }
      if (ddgCoeffs->size[1] != 0) {
        ddg_h_re = ddgCoeffs_data[0].re;
        ddg_h_im = ddgCoeffs_data[0].im;
        i = ddgCoeffs->size[1];
        for (k = 0; k <= i - 2; k++) {
          h_re = h.re * ddg_h_re - h.im * ddg_h_im;
          p_step_size = h.re * ddg_h_im + h.im * ddg_h_re;
          ddg_h_re = h_re + ddgCoeffs_data[k + 1].re;
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
          h_re = dg_h_re + p_step_size * dg_h_im;
          F_h_re = p_step_size / h_re;
          F_h_im = (1.0 - p_step_size * 0.0) / h_re;
        } else if (p_step_size == brm) {
          if (dg_h_re > 0.0) {
            p_step_size = 0.5;
          } else {
            p_step_size = -0.5;
          }
          if (dg_h_im > 0.0) {
            h_re = 0.5;
          } else {
            h_re = -0.5;
          }
          F_h_re = (0.0 * p_step_size + h_re) / brm;
          F_h_im = (p_step_size - 0.0 * h_re) / brm;
        } else {
          p_step_size = dg_h_re / dg_h_im;
          h_re = dg_h_im + p_step_size * dg_h_re;
          F_h_re = (p_step_size * 0.0 + 1.0) / h_re;
          F_h_im = p_step_size / h_re;
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
          h_re = ddg_h_re + p_step_size * ddg_h_im;
          dg_h_re = (b_dg_h_re + p_step_size * dg_h_im) / h_re;
          dg_h_im = (dg_h_im - p_step_size * b_dg_h_re) / h_re;
        } else if (p_step_size == brm) {
          if (ddg_h_re > 0.0) {
            p_step_size = 0.5;
          } else {
            p_step_size = -0.5;
          }
          if (ddg_h_im > 0.0) {
            h_re = 0.5;
          } else {
            h_re = -0.5;
          }
          dg_h_re = (b_dg_h_re * p_step_size + dg_h_im * h_re) / brm;
          dg_h_im = (dg_h_im * p_step_size - b_dg_h_re * h_re) / brm;
        } else {
          p_step_size = ddg_h_re / ddg_h_im;
          h_re = ddg_h_im + p_step_size * ddg_h_re;
          dg_h_re = (p_step_size * b_dg_h_re + dg_h_im) / h_re;
          dg_h_im = (p_step_size * dg_h_im - b_dg_h_re) / h_re;
        }
      }
      st.site = &f_emlrtRSI;
      i = b_SPs->size[0];
      b_SPs->size[0] = SPs->size[0];
      emxEnsureCapacity_creal_T(&st, b_SPs, i, &o_emlrtRTEI);
      b_SPs_data = b_SPs->data;
      last = SPs->size[0];
      for (i = 0; i < last; i++) {
        b_SPs_data[i].re = SPs_data[i].re - h.re;
        b_SPs_data[i].im = SPs_data[i].im - h.im;
      }
      b_st.site = &f_emlrtRSI;
      b_abs(&b_st, b_SPs, varargin_1);
      p_log_out_data = varargin_1->data;
      b_st.site = &fb_emlrtRSI;
      c_st.site = &gb_emlrtRSI;
      d_st.site = &hb_emlrtRSI;
      e_st.site = &ib_emlrtRSI;
      f_st.site = &jb_emlrtRSI;
      last = varargin_1->size[0];
      if (varargin_1->size[0] <= 2) {
        if (varargin_1->size[0] == 1) {
          h_re = p_log_out_data[0];
        } else if ((p_log_out_data[0] >
                    p_log_out_data[varargin_1->size[0] - 1]) ||
                   (muDoubleScalarIsNaN(p_log_out_data[0]) &&
                    (!muDoubleScalarIsNaN(
                        p_log_out_data[varargin_1->size[0] - 1])))) {
          h_re = p_log_out_data[varargin_1->size[0] - 1];
        } else {
          h_re = p_log_out_data[0];
        }
      } else {
        g_st.site = &cb_emlrtRSI;
        if (!muDoubleScalarIsNaN(p_log_out_data[0])) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &db_emlrtRSI;
          if (varargin_1->size[0] > 2147483646) {
            i_st.site = &k_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          k = 2;
          exitg2 = false;
          while ((!exitg2) && (k <= last)) {
            if (!muDoubleScalarIsNaN(p_log_out_data[k - 1])) {
              idx = k;
              exitg2 = true;
            } else {
              k++;
            }
          }
        }
        if (idx == 0) {
          h_re = p_log_out_data[0];
        } else {
          g_st.site = &bb_emlrtRSI;
          h_re = p_log_out_data[idx - 1];
          j = idx + 1;
          h_st.site = &eb_emlrtRSI;
          if ((idx + 1 <= varargin_1->size[0]) &&
              (varargin_1->size[0] > 2147483646)) {
            i_st.site = &k_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          for (k = j; k <= last; k++) {
            p_step_size = p_log_out_data[k - 1];
            if (h_re > p_step_size) {
              h_re = p_step_size;
            }
          }
        }
      }
      p_step_size =
          base_step_size *
          muDoubleScalarMin(muDoubleScalarHypot(dg_h_re, dg_h_im),
                            h_re / muDoubleScalarHypot(F_h_re, F_h_im));
      h.re += p_step_size * F_h_re;
      h.im += p_step_size * F_h_im;
      if (((int32_T)n - 1 < 1) || ((int32_T)n - 1 > p_log->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)n - 1, 1, p_log->size[0],
                                      &r_emlrtBCI, (emlrtCTX)sp);
      }
      if (((int32_T)n < 1) || ((int32_T)n > p_log->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)n, 1, p_log->size[0],
                                      &s_emlrtBCI, (emlrtCTX)sp);
      }
      p_log_data[(int32_T)n - 1] = p_log_data[(int32_T)n - 2] + p_step_size;
      if (((int32_T)n < 1) || ((int32_T)n > h_log->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)n, 1, h_log->size[0],
                                      &t_emlrtBCI, (emlrtCTX)sp);
      }
      h_log_data[(int32_T)n - 1].re = h.re;
      if (((int32_T)n < 1) || ((int32_T)n > h_log->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)n, 1, h_log->size[0],
                                      &t_emlrtBCI, (emlrtCTX)sp);
      }
      h_log_data[(int32_T)n - 1].im = h.im;
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
  emxFree_creal_T(sp, &b_SPs);
  emxFree_real_T(sp, &varargin_1);
  emxFree_creal_T(sp, &ddgCoeffs);
  emxFree_creal_T(sp, &dgCoeffs);
  if (1 > p_log->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, p_log->size[0], &h_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  last = (int32_T)n;
  if (((int32_T)n < 1) || ((int32_T)n > p_log->size[0])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)n, 1, p_log->size[0], &i_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  iv[0] = 1;
  iv[1] = (int32_T)n;
  st.site = &e_emlrtRSI;
  indexShapeCheck(&st, p_log->size[0], iv);
  i = p_log_out->size[0];
  p_log_out->size[0] = (int32_T)n;
  emxEnsureCapacity_real_T(sp, p_log_out, i, &m_emlrtRTEI);
  p_log_out_data = p_log_out->data;
  for (i = 0; i < last; i++) {
    p_log_out_data[i] = p_log_data[i];
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
  st.site = &d_emlrtRSI;
  indexShapeCheck(&st, h_log->size[0], iv);
  i = h_log_out->size[0];
  h_log_out->size[0] = (int32_T)n;
  emxEnsureCapacity_creal_T(sp, h_log_out, i, &n_emlrtRTEI);
  dgCoeffs_data = h_log_out->data;
  for (i = 0; i < last; i++) {
    dgCoeffs_data[i] = h_log_data[i];
  }
  emxFree_creal_T(sp, &h_log);
  if (*success) {
    st.site = &c_emlrtRSI;
    /* returns 1 if SD path is in a ball, 0 otherwise */
    varargout_1 = false;
    last = 1;
    exitg2 = false;
    while ((!exitg2) && (last - 1 <= SPs->size[0] - 1)) {
      if ((last < 1) || (last > SPs->size[0])) {
        emlrtDynamicBoundsCheckR2012b(last, 1, SPs->size[0], &p_emlrtBCI, &st);
      }
      if (last > SPs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(last, 1, SPs->size[0], &p_emlrtBCI, &st);
      }
      if (last > cover_radii->size[0]) {
        emlrtDynamicBoundsCheckR2012b(last, 1, cover_radii->size[0],
                                      &q_emlrtBCI, &st);
      }
      if (muDoubleScalarHypot(h.re - SPs_data[last - 1].re,
                              h.im - SPs_data[last - 1].im) <
          cover_radii_data[last - 1]) {
        varargout_1 = true;
        exitg2 = true;
      } else {
        last++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
    }
    if (varargout_1) {
      st.site = &b_emlrtRSI;
      /* returns 1 if SD path is in a ball, 0 otherwise */
      idx = 0;
      last = 1;
      exitg2 = false;
      while ((!exitg2) && (last - 1 <= SPs->size[0] - 1)) {
        if ((last < 1) || (last > SPs->size[0])) {
          emlrtDynamicBoundsCheckR2012b(last, 1, SPs->size[0], &p_emlrtBCI,
                                        &st);
        }
        if (last > SPs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(last, 1, SPs->size[0], &p_emlrtBCI,
                                        &st);
        }
        if (last > cover_radii->size[0]) {
          emlrtDynamicBoundsCheckR2012b(last, 1, cover_radii->size[0],
                                        &q_emlrtBCI, &st);
        }
        if (muDoubleScalarHypot(h.re - SPs_data[last - 1].re,
                                h.im - SPs_data[last - 1].im) <
            cover_radii_data[last - 1]) {
          idx = last;
          exitg2 = true;
        } else {
          last++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&st);
          }
        }
      }
      ball_index_size[0] = 1;
      ball_index_size[1] = 1;
      ball_index_data[0] = idx;
    } else {
      st.site = &emlrtRSI;
      beyondNoReturn(
          &st, h, Cnr,
          muDoubleScalarAtan2(gCoeffs_data[0].im, gCoeffs_data[0].re), valleys,
          &varargout_1, &p_step_size);
      valley_index_size[0] = 1;
      valley_index_size[1] = 1;
      valley_index_data[0] = p_step_size;
    }
  }
  /*      function [value,v_index] = beyondNoReturnNested(h) */
  /*          %function corresponding to an event which would halt ODE solve,
   * because SD */
  /*          %path is at 'point of no return'. */
  /*           */
  /*          wiggle_room = 0.95; */
  /*           */
  /*          % the 'no return test' */
  /*          order = length(valleys); */
  /*          R = abs(h); */
  /*          theta = mod(angle(h),2*pi); */
  /*          theta_diff = wiggle_room*pi/(2*order); */
  /*       */
  /*          [~,v_index] = min(abs(exp(1i*angle(valleys))-exp(1i*angle(h))));
   */
  /*          v = mod(angle(valleys(v_index)),2*pi); */
  /*       */
  /*          %first check if theta_end is pointing sufficiently close to valley
   */
  /*          theta_L = mod(v-theta_diff,2*pi); */
  /*          theta_R = mod(v+theta_diff,2*pi); */
  /*          in_arc = false; */
  /*          if theta_L<theta_R */
  /*              if theta_L<theta && theta< theta_R */
  /*                  in_arc = true; */
  /*              end */
  /*          else % arc endpoints are either side of zero=2pi */
  /*              if theta_L<theta % case where theta_L is to left of zero=2pi
   */
  /*                  in_arc = true; */
  /*              elseif theta<theta_R % case where theta_L is to right of
   * zero=2pi */
  /*                  in_arc = true; */
  /*              end */
  /*          end */
  /*       */
  /*          if in_arc ... */
  /*              && R>1 &&
   * R*min(sin(order*(v+theta_diff+argBeta/order)),cos(order*(v-theta_diff+argBeta/order)))>Cnr...
   */
  /*              && theta_diff<pi/(2*order) */
  /*              value = true; */
  /*          else */
  /*              value = false; */
  /*          end */
  /*      %     end */
  /*      end */
  /*   */
  /*      function value = inAballNested(h) */
  /*          value = false; */
  /*          for index = 1:length(SPs) */
  /*              if abs(h-SPs(index))<cover_radii(index) */
  /*                  value = true; */
  /*                  break; */
  /*              end */
  /*          end */
  /*      end */
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (SDpathODEuler_v2.c) */
