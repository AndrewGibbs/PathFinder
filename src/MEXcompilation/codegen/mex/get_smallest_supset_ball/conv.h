/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * conv.h
 *
 * Code generation for function 'conv'
 *
 */

#pragma once

/* Include files */
#include "get_smallest_supset_ball_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void conv(const emlrtStack *sp, const emxArray_creal_T *A,
          const emxArray_creal_T *B, emxArray_creal_T *C);

/* End of code generation (conv.h) */
