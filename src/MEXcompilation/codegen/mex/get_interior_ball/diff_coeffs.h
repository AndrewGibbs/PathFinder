/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diff_coeffs.h
 *
 * Code generation for function 'diff_coeffs'
 *
 */

#pragma once

/* Include files */
#include "get_interior_ball_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void times(const emlrtStack *sp, emxArray_creal_T *dG_,
           const emxArray_creal_T *d_coeffs, const emxArray_real_T *r1);

/* End of code generation (diff_coeffs.h) */
