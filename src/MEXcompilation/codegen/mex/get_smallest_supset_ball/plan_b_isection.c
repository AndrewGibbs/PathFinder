/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * plan_b_isection.c
 *
 * Code generation for function 'plan_b_isection'
 *
 */

/* Include files */
#include "plan_b_isection.h"
#include "eml_int_forloop_overflow_check.h"
#include "get_smallest_supset_ball_data.h"
#include "get_smallest_supset_ball_emxutil.h"
#include "get_smallest_supset_ball_mexutil.h"
#include "get_smallest_supset_ball_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo xd_emlrtRSI = {
    10,                /* lineNo */
    "plan_b_isection", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/plan_b_isection.m" /* pathName
                                                                          */
};

static emlrtRSInfo yd_emlrtRSI = {
    15,                /* lineNo */
    "plan_b_isection", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/plan_b_isection.m" /* pathName
                                                                          */
};

static emlrtRSInfo ae_emlrtRSI = {
    17,                /* lineNo */
    "plan_b_isection", /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/plan_b_isection.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    ke_emlrtRSI =
        {
            63,                               /* lineNo */
            "function_handle/parenReference", /* fcnName */
            "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/"
            "function_handle.m" /* pathName */
};

static emlrtRSInfo me_emlrtRSI = {
    16,                                                       /* lineNo */
    "bisection",                                              /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/covers/bisection.m" /* pathName */
};

static emlrtRSInfo ne_emlrtRSI = {
    19,                                                       /* lineNo */
    "bisection",                                              /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/covers/bisection.m" /* pathName */
};

static emlrtRSInfo oe_emlrtRSI = {
    24,                                                       /* lineNo */
    "bisection",                                              /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/covers/bisection.m" /* pathName */
};

static emlrtRSInfo pe_emlrtRSI = {
    35,                                                       /* lineNo */
    "bisection",                                              /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/covers/bisection.m" /* pathName */
};

static emlrtRSInfo qe_emlrtRSI = {
    37,                                                       /* lineNo */
    "bisection",                                              /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/covers/bisection.m" /* pathName */
};

static emlrtRSInfo re_emlrtRSI = {
    45,                                                       /* lineNo */
    "bisection",                                              /* fcnName */
    "/home/andrew/OneDrive/PathFinder/src/covers/bisection.m" /* pathName */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    15,                /* lineNo */
    22,                /* colNo */
    "guesses",         /* aName */
    "plan_b_isection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/plan_b_isection.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    17,                /* lineNo */
    41,                /* colNo */
    "guesses",         /* aName */
    "plan_b_isection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/plan_b_isection.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    17,                /* lineNo */
    55,                /* colNo */
    "guesses",         /* aName */
    "plan_b_isection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/plan_b_isection.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtRTEInfo ub_emlrtRTEI = {
    10,                /* lineNo */
    15,                /* colNo */
    "plan_b_isection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/plan_b_isection.m" /* pName
                                                                          */
};

static emlrtRTEInfo vb_emlrtRTEI = {
    10,                /* lineNo */
    5,                 /* colNo */
    "plan_b_isection", /* fName */
    "/home/andrew/OneDrive/PathFinder/src/rootFinding/plan_b_isection.m" /* pName
                                                                          */
};

/* Function Declarations */
static real_T
plan_b_isection_anonFcn2(const emxArray_creal_T *g_workspace_g_coeffs,
                         const creal_T xi, real_T theta, real_T C_over_omega,
                         real_T r);

/* Function Definitions */
static real_T
plan_b_isection_anonFcn2(const emxArray_creal_T *g_workspace_g_coeffs,
                         const creal_T xi, real_T theta, real_T C_over_omega,
                         real_T r)
{
  const creal_T *g_workspace_g_coeffs_data;
  real_T b_r;
  real_T b_y_re;
  real_T varargout_1_im;
  real_T varargout_1_re;
  real_T y_im;
  real_T y_re;
  int32_T i;
  int32_T k;
  g_workspace_g_coeffs_data = g_workspace_g_coeffs->data;
  y_re = theta * 0.0;
  if (theta == 0.0) {
    y_re = muDoubleScalarExp(y_re);
    y_im = 0.0;
  } else {
    b_r = muDoubleScalarExp(y_re / 2.0);
    y_re = b_r * (b_r * muDoubleScalarCos(theta));
    y_im = b_r * (b_r * muDoubleScalarSin(theta));
  }
  y_re = xi.re + r * y_re;
  y_im = xi.im + r * y_im;
  if (g_workspace_g_coeffs->size[0] != 0) {
    varargout_1_re = g_workspace_g_coeffs_data[0].re;
    varargout_1_im = g_workspace_g_coeffs_data[0].im;
    i = g_workspace_g_coeffs->size[0];
    for (k = 0; k <= i - 2; k++) {
      b_y_re = y_re * varargout_1_re - y_im * varargout_1_im;
      b_r = y_re * varargout_1_im + y_im * varargout_1_re;
      varargout_1_re = b_y_re + g_workspace_g_coeffs_data[k + 1].re;
      varargout_1_im = b_r + g_workspace_g_coeffs_data[k + 1].im;
    }
  }
  if (g_workspace_g_coeffs->size[0] != 0) {
    y_re = g_workspace_g_coeffs_data[0].re;
    y_im = g_workspace_g_coeffs_data[0].im;
    i = g_workspace_g_coeffs->size[0];
    for (k = 0; k <= i - 2; k++) {
      b_y_re = xi.re * y_re - xi.im * y_im;
      b_r = xi.re * y_im + xi.im * y_re;
      y_re = b_y_re + g_workspace_g_coeffs_data[k + 1].re;
      y_im = b_r + g_workspace_g_coeffs_data[k + 1].im;
    }
  }
  y_re = varargout_1_re - y_re;
  y_im = varargout_1_im - y_im;
  b_r = muDoubleScalarHypot(y_re, y_im);
  return b_r * b_r - C_over_omega * C_over_omega;
}

real_T plan_b_isection(const emlrtStack *sp, const emxArray_creal_T *g_coeffs,
                       const creal_T xi, real_T C_over_omega, real_T theta,
                       emxArray_real_T *guesses)
{
  static const int32_T iv[2] = {1, 16};
  static const char_T varargin_1[16] = {'f', 'a', 'i', 'l', 'e', 'd', ' ', 't',
                                        'o', ' ', 'b', 'i', 's', 'e', 'c', 't'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  emxArray_real_T *r;
  const mxArray *m;
  const mxArray *y;
  real_T b;
  real_T b_a;
  real_T c_err;
  real_T count;
  real_T d;
  real_T root;
  real_T varargout_1;
  real_T *guesses_data;
  real_T *r1;
  int32_T a;
  int32_T idx;
  int32_T k;
  int32_T last;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T guard1 = false;
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
  guesses_data = guesses->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*  bisection tolerance */
  /*  define the polynomial g */
  /*  and the 'polynomial' which we are seeking the root of */
  /*  note that G(0)<0 */
  /*  add a couple of extra extremities to the guesses, just incase */
  st.site = &xd_emlrtRSI;
  b_st.site = &be_emlrtRSI;
  c_st.site = &ce_emlrtRSI;
  d_st.site = &de_emlrtRSI;
  if (guesses->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &ee_emlrtRSI;
  f_st.site = &fe_emlrtRSI;
  last = guesses->size[0];
  if (guesses->size[0] <= 2) {
    if (guesses->size[0] == 1) {
      count = guesses_data[0];
    } else if ((guesses_data[0] < guesses_data[1]) ||
               (muDoubleScalarIsNaN(guesses_data[0]) &&
                (!muDoubleScalarIsNaN(guesses_data[1])))) {
      count = guesses_data[1];
    } else {
      count = guesses_data[0];
    }
  } else {
    g_st.site = &he_emlrtRSI;
    if (!muDoubleScalarIsNaN(guesses_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &ie_emlrtRSI;
      if (guesses->size[0] > 2147483646) {
        i_st.site = &f_emlrtRSI;
        b_check_forloop_overflow_error(&i_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!muDoubleScalarIsNaN(guesses_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      count = guesses_data[0];
    } else {
      g_st.site = &ge_emlrtRSI;
      count = guesses_data[idx - 1];
      a = idx + 1;
      h_st.site = &je_emlrtRSI;
      if ((idx + 1 <= guesses->size[0]) && (guesses->size[0] > 2147483646)) {
        i_st.site = &f_emlrtRSI;
        b_check_forloop_overflow_error(&i_st);
      }
      for (k = a; k <= last; k++) {
        d = guesses_data[k - 1];
        if (count < d) {
          count = d;
        }
      }
    }
  }
  emxInit_real_T(&f_st, &r, &ub_emlrtRTEI);
  idx = r->size[0];
  r->size[0] = guesses->size[0] + 2;
  emxEnsureCapacity_real_T(sp, r, idx, &ub_emlrtRTEI);
  r1 = r->data;
  r1[0] = 0.0;
  last = guesses->size[0];
  for (idx = 0; idx < last; idx++) {
    r1[idx + 1] = guesses_data[idx];
  }
  r1[guesses->size[0] + 1] = count * 2.0;
  idx = guesses->size[0];
  guesses->size[0] = r->size[0];
  emxEnsureCapacity_real_T(sp, guesses, idx, &vb_emlrtRTEI);
  guesses_data = guesses->data;
  last = r->size[0];
  for (idx = 0; idx < last; idx++) {
    guesses_data[idx] = r1[idx];
  }
  emxFree_real_T(sp, &r);
  root = rtInf;
  last = 0;
  exitg1 = false;
  while ((!exitg1) && (last <= guesses->size[0] - 2)) {
    st.site = &yd_emlrtRSI;
    if (last + 2 > guesses->size[0]) {
      emlrtDynamicBoundsCheckR2012b(last + 2, 1, guesses->size[0], &m_emlrtBCI,
                                    &st);
    }
    b_st.site = &ke_emlrtRSI;
    varargout_1 = plan_b_isection_anonFcn2(g_coeffs, xi, theta, C_over_omega,
                                           guesses_data[last + 1]);
    if (varargout_1 > 0.0) {
      /*  look for a sign change */
      st.site = &ae_emlrtRSI;
      if (last + 1 > guesses->size[0]) {
        emlrtDynamicBoundsCheckR2012b(last + 1, 1, guesses->size[0],
                                      &n_emlrtBCI, &st);
      }
      b_a = guesses_data[last];
      if (last + 2 > guesses->size[0]) {
        emlrtDynamicBoundsCheckR2012b(last + 2, 1, guesses->size[0],
                                      &o_emlrtBCI, &st);
      }
      b = guesses_data[last + 1];
      /*  L = abs(b-a); */
      /*  rayDir = (b-a)/L; */
      /*  ray = @(s) a + s*(b-a); */
      root = rtNaN;
      /* inside contour f is negative, outside contour f is positive */
      /*  err = @(a,b) min(abs(f(a)),abs(f(b))); */
      d = guesses_data[last + 1];
      c_err = muDoubleScalarAbs(d - guesses_data[last]);
      if (c_err <= 1.0E-8) {
        /*  take midpoint if no bisection is required */
        root = (d + guesses_data[last]) / 2.0;
      } else {
        b_st.site = &me_emlrtRSI;
        c_st.site = &ke_emlrtRSI;
        varargout_1 = plan_b_isection_anonFcn2(
            g_coeffs, xi, theta, C_over_omega, guesses_data[last]);
        if (varargout_1 == 0.0) {
          root = guesses_data[last];
        } else {
          b_st.site = &ne_emlrtRSI;
          c_st.site = &ke_emlrtRSI;
          varargout_1 = plan_b_isection_anonFcn2(
              g_coeffs, xi, theta, C_over_omega, guesses_data[last + 1]);
          if (varargout_1 == 0.0) {
            root = d;
          } else {
            b_st.site = &oe_emlrtRSI;
            c_st.site = &ke_emlrtRSI;
            varargout_1 = plan_b_isection_anonFcn2(
                g_coeffs, xi, theta, C_over_omega, guesses_data[last]);
            if (varargout_1 > 0.0) {
              /* f = @(x) -f(x); */
              last = -1;
            } else {
              last = 1;
            }
            count = 0.0;
            exitg2 = false;
            while ((!exitg2) && (c_err > 1.0E-8)) {
              root = b_a + (b - b_a) / 2.0;
              b_st.site = &pe_emlrtRSI;
              c_st.site = &ke_emlrtRSI;
              varargout_1 = plan_b_isection_anonFcn2(g_coeffs, xi, theta,
                                                     C_over_omega, root);
              guard1 = false;
              if ((real_T)last * varargout_1 > 0.0) {
                b = root;
                guard1 = true;
              } else {
                b_st.site = &qe_emlrtRSI;
                c_st.site = &ke_emlrtRSI;
                varargout_1 = plan_b_isection_anonFcn2(g_coeffs, xi, theta,
                                                       C_over_omega, root);
                if ((real_T)last * varargout_1 < 0.0) {
                  b_a = root;
                  guard1 = true;
                } else {
                  exitg2 = true;
                }
              }
              if (guard1) {
                c_err = muDoubleScalarAbs(b - b_a);
                count++;
                if (count > 1000.0) {
                  b_st.site = &re_emlrtRSI;
                  y = NULL;
                  m = emlrtCreateCharArray(2, &iv[0]);
                  emlrtInitCharArrayR2013a(&b_st, 16, m, &varargin_1[0]);
                  emlrtAssign(&y, m);
                  c_st.site = &ye_emlrtRSI;
                  b_error(&c_st, y, &c_emlrtMCI);
                }
                if (*emlrtBreakCheckR2012bFlagVar != 0) {
                  emlrtBreakCheckR2012b(&st);
                }
              }
            }
          }
        }
      }
      exitg1 = true;
    } else {
      last++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
  }
  /*      if ~found_a_root */
  /*          print('Warning - no roots found after bisection, treating radius
   * at this angle as inf'); */
  /*      end */
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return root;
}

/* End of code generation (plan_b_isection.c) */
