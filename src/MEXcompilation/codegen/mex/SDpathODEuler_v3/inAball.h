/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * inAball.h
 *
 * Code generation for function 'inAball'
 *
 */

#pragma once

/* Include files */
#include "SDpathODEuler_v3_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_inAball(const emlrtStack *sp, const creal_T h,
               const emxArray_creal_T *cover_centres,
               const emxArray_real_T *cover_radii, boolean_T *value,
               real_T *output_index);

boolean_T inAball(const emlrtStack *sp, const creal_T h,
                  const emxArray_creal_T *cover_centres,
                  const emxArray_real_T *cover_radii);

/* End of code generation (inAball.h) */
