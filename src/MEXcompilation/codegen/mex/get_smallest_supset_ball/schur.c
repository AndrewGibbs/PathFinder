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
#include "get_smallest_supset_ball_data.h"
#include "get_smallest_supset_ball_emxutil.h"
#include "get_smallest_supset_ball_types.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "lapacke.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo yb_emlrtRSI = {
    35,                                                         /* lineNo */
    "schur",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/schur.m" /* pathName */
};

static emlrtRSInfo ac_emlrtRSI = {
    43,                                                         /* lineNo */
    "schur",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/schur.m" /* pathName */
};

static emlrtRSInfo bc_emlrtRSI = {
    60,                                                         /* lineNo */
    "schur",                                                    /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/schur.m" /* pathName */
};

static emlrtRSInfo cc_emlrtRSI = {
    61,                                                         /* lineNo */
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

static emlrtRSInfo
    ic_emlrtRSI =
        {
            28,       /* lineNo */
            "xhseqr", /* fcnName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
            "xhseqr.m" /* pathName */
};

static emlrtRSInfo
    jc_emlrtRSI =
        {
            128,            /* lineNo */
            "ceval_xhseqr", /* fcnName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
            "xhseqr.m" /* pathName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    18,                                                         /* lineNo */
    15,                                                         /* colNo */
    "schur",                                                    /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/schur.m" /* pName */
};

static emlrtRTEInfo
    sb_emlrtRTEI =
        {
            76,       /* lineNo */
            22,       /* colNo */
            "xgehrd", /* fName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
            "xgehrd.m" /* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = {
    42,                                                         /* lineNo */
    9,                                                          /* colNo */
    "schur",                                                    /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/schur.m" /* pName */
};

static emlrtRTEInfo
    ub_emlrtRTEI =
        {
            86,       /* lineNo */
            9,        /* colNo */
            "xgehrd", /* fName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
            "xgehrd.m" /* pName */
};

static emlrtRTEInfo
    vb_emlrtRTEI =
        {
            101,      /* lineNo */
            28,       /* colNo */
            "xhseqr", /* fName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
            "xhseqr.m" /* pName */
};

static emlrtRTEInfo
    wb_emlrtRTEI =
        {
            129,      /* lineNo */
            9,        /* colNo */
            "xhseqr", /* fName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
            "xhseqr.m" /* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = {
    1,                                                          /* lineNo */
    18,                                                         /* colNo */
    "schur",                                                    /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/matfun/schur.m" /* pName */
};

static emlrtRTEInfo
    yb_emlrtRTEI =
        {
            101,      /* lineNo */
            9,        /* colNo */
            "xhseqr", /* fName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
            "xhseqr.m" /* pName */
};

/* Function Definitions */
void schur(const emlrtStack *sp, emxArray_creal_T *A)
{
  static const char_T b_fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                     '_', 'z', 'h', 's', 'e', 'q', 'r'};
  static const char_T fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'z', 'g', 'e', 'h', 'r', 'd'};
  ptrdiff_t info_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_creal_T *tau;
  emxArray_creal_T *w;
  creal_T z;
  creal_T *A_data;
  creal_T *w_data;
  int32_T i;
  int32_T istart;
  int32_T j;
  int32_T jend;
  int32_T m;
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
    emlrtErrorWithMessageIdR2018a(sp, &p_emlrtRTEI, "Coder:MATLAB:square",
                                  "Coder:MATLAB:square", 0);
  }
  st.site = &yb_emlrtRSI;
  if (b_anyNonFinite(&st, A)) {
    m = A->size[0];
    istart = A->size[1];
    j = A->size[0] * A->size[1];
    A->size[0] = m;
    A->size[1] = istart;
    emxEnsureCapacity_creal_T(sp, A, j, &tb_emlrtRTEI);
    A_data = A->data;
    for (j = 0; j < istart; j++) {
      for (i = 0; i < m; i++) {
        A_data[i + A->size[0] * j].re = rtNaN;
        A_data[i + A->size[0] * j].im = 0.0;
      }
    }
    st.site = &ac_emlrtRSI;
    m = A->size[0];
    if (1 < A->size[0]) {
      istart = 2;
      if (A->size[0] - 2 < A->size[1] - 1) {
        jend = A->size[0] - 1;
      } else {
        jend = A->size[1];
      }
      b_st.site = &fc_emlrtRSI;
      if ((1 <= jend) && (jend > 2147483646)) {
        c_st.site = &e_emlrtRSI;
        b_check_forloop_overflow_error(&c_st);
      }
      for (j = 0; j < jend; j++) {
        b_st.site = &ec_emlrtRSI;
        if ((istart <= m) && (m > 2147483646)) {
          c_st.site = &e_emlrtRSI;
          b_check_forloop_overflow_error(&c_st);
        }
        for (i = istart; i <= m; i++) {
          A_data[(i + A->size[0] * j) - 1].re = 0.0;
          A_data[(i + A->size[0] * j) - 1].im = 0.0;
        }
        istart++;
      }
    }
  } else {
    emxInit_creal_T(sp, &tau, 1, &xb_emlrtRTEI);
    st.site = &bc_emlrtRSI;
    b_st.site = &gc_emlrtRSI;
    j = tau->size[0];
    tau->size[0] = A->size[0] - 1;
    emxEnsureCapacity_creal_T(&b_st, tau, j, &sb_emlrtRTEI);
    w_data = tau->data;
    if (A->size[0] > 1) {
      info_t = LAPACKE_zgehrd(
          102, (ptrdiff_t)A->size[0], (ptrdiff_t)1, (ptrdiff_t)A->size[0],
          (lapack_complex_double *)&A_data[0], (ptrdiff_t)A->size[0],
          (lapack_complex_double *)&w_data[0]);
      m = (int32_T)info_t;
      c_st.site = &hc_emlrtRSI;
      if (m != 0) {
        p = true;
        if (m != -5) {
          if (m == -1010) {
            emlrtErrorWithMessageIdR2018a(&c_st, &g_emlrtRTEI, "MATLAB:nomem",
                                          "MATLAB:nomem", 0);
          } else {
            emlrtErrorWithMessageIdR2018a(&c_st, &f_emlrtRTEI,
                                          "Coder:toolbox:LAPACKCallErrorInfo",
                                          "Coder:toolbox:LAPACKCallErrorInfo",
                                          5, 4, 14, &fname[0], 12, m);
          }
        }
      } else {
        p = false;
      }
      if (p) {
        istart = A->size[0];
        jend = A->size[1];
        j = A->size[0] * A->size[1];
        A->size[0] = istart;
        A->size[1] = jend;
        emxEnsureCapacity_creal_T(&b_st, A, j, &ub_emlrtRTEI);
        A_data = A->data;
        for (j = 0; j < jend; j++) {
          for (i = 0; i < istart; i++) {
            A_data[i + A->size[0] * j].re = rtNaN;
            A_data[i + A->size[0] * j].im = 0.0;
          }
        }
      }
    }
    emxFree_creal_T(&b_st, &tau);
    emxInit_creal_T(&b_st, &w, 2, &yb_emlrtRTEI);
    st.site = &cc_emlrtRSI;
    b_st.site = &ic_emlrtRSI;
    z.re = 0.0;
    z.im = 0.0;
    info_t = (ptrdiff_t)A->size[0];
    j = w->size[0] * w->size[1];
    w->size[0] = 1;
    w->size[1] = A->size[0];
    emxEnsureCapacity_creal_T(&b_st, w, j, &vb_emlrtRTEI);
    w_data = w->data;
    info_t = LAPACKE_zhseqr(102, 'S', 'N', info_t, (ptrdiff_t)1,
                            (ptrdiff_t)A->size[0],
                            (lapack_complex_double *)&A_data[0], info_t,
                            (lapack_complex_double *)&w_data[0],
                            (lapack_complex_double *)&z, (ptrdiff_t)A->size[0]);
    m = (int32_T)info_t;
    c_st.site = &jc_emlrtRSI;
    emxFree_creal_T(&c_st, &w);
    if (m < 0) {
      p = true;
      b_p = false;
      if (m == -7) {
        b_p = true;
      } else if (m == -10) {
        b_p = true;
      }
      if (!b_p) {
        if (m == -1010) {
          emlrtErrorWithMessageIdR2018a(&c_st, &g_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&c_st, &f_emlrtRTEI,
                                        "Coder:toolbox:LAPACKCallErrorInfo",
                                        "Coder:toolbox:LAPACKCallErrorInfo", 5,
                                        4, 14, &b_fname[0], 12, m);
        }
      }
    } else {
      p = false;
    }
    if (p) {
      istart = A->size[0];
      jend = A->size[1];
      j = A->size[0] * A->size[1];
      A->size[0] = istart;
      A->size[1] = jend;
      emxEnsureCapacity_creal_T(&b_st, A, j, &wb_emlrtRTEI);
      A_data = A->data;
      for (j = 0; j < jend; j++) {
        for (i = 0; i < istart; i++) {
          A_data[i + A->size[0] * j].re = rtNaN;
          A_data[i + A->size[0] * j].im = 0.0;
        }
      }
    }
    if (m != 0) {
      st.site = &dc_emlrtRSI;
      b_warning(&st);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (schur.c) */
