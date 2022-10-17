/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDpathODEuler_emxutil.h
 *
 * Code generation for function 'SDpathODEuler_emxutil'
 *
 */

#pragma once

/* Include files */
#include "SDpathODEuler_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void emxEnsureCapacity_creal_T(const emlrtStack *sp, emxArray_creal_T *emxArray,
                               int32_T oldNumel,
                               const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
                              int32_T oldNumel,
                              const emlrtRTEInfo *srcLocation);

void emxFree_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray);

void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

void emxInit_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray,
                     int32_T numDimensions, const emlrtRTEInfo *srcLocation);

void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                    int32_T numDimensions, const emlrtRTEInfo *srcLocation);

/* End of code generation (SDpathODEuler_emxutil.h) */
