/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sumMatrixIncludeNaN.h
 *
 * Code generation for function 'sumMatrixIncludeNaN'
 *
 */

#pragma once

/* Include files */
#include "get_stepest_exits_on_ball_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
creal_T b_sumColumnB(const emlrtStack *sp, const emxArray_creal_T *x,
                     int32_T vlen, int32_T vstart);

creal_T sumColumnB(const emlrtStack *sp, const emxArray_creal_T *x,
                   int32_T vlen);

creal_T sumColumnB4(const emxArray_creal_T *x, int32_T vstart);

/* End of code generation (sumMatrixIncludeNaN.h) */
