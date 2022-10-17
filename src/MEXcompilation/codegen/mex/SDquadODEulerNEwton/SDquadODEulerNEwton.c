/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDquadODEulerNEwton.c
 *
 * Code generation for function 'SDquadODEulerNEwton'
 *
 */

/* Include files */
#include "SDquadODEulerNEwton.h"
#include "SDquadODEulerNEwton_data.h"
#include "SDquadODEulerNEwton_emxutil.h"
#include "SDquadODEulerNEwton_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtBCInfo
    emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            32,                    /* lineNo */
            86,                    /* colNo */
            "h_quad",              /* aName */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m", /* pName */
            0                        /* checkKind */
};

static emlrtBCInfo
    b_emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            32,                    /* lineNo */
            53,                    /* colNo */
            "p_quad",              /* aName */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m", /* pName */
            0                        /* checkKind */
};

static emlrtBCInfo
    c_emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            31,                    /* lineNo */
            138,                   /* colNo */
            "h_quad",              /* aName */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m", /* pName */
            0                        /* checkKind */
};

static emlrtBCInfo
    d_emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            31,                    /* lineNo */
            103,                   /* colNo */
            "h_quad",              /* aName */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m", /* pName */
            0                        /* checkKind */
};

static emlrtBCInfo
    e_emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            31,                    /* lineNo */
            70,                    /* colNo */
            "p_quad",              /* aName */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m", /* pName */
            0                        /* checkKind */
};

static emlrtBCInfo
    f_emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            26,                    /* lineNo */
            72,                    /* colNo */
            "h_quad",              /* aName */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m", /* pName */
            0                        /* checkKind */
};

static emlrtBCInfo
    g_emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            26,                    /* lineNo */
            57,                    /* colNo */
            "p_quad",              /* aName */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m", /* pName */
            0                        /* checkKind */
};

static emlrtBCInfo
    h_emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            26,                    /* lineNo */
            47,                    /* colNo */
            "p_quad",              /* aName */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m", /* pName */
            0                        /* checkKind */
};

static emlrtBCInfo
    i_emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            24,                    /* lineNo */
            20,                    /* colNo */
            "h_quad",              /* aName */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m", /* pName */
            0                        /* checkKind */
};

static emlrtBCInfo
    j_emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            24,                    /* lineNo */
            37,                    /* colNo */
            "p_quad",              /* aName */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m", /* pName */
            0                        /* checkKind */
};

static emlrtECInfo
    emlrtECI =
        {
            2,                     /* nDims */
            10,                    /* lineNo */
            17,                    /* colNo */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m" /* pName */
};

static emlrtBCInfo
    k_emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            10,                    /* lineNo */
            29,                    /* colNo */
            "dgCoeffs",            /* aName */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m", /* pName */
            0                        /* checkKind */
};

static emlrtBCInfo
    l_emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            10,                    /* lineNo */
            26,                    /* colNo */
            "dgCoeffs",            /* aName */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m", /* pName */
            0                        /* checkKind */
};

static emlrtECInfo
    b_emlrtECI =
        {
            2,                     /* nDims */
            9,                     /* lineNo */
            16,                    /* colNo */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m" /* pName */
};

static emlrtBCInfo
    m_emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            9,                     /* lineNo */
            27,                    /* colNo */
            "gCoeffs",             /* aName */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m", /* pName */
            0                        /* checkKind */
};

static emlrtBCInfo
    n_emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            9,                     /* lineNo */
            24,                    /* colNo */
            "gCoeffs",             /* aName */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m", /* pName */
            0                        /* checkKind */
};

static emlrtBCInfo
    o_emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            26,                    /* lineNo */
            32,                    /* colNo */
            "h_quad",              /* aName */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m", /* pName */
            0                        /* checkKind */
};

static emlrtBCInfo
    p_emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            26,                    /* lineNo */
            20,                    /* colNo */
            "h_quad",              /* aName */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m", /* pName */
            0                        /* checkKind */
};

