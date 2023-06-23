/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * roots.c
 *
 * Code generation for function 'roots'
 *
 */

/* Include files */
#include "roots.h"
#include "anyNonFinite.h"
#include "eml_int_forloop_overflow_check.h"
#include "get_smallest_supset_ball_data.h"
#include "get_smallest_supset_ball_emxutil.h"
#include "get_smallest_supset_ball_types.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "schur.h"
#include "warning.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo lb_emlrtRSI = {
    74,                                                          /* lineNo */
    "roots",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pathName */
};

static emlrtRSInfo mb_emlrtRSI = {
    100,                                                         /* lineNo */
    "roots",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pathName */
};

static emlrtRSInfo nb_emlrtRSI = {
    95,                                                          /* lineNo */
    "roots",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    94,                                                          /* lineNo */
    "roots",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pathName */
};

static emlrtRSInfo pb_emlrtRSI = {
    91,                                                          /* lineNo */
    "roots",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI = {
    85,                                                          /* lineNo */
    "roots",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pathName */
};

static emlrtRSInfo rb_emlrtRSI = {
    79,                                                          /* lineNo */
    "roots",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pathName */
};

static emlrtRSInfo sb_emlrtRSI = {
    23,                                                          /* lineNo */
    "roots",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pathName */
};

static emlrtRSInfo ub_emlrtRSI = {
    155,                                                      /* lineNo */
    "eig",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/eig.m" /* pathName */
};

static emlrtRSInfo vb_emlrtRSI = {
    147,                                                      /* lineNo */
    "eig",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/eig.m" /* pathName */
};

static emlrtRSInfo wb_emlrtRSI = {
    139,                                                      /* lineNo */
    "eig",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/eig.m" /* pathName */
};

static emlrtRSInfo xb_emlrtRSI = {
    93,                                                       /* lineNo */
    "eig",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/eig.m" /* pathName */
};

static emlrtRSInfo yb_emlrtRSI = {
    21,                     /* lineNo */
    "eigHermitianStandard", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eigHermitianStandard.m" /* pathName */
};

static emlrtRSInfo ac_emlrtRSI = {
    22,                     /* lineNo */
    "eigHermitianStandard", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eigHermitianStandard.m" /* pathName */
};

static emlrtRSInfo mc_emlrtRSI = {
    47,                 /* lineNo */
    "mainDiagZeroImag", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eigHermitianStandard.m" /* pathName */
};

static emlrtRSInfo nc_emlrtRSI = {
    18,                         /* lineNo */
    "eigSkewHermitianStandard", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eigSkewHermitianStandard.m" /* pathName */
};

static emlrtRSInfo oc_emlrtRSI = {
    18,                                /* lineNo */
    "eigComplexSkewHermitianStandard", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eigComplexSkewHermitianStandard.m" /* pathName */
};

static emlrtRSInfo pc_emlrtRSI = {
    19,                                /* lineNo */
    "eigComplexSkewHermitianStandard", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eigComplexSkewHermitianStandard.m" /* pathName */
};

static emlrtRSInfo qc_emlrtRSI = {
    41,                 /* lineNo */
    "makeEigValVector", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eigComplexSkewHermitianStandard.m" /* pathName */
};

static emlrtRSInfo rc_emlrtRSI =
    {
        59,            /* lineNo */
        "eigStandard", /* fcnName */
        "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
        "eigStandard.m" /* pathName */
};

static emlrtRSInfo sc_emlrtRSI =
    {
        44,            /* lineNo */
        "eigStandard", /* fcnName */
        "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
        "eigStandard.m" /* pathName */
};

static emlrtRSInfo tc_emlrtRSI = {
    38,      /* lineNo */
    "xgeev", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/xgeev.m" /* pathName
                                                                            */
};

static emlrtRSInfo uc_emlrtRSI = {
    182,           /* lineNo */
    "ceval_xgeev", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/xgeev.m" /* pathName
                                                                            */
};

static emlrtRTEInfo h_emlrtRTEI = {
    62,                                                       /* lineNo */
    27,                                                       /* colNo */
    "eig",                                                    /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/eig.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    24,                                                          /* lineNo */
    5,                                                           /* colNo */
    "roots",                                                     /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    48,                                                          /* lineNo */
    1,                                                           /* colNo */
    "roots",                                                     /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    51,                                                          /* lineNo */
    1,                                                           /* colNo */
    "roots",                                                     /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = {
    82,                                                          /* lineNo */
    5,                                                           /* colNo */
    "roots",                                                     /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    99,                                                          /* lineNo */
    5,                                                           /* colNo */
    "roots",                                                     /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pName */
};

static emlrtDCInfo d_emlrtDCI = {
    29,                                                           /* lineNo */
    1,                                                            /* colNo */
    "roots",                                                      /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m", /* pName */
    4 /* checkKind */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    29,                                                          /* lineNo */
    1,                                                           /* colNo */
    "roots",                                                     /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = {
    56,                                                          /* lineNo */
    27,                                                          /* colNo */
    "roots",                                                     /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = {
    74,                                                          /* lineNo */
    5,                                                           /* colNo */
    "roots",                                                     /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = {
    84,                                                          /* lineNo */
    5,                                                           /* colNo */
    "roots",                                                     /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = {
    79,                                                          /* lineNo */
    5,                                                           /* colNo */
    "roots",                                                     /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = {
    94,                                                          /* lineNo */
    5,                                                           /* colNo */
    "roots",                                                     /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = {
    46,                     /* lineNo */
    20,                     /* colNo */
    "eigHermitianStandard", /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eigHermitianStandard.m" /* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = {
    83,      /* lineNo */
    24,      /* colNo */
    "xgeev", /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/xgeev.m" /* pName
                                                                            */
};

static emlrtRTEInfo pb_emlrtRTEI = {
    86,      /* lineNo */
    21,      /* colNo */
    "xgeev", /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/xgeev.m" /* pName
                                                                            */
};

static emlrtRTEInfo qb_emlrtRTEI = {
    100,                                                         /* lineNo */
    5,                                                           /* colNo */
    "roots",                                                     /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = {
    39,                                /* lineNo */
    20,                                /* colNo */
    "eigComplexSkewHermitianStandard", /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eigComplexSkewHermitianStandard.m" /* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = {
    56,                                                          /* lineNo */
    5,                                                           /* colNo */
    "roots",                                                     /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/roots.m" /* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = {
    83,      /* lineNo */
    1,       /* colNo */
    "xgeev", /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/xgeev.m" /* pName
                                                                            */
};

/* Function Definitions */
void roots(const emlrtStack *sp, const emxArray_creal_T *c, emxArray_creal_T *r)
{
  static const char_T fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'z', 'g', 'e', 'e', 'v', 'x'};
  ptrdiff_t ihi_t;
  ptrdiff_t ilo_t;
  ptrdiff_t info_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_creal_T *a;
  emxArray_creal_T *ctmp;
  emxArray_real_T *scale;
  const creal_T *c_data;
  creal_T vl;
  creal_T vr;
  creal_T *a_data;
  creal_T *ctmp_data;
  creal_T *r_data;
  real_T abnrm;
  real_T ai;
  real_T ar;
  real_T bi;
  real_T brm;
  real_T rconde;
  real_T rcondv;
  real_T *scale_data;
  int32_T iv[2];
  int32_T companDim;
  int32_T exitg3;
  int32_T j;
  int32_T k1;
  int32_T k2;
  int32_T nTrailingZeros;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T p;
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
  c_data = c->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &sb_emlrtRSI;
  if (anyNonFinite(&st, c)) {
    emlrtErrorWithMessageIdR2018a(sp, &i_emlrtRTEI,
                                  "MATLAB:roots:NonFiniteInput",
                                  "MATLAB:roots:NonFiniteInput", 0);
  }
  if (c->size[0] - 1 < 0) {
    emlrtNonNegativeCheckR2012b(-1.0, &d_emlrtDCI, (emlrtCTX)sp);
  }
  j = r->size[0];
  r->size[0] = c->size[0] - 1;
  emxEnsureCapacity_creal_T(sp, r, j, &hb_emlrtRTEI);
  r_data = r->data;
  if (c->size[0] - 1 < 0) {
    emlrtNonNegativeCheckR2012b(-1.0, &d_emlrtDCI, (emlrtCTX)sp);
  }
  k2 = c->size[0] - 1;
  for (j = 0; j < k2; j++) {
    r_data[j].re = 0.0;
    r_data[j].im = 0.0;
  }
  k1 = 1;
  while ((k1 <= c->size[0]) &&
         ((!(c_data[k1 - 1].re != 0.0)) && (!(c_data[k1 - 1].im != 0.0)))) {
    k1++;
  }
  k2 = c->size[0];
  while ((k2 >= k1) &&
         ((!(c_data[k2 - 1].re != 0.0)) && (!(c_data[k2 - 1].im != 0.0)))) {
    k2--;
  }
  if (k2 > c->size[0]) {
    emlrtErrorWithMessageIdR2018a(sp, &j_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  nTrailingZeros = c->size[0] - k2;
  if (nTrailingZeros > c->size[0]) {
    emlrtErrorWithMessageIdR2018a(sp, &k_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (k1 < k2) {
    emxInit_creal_T(sp, &ctmp, 1, &sb_emlrtRTEI);
    companDim = k2 - k1;
    j = ctmp->size[0];
    ctmp->size[0] = c->size[0];
    emxEnsureCapacity_creal_T(sp, ctmp, j, &ib_emlrtRTEI);
    ctmp_data = ctmp->data;
    exitg1 = false;
    while ((!exitg1) && (companDim > 0)) {
      j = 0;
      exitg2 = false;
      while ((!exitg2) && (j + 1 <= companDim)) {
        k2 = k1 + j;
        ar = c_data[k2].re;
        ai = c_data[k2].im;
        rcondv = c_data[k1 - 1].re;
        bi = c_data[k1 - 1].im;
        if (bi == 0.0) {
          if (ai == 0.0) {
            ctmp_data[j].re = ar / rcondv;
            ctmp_data[j].im = 0.0;
          } else if (ar == 0.0) {
            ctmp_data[j].re = 0.0;
            ctmp_data[j].im = ai / rcondv;
          } else {
            ctmp_data[j].re = ar / rcondv;
            ctmp_data[j].im = ai / rcondv;
          }
        } else if (rcondv == 0.0) {
          if (ar == 0.0) {
            ctmp_data[j].re = ai / bi;
            ctmp_data[j].im = 0.0;
          } else if (ai == 0.0) {
            ctmp_data[j].re = 0.0;
            ctmp_data[j].im = -(ar / bi);
          } else {
            ctmp_data[j].re = ai / bi;
            ctmp_data[j].im = -(ar / bi);
          }
        } else {
          brm = muDoubleScalarAbs(rcondv);
          abnrm = muDoubleScalarAbs(bi);
          if (brm > abnrm) {
            rconde = bi / rcondv;
            abnrm = rcondv + rconde * bi;
            ctmp_data[j].re = (ar + rconde * ai) / abnrm;
            ctmp_data[j].im = (ai - rconde * ar) / abnrm;
          } else if (abnrm == brm) {
            if (rcondv > 0.0) {
              rconde = 0.5;
            } else {
              rconde = -0.5;
            }
            if (bi > 0.0) {
              abnrm = 0.5;
            } else {
              abnrm = -0.5;
            }
            ctmp_data[j].re = (ar * rconde + ai * abnrm) / brm;
            ctmp_data[j].im = (ai * rconde - ar * abnrm) / brm;
          } else {
            rconde = rcondv / bi;
            abnrm = bi + rconde * rcondv;
            ctmp_data[j].re = (rconde * ar + ai) / abnrm;
            ctmp_data[j].im = (rconde * ai - ar) / abnrm;
          }
        }
        if (muDoubleScalarIsInf(
                muDoubleScalarHypot(ctmp_data[j].re, ctmp_data[j].im))) {
          exitg2 = true;
        } else {
          j++;
        }
      }
      if (j + 1 > companDim) {
        exitg1 = true;
      } else {
        k1++;
        companDim--;
      }
    }
    if (companDim < 1) {
      if (1 > nTrailingZeros) {
        j = 0;
      } else {
        j = nTrailingZeros;
      }
      iv[0] = 1;
      iv[1] = j;
      st.site = &rb_emlrtRSI;
      indexShapeCheck(&st, r->size[0], iv);
      k2 = r->size[0];
      r->size[0] = j;
      emxEnsureCapacity_creal_T(sp, r, k2, &lb_emlrtRTEI);
    } else {
      if (companDim > c->size[0]) {
        emlrtErrorWithMessageIdR2018a(sp, &l_emlrtRTEI,
                                      "Coder:builtins:AssertionFailed",
                                      "Coder:builtins:AssertionFailed", 0);
      }
      emxInit_creal_T(sp, &a, 2, &kb_emlrtRTEI);
      j = a->size[0] * a->size[1];
      a->size[0] = companDim;
      a->size[1] = companDim;
      emxEnsureCapacity_creal_T(sp, a, j, &kb_emlrtRTEI);
      a_data = a->data;
      k2 = companDim * companDim;
      for (j = 0; j < k2; j++) {
        a_data[j].re = 0.0;
        a_data[j].im = 0.0;
      }
      st.site = &qb_emlrtRSI;
      for (j = 0; j <= companDim - 2; j++) {
        a_data[a->size[0] * j].re = -ctmp_data[j].re;
        a_data[a->size[0] * j].im = -ctmp_data[j].im;
        a_data[(j + a->size[0] * j) + 1].re = 1.0;
        a_data[(j + a->size[0] * j) + 1].im = 0.0;
      }
      a_data[a->size[0] * (companDim - 1)].re = -ctmp_data[companDim - 1].re;
      a_data[a->size[0] * (companDim - 1)].im = -ctmp_data[companDim - 1].im;
      st.site = &pb_emlrtRSI;
      if ((1 <= nTrailingZeros) && (nTrailingZeros > 2147483646)) {
        b_st.site = &f_emlrtRSI;
        b_check_forloop_overflow_error(&b_st);
      }
      for (j = 0; j < nTrailingZeros; j++) {
        r_data[j].re = 0.0;
        r_data[j].im = 0.0;
      }
      st.site = &ob_emlrtRSI;
      if (a->size[0] != a->size[1]) {
        emlrtErrorWithMessageIdR2018a(
            &st, &h_emlrtRTEI, "MATLAB:eig:inputMustBeSquareStandard",
            "MATLAB:eig:inputMustBeSquareStandard", 0);
      }
      b_st.site = &xb_emlrtRSI;
      if (b_anyNonFinite(&b_st, a)) {
        j = ctmp->size[0];
        ctmp->size[0] = a->size[0];
        emxEnsureCapacity_creal_T(&st, ctmp, j, &mb_emlrtRTEI);
        ctmp_data = ctmp->data;
        k2 = a->size[0];
        for (j = 0; j < k2; j++) {
          ctmp_data[j].re = rtNaN;
          ctmp_data[j].im = 0.0;
        }
      } else {
        p = (a->size[0] == a->size[1]);
        if (p) {
          j = 0;
          exitg1 = false;
          while ((!exitg1) && (j <= a->size[1] - 1)) {
            k2 = 0;
            do {
              exitg3 = 0;
              if (k2 <= j) {
                if ((!(a_data[k2 + a->size[0] * j].re ==
                       a_data[j + a->size[0] * k2].re)) ||
                    (!(a_data[k2 + a->size[0] * j].im ==
                       -a_data[j + a->size[0] * k2].im))) {
                  p = false;
                  exitg3 = 1;
                } else {
                  k2++;
                }
              } else {
                j++;
                exitg3 = 2;
              }
            } while (exitg3 == 0);
            if (exitg3 == 1) {
              exitg1 = true;
            }
          }
        }
        if (p) {
          b_st.site = &wb_emlrtRSI;
          c_st.site = &yb_emlrtRSI;
          schur(&c_st, a);
          a_data = a->data;
          c_st.site = &ac_emlrtRSI;
          k2 = a->size[0];
          j = ctmp->size[0];
          ctmp->size[0] = a->size[0];
          emxEnsureCapacity_creal_T(&c_st, ctmp, j, &nb_emlrtRTEI);
          ctmp_data = ctmp->data;
          d_st.site = &mc_emlrtRSI;
          if ((1 <= a->size[0]) && (a->size[0] > 2147483646)) {
            e_st.site = &f_emlrtRSI;
            b_check_forloop_overflow_error(&e_st);
          }
          for (j = 0; j < k2; j++) {
            ctmp_data[j].re = a_data[j + a->size[0] * j].re;
            ctmp_data[j].im = 0.0;
          }
        } else {
          p = (a->size[0] == a->size[1]);
          if (p) {
            j = 0;
            exitg1 = false;
            while ((!exitg1) && (j <= a->size[1] - 1)) {
              k2 = 0;
              do {
                exitg3 = 0;
                if (k2 <= j) {
                  if ((!(a_data[k2 + a->size[0] * j].re ==
                         -a_data[j + a->size[0] * k2].re)) ||
                      (!(a_data[k2 + a->size[0] * j].im ==
                         a_data[j + a->size[0] * k2].im))) {
                    p = false;
                    exitg3 = 1;
                  } else {
                    k2++;
                  }
                } else {
                  j++;
                  exitg3 = 2;
                }
              } while (exitg3 == 0);
              if (exitg3 == 1) {
                exitg1 = true;
              }
            }
          }
          if (p) {
            b_st.site = &vb_emlrtRSI;
            c_st.site = &nc_emlrtRSI;
            k2 = a->size[0] * a->size[1];
            for (j = 0; j < k2; j++) {
              abnrm = a_data[j].im;
              rconde = a_data[j].re;
              a_data[j].re = 0.0 * rconde - abnrm;
              a_data[j].im = 0.0 * abnrm + rconde;
            }
            d_st.site = &oc_emlrtRSI;
            schur(&d_st, a);
            a_data = a->data;
            d_st.site = &pc_emlrtRSI;
            k2 = a->size[0];
            j = ctmp->size[0];
            ctmp->size[0] = a->size[0];
            emxEnsureCapacity_creal_T(&d_st, ctmp, j, &rb_emlrtRTEI);
            ctmp_data = ctmp->data;
            e_st.site = &qc_emlrtRSI;
            if ((1 <= a->size[0]) && (a->size[0] > 2147483646)) {
              f_st.site = &f_emlrtRSI;
              b_check_forloop_overflow_error(&f_st);
            }
            for (j = 0; j < k2; j++) {
              ctmp_data[j].re = 0.0;
              ctmp_data[j].im = -a_data[j + a->size[0] * j].re;
            }
          } else {
            emxInit_real_T(&st, &scale, &tb_emlrtRTEI);
            b_st.site = &ub_emlrtRSI;
            c_st.site = &sc_emlrtRSI;
            d_st.site = &tc_emlrtRSI;
            j = scale->size[0];
            scale->size[0] = a->size[1];
            emxEnsureCapacity_real_T(&d_st, scale, j, &ob_emlrtRTEI);
            scale_data = scale->data;
            j = ctmp->size[0];
            ctmp->size[0] = a->size[1];
            emxEnsureCapacity_creal_T(&d_st, ctmp, j, &pb_emlrtRTEI);
            ctmp_data = ctmp->data;
            info_t = LAPACKE_zgeevx(
                102, 'B', 'N', 'N', 'N', (ptrdiff_t)a->size[1],
                (lapack_complex_double *)&a_data[0], (ptrdiff_t)a->size[0],
                (lapack_complex_double *)&ctmp_data[0],
                (lapack_complex_double *)&vl, (ptrdiff_t)1,
                (lapack_complex_double *)&vr, (ptrdiff_t)1, &ilo_t, &ihi_t,
                &scale_data[0], &abnrm, &rconde, &rcondv);
            k2 = (int32_T)info_t;
            e_st.site = &uc_emlrtRSI;
            emxFree_real_T(&e_st, &scale);
            if (k2 < 0) {
              if (k2 == -1010) {
                emlrtErrorWithMessageIdR2018a(
                    &e_st, &g_emlrtRTEI, "MATLAB:nomem", "MATLAB:nomem", 0);
              } else {
                emlrtErrorWithMessageIdR2018a(
                    &e_st, &f_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
                    "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &fname[0],
                    12, k2);
              }
            }
            if (k2 != 0) {
              c_st.site = &rc_emlrtRSI;
              c_warning(&c_st);
            }
          }
        }
      }
      emxFree_creal_T(&st, &a);
      st.site = &nb_emlrtRSI;
      for (j = 0; j < companDim; j++) {
        r_data[j + nTrailingZeros] = ctmp_data[j];
      }
      k2 = nTrailingZeros + companDim;
      if (k2 > c->size[0]) {
        emlrtErrorWithMessageIdR2018a(sp, &m_emlrtRTEI,
                                      "Coder:builtins:AssertionFailed",
                                      "Coder:builtins:AssertionFailed", 0);
      }
      if (1 > k2) {
        j = 0;
      } else {
        j = k2;
      }
      iv[0] = 1;
      iv[1] = j;
      st.site = &mb_emlrtRSI;
      indexShapeCheck(&st, r->size[0], iv);
      k2 = r->size[0];
      r->size[0] = j;
      emxEnsureCapacity_creal_T(sp, r, k2, &qb_emlrtRTEI);
    }
    emxFree_creal_T(sp, &ctmp);
  } else {
    if (1 > nTrailingZeros) {
      j = 0;
    } else {
      j = nTrailingZeros;
    }
    iv[0] = 1;
    iv[1] = j;
    st.site = &lb_emlrtRSI;
    indexShapeCheck(&st, r->size[0], iv);
    k2 = r->size[0];
    r->size[0] = j;
    emxEnsureCapacity_creal_T(sp, r, k2, &jb_emlrtRTEI);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (roots.c) */
