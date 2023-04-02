/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_smallest_supset_ball.h
 *
 * Code generation for function 'get_smallest_supset_ball'
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
real_T get_smallest_supset_ball(const emlrtStack *sp,
                                const emxArray_creal_T *g_coeffs, real_T freq,
                                const creal_T xi, real_T Cosc);

/* End of code generation (get_smallest_supset_ball.h) */
