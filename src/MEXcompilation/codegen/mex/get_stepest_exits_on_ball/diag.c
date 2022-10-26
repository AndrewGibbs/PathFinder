/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diag.c
 *
 * Code generation for function 'diag'
 *
 */

/* Include files */
#include "diag.h"
#include "get_stepest_exits_on_ball_emxutil.h"
#include "get_stepest_exits_on_ball_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRTEInfo m_emlrtRTEI = {
    102,                                                      /* lineNo */
    19,                                                       /* colNo */
    "diag",                                                   /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/elmat/diag.m" /* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = {
    100,                                                      /* lineNo */
    5,                                                        /* colNo */
    "diag",                                                   /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/elmat/diag.m" /* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = {
    109,                                                      /* lineNo */
    24,                                                       /* colNo */
    "diag",                                                   /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/elmat/diag.m" /* pName */
};

/* Function Definitions */
void diag(const emlrtStack *sp, const emxArray_creal_T *v, emxArray_creal_T *d)
{
  const creal_T *v_data;
  creal_T *d_data;
  int32_T m;
  int32_T n;
  v_data = v->data;
  if ((v->size[0] == 1) && (v->size[1] == 1)) {
    n = d->size[0];
    d->size[0] = 1;
    emxEnsureCapacity_creal_T(sp, d, n, &mc_emlrtRTEI);
    d_data = d->data;
    d_data[0] = v_data[0];
  } else {
    if ((v->size[0] == 1) || (v->size[1] == 1)) {
      emlrtErrorWithMessageIdR2018a(
          sp, &m_emlrtRTEI, "Coder:toolbox:diag_varsizedMatrixVector",
          "Coder:toolbox:diag_varsizedMatrixVector", 0);
    }
    m = v->size[0];
    n = v->size[1];
    if (0 < v->size[1]) {
      m = muIntScalarMin_sint32(m, n);
    } else {
      m = 0;
    }
    n = d->size[0];
    d->size[0] = m;
    emxEnsureCapacity_creal_T(sp, d, n, &nc_emlrtRTEI);
    d_data = d->data;
    n = m - 1;
    for (m = 0; m <= n; m++) {
      d_data[m] = v_data[m + v->size[0] * m];
    }
  }
}

/* End of code generation (diag.c) */
