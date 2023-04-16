/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * getNoReturnConstant.c
 *
 * Code generation for function 'getNoReturnConstant'
 *
 */

/* Include files */
#include "getNoReturnConstant.h"
#include "SDpathODEuler_v3_data.h"
#include "SDpathODEuler_v3_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtBCInfo u_emlrtBCI = {
    -1,                    /* iFirst */
    -1,                    /* iLast */
    9,                     /* lineNo */
    27,                    /* colNo */
    "coeffs",              /* aName */
    "getNoReturnConstant", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/getNoReturnConstant.m", /* pName
                                                                            */
    0 /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,                    /* iFirst */
    -1,                    /* iLast */
    7,                     /* lineNo */
    30,                    /* colNo */
    "coeffs",              /* aName */
    "getNoReturnConstant", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/contours/getNoReturnConstant.m", /* pName
                                                                            */
    0 /* checkKind */
};

/* Function Definitions */
real_T getNoReturnConstant(const emlrtStack *sp, const emxArray_creal_T *coeffs)
{
  const creal_T *coeffs_data;
  real_T C;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T j;
  coeffs_data = coeffs->data;
  /*  computes the constant which determines how large / narrow the SD path */
  /*  must be before it cannot leave the complex segment */
  C = 0.0;
  i = coeffs->size[1];
  for (j = 0; j <= i - 3; j++) {
    i1 = (coeffs->size[1] - j) - 1;
    if ((i1 < 1) || (i1 > coeffs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, coeffs->size[1], &v_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i2 = (coeffs->size[1] - j) - 1;
    if ((i2 < 1) || (i2 > coeffs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, coeffs->size[1], &v_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    C += muDoubleScalarHypot(((real_T)j + 1.0) * coeffs_data[i1 - 1].re,
                             ((real_T)j + 1.0) * coeffs_data[i2 - 1].im);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  if (1 > coeffs->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, coeffs->size[1], &u_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  C /= ((real_T)coeffs->size[1] - 1.0) *
       muDoubleScalarHypot(coeffs_data[0].re, coeffs_data[0].im);
  /*  C =
   * norm(sum(fliplr(1:(deg-1)).*abs(coeffs(1:(deg-1))))/(deg*abs(coeffs(1))));
   */
  return C;
}

/* End of code generation (getNoReturnConstant.c) */
