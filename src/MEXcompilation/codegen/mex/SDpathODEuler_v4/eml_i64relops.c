/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_i64relops.c
 *
 * Code generation for function 'eml_i64relops'
 *
 */

/* Include files */
#include "eml_i64relops.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
boolean_T eml_i64relops(real_T a, int64_T b)
{
  boolean_T alarge;
  boolean_T blarge;
  boolean_T p;
  p = false;
  if (a < 9.2233720368547758E+18) {
    alarge = (a >= 4.503599627370496E+15);
    blarge = (b >= 4503599627370496L);
    if ((!alarge) && blarge) {
      p = true;
    } else if (blarge) {
      p = ((int64_T)muDoubleScalarRound(a) < b);
    } else if ((!alarge) && (b > -4503599627370496L)) {
      p = (a < b);
    }
  }
  return p;
}

/* End of code generation (eml_i64relops.c) */
