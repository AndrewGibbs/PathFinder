/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SE_NEwtonCorrection.c
 *
 * Code generation for function 'SE_NEwtonCorrection'
 *
 */

/* Include files */
#include "SE_NEwtonCorrection.h"
#include "SE_NEwtonCorrection_data.h"
#include "SE_NEwtonCorrection_emxutil.h"
#include "SE_NEwtonCorrection_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo
    emlrtRSI =
        {
            10,                    /* lineNo */
            "SE_NEwtonCorrection", /* fcnName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SE_NEwtonCorrection.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    21,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" /* pathName */
};

static emlrtECInfo
    emlrtECI =
        {
            2,                     /* nDims */
            7,                     /* lineNo */
            16,                    /* colNo */
            "SE_NEwtonCorrection", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SE_NEwtonCorrection.m" /* pName */
};

static emlrtBCInfo
    emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            7,                     /* lineNo */
            27,                    /* colNo */
            "gCoeffs",             /* aName */
            "SE_NEwtonCorrection", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SE_NEwtonCorrection.m", /* pName */
            0                        /* checkKind */
};

static emlrtBCInfo
    b_emlrtBCI =
        {
            -1,                    /* iFirst */
            -1,                    /* iLast */
            7,                     /* lineNo */
            24,                    /* colNo */
            "gCoeffs",             /* aName */
            "SE_NEwtonCorrection", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SE_NEwtonCorrection.m", /* pName */
            0                        /* checkKind */
};

static emlrtRTEInfo
    b_emlrtRTEI =
        {
            7,                     /* lineNo */
            37,                    /* colNo */
            "SE_NEwtonCorrection", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SE_NEwtonCorrection.m" /* pName */
};

static emlrtRTEInfo
    c_emlrtRTEI =
        {
            7,                     /* lineNo */
            5,                     /* colNo */
            "SE_NEwtonCorrection", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SE_NEwtonCorrection.m" /* pName */
};

static emlrtRTEInfo
    d_emlrtRTEI =
        {
            1,                     /* lineNo */
            36,                    /* colNo */
            "SE_NEwtonCorrection", /* fName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SE_NEwtonCorrection.m" /* pName */
};

