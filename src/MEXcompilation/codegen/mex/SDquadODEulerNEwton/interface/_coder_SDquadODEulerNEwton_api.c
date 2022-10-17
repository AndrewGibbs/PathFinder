/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_SDquadODEulerNEwton_api.c
 *
 * Code generation for function '_coder_SDquadODEulerNEwton_api'
 *
 */

/* Include files */
#include "_coder_SDquadODEulerNEwton_api.h"
#include "SDquadODEulerNEwton.h"
#include "SDquadODEulerNEwton_data.h"
#include "SDquadODEulerNEwton_emxutil.h"
#include "SDquadODEulerNEwton_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo h_emlrtRTEI = {
    1,                                /* lineNo */
    1,                                /* colNo */
    "_coder_SDquadODEulerNEwton_api", /* fName */
    ""                                /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);

static creal_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *h0,
                                  const char_T *identifier);

static creal_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId);

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *gCoeffs,
                               const char_T *identifier, emxArray_creal_T *y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *p_quad,
                             const char_T *identifier, emxArray_real_T *y);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const emxArray_creal_T *u);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_creal_T *y);

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *freq,
                                 const char_T *identifier);

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static creal_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId);

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_creal_T *ret);

static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  static const int32_T i = 0;
  const mxArray *m;
  const mxArray *y;
  const real_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 1);
  emlrtAssign(&y, m);
  return y;
}

static creal_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *h0,
                                  const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  creal_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(h0), &thisId);
  emlrtDestroyArray(&h0);
  return y;
}

static creal_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId)
{
  creal_T y;
  y = j_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *gCoeffs,
                               const char_T *identifier, emxArray_creal_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(gCoeffs), &thisId, y);
  emlrtDestroyArray(&gCoeffs);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *p_quad,
                             const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(p_quad), &thisId, y);
  emlrtDestroyArray(&p_quad);
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const emxArray_creal_T *u)
{
  const mxArray *m;
  const mxArray *y;
  const creal_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(1, &u->size[0], mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b((emlrtCTX)sp, m, (void *)&u_data[0], 8);
  emlrtAssign(&y, m);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_creal_T *y)
{
  k_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *freq,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(freq), &thisId);
  emlrtDestroyArray(&freq);
  return y;
}

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims = -1;
  int32_T i;
  int32_T i1;
  const boolean_T b = true;
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 1U, (void *)&dims, &b, &i);
  ret->allocatedSize = i;
  i1 = ret->size[0];
  ret->size[0] = i;
  emxEnsureCapacity_real_T(sp, ret, i1, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static creal_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  creal_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          true, 0U, (void *)&dims);
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret, 8, true);
  emlrtDestroyArray(&src);
  return ret;
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_creal_T *ret)
{
  static const int32_T dims[2] = {1, -1};
  creal_T *ret_data;
  int32_T iv[2];
  int32_T i;
  const boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            true, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_creal_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret_data[0], 8, true);
  emlrtDestroyArray(&src);
}

static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void SDquadODEulerNEwton_api(const mxArray *const prhs[4], int32_T nlhs,
                             const mxArray *plhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_creal_T *dhdp_quad;
  emxArray_creal_T *gCoeffs;
  emxArray_creal_T *h_quad;
  emxArray_real_T *Newton_success;
  emxArray_real_T *p_quad;
  creal_T h0;
  real_T freq;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &p_quad, 1, &h_emlrtRTEI);
  emxInit_creal_T(&st, &gCoeffs, 2, &h_emlrtRTEI);
  emxInit_creal_T(&st, &h_quad, 1, &h_emlrtRTEI);
  emxInit_creal_T(&st, &dhdp_quad, 1, &h_emlrtRTEI);
  emxInit_real_T(&st, &Newton_success, 1, &h_emlrtRTEI);
  /* Marshall function inputs */
  p_quad->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "p_quad", p_quad);
  h0 = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "h0");
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "gCoeffs", gCoeffs);
  freq = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "freq");
  /* Invoke the target function */
  SDquadODEulerNEwton(&st, p_quad, h0, gCoeffs, freq, h_quad, dhdp_quad,
                      Newton_success);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, h_quad);
  emxFree_creal_T(&st, &h_quad);
  emxFree_creal_T(&st, &gCoeffs);
  emxFree_real_T(&st, &p_quad);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(&st, dhdp_quad);
  }
  emxFree_creal_T(&st, &dhdp_quad);
  if (nlhs > 2) {
    Newton_success->canFreeData = false;
    plhs[2] = b_emlrt_marshallOut(Newton_success);
  }
  emxFree_real_T(&st, &Newton_success);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_SDquadODEulerNEwton_api.c) */
