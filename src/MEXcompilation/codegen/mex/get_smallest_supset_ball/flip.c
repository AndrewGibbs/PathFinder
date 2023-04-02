/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * flip.c
 *
 * Code generation for function 'flip'
 *
 */

/* Include files */
#include "flip.h"
#include "get_smallest_supset_ball_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void flip(emxArray_creal_T *x)
{
  creal_T *x_data;
  real_T tmp_im;
  real_T tmp_re;
  int32_T b_i;
  int32_T dim;
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T nd2;
  int32_T tmp_re_tmp;
  int32_T vstride;
  x_data = x->data;
  dim = 2;
  if (x->size[0] != 1) {
    dim = 1;
  }
  if (x->size[0] != 0) {
    if (dim <= 1) {
      vstride = x->size[0];
    } else {
      vstride = 1;
    }
    if (vstride > 1) {
      vstride = 1;
      for (k = 0; k <= dim - 2; k++) {
        vstride *= x->size[0];
      }
      if (dim <= 1) {
        dim = x->size[0] - 1;
      } else {
        dim = 0;
      }
      nd2 = (dim + 1) >> 1;
      i = vstride - 1;
      for (b_i = 0; b_i <= i; b_i++) {
        for (k = 0; k < nd2; k++) {
          tmp_re_tmp = b_i + k * vstride;
          tmp_re = x_data[tmp_re_tmp].re;
          tmp_im = x_data[tmp_re_tmp].im;
          i1 = b_i + (dim - k) * vstride;
          x_data[tmp_re_tmp] = x_data[i1];
          x_data[i1].re = tmp_re;
          x_data[i1].im = tmp_im;
        }
      }
    }
  }
}

/* End of code generation (flip.c) */
