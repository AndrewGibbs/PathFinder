/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * schur.c
 *
 * Code generation for function 'schur'
 *
 */

/* Include files */
#include "schur.h"
#include "anyNonFinite.h"
#include "eml_int_forloop_overflow_check.h"
#include "get_stepest_exits_on_ball_data.h"
#include "get_stepest_exits_on_ball_emxutil.h"
#include "get_stepest_exits_on_ball_types.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo xb_emlrtRSI = {
    35,                                                         /* lineNo */
    "schur",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/schur.m" /* pathName */
};

static emlrtRSInfo yb_emlrtRSI = {
    43,                                                         /* lineNo */
    "schur",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/schur.m" /* pathName */
};

static emlrtRSInfo ac_emlrtRSI = {
    66,                                                         /* lineNo */
    "schur",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/schur.m" /* pathName */
};

static emlrtRSInfo bc_emlrtRSI = {
    77,                                                         /* lineNo */
    "schur",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/schur.m" /* pathName */
};

static emlrtRSInfo cc_emlrtRSI = {
    78,                                                         /* lineNo */
    "schur",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/schur.m" /* pathName */
};

static emlrtRSInfo dc_emlrtRSI = {
    83,                                                         /* lineNo */
    "schur",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/schur.m" /* pathName */
};

static emlrtRSInfo ec_emlrtRSI = {
    48,                                                       /* lineNo */
    "triu",                                                   /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/elmat/triu.m" /* pathName */
};

static emlrtRSInfo fc_emlrtRSI = {
    47,                                                       /* lineNo */
    "triu",                                                   /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/elmat/triu.m" /* pathName */
};

static emlrtRSInfo
    gc_emlrtRSI =
        {
            15,       /* lineNo */
            "xgehrd", /* fcnName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
            "xgehrd.m" /* pathName */
};

static emlrtRSInfo
    hc_emlrtRSI =
        {
            85,             /* lineNo */
            "ceval_xgehrd", /* fcnName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
            "xgehrd.m" /* pathName */
};

static emlrtRSInfo ic_emlrtRSI =
    {
        69,                /* lineNo */
        "ceval_xungorghr", /* fcnName */
        "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xungorghr.m" /* pathName */
};

static emlrtRSInfo jc_emlrtRSI =
    {
        11,          /* lineNo */
        "xungorghr", /* fcnName */
        "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xungorghr.m" /* pathName */
};

static emlrtRSInfo
    kc_emlrtRSI =
        {
            17,       /* lineNo */
            "xhseqr", /* fcnName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
            "xhseqr.m" /* pathName */
};

static emlrtRSInfo
    lc_emlrtRSI =
        {
            128,            /* lineNo */
            "ceval_xhseqr", /* fcnName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
            "xhseqr.m" /* pathName */
};

static emlrtRTEInfo l_emlrtRTEI = {
    18,                                                         /* lineNo */
    15,                                                         /* colNo */
    "schur",                                                    /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/schur.m" /* pName */
};

static emlrtRTEInfo
    ac_emlrtRTEI =
        {
            1,        /* lineNo */
            27,       /* colNo */
            "xgehrd", /* fName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
            "xgehrd.m" /* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = {
    42,                                                         /* lineNo */
    9,                                                          /* colNo */
    "schur",                                                    /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/schur.m" /* pName */
};

static emlrtRTEInfo
    cc_emlrtRTEI =
        {
            76,       /* lineNo */
            22,       /* colNo */
            "xgehrd", /* fName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
            "xgehrd.m" /* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = {
    77,                                                         /* lineNo */
    9,                                                          /* colNo */
    "schur",                                                    /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/schur.m" /* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = {
    46,                                                         /* lineNo */
    9,                                                          /* colNo */
    "schur",                                                    /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/schur.m" /* pName */
};

static emlrtRTEInfo
    fc_emlrtRTEI =
        {
            86,       /* lineNo */
            9,        /* colNo */
            "xgehrd", /* fName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
            "xgehrd.m" /* pName */
};

