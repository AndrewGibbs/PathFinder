/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_stepest_exits_on_ball.c
 *
 * Code generation for function 'get_stepest_exits_on_ball'
 *
 */

/* Include files */
#include "get_stepest_exits_on_ball.h"
#include "abs.h"
#include "angle.h"
#include "cos.h"
#include "diag.h"
#include "eig.h"
#include "exp.h"
#include "eye.h"
#include "get_stepest_exits_on_ball_data.h"
#include "get_stepest_exits_on_ball_emxutil.h"
#include "get_stepest_exits_on_ball_types.h"
#include "log.h"
#include "mpower.h"
#include "nchoosek.h"
#include "rt_nonfinite.h"
#include "sin.h"
#include "sum.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    2,                           /* lineNo */
    "get_stepest_exits_on_ball", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    15,                          /* lineNo */
    "get_stepest_exits_on_ball", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    17,                          /* lineNo */
    "get_stepest_exits_on_ball", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    23,                          /* lineNo */
    "get_stepest_exits_on_ball", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    39,                          /* lineNo */
    "get_stepest_exits_on_ball", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    42,                          /* lineNo */
    "get_stepest_exits_on_ball", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    46,                          /* lineNo */
    "get_stepest_exits_on_ball", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    47,                          /* lineNo */
    "get_stepest_exits_on_ball", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    48,                          /* lineNo */
    "get_stepest_exits_on_ball", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    50,                          /* lineNo */
    "get_stepest_exits_on_ball", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    56,                          /* lineNo */
    "get_stepest_exits_on_ball", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pathName */
};

static emlrtRSInfo l_emlrtRSI = {
    58,                          /* lineNo */
    "get_stepest_exits_on_ball", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    62,                          /* lineNo */
    "get_stepest_exits_on_ball", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    7,                                                           /* lineNo */
    "ref/ref",                                                   /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/ref.m" /* pathName */
};

static emlrtRSInfo lb_emlrtRSI = {
    28,                                                          /* lineNo */
    "cat",                                                       /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/cat.m" /* pathName */
};

static emlrtRSInfo mb_emlrtRSI = {
    100,                                                         /* lineNo */
    "cat_impl",                                                  /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/cat.m" /* pathName */
};

static emlrtRTEInfo emlrtRTEI = {
    275,                                                         /* lineNo */
    27,                                                          /* colNo */
    "check_non_axis_size",                                       /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/cat.m" /* pName */
};

static emlrtECInfo emlrtECI = {
    1,                           /* nDims */
    58,                          /* lineNo */
    23,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    58,                          /* lineNo */
    35,                          /* colNo */
    "db",                        /* aName */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    0                              /* checkKind */
};

static emlrtECInfo b_emlrtECI = {
    1,                           /* nDims */
    56,                          /* lineNo */
    19,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    56,                          /* lineNo */
    31,                          /* colNo */
    "da",                        /* aName */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    0                              /* checkKind */
};

