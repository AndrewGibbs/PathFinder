/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_SDpathODEuler_api.c
 *
 * Code generation for function '_coder_SDpathODEuler_api'
 *
 */

/* Include files */
#include "_coder_SDpathODEuler_api.h"
#include "SDpathODEuler.h"
#include "SDpathODEuler_data.h"
#include "SDpathODEuler_emxutil.h"
#include "SDpathODEuler_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo v_emlrtRTEI = {
    1,                          /* lineNo */
    1,                          /* colNo */
    "_coder_SDpathODEuler_api", /* fName */
    ""                          /* pName */
};

/* Function Declarations */
static creal_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId);

static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp,
                                          const emxArray_creal_T *u);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *gCoeffs,
                               const char_T *identifier, emxArray_creal_T *y);

static const mxArray *c_emlrt_marshallOut(const real_T u_data[],
                                          const int32_T u_size[2]);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_creal_T *y);

static const mxArray *d_emlrt_marshallOut(const boolean_T u);

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *SPs,
                               const char_T *identifier, emxArray_creal_T *y);

static creal_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *h0,
                                const char_T *identifier);

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_creal_T *y);

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *cover_radii,
                               const char_T *identifier, emxArray_real_T *y);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static real_T i_emlrt_marshallIn(const emlrtStack *sp,
                                 const mxArray *base_step_size,
                                 const char_T *identifier);

static real_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static int64_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *n_max,
                                  const char_T *identifier);

static int64_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId);

static creal_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId);

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_creal_T *ret);

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_creal_T *ret);

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static real_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static int64_T r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId);

/* Function Definitions */
static creal_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId)
{
  creal_T y;
  y = m_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp,
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

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *gCoeffs,
                               const char_T *identifier, emxArray_creal_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(gCoeffs), &thisId, y);
  emlrtDestroyArray(&gCoeffs);
}

static const mxArray *c_emlrt_marshallOut(const real_T u_data[],
                                          const int32_T u_size[2])
{
  static const int32_T iv[2] = {0, 0};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u_size[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_creal_T *y)
{
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *d_emlrt_marshallOut(const boolean_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateLogicalScalar(u);
  emlrtAssign(&y, m);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *SPs,
                               const char_T *identifier, emxArray_creal_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(SPs), &thisId, y);
  emlrtDestroyArray(&SPs);
}

static creal_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *h0,
                                const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  creal_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(h0), &thisId);
  emlrtDestroyArray(&h0);
  return y;
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
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

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_creal_T *y)
{
  o_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *cover_radii,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(cover_radii), &thisId, y);
  emlrtDestroyArray(&cover_radii);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  p_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T i_emlrt_marshallIn(const emlrtStack *sp,
                                 const mxArray *base_step_size,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = j_emlrt_marshallIn(sp, emlrtAlias(base_step_size), &thisId);
  emlrtDestroyArray(&base_step_size);
  return y;
}

static real_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = q_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static int64_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *n_max,
                                  const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  int64_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = l_emlrt_marshallIn(sp, emlrtAlias(n_max), &thisId);
  emlrtDestroyArray(&n_max);
  return y;
}

static int64_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId)
{
  int64_T y;
  y = r_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static creal_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_creal_T *ret)
{
  static const int32_T dims = -1;
  creal_T *ret_data;
  int32_T i;
  int32_T i1;
  const boolean_T b = true;
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            true, 1U, (void *)&dims, &b, &i);
  i1 = ret->size[0];
  ret->size[0] = i;
  emxEnsureCapacity_creal_T(sp, ret, i1, (emlrtRTEInfo *)NULL);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret_data[0], 8, true);
  emlrtDestroyArray(&src);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static real_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static int64_T r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  int64_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"int64",
                          false, 0U, (void *)&dims);
  ret = *(int64_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void SDpathODEuler_api(const mxArray *const prhs[7], int32_T nlhs,
                       const mxArray *plhs[5])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_creal_T *SPs;
  emxArray_creal_T *gCoeffs;
  emxArray_creal_T *h_log_out;
  emxArray_creal_T *valleys;
  emxArray_real_T *cover_radii;
  emxArray_real_T *p_log_out;
  const mxArray *prhs_copy_idx_3;
  creal_T h0;
  int64_T n_max;
  real_T base_step_size;
  real_T *ball_index_data;
  real_T *valley_index_data;
  int32_T ball_index_size[2];
  int32_T valley_index_size[2];
  boolean_T success;
  st.tls = emlrtRootTLSGlobal;
  valley_index_data = &(*(real_T(*)[1])mxMalloc(sizeof(real_T)))[0];
  ball_index_data = &(*(real_T(*)[1])mxMalloc(sizeof(real_T)))[0];
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_creal_T(&st, &gCoeffs, 2, &v_emlrtRTEI);
  emxInit_creal_T(&st, &SPs, 1, &v_emlrtRTEI);
  emxInit_real_T(&st, &cover_radii, 1, &v_emlrtRTEI);
  emxInit_creal_T(&st, &valleys, 1, &v_emlrtRTEI);
  emxInit_real_T(&st, &p_log_out, 1, &v_emlrtRTEI);
  emxInit_creal_T(&st, &h_log_out, 1, &v_emlrtRTEI);
  prhs_copy_idx_3 = emlrtProtectR2012b(prhs[3], 3, false, -1);
  /* Marshall function inputs */
  h0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "h0");
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "gCoeffs", gCoeffs);
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "SPs", SPs);
  cover_radii->canFreeData = false;
  g_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_3), "cover_radii",
                     cover_radii);
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "valleys", valleys);
  base_step_size =
      i_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "base_step_size");
  n_max = k_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "n_max");
  /* Invoke the target function */
  SDpathODEuler(&st, h0, gCoeffs, SPs, cover_radii, valleys, base_step_size,
                n_max, p_log_out, h_log_out, (real_T *)valley_index_data,
                valley_index_size, (real_T *)ball_index_data, ball_index_size,
                &success);
  /* Marshall function outputs */
  p_log_out->canFreeData = false;
  plhs[0] = emlrt_marshallOut(p_log_out);
  emxFree_real_T(&st, &p_log_out);
  emxFree_creal_T(&st, &valleys);
  emxFree_real_T(&st, &cover_radii);
  emxFree_creal_T(&st, &SPs);
  emxFree_creal_T(&st, &gCoeffs);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(&st, h_log_out);
  }
  emxFree_creal_T(&st, &h_log_out);
  if (nlhs > 2) {
    plhs[2] =
        c_emlrt_marshallOut((real_T *)valley_index_data, valley_index_size);
  }
  if (nlhs > 3) {
    plhs[3] = c_emlrt_marshallOut((real_T *)ball_index_data, ball_index_size);
  }
  if (nlhs > 4) {
    plhs[4] = d_emlrt_marshallOut(success);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_SDpathODEuler_api.c) */
