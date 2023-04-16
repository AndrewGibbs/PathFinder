/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eig.h
 *
 * Code generation for function 'eig'
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
void eig(const emlrtStack *sp, const emxArray_creal_T *A, emxArray_creal_T *V,
         emxArray_creal_T *D);

/* End of code generation (eig.h) */
