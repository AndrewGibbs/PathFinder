/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_r_given_theta.h
 *
 * Code generation for function 'get_r_given_theta'
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
real_T get_r_given_theta(const emlrtStack *sp, const emxArray_creal_T *g_coeffs,
                         const creal_T xi, real_T C_over_omega, real_T theta);

/* End of code generation (get_r_given_theta.h) */
