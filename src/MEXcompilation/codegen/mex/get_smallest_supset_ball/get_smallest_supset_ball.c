/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_smallest_supset_ball.c
 *
 * Code generation for function 'get_smallest_supset_ball'
 *
 */

/* Include files */
#include "get_smallest_supset_ball.h"
#include "eml_int_forloop_overflow_check.h"
#include "get_r_given_theta.h"
#include "get_smallest_supset_ball_data.h"
#include "get_smallest_supset_ball_emxutil.h"
#include "get_smallest_supset_ball_mexutil.h"
#include "get_smallest_supset_ball_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo
    emlrtRSI =
        {
            5,                          /* lineNo */
            "get_smallest_supset_ball", /* fcnName */
            "/home/andrew/OneDrive/PathFinder/src/covers/"
            "get_smallest_supset_ball.m" /* pathName */
};

static emlrtRSInfo
    b_emlrtRSI =
        {
            7,                          /* lineNo */
            "get_smallest_supset_ball", /* fcnName */
            "/home/andrew/OneDrive/PathFinder/src/covers/"
            "get_smallest_supset_ball.m" /* pathName */
};

static emlrtRSInfo
    c_emlrtRSI =
        {
            14,                         /* lineNo */
            "get_smallest_supset_ball", /* fcnName */
            "/home/andrew/OneDrive/PathFinder/src/covers/"
            "get_smallest_supset_ball.m" /* pathName */
};

static emlrtRSInfo
    d_emlrtRSI =
        {
            16,                         /* lineNo */
            "get_smallest_supset_ball", /* fcnName */
            "/home/andrew/OneDrive/PathFinder/src/covers/"
            "get_smallest_supset_ball.m" /* pathName */
};

static emlrtRSInfo
    e_emlrtRSI =
        {
            20,                         /* lineNo */
            "get_smallest_supset_ball", /* fcnName */
            "/home/andrew/OneDrive/PathFinder/src/covers/"
            "get_smallest_supset_ball.m" /* pathName */
};

static emlrtBCInfo emlrtBCI =
    {
        -1,                         /* iFirst */
        -1,                         /* iLast */
        8,                          /* lineNo */
        24,                         /* colNo */
        "radii",                    /* aName */
        "get_smallest_supset_ball", /* fName */
        "/home/andrew/OneDrive/PathFinder/src/covers/"
        "get_smallest_supset_ball.m", /* pName */
        0                             /* checkKind */
};

static emlrtDCInfo emlrtDCI =
    {
        3,                          /* lineNo */
        19,                         /* colNo */
        "get_smallest_supset_ball", /* fName */
        "/home/andrew/OneDrive/PathFinder/src/covers/"
        "get_smallest_supset_ball.m", /* pName */
        1                             /* checkKind */
};

static emlrtBCInfo b_emlrtBCI =
    {
        -1,                         /* iFirst */
        -1,                         /* iLast */
        7,                          /* lineNo */
        15,                         /* colNo */
        "radii",                    /* aName */
        "get_smallest_supset_ball", /* fName */
        "/home/andrew/OneDrive/PathFinder/src/covers/"
        "get_smallest_supset_ball.m", /* pName */
        0                             /* checkKind */
};

static emlrtBCInfo c_emlrtBCI =
    {
        -1,                         /* iFirst */
        -1,                         /* iLast */
        9,                          /* lineNo */
        19,                         /* colNo */
        "radii",                    /* aName */
        "get_smallest_supset_ball", /* fName */
        "/home/andrew/OneDrive/PathFinder/src/covers/"
        "get_smallest_supset_ball.m", /* pName */
        0                             /* checkKind */
};

static emlrtRTEInfo
    q_emlrtRTEI =
        {
            3,                          /* lineNo */
            13,                         /* colNo */
            "get_smallest_supset_ball", /* fName */
            "/home/andrew/OneDrive/PathFinder/src/covers/"
            "get_smallest_supset_ball.m" /* pName */
};

static emlrtRTEInfo
    r_emlrtRTEI =
        {
            3,                          /* lineNo */
            5,                          /* colNo */
            "get_smallest_supset_ball", /* fName */
            "/home/andrew/OneDrive/PathFinder/src/covers/"
            "get_smallest_supset_ball.m" /* pName */
};

