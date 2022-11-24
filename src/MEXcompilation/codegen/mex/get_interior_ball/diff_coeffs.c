/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diff_coeffs.c
 *
 * Code generation for function 'diff_coeffs'
 *
 */

/* Include files */
#include "diff_coeffs.h"
#include "get_interior_ball_data.h"
#include "get_interior_ball_emxutil.h"
#include "get_interior_ball_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void times(const emlrtStack *sp, emxArray_creal_T *dG_,
           const emxArray_creal_T *d_coeffs, const emxArray_real_T *r1)
{
  const creal_T *d_coeffs_data;
  creal_T *dG__data;
  const real_T *r;
  real_T d;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  r = r1->data;
  d_coeffs_data = d_coeffs->data;
  i = dG_->size[0] * dG_->size[1];
  dG_->size[0] = 1;
  if (r1->size[1] == 1) {
    dG_->size[1] = d_coeffs->size[1];
  } else {
    dG_->size[1] = r1->size[1];
  }
  emxEnsureCapacity_creal_T(sp, dG_, i, &e_emlrtRTEI);
  dG__data = dG_->data;
  stride_0_1 = (d_coeffs->size[1] != 1);
  stride_1_1 = (r1->size[1] != 1);
  if (r1->size[1] == 1) {
    loop_ub = d_coeffs->size[1];
  } else {
    loop_ub = r1->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    d = r[i * stride_1_1];
    dG__data[i].re = d * d_coeffs_data[i * stride_0_1].re;
    dG__data[i].im = d * d_coeffs_data[i * stride_0_1].im;
  }
}

/* End of code generation (diff_coeffs.c) */