static emlrtRSInfo
    c_emlrtRSI =
        {
            7,                     /* lineNo */
            "SE_NEwtonCorrection", /* fcnName */
            "/home/andrew/Dropbox/PathFinderInf/src/contours/"
            "SE_NEwtonCorrection.m" /* pathName */
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

void SE_NEwtonCorrection(const emlrtStack *sp, real_T P, const creal_T SEn0,
                         const creal_T SEx, const emxArray_creal_T *gCoeffs,
                         real_T NewtonThresh, uint32_T NewtonIts,
                         const creal_T nearby_SP, real_T step_size_adjust,
                         creal_T *SEn_n, boolean_T *Newton_success)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_creal_T *dgCoeffs;
  emxArray_real_T *r;
  const creal_T *gCoeffs_data;
  creal_T *dgCoeffs_data;
  real_T Newton_step_im;
  real_T Newton_step_re;
  real_T SEx_im;
  real_T SEx_re;
  real_T brm;
  real_T err_im;
  real_T err_re;
  real_T g_at_SEx_im;
  real_T g_at_SEx_re;
  real_T max_deviation;
  real_T re;
  real_T *r1;
  int32_T i;
  int32_T k;
  int32_T loop_ub;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  gCoeffs_data = gCoeffs->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  max_deviation =
      step_size_adjust *
      muDoubleScalarHypot(SEn0.re - nearby_SP.re, SEn0.im - nearby_SP.im);
  *Newton_success = false;
  if (gCoeffs->size[1] != 0) {
    g_at_SEx_re = gCoeffs_data[0].re;
    g_at_SEx_im = gCoeffs_data[0].im;
    i = gCoeffs->size[1];
    for (k = 0; k <= i - 2; k++) {
      SEx_re = SEx.re * g_at_SEx_re - SEx.im * g_at_SEx_im;
      SEx_im = SEx.re * g_at_SEx_im + SEx.im * g_at_SEx_re;
      g_at_SEx_re = SEx_re + gCoeffs_data[k + 1].re;
      g_at_SEx_im = SEx_im + gCoeffs_data[k + 1].im;
    }
  }
  if (1 > gCoeffs->size[1] - 1) {
    loop_ub = 0;
  } else {
    if (1 > gCoeffs->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, gCoeffs->size[1], &b_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if ((gCoeffs->size[1] - 1 < 1) ||
        (gCoeffs->size[1] - 1 > gCoeffs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(gCoeffs->size[1] - 1, 1, gCoeffs->size[1],
                                    &emlrtBCI, (emlrtCTX)sp);
    }
    loop_ub = gCoeffs->size[1] - 1;
  }
  emxInit_real_T(sp, &r, &d_emlrtRTEI);
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
    k = (int32_T) - (1.0 - ((real_T)gCoeffs->size[1] - 1.0));
    for (i = 0; i <= k; i++) {
      r1[i] = ((real_T)gCoeffs->size[1] - 1.0) - (real_T)i;
    }
  }
  if ((loop_ub != r->size[1]) && ((loop_ub != 1) && (r->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(loop_ub, r->size[1], &emlrtECI, (emlrtCTX)sp);
  }
  emxInit_creal_T(sp, &dgCoeffs, &c_emlrtRTEI);
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
    st.site = &c_emlrtRSI;
    binary_expand_op(&st, dgCoeffs, gCoeffs, loop_ub - 1, r);
    dgCoeffs_data = dgCoeffs->data;
  }
  emxFree_real_T(sp, &r);
  *SEn_n = SEn0;
  st.site = &emlrtRSI;
  if ((1U <= NewtonIts) && (NewtonIts > 4294967294U)) {
    b_st.site = &b_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  loop_ub = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= (int32_T)NewtonIts - 1)) {
    if (gCoeffs->size[1] != 0) {
      Newton_step_re = gCoeffs_data[0].re;
      Newton_step_im = gCoeffs_data[0].im;
      i = gCoeffs->size[1];
      for (k = 0; k <= i - 2; k++) {
        SEx_re = SEn_n->re * Newton_step_re - SEn_n->im * Newton_step_im;
        SEx_im = SEn_n->re * Newton_step_im + SEn_n->im * Newton_step_re;
        Newton_step_re = SEx_re + gCoeffs_data[k + 1].re;
        Newton_step_im = SEx_im + gCoeffs_data[k + 1].im;
      }
    }
    err_re = (g_at_SEx_re + 0.0 * P) - Newton_step_re;
    err_im = (g_at_SEx_im + P) - Newton_step_im;
    /*  check if residual error is small enough to suggest convergence */
    if (muDoubleScalarHypot(err_re, err_im) < NewtonThresh) {
      *Newton_success = true;
      exitg1 = true;
    } else {
      /*  get step which will take us to new point */
      if (dgCoeffs->size[1] != 0) {
        Newton_step_re = dgCoeffs_data[0].re;
        Newton_step_im = dgCoeffs_data[0].im;
        i = dgCoeffs->size[1];
        for (k = 0; k <= i - 2; k++) {
          SEx_re = SEn_n->re * Newton_step_re - SEn_n->im * Newton_step_im;
          SEx_im = SEn_n->re * Newton_step_im + SEn_n->im * Newton_step_re;
          Newton_step_re = SEx_re + dgCoeffs_data[k + 1].re;
          Newton_step_im = SEx_im + dgCoeffs_data[k + 1].im;
        }
      }
      if (Newton_step_im == 0.0) {
        if (err_im == 0.0) {
          re = err_re / Newton_step_re;
          SEx_im = 0.0;
        } else if (err_re == 0.0) {
          re = 0.0;
          SEx_im = err_im / Newton_step_re;
        } else {
          re = err_re / Newton_step_re;
          SEx_im = err_im / Newton_step_re;
        }
      } else if (Newton_step_re == 0.0) {
        if (err_re == 0.0) {
          re = err_im / Newton_step_im;
          SEx_im = 0.0;
        } else if (err_im == 0.0) {
          re = 0.0;
          SEx_im = -(err_re / Newton_step_im);
        } else {
          re = err_im / Newton_step_im;
          SEx_im = -(err_re / Newton_step_im);
        }
      } else {
        brm = muDoubleScalarAbs(Newton_step_re);
        SEx_im = muDoubleScalarAbs(Newton_step_im);
        if (brm > SEx_im) {
          SEx_re = Newton_step_im / Newton_step_re;
          SEx_im = Newton_step_re + SEx_re * Newton_step_im;
          re = (err_re + SEx_re * err_im) / SEx_im;
          SEx_im = (err_im - SEx_re * err_re) / SEx_im;
        } else if (SEx_im == brm) {
          if (Newton_step_re > 0.0) {
            SEx_re = 0.5;
          } else {
            SEx_re = -0.5;
          }
          if (Newton_step_im > 0.0) {
            SEx_im = 0.5;
          } else {
            SEx_im = -0.5;
          }
          re = (err_re * SEx_re + err_im * SEx_im) / brm;
          SEx_im = (err_im * SEx_re - err_re * SEx_im) / brm;
        } else {
          SEx_re = Newton_step_re / Newton_step_im;
          SEx_im = Newton_step_im + SEx_re * Newton_step_re;
          re = (SEx_re * err_re + err_im) / SEx_im;
          SEx_im = (SEx_re * err_im - err_re) / SEx_im;
        }
      }
      /*  get next approx of steepest entrance */
      SEn_n->re += re;
      SEn_n->im += SEx_im;
      /*  check this step isn't too big */
      if ((muDoubleScalarHypot(re, SEx_im) > max_deviation) ||
          (muDoubleScalarHypot(SEn_n->re - SEn0.re, SEn_n->im - SEn0.im) >
           max_deviation)) {
        /*  this check is actually not essential */
        /*              Newton_success = false; */
        /*              Newton_success = false; */
        exitg1 = true;
      } else {
        /*  check distance from where we started isn't too big */
        loop_ub++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtCTX)sp);
        }
      }
    }
  }
  emxFree_creal_T(sp, &dgCoeffs);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (SE_NEwtonCorrection.c) */
