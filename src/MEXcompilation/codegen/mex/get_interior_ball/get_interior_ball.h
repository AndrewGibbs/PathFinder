/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_interior_ball.h
 *
 * Code generation for function 'get_interior_ball'
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
real_T get_interior_ball(const emlrtStack *sp, const emxArray_creal_T *g_coeffs,
                         real_T freq, const creal_T SP, uint32_T order,
                         real_T C);

/* End of code generation (get_interior_ball.h) */
