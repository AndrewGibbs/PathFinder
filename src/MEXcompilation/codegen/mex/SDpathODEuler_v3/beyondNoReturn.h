/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * beyondNoReturn.h
 *
 * Code generation for function 'beyondNoReturn'
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
void beyondNoReturn(const emlrtStack *sp, const creal_T h, real_T Cnr,
                    real_T argBeta, const emxArray_creal_T *V, boolean_T *value,
                    real_T *v_index);

/* End of code generation (beyondNoReturn.h) */
