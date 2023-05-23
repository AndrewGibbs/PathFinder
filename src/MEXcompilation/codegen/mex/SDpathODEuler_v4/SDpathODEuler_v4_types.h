/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDpathODEuler_v4_types.h
 *
 * Code generation for function 'SDpathODEuler_v4'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T
typedef struct {
  creal_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_creal_T;
#endif /* typedef_emxArray_creal_T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef struct_emxArray_int64_T
#define struct_emxArray_int64_T
struct emxArray_int64_T {
  int64_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int64_T */
#ifndef typedef_emxArray_int64_T
#define typedef_emxArray_int64_T
typedef struct emxArray_int64_T emxArray_int64_T;
#endif /* typedef_emxArray_int64_T */

#ifndef typedef_c_captured_var
#define typedef_c_captured_var
typedef struct {
  emxArray_creal_T *contents;
} c_captured_var;
#endif /* typedef_c_captured_var */

#ifndef typedef_d_captured_var
#define typedef_d_captured_var
typedef struct {
  emxArray_real_T *contents;
} d_captured_var;
#endif /* typedef_d_captured_var */

/* End of code generation (SDpathODEuler_v4_types.h) */