static emlrtECInfo c_emlrtECI = {
    1,                           /* nDims */
    48,                          /* lineNo */
    29,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    42,                          /* lineNo */
    49,                          /* colNo */
    "b",                         /* aName */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    42,                          /* lineNo */
    37,                          /* colNo */
    "a",                         /* aName */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    0                              /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    41,                          /* lineNo */
    11,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtDCInfo emlrtDCI = {
    39,                          /* lineNo */
    25,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    1                              /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    39,                          /* lineNo */
    25,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    4                              /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    23,                          /* lineNo */
    24,                          /* colNo */
    "A",                         /* aName */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    69,                                  /* lineNo */
    23,                                  /* colNo */
    "a",                                 /* aName */
    "get_stepest_exits_on_ball/get_h_j", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    0                              /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    39,                          /* lineNo */
    67,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    1                              /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    39,                          /* lineNo */
    67,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    4                              /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    24,                          /* lineNo */
    11,                          /* colNo */
    "a",                         /* aName */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    25,                          /* lineNo */
    12,                          /* colNo */
    "da",                        /* aName */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    27,                          /* lineNo */
    15,                          /* colNo */
    "b",                         /* aName */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    28,                          /* lineNo */
    16,                          /* colNo */
    "db",                        /* aName */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    0                              /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    39,                          /* lineNo */
    59,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    1                              /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    39,                          /* lineNo */
    59,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    4                              /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    67,                                  /* lineNo */
    33,                                  /* colNo */
    "b",                                 /* aName */
    "get_stepest_exits_on_ball/get_h_j", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    71,                                  /* lineNo */
    33,                                  /* colNo */
    "b",                                 /* aName */
    "get_stepest_exits_on_ball/get_h_j", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    50,                          /* lineNo */
    49,                          /* colNo */
    "complex_angular_roots",     /* aName */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    62,                          /* lineNo */
    47,                          /* colNo */
    "turning_points",            /* aName */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    15,                          /* lineNo */
    13,                          /* colNo */
    "g_coeffs",                  /* aName */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    76,                  /* lineNo */
    9,                   /* colNo */
    "A",                 /* aName */
    "eml_mtimes_helper", /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    76,                  /* lineNo */
    9,                   /* colNo */
    "dA",                /* aName */
    "eml_mtimes_helper", /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,                                                           /* iFirst */
    -1,                                                           /* iLast */
    52,                                                           /* lineNo */
    5,                                                            /* colNo */
    "B",                                                          /* aName */
    "div",                                                        /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/div.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    67,                                  /* lineNo */
    21,                                  /* colNo */
    "a",                                 /* aName */
    "get_stepest_exits_on_ball/get_h_j", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    71,                                  /* lineNo */
    21,                                  /* colNo */
    "a",                                 /* aName */
    "get_stepest_exits_on_ball/get_h_j", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m", /* pName */
    0                              /* checkKind */
};

static emlrtRTEInfo o_emlrtRTEI = {
    5,                           /* lineNo */
    5,                           /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    6,                           /* lineNo */
    5,                           /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    7,                           /* lineNo */
    5,                           /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo r_emlrtRTEI = {
    8,                           /* lineNo */
    5,                           /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    9,                           /* lineNo */
    5,                           /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo t_emlrtRTEI = {
    10,                          /* lineNo */
    5,                           /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo u_emlrtRTEI = {
    23,                          /* lineNo */
    20,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    28,                                                          /* lineNo */
    5,                                                           /* colNo */
    "cat",                                                       /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/cat.m" /* pName */
};

static emlrtRTEInfo w_emlrtRTEI = {
    39,                          /* lineNo */
    5,                           /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo x_emlrtRTEI = {
    48,                          /* lineNo */
    47,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo y_emlrtRTEI = {
    48,                          /* lineNo */
    5,                           /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    50,                          /* lineNo */
    53,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    50,                          /* lineNo */
    49,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    1,                           /* lineNo */
    16,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = {
    54,                          /* lineNo */
    5,                           /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    56,                          /* lineNo */
    37,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = {
    62,                          /* lineNo */
    25,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    58,                          /* lineNo */
    41,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    47,                          /* lineNo */
    5,                           /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = {
    50,                          /* lineNo */
    5,                           /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = {
    62,                          /* lineNo */
    47,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = {
    39,                          /* lineNo */
    19,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = {
    39,                          /* lineNo */
    36,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo qc_emlrtRTEI = {
    58,                          /* lineNo */
    23,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = {
    48,                          /* lineNo */
    29,                          /* colNo */
    "get_stepest_exits_on_ball", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/"
    "get_stepest_exits_on_ball.m" /* pName */
};

/* Function Declarations */
static void binary_expand_op(const emlrtStack *sp, emxArray_creal_T *eig_vals,
                             const emxArray_real_T *tp_vals);

static void plus(const emlrtStack *sp, emxArray_real_T *tp_vals,
                 const emxArray_real_T *b);

/* Function Definitions */
static void binary_expand_op(const emlrtStack *sp, emxArray_creal_T *eig_vals,
                             const emxArray_real_T *tp_vals)
{
  emxArray_creal_T *b_tp_vals;
  creal_T *b_tp_vals_data;
  creal_T *eig_vals_data;
  const real_T *tp_vals_data;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  tp_vals_data = tp_vals->data;
  eig_vals_data = eig_vals->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_creal_T(sp, &b_tp_vals, 1, &rc_emlrtRTEI);
  i = b_tp_vals->size[0];
  if (eig_vals->size[0] == 1) {
    b_tp_vals->size[0] = tp_vals->size[0];
  } else {
    b_tp_vals->size[0] = eig_vals->size[0];
  }
  emxEnsureCapacity_creal_T(sp, b_tp_vals, i, &rc_emlrtRTEI);
  b_tp_vals_data = b_tp_vals->data;
  stride_0_0 = (tp_vals->size[0] != 1);
  stride_1_0 = (eig_vals->size[0] != 1);
  if (eig_vals->size[0] == 1) {
    loop_ub = tp_vals->size[0];
  } else {
    loop_ub = eig_vals->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    i1 = i * stride_1_0;
    b_tp_vals_data[i].re = tp_vals_data[i * stride_0_0] - eig_vals_data[i1].re;
    b_tp_vals_data[i].im = 0.0 - eig_vals_data[i1].im;
  }
  i = eig_vals->size[0];
  eig_vals->size[0] = b_tp_vals->size[0];
  emxEnsureCapacity_creal_T(sp, eig_vals, i, &rc_emlrtRTEI);
  eig_vals_data = eig_vals->data;
  loop_ub = b_tp_vals->size[0];
  for (i = 0; i < loop_ub; i++) {
    eig_vals_data[i] = b_tp_vals_data[i];
  }
  emxFree_creal_T(sp, &b_tp_vals);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void plus(const emlrtStack *sp, emxArray_real_T *tp_vals,
                 const emxArray_real_T *b)
{
  emxArray_real_T *b_tp_vals;
  const real_T *b_data;
  real_T *b_tp_vals_data;
  real_T *tp_vals_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  b_data = b->data;
  tp_vals_data = tp_vals->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_tp_vals, 1, &qc_emlrtRTEI);
  i = b_tp_vals->size[0];
  if (b->size[0] == 1) {
    b_tp_vals->size[0] = tp_vals->size[0];
  } else {
    b_tp_vals->size[0] = b->size[0];
  }
  emxEnsureCapacity_real_T(sp, b_tp_vals, i, &qc_emlrtRTEI);
  b_tp_vals_data = b_tp_vals->data;
  stride_0_0 = (tp_vals->size[0] != 1);
  stride_1_0 = (b->size[0] != 1);
  if (b->size[0] == 1) {
    loop_ub = tp_vals->size[0];
  } else {
    loop_ub = b->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    b_tp_vals_data[i] = tp_vals_data[i * stride_0_0] + b_data[i * stride_1_0];
  }
  i = tp_vals->size[0];
  tp_vals->size[0] = b_tp_vals->size[0];
  emxEnsureCapacity_real_T(sp, tp_vals, i, &qc_emlrtRTEI);
  tp_vals_data = tp_vals->data;
  loop_ub = b_tp_vals->size[0];
  for (i = 0; i < loop_ub; i++) {
    tp_vals_data[i] = b_tp_vals_data[i];
  }
  emxFree_real_T(sp, &b_tp_vals);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void get_stepest_exits_on_ball(const emlrtStack *sp,
                               const emxArray_creal_T *g_coeffs,
                               const creal_T centre, real_T radius,
                               emxArray_creal_T *SEs)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_boolean_T *r;
  emxArray_creal_T *A;
  emxArray_creal_T *E;
  emxArray_creal_T *dA;
  emxArray_creal_T *eig_vals;
  emxArray_int32_T *r2;
  emxArray_real_T *a_contents;
  emxArray_real_T *da;
  emxArray_real_T *db;
  emxArray_real_T *result;
  emxArray_real_T *tp_vals;
  emxArray_real_T *turning_points;
  emxArray_real_T *varargin_2;
  const creal_T *g_coeffs_data;
  creal_T main_coeff;
  creal_T *A_data;
  creal_T *dA_data;
  real_T a_im;
  real_T a_re;
  real_T bi;
  real_T br;
  real_T brm;
  real_T *a_contents_data;
  real_T *da_data;
  real_T *db_data;
  real_T *result_data;
  real_T *tp_vals_data;
  real_T *turning_points_data;
  int32_T i;
  int32_T i1;
  int32_T input_sizes_idx_0;
  int32_T k;
  int32_T rho_contents;
  int32_T sizes_idx_1;
  int32_T *r3;
  int8_T input_sizes_idx_1;
  boolean_T empty_non_axis_sizes;
  boolean_T *r1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  g_coeffs_data = g_coeffs->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_creal_T(sp, &A, 2, &o_emlrtRTEI);
  st.site = &emlrtRSI;
  b_st.site = &n_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &n_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &n_emlrtRSI;
  rho_contents = g_coeffs->size[0] - 1;
  /*  order of g'(z) */
  /*       */
  i = A->size[0] * A->size[1];
  A->size[0] = g_coeffs->size[0];
  A->size[1] = g_coeffs->size[0];
  emxEnsureCapacity_creal_T(sp, A, i, &o_emlrtRTEI);
  A_data = A->data;
  input_sizes_idx_0 = g_coeffs->size[0] * g_coeffs->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    A_data[i].re = 0.0;
    A_data[i].im = 0.0;
  }
  emxInit_creal_T(sp, &dA, 2, &p_emlrtRTEI);
  /*  matrix of indices of double sum */
  i = dA->size[0] * dA->size[1];
  dA->size[0] = g_coeffs->size[0];
  dA->size[1] = g_coeffs->size[0];
  emxEnsureCapacity_creal_T(sp, dA, i, &p_emlrtRTEI);
  dA_data = dA->data;
  input_sizes_idx_0 = g_coeffs->size[0] * g_coeffs->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    dA_data[i].re = 0.0;
    dA_data[i].im = 0.0;
  }
  emxInit_real_T(sp, &a_contents, 1, &q_emlrtRTEI);
  /*  matrix of indices of double sum, deriv */
  i = a_contents->size[0];
  a_contents->size[0] = g_coeffs->size[0];
  emxEnsureCapacity_real_T(sp, a_contents, i, &q_emlrtRTEI);
  a_contents_data = a_contents->data;
  input_sizes_idx_0 = g_coeffs->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    a_contents_data[i] = 0.0;
  }
  emxInit_real_T(sp, &tp_vals, 1, &db_emlrtRTEI);
  /*  cosine indices */
  i = tp_vals->size[0];
  tp_vals->size[0] = g_coeffs->size[0];
  emxEnsureCapacity_real_T(sp, tp_vals, i, &r_emlrtRTEI);
  tp_vals_data = tp_vals->data;
  input_sizes_idx_0 = g_coeffs->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    tp_vals_data[i] = 0.0;
  }
  emxInit_real_T(sp, &da, 1, &s_emlrtRTEI);
  /*  sine indices */
  i = da->size[0];
  da->size[0] = g_coeffs->size[0];
  emxEnsureCapacity_real_T(sp, da, i, &s_emlrtRTEI);
  da_data = da->data;
  input_sizes_idx_0 = g_coeffs->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    da_data[i] = 0.0;
  }
  emxInit_real_T(sp, &db, 1, &t_emlrtRTEI);
  /*  cosine indices, deriv */
  i = db->size[0];
  db->size[0] = g_coeffs->size[0];
  emxEnsureCapacity_real_T(sp, db, i, &t_emlrtRTEI);
  db_data = db->data;
  input_sizes_idx_0 = g_coeffs->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    db_data[i] = 0.0;
  }
  /*  sine indices, deriv */
  /*     %%  compute Fourier indices (notation as in my notes) */
  i = g_coeffs->size[0];
  for (sizes_idx_1 = 0; sizes_idx_1 < i; sizes_idx_1++) {
    if (0 <= sizes_idx_1) {
      i1 = (rho_contents - sizes_idx_1) + 1;
    }
    for (k = 0; k <= sizes_idx_1; k++) {
      st.site = &b_emlrtRSI;
      a_im = nchoosek(&st, sizes_idx_1, k) * mpower(&st, radius, k);
      main_coeff = b_mpower(centre, sizes_idx_1 - k);
      a_re = a_im * main_coeff.re;
      a_im *= main_coeff.im;
      if ((i1 < 1) || (i1 > g_coeffs->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, g_coeffs->size[0], &o_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      main_coeff.re =
          a_re * g_coeffs_data[i1 - 1].re - a_im * g_coeffs_data[i1 - 1].im;
      if (i1 > g_coeffs->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, g_coeffs->size[0], &o_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      main_coeff.im =
          a_re * g_coeffs_data[i1 - 1].im + a_im * g_coeffs_data[i1 - 1].re;
      if (sizes_idx_1 + 1 > A->size[0]) {
        emlrtDynamicBoundsCheckR2012b(sizes_idx_1 + 1, 1, A->size[0],
                                      &p_emlrtBCI, (emlrtCTX)sp);
      }
      if (k + 1 > A->size[1]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, A->size[1], &p_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      A_data[sizes_idx_1 + A->size[0] * k].re = (real_T)k * main_coeff.re;
      if (sizes_idx_1 + 1 > A->size[0]) {
        emlrtDynamicBoundsCheckR2012b(sizes_idx_1 + 1, 1, A->size[0],
                                      &p_emlrtBCI, (emlrtCTX)sp);
      }
      if (k + 1 > A->size[1]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, A->size[1], &p_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      A_data[sizes_idx_1 + A->size[0] * k].im = (real_T)k * main_coeff.im;
      st.site = &c_emlrtRSI;
      b_st.site = &q_emlrtRSI;
      if (sizes_idx_1 + 1 > dA->size[0]) {
        emlrtDynamicBoundsCheckR2012b(sizes_idx_1 + 1, 1, dA->size[0],
                                      &q_emlrtBCI, (emlrtCTX)sp);
      }
      if (k + 1 > dA->size[1]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, dA->size[1], &q_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      a_im = (real_T)k * (real_T)k;
      dA_data[sizes_idx_1 + dA->size[0] * k].re = a_im * main_coeff.re;
      if (sizes_idx_1 + 1 > dA->size[0]) {
        emlrtDynamicBoundsCheckR2012b(sizes_idx_1 + 1, 1, dA->size[0],
                                      &q_emlrtBCI, (emlrtCTX)sp);
      }
      if (k + 1 > dA->size[1]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, dA->size[1], &q_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      dA_data[sizes_idx_1 + dA->size[0] * k].im = a_im * main_coeff.im;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  /*  filtering in this way isolates the imaginary part of g'(z): */
  i = g_coeffs->size[0];
  emxInit_creal_T(sp, &eig_vals, 1, &hb_emlrtRTEI);
  for (k = 0; k < i; k++) {
    if (k + 1 > A->size[1]) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, A->size[1], &e_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    input_sizes_idx_0 = A->size[0];
    i1 = eig_vals->size[0];
    eig_vals->size[0] = A->size[0];
    emxEnsureCapacity_creal_T(sp, eig_vals, i1, &u_emlrtRTEI);
    dA_data = eig_vals->data;
    for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
      dA_data[i1] = A_data[i1 + A->size[0] * k];
    }
    st.site = &d_emlrtRSI;
    main_coeff = sum(&st, eig_vals);
    if (k + 1 > a_contents->size[0]) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, a_contents->size[0], &g_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    a_contents_data[k] = main_coeff.re;
    if (k + 1 > da->size[0]) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, da->size[0], &h_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    da_data[k] = -main_coeff.im;
    if (k > 0) {
      if (k + 1 > tp_vals->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, tp_vals->size[0], &i_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      tp_vals_data[k] = -main_coeff.im;
      if (k + 1 > db->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, db->size[0], &j_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      db_data[k] = -main_coeff.re;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxInit_real_T(sp, &result, 2, &kb_emlrtRTEI);
  /*      binomial_check; */
  /*        imag_check(); */
  /*  binomial_check(); */
  /*     %%  now find zeros of Fourier series using colleague method */
  /* ( notation as in Boyd) */
  /*  construct Frobenius matrix (with zeros in final row) */
  st.site = &e_emlrtRSI;
  a_im = 2.0 * ((real_T)g_coeffs->size[0] - 1.0) - 1.0;
  if (!(a_im >= 0.0)) {
    emlrtNonNegativeCheckR2012b(a_im, &b_emlrtDCI, &st);
  }
  if (a_im != (int32_T)a_im) {
    emlrtIntegerCheckR2012b(a_im, &emlrtDCI, &st);
  }
  emxInit_real_T(&st, &varargin_2, 2, &lb_emlrtRTEI);
  b_st.site = &e_emlrtRSI;
  eye(&b_st, 2.0 * ((real_T)g_coeffs->size[0] - 1.0) - 1.0,
      2.0 * ((real_T)g_coeffs->size[0] - 1.0) - 1.0, varargin_2);
  turning_points_data = varargin_2->data;
  b_st.site = &lb_emlrtRSI;
  if (((g_coeffs->size[0] - 1) << 1) - 1 != 0) {
    k = ((g_coeffs->size[0] - 1) << 1) - 1;
  } else if ((varargin_2->size[0] != 0) && (varargin_2->size[1] != 0)) {
    k = varargin_2->size[0];
  } else {
    i = ((g_coeffs->size[0] - 1) << 1) - 1;
    k = muIntScalarMax_sint32(i, 0);
    if (varargin_2->size[0] > k) {
      k = varargin_2->size[0];
    }
  }
  c_st.site = &mb_emlrtRSI;
  if ((((g_coeffs->size[0] - 1) << 1) - 1 != k) &&
      (((g_coeffs->size[0] - 1) << 1) - 1 != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  if ((varargin_2->size[0] != k) &&
      ((varargin_2->size[0] != 0) && (varargin_2->size[1] != 0))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  empty_non_axis_sizes = (k == 0);
  if (empty_non_axis_sizes || (((g_coeffs->size[0] - 1) << 1) - 1 != 0)) {
    input_sizes_idx_1 = 1;
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes ||
      ((varargin_2->size[0] != 0) && (varargin_2->size[1] != 0))) {
    sizes_idx_1 = varargin_2->size[1];
  } else {
    sizes_idx_1 = 0;
  }
  i = result->size[0] * result->size[1];
  result->size[0] = k;
  result->size[1] = input_sizes_idx_1 + sizes_idx_1;
  emxEnsureCapacity_real_T(&b_st, result, i, &v_emlrtRTEI);
  result_data = result->data;
  input_sizes_idx_0 = input_sizes_idx_1;
  for (i = 0; i < input_sizes_idx_0; i++) {
    for (i1 = 0; i1 < k; i1++) {
      result_data[i1] = 0.0;
    }
  }
  for (i = 0; i < sizes_idx_1; i++) {
    for (i1 = 0; i1 < k; i1++) {
      result_data[i1 + result->size[0] * (i + input_sizes_idx_1)] =
          turning_points_data[i1 + k * i];
    }
  }
  emxFree_real_T(&b_st, &varargin_2);
  st.site = &e_emlrtRSI;
  a_im = 2.0 * ((real_T)g_coeffs->size[0] - 1.0);
  if (!(a_im >= 0.0)) {
    emlrtNonNegativeCheckR2012b(a_im, &d_emlrtDCI, &st);
  }
  if (a_im != (int32_T)a_im) {
    emlrtIntegerCheckR2012b(a_im, &c_emlrtDCI, &st);
  }
  a_im = 2.0 * ((real_T)g_coeffs->size[0] - 1.0);
  if (!(a_im >= 0.0)) {
    emlrtNonNegativeCheckR2012b(a_im, &f_emlrtDCI, &st);
  }
  if (a_im != (int32_T)a_im) {
    emlrtIntegerCheckR2012b(a_im, &e_emlrtDCI, &st);
  }
  b_st.site = &lb_emlrtRSI;
  if ((result->size[0] != 0) && (result->size[1] != 0)) {
    k = result->size[1];
  } else if ((g_coeffs->size[0] - 1) << 1 != 0) {
    k = (g_coeffs->size[0] - 1) << 1;
  } else {
    k = result->size[1];
    if (((g_coeffs->size[0] - 1) << 1) > result->size[1]) {
      k = (g_coeffs->size[0] - 1) << 1;
    }
  }
  c_st.site = &mb_emlrtRSI;
  if ((result->size[1] != k) &&
      ((result->size[0] != 0) && (result->size[1] != 0))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  if (((g_coeffs->size[0] - 1) << 1 != k) &&
      ((g_coeffs->size[0] - 1) << 1 != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  empty_non_axis_sizes = (k == 0);
  if (empty_non_axis_sizes ||
      ((result->size[0] != 0) && (result->size[1] != 0))) {
    input_sizes_idx_0 = result->size[0];
  } else {
    input_sizes_idx_0 = 0;
  }
  if (empty_non_axis_sizes || ((g_coeffs->size[0] - 1) << 1 != 0)) {
    sizes_idx_1 = 1;
  } else {
    sizes_idx_1 = 0;
  }
  i = A->size[0] * A->size[1];
  A->size[0] = input_sizes_idx_0 + sizes_idx_1;
  A->size[1] = k;
  emxEnsureCapacity_creal_T(sp, A, i, &w_emlrtRTEI);
  A_data = A->data;
  for (i = 0; i < k; i++) {
    for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
      A_data[i1 + A->size[0] * i].re = result_data[i1 + input_sizes_idx_0 * i];
      A_data[i1 + A->size[0] * i].im = 0.0;
    }
  }
  emxFree_real_T(sp, &result);
  for (i = 0; i < k; i++) {
    for (i1 = 0; i1 < sizes_idx_1; i1++) {
      A_data[input_sizes_idx_0 + A->size[0] * i].re = 0.0;
      A_data[input_sizes_idx_0 + A->size[0] * i].im = 0.0;
    }
  }
  /*  now construct final row */
  a_im = 2.0 * ((real_T)g_coeffs->size[0] - 1.0);
  i = (int32_T)a_im;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, a_im, mxDOUBLE_CLASS, (int32_T)a_im,
                                &b_emlrtRTEI, (emlrtCTX)sp);
  for (k = 0; k < i; k++) {
    if (tp_vals->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(tp_vals->size[0], 1, tp_vals->size[0],
                                    &c_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &f_emlrtRSI;
    if (k < rho_contents) {
      i1 = (rho_contents - k) + 1;
      if ((i1 < 1) || (i1 > tp_vals->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, tp_vals->size[0], &k_emlrtBCI,
                                      &st);
      }
      if (i1 > a_contents->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, a_contents->size[0], &s_emlrtBCI,
                                      &st);
      }
      main_coeff.re = a_contents_data[i1 - 1];
      main_coeff.im = tp_vals_data[i1 - 1];
    } else if (k == rho_contents) {
      if (1 > a_contents->size[0]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, a_contents->size[0], &f_emlrtBCI,
                                      &st);
      }
      main_coeff.re = 2.0 * a_contents_data[0];
      main_coeff.im = 0.0;
    } else {
      i1 = (int32_T)(((((real_T)k + 1.0) - 1.0) - (real_T)rho_contents) + 1.0);
      if ((i1 < 1) || (i1 > tp_vals->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, tp_vals->size[0], &l_emlrtBCI,
                                      &st);
      }
      a_im = tp_vals_data[i1 - 1];
      if (i1 > a_contents->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, a_contents->size[0], &t_emlrtBCI,
                                      &st);
      }
      main_coeff.re = a_contents_data[i1 - 1] - 0.0 * a_im;
      main_coeff.im = 0.0 - a_im;
    }
    if (a_contents->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(a_contents->size[0], 1, a_contents->size[0],
                                    &d_emlrtBCI, (emlrtCTX)sp);
    }
    br = a_contents_data[a_contents->size[0] - 1] -
         0.0 * tp_vals_data[tp_vals->size[0] - 1];
    bi = 0.0 - tp_vals_data[tp_vals->size[0] - 1];
    if (bi == 0.0) {
      if (-main_coeff.im == 0.0) {
        if (A->size[0] < 1) {
          emlrtDynamicBoundsCheckR2012b(A->size[0], 1, A->size[0], &r_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > A->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, A->size[1],
                                        &r_emlrtBCI, (emlrtCTX)sp);
        }
        A_data[(A->size[0] + A->size[0] * k) - 1].re = -main_coeff.re / br;
        if (A->size[0] < 1) {
          emlrtDynamicBoundsCheckR2012b(A->size[0], 1, A->size[0], &r_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > A->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, A->size[1],
                                        &r_emlrtBCI, (emlrtCTX)sp);
        }
        A_data[(A->size[0] + A->size[0] * k) - 1].im = 0.0;
      } else if (-main_coeff.re == 0.0) {
        if (A->size[0] < 1) {
          emlrtDynamicBoundsCheckR2012b(A->size[0], 1, A->size[0], &r_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > A->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, A->size[1],
                                        &r_emlrtBCI, (emlrtCTX)sp);
        }
        A_data[(A->size[0] + A->size[0] * k) - 1].re = 0.0;
        if (A->size[0] < 1) {
          emlrtDynamicBoundsCheckR2012b(A->size[0], 1, A->size[0], &r_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > A->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, A->size[1],
                                        &r_emlrtBCI, (emlrtCTX)sp);
        }
        A_data[(A->size[0] + A->size[0] * k) - 1].im = -main_coeff.im / br;
      } else {
        if (A->size[0] < 1) {
          emlrtDynamicBoundsCheckR2012b(A->size[0], 1, A->size[0], &r_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > A->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, A->size[1],
                                        &r_emlrtBCI, (emlrtCTX)sp);
        }
        A_data[(A->size[0] + A->size[0] * k) - 1].re = -main_coeff.re / br;
        if (A->size[0] < 1) {
          emlrtDynamicBoundsCheckR2012b(A->size[0], 1, A->size[0], &r_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > A->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, A->size[1],
                                        &r_emlrtBCI, (emlrtCTX)sp);
        }
        A_data[(A->size[0] + A->size[0] * k) - 1].im = -main_coeff.im / br;
      }
    } else if (br == 0.0) {
      if (-main_coeff.re == 0.0) {
        if (A->size[0] < 1) {
          emlrtDynamicBoundsCheckR2012b(A->size[0], 1, A->size[0], &r_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > A->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, A->size[1],
                                        &r_emlrtBCI, (emlrtCTX)sp);
        }
        A_data[(A->size[0] + A->size[0] * k) - 1].re = -main_coeff.im / bi;
        if (A->size[0] < 1) {
          emlrtDynamicBoundsCheckR2012b(A->size[0], 1, A->size[0], &r_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > A->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, A->size[1],
                                        &r_emlrtBCI, (emlrtCTX)sp);
        }
        A_data[(A->size[0] + A->size[0] * k) - 1].im = 0.0;
      } else if (-main_coeff.im == 0.0) {
        if (A->size[0] < 1) {
          emlrtDynamicBoundsCheckR2012b(A->size[0], 1, A->size[0], &r_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > A->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, A->size[1],
                                        &r_emlrtBCI, (emlrtCTX)sp);
        }
        A_data[(A->size[0] + A->size[0] * k) - 1].re = 0.0;
        if (A->size[0] < 1) {
          emlrtDynamicBoundsCheckR2012b(A->size[0], 1, A->size[0], &r_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > A->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, A->size[1],
                                        &r_emlrtBCI, (emlrtCTX)sp);
        }
        A_data[(A->size[0] + A->size[0] * k) - 1].im = -(-main_coeff.re / bi);
      } else {
        if (A->size[0] < 1) {
          emlrtDynamicBoundsCheckR2012b(A->size[0], 1, A->size[0], &r_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > A->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, A->size[1],
                                        &r_emlrtBCI, (emlrtCTX)sp);
        }
        A_data[(A->size[0] + A->size[0] * k) - 1].re = -main_coeff.im / bi;
        if (A->size[0] < 1) {
          emlrtDynamicBoundsCheckR2012b(A->size[0], 1, A->size[0], &r_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > A->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, A->size[1],
                                        &r_emlrtBCI, (emlrtCTX)sp);
        }
        A_data[(A->size[0] + A->size[0] * k) - 1].im = -(-main_coeff.re / bi);
      }
    } else {
      brm = muDoubleScalarAbs(br);
      a_im = muDoubleScalarAbs(bi);
      if (brm > a_im) {
        a_re = bi / br;
        a_im = br + a_re * bi;
        if (A->size[0] < 1) {
          emlrtDynamicBoundsCheckR2012b(A->size[0], 1, A->size[0], &r_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > A->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, A->size[1],
                                        &r_emlrtBCI, (emlrtCTX)sp);
        }
        A_data[(A->size[0] + A->size[0] * k) - 1].re =
            (-main_coeff.re + a_re * -main_coeff.im) / a_im;
        if (A->size[0] < 1) {
          emlrtDynamicBoundsCheckR2012b(A->size[0], 1, A->size[0], &r_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > A->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, A->size[1],
                                        &r_emlrtBCI, (emlrtCTX)sp);
        }
        A_data[(A->size[0] + A->size[0] * k) - 1].im =
            (-main_coeff.im - a_re * -main_coeff.re) / a_im;
      } else if (a_im == brm) {
        if (br > 0.0) {
          a_re = 0.5;
        } else {
          a_re = -0.5;
        }
        if (bi > 0.0) {
          a_im = 0.5;
        } else {
          a_im = -0.5;
        }
        if (A->size[0] < 1) {
          emlrtDynamicBoundsCheckR2012b(A->size[0], 1, A->size[0], &r_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > A->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, A->size[1],
                                        &r_emlrtBCI, (emlrtCTX)sp);
        }
        A_data[(A->size[0] + A->size[0] * k) - 1].re =
            (-main_coeff.re * a_re + -main_coeff.im * a_im) / brm;
        if (A->size[0] < 1) {
          emlrtDynamicBoundsCheckR2012b(A->size[0], 1, A->size[0], &r_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > A->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, A->size[1],
                                        &r_emlrtBCI, (emlrtCTX)sp);
        }
        A_data[(A->size[0] + A->size[0] * k) - 1].im =
            (-main_coeff.im * a_re - -main_coeff.re * a_im) / brm;
      } else {
        a_re = br / bi;
        a_im = bi + a_re * br;
        if (A->size[0] < 1) {
          emlrtDynamicBoundsCheckR2012b(A->size[0], 1, A->size[0], &r_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > A->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, A->size[1],
                                        &r_emlrtBCI, (emlrtCTX)sp);
        }
        A_data[(A->size[0] + A->size[0] * k) - 1].re =
            (a_re * -main_coeff.re + -main_coeff.im) / a_im;
        if (A->size[0] < 1) {
          emlrtDynamicBoundsCheckR2012b(A->size[0], 1, A->size[0], &r_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (((int32_T)(k + 1U) < 1) || ((int32_T)(k + 1U) > A->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, A->size[1],
                                        &r_emlrtBCI, (emlrtCTX)sp);
        }
        A_data[(A->size[0] + A->size[0] * k) - 1].im =
            (a_re * -main_coeff.im - (-main_coeff.re)) / a_im;
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxInit_creal_T(sp, &E, 2, &cb_emlrtRTEI);
  /*  convert eigenvalues to roots */
  st.site = &g_emlrtRSI;
  eig(&st, A, dA, E);
  st.site = &h_emlrtRSI;
  diag(&st, E, eig_vals);
  st.site = &i_emlrtRSI;
  angle(&st, eig_vals, tp_vals);
  tp_vals_data = tp_vals->data;
  st.site = &i_emlrtRSI;
  b_abs(&st, eig_vals, a_contents);
  st.site = &i_emlrtRSI;
  b_log(&st, a_contents);
  a_contents_data = a_contents->data;
  i = eig_vals->size[0];
  eig_vals->size[0] = a_contents->size[0];
  emxEnsureCapacity_creal_T(sp, eig_vals, i, &x_emlrtRTEI);
  dA_data = eig_vals->data;
  input_sizes_idx_0 = a_contents->size[0];
  emxFree_creal_T(sp, &E);
  emxFree_creal_T(sp, &dA);
  emxFree_creal_T(sp, &A);
  for (i = 0; i < input_sizes_idx_0; i++) {
    dA_data[i].re = a_contents_data[i] * 0.0;
    dA_data[i].im = a_contents_data[i];
  }
  if ((tp_vals->size[0] != eig_vals->size[0]) &&
      ((tp_vals->size[0] != 1) && (eig_vals->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(tp_vals->size[0], eig_vals->size[0],
                                &c_emlrtECI, (emlrtCTX)sp);
  }
  if (tp_vals->size[0] == eig_vals->size[0]) {
    i = eig_vals->size[0];
    eig_vals->size[0] = tp_vals->size[0];
    emxEnsureCapacity_creal_T(sp, eig_vals, i, &y_emlrtRTEI);
    dA_data = eig_vals->data;
    input_sizes_idx_0 = tp_vals->size[0];
    for (i = 0; i < input_sizes_idx_0; i++) {
      dA_data[i].re = tp_vals_data[i] - dA_data[i].re;
      dA_data[i].im = 0.0 - dA_data[i].im;
    }
  } else {
    st.site = &i_emlrtRSI;
    binary_expand_op(&st, eig_vals, tp_vals);
    dA_data = eig_vals->data;
  }
  /*  now filter out real-valued roots */
  i = a_contents->size[0];
  a_contents->size[0] = eig_vals->size[0];
  emxEnsureCapacity_real_T(sp, a_contents, i, &ab_emlrtRTEI);
  a_contents_data = a_contents->data;
  input_sizes_idx_0 = eig_vals->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    a_contents_data[i] = dA_data[i].im;
  }
  emxInit_boolean_T(sp, &r, &bb_emlrtRTEI);
  st.site = &j_emlrtRSI;
  c_abs(&st, a_contents, tp_vals);
  tp_vals_data = tp_vals->data;
  i = r->size[0];
  r->size[0] = tp_vals->size[0];
  emxEnsureCapacity_boolean_T(sp, r, i, &bb_emlrtRTEI);
  r1 = r->data;
  input_sizes_idx_0 = tp_vals->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    r1[i] = (tp_vals_data[i] < 0.1);
  }
  input_sizes_idx_0 = r->size[0] - 1;
  sizes_idx_1 = 0;
  for (k = 0; k <= input_sizes_idx_0; k++) {
    if (r1[k]) {
      sizes_idx_1++;
    }
  }
  emxInit_real_T(sp, &turning_points, 1, &ib_emlrtRTEI);
  i = turning_points->size[0];
  turning_points->size[0] = sizes_idx_1;
  emxEnsureCapacity_real_T(sp, turning_points, i, &cb_emlrtRTEI);
  turning_points_data = turning_points->data;
  sizes_idx_1 = 0;
  for (k = 0; k <= input_sizes_idx_0; k++) {
    if (r1[k]) {
      if (k + 1 > eig_vals->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, eig_vals->size[0], &m_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      turning_points_data[sizes_idx_1] = dA_data[k].re;
      sizes_idx_1++;
    }
  }
  emxFree_boolean_T(sp, &r);
  emxFree_creal_T(sp, &eig_vals);
  /*      dg_coeffs = diff_coeffs(g_coeffs); */
  /*      ddg_coeffs = diff_coeffs(dg_coeffs); */
  i = tp_vals->size[0];
  tp_vals->size[0] = turning_points->size[0];
  emxEnsureCapacity_real_T(sp, tp_vals, i, &db_emlrtRTEI);
  tp_vals_data = tp_vals->data;
  input_sizes_idx_0 = turning_points->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    tp_vals_data[i] = 0.0;
  }
  i = g_coeffs->size[0];
  for (sizes_idx_1 = 0; sizes_idx_1 < i; sizes_idx_1++) {
    if (sizes_idx_1 + 1 > da->size[0]) {
      emlrtDynamicBoundsCheckR2012b(sizes_idx_1 + 1, 1, da->size[0],
                                    &b_emlrtBCI, (emlrtCTX)sp);
    }
    input_sizes_idx_0 = turning_points->size[0];
    i1 = a_contents->size[0];
    a_contents->size[0] = turning_points->size[0];
    emxEnsureCapacity_real_T(sp, a_contents, i1, &eb_emlrtRTEI);
    a_contents_data = a_contents->data;
    for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
      a_contents_data[i1] = (real_T)sizes_idx_1 * turning_points_data[i1];
    }
    st.site = &k_emlrtRSI;
    b_cos(&st, a_contents);
    a_contents_data = a_contents->data;
    input_sizes_idx_0 = a_contents->size[0];
    for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
      a_contents_data[i1] *= da_data[sizes_idx_1];
    }
    input_sizes_idx_0 = tp_vals->size[0];
    if ((tp_vals->size[0] != a_contents->size[0]) &&
        ((tp_vals->size[0] != 1) && (a_contents->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(tp_vals->size[0], a_contents->size[0],
                                  &b_emlrtECI, (emlrtCTX)sp);
    }
    if (tp_vals->size[0] == a_contents->size[0]) {
      for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
        tp_vals_data[i1] += a_contents_data[i1];
      }
    } else {
      st.site = &k_emlrtRSI;
      plus(&st, tp_vals, a_contents);
      tp_vals_data = tp_vals->data;
    }
    if (sizes_idx_1 > 0) {
      if (sizes_idx_1 + 1 > db->size[0]) {
        emlrtDynamicBoundsCheckR2012b(sizes_idx_1 + 1, 1, db->size[0],
                                      &emlrtBCI, (emlrtCTX)sp);
      }
      input_sizes_idx_0 = turning_points->size[0];
      i1 = a_contents->size[0];
      a_contents->size[0] = turning_points->size[0];
      emxEnsureCapacity_real_T(sp, a_contents, i1, &gb_emlrtRTEI);
      a_contents_data = a_contents->data;
      for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
        a_contents_data[i1] = (real_T)sizes_idx_1 * turning_points_data[i1];
      }
      st.site = &l_emlrtRSI;
      b_sin(&st, a_contents);
      a_contents_data = a_contents->data;
      input_sizes_idx_0 = a_contents->size[0];
      for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
        a_contents_data[i1] *= db_data[sizes_idx_1];
      }
      input_sizes_idx_0 = tp_vals->size[0];
      if ((tp_vals->size[0] != a_contents->size[0]) &&
          ((tp_vals->size[0] != 1) && (a_contents->size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(tp_vals->size[0], a_contents->size[0],
                                    &emlrtECI, (emlrtCTX)sp);
      }
      if (tp_vals->size[0] == a_contents->size[0]) {
        for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
          tp_vals_data[i1] += a_contents_data[i1];
        }
      } else {
        st.site = &l_emlrtRSI;
        plus(&st, tp_vals, a_contents);
        tp_vals_data = tp_vals->data;
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_real_T(sp, &db);
  emxFree_real_T(sp, &da);
  emxFree_real_T(sp, &a_contents);
  input_sizes_idx_0 = tp_vals->size[0] - 1;
  sizes_idx_1 = 0;
  for (k = 0; k <= input_sizes_idx_0; k++) {
    if (tp_vals_data[k] < 0.0) {
      sizes_idx_1++;
    }
  }
  emxInit_int32_T(sp, &r2, &jb_emlrtRTEI);
  i = r2->size[0];
  r2->size[0] = sizes_idx_1;
  emxEnsureCapacity_int32_T(sp, r2, i, &cb_emlrtRTEI);
  r3 = r2->data;
  sizes_idx_1 = 0;
  for (k = 0; k <= input_sizes_idx_0; k++) {
    if (tp_vals_data[k] < 0.0) {
      r3[sizes_idx_1] = k + 1;
      sizes_idx_1++;
    }
  }
  emxFree_real_T(sp, &tp_vals);
  input_sizes_idx_0 = r2->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    if ((r3[i] < 1) || (r3[i] > turning_points->size[0])) {
      emlrtDynamicBoundsCheckR2012b(r3[i], 1, turning_points->size[0],
                                    &n_emlrtBCI, (emlrtCTX)sp);
    }
  }
  i = SEs->size[0];
  SEs->size[0] = r2->size[0];
  emxEnsureCapacity_creal_T(sp, SEs, i, &fb_emlrtRTEI);
  dA_data = SEs->data;
  input_sizes_idx_0 = r2->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    a_im = turning_points_data[r3[i] - 1];
    dA_data[i].re = a_im * 0.0;
    dA_data[i].im = a_im;
  }
  emxFree_int32_T(sp, &r2);
  emxFree_real_T(sp, &turning_points);
  st.site = &m_emlrtRSI;
  b_exp(&st, SEs);
  dA_data = SEs->data;
  input_sizes_idx_0 = SEs->size[0];
  for (i = 0; i < input_sizes_idx_0; i++) {
    dA_data[i].re = centre.re + radius * dA_data[i].re;
    dA_data[i].im = centre.im + radius * dA_data[i].im;
  }
  /*      function binomial_check() */
  /*          theta = linspace(0,2*pi); */
  /*          dg_coeffs = diff_coeffs(g_coeffs); % coefficients of dg/dz */
  /*          plot(theta,real(polyval(dg_coeffs,centre+radius*exp(1i*theta))),'b:');
   */
  /*          val = zeros(size(theta)); */
  /*          for k_=0:rho */
  /*              c_k = sum(A(:,k_+1)); */
  /*              val = val+c_k*exp(1i*k_*theta); */
  /*          end */
  /*          hold on; */
  /*          plot(theta,real(val),'rx'); */
  /*      end */
  /*  %  */
  /*      function imag_check() */
  /*          theta = linspace(0,2*pi); */
  /*          dg_coeffs = diff_coeffs(g_coeffs); % coefficients of dg/dz */
  /*          plot(theta,imag(polyval(g_coeffs,centre+radius*exp(1i*theta))),'b');
   */
  /*          val = zeros(size(theta)); */
  /*          for k_=0:rho */
  /*              val = val+a(k_+1)*cos(k_*theta); */
  /*              if k_>0 */
  /*                  val = val+b(k_+1)*sin(k_*theta); */
  /*              end */
  /*          end */
  /*          hold on; */
  /*          plot(theta,val,'r'); */
  /*          legend('g(z)','Im g(z)'); */
  /*      end */
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (get_stepest_exits_on_ball.c) */