static emlrtRTEInfo
    gc_emlrtRTEI =
        {
            87,       /* lineNo */
            9,        /* colNo */
            "xgehrd", /* fName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
            "xgehrd.m" /* pName */
};

static emlrtRTEInfo
    hc_emlrtRTEI =
        {
            101,      /* lineNo */
            28,       /* colNo */
            "xhseqr", /* fName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
            "xhseqr.m" /* pName */
};

static emlrtRTEInfo
    ic_emlrtRTEI =
        {
            129,      /* lineNo */
            9,        /* colNo */
            "xhseqr", /* fName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
            "xhseqr.m" /* pName */
};

static emlrtRTEInfo
    jc_emlrtRTEI =
        {
            130,      /* lineNo */
            9,        /* colNo */
            "xhseqr", /* fName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
            "xhseqr.m" /* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = {
    1,                                                          /* lineNo */
    18,                                                         /* colNo */
    "schur",                                                    /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/schur.m" /* pName */
};

static emlrtRTEInfo
    lc_emlrtRTEI =
        {
            101,      /* lineNo */
            9,        /* colNo */
            "xhseqr", /* fName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
            "xhseqr.m" /* pName */
};

/* Function Definitions */
void schur(const emlrtStack *sp, const emxArray_creal_T *A, emxArray_creal_T *V,
           emxArray_creal_T *T)
{
  static const char_T b_fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                     '_', 'z', 'u', 'n', 'g', 'h', 'r'};
  static const char_T c_fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                     '_', 'z', 'h', 's', 'e', 'q', 'r'};
  static const char_T fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'z', 'g', 'e', 'h', 'r', 'd'};
  ptrdiff_t info_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_creal_T *tau;
  emxArray_creal_T *w;
  const creal_T *A_data;
  creal_T *T_data;
  creal_T *V_data;
  creal_T *w_data;
  int32_T i;
  int32_T istart;
  int32_T j;
  int32_T jend;
  int32_T n;
  boolean_T b_p;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  A_data = A->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (A->size[0] != A->size[1]) {
    emlrtErrorWithMessageIdR2018a(sp, &l_emlrtRTEI, "Coder:MATLAB:square",
                                  "Coder:MATLAB:square", 0);
  }
  st.site = &xb_emlrtRSI;
  if (anyNonFinite(&st, A)) {
    j = V->size[0] * V->size[1];
    V->size[0] = A->size[0];
    V->size[1] = A->size[1];
    emxEnsureCapacity_creal_T(sp, V, j, &bc_emlrtRTEI);
    V_data = V->data;
    n = A->size[0] * A->size[1];
    for (j = 0; j < n; j++) {
      V_data[j].re = rtNaN;
      V_data[j].im = 0.0;
    }
    st.site = &yb_emlrtRSI;
    n = V->size[0];
    if ((V->size[0] != 0) && (V->size[1] != 0) && (1 < V->size[0])) {
      istart = 2;
      if (V->size[0] - 2 < V->size[1] - 1) {
        jend = V->size[0] - 1;
      } else {
        jend = V->size[1];
      }
      b_st.site = &fc_emlrtRSI;
      if (jend > 2147483646) {
        c_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (j = 0; j < jend; j++) {
        b_st.site = &ec_emlrtRSI;
        if ((istart <= n) && (n > 2147483646)) {
          c_st.site = &hb_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (i = istart; i <= n; i++) {
          V_data[(i + V->size[0] * j) - 1].re = 0.0;
          V_data[(i + V->size[0] * j) - 1].im = 0.0;
        }
        istart++;
      }
    }
    j = T->size[0] * T->size[1];
    T->size[0] = A->size[0];
    T->size[1] = A->size[1];
    emxEnsureCapacity_creal_T(sp, T, j, &ec_emlrtRTEI);
    T_data = T->data;
    n = A->size[0] * A->size[1];
    for (j = 0; j < n; j++) {
      T_data[j].re = rtNaN;
      T_data[j].im = 0.0;
    }
  } else {
    st.site = &ac_emlrtRSI;
    j = T->size[0] * T->size[1];
    T->size[0] = A->size[0];
    T->size[1] = A->size[1];
    emxEnsureCapacity_creal_T(&st, T, j, &ac_emlrtRTEI);
    T_data = T->data;
    n = A->size[0] * A->size[1];
    for (j = 0; j < n; j++) {
      T_data[j] = A_data[j];
    }
    emxInit_creal_T(&st, &tau, 1, &kc_emlrtRTEI);
    b_st.site = &gc_emlrtRSI;
    n = T->size[0];
    j = tau->size[0];
    if (T->size[0] < 1) {
      tau->size[0] = 0;
    } else {
      tau->size[0] = T->size[0] - 1;
    }
    emxEnsureCapacity_creal_T(&b_st, tau, j, &cc_emlrtRTEI);
    w_data = tau->data;
    if (T->size[0] > 1) {
      info_t = LAPACKE_zgehrd(102, (ptrdiff_t)T->size[0], (ptrdiff_t)1,
                              (ptrdiff_t)T->size[0],
                              (lapack_complex_double *)&T_data[0],
                              (ptrdiff_t)muIntScalarMax_sint32(1, n),
                              (lapack_complex_double *)&w_data[0]);
      jend = (int32_T)info_t;
      c_st.site = &hc_emlrtRSI;
      if (jend != 0) {
        p = true;
        if (jend != -5) {
          if (jend == -1010) {
            emlrtErrorWithMessageIdR2018a(&c_st, &j_emlrtRTEI, "MATLAB:nomem",
                                          "MATLAB:nomem", 0);
          } else {
            emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
                                          "Coder:toolbox:LAPACKCallErrorInfo",
                                          "Coder:toolbox:LAPACKCallErrorInfo",
                                          5, 4, 14, &fname[0], 12, jend);
          }
        }
      } else {
        p = false;
      }
      if (p) {
        n = T->size[0];
        istart = T->size[1];
        j = T->size[0] * T->size[1];
        T->size[0] = n;
        T->size[1] = istart;
        emxEnsureCapacity_creal_T(&b_st, T, j, &fc_emlrtRTEI);
        T_data = T->data;
        n *= istart;
        for (j = 0; j < n; j++) {
          T_data[j].re = rtNaN;
          T_data[j].im = 0.0;
        }
        n = tau->size[0];
        j = tau->size[0];
        tau->size[0] = n;
        emxEnsureCapacity_creal_T(&b_st, tau, j, &gc_emlrtRTEI);
        w_data = tau->data;
        for (j = 0; j < n; j++) {
          w_data[j].re = rtNaN;
          w_data[j].im = 0.0;
        }
      }
    }
    st.site = &bc_emlrtRSI;
    j = V->size[0] * V->size[1];
    V->size[0] = T->size[0];
    V->size[1] = T->size[1];
    emxEnsureCapacity_creal_T(&st, V, j, &dc_emlrtRTEI);
    V_data = V->data;
    n = T->size[0] * T->size[1];
    for (j = 0; j < n; j++) {
      V_data[j] = T_data[j];
    }
    b_st.site = &jc_emlrtRSI;
    if ((V->size[0] != 0) && (V->size[1] != 0)) {
      info_t = LAPACKE_zunghr(
          102, (ptrdiff_t)A->size[0], (ptrdiff_t)1, (ptrdiff_t)A->size[0],
          (lapack_complex_double *)&V_data[0], (ptrdiff_t)A->size[0],
          (lapack_complex_double *)&w_data[0]);
      jend = (int32_T)info_t;
      c_st.site = &ic_emlrtRSI;
      if (jend != 0) {
        p = true;
        b_p = false;
        if (jend == -5) {
          b_p = true;
        } else if (jend == -7) {
          b_p = true;
        }
        if (!b_p) {
          if (jend == -1010) {
            emlrtErrorWithMessageIdR2018a(&c_st, &j_emlrtRTEI, "MATLAB:nomem",
                                          "MATLAB:nomem", 0);
          } else {
            emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
                                          "Coder:toolbox:LAPACKCallErrorInfo",
                                          "Coder:toolbox:LAPACKCallErrorInfo",
                                          5, 4, 14, &b_fname[0], 12, jend);
          }
        }
      } else {
        p = false;
      }
      if (p) {
        n = V->size[0];
        istart = V->size[1];
        j = V->size[0] * V->size[1];
        V->size[0] = n;
        V->size[1] = istart;
        emxEnsureCapacity_creal_T(&b_st, V, j, &dc_emlrtRTEI);
        V_data = V->data;
        n *= istart;
        for (j = 0; j < n; j++) {
          V_data[j].re = rtNaN;
          V_data[j].im = 0.0;
        }
      }
    }
    emxFree_creal_T(&b_st, &tau);
    st.site = &cc_emlrtRSI;
    b_st.site = &kc_emlrtRSI;
    n = T->size[0];
    info_t = (ptrdiff_t)T->size[0];
    if ((T->size[0] != 0) && (T->size[1] != 0)) {
      emxInit_creal_T(&b_st, &w, 2, &lc_emlrtRTEI);
      j = w->size[0] * w->size[1];
      w->size[0] = 1;
      w->size[1] = T->size[0];
      emxEnsureCapacity_creal_T(&b_st, w, j, &hc_emlrtRTEI);
      w_data = w->data;
      info_t = LAPACKE_zhseqr(102, 'S', 'V', info_t, (ptrdiff_t)1,
                              (ptrdiff_t)T->size[0],
                              (lapack_complex_double *)&T_data[0], info_t,
                              (lapack_complex_double *)&w_data[0],
                              (lapack_complex_double *)&V_data[0],
                              (ptrdiff_t)muIntScalarMax_sint32(1, n));
      jend = (int32_T)info_t;
      c_st.site = &lc_emlrtRSI;
      emxFree_creal_T(&c_st, &w);
      if (jend < 0) {
        p = true;
        b_p = false;
        if (jend == -7) {
          b_p = true;
        } else if (jend == -10) {
          b_p = true;
        }
        if (!b_p) {
          if (jend == -1010) {
            emlrtErrorWithMessageIdR2018a(&c_st, &j_emlrtRTEI, "MATLAB:nomem",
                                          "MATLAB:nomem", 0);
          } else {
            emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
                                          "Coder:toolbox:LAPACKCallErrorInfo",
                                          "Coder:toolbox:LAPACKCallErrorInfo",
                                          5, 4, 14, &c_fname[0], 12, jend);
          }
        }
      } else {
        p = false;
      }
      if (p) {
        n = T->size[0];
        istart = T->size[1];
        j = T->size[0] * T->size[1];
        T->size[0] = n;
        T->size[1] = istart;
        emxEnsureCapacity_creal_T(&b_st, T, j, &ic_emlrtRTEI);
        T_data = T->data;
        n *= istart;
        for (j = 0; j < n; j++) {
          T_data[j].re = rtNaN;
          T_data[j].im = 0.0;
        }
        n = V->size[0];
        istart = V->size[1];
        j = V->size[0] * V->size[1];
        V->size[0] = n;
        V->size[1] = istart;
        emxEnsureCapacity_creal_T(&b_st, V, j, &jc_emlrtRTEI);
        V_data = V->data;
        n *= istart;
        for (j = 0; j < n; j++) {
          V_data[j].re = rtNaN;
          V_data[j].im = 0.0;
        }
      }
    } else {
      jend = 0;
    }
    if (jend != 0) {
      st.site = &dc_emlrtRSI;
      b_warning(&st);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (schur.c) */
