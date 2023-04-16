/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * inAball.c
 *
 * Code generation for function 'inAball'
 *
 */

/* Include files */
#include "inAball.h"
#include "SDpathODEuler_v3_data.h"
#include "SDpathODEuler_v3_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
void b_inAball(const emlrtStack *sp, const creal_T h,
               const emxArray_creal_T *cover_centres,
               const emxArray_real_T *cover_radii, boolean_T *value,
               real_T *output_index)
{
  const creal_T *cover_centres_data;
  const real_T *cover_radii_data;
  int32_T b_index;
  boolean_T exitg1;
  cover_radii_data = cover_radii->data;
  cover_centres_data = cover_centres->data;
  /* returns 1 if SD path is in a ball, 0 otherwise */
  *value = false;
  *output_index = 0.0;
  b_index = 0;
  exitg1 = false;
  while ((!exitg1) && (b_index <= cover_centres->size[0] - 1)) {
    if (b_index + 1 > cover_centres->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_index + 1, 1, cover_centres->size[0],
                                    &y_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_index + 1 > cover_radii->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_index + 1, 1, cover_radii->size[0],
                                    &ab_emlrtBCI, (emlrtCTX)sp);
    }
    if (muDoubleScalarHypot(h.re - cover_centres_data[b_index].re,
                            h.im - cover_centres_data[b_index].im) <
        cover_radii_data[b_index]) {
      *value = true;
      *output_index = (real_T)b_index + 1.0;
      exitg1 = true;
    } else {
      b_index++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
  }
}

boolean_T inAball(const emlrtStack *sp, const creal_T h,
                  const emxArray_creal_T *cover_centres,
                  const emxArray_real_T *cover_radii)
{
  const creal_T *cover_centres_data;
  const real_T *cover_radii_data;
  int32_T b_index;
  boolean_T exitg1;
  boolean_T value;
  cover_radii_data = cover_radii->data;
  cover_centres_data = cover_centres->data;
  /* returns 1 if SD path is in a ball, 0 otherwise */
  value = false;
  b_index = 1;
  exitg1 = false;
  while ((!exitg1) && (b_index - 1 <= cover_centres->size[0] - 1)) {
    if ((b_index < 1) || (b_index > cover_centres->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_index, 1, cover_centres->size[0],
                                    &y_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_index > cover_centres->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_index, 1, cover_centres->size[0],
                                    &y_emlrtBCI, (emlrtCTX)sp);
    }
    if (b_index > cover_radii->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_index, 1, cover_radii->size[0],
                                    &ab_emlrtBCI, (emlrtCTX)sp);
    }
    if (muDoubleScalarHypot(h.re - cover_centres_data[b_index - 1].re,
                            h.im - cover_centres_data[b_index - 1].im) <
        cover_radii_data[b_index - 1]) {
      value = true;
      exitg1 = true;
    } else {
      b_index++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
  }
  return value;
}

/* End of code generation (inAball.c) */