static emlrtBCInfo
    q_emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            40,                    /* lineNo */
            24,                    /* colNo */
            "Newton_success",      /* aName */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m", /* pName */
            0                        /* checkKind */
};

static emlrtBCInfo
    r_emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            31,                    /* lineNo */
            32,                    /* colNo */
            "h_quad",              /* aName */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m", /* pName */
            0                        /* checkKind */
};

static emlrtBCInfo
    s_emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            31,                    /* lineNo */
            20,                    /* colNo */
            "h_quad",              /* aName */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m", /* pName */
            0                        /* checkKind */
};

static emlrtRTEInfo
    emlrtRTEI =
        {
            5,                     /* lineNo */
            5,                     /* colNo */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m" /* pName */
};

static emlrtRTEInfo
    b_emlrtRTEI =
        {
            9,                     /* lineNo */
            37,                    /* colNo */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m" /* pName */
};

static emlrtRTEInfo
    c_emlrtRTEI =
        {
            9,                     /* lineNo */
            5,                     /* colNo */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m" /* pName */
};

static emlrtRTEInfo
    d_emlrtRTEI =
        {
            19,                    /* lineNo */
            5,                     /* colNo */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    33,                                                            /* lineNo */
    20,                                                            /* colNo */
    "polyval",                                                     /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/polyfun/polyval.m" /* pName */
};

static emlrtRTEInfo
    f_emlrtRTEI =
        {
            11,                    /* lineNo */
            19,                    /* colNo */
            "SDquadODEulerNEwton", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    117,                                                     /* lineNo */
    9,                                                       /* colNo */
    "colon",                                                 /* fName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/ops/colon.m" /* pName */
};

static emlrtRSInfo
    emlrtRSI =
        {
            9,                     /* lineNo */
            "SDquadODEulerNEwton", /* fcnName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SDquadODEulerNEwton.m" /* pathName */
};

/* Function Declarations */
static void binary_expand_op(const emlrtStack *sp, emxArray_creal_T *dgCoeffs,
                             const emxArray_creal_T *gCoeffs, int32_T i1,
                             const emxArray_real_T *r1);

/* Function Definitions */
static void binary_expand_op(const emlrtStack *sp, emxArray_creal_T *dgCoeffs,
                             const emxArray_creal_T *gCoeffs, int32_T i1,
                             const emxArray_real_T *r1)
{
  const creal_T *gCoeffs_data;
  creal_T *dgCoeffs_data;
  const real_T *r;
  real_T d;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  r = r1->data;
  gCoeffs_data = gCoeffs->data;
  i = dgCoeffs->size[0] * dgCoeffs->size[1];
  dgCoeffs->size[0] = 1;
  if (r1->size[1] == 1) {
    dgCoeffs->size[1] = i1 + 1;
  } else {
    dgCoeffs->size[1] = r1->size[1];
  }
  emxEnsureCapacity_creal_T(sp, dgCoeffs, i, &c_emlrtRTEI);
  dgCoeffs_data = dgCoeffs->data;
  stride_0_1 = (i1 + 1 != 1);
  stride_1_1 = (r1->size[1] != 1);
  if (r1->size[1] == 1) {
    loop_ub = i1 + 1;
  } else {
    loop_ub = r1->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    d = r[i * stride_1_1];
    dgCoeffs_data[i].re = d * gCoeffs_data[i * stride_0_1].re;
    dgCoeffs_data[i].im = d * gCoeffs_data[i * stride_0_1].im;
  }
}

