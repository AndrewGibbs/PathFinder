/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_SE_NEwtonCorrection_api.c
 *
 * Code generation for function '_coder_SE_NEwtonCorrection_api'
 *
 */

/* Include files */
#include "_coder_SE_NEwtonCorrection_api.h"
#include "SE_NEwtonCorrection.h"
#include "SE_NEwtonCorrection_data.h"
#include "SE_NEwtonCorrection_emxutil.h"
#include "SE_NEwtonCorrection_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo e_emlrtRTEI = {
    1,                                /* lineNo */
    1,                                /* colNo */
    "_coder_SE_NEwtonCorrection_api", /* fName */
    ""                                /* pName */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *b_emlrt_marshallOut(const boolean_T u);

static creal_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *SEn0,
                                  const char_T *identifier);

static creal_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId);

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *gCoeffs,
                               const char_T *identifier, emxArray_creal_T *y);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *P,
                               const char_T *identifier);

static const mxArray *emlrt_marshallOut(const creal_T u);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_creal_T *y);

static uint32_T g_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *NewtonIts,
                                   const char_T *identifier);

static uint32_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId);

static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static creal_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId);

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_creal_T *ret);

static uint32_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *b_emlrt_marshallOut(const boolean_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateLogicalScalar(u);
  emlrtAssign(&y, m);
  return y;
}

static creal_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *SEn0,
                                  const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  creal_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(SEn0), &thisId);
  emlrtDestroyArray(&SEn0);
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

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *P,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(P), &thisId);
  emlrtDestroyArray(&P);
  return y;
}

static const mxArray *emlrt_marshallOut(const creal_T u)
{
  const mxArray *m;
  const mxArray *y;
  creal_T *r;
  y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxCOMPLEX);
  r = (creal_T *)emlrtMxGetData(m);
  *r = u;
  emlrtFreeImagIfZero(m);
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

static uint32_T g_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *NewtonIts,
                                   const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  uint32_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(NewtonIts), &thisId);
  emlrtDestroyArray(&NewtonIts);
  return y;
}

static uint32_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId)
{
  uint32_T y;
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static uint32_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  uint32_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"uint32",
                          false, 0U, (void *)&dims);
  ret = *(uint32_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void SE_NEwtonCorrection_api(const mxArray *const prhs[8], int32_T nlhs,
                             const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_creal_T *gCoeffs;
  creal_T SEn0;
  creal_T SEn_n;
  creal_T SEx;
  creal_T nearby_SP;
  real_T NewtonThresh;
  real_T P;
  real_T step_size_adjust;
  uint32_T NewtonIts;
  boolean_T Newton_success;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_creal_T(&st, &gCoeffs, &e_emlrtRTEI);
  /* Marshall function inputs */
  P = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "P");
  SEn0 = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "SEn0");
  SEx = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "SEx");
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "gCoeffs", gCoeffs);
  NewtonThresh = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "NewtonThresh");
  NewtonIts = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "NewtonIts");
  nearby_SP = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "nearby_SP");
  step_size_adjust =
      emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "step_size_adjust");
  /* Invoke the target function */
  SE_NEwtonCorrection(&st, P, SEn0, SEx, gCoeffs, NewtonThresh, NewtonIts,
                      nearby_SP, step_size_adjust, &SEn_n, &Newton_success);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(SEn_n);
  emxFree_creal_T(&st, &gCoeffs);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(Newton_success);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_SE_NEwtonCorrection_api.c) */
