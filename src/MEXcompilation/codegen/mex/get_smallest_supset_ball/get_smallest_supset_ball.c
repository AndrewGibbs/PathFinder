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
            10,                         /* lineNo */
            "get_smallest_supset_ball", /* fcnName */
            "/home/andrew/OneDrive/PathFinder/src/covers/"
            "get_smallest_supset_ball.m" /* pathName */
};

static emlrtRSInfo
    d_emlrtRSI =
        {
            12,                         /* lineNo */
            "get_smallest_supset_ball", /* fcnName */
            "/home/andrew/OneDrive/PathFinder/src/covers/"
            "get_smallest_supset_ball.m" /* pathName */
};

static emlrtRSInfo ed_emlrtRSI = {
    15,                                                        /* lineNo */
    "max",                                                     /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/datafun/max.m" /* pathName */
};

static emlrtRSInfo fd_emlrtRSI = {
    44,         /* lineNo */
    "minOrMax", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                       */
};

static emlrtRSInfo gd_emlrtRSI = {
    79,        /* lineNo */
    "maximum", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                       */
};

static emlrtRSInfo hd_emlrtRSI = {
    186,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m" /* pathName
                                                                            */
};

static emlrtRSInfo id_emlrtRSI = {
    897,                    /* lineNo */
    "maxRealVectorOmitNaN", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m" /* pathName
                                                                            */
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

static emlrtBCInfo emlrtBCI =
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
                                uint32_T num_rays, boolean_T take_max)
{
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
  real_T d_theta;
  real_T r;
  real_T *radii_data;
  int32_T a;
  int32_T idx;
  int32_T k;
  int32_T last;
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
    b_st.site = &e_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  last = (int32_T)num_rays;
  for (idx = 0; idx < last; idx++) {
    if (((int32_T)(idx + 1U) < 1) || ((int32_T)(idx + 1U) > radii->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(idx + 1U), 1, radii->size[0],
                                    &emlrtBCI, (emlrtCTX)sp);
    }
    st.site = &b_emlrtRSI;
    radii_data[idx] = get_r_given_theta(&st, g_coeffs, xi, Cosc / freq,
                                        d_theta * ((real_T)idx + 1.0));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  if (take_max) {
    st.site = &c_emlrtRSI;
    b_st.site = &ed_emlrtRSI;
    c_st.site = &fd_emlrtRSI;
    d_st.site = &gd_emlrtRSI;
    if (radii->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }
    e_st.site = &hd_emlrtRSI;
    f_st.site = &id_emlrtRSI;
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
      g_st.site = &bd_emlrtRSI;
      if (!muDoubleScalarIsNaN(radii_data[0])) {
        idx = 1;
      } else {
        idx = 0;
        h_st.site = &cd_emlrtRSI;
        if (radii->size[0] > 2147483646) {
          i_st.site = &e_emlrtRSI;
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
        g_st.site = &ad_emlrtRSI;
        r = radii_data[idx - 1];
        a = idx + 1;
        h_st.site = &dd_emlrtRSI;
        if ((idx + 1 <= radii->size[0]) && (radii->size[0] > 2147483646)) {
          i_st.site = &e_emlrtRSI;
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
    b_st.site = &uc_emlrtRSI;
    c_st.site = &vc_emlrtRSI;
    d_st.site = &wc_emlrtRSI;
    if (radii->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }
    e_st.site = &xc_emlrtRSI;
    f_st.site = &yc_emlrtRSI;
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
      g_st.site = &bd_emlrtRSI;
      if (!muDoubleScalarIsNaN(radii_data[0])) {
        idx = 1;
      } else {
        idx = 0;
        h_st.site = &cd_emlrtRSI;
        if (radii->size[0] > 2147483646) {
          i_st.site = &e_emlrtRSI;
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
        g_st.site = &ad_emlrtRSI;
        r = radii_data[idx - 1];
        a = idx + 1;
        h_st.site = &dd_emlrtRSI;
        if ((idx + 1 <= radii->size[0]) && (radii->size[0] > 2147483646)) {
          i_st.site = &e_emlrtRSI;
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
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return r;
}

/* End of code generation (get_smallest_supset_ball.c) */