void SDquadODEulerNEwton(const emlrtStack *sp, const emxArray_real_T *p_quad,
                         const creal_T h0, const emxArray_creal_T *gCoeffs,
                         real_T freq, emxArray_creal_T *h_quad,
                         emxArray_creal_T *dhdp_quad,
                         emxArray_real_T *Newton_success)
{
  emlrtStack st;
  emxArray_creal_T *dgCoeffs;
  emxArray_real_T *r;
  const creal_T *gCoeffs_data;
  creal_T *dgCoeffs_data;
  creal_T *dhdp_quad_data;
  creal_T *h_quad_data;
  const real_T *p_quad_data;
  real_T ar;
  real_T b_b_re;
  real_T b_h_quad_re_tmp;
  real_T b_im;
  real_T b_re;
  real_T brm;
  real_T freq_times_g_at_se_im;
  real_T freq_times_g_at_se_re;
  real_T h0_im;
  real_T h0_re;
  real_T h_quad_re_tmp;
  real_T n;
  real_T *Newton_success_data;
  real_T *r1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T loop_ub;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  gCoeffs_data = gCoeffs->data;
  p_quad_data = p_quad->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  i = Newton_success->size[0];
  Newton_success->size[0] = p_quad->size[0];
  emxEnsureCapacity_real_T(sp, Newton_success, i, &emlrtRTEI);
  Newton_success_data = Newton_success->data;
  loop_ub = p_quad->size[0];
  for (i = 0; i < loop_ub; i++) {
    Newton_success_data[i] = 1.0;
  }
  /* ODE for path of steepest descent, make seperate file for this: */
  if (1 > gCoeffs->size[1] - 1) {
    loop_ub = 0;
  } else {
    if (1 > gCoeffs->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, gCoeffs->size[1], &n_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if ((gCoeffs->size[1] - 1 < 1) ||
        (gCoeffs->size[1] - 1 > gCoeffs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(gCoeffs->size[1] - 1, 1, gCoeffs->size[1],
                                    &m_emlrtBCI, (emlrtCTX)sp);
    }
    loop_ub = gCoeffs->size[1] - 1;
  }
  emxInit_real_T(sp, &r, 2, &g_emlrtRTEI);
  r1 = r->data;
  if (gCoeffs->size[1] - 1 < 1) {
    r->size[0] = 1;
    r->size[1] = 0;
  } else {
    i = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = (int32_T) - (1.0 - ((real_T)gCoeffs->size[1] - 1.0)) + 1;
    emxEnsureCapacity_real_T(sp, r, i, &b_emlrtRTEI);
    r1 = r->data;
    b_loop_ub = (int32_T) - (1.0 - ((real_T)gCoeffs->size[1] - 1.0));
    for (i = 0; i <= b_loop_ub; i++) {
      r1[i] = ((real_T)gCoeffs->size[1] - 1.0) - (real_T)i;
    }
  }
  if ((loop_ub != r->size[1]) && ((loop_ub != 1) && (r->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(loop_ub, r->size[1], &b_emlrtECI, (emlrtCTX)sp);
  }
  emxInit_creal_T(sp, &dgCoeffs, 2, &c_emlrtRTEI);
  if (loop_ub == r->size[1]) {
    i = dgCoeffs->size[0] * dgCoeffs->size[1];
    dgCoeffs->size[0] = 1;
    dgCoeffs->size[1] = loop_ub;
    emxEnsureCapacity_creal_T(sp, dgCoeffs, i, &c_emlrtRTEI);
    dgCoeffs_data = dgCoeffs->data;
    for (i = 0; i < loop_ub; i++) {
      dgCoeffs_data[i].re = r1[i] * gCoeffs_data[i].re;
      dgCoeffs_data[i].im = r1[i] * gCoeffs_data[i].im;
    }
  } else {
    st.site = &emlrtRSI;
    binary_expand_op(&st, dgCoeffs, gCoeffs, loop_ub - 1, r);
    dgCoeffs_data = dgCoeffs->data;
  }
  emxFree_real_T(sp, &r);
  if (1 > dgCoeffs->size[1] - 1) {
    i = 0;
  } else {
    if (1 > dgCoeffs->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, dgCoeffs->size[1], &l_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if ((dgCoeffs->size[1] - 1 < 1) ||
        (dgCoeffs->size[1] - 1 > dgCoeffs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(dgCoeffs->size[1] - 1, 1, dgCoeffs->size[1],
                                    &k_emlrtBCI, (emlrtCTX)sp);
    }
    i = dgCoeffs->size[1] - 1;
  }
  if (gCoeffs->size[1] - 2 < 1) {
    b_loop_ub = 0;
  } else {
    b_loop_ub =
        (int32_T) - (1.0 - (((real_T)gCoeffs->size[1] - 1.0) - 1.0)) + 1;
  }
  if ((i != b_loop_ub) && ((i != 1) && (b_loop_ub != 1))) {
    emlrtDimSizeImpxCheckR2021b(i, b_loop_ub, &emlrtECI, (emlrtCTX)sp);
  }
  if (gCoeffs->size[1] != 0) {
    b_re = gCoeffs_data[0].re;
    b_im = gCoeffs_data[0].im;
    i = gCoeffs->size[1];
    for (k = 0; k <= i - 2; k++) {
      h0_re = h0.re * b_re - h0.im * b_im;
      h0_im = h0.re * b_im + h0.im * b_re;
      b_re = h0_re + gCoeffs_data[k + 1].re;
      b_im = h0_im + gCoeffs_data[k + 1].im;
    }
  }
  freq_times_g_at_se_re = freq * b_re;
  freq_times_g_at_se_im = freq * b_im;
  /*  may not need this yet - but it's the local error est. Return this */
  /*  from the same routine as above: */
  /*  main loop */
  i = h_quad->size[0];
  h_quad->size[0] = p_quad->size[0];
  emxEnsureCapacity_creal_T(sp, h_quad, i, &d_emlrtRTEI);
  h_quad_data = h_quad->data;
  loop_ub = p_quad->size[0];
  for (i = 0; i < loop_ub; i++) {
    h_quad_data[i].re = 0.0;
    h_quad_data[i].im = 2.2204460492503131E-16;
  }
  i = p_quad->size[0];
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    /*  Euler predictor step */
    if (loop_ub + 1 == 1) {
      if (loop_ub + 1 > h_quad->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, h_quad->size[0],
                                      &i_emlrtBCI, (emlrtCTX)sp);
      }
      if (1 > p_quad->size[0]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, p_quad->size[0], &j_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (dgCoeffs->size[1] != 0) {
        b_re = dgCoeffs_data[0].re;
        b_im = dgCoeffs_data[0].im;
        i1 = dgCoeffs->size[1];
        for (k = 0; k <= i1 - 2; k++) {
          h0_re = h0.re * b_re - h0.im * b_im;
          h0_im = h0.re * b_im + h0.im * b_re;
          b_re = h0_re + dgCoeffs_data[k + 1].re;
          b_im = h0_im + dgCoeffs_data[k + 1].im;
        }
      }
      if (b_im == 0.0) {
        h_quad_re_tmp = 0.0;
        h0_re = 1.0 / b_re;
      } else if (b_re == 0.0) {
        h_quad_re_tmp = 1.0 / b_im;
        h0_re = 0.0;
      } else {
        brm = muDoubleScalarAbs(b_re);
        h0_im = muDoubleScalarAbs(b_im);
        if (brm > h0_im) {
          h0_re = b_im / b_re;
          h0_im = b_re + h0_re * b_im;
          h_quad_re_tmp = h0_re / h0_im;
          h0_re = (1.0 - h0_re * 0.0) / h0_im;
        } else if (h0_im == brm) {
          if (b_re > 0.0) {
            h0_re = 0.5;
          } else {
            h0_re = -0.5;
          }
          if (b_im > 0.0) {
            h0_im = 0.5;
          } else {
            h0_im = -0.5;
          }
          h_quad_re_tmp = (0.0 * h0_re + h0_im) / brm;
          h0_re = (h0_re - 0.0 * h0_im) / brm;
        } else {
          h0_re = b_re / b_im;
          h0_im = b_im + h0_re * b_re;
          h_quad_re_tmp = (h0_re * 0.0 + 1.0) / h0_im;
          h0_re /= h0_im;
        }
      }
      if (h0_re == 0.0) {
        h_quad_re_tmp /= freq;
        h0_re = 0.0;
      } else if (h_quad_re_tmp == 0.0) {
        h_quad_re_tmp = 0.0;
        h0_re /= freq;
      } else {
        h_quad_re_tmp /= freq;
        h0_re /= freq;
      }
      h_quad_data[0].re = h0.re + p_quad_data[0] * h_quad_re_tmp;
      h_quad_data[0].im = h0.im + p_quad_data[0] * h0_re;
    } else {
      if (loop_ub + 1 > h_quad->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, h_quad->size[0],
                                      &f_emlrtBCI, (emlrtCTX)sp);
      }
      if (dgCoeffs->size[1] != 0) {
        b_re = dgCoeffs_data[0].re;
        b_im = dgCoeffs_data[0].im;
        i1 = dgCoeffs->size[1];
        for (k = 0; k <= i1 - 2; k++) {
          h_quad_re_tmp = h_quad_data[loop_ub].re;
          b_h_quad_re_tmp = h_quad_data[loop_ub].im;
          h0_re = h_quad_re_tmp * b_re - b_h_quad_re_tmp * b_im;
          h0_im = h_quad_re_tmp * b_im + b_h_quad_re_tmp * b_re;
          b_re = h0_re + dgCoeffs_data[k + 1].re;
          b_im = h0_im + dgCoeffs_data[k + 1].im;
        }
      }
      if (loop_ub + 1 > p_quad->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, p_quad->size[0],
                                      &h_emlrtBCI, (emlrtCTX)sp);
      }
      if ((loop_ub < 1) || (loop_ub > p_quad->size[0])) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, p_quad->size[0], &g_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (b_im == 0.0) {
        h_quad_re_tmp = 0.0;
        h0_re = 1.0 / b_re;
      } else if (b_re == 0.0) {
        h_quad_re_tmp = 1.0 / b_im;
        h0_re = 0.0;
      } else {
        brm = muDoubleScalarAbs(b_re);
        h0_im = muDoubleScalarAbs(b_im);
        if (brm > h0_im) {
          h0_re = b_im / b_re;
          h0_im = b_re + h0_re * b_im;
          h_quad_re_tmp = h0_re / h0_im;
          h0_re = (1.0 - h0_re * 0.0) / h0_im;
        } else if (h0_im == brm) {
          if (b_re > 0.0) {
            h0_re = 0.5;
          } else {
            h0_re = -0.5;
          }
          if (b_im > 0.0) {
            h0_im = 0.5;
          } else {
            h0_im = -0.5;
          }
          h_quad_re_tmp = (0.0 * h0_re + h0_im) / brm;
          h0_re = (h0_re - 0.0 * h0_im) / brm;
        } else {
          h0_re = b_re / b_im;
          h0_im = b_im + h0_re * b_re;
          h_quad_re_tmp = (h0_re * 0.0 + 1.0) / h0_im;
          h0_re /= h0_im;
        }
      }
      if (h0_re == 0.0) {
        h_quad_re_tmp /= freq;
        h0_re = 0.0;
      } else if (h_quad_re_tmp == 0.0) {
        h_quad_re_tmp = 0.0;
        h0_re /= freq;
      } else {
        h_quad_re_tmp /= freq;
        h0_re /= freq;
      }
      if (loop_ub + 1 > h_quad->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, h_quad->size[0],
                                      &p_emlrtBCI, (emlrtCTX)sp);
      }
      if (loop_ub > h_quad->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, h_quad->size[0], &o_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      h0_im = p_quad_data[loop_ub] - p_quad_data[loop_ub - 1];
      h_quad_data[loop_ub].re =
          h_quad_data[loop_ub - 1].re + h0_im * h_quad_re_tmp;
      if (loop_ub > h_quad->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, h_quad->size[0], &o_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (loop_ub + 1 > h_quad->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, h_quad->size[0],
                                      &p_emlrtBCI, (emlrtCTX)sp);
      }
      h_quad_data[loop_ub].im = h_quad_data[loop_ub - 1].im + h0_im * h0_re;
    }
    /*  Newton corrector step */
    n = 1.0;
    b_loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (b_loop_ub < 10)) {
      n = (real_T)b_loop_ub + 1.0;
      if (loop_ub + 1 > p_quad->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, p_quad->size[0],
                                      &e_emlrtBCI, (emlrtCTX)sp);
      }
      if (loop_ub + 1 > h_quad->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, h_quad->size[0],
                                      &d_emlrtBCI, (emlrtCTX)sp);
      }
      if (gCoeffs->size[1] != 0) {
        b_re = gCoeffs_data[0].re;
        b_im = gCoeffs_data[0].im;
        i1 = gCoeffs->size[1];
        for (k = 0; k <= i1 - 2; k++) {
          h_quad_re_tmp = h_quad_data[loop_ub].re;
          b_h_quad_re_tmp = h_quad_data[loop_ub].im;
          h0_re = h_quad_re_tmp * b_re - b_h_quad_re_tmp * b_im;
          h0_im = h_quad_re_tmp * b_im + b_h_quad_re_tmp * b_re;
          b_re = h0_re + gCoeffs_data[k + 1].re;
          b_im = h0_im + gCoeffs_data[k + 1].im;
        }
      }
      if (loop_ub + 1 > h_quad->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, h_quad->size[0],
                                      &c_emlrtBCI, (emlrtCTX)sp);
      }
      if (dgCoeffs->size[1] != 0) {
        b_b_re = dgCoeffs_data[0].re;
        h0_im = dgCoeffs_data[0].im;
        i1 = dgCoeffs->size[1];
        for (k = 0; k <= i1 - 2; k++) {
          h_quad_re_tmp = h_quad_data[loop_ub].re;
          b_h_quad_re_tmp = h_quad_data[loop_ub].im;
          h0_re = h_quad_re_tmp * b_b_re - b_h_quad_re_tmp * h0_im;
          h0_im = h_quad_re_tmp * h0_im + b_h_quad_re_tmp * b_b_re;
          b_b_re = h0_re + dgCoeffs_data[k + 1].re;
          h0_im += dgCoeffs_data[k + 1].im;
        }
      }
      ar = (-freq_times_g_at_se_re - 0.0 * p_quad_data[loop_ub]) + freq * b_re;
      b_re = (-freq_times_g_at_se_im - p_quad_data[loop_ub]) + freq * b_im;
      b_h_quad_re_tmp = freq * b_b_re;
      h_quad_re_tmp = freq * h0_im;
      if (h_quad_re_tmp == 0.0) {
        if (b_re == 0.0) {
          b_b_re = ar / b_h_quad_re_tmp;
          h0_im = 0.0;
        } else if (ar == 0.0) {
          b_b_re = 0.0;
          h0_im = b_re / b_h_quad_re_tmp;
        } else {
          b_b_re = ar / b_h_quad_re_tmp;
          h0_im = b_re / b_h_quad_re_tmp;
        }
      } else if (b_h_quad_re_tmp == 0.0) {
        if (ar == 0.0) {
          b_b_re = b_re / h_quad_re_tmp;
          h0_im = 0.0;
        } else if (b_re == 0.0) {
          b_b_re = 0.0;
          h0_im = -(ar / h_quad_re_tmp);
        } else {
          b_b_re = b_re / h_quad_re_tmp;
          h0_im = -(ar / h_quad_re_tmp);
        }
      } else {
        brm = muDoubleScalarAbs(b_h_quad_re_tmp);
        h0_im = muDoubleScalarAbs(h_quad_re_tmp);
        if (brm > h0_im) {
          h0_re = h_quad_re_tmp / b_h_quad_re_tmp;
          h0_im = b_h_quad_re_tmp + h0_re * h_quad_re_tmp;
          b_b_re = (ar + h0_re * b_re) / h0_im;
          h0_im = (b_re - h0_re * ar) / h0_im;
        } else if (h0_im == brm) {
          if (b_h_quad_re_tmp > 0.0) {
            h0_re = 0.5;
          } else {
            h0_re = -0.5;
          }
          if (h_quad_re_tmp > 0.0) {
            h0_im = 0.5;
          } else {
            h0_im = -0.5;
          }
          b_b_re = (ar * h0_re + b_re * h0_im) / brm;
          h0_im = (b_re * h0_re - ar * h0_im) / brm;
        } else {
          h0_re = b_h_quad_re_tmp / h_quad_re_tmp;
          h0_im = h_quad_re_tmp + h0_re * b_h_quad_re_tmp;
          b_b_re = (h0_re * ar + b_re) / h0_im;
          h0_im = (h0_re * b_re - ar) / h0_im;
        }
      }
      if (loop_ub + 1 > h_quad->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, h_quad->size[0],
                                      &s_emlrtBCI, (emlrtCTX)sp);
      }
      h_quad_data[loop_ub].re -= b_b_re;
      if (loop_ub + 1 > h_quad->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, h_quad->size[0],
                                      &r_emlrtBCI, (emlrtCTX)sp);
      }
      h_quad_data[loop_ub].im -= h0_im;
      if (loop_ub + 1 > p_quad->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, p_quad->size[0],
                                      &b_emlrtBCI, (emlrtCTX)sp);
      }
      if (loop_ub + 1 > h_quad->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, h_quad->size[0],
                                      &emlrtBCI, (emlrtCTX)sp);
      }
      if (gCoeffs->size[1] != 0) {
        b_re = gCoeffs_data[0].re;
        b_im = gCoeffs_data[0].im;
        i1 = gCoeffs->size[1];
        for (k = 0; k <= i1 - 2; k++) {
          h_quad_re_tmp = h_quad_data[loop_ub].re;
          b_h_quad_re_tmp = h_quad_data[loop_ub].im;
          h0_re = h_quad_re_tmp * b_re - b_h_quad_re_tmp * b_im;
          h0_im = h_quad_re_tmp * b_im + b_h_quad_re_tmp * b_re;
          b_re = h0_re + gCoeffs_data[k + 1].re;
          b_im = h0_im + gCoeffs_data[k + 1].im;
        }
      }
      b_re = (freq_times_g_at_se_re + 0.0 * p_quad_data[loop_ub]) - freq * b_re;
      b_im = (freq_times_g_at_se_im + p_quad_data[loop_ub]) - freq * b_im;
      if (muDoubleScalarHypot(b_re, b_im) < 1.0E-10) {
        exitg1 = true;
      } else if (b_loop_ub + 1 == 10) {
        n = rtInf;
        exitg1 = true;
      } else {
        b_loop_ub++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtCTX)sp);
        }
      }
    }
    if (loop_ub + 1 > Newton_success->size[0]) {
      emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, Newton_success->size[0],
                                    &q_emlrtBCI, (emlrtCTX)sp);
    }
    Newton_success_data[loop_ub] = n;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  /*  now get Jacobian */
  i = dhdp_quad->size[0];
  dhdp_quad->size[0] = h_quad->size[0];
  emxEnsureCapacity_creal_T(sp, dhdp_quad, i, &e_emlrtRTEI);
  dhdp_quad_data = dhdp_quad->data;
  if ((h_quad->size[0] != 0) && (dgCoeffs->size[1] != 0)) {
    i = dhdp_quad->size[0];
    dhdp_quad->size[0] = h_quad->size[0];
    emxEnsureCapacity_creal_T(sp, dhdp_quad, i, &f_emlrtRTEI);
    dhdp_quad_data = dhdp_quad->data;
    loop_ub = h_quad->size[0];
    for (i = 0; i < loop_ub; i++) {
      dhdp_quad_data[i] = dgCoeffs_data[0];
    }
    i = dgCoeffs->size[1];
    for (k = 0; k <= i - 2; k++) {
      loop_ub = h_quad->size[0];
      i1 = dhdp_quad->size[0];
      dhdp_quad->size[0] = h_quad->size[0];
      emxEnsureCapacity_creal_T(sp, dhdp_quad, i1, &f_emlrtRTEI);
      dhdp_quad_data = dhdp_quad->data;
      for (i1 = 0; i1 < loop_ub; i1++) {
        h_quad_re_tmp = h_quad_data[i1].re;
        b_h_quad_re_tmp = dhdp_quad_data[i1].im;
        h0_im = h_quad_data[i1].im;
        h0_re = dhdp_quad_data[i1].re;
        dhdp_quad_data[i1].re =
            (h_quad_re_tmp * h0_re - h0_im * b_h_quad_re_tmp) +
            dgCoeffs_data[k + 1].re;
        dhdp_quad_data[i1].im =
            (h_quad_re_tmp * b_h_quad_re_tmp + h0_im * h0_re) +
            dgCoeffs_data[k + 1].im;
      }
    }
  }
  emxFree_creal_T(sp, &dgCoeffs);
  loop_ub = dhdp_quad->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_h_quad_re_tmp = dhdp_quad_data[i].re;
    h_quad_re_tmp = dhdp_quad_data[i].im;
    if (h_quad_re_tmp == 0.0) {
      h_quad_re_tmp = 0.0;
      h0_re = 1.0 / b_h_quad_re_tmp;
    } else if (b_h_quad_re_tmp == 0.0) {
      h_quad_re_tmp = 1.0 / h_quad_re_tmp;
      h0_re = 0.0;
    } else {
      brm = muDoubleScalarAbs(b_h_quad_re_tmp);
      h0_im = muDoubleScalarAbs(h_quad_re_tmp);
      if (brm > h0_im) {
        h0_re = h_quad_re_tmp / b_h_quad_re_tmp;
        h0_im = b_h_quad_re_tmp + h0_re * h_quad_re_tmp;
        h_quad_re_tmp = h0_re / h0_im;
        h0_re = (1.0 - h0_re * 0.0) / h0_im;
      } else if (h0_im == brm) {
        if (b_h_quad_re_tmp > 0.0) {
          h0_re = 0.5;
        } else {
          h0_re = -0.5;
        }
        if (h_quad_re_tmp > 0.0) {
          h0_im = 0.5;
        } else {
          h0_im = -0.5;
        }
        h_quad_re_tmp = (0.0 * h0_re + h0_im) / brm;
        h0_re = (h0_re - 0.0 * h0_im) / brm;
      } else {
        h0_re = b_h_quad_re_tmp / h_quad_re_tmp;
        h0_im = h_quad_re_tmp + h0_re * b_h_quad_re_tmp;
        h_quad_re_tmp = (h0_re * 0.0 + 1.0) / h0_im;
        h0_re /= h0_im;
      }
    }
    if (h0_re == 0.0) {
      dhdp_quad_data[i].re = h_quad_re_tmp / freq;
      dhdp_quad_data[i].im = 0.0;
    } else if (h_quad_re_tmp == 0.0) {
      dhdp_quad_data[i].re = 0.0;
      dhdp_quad_data[i].im = h0_re / freq;
    } else {
      dhdp_quad_data[i].re = h_quad_re_tmp / freq;
      dhdp_quad_data[i].im = h0_re / freq;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (SDquadODEulerNEwton.c) */
