/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDpathODEuler_extend_coarse_path.h
 *
 * Code generation for function 'SDpathODEuler_extend_coarse_path'
 *
 */

#pragma once

/* Include files */
#include "SDpathODEuler_extend_coarse_path_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void SDpathODEuler_extend_coarse_path(
    const emlrtStack *sp, const emxArray_real_T *p_init,
    const emxArray_creal_T *h_init, const emxArray_creal_T *gCoeffs,
    const emxArray_creal_T *SPs, real_T base_step_size, int64_T n_max,
    real_T P_new_max, emxArray_real_T *p_log_out, emxArray_creal_T *h_log_out,
    boolean_T *success);

/* End of code generation (SDpathODEuler_extend_coarse_path.h) */
