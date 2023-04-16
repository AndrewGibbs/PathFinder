/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDpathODEuler_v4.h
 *
 * Code generation for function 'SDpathODEuler_v4'
 *
 */

#pragma once

/* Include files */
#include "SDpathODEuler_v4_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void SDpathODEuler_v4(
    const emlrtStack *sp, const creal_T h0, const emxArray_creal_T *gCoeffs,
    const emxArray_creal_T *SPs, const emxArray_real_T *cover_radii,
    const emxArray_creal_T *valleys, real_T base_step_size, int64_T n_max,
    real_T r_star, real_T Newton_small_threshold, real_T Newton_big_threshold,
    emxArray_real_T *p_log_out, emxArray_creal_T *h_log_out);

/* End of code generation (SDpathODEuler_v4.h) */
