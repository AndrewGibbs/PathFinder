/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDpathODEuler_v2.h
 *
 * Code generation for function 'SDpathODEuler_v2'
 *
 */

#pragma once

/* Include files */
#include "SDpathODEuler_v2_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void SDpathODEuler_v2(const emlrtStack *sp, const creal_T h0,
                      const emxArray_creal_T *gCoeffs,
                      const emxArray_creal_T *SPs,
                      const emxArray_real_T *cover_radii,
                      const emxArray_creal_T *valleys, real_T base_step_size,
                      int64_T n_max, emxArray_real_T *p_log_out,
                      emxArray_creal_T *h_log_out, real_T valley_index_data[],
                      int32_T valley_index_size[2], real_T ball_index_data[],
                      int32_T ball_index_size[2], boolean_T *success);

/* End of code generation (SDpathODEuler_v2.h) */
