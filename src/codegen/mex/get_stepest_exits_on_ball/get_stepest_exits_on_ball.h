/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_stepest_exits_on_ball.h
 *
 * Code generation for function 'get_stepest_exits_on_ball'
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
void get_stepest_exits_on_ball(const emlrtStack *sp,
                               const emxArray_creal_T *g_coeffs,
                               const creal_T centre, real_T radius,
                               emxArray_creal_T *SEs);

/* End of code generation (get_stepest_exits_on_ball.h) */
