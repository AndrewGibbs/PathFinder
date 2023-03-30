/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDpathODEuler_v3.c
 *
 * Code generation for function 'SDpathODEuler_v3'
 *
 */

/* Include files */
#include "SDpathODEuler_v3.h"
#include "SDpathODEuler_v3_data.h"
#include "SDpathODEuler_v3_emxutil.h"
#include "SDpathODEuler_v3_types.h"
#include "abs.h"
#include "angle.h"
#include "beyondNoReturn.h"
#include "eml_int_forloop_overflow_check.h"
#include "exp.h"
#include "inAball.h"
#include "indexShapeCheck.h"
#include "mod.h"
#include "polyval.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Type Definitions */
#ifndef typedef_captured_var
#define typedef_captured_var
typedef struct {
  real_T contents;
} captured_var;
#endif /* typedef_captured_var */

#ifndef typedef_b_captured_var
#define typedef_b_captured_var
typedef struct {
  creal_T contents;
} b_captured_var;
#endif /* typedef_b_captured_var */

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    93,                 /* lineNo */
    "SDpathODEuler_v3", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pathName
                                                                          */
};

static emlrtRSInfo b_emlrtRSI = {
    91,                 /* lineNo */
    "SDpathODEuler_v3", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pathName
                                                                          */
};

static emlrtRSInfo c_emlrtRSI = {
    90,                 /* lineNo */
    "SDpathODEuler_v3", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pathName
                                                                          */
};

static emlrtRSInfo d_emlrtRSI = {
    87,                 /* lineNo */
    "SDpathODEuler_v3", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pathName
                                                                          */
};

static emlrtRSInfo e_emlrtRSI = {
    86,                 /* lineNo */
    "SDpathODEuler_v3", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pathName
                                                                          */
};

static emlrtRSInfo f_emlrtRSI = {
    78,                 /* lineNo */
    "SDpathODEuler_v3", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pathName
                                                                          */
};

static emlrtRSInfo g_emlrtRSI = {
    76,                 /* lineNo */
    "SDpathODEuler_v3", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pathName
                                                                          */
};

static emlrtRSInfo h_emlrtRSI = {
    69,                 /* lineNo */
    "SDpathODEuler_v3", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pathName
                                                                          */
};

static emlrtRSInfo i_emlrtRSI = {
    62,                 /* lineNo */
    "SDpathODEuler_v3", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pathName
                                                                          */
};

static emlrtRSInfo j_emlrtRSI = {
    54,                 /* lineNo */
    "SDpathODEuler_v3", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pathName
                                                                          */
};

static emlrtRSInfo k_emlrtRSI = {
    46,                 /* lineNo */
    "SDpathODEuler_v3", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pathName
                                                                          */
};

static emlrtRSInfo l_emlrtRSI = {
    37,                 /* lineNo */
    "SDpathODEuler_v3", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pathName
                                                                          */
};

static emlrtRSInfo m_emlrtRSI = {
    29,                 /* lineNo */
    "SDpathODEuler_v3", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pathName
                                                                          */
};

static emlrtRSInfo n_emlrtRSI = {
    28,                 /* lineNo */
    "SDpathODEuler_v3", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pathName
                                                                          */
};

static emlrtRSInfo o_emlrtRSI = {
    9,                  /* lineNo */
    "SDpathODEuler_v3", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pathName
                                                                          */
};

static emlrtRSInfo p_emlrtRSI = {
    7,                                                           /* lineNo */
    "ref/ref",                                                   /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/ref.m" /* pathName */
};

static emlrtRSInfo r_emlrtRSI = {
    121,                           /* lineNo */
    "SDpathODEuler_v3/halt_euler", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pathName
                                                                          */
};

static emlrtRSInfo s_emlrtRSI = {
    12,                  /* lineNo */
    "beyondNoReturn_v2", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn_v2.m" /* pathName
                                                                           */
};

static emlrtRSInfo t_emlrtRSI = {
    16,                  /* lineNo */
    "beyondNoReturn_v2", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn_v2.m" /* pathName
                                                                           */
};

static emlrtRSInfo u_emlrtRSI = {
    21,                  /* lineNo */
    "beyondNoReturn_v2", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn_v2.m" /* pathName
                                                                           */
};

static emlrtRSInfo v_emlrtRSI = {
    23,                  /* lineNo */
    "beyondNoReturn_v2", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn_v2.m" /* pathName
                                                                           */
};

