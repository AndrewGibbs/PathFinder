/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sort.c
 *
 * Code generation for function 'sort'
 *
 */

/* Include files */
#include "sort.h"
#include "eml_int_forloop_overflow_check.h"
#include "get_smallest_supset_ball_data.h"
#include "get_smallest_supset_ball_emxutil.h"
#include "get_smallest_supset_ball_types.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"

/* Variable Definitions */
static emlrtRSInfo yc_emlrtRSI = {
    76,                                                           /* lineNo */
    "sort",                                                       /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sort.m" /* pathName */
};

static emlrtRSInfo ad_emlrtRSI = {
    79,                                                           /* lineNo */
    "sort",                                                       /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sort.m" /* pathName */
};

static emlrtRSInfo bd_emlrtRSI = {
    81,                                                           /* lineNo */
    "sort",                                                       /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sort.m" /* pathName */
};

static emlrtRSInfo cd_emlrtRSI = {
    84,                                                           /* lineNo */
    "sort",                                                       /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sort.m" /* pathName */
};

static emlrtRSInfo dd_emlrtRSI = {
    87,                                                           /* lineNo */
    "sort",                                                       /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sort.m" /* pathName */
};

static emlrtRSInfo ed_emlrtRSI = {
    90,                                                           /* lineNo */
    "sort",                                                       /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sort.m" /* pathName */
};

static emlrtRTEInfo fc_emlrtRTEI = {
    56,                                                           /* lineNo */
    24,                                                           /* colNo */
    "sort",                                                       /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sort.m" /* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = {
    56,                                                           /* lineNo */
    1,                                                            /* colNo */
    "sort",                                                       /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sort.m" /* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = {
    1,                                                            /* lineNo */
    20,                                                           /* colNo */
    "sort",                                                       /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sort.m" /* pName */
};

/* Function Definitions */
void sort(const emlrtStack *sp, emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_int32_T *af_emlrtRSI;
  emxArray_real_T *vwork;
  real_T *vwork_data;
  real_T *x_data;
  int32_T dim;
  int32_T i;
  int32_T k;
  int32_T vlen;
  int32_T vstride;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  dim = 0;
  if (x->size[0] != 1) {
    dim = -1;
  }
  emxInit_real_T(sp, &vwork, &gc_emlrtRTEI);
  if (dim + 2 <= 1) {
    i = x->size[0];
  } else {
    i = 1;
  }
  vlen = i - 1;
  vstride = vwork->size[0];
  vwork->size[0] = i;
  emxEnsureCapacity_real_T(sp, vwork, vstride, &fc_emlrtRTEI);
  vwork_data = vwork->data;
  st.site = &yc_emlrtRSI;
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= x->size[0];
  }
  st.site = &ad_emlrtRSI;
  st.site = &bd_emlrtRSI;
  if ((1 <= vstride) && (vstride > 2147483646)) {
    b_st.site = &f_emlrtRSI;
    b_check_forloop_overflow_error(&b_st);
  }
  emxInit_int32_T(sp, &af_emlrtRSI, &hc_emlrtRTEI);
  for (dim = 0; dim < vstride; dim++) {
    st.site = &cd_emlrtRSI;
    if ((1 <= i) && (i > 2147483646)) {
      b_st.site = &f_emlrtRSI;
      b_check_forloop_overflow_error(&b_st);
    }
    for (k = 0; k <= vlen; k++) {
      vwork_data[k] = x_data[dim + k * vstride];
    }
    st.site = &dd_emlrtRSI;
    sortIdx(&st, vwork, af_emlrtRSI);
    vwork_data = vwork->data;
    st.site = &ed_emlrtRSI;
    for (k = 0; k <= vlen; k++) {
      x_data[dim + k * vstride] = vwork_data[k];
    }
  }
  emxFree_int32_T(sp, &af_emlrtRSI);
  emxFree_real_T(sp, &vwork);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (sort.c) */
