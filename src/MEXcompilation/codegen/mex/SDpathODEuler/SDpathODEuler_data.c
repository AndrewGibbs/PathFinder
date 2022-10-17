/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDpathODEuler_data.c
 *
 * Code generation for function 'SDpathODEuler_data'
 *
 */

/* Include files */
#include "SDpathODEuler_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131611U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "SDpathODEuler",                                      /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

emlrtRSInfo k_emlrtRSI = {
    21,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" /* pathName */
};

emlrtRSInfo n_emlrtRSI = {
    13,               /* lineNo */
    "beyondNoReturn", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn.m" /* pathName
                                                                        */
};

emlrtRSInfo o_emlrtRSI = {
    16,               /* lineNo */
    "beyondNoReturn", /* fcnName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn.m" /* pathName
                                                                        */
};

emlrtRSInfo q_emlrtRSI =
    {
        74,                    /* lineNo */
        "applyScalarFunction", /* fcnName */
        "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
        "applyScalarFunction.m" /* pathName */
};

emlrtRSInfo u_emlrtRSI = {
    17,                                                        /* lineNo */
    "min",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/min.m" /* pathName */
};

emlrtRSInfo v_emlrtRSI = {
    40,         /* lineNo */
    "minOrMax", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                       */
};

emlrtRSInfo w_emlrtRSI = {
    90,        /* lineNo */
    "minimum", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                       */
};

emlrtRSInfo x_emlrtRSI = {
    169,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m" /* pathName
                                                                            */
};

emlrtRSInfo y_emlrtRSI = {
    62,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

emlrtRSInfo ab_emlrtRSI = {
    54,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

emlrtRSInfo bb_emlrtRSI = {
    103,         /* lineNo */
    "findFirst", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

emlrtRSInfo cb_emlrtRSI = {
    120,                        /* lineNo */
    "minOrMaxRealVectorKernel", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

emlrtRSInfo db_emlrtRSI = {
    15,                                                        /* lineNo */
    "min",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/min.m" /* pathName */
};

emlrtRSInfo eb_emlrtRSI = {
    46,         /* lineNo */
    "minOrMax", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                       */
};

emlrtRSInfo fb_emlrtRSI = {
    92,        /* lineNo */
    "minimum", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                       */
};

emlrtRSInfo gb_emlrtRSI = {
    204,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m" /* pathName
                                                                            */
};

emlrtRSInfo hb_emlrtRSI = {
    893,                    /* lineNo */
    "minRealVectorOmitNaN", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m" /* pathName
                                                                            */
};

emlrtRTEInfo emlrtRTEI = {
    130,             /* lineNo */
    27,              /* colNo */
    "unaryMinOrMax", /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m" /* pName
                                                                            */
};

emlrtBCInfo u_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    14,               /* lineNo */
    21,               /* colNo */
    "V",              /* aName */
    "beyondNoReturn", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn.m", /* pName
                                                                         */
    0 /* checkKind */
};

emlrtRTEInfo s_emlrtRTEI = {
    13,               /* lineNo */
    27,               /* colNo */
    "beyondNoReturn", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn.m" /* pName
                                                                        */
};

emlrtRTEInfo t_emlrtRTEI = {
    13,               /* lineNo */
    34,               /* colNo */
    "beyondNoReturn", /* fName */
    "/home/andrew/Dropbox/PathFinderInf/src/contours/beyondNoReturn.m" /* pName
                                                                        */
};

emlrtRTEInfo u_emlrtRTEI =
    {
        30,                    /* lineNo */
        21,                    /* colNo */
        "applyScalarFunction", /* fName */
        "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
        "applyScalarFunction.m" /* pName */
};

/* End of code generation (SDpathODEuler_data.c) */
