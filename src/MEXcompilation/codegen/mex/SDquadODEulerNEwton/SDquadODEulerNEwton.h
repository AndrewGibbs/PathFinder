/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDquadODEulerNEwton.h
 *
 * Code generation for function 'SDquadODEulerNEwton'
 *
 */

#pragma once

/* Include files */
#include "SDquadODEulerNEwton_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void SDquadODEulerNEwton(const emlrtStack *sp, const emxArray_real_T *p_quad,
                         const creal_T h0, const emxArray_creal_T *gCoeffs,
                         real_T freq, emxArray_creal_T *h_quad,
                         emxArray_creal_T *dhdp_quad,
                         emxArray_real_T *Newton_success);

/* End of code generation (SDquadODEulerNEwton.h) */
