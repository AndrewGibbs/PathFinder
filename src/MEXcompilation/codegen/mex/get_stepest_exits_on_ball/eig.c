/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eig.c
 *
 * Code generation for function 'eig'
 *
 */

/* Include files */
#include "eig.h"
#include "anyNonFinite.h"
#include "eml_int_forloop_overflow_check.h"
#include "get_stepest_exits_on_ball_data.h"
#include "get_stepest_exits_on_ball_emxutil.h"
#include "get_stepest_exits_on_ball_types.h"
#include "rt_nonfinite.h"
#include "schur.h"
#include "warning.h"
#include "lapacke.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo nb_emlrtRSI = {
    93,                                                       /* lineNo */
    "eig",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/eig.m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    102,                                                      /* lineNo */
    "eig",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/eig.m" /* pathName */
};

static emlrtRSInfo pb_emlrtRSI = {
    137,                                                      /* lineNo */
    "eig",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/eig.m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI = {
    145,                                                      /* lineNo */
    "eig",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/eig.m" /* pathName */
};

static emlrtRSInfo rb_emlrtRSI = {
    153,                                                      /* lineNo */
    "eig",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/eig.m" /* pathName */
};

static emlrtRSInfo vb_emlrtRSI = {
    32,                     /* lineNo */
    "eigHermitianStandard", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eigHermitianStandard.m" /* pathName */
};

static emlrtRSInfo wb_emlrtRSI = {
    33,                     /* lineNo */
    "eigHermitianStandard", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eigHermitianStandard.m" /* pathName */
};

static emlrtRSInfo mc_emlrtRSI = {
    59,                        /* lineNo */
    "diagDiagUpperHessNoImag", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eigHermitianStandard.m" /* pathName */
};

static emlrtRSInfo nc_emlrtRSI = {
    62,                        /* lineNo */
    "diagDiagUpperHessNoImag", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eigHermitianStandard.m" /* pathName */
};

static emlrtRSInfo oc_emlrtRSI = {
    20,                         /* lineNo */
    "eigSkewHermitianStandard", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eigSkewHermitianStandard.m" /* pathName */
};

static emlrtRSInfo pc_emlrtRSI = {
    29,                                /* lineNo */
    "eigComplexSkewHermitianStandard", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eigComplexSkewHermitianStandard.m" /* pathName */
};

static emlrtRSInfo qc_emlrtRSI = {
    30,                                /* lineNo */
    "eigComplexSkewHermitianStandard", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eigComplexSkewHermitianStandard.m" /* pathName */
};

static emlrtRSInfo rc_emlrtRSI = {
    53,                 /* lineNo */
    "makeEigValMatrix", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eigComplexSkewHermitianStandard.m" /* pathName */
};

static emlrtRSInfo sc_emlrtRSI = {
    55,                 /* lineNo */
    "makeEigValMatrix", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eigComplexSkewHermitianStandard.m" /* pathName */
};

static emlrtRSInfo tc_emlrtRSI =
    {
        59,            /* lineNo */
        "eigStandard", /* fcnName */
        "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
        "eigStandard.m" /* pathName */
};

static emlrtRSInfo uc_emlrtRSI =
    {
        33,            /* lineNo */
        "eigStandard", /* fcnName */
        "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
        "eigStandard.m" /* pathName */
};

static emlrtRSInfo vc_emlrtRSI =
    {
        31,            /* lineNo */
        "eigStandard", /* fcnName */
        "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
        "eigStandard.m" /* pathName */
};

static emlrtRSInfo wc_emlrtRSI = {
    36,      /* lineNo */
    "xgeev", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/xgeev.m" /* pathName
                                                                            */
};

static emlrtRSInfo xc_emlrtRSI = {
    182,           /* lineNo */
    "ceval_xgeev", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/xgeev.m" /* pathName
                                                                            */
};

static emlrtRTEInfo k_emlrtRTEI = {
    62,                                                       /* lineNo */
    27,                                                       /* colNo */
    "eig",                                                    /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/eig.m" /* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = {
    68,                                                       /* lineNo */
    24,                                                       /* colNo */
    "eig",                                                    /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/eig.m" /* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = {
    72,                                                       /* lineNo */
    28,                                                       /* colNo */
    "eig",                                                    /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/eig.m" /* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = {
    97,                                                       /* lineNo */
    9,                                                        /* colNo */
    "eig",                                                    /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/eig.m" /* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = {
    101,                                                      /* lineNo */
    13,                                                       /* colNo */
    "eig",                                                    /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/eig.m" /* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = {
    76,                  /* lineNo */
    13,                  /* colNo */
    "eml_mtimes_helper", /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m" /* pName
                                                                          */
};

static emlrtRTEInfo sb_emlrtRTEI = {
    36,      /* lineNo */
    33,      /* colNo */
    "xgeev", /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/xgeev.m" /* pName
                                                                            */
};

static emlrtRTEInfo tb_emlrtRTEI = {
    83,      /* lineNo */
    24,      /* colNo */
    "xgeev", /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/xgeev.m" /* pName
                                                                            */
};

static emlrtRTEInfo ub_emlrtRTEI = {
    86,      /* lineNo */
    21,      /* colNo */
    "xgeev", /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/xgeev.m" /* pName
                                                                            */
};

static emlrtRTEInfo vb_emlrtRTEI = {
    90,      /* lineNo */
    29,      /* colNo */
    "xgeev", /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/xgeev.m" /* pName
                                                                            */
};

static emlrtRTEInfo wb_emlrtRTEI =
    {
        32,            /* lineNo */
        13,            /* colNo */
        "eigStandard", /* fName */
        "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/private/"
        "eigStandard.m" /* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = {
    1,                                                        /* lineNo */
    20,                                                       /* colNo */
    "eig",                                                    /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/eig.m" /* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = {
    83,      /* lineNo */
    1,       /* colNo */
    "xgeev", /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/xgeev.m" /* pName
                                                                            */
};

/* Function Definitions */
void eig(const emlrtStack *sp, const emxArray_creal_T *A, emxArray_creal_T *V,
         emxArray_creal_T *D)
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
  emlrtStack st;
  emxArray_creal_T *W;
  emxArray_creal_T *b_A;
  emxArray_real_T *scale;
  const creal_T *A_data;
  creal_T vl;
  creal_T *V_data;
  creal_T *W_data;
  creal_T *b_A_data;
  real_T abnrm;
  real_T rconde;
  real_T rcondv;
  real_T *scale_data;
  int32_T b_i;
  int32_T exitg1;
  int32_T i;
  int32_T j;
  int32_T n;
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
  A_data = A->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  n = A->size[0];
  if (A->size[0] != A->size[1]) {
    emlrtErrorWithMessageIdR2018a(sp, &k_emlrtRTEI,
                                  "MATLAB:eig:inputMustBeSquareStandard",
                                  "MATLAB:eig:inputMustBeSquareStandard", 0);
  }
  i = V->size[0] * V->size[1];
  V->size[0] = A->size[0];
  V->size[1] = A->size[0];
  emxEnsureCapacity_creal_T(sp, V, i, &nb_emlrtRTEI);
  i = D->size[0] * D->size[1];
  D->size[0] = A->size[0];
  D->size[1] = A->size[0];
  emxEnsureCapacity_creal_T(sp, D, i, &ob_emlrtRTEI);
  if ((A->size[0] != 0) && (A->size[1] != 0)) {
    st.site = &nb_emlrtRSI;
    if (anyNonFinite(&st, A)) {
      i = V->size[0] * V->size[1];
      V->size[0] = A->size[0];
      V->size[1] = A->size[0];
      emxEnsureCapacity_creal_T(sp, V, i, &pb_emlrtRTEI);
      V_data = V->data;
      j = A->size[0] * A->size[0];
      for (i = 0; i < j; i++) {
        V_data[i].re = rtNaN;
        V_data[i].im = 0.0;
      }
      i = D->size[0] * D->size[1];
      D->size[0] = A->size[0];
      D->size[1] = A->size[0];
      emxEnsureCapacity_creal_T(sp, D, i, &qb_emlrtRTEI);
      V_data = D->data;
      j = A->size[0] * A->size[0];
      for (i = 0; i < j; i++) {
        V_data[i].re = 0.0;
        V_data[i].im = 0.0;
      }
      st.site = &ob_emlrtRSI;
      if (A->size[0] > 2147483646) {
        b_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (j = 0; j < n; j++) {
        V_data[j + D->size[0] * j].re = rtNaN;
        V_data[j + D->size[0] * j].im = 0.0;
      }
    } else {
      p = (A->size[0] == A->size[1]);
      if (p) {
        j = 0;
        exitg2 = false;
        while ((!exitg2) && (j <= A->size[1] - 1)) {
          b_i = 0;
          do {
            exitg1 = 0;
            if (b_i <= j) {
              if ((!(A_data[b_i + A->size[0] * j].re ==
                     A_data[j + A->size[0] * b_i].re)) ||
                  (!(A_data[b_i + A->size[0] * j].im ==
                     -A_data[j + A->size[0] * b_i].im))) {
                p = false;
                exitg1 = 1;
              } else {
                b_i++;
              }
            } else {
              j++;
              exitg1 = 2;
            }
          } while (exitg1 == 0);
          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      }
      if (p) {
        st.site = &pb_emlrtRSI;
        b_st.site = &vb_emlrtRSI;
        schur(&b_st, A, V, D);
        V_data = D->data;
        b_st.site = &wb_emlrtRSI;
        n = D->size[0];
        V_data[0].im = 0.0;
        c_st.site = &mc_emlrtRSI;
        if ((2 <= n) && (n > 2147483646)) {
          d_st.site = &hb_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }
        for (j = 2; j <= n; j++) {
          V_data[(j + D->size[0] * (j - 1)) - 1].im = 0.0;
          V_data[(j + D->size[0] * (j - 2)) - 1].re = 0.0;
          V_data[(j + D->size[0] * (j - 2)) - 1].im = 0.0;
          c_st.site = &nc_emlrtRSI;
          for (b_i = 0; b_i <= j - 2; b_i++) {
            V_data[b_i + D->size[0] * (j - 1)].re = 0.0;
            V_data[b_i + D->size[0] * (j - 1)].im = 0.0;
          }
        }
      } else {
        p = (A->size[0] == A->size[1]);
        if (p) {
          j = 0;
          exitg2 = false;
          while ((!exitg2) && (j <= A->size[1] - 1)) {
            b_i = 0;
            do {
              exitg1 = 0;
              if (b_i <= j) {
                if ((!(A_data[b_i + A->size[0] * j].re ==
                       -A_data[j + A->size[0] * b_i].re)) ||
                    (!(A_data[b_i + A->size[0] * j].im ==
                       A_data[j + A->size[0] * b_i].im))) {
                  p = false;
                  exitg1 = 1;
                } else {
                  b_i++;
                }
              } else {
                j++;
                exitg1 = 2;
              }
            } while (exitg1 == 0);
            if (exitg1 == 1) {
              exitg2 = true;
            }
          }
        }
        emxInit_creal_T(sp, &b_A, 2, &sb_emlrtRTEI);
        if (p) {
          st.site = &qb_emlrtRSI;
          b_st.site = &oc_emlrtRSI;
          i = b_A->size[0] * b_A->size[1];
          b_A->size[0] = A->size[0];
          b_A->size[1] = A->size[1];
          emxEnsureCapacity_creal_T(&b_st, b_A, i, &rb_emlrtRTEI);
          b_A_data = b_A->data;
          j = A->size[0] * A->size[1];
          for (i = 0; i < j; i++) {
            b_A_data[i].re = 0.0 * A_data[i].re - A_data[i].im;
            b_A_data[i].im = 0.0 * A_data[i].im + A_data[i].re;
          }
          c_st.site = &pc_emlrtRSI;
          schur(&c_st, b_A, V, D);
          V_data = D->data;
          c_st.site = &qc_emlrtRSI;
          n = D->size[0];
          abnrm = V_data[0].re;
          V_data[0].re = 0.0;
          V_data[0].im = -abnrm;
          d_st.site = &rc_emlrtRSI;
          if ((2 <= n) && (n > 2147483646)) {
            e_st.site = &hb_emlrtRSI;
            check_forloop_overflow_error(&e_st);
          }
          for (j = 2; j <= n; j++) {
            abnrm = V_data[(j + D->size[0] * (j - 1)) - 1].re;
            V_data[(j + D->size[0] * (j - 1)) - 1].re = 0.0;
            V_data[(j + D->size[0] * (j - 1)) - 1].im = -abnrm;
            d_st.site = &sc_emlrtRSI;
            for (b_i = 0; b_i <= j - 2; b_i++) {
              V_data[b_i + D->size[0] * (j - 1)].re = 0.0;
              V_data[b_i + D->size[0] * (j - 1)].im = 0.0;
            }
          }
        } else {
          st.site = &rb_emlrtRSI;
          n = A->size[0];
          b_st.site = &vc_emlrtRSI;
          c_st.site = &wc_emlrtRSI;
          i = b_A->size[0] * b_A->size[1];
          b_A->size[0] = A->size[0];
          b_A->size[1] = A->size[1];
          emxEnsureCapacity_creal_T(&c_st, b_A, i, &sb_emlrtRTEI);
          b_A_data = b_A->data;
          j = A->size[0] * A->size[1];
          for (i = 0; i < j; i++) {
            b_A_data[i] = A_data[i];
          }
          emxInit_creal_T(&c_st, &W, 1, &xb_emlrtRTEI);
          emxInit_real_T(&c_st, &scale, 1, &yb_emlrtRTEI);
          i = scale->size[0];
          scale->size[0] = A->size[1];
          emxEnsureCapacity_real_T(&c_st, scale, i, &tb_emlrtRTEI);
          scale_data = scale->data;
          i = W->size[0];
          W->size[0] = A->size[1];
          emxEnsureCapacity_creal_T(&c_st, W, i, &ub_emlrtRTEI);
          W_data = W->data;
          i = V->size[0] * V->size[1];
          V->size[0] = A->size[1];
          V->size[1] = A->size[1];
          emxEnsureCapacity_creal_T(&c_st, V, i, &vb_emlrtRTEI);
          V_data = V->data;
          info_t = LAPACKE_zgeevx(
              102, 'B', 'N', 'V', 'N', (ptrdiff_t)A->size[1],
              (lapack_complex_double *)&b_A_data[0], (ptrdiff_t)A->size[0],
              (lapack_complex_double *)&W_data[0], (lapack_complex_double *)&vl,
              (ptrdiff_t)1, (lapack_complex_double *)&V_data[0],
              (ptrdiff_t)A->size[1], &ilo_t, &ihi_t, &scale_data[0], &abnrm,
              &rconde, &rcondv);
          b_i = (int32_T)info_t;
          d_st.site = &xc_emlrtRSI;
          emxFree_real_T(&d_st, &scale);
          if (b_i < 0) {
            if (b_i == -1010) {
              emlrtErrorWithMessageIdR2018a(&d_st, &j_emlrtRTEI, "MATLAB:nomem",
                                            "MATLAB:nomem", 0);
            } else {
              emlrtErrorWithMessageIdR2018a(&d_st, &i_emlrtRTEI,
                                            "Coder:toolbox:LAPACKCallErrorInfo",
                                            "Coder:toolbox:LAPACKCallErrorInfo",
                                            5, 4, 14, &fname[0], 12, b_i);
            }
          }
          i = D->size[0] * D->size[1];
          D->size[0] = A->size[0];
          D->size[1] = A->size[0];
          emxEnsureCapacity_creal_T(&st, D, i, &wb_emlrtRTEI);
          V_data = D->data;
          j = A->size[0] * A->size[0];
          for (i = 0; i < j; i++) {
            V_data[i].re = 0.0;
            V_data[i].im = 0.0;
          }
          b_st.site = &uc_emlrtRSI;
          if (A->size[0] > 2147483646) {
            c_st.site = &hb_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }
          for (j = 0; j < n; j++) {
            V_data[j + D->size[0] * j] = W_data[j];
          }
          emxFree_creal_T(&st, &W);
          if (b_i != 0) {
            b_st.site = &tc_emlrtRSI;
            c_warning(&b_st);
          }
        }
        emxFree_creal_T(sp, &b_A);
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (eig.c) */