/* Function Definitions */
real_T get_smallest_supset_ball(const emlrtStack *sp,
                                const emxArray_creal_T *g_coeffs, real_T freq,
                                const creal_T xi, real_T Cosc,
                                uint32_T num_rays, boolean_T take_max,
                                real_T imag_thresh)
{
  static const int32_T iv[2] = {1, 94};
  static const char_T u[94] = {
      'C',  'o', 'u', 'l', 'd', ' ',  'n', 'o', 't', ' ', 'd', 'e', 't', 'e',
      'r',  'm', 'i', 'n', 'e', ' ',  'r', 'a', 'd', 'i', 'u', 's', ' ', 'o',
      'f',  ' ', 'b', 'a', 'l', 'l',  ',', ' ', 't', 'r', 'y', ' ', 'i', 'n',
      'c',  'r', 'e', 'a', 's', 'i',  'n', 'g', ' ', 'p', 'a', 'r', 'a', 'm',
      'e',  't', 'e', 'r', ' ', '\'', 'n', 'u', 'm', ' ', 'r', 'a', 'y', 's',
      '\'', ',', ' ', '(', 'd', 'e',  'f', 'a', 'u', 'l', 't', ' ', 'v', 'a',
      'l',  'u', 'e', ' ', 'i', 's',  ' ', '1', '6', ')'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  emxArray_real_T *radii;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *propValues;
  const mxArray *y;
  real_T d_theta;
  real_T r;
  real_T *radii_data;
  int32_T a;
  int32_T idx;
  int32_T k;
  int32_T last;
  const char_T *propClasses = "coder.internal.string";
  const char_T *propNames = "Value";
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /* find the smallest ball containing the blob such that freq*|g(z)-g(\xi)|<C
   */
  if ((real_T)num_rays != (int32_T)num_rays) {
    emlrtIntegerCheckR2012b(num_rays, &emlrtDCI, (emlrtCTX)sp);
  }
  emxInit_real_T(sp, &radii, &r_emlrtRTEI);
  last = radii->size[0];
  radii->size[0] = (int32_T)num_rays;
  emxEnsureCapacity_real_T(sp, radii, last, &q_emlrtRTEI);
  radii_data = radii->data;
  d_theta = 6.2831853071795862 / (real_T)num_rays;
  st.site = &emlrtRSI;
  if ((1U <= num_rays) && (num_rays > 4294967294U)) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  last = (int32_T)num_rays;
  for (idx = 0; idx < last; idx++) {
    if (((int32_T)(idx + 1U) < 1) || ((int32_T)(idx + 1U) > radii->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(idx + 1U), 1, radii->size[0],
                                    &b_emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &b_emlrtRSI;
    radii_data[idx] =
        get_r_given_theta(&st, g_coeffs, xi, Cosc / freq,
                          d_theta * ((real_T)idx + 1.0), imag_thresh);
    if (((int32_T)(idx + 1U) < 1) || ((int32_T)(idx + 1U) > radii->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(idx + 1U), 1, radii->size[0],
                                    &emlrtBCI, (emlrtCTX)sp);
    }
    if (muDoubleScalarIsInf(radii_data[idx]) && take_max) {
      if (((int32_T)(idx + 1U) < 1) || ((int32_T)(idx + 1U) > radii->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(idx + 1U), 1, radii->size[0],
                                      &c_emlrtBCI, (emlrtCTX)sp);
      }
      radii_data[idx] = 0.0;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  if (take_max) {
    st.site = &c_emlrtRSI;
    b_st.site = &be_emlrtRSI;
    c_st.site = &ce_emlrtRSI;
    d_st.site = &de_emlrtRSI;
    if (radii->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }
    e_st.site = &ee_emlrtRSI;
    f_st.site = &fe_emlrtRSI;
    last = radii->size[0];
    if (radii->size[0] <= 2) {
      if (radii->size[0] == 1) {
        r = radii_data[0];
      } else if ((radii_data[0] < radii_data[1]) ||
                 (muDoubleScalarIsNaN(radii_data[0]) &&
                  (!muDoubleScalarIsNaN(radii_data[1])))) {
        r = radii_data[1];
      } else {
        r = radii_data[0];
      }
    } else {
      g_st.site = &he_emlrtRSI;
      if (!muDoubleScalarIsNaN(radii_data[0])) {
        idx = 1;
      } else {
        idx = 0;
        h_st.site = &ie_emlrtRSI;
        if (radii->size[0] > 2147483646) {
          i_st.site = &f_emlrtRSI;
          b_check_forloop_overflow_error(&i_st);
        }
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= last)) {
          if (!muDoubleScalarIsNaN(radii_data[k - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (idx == 0) {
        r = radii_data[0];
      } else {
        g_st.site = &ge_emlrtRSI;
        r = radii_data[idx - 1];
        a = idx + 1;
        h_st.site = &je_emlrtRSI;
        if ((idx + 1 <= radii->size[0]) && (radii->size[0] > 2147483646)) {
          i_st.site = &f_emlrtRSI;
          b_check_forloop_overflow_error(&i_st);
        }
        for (k = a; k <= last; k++) {
          d_theta = radii_data[k - 1];
          if (r < d_theta) {
            r = d_theta;
          }
        }
      }
    }
  } else {
    st.site = &d_emlrtRSI;
    b_st.site = &se_emlrtRSI;
    c_st.site = &te_emlrtRSI;
    d_st.site = &ue_emlrtRSI;
    if (radii->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }
    e_st.site = &ve_emlrtRSI;
    f_st.site = &we_emlrtRSI;
    last = radii->size[0];
    if (radii->size[0] <= 2) {
      if (radii->size[0] == 1) {
        r = radii_data[0];
      } else if ((radii_data[0] > radii_data[1]) ||
                 (muDoubleScalarIsNaN(radii_data[0]) &&
                  (!muDoubleScalarIsNaN(radii_data[1])))) {
        r = radii_data[1];
      } else {
        r = radii_data[0];
      }
    } else {
      g_st.site = &he_emlrtRSI;
      if (!muDoubleScalarIsNaN(radii_data[0])) {
        idx = 1;
      } else {
        idx = 0;
        h_st.site = &ie_emlrtRSI;
        if (radii->size[0] > 2147483646) {
          i_st.site = &f_emlrtRSI;
          b_check_forloop_overflow_error(&i_st);
        }
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= last)) {
          if (!muDoubleScalarIsNaN(radii_data[k - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (idx == 0) {
        r = radii_data[0];
      } else {
        g_st.site = &ge_emlrtRSI;
        r = radii_data[idx - 1];
        a = idx + 1;
        h_st.site = &je_emlrtRSI;
        if ((idx + 1 <= radii->size[0]) && (radii->size[0] > 2147483646)) {
          i_st.site = &f_emlrtRSI;
          b_check_forloop_overflow_error(&i_st);
        }
        for (k = a; k <= last; k++) {
          d_theta = radii_data[k - 1];
          if (r > d_theta) {
            r = d_theta;
          }
        }
      }
    }
  }
  emxFree_real_T(sp, &radii);
  if (muDoubleScalarIsInf(r) || (r == 0.0)) {
    st.site = &e_emlrtRSI;
    y = NULL;
    m = NULL;
    emlrtAssign(
        &y, emlrtCreateClassInstance((const char_T *)"coder.internal.string"));
    m = NULL;
    b_y = NULL;
    propValues = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(&st, 94, propValues, &u[0]);
    emlrtAssign(&b_y, propValues);
    emlrtAssign(&m, b_y);
    propValues = m;
    emlrtSetAllProperties(&st, &y, 0, 1, (const char_T **)&propNames,
                          (const char_T **)&propClasses, &propValues);
    emlrtAssign(&y, emlrtConvertInstanceToRedirectSource(
                        &st, y, 0, (const char_T *)"coder.internal.string"));
    b_st.site = &ye_emlrtRSI;
    b_error(&b_st, y, &c_emlrtMCI);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return r;
}

/* End of code generation (get_smallest_supset_ball.c) */
