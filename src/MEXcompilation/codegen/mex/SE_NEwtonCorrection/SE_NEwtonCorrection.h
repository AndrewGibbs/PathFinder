/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SE_NEwtonCorrection.h
 *
 * Code generation for function 'SE_NEwtonCorrection'
 *
 */

#pragma once

/* Include files */
#include "SE_NEwtonCorrection_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void SE_NEwtonCorrection(const emlrtStack *sp, real_T P, const creal_T SEn0,
                         const creal_T SEx, const emxArray_creal_T *gCoeffs,
                         real_T NewtonThresh, uint32_T NewtonIts,
                         const creal_T nearby_SP, real_T step_size_adjust,
                         creal_T *SEn_n, boolean_T *Newton_success);

/* End of code generation (SE_NEwtonCorrection.h) */
