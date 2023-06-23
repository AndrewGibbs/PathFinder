/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * plan_b_isection.h
 *
 * Code generation for function 'plan_b_isection'
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
real_T plan_b_isection(const emlrtStack *sp, const emxArray_creal_T *g_coeffs,
                       const creal_T xi, real_T C_over_omega, real_T theta,
                       emxArray_real_T *guesses);

/* End of code generation (plan_b_isection.h) */