static emlrtRSInfo pb_emlrtRSI = {
    44,                                                          /* lineNo */
    "mpower",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/mpower.m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI = {
    71,                                                      /* lineNo */
    "power",                                                 /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/ops/power.m" /* pathName */
};

static emlrtRSInfo rb_emlrtRSI = {
    115,                              /* lineNo */
    "SDpathODEuler_v3/Newton_method", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pathName
                                                                          */
};

static emlrtRSInfo sb_emlrtRSI = {
    110,                              /* lineNo */
    "SDpathODEuler_v3/Newton_method", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pathName
                                                                          */
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
    28,                 /* lineNo */
    24,                 /* colNo */
    "gCoeffs",          /* aName */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    28,                 /* lineNo */
    27,                 /* colNo */
    "gCoeffs",          /* aName */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtECInfo emlrtECI = {
    2,                  /* nDims */
    28,                 /* lineNo */
    16,                 /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pName
                                                                          */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    29,                 /* lineNo */
    26,                 /* colNo */
    "dgCoeffs",         /* aName */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    29,                 /* lineNo */
    29,                 /* colNo */
    "dgCoeffs",         /* aName */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtECInfo b_emlrtECI = {
    2,                  /* nDims */
    29,                 /* lineNo */
    17,                 /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pName
                                                                          */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    36,                 /* lineNo */
    29,                 /* colNo */
    "gCoeffs",          /* aName */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    43,                 /* lineNo */
    11,                 /* colNo */
    "p_log",            /* aName */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    61,                 /* lineNo */
    19,                 /* colNo */
    "p_log",            /* aName */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    86,                 /* lineNo */
    23,                 /* colNo */
    "p_log",            /* aName */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    86,                 /* lineNo */
    25,                 /* colNo */
    "p_log",            /* aName */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    44,                 /* lineNo */
    11,                 /* colNo */
    "h_log",            /* aName */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    87,                 /* lineNo */
    23,                 /* colNo */
    "h_log",            /* aName */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    87,                 /* lineNo */
    25,                 /* colNo */
    "h_log",            /* aName */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    19,                 /* lineNo */
    24,                 /* colNo */
    "cover_radii",      /* aName */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    20,                 /* lineNo */
    17,                 /* colNo */
    "SPs",              /* aName */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo
    p_emlrtBCI =
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
    41,                 /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m", /* pName
                                                                           */
    1 /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    41,                 /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m", /* pName
                                                                           */
    4 /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    42,                 /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m", /* pName
                                                                           */
    1 /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    42,                 /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m", /* pName
                                                                           */
    4 /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    72,                 /* lineNo */
    15,                 /* colNo */
    "p_log",            /* aName */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    73,                 /* lineNo */
    15,                 /* colNo */
    "h_log",            /* aName */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
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

static emlrtBCInfo t_emlrtBCI = {
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
    15,                                                          /* lineNo */
    17,                                                          /* colNo */
    "ref",                                                       /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/ref.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    13,                 /* lineNo */
    9,                  /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pName
                                                                          */
};

static emlrtRTEInfo g_emlrtRTEI = {
    14,                 /* lineNo */
    9,                  /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pName
                                                                          */
};

static emlrtRTEInfo h_emlrtRTEI = {
    28,                 /* lineNo */
    37,                 /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pName
                                                                          */
};

static emlrtRTEInfo i_emlrtRTEI = {
    28,                 /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pName
                                                                          */
};

static emlrtRTEInfo j_emlrtRTEI = {
    29,                 /* lineNo */
    39,                 /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pName
                                                                          */
};

static emlrtRTEInfo k_emlrtRTEI = {
    29,                 /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pName
                                                                          */
};

static emlrtRTEInfo l_emlrtRTEI = {
    41,                 /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pName
                                                                          */
};

static emlrtRTEInfo m_emlrtRTEI = {
    42,                 /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pName
                                                                          */
};

static emlrtRTEInfo n_emlrtRTEI = {
    86,                 /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pName
                                                                          */
};

static emlrtRTEInfo o_emlrtRTEI = {
    87,                 /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pName
                                                                          */
};

static emlrtRTEInfo p_emlrtRTEI = {
    54,                 /* lineNo */
    68,                 /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pName
                                                                          */
};

static emlrtRTEInfo q_emlrtRTEI = {
    2,                  /* lineNo */
    5,                  /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pName
                                                                          */
};

static emlrtRTEInfo r_emlrtRTEI = {
    54,                 /* lineNo */
    64,                 /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pName
                                                                          */
};

static emlrtRTEInfo s_emlrtRTEI = {
    121,                /* lineNo */
    25,                 /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pName
                                                                          */
};

static emlrtRTEInfo t_emlrtRTEI = {
    121,                /* lineNo */
    30,                 /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pName
                                                                          */
};

static emlrtRTEInfo u_emlrtRTEI = {
    121,                /* lineNo */
    66,                 /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pName
                                                                          */
};

static emlrtRTEInfo v_emlrtRTEI = {
    12,                  /* lineNo */
    31,                  /* colNo */
    "beyondNoReturn_v2", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn_v2.m" /* pName
                                                                           */
};

static emlrtRTEInfo x_emlrtRTEI = {
    103,                /* lineNo */
    23,                 /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pName
                                                                          */
};

static emlrtRTEInfo y_emlrtRTEI = {
    104,                /* lineNo */
    24,                 /* colNo */
    "SDpathODEuler_v3", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/SDpathODEuler_v3.m" /* pName
                                                                          */
};

/* Function Declarations */
static void Newton_method(const emlrtStack *sp, b_captured_var *g_h,
                          const c_captured_var *gCoeffs, b_captured_var *h,
                          b_captured_var *dg_h, const c_captured_var *dgCoeffs,
                          const b_captured_var *g_se, const captured_var *p,
                          const captured_var *Newton_small_threshold,
                          creal_T Newton_step);

static void b_Newton_method(const emlrtStack *sp, b_captured_var *g_h,
                            const c_captured_var *gCoeffs, b_captured_var *h,
                            b_captured_var *dg_h,
                            const c_captured_var *dgCoeffs,
                            const b_captured_var *g_se, const captured_var *p,
                            const captured_var *Newton_small_threshold);

static void b_binary_expand_op(const emlrtStack *sp, c_captured_var *dgCoeffs,
                               const emxArray_creal_T *gCoeffs, int32_T i1,
                               const emxArray_real_T *r1);

static void binary_expand_op(const emlrtStack *sp, emxArray_creal_T *ddgCoeffs,
                             const c_captured_var *dgCoeffs, int32_T i1,
                             const emxArray_real_T *r1);

static boolean_T halt_euler(const emlrtStack *sp, const b_captured_var *h,
                            const c_captured_var *SPs,
                            const d_captured_var *cover_radii,
                            const c_captured_var *valleys,
                            const c_captured_var *gCoeffs,
                            const captured_var *r_star);

/* Function Definitions */
static void Newton_method(const emlrtStack *sp, b_captured_var *g_h,
                          const c_captured_var *gCoeffs, b_captured_var *h,
                          b_captured_var *dg_h, const c_captured_var *dgCoeffs,
                          const b_captured_var *g_se, const captured_var *p,
                          const captured_var *Newton_small_threshold,
                          creal_T Newton_step)
{
  emlrtStack st;
  emxArray_creal_T *b_p;
  creal_T *p_data;
  real_T ai;
  real_T ar;
  real_T b_x_re;
  real_T im;
  real_T re;
  real_T x_im;
  real_T x_re;
  int32_T exitg1;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_creal_T(sp, &b_p, 2, &x_emlrtRTEI);
  do {
    exitg1 = 0;
    im = muDoubleScalarHypot(Newton_step.re, Newton_step.im);
    if (im > Newton_small_threshold->contents) {
      h->contents.re -= Newton_step.re;
      h->contents.im -= Newton_step.im;
      if (im > Newton_small_threshold->contents) {
        st.site = &rb_emlrtRSI;
        /*     %% indended functions */
        i = b_p->size[0] * b_p->size[1];
        b_p->size[0] = 1;
        b_p->size[1] = gCoeffs->contents->size[1];
        emxEnsureCapacity_creal_T(&st, b_p, i, &x_emlrtRTEI);
        p_data = b_p->data;
        loop_ub = gCoeffs->contents->size[1];
        for (i = 0; i < loop_ub; i++) {
          p_data[i] = gCoeffs->contents->data[i];
        }
        x_re = h->contents.re;
        x_im = h->contents.im;
        if (b_p->size[1] != 0) {
          re = p_data[0].re;
          im = p_data[0].im;
          i = b_p->size[1];
          for (loop_ub = 0; loop_ub <= i - 2; loop_ub++) {
            b_x_re = x_re * re - x_im * im;
            im = x_re * im + x_im * re;
            re = b_x_re + p_data[loop_ub + 1].re;
            im += p_data[loop_ub + 1].im;
          }
        }
        g_h->contents.re = re;
        g_h->contents.im = im;
        i = b_p->size[0] * b_p->size[1];
        b_p->size[0] = 1;
        b_p->size[1] = dgCoeffs->contents->size[1];
        emxEnsureCapacity_creal_T(&st, b_p, i, &y_emlrtRTEI);
        p_data = b_p->data;
        loop_ub = dgCoeffs->contents->size[1];
        for (i = 0; i < loop_ub; i++) {
          p_data[i] = dgCoeffs->contents->data[i];
        }
        x_re = h->contents.re;
        x_im = h->contents.im;
        if (b_p->size[1] != 0) {
          re = p_data[0].re;
          im = p_data[0].im;
          i = b_p->size[1];
          for (loop_ub = 0; loop_ub <= i - 2; loop_ub++) {
            b_x_re = x_re * re - x_im * im;
            im = x_re * im + x_im * re;
            re = b_x_re + p_data[loop_ub + 1].re;
            im += p_data[loop_ub + 1].im;
          }
        }
        dg_h->contents.re = re;
        dg_h->contents.im = im;
        ar = (g_h->contents.re - g_se->contents.re) - 0.0 * p->contents;
        ai = (g_h->contents.im - g_se->contents.im) - p->contents;
        x_im = dg_h->contents.re;
        re = dg_h->contents.im;
        if (re == 0.0) {
          if (ai == 0.0) {
            Newton_step.re = ar / x_im;
            Newton_step.im = 0.0;
          } else if (ar == 0.0) {
            Newton_step.re = 0.0;
            Newton_step.im = ai / x_im;
          } else {
            Newton_step.re = ar / x_im;
            Newton_step.im = ai / x_im;
          }
        } else if (x_im == 0.0) {
          if (ar == 0.0) {
            Newton_step.re = ai / re;
            Newton_step.im = 0.0;
          } else if (ai == 0.0) {
            Newton_step.re = 0.0;
            Newton_step.im = -(ar / re);
          } else {
            Newton_step.re = ai / re;
            Newton_step.im = -(ar / re);
          }
        } else {
          b_x_re = muDoubleScalarAbs(x_im);
          im = muDoubleScalarAbs(re);
          if (b_x_re > im) {
            x_re = re / x_im;
            im = x_im + x_re * re;
            Newton_step.re = (ar + x_re * ai) / im;
            Newton_step.im = (ai - x_re * ar) / im;
          } else if (im == b_x_re) {
            if (x_im > 0.0) {
              x_re = 0.5;
            } else {
              x_re = -0.5;
            }
            if (re > 0.0) {
              im = 0.5;
            } else {
              im = -0.5;
            }
            Newton_step.re = (ar * x_re + ai * im) / b_x_re;
            Newton_step.im = (ai * x_re - ar * im) / b_x_re;
          } else {
            x_re = x_im / re;
            im = re + x_re * x_im;
            Newton_step.re = (x_re * ar + ai) / im;
            Newton_step.im = (x_re * ai - ar) / im;
          }
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  emxFree_creal_T(sp, &b_p);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void b_Newton_method(const emlrtStack *sp, b_captured_var *g_h,
                            const c_captured_var *gCoeffs, b_captured_var *h,
                            b_captured_var *dg_h,
                            const c_captured_var *dgCoeffs,
                            const b_captured_var *g_se, const captured_var *p,
                            const captured_var *Newton_small_threshold)
{
  emlrtStack st;
  emxArray_creal_T *b_p;
  creal_T *p_data;
  real_T Newton_step_im;
  real_T Newton_step_im_tmp_tmp;
  real_T Newton_step_re;
  real_T Newton_step_re_tmp_tmp;
  real_T brm;
  real_T im;
  real_T re;
  int32_T exitg1;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_creal_T(sp, &b_p, 2, &x_emlrtRTEI);
  st.site = &sb_emlrtRSI;
  /*     %% indended functions */
  i = b_p->size[0] * b_p->size[1];
  b_p->size[0] = 1;
  b_p->size[1] = gCoeffs->contents->size[1];
  emxEnsureCapacity_creal_T(&st, b_p, i, &x_emlrtRTEI);
  p_data = b_p->data;
  loop_ub = gCoeffs->contents->size[1];
  for (i = 0; i < loop_ub; i++) {
    p_data[i] = gCoeffs->contents->data[i];
  }
  Newton_step_re_tmp_tmp = h->contents.re;
  Newton_step_im_tmp_tmp = h->contents.im;
  if (b_p->size[1] != 0) {
    re = p_data[0].re;
    im = p_data[0].im;
    i = b_p->size[1];
    for (loop_ub = 0; loop_ub <= i - 2; loop_ub++) {
      Newton_step_re =
          Newton_step_re_tmp_tmp * re - Newton_step_im_tmp_tmp * im;
      Newton_step_im =
          Newton_step_re_tmp_tmp * im + Newton_step_im_tmp_tmp * re;
      re = Newton_step_re + p_data[loop_ub + 1].re;
      im = Newton_step_im + p_data[loop_ub + 1].im;
    }
  }
  g_h->contents.re = re;
  g_h->contents.im = im;
  i = b_p->size[0] * b_p->size[1];
  b_p->size[0] = 1;
  b_p->size[1] = dgCoeffs->contents->size[1];
  emxEnsureCapacity_creal_T(&st, b_p, i, &y_emlrtRTEI);
  p_data = b_p->data;
  loop_ub = dgCoeffs->contents->size[1];
  for (i = 0; i < loop_ub; i++) {
    p_data[i] = dgCoeffs->contents->data[i];
  }
  if (b_p->size[1] != 0) {
    re = p_data[0].re;
    im = p_data[0].im;
    i = b_p->size[1];
    for (loop_ub = 0; loop_ub <= i - 2; loop_ub++) {
      Newton_step_re =
          Newton_step_re_tmp_tmp * re - Newton_step_im_tmp_tmp * im;
      Newton_step_im =
          Newton_step_re_tmp_tmp * im + Newton_step_im_tmp_tmp * re;
      re = Newton_step_re + p_data[loop_ub + 1].re;
      im = Newton_step_im + p_data[loop_ub + 1].im;
    }
  }
  dg_h->contents.re = re;
  dg_h->contents.im = im;
  re = (g_h->contents.re - g_se->contents.re) - 0.0 * p->contents;
  Newton_step_im = (g_h->contents.im - g_se->contents.im) - p->contents;
  Newton_step_re_tmp_tmp = dg_h->contents.re;
  Newton_step_im_tmp_tmp = dg_h->contents.im;
  if (Newton_step_im_tmp_tmp == 0.0) {
    if (Newton_step_im == 0.0) {
      Newton_step_re = re / Newton_step_re_tmp_tmp;
      Newton_step_im = 0.0;
    } else if (re == 0.0) {
      Newton_step_re = 0.0;
      Newton_step_im /= Newton_step_re_tmp_tmp;
    } else {
      Newton_step_re = re / Newton_step_re_tmp_tmp;
      Newton_step_im /= Newton_step_re_tmp_tmp;
    }
  } else if (Newton_step_re_tmp_tmp == 0.0) {
    if (re == 0.0) {
      Newton_step_re = Newton_step_im / Newton_step_im_tmp_tmp;
      Newton_step_im = 0.0;
    } else if (Newton_step_im == 0.0) {
      Newton_step_re = 0.0;
      Newton_step_im = -(re / Newton_step_im_tmp_tmp);
    } else {
      Newton_step_re = Newton_step_im / Newton_step_im_tmp_tmp;
      Newton_step_im = -(re / Newton_step_im_tmp_tmp);
    }
  } else {
    brm = muDoubleScalarAbs(Newton_step_re_tmp_tmp);
    im = muDoubleScalarAbs(Newton_step_im_tmp_tmp);
    if (brm > im) {
      im = Newton_step_im_tmp_tmp / Newton_step_re_tmp_tmp;
      Newton_step_re_tmp_tmp += im * Newton_step_im_tmp_tmp;
      Newton_step_re = (re + im * Newton_step_im) / Newton_step_re_tmp_tmp;
      Newton_step_im = (Newton_step_im - im * re) / Newton_step_re_tmp_tmp;
    } else if (im == brm) {
      if (Newton_step_re_tmp_tmp > 0.0) {
        im = 0.5;
      } else {
        im = -0.5;
      }
      if (Newton_step_im_tmp_tmp > 0.0) {
        Newton_step_re_tmp_tmp = 0.5;
      } else {
        Newton_step_re_tmp_tmp = -0.5;
      }
      Newton_step_re =
          (re * im + Newton_step_im * Newton_step_re_tmp_tmp) / brm;
      Newton_step_im =
          (Newton_step_im * im - re * Newton_step_re_tmp_tmp) / brm;
    } else {
      im = Newton_step_re_tmp_tmp / Newton_step_im_tmp_tmp;
      Newton_step_re_tmp_tmp =
          Newton_step_im_tmp_tmp + im * Newton_step_re_tmp_tmp;
      Newton_step_re = (im * re + Newton_step_im) / Newton_step_re_tmp_tmp;
      Newton_step_im = (im * Newton_step_im - re) / Newton_step_re_tmp_tmp;
    }
  }
  do {
    exitg1 = 0;
    Newton_step_re_tmp_tmp =
        muDoubleScalarHypot(Newton_step_re, Newton_step_im);
    if (Newton_step_re_tmp_tmp > Newton_small_threshold->contents) {
      h->contents.re -= Newton_step_re;
      h->contents.im -= Newton_step_im;
      if (Newton_step_re_tmp_tmp > Newton_small_threshold->contents) {
        st.site = &rb_emlrtRSI;
        /*     %% indended functions */
        i = b_p->size[0] * b_p->size[1];
        b_p->size[0] = 1;
        b_p->size[1] = gCoeffs->contents->size[1];
        emxEnsureCapacity_creal_T(&st, b_p, i, &x_emlrtRTEI);
        p_data = b_p->data;
        loop_ub = gCoeffs->contents->size[1];
        for (i = 0; i < loop_ub; i++) {
          p_data[i] = gCoeffs->contents->data[i];
        }
        Newton_step_re = h->contents.re;
        Newton_step_im = h->contents.im;
        if (b_p->size[1] != 0) {
          re = p_data[0].re;
          im = p_data[0].im;
          i = b_p->size[1];
          for (loop_ub = 0; loop_ub <= i - 2; loop_ub++) {
            Newton_step_im_tmp_tmp = Newton_step_re * re - Newton_step_im * im;
            Newton_step_re_tmp_tmp = Newton_step_re * im + Newton_step_im * re;
            re = Newton_step_im_tmp_tmp + p_data[loop_ub + 1].re;
            im = Newton_step_re_tmp_tmp + p_data[loop_ub + 1].im;
          }
        }
        g_h->contents.re = re;
        g_h->contents.im = im;
        i = b_p->size[0] * b_p->size[1];
        b_p->size[0] = 1;
        b_p->size[1] = dgCoeffs->contents->size[1];
        emxEnsureCapacity_creal_T(&st, b_p, i, &y_emlrtRTEI);
        p_data = b_p->data;
        loop_ub = dgCoeffs->contents->size[1];
        for (i = 0; i < loop_ub; i++) {
          p_data[i] = dgCoeffs->contents->data[i];
        }
        Newton_step_re = h->contents.re;
        Newton_step_im = h->contents.im;
        if (b_p->size[1] != 0) {
          re = p_data[0].re;
          im = p_data[0].im;
          i = b_p->size[1];
          for (loop_ub = 0; loop_ub <= i - 2; loop_ub++) {
            Newton_step_im_tmp_tmp = Newton_step_re * re - Newton_step_im * im;
            Newton_step_re_tmp_tmp = Newton_step_re * im + Newton_step_im * re;
            re = Newton_step_im_tmp_tmp + p_data[loop_ub + 1].re;
            im = Newton_step_re_tmp_tmp + p_data[loop_ub + 1].im;
          }
        }
        dg_h->contents.re = re;
        dg_h->contents.im = im;
        re = (g_h->contents.re - g_se->contents.re) - 0.0 * p->contents;
        Newton_step_im = (g_h->contents.im - g_se->contents.im) - p->contents;
        Newton_step_re_tmp_tmp = dg_h->contents.re;
        Newton_step_im_tmp_tmp = dg_h->contents.im;
        if (Newton_step_im_tmp_tmp == 0.0) {
          if (Newton_step_im == 0.0) {
            Newton_step_re = re / Newton_step_re_tmp_tmp;
            Newton_step_im = 0.0;
          } else if (re == 0.0) {
            Newton_step_re = 0.0;
            Newton_step_im /= Newton_step_re_tmp_tmp;
          } else {
            Newton_step_re = re / Newton_step_re_tmp_tmp;
            Newton_step_im /= Newton_step_re_tmp_tmp;
          }
        } else if (Newton_step_re_tmp_tmp == 0.0) {
          if (re == 0.0) {
            Newton_step_re = Newton_step_im / Newton_step_im_tmp_tmp;
            Newton_step_im = 0.0;
          } else if (Newton_step_im == 0.0) {
            Newton_step_re = 0.0;
            Newton_step_im = -(re / Newton_step_im_tmp_tmp);
          } else {
            Newton_step_re = Newton_step_im / Newton_step_im_tmp_tmp;
            Newton_step_im = -(re / Newton_step_im_tmp_tmp);
          }
        } else {
          brm = muDoubleScalarAbs(Newton_step_re_tmp_tmp);
          im = muDoubleScalarAbs(Newton_step_im_tmp_tmp);
          if (brm > im) {
            im = Newton_step_im_tmp_tmp / Newton_step_re_tmp_tmp;
            Newton_step_re_tmp_tmp += im * Newton_step_im_tmp_tmp;
            Newton_step_re =
                (re + im * Newton_step_im) / Newton_step_re_tmp_tmp;
            Newton_step_im =
                (Newton_step_im - im * re) / Newton_step_re_tmp_tmp;
          } else if (im == brm) {
            if (Newton_step_re_tmp_tmp > 0.0) {
              im = 0.5;
            } else {
              im = -0.5;
            }
            if (Newton_step_im_tmp_tmp > 0.0) {
              Newton_step_re_tmp_tmp = 0.5;
            } else {
              Newton_step_re_tmp_tmp = -0.5;
            }
            Newton_step_re =
                (re * im + Newton_step_im * Newton_step_re_tmp_tmp) / brm;
            Newton_step_im =
                (Newton_step_im * im - re * Newton_step_re_tmp_tmp) / brm;
          } else {
            im = Newton_step_re_tmp_tmp / Newton_step_im_tmp_tmp;
            Newton_step_re_tmp_tmp =
                Newton_step_im_tmp_tmp + im * Newton_step_re_tmp_tmp;
            Newton_step_re =
                (im * re + Newton_step_im) / Newton_step_re_tmp_tmp;
            Newton_step_im =
                (im * Newton_step_im - re) / Newton_step_re_tmp_tmp;
          }
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  emxFree_creal_T(sp, &b_p);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void b_binary_expand_op(const emlrtStack *sp, c_captured_var *dgCoeffs,
                               const emxArray_creal_T *gCoeffs, int32_T i1,
                               const emxArray_real_T *r1)
{
  const creal_T *gCoeffs_data;
  const real_T *r;
  real_T d;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  r = r1->data;
  gCoeffs_data = gCoeffs->data;
  i = dgCoeffs->contents->size[0] * dgCoeffs->contents->size[1];
  dgCoeffs->contents->size[0] = 1;
  if (r1->size[1] == 1) {
    dgCoeffs->contents->size[1] = i1 + 1;
  } else {
    dgCoeffs->contents->size[1] = r1->size[1];
  }
  emxEnsureCapacity_creal_T(sp, dgCoeffs->contents, i, &i_emlrtRTEI);
  stride_0_1 = (i1 + 1 != 1);
  stride_1_1 = (r1->size[1] != 1);
  if (r1->size[1] == 1) {
    loop_ub = i1 + 1;
  } else {
    loop_ub = r1->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    d = r[i * stride_1_1];
    dgCoeffs->contents->data[i].re = d * gCoeffs_data[i * stride_0_1].re;
    dgCoeffs->contents->data[i].im = d * gCoeffs_data[i * stride_0_1].im;
  }
}

static void binary_expand_op(const emlrtStack *sp, emxArray_creal_T *ddgCoeffs,
                             const c_captured_var *dgCoeffs, int32_T i1,
                             const emxArray_real_T *r1)
{
  creal_T *ddgCoeffs_data;
  const real_T *r;
  real_T d;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  r = r1->data;
  i = ddgCoeffs->size[0] * ddgCoeffs->size[1];
  ddgCoeffs->size[0] = 1;
  if (r1->size[1] == 1) {
    ddgCoeffs->size[1] = i1 + 1;
  } else {
    ddgCoeffs->size[1] = r1->size[1];
  }
  emxEnsureCapacity_creal_T(sp, ddgCoeffs, i, &k_emlrtRTEI);
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
    ddgCoeffs_data[i].re = d * dgCoeffs->contents->data[i * stride_0_1].re;
    ddgCoeffs_data[i].im = d * dgCoeffs->contents->data[i * stride_0_1].im;
  }
}

static boolean_T halt_euler(const emlrtStack *sp, const b_captured_var *h,
                            const c_captured_var *SPs,
                            const d_captured_var *cover_radii,
                            const c_captured_var *valleys,
                            const c_captured_var *gCoeffs,
                            const captured_var *r_star)
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
  emxArray_creal_T *b_r;
  emxArray_creal_T *cover_centres;
  emxArray_real_T *b_cover_radii;
  creal_T *cover_centres_data;
  creal_T *r1;
  real_T varargin_1[3];
  real_T R;
  real_T r;
  real_T theta_diff;
  real_T x_re_tmp;
  real_T *cover_radii_data;
  int32_T a;
  int32_T idx;
  int32_T k;
  int32_T last;
  boolean_T b_yn;
  boolean_T exitg1;
  boolean_T value;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_creal_T(sp, &cover_centres, 1, &s_emlrtRTEI);
  st.site = &r_emlrtRSI;
  theta_diff = h->contents.re;
  r = h->contents.im;
  k = cover_centres->size[0];
  cover_centres->size[0] = SPs->contents->size[0];
  emxEnsureCapacity_creal_T(&st, cover_centres, k, &s_emlrtRTEI);
  cover_centres_data = cover_centres->data;
  last = SPs->contents->size[0];
  for (k = 0; k < last; k++) {
    cover_centres_data[k] = SPs->contents->data[k];
  }
  emxInit_real_T(&st, &b_cover_radii, 1, &t_emlrtRTEI);
  k = b_cover_radii->size[0];
  b_cover_radii->size[0] = cover_radii->contents->size[0];
  emxEnsureCapacity_real_T(&st, b_cover_radii, k, &t_emlrtRTEI);
  cover_radii_data = b_cover_radii->data;
  last = cover_radii->contents->size[0];
  for (k = 0; k < last; k++) {
    cover_radii_data[k] = cover_radii->contents->data[k];
  }
  /* returns 1 if SD path is in a ball, 0 otherwise */
  value = false;
  last = 1;
  exitg1 = false;
  while ((!exitg1) && (last - 1 <= cover_centres->size[0] - 1)) {
    if ((last < 1) || (last > cover_centres->size[0])) {
      emlrtDynamicBoundsCheckR2012b(last, 1, cover_centres->size[0],
                                    &u_emlrtBCI, &st);
    }
    if (last > cover_centres->size[0]) {
      emlrtDynamicBoundsCheckR2012b(last, 1, cover_centres->size[0],
                                    &u_emlrtBCI, &st);
    }
    if (last > b_cover_radii->size[0]) {
      emlrtDynamicBoundsCheckR2012b(last, 1, b_cover_radii->size[0],
                                    &v_emlrtBCI, &st);
    }
    if (muDoubleScalarHypot(theta_diff - cover_centres_data[last - 1].re,
                            r - cover_centres_data[last - 1].im) <
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
  emxInit_creal_T(sp, &b_r, 1, &v_emlrtRTEI);
  if (value) {
    b_yn = true;
  } else {
    st.site = &r_emlrtRSI;
    k = cover_centres->size[0];
    cover_centres->size[0] = valleys->contents->size[0];
    emxEnsureCapacity_creal_T(&st, cover_centres, k, &u_emlrtRTEI);
    cover_centres_data = cover_centres->data;
    last = valleys->contents->size[0];
    for (k = 0; k < last; k++) {
      cover_centres_data[k] = valleys->contents->data[k];
    }
    /* function corresponding to an event which would halt ODE solve, because SD
     */
    /* path is at 'point of no return'. */
    /*  the 'no return test' */
    value = false;
    R = muDoubleScalarHypot(theta_diff, r);
    if (R > r_star->contents) {
      /*  first test, based on length of z */
      /*  now check that path is sufficiently close to monomial SD path */
      b_st.site = &s_emlrtRSI;
      angle(&b_st, cover_centres, b_cover_radii);
      cover_radii_data = b_cover_radii->data;
      x_re_tmp = muDoubleScalarAtan2(r, theta_diff);
      theta_diff = x_re_tmp * 0.0;
      b_st.site = &s_emlrtRSI;
      if (x_re_tmp == 0.0) {
        theta_diff = muDoubleScalarExp(theta_diff);
        r = 0.0;
      } else {
        r = muDoubleScalarExp(theta_diff / 2.0);
        theta_diff = r * (r * muDoubleScalarCos(x_re_tmp));
        r *= r * muDoubleScalarSin(x_re_tmp);
      }
      k = b_r->size[0];
      b_r->size[0] = b_cover_radii->size[0];
      emxEnsureCapacity_creal_T(&b_st, b_r, k, &v_emlrtRTEI);
      r1 = b_r->data;
      last = b_cover_radii->size[0];
      for (k = 0; k < last; k++) {
        r1[k].re = cover_radii_data[k] * 0.0;
        r1[k].im = cover_radii_data[k];
      }
      c_st.site = &s_emlrtRSI;
      b_exp(&c_st, b_r);
      r1 = b_r->data;
      last = b_r->size[0];
      for (k = 0; k < last; k++) {
        r1[k].re -= theta_diff;
        r1[k].im -= r;
      }
      c_st.site = &s_emlrtRSI;
      b_abs(&c_st, b_r, b_cover_radii);
      cover_radii_data = b_cover_radii->data;
      c_st.site = &cb_emlrtRSI;
      d_st.site = &db_emlrtRSI;
      e_st.site = &eb_emlrtRSI;
      if (b_cover_radii->size[0] < 1) {
        emlrtErrorWithMessageIdR2018a(
            &e_st, &emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
            "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }
      f_st.site = &fb_emlrtRSI;
      last = b_cover_radii->size[0];
      if (b_cover_radii->size[0] <= 2) {
        if (b_cover_radii->size[0] == 1) {
          idx = 1;
        } else if ((cover_radii_data[0] > cover_radii_data[1]) ||
                   (muDoubleScalarIsNaN(cover_radii_data[0]) &&
                    (!muDoubleScalarIsNaN(cover_radii_data[1])))) {
          idx = 2;
        } else {
          idx = 1;
        }
      } else {
        g_st.site = &hb_emlrtRSI;
        if (!muDoubleScalarIsNaN(cover_radii_data[0])) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &ib_emlrtRSI;
          if (b_cover_radii->size[0] > 2147483646) {
            i_st.site = &q_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= last)) {
            if (!muDoubleScalarIsNaN(cover_radii_data[k - 1])) {
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
          g_st.site = &gb_emlrtRSI;
          theta_diff = cover_radii_data[idx - 1];
          a = idx + 1;
          h_st.site = &jb_emlrtRSI;
          if ((idx + 1 <= b_cover_radii->size[0]) &&
              (b_cover_radii->size[0] > 2147483646)) {
            i_st.site = &q_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          for (k = a; k <= last; k++) {
            r = cover_radii_data[k - 1];
            if (theta_diff > r) {
              theta_diff = r;
              idx = k;
            }
          }
        }
      }
      if ((idx < 1) || (idx > cover_centres->size[0])) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, cover_centres->size[0],
                                      &s_emlrtBCI, &st);
      }
      b_st.site = &t_emlrtRSI;
      theta_diff = b_mod(x_re_tmp) -
                   b_mod(muDoubleScalarAtan2(cover_centres_data[idx - 1].im,
                                             cover_centres_data[idx - 1].re));
      varargin_1[0] = muDoubleScalarAbs(theta_diff);
      varargin_1[1] = muDoubleScalarAbs(theta_diff - 6.2831853071795862);
      varargin_1[2] = muDoubleScalarAbs(theta_diff + 6.2831853071795862);
      c_st.site = &kb_emlrtRSI;
      d_st.site = &lb_emlrtRSI;
      e_st.site = &mb_emlrtRSI;
      f_st.site = &nb_emlrtRSI;
      g_st.site = &ob_emlrtRSI;
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
        theta_diff = varargin_1[0];
      } else {
        h_st.site = &gb_emlrtRSI;
        theta_diff = varargin_1[idx - 1];
        a = idx + 1;
        for (k = a; k < 4; k++) {
          r = varargin_1[k - 1];
          if (theta_diff > r) {
            theta_diff = r;
          }
        }
      }
      /*          theta_diff = max(theta_in_diff,pi/(4*order)); */
      if (theta_diff <
          3.1415926535897931 / (2.0 * (real_T)cover_centres->size[0])) {
        /*  now check Dave's refined polynomial condition */
        k = gCoeffs->contents->size[1];
        if (1 > k) {
          emlrtDynamicBoundsCheckR2012b(1, 1, k, &t_emlrtBCI, &st);
        }
        b_st.site = &u_emlrtRSI;
        c_st.site = &pb_emlrtRSI;
        d_st.site = &qb_emlrtRSI;
        theta_diff =
            (real_T)cover_centres->size[0] *
            muDoubleScalarHypot(gCoeffs->contents->data[0].re,
                                gCoeffs->contents->data[0].im) *
            muDoubleScalarPower(R, (real_T)cover_centres->size[0] - 1.0) *
            muDoubleScalarMin(
                0.70710678118654746,
                muDoubleScalarCos((real_T)cover_centres->size[0] * theta_diff));
        last = 0;
        exitg1 = false;
        while ((!exitg1) && (last <= cover_centres->size[0] - 2)) {
          k = gCoeffs->contents->size[1];
          idx = (gCoeffs->contents->size[1] - last) - 1;
          if ((idx < 1) || (idx > k)) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, k, &w_emlrtBCI, &st);
          }
          k = gCoeffs->contents->size[1];
          a = (gCoeffs->contents->size[1] - last) - 1;
          if ((a < 1) || (a > k)) {
            emlrtDynamicBoundsCheckR2012b(a, 1, k, &w_emlrtBCI, &st);
          }
          b_st.site = &v_emlrtRSI;
          c_st.site = &pb_emlrtRSI;
          d_st.site = &qb_emlrtRSI;
          theta_diff -= ((real_T)last + 1.0) *
                        muDoubleScalarHypot(gCoeffs->contents->data[idx - 1].re,
                                            gCoeffs->contents->data[a - 1].im) *
                        muDoubleScalarPower(R, ((real_T)last + 1.0) - 1.0);
          if (theta_diff <= 0.0) {
            /*  G isn't getting any bigger */
            exitg1 = true;
          } else {
            last++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(&st);
            }
          }
        }
        value = (theta_diff > 0.0);
      }
    }
    if (value) {
      b_yn = true;
    } else {
      b_yn = false;
    }
  }
  emxFree_creal_T(sp, &b_r);
  emxFree_real_T(sp, &b_cover_radii);
  emxFree_creal_T(sp, &cover_centres);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return b_yn;
}

void SDpathODEuler_v3(
    const emlrtStack *sp, const creal_T h0, const emxArray_creal_T *gCoeffs,
    const emxArray_creal_T *SPs, const emxArray_real_T *cover_radii,
    const emxArray_creal_T *valleys, real_T base_step_size, int64_T n_max,
    real_T r_star, real_T Newton_small_threshold, real_T Newton_big_threshold,
    emxArray_real_T *p_log_out, emxArray_creal_T *h_log_out,
    real_T valley_index_data[], int32_T valley_index_size[2],
    real_T ball_index_data[], int32_T ball_index_size[2], boolean_T *success)
{
  b_captured_var dg_h;
  b_captured_var g_h;
  b_captured_var g_se;
  b_captured_var h;
  c_captured_var b_SPs;
  c_captured_var b_gCoeffs;
  c_captured_var b_valleys;
  c_captured_var dgCoeffs;
  captured_var b_Newton_small_threshold;
  captured_var b_r_star;
  captured_var p;
  d_captured_var b_cover_radii;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  emxArray_creal_T *c_SPs;
  emxArray_creal_T *ddgCoeffs;
  emxArray_creal_T *h_log;
  emxArray_real_T *p_log;
  emxArray_real_T *r;
  emxArray_real_T *varargin_1;
  const creal_T *SPs_data;
  const creal_T *gCoeffs_data;
  const creal_T *valleys_data;
  creal_T F_h;
  creal_T dc;
  creal_T *ddgCoeffs_data;
  creal_T *h_log_data;
  const real_T *cover_radii_data;
  real_T Cnr;
  real_T brm;
  real_T dg_h_im;
  real_T dg_h_re;
  real_T p_step_size;
  real_T sgnbi;
  real_T z_re;
  real_T *p_log_data;
  real_T *p_log_out_data;
  int32_T iv[2];
  int32_T exitg11;
  int32_T idx;
  int32_T j;
  int32_T k;
  int32_T last;
  uint32_T n;
  boolean_T a__2;
  boolean_T exitg1;
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
  valleys_data = valleys->data;
  cover_radii_data = cover_radii->data;
  SPs_data = SPs->data;
  gCoeffs_data = gCoeffs->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInitStruct_captured_var(sp, &b_gCoeffs, &q_emlrtRTEI);
  st.site = &o_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  k = b_gCoeffs.contents->size[0] * b_gCoeffs.contents->size[1];
  b_gCoeffs.contents->size[0] = 1;
  b_gCoeffs.contents->size[1] = gCoeffs->size[1];
  emxEnsureCapacity_creal_T(&st, b_gCoeffs.contents, k, &e_emlrtRTEI);
  last = gCoeffs->size[1];
  for (k = 0; k < last; k++) {
    b_gCoeffs.contents->data[k] = gCoeffs_data[k];
  }
  emxInitStruct_captured_var1(&st, &b_SPs, &q_emlrtRTEI);
  st.site = &o_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  k = b_SPs.contents->size[0];
  b_SPs.contents->size[0] = SPs->size[0];
  emxEnsureCapacity_creal_T(&st, b_SPs.contents, k, &e_emlrtRTEI);
  last = SPs->size[0];
  for (k = 0; k < last; k++) {
    b_SPs.contents->data[k] = SPs_data[k];
  }
  emxInitStruct_captured_var2(&st, &b_cover_radii, &q_emlrtRTEI);
  st.site = &o_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  k = b_cover_radii.contents->size[0];
  b_cover_radii.contents->size[0] = cover_radii->size[0];
  emxEnsureCapacity_real_T(&st, b_cover_radii.contents, k, &e_emlrtRTEI);
  last = cover_radii->size[0];
  for (k = 0; k < last; k++) {
    b_cover_radii.contents->data[k] = cover_radii_data[k];
  }
  emxInitStruct_captured_var1(&st, &b_valleys, &q_emlrtRTEI);
  st.site = &o_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  k = b_valleys.contents->size[0];
  b_valleys.contents->size[0] = valleys->size[0];
  emxEnsureCapacity_creal_T(&st, b_valleys.contents, k, &e_emlrtRTEI);
  last = valleys->size[0];
  for (k = 0; k < last; k++) {
    b_valleys.contents->data[k] = valleys_data[k];
  }
  st.site = &o_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  b_r_star.contents = r_star;
  st.site = &o_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  b_Newton_small_threshold.contents = Newton_small_threshold;
  st.site = &o_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  st.site = &o_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  st.site = &o_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  st.site = &o_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  st.site = &o_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  st.site = &o_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  /*  version three adds error checking at each step */
  /* computes NSD path h(p) and h'(p) */
  /* excluded_SPs_indices */
  valley_index_size[0] = 0;
  valley_index_size[1] = 0;
  ball_index_size[0] = 0;
  ball_index_size[1] = 0;
  *success = true;
  if (SPs->size[0] == 0) {
    k = b_SPs.contents->size[0];
    b_SPs.contents->size[0] = 1;
    emxEnsureCapacity_creal_T(sp, b_SPs.contents, k, &f_emlrtRTEI);
    b_SPs.contents->data[0].re = rtInf;
    b_SPs.contents->data[0].im = 0.0;
    /*  bodge to speed things up further down */
    k = b_cover_radii.contents->size[0];
    b_cover_radii.contents->size[0] = 1;
    emxEnsureCapacity_real_T(sp, b_cover_radii.contents, k, &g_emlrtRTEI);
    b_cover_radii.contents->data[0] = 0.0;
  }
  k = b_SPs.contents->size[0];
  for (last = 0; last < k; last++) {
    /*  another bodge to stop stationary points being treated like critical */
    /*  points */
    if (last + 1 > b_cover_radii.contents->size[0]) {
      emlrtDynamicBoundsCheckR2012b(last + 1, 1,
                                    b_cover_radii.contents->size[0],
                                    &n_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_cover_radii.contents->data[last] == 0.0) {
      /*  || ismember(n,excluded_SPs_indices) */
      if (last + 1 > b_SPs.contents->size[0]) {
        emlrtDynamicBoundsCheckR2012b(last + 1, 1, b_SPs.contents->size[0],
                                      &o_emlrtBCI, (emlrtCTX)sp);
      }
      b_SPs.contents->data[last].re = rtInf;
      if (last + 1 > b_SPs.contents->size[0]) {
        emlrtDynamicBoundsCheckR2012b(last + 1, 1, b_SPs.contents->size[0],
                                      &o_emlrtBCI, (emlrtCTX)sp);
      }
      b_SPs.contents->data[last].im = 0.0;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  g_se.contents = polyval(gCoeffs, h0);
  /*  value of g at steepest exit */
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
  st.site = &n_emlrtRSI;
  emxInit_real_T(&st, &r, 2, &q_emlrtRTEI);
  p_log_out_data = r->data;
  if (gCoeffs->size[1] - 1 < 1) {
    r->size[0] = 1;
    r->size[1] = 0;
  } else {
    k = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = (int32_T) - (1.0 - ((real_T)gCoeffs->size[1] - 1.0)) + 1;
    emxEnsureCapacity_real_T(&st, r, k, &h_emlrtRTEI);
    p_log_out_data = r->data;
    idx = (int32_T) - (1.0 - ((real_T)gCoeffs->size[1] - 1.0));
    for (k = 0; k <= idx; k++) {
      p_log_out_data[k] = ((real_T)gCoeffs->size[1] - 1.0) - (real_T)k;
    }
  }
  if ((last != r->size[1]) && ((last != 1) && (r->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(last, r->size[1], &emlrtECI, (emlrtCTX)sp);
  }
  emxInitStruct_captured_var(sp, &dgCoeffs, &i_emlrtRTEI);
  if (last == r->size[1]) {
    k = dgCoeffs.contents->size[0] * dgCoeffs.contents->size[1];
    dgCoeffs.contents->size[0] = 1;
    dgCoeffs.contents->size[1] = last;
    emxEnsureCapacity_creal_T(sp, dgCoeffs.contents, k, &i_emlrtRTEI);
    for (k = 0; k < last; k++) {
      dgCoeffs.contents->data[k].re = p_log_out_data[k] * gCoeffs_data[k].re;
      dgCoeffs.contents->data[k].im = p_log_out_data[k] * gCoeffs_data[k].im;
    }
  } else {
    st.site = &n_emlrtRSI;
    b_binary_expand_op(&st, &dgCoeffs, gCoeffs, last - 1, r);
  }
  if (1 > dgCoeffs.contents->size[1] - 1) {
    last = 0;
  } else {
    if (1 > dgCoeffs.contents->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, dgCoeffs.contents->size[1],
                                    &d_emlrtBCI, (emlrtCTX)sp);
    }
    if ((dgCoeffs.contents->size[1] - 1 < 1) ||
        (dgCoeffs.contents->size[1] - 1 > dgCoeffs.contents->size[1])) {
      emlrtDynamicBoundsCheckR2012b(dgCoeffs.contents->size[1] - 1, 1,
                                    dgCoeffs.contents->size[1], &e_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    last = dgCoeffs.contents->size[1] - 1;
  }
  st.site = &m_emlrtRSI;
  if (gCoeffs->size[1] - 2 < 1) {
    r->size[0] = 1;
    r->size[1] = 0;
  } else {
    k = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] =
        (int32_T) - (1.0 - (((real_T)gCoeffs->size[1] - 1.0) - 1.0)) + 1;
    emxEnsureCapacity_real_T(&st, r, k, &j_emlrtRTEI);
    p_log_out_data = r->data;
    idx = (int32_T) - (1.0 - (((real_T)gCoeffs->size[1] - 1.0) - 1.0));
    for (k = 0; k <= idx; k++) {
      p_log_out_data[k] = (((real_T)gCoeffs->size[1] - 1.0) - 1.0) - (real_T)k;
    }
  }
  if ((last != r->size[1]) && ((last != 1) && (r->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(last, r->size[1], &b_emlrtECI, (emlrtCTX)sp);
  }
  emxInit_creal_T(sp, &ddgCoeffs, 2, &k_emlrtRTEI);
  if (last == r->size[1]) {
    k = ddgCoeffs->size[0] * ddgCoeffs->size[1];
    ddgCoeffs->size[0] = 1;
    ddgCoeffs->size[1] = last;
    emxEnsureCapacity_creal_T(sp, ddgCoeffs, k, &k_emlrtRTEI);
    ddgCoeffs_data = ddgCoeffs->data;
    for (k = 0; k < last; k++) {
      ddgCoeffs_data[k].re = p_log_out_data[k] * dgCoeffs.contents->data[k].re;
      ddgCoeffs_data[k].im = p_log_out_data[k] * dgCoeffs.contents->data[k].im;
    }
  } else {
    st.site = &m_emlrtRSI;
    binary_expand_op(&st, ddgCoeffs, &dgCoeffs, last - 1, r);
  }
  emxFree_real_T(sp, &r);
  /*  may not need this yet - but it's the local error est */
  /*  get parameters for halting zones */
  if (1 > gCoeffs->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, gCoeffs->size[1], &f_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  st.site = &l_emlrtRSI;
  /*  computes the constant which determines how large / narrow the SD path */
  /*  must be before it cannot leave the complex segment */
  Cnr = 0.0;
  k = gCoeffs->size[1];
  for (j = 0; j <= k - 3; j++) {
    last = (gCoeffs->size[1] - j) - 1;
    if ((last < 1) || (last > gCoeffs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(last, 1, gCoeffs->size[1], &p_emlrtBCI,
                                    &st);
    }
    idx = (gCoeffs->size[1] - j) - 1;
    if ((idx < 1) || (idx > gCoeffs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, gCoeffs->size[1], &p_emlrtBCI, &st);
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
  emxInit_real_T(&st, &p_log, 1, &l_emlrtRTEI);
  Cnr /= ((real_T)gCoeffs->size[1] - 1.0) *
         muDoubleScalarHypot(gCoeffs_data[0].re, gCoeffs_data[0].im);
  /*  C =
   * norm(sum(fliplr(1:(deg-1)).*abs(coeffs(1:(deg-1))))/(deg*abs(coeffs(1))));
   */
  /*  main loop */
  h.contents = h0;
  if (!(n_max >= 0.0)) {
    emlrtNonNegativeCheckR2012b((real_T)n_max, &b_emlrtDCI, (emlrtCTX)sp);
  }
  p_step_size = (real_T)(int64_T)muDoubleScalarFloor((real_T)n_max);
  if (p_step_size != (int32_T)muDoubleScalarFloor(p_step_size)) {
    emlrtIntegerCheckR2012b(p_step_size, &emlrtDCI, (emlrtCTX)sp);
  }
  k = p_log->size[0];
  p_log->size[0] = (int32_T)(int64_T)muDoubleScalarFloor(p_step_size);
  emxEnsureCapacity_real_T(sp, p_log, k, &l_emlrtRTEI);
  p_log_data = p_log->data;
  if (!(n_max >= 0.0)) {
    emlrtNonNegativeCheckR2012b((real_T)n_max, &b_emlrtDCI, (emlrtCTX)sp);
  }
  if (p_step_size != (int32_T)muDoubleScalarFloor(p_step_size)) {
    emlrtIntegerCheckR2012b(p_step_size, &emlrtDCI, (emlrtCTX)sp);
  }
  last = (int32_T)(int64_T)muDoubleScalarFloor(p_step_size);
  for (k = 0; k < last; k++) {
    p_log_data[k] = 0.0;
  }
  emxInit_creal_T(sp, &h_log, 1, &m_emlrtRTEI);
  if (!(n_max >= 0.0)) {
    emlrtNonNegativeCheckR2012b((real_T)n_max, &d_emlrtDCI, (emlrtCTX)sp);
  }
  if (p_step_size != (int32_T)muDoubleScalarFloor(p_step_size)) {
    emlrtIntegerCheckR2012b(p_step_size, &c_emlrtDCI, (emlrtCTX)sp);
  }
  k = h_log->size[0];
  h_log->size[0] = (int32_T)(int64_T)muDoubleScalarFloor(p_step_size);
  emxEnsureCapacity_creal_T(sp, h_log, k, &m_emlrtRTEI);
  h_log_data = h_log->data;
  if (!(n_max >= 0.0)) {
    emlrtNonNegativeCheckR2012b((real_T)n_max, &d_emlrtDCI, (emlrtCTX)sp);
  }
  if (p_step_size != (int32_T)muDoubleScalarFloor(p_step_size)) {
    emlrtIntegerCheckR2012b(p_step_size, &c_emlrtDCI, (emlrtCTX)sp);
  }
  last = (int32_T)(int64_T)muDoubleScalarFloor(p_step_size);
  for (k = 0; k < last; k++) {
    h_log_data[k].re = 0.0;
    h_log_data[k].im = 2.2204460492503131E-16;
  }
  if (1 > (int32_T)n_max) {
    emlrtDynamicBoundsCheckR2012b(1, 1, (int32_T)n_max, &g_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  p_log_data[0] = 0.0;
  if (1 > h_log->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, h_log->size[0], &k_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  h_log_data[0] = h0;
  n = 1U;
  emxInit_real_T(sp, &varargin_1, 1, &r_emlrtRTEI);
  emxInit_creal_T(sp, &c_SPs, 1, &p_emlrtRTEI);
  exitg1 = false;
  do {
    exitg11 = 0;
    st.site = &k_emlrtRSI;
    if ((!exitg1) && (!halt_euler(&st, &h, &b_SPs, &b_cover_radii, &b_valleys,
                                  &b_gCoeffs, &b_r_star))) {
      /*  get ingreidents which will be used multiple times */
      n++;
      dg_h.contents = polyval(dgCoeffs.contents, h.contents);
      /*  Forward Euler step */
      if (dg_h.contents.im == 0.0) {
        F_h.re = 0.0;
        F_h.im = 1.0 / dg_h.contents.re;
      } else if (dg_h.contents.re == 0.0) {
        F_h.re = 1.0 / dg_h.contents.im;
        F_h.im = 0.0;
      } else {
        brm = muDoubleScalarAbs(dg_h.contents.re);
        p_step_size = muDoubleScalarAbs(dg_h.contents.im);
        if (brm > p_step_size) {
          p_step_size = dg_h.contents.im / dg_h.contents.re;
          brm = dg_h.contents.re + p_step_size * dg_h.contents.im;
          F_h.re = p_step_size / brm;
          F_h.im = (1.0 - p_step_size * 0.0) / brm;
        } else if (p_step_size == brm) {
          if (dg_h.contents.re > 0.0) {
            p_step_size = 0.5;
          } else {
            p_step_size = -0.5;
          }
          if (dg_h.contents.im > 0.0) {
            sgnbi = 0.5;
          } else {
            sgnbi = -0.5;
          }
          F_h.re = (0.0 * p_step_size + sgnbi) / brm;
          F_h.im = (p_step_size - 0.0 * sgnbi) / brm;
        } else {
          p_step_size = dg_h.contents.re / dg_h.contents.im;
          brm = dg_h.contents.im + p_step_size * dg_h.contents.re;
          F_h.re = (p_step_size * 0.0 + 1.0) / brm;
          F_h.im = p_step_size / brm;
        }
      }
      dg_h_re = dg_h.contents.re * dg_h.contents.re -
                dg_h.contents.im * dg_h.contents.im;
      p_step_size = dg_h.contents.re * dg_h.contents.im;
      dg_h_im = p_step_size + p_step_size;
      dc = polyval(ddgCoeffs, h.contents);
      if (dc.im == 0.0) {
        if (dg_h_im == 0.0) {
          z_re = dg_h_re / dc.re;
          brm = 0.0;
        } else if (dg_h_re == 0.0) {
          z_re = 0.0;
          brm = dg_h_im / dc.re;
        } else {
          z_re = dg_h_re / dc.re;
          brm = dg_h_im / dc.re;
        }
      } else if (dc.re == 0.0) {
        if (dg_h_re == 0.0) {
          z_re = dg_h_im / dc.im;
          brm = 0.0;
        } else if (dg_h_im == 0.0) {
          z_re = 0.0;
          brm = -(dg_h_re / dc.im);
        } else {
          z_re = dg_h_im / dc.im;
          brm = -(dg_h_re / dc.im);
        }
      } else {
        brm = muDoubleScalarAbs(dc.re);
        p_step_size = muDoubleScalarAbs(dc.im);
        if (brm > p_step_size) {
          p_step_size = dc.im / dc.re;
          brm = dc.re + p_step_size * dc.im;
          z_re = (dg_h_re + p_step_size * dg_h_im) / brm;
          brm = (dg_h_im - p_step_size * dg_h_re) / brm;
        } else if (p_step_size == brm) {
          if (dc.re > 0.0) {
            p_step_size = 0.5;
          } else {
            p_step_size = -0.5;
          }
          if (dc.im > 0.0) {
            sgnbi = 0.5;
          } else {
            sgnbi = -0.5;
          }
          z_re = (dg_h_re * p_step_size + dg_h_im * sgnbi) / brm;
          brm = (dg_h_im * p_step_size - dg_h_re * sgnbi) / brm;
        } else {
          p_step_size = dc.re / dc.im;
          brm = dc.im + p_step_size * dc.re;
          z_re = (p_step_size * dg_h_re + dg_h_im) / brm;
          brm = (p_step_size * dg_h_im - dg_h_re) / brm;
        }
      }
      st.site = &j_emlrtRSI;
      k = c_SPs->size[0];
      c_SPs->size[0] = b_SPs.contents->size[0];
      emxEnsureCapacity_creal_T(&st, c_SPs, k, &p_emlrtRTEI);
      ddgCoeffs_data = c_SPs->data;
      last = b_SPs.contents->size[0];
      for (k = 0; k < last; k++) {
        ddgCoeffs_data[k].re = b_SPs.contents->data[k].re - h.contents.re;
        ddgCoeffs_data[k].im = b_SPs.contents->data[k].im - h.contents.im;
      }
      b_st.site = &j_emlrtRSI;
      b_abs(&b_st, c_SPs, varargin_1);
      p_log_out_data = varargin_1->data;
      b_st.site = &kb_emlrtRSI;
      c_st.site = &lb_emlrtRSI;
      d_st.site = &mb_emlrtRSI;
      if (varargin_1->size[0] < 1) {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
            "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }
      e_st.site = &nb_emlrtRSI;
      f_st.site = &ob_emlrtRSI;
      last = varargin_1->size[0];
      if (varargin_1->size[0] <= 2) {
        if (varargin_1->size[0] == 1) {
          sgnbi = p_log_out_data[0];
        } else if ((p_log_out_data[0] > p_log_out_data[1]) ||
                   (muDoubleScalarIsNaN(p_log_out_data[0]) &&
                    (!muDoubleScalarIsNaN(p_log_out_data[1])))) {
          sgnbi = p_log_out_data[1];
        } else {
          sgnbi = p_log_out_data[0];
        }
      } else {
        g_st.site = &hb_emlrtRSI;
        if (!muDoubleScalarIsNaN(p_log_out_data[0])) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &ib_emlrtRSI;
          if (varargin_1->size[0] > 2147483646) {
            i_st.site = &q_emlrtRSI;
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
          sgnbi = p_log_out_data[0];
        } else {
          g_st.site = &gb_emlrtRSI;
          sgnbi = p_log_out_data[idx - 1];
          j = idx + 1;
          h_st.site = &jb_emlrtRSI;
          if ((idx + 1 <= varargin_1->size[0]) &&
              (varargin_1->size[0] > 2147483646)) {
            i_st.site = &q_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          for (k = j; k <= last; k++) {
            p_step_size = p_log_out_data[k - 1];
            if (sgnbi > p_step_size) {
              sgnbi = p_step_size;
            }
          }
        }
      }
      p_step_size =
          base_step_size *
          muDoubleScalarMin(muDoubleScalarHypot(z_re, brm),
                            sgnbi / muDoubleScalarHypot(F_h.re, F_h.im));
      h.contents.re += p_step_size * F_h.re;
      h.contents.im += p_step_size * F_h.im;
      /*  error checking */
      /*          longitude_err = imag(g_h)-imag(g_se)-p; */
      /*          transverse_err = real(g_h)-real(g_se); */
      if (((int32_T)((real_T)n - 1.0) < 1) ||
          ((int32_T)((real_T)n - 1.0) > p_log->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((real_T)n - 1.0), 1,
                                      p_log->size[0], &h_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      p.contents = p_log_data[(int32_T)n - 2] + p_step_size;
      st.site = &i_emlrtRSI;
      /*     %% indended functions */
      g_h.contents = polyval(b_gCoeffs.contents, h.contents);
      dg_h.contents = polyval(dgCoeffs.contents, h.contents);
      dg_h_im = (g_h.contents.re - g_se.contents.re) - 0.0 * p.contents;
      dg_h_re = (g_h.contents.im - g_se.contents.im) - p.contents;
      if (dg_h.contents.im == 0.0) {
        if (dg_h_re == 0.0) {
          F_h.re = dg_h_im / dg_h.contents.re;
          F_h.im = 0.0;
        } else if (dg_h_im == 0.0) {
          F_h.re = 0.0;
          F_h.im = dg_h_re / dg_h.contents.re;
        } else {
          F_h.re = dg_h_im / dg_h.contents.re;
          F_h.im = dg_h_re / dg_h.contents.re;
        }
      } else if (dg_h.contents.re == 0.0) {
        if (dg_h_im == 0.0) {
          F_h.re = dg_h_re / dg_h.contents.im;
          F_h.im = 0.0;
        } else if (dg_h_re == 0.0) {
          F_h.re = 0.0;
          F_h.im = -(dg_h_im / dg_h.contents.im);
        } else {
          F_h.re = dg_h_re / dg_h.contents.im;
          F_h.im = -(dg_h_im / dg_h.contents.im);
        }
      } else {
        brm = muDoubleScalarAbs(dg_h.contents.re);
        p_step_size = muDoubleScalarAbs(dg_h.contents.im);
        if (brm > p_step_size) {
          p_step_size = dg_h.contents.im / dg_h.contents.re;
          brm = dg_h.contents.re + p_step_size * dg_h.contents.im;
          F_h.re = (dg_h_im + p_step_size * dg_h_re) / brm;
          F_h.im = (dg_h_re - p_step_size * dg_h_im) / brm;
        } else if (p_step_size == brm) {
          if (dg_h.contents.re > 0.0) {
            p_step_size = 0.5;
          } else {
            p_step_size = -0.5;
          }
          if (dg_h.contents.im > 0.0) {
            sgnbi = 0.5;
          } else {
            sgnbi = -0.5;
          }
          F_h.re = (dg_h_im * p_step_size + dg_h_re * sgnbi) / brm;
          F_h.im = (dg_h_re * p_step_size - dg_h_im * sgnbi) / brm;
        } else {
          p_step_size = dg_h.contents.re / dg_h.contents.im;
          brm = dg_h.contents.im + p_step_size * dg_h.contents.re;
          F_h.re = (p_step_size * dg_h_im + dg_h_re) / brm;
          F_h.im = (p_step_size * dg_h_re - dg_h_im) / brm;
        }
      }
      /*  might as well apply Newton once: */
      h.contents.re -= F_h.re;
      h.contents.im -= F_h.im;
      if (muDoubleScalarHypot(F_h.re, F_h.im) > Newton_big_threshold) {
        /* apply newton more times */
        st.site = &h_emlrtRSI;
        Newton_method(&st, &g_h, &b_gCoeffs, &h, &dg_h, &dgCoeffs, &g_se, &p,
                      &b_Newton_small_threshold, F_h);
      }
      if (((int32_T)n < 1) || ((int32_T)n > p_log->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)n, 1, p_log->size[0],
                                      &q_emlrtBCI, (emlrtCTX)sp);
      }
      p_log_data[(int32_T)n - 1] = p.contents;
      if (((int32_T)n < 1) || ((int32_T)n > h_log->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)n, 1, h_log->size[0],
                                      &r_emlrtBCI, (emlrtCTX)sp);
      }
      h_log_data[(int32_T)n - 1].re = h.contents.re;
      if (((int32_T)n < 1) || ((int32_T)n > h_log->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)n, 1, h_log->size[0],
                                      &r_emlrtBCI, (emlrtCTX)sp);
      }
      h_log_data[(int32_T)n - 1].im = h.contents.im;
      st.site = &g_emlrtRSI;
      if (halt_euler(&st, &h, &b_SPs, &b_cover_radii, &b_valleys, &b_gCoeffs,
                     &b_r_star)) {
        /*  beyore actually halting the process, refine this endpoint */
        st.site = &f_emlrtRSI;
        b_Newton_method(&st, &g_h, &b_gCoeffs, &h, &dg_h, &dgCoeffs, &g_se, &p,
                        &b_Newton_small_threshold);
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
      if (n_max == n) {
        *success = false;
        exitg1 = true;
      }
    } else {
      exitg11 = 1;
    }
  } while (exitg11 == 0);
  emxFree_creal_T(sp, &c_SPs);
  emxFree_real_T(sp, &varargin_1);
  emxFree_creal_T(sp, &ddgCoeffs);
  emxFreeStruct_captured_var(sp, &dgCoeffs);
  emxFreeStruct_captured_var(sp, &b_gCoeffs);
  if (1 > p_log->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, p_log->size[0], &i_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  last = (int32_T)n;
  if (((int32_T)n < 1) || ((int32_T)n > p_log->size[0])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)n, 1, p_log->size[0], &j_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  iv[0] = 1;
  iv[1] = (int32_T)n;
  st.site = &e_emlrtRSI;
  indexShapeCheck(&st, p_log->size[0], iv);
  k = p_log_out->size[0];
  p_log_out->size[0] = (int32_T)n;
  emxEnsureCapacity_real_T(sp, p_log_out, k, &n_emlrtRTEI);
  p_log_out_data = p_log_out->data;
  for (k = 0; k < last; k++) {
    p_log_out_data[k] = p_log_data[k];
  }
  emxFree_real_T(sp, &p_log);
  if (1 > h_log->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, h_log->size[0], &l_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (((int32_T)n < 1) || ((int32_T)n > h_log->size[0])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)n, 1, h_log->size[0], &m_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  iv[0] = 1;
  iv[1] = (int32_T)n;
  st.site = &d_emlrtRSI;
  indexShapeCheck(&st, h_log->size[0], iv);
  k = h_log_out->size[0];
  h_log_out->size[0] = (int32_T)n;
  emxEnsureCapacity_creal_T(sp, h_log_out, k, &o_emlrtRTEI);
  ddgCoeffs_data = h_log_out->data;
  for (k = 0; k < last; k++) {
    ddgCoeffs_data[k] = h_log_data[k];
  }
  emxFree_creal_T(sp, &h_log);
  if (*success) {
    st.site = &c_emlrtRSI;
    if (inAball(&st, h.contents, b_SPs.contents, b_cover_radii.contents)) {
      st.site = &b_emlrtRSI;
      b_inAball(&st, h.contents, b_SPs.contents, b_cover_radii.contents, &a__2,
                &p_step_size);
      ball_index_size[0] = 1;
      ball_index_size[1] = 1;
      ball_index_data[0] = p_step_size;
    } else {
      st.site = &emlrtRSI;
      beyondNoReturn(
          &st, h.contents, Cnr,
          muDoubleScalarAtan2(gCoeffs_data[0].im, gCoeffs_data[0].re),
          b_valleys.contents, &a__2, &p_step_size);
      valley_index_size[0] = 1;
      valley_index_size[1] = 1;
      valley_index_data[0] = p_step_size;
    }
  }
  emxFreeStruct_captured_var(sp, &b_SPs);
  emxFreeStruct_captured_var1(sp, &b_cover_radii);
  emxFreeStruct_captured_var(sp, &b_valleys);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (SDpathODEuler_v3.c) */
