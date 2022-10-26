/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * polyval.c
 *
 * Code generation for function 'polyval'
 *
 */

/* Include files */
#include "polyval.h"
#include "get_interior_ball_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
creal_T polyval(const emxArray_creal_T *p, const creal_T x)
{
  const creal_T *p_data;
  creal_T y;
  real_T x_im;
  real_T x_re;
  int32_T i;
  int32_T k;
  p_data = p->data;
  if (p->size[0] != 0) {
    y = p_data[0];
    i = p->size[0];
    for (k = 0; k <= i - 2; k++) {
      x_re = x.re * y.re - x.im * y.im;
      x_im = x.re * y.im + x.im * y.re;
      y.re = x_re + p_data[k + 1].re;
      y.im = x_im + p_data[k + 1].im;
    }
  }
  return y;
}

/* End of code generation (polyval.c) */
