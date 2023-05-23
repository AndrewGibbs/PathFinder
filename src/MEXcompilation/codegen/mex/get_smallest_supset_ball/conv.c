/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * conv.c
 *
 * Code generation for function 'conv'
 *
 */

/* Include files */
#include "conv.h"
#include "anyNonFinite.h"
#include "eml_int_forloop_overflow_check.h"
#include "get_smallest_supset_ball_data.h"
#include "get_smallest_supset_ball_emxutil.h"
#include "get_smallest_supset_ball_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo s_emlrtRSI = {
    57,                                                         /* lineNo */
    "conv",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/conv.m" /* pathName */
};

static emlrtRSInfo t_emlrtRSI = {
    48,                                                         /* lineNo */
    "conv",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/conv.m" /* pathName */
};

static emlrtRSInfo u_emlrtRSI = {
    45,                                                         /* lineNo */
    "conv",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/conv.m" /* pathName */
};

static emlrtRSInfo v_emlrtRSI = {
    44,                                                         /* lineNo */
    "conv",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/conv.m" /* pathName */
};

static emlrtRSInfo ab_emlrtRSI = {
    109,                                                        /* lineNo */
    "convFull",                                                 /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/conv.m" /* pathName */
};

static emlrtRSInfo bb_emlrtRSI = {
    113,                                                        /* lineNo */
    "convFull",                                                 /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/conv.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    110,                                                        /* lineNo */
    "convFull",                                                 /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/conv.m" /* pathName */
};

static emlrtRSInfo db_emlrtRSI = {
    114,                                                        /* lineNo */
    "convFull",                                                 /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/conv.m" /* pathName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    79,                                                         /* lineNo */
    1,                                                          /* colNo */
    "convFull",                                                 /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/conv.m" /* pName */
};

static emlrtDCInfo b_emlrtDCI = {
    57,                                                          /* lineNo */
    13,                                                          /* colNo */
    "conv",                                                      /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/conv.m", /* pName */
    4                                                            /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    48,                                                          /* lineNo */
    13,                                                          /* colNo */
    "conv",                                                      /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/conv.m", /* pName */
    4                                                            /* checkKind */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    57,                                                         /* lineNo */
    13,                                                         /* colNo */
    "conv",                                                     /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/conv.m" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = {
    48,                                                         /* lineNo */
    13,                                                         /* colNo */
    "conv",                                                     /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/conv.m" /* pName */
};

/* Function Definitions */
void conv(const emlrtStack *sp, const emxArray_creal_T *A,
          const emxArray_creal_T *B, emxArray_creal_T *C)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  const creal_T *A_data;
  const creal_T *B_data;
  creal_T *C_data;
  real_T B_re_tmp;
  real_T b_B_re_tmp;
  real_T c_B_re_tmp;
  real_T d_B_re_tmp;
  int32_T i;
  int32_T nA;
  int32_T nApnB;
  int32_T nB;
  int32_T nC;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = sp;
  b_st.tls = sp->tls;
  c_st.prev = &st;
  c_st.tls = st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  B_data = B->data;
  A_data = A->data;
  st.site = &v_emlrtRSI;
  b_st.site = &u_emlrtRSI;
  if (anyNonFinite(&st, A) || anyNonFinite(&b_st, B)) {
    st.site = &t_emlrtRSI;
    nA = A->size[0] - 1;
    nB = B->size[0] - 1;
    nApnB = A->size[0] + B->size[0];
    if ((A->size[0] == 0) || (B->size[0] == 0)) {
      nC = nApnB;
    } else {
      nC = nApnB - 1;
    }
    if (nC > nApnB) {
      emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nC < 0) {
      emlrtNonNegativeCheckR2012b(nC, &c_emlrtDCI, &st);
    }
    i = C->size[0];
    C->size[0] = nC;
    emxEnsureCapacity_creal_T(&st, C, i, &db_emlrtRTEI);
    C_data = C->data;
    for (i = 0; i < nC; i++) {
      C_data[i].re = 0.0;
      C_data[i].im = 0.0;
    }
    if ((A->size[0] > 0) && (B->size[0] > 0)) {
      if (B->size[0] > A->size[0]) {
        c_st.site = &ab_emlrtRSI;
        for (nApnB = 0; nApnB <= nA; nApnB++) {
          for (nC = 0; nC <= nB; nC++) {
            B_re_tmp = A_data[nApnB].re;
            b_B_re_tmp = B_data[nC].im;
            c_B_re_tmp = A_data[nApnB].im;
            d_B_re_tmp = B_data[nC].re;
            i = nApnB + nC;
            C_data[i].re += B_re_tmp * d_B_re_tmp - c_B_re_tmp * b_B_re_tmp;
            C_data[i].im += B_re_tmp * b_B_re_tmp + c_B_re_tmp * d_B_re_tmp;
          }
        }
      } else {
        c_st.site = &bb_emlrtRSI;
        if (B->size[0] > 2147483646) {
          d_st.site = &e_emlrtRSI;
          b_check_forloop_overflow_error(&d_st);
        }
        for (nApnB = 0; nApnB <= nB; nApnB++) {
          for (nC = 0; nC <= nA; nC++) {
            B_re_tmp = B_data[nApnB].re;
            b_B_re_tmp = A_data[nC].im;
            c_B_re_tmp = B_data[nApnB].im;
            d_B_re_tmp = A_data[nC].re;
            i = nApnB + nC;
            C_data[i].re += B_re_tmp * d_B_re_tmp - c_B_re_tmp * b_B_re_tmp;
            C_data[i].im += B_re_tmp * b_B_re_tmp + c_B_re_tmp * d_B_re_tmp;
          }
        }
      }
    }
  } else {
    st.site = &s_emlrtRSI;
    nA = A->size[0];
    nB = B->size[0];
    nApnB = A->size[0] + B->size[0];
    if ((A->size[0] == 0) || (B->size[0] == 0)) {
      nC = nApnB;
    } else {
      nC = nApnB - 1;
    }
    if (nC > nApnB) {
      emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (nC < 0) {
      emlrtNonNegativeCheckR2012b(nC, &b_emlrtDCI, &st);
    }
    i = C->size[0];
    C->size[0] = nC;
    emxEnsureCapacity_creal_T(&st, C, i, &cb_emlrtRTEI);
    C_data = C->data;
    for (i = 0; i < nC; i++) {
      C_data[i].re = 0.0;
      C_data[i].im = 0.0;
    }
    if ((A->size[0] > 0) && (B->size[0] > 0)) {
      if (B->size[0] > A->size[0]) {
        c_st.site = &ab_emlrtRSI;
        for (nApnB = 0; nApnB < nA; nApnB++) {
          c_st.site = &cb_emlrtRSI;
          n_t = (ptrdiff_t)nB;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          zaxpy(&n_t, (real_T *)&A_data[nApnB], (real_T *)&B_data[0], &incx_t,
                (real_T *)&C_data[nApnB], &incy_t);
        }
      } else {
        c_st.site = &bb_emlrtRSI;
        if (B->size[0] > 2147483646) {
          d_st.site = &e_emlrtRSI;
          b_check_forloop_overflow_error(&d_st);
        }
        for (nApnB = 0; nApnB < nB; nApnB++) {
          c_st.site = &db_emlrtRSI;
          n_t = (ptrdiff_t)nA;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          zaxpy(&n_t, (real_T *)&B_data[nApnB], (real_T *)&A_data[0], &incx_t,
                (real_T *)&C_data[nApnB], &incy_t);
        }
      }
    }
  }
}

/* End of code generation (conv.c) */
