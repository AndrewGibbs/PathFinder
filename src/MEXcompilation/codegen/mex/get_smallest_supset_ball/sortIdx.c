/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sortIdx.c
 *
 * Code generation for function 'sortIdx'
 *
 */

/* Include files */
#include "sortIdx.h"
#include "eml_int_forloop_overflow_check.h"
#include "get_smallest_supset_ball_data.h"
#include "get_smallest_supset_ball_emxutil.h"
#include "get_smallest_supset_ball_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo fd_emlrtRSI = {
    105,       /* lineNo */
    "sortIdx", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                      */
};

static emlrtRSInfo gd_emlrtRSI = {
    308,                /* lineNo */
    "block_merge_sort", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                      */
};

static emlrtRSInfo hd_emlrtRSI = {
    316,                /* lineNo */
    "block_merge_sort", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                      */
};

static emlrtRSInfo id_emlrtRSI = {
    317,                /* lineNo */
    "block_merge_sort", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                      */
};

static emlrtRSInfo jd_emlrtRSI = {
    325,                /* lineNo */
    "block_merge_sort", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                      */
};

static emlrtRSInfo kd_emlrtRSI = {
    333,                /* lineNo */
    "block_merge_sort", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                      */
};

static emlrtRSInfo ld_emlrtRSI = {
    392,                      /* lineNo */
    "initialize_vector_sort", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                      */
};

static emlrtRSInfo md_emlrtRSI = {
    420,                      /* lineNo */
    "initialize_vector_sort", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                      */
};

static emlrtRSInfo nd_emlrtRSI = {
    427,                      /* lineNo */
    "initialize_vector_sort", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                      */
};

static emlrtRSInfo rd_emlrtRSI = {
    499,           /* lineNo */
    "merge_block", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                      */
};

static emlrtRSInfo td_emlrtRSI = {
    507,           /* lineNo */
    "merge_block", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                      */
};

static emlrtRSInfo ud_emlrtRSI = {
    514,           /* lineNo */
    "merge_block", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                      */
};

static emlrtRSInfo vd_emlrtRSI = {
    561,     /* lineNo */
    "merge", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                      */
};

static emlrtRSInfo wd_emlrtRSI = {
    530,     /* lineNo */
    "merge", /* fcnName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pathName
                                                                      */
};

static emlrtRTEInfo ic_emlrtRTEI = {
    61,        /* lineNo */
    5,         /* colNo */
    "sortIdx", /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = {
    386,       /* lineNo */
    1,         /* colNo */
    "sortIdx", /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = {
    388,       /* lineNo */
    1,         /* colNo */
    "sortIdx", /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pName */
};

static emlrtRTEInfo lc_emlrtRTEI = {
    308,       /* lineNo */
    14,        /* colNo */
    "sortIdx", /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = {
    308,       /* lineNo */
    20,        /* colNo */
    "sortIdx", /* fName */
    "/home/andrew/matlab/toolbox/eml/eml/+coder/+internal/sortIdx.m" /* pName */
};

/* Function Declarations */
static void merge(const emlrtStack *sp, emxArray_int32_T *idx,
                  emxArray_real_T *x, int32_T offset, int32_T np, int32_T nq,
                  emxArray_int32_T *iwork, emxArray_real_T *xwork);

static void merge_block(const emlrtStack *sp, emxArray_int32_T *idx,
                        emxArray_real_T *x, int32_T offset, int32_T n,
                        int32_T preSortLevel, emxArray_int32_T *iwork,
                        emxArray_real_T *xwork);

static void merge_pow2_block(emxArray_int32_T *idx, emxArray_real_T *x,
                             int32_T offset);

/* Function Definitions */
static void merge(const emlrtStack *sp, emxArray_int32_T *idx,
                  emxArray_real_T *x, int32_T offset, int32_T np, int32_T nq,
                  emxArray_int32_T *iwork, emxArray_real_T *xwork)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T *x_data;
  real_T *xwork_data;
  int32_T exitg1;
  int32_T iout;
  int32_T j;
  int32_T n_tmp;
  int32_T p;
  int32_T q;
  int32_T *idx_data;
  int32_T *iwork_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  xwork_data = xwork->data;
  iwork_data = iwork->data;
  x_data = x->data;
  idx_data = idx->data;
  if (nq != 0) {
    n_tmp = np + nq;
    st.site = &wd_emlrtRSI;
    if ((1 <= n_tmp) && (n_tmp > 2147483646)) {
      b_st.site = &f_emlrtRSI;
      b_check_forloop_overflow_error(&b_st);
    }
    for (j = 0; j < n_tmp; j++) {
      iout = offset + j;
      iwork_data[j] = idx_data[iout];
      xwork_data[j] = x_data[iout];
    }
    p = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork_data[p] <= xwork_data[q]) {
        idx_data[iout] = iwork_data[p];
        x_data[iout] = xwork_data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx_data[iout] = iwork_data[q];
        x_data[iout] = xwork_data[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          st.site = &vd_emlrtRSI;
          if ((p + 1 <= np) && (np > 2147483646)) {
            b_st.site = &f_emlrtRSI;
            b_check_forloop_overflow_error(&b_st);
          }
          for (j = p + 1; j <= np; j++) {
            iout = q + j;
            idx_data[iout] = iwork_data[j - 1];
            x_data[iout] = xwork_data[j - 1];
          }
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void merge_block(const emlrtStack *sp, emxArray_int32_T *idx,
                        emxArray_real_T *x, int32_T offset, int32_T n,
                        int32_T preSortLevel, emxArray_int32_T *iwork,
                        emxArray_real_T *xwork)
{
  emlrtStack st;
  int32_T bLen;
  int32_T nPairs;
  int32_T nTail;
  int32_T tailOffset;
  st.prev = sp;
  st.tls = sp->tls;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        st.site = &rd_emlrtRSI;
        merge(&st, idx, x, offset + tailOffset, bLen, nTail - bLen, iwork,
              xwork);
      }
    }
    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      st.site = &td_emlrtRSI;
      merge(&st, idx, x, offset + nTail * tailOffset, bLen, bLen, iwork, xwork);
    }
    bLen = tailOffset;
  }
  if (n > bLen) {
    st.site = &ud_emlrtRSI;
    merge(&st, idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

static void merge_pow2_block(emxArray_int32_T *idx, emxArray_real_T *x,
                             int32_T offset)
{
  real_T xwork[256];
  real_T *x_data;
  int32_T iwork[256];
  int32_T b;
  int32_T bLen;
  int32_T bLen2;
  int32_T blockOffset;
  int32_T exitg1;
  int32_T iout;
  int32_T j;
  int32_T k;
  int32_T nPairs;
  int32_T p;
  int32_T q;
  int32_T *idx_data;
  x_data = x->data;
  idx_data = idx->data;
  for (b = 0; b < 6; b++) {
    bLen = 1 << (b + 2);
    bLen2 = bLen << 1;
    nPairs = 256 >> (b + 3);
    for (k = 0; k < nPairs; k++) {
      blockOffset = offset + k * bLen2;
      for (j = 0; j < bLen2; j++) {
        iout = blockOffset + j;
        iwork[j] = idx_data[iout];
        xwork[j] = x_data[iout];
      }
      p = 0;
      q = bLen;
      iout = blockOffset - 1;
      do {
        exitg1 = 0;
        iout++;
        if (xwork[p] <= xwork[q]) {
          idx_data[iout] = iwork[p];
          x_data[iout] = xwork[p];
          if (p + 1 < bLen) {
            p++;
          } else {
            exitg1 = 1;
          }
        } else {
          idx_data[iout] = iwork[q];
          x_data[iout] = xwork[q];
          if (q + 1 < bLen2) {
            q++;
          } else {
            iout -= p;
            for (j = p + 1; j <= bLen; j++) {
              q = iout + j;
              idx_data[q] = iwork[j - 1];
              x_data[q] = xwork[j - 1];
            }
            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);
    }
  }
}

void sortIdx(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_int32_T *iwork;
  emxArray_real_T *xwork;
  real_T x4[4];
  real_T d;
  real_T d1;
  real_T *x_data;
  real_T *xwork_data;
  int32_T idx4[4];
  int32_T b_n;
  int32_T i1;
  int32_T i3;
  int32_T i4;
  int32_T ib;
  int32_T k;
  int32_T n;
  int32_T nNaNs;
  int32_T quartetOffset;
  int32_T *idx_data;
  int32_T *iwork_data;
  int8_T perm[4];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  ib = x->size[0];
  quartetOffset = idx->size[0];
  idx->size[0] = ib;
  emxEnsureCapacity_int32_T(sp, idx, quartetOffset, &ic_emlrtRTEI);
  idx_data = idx->data;
  for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
    idx_data[quartetOffset] = 0;
  }
  if (x->size[0] != 0) {
    emxInit_int32_T(sp, &iwork, &lc_emlrtRTEI);
    st.site = &fd_emlrtRSI;
    n = x->size[0];
    b_st.site = &gd_emlrtRSI;
    b_n = x->size[0];
    x4[0] = 0.0;
    idx4[0] = 0;
    x4[1] = 0.0;
    idx4[1] = 0;
    x4[2] = 0.0;
    idx4[2] = 0;
    x4[3] = 0.0;
    idx4[3] = 0;
    quartetOffset = iwork->size[0];
    iwork->size[0] = ib;
    emxEnsureCapacity_int32_T(&b_st, iwork, quartetOffset, &jc_emlrtRTEI);
    iwork_data = iwork->data;
    for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
      iwork_data[quartetOffset] = 0;
    }
    emxInit_real_T(&b_st, &xwork, &mc_emlrtRTEI);
    ib = x->size[0];
    quartetOffset = xwork->size[0];
    xwork->size[0] = ib;
    emxEnsureCapacity_real_T(&b_st, xwork, quartetOffset, &kc_emlrtRTEI);
    xwork_data = xwork->data;
    for (quartetOffset = 0; quartetOffset < ib; quartetOffset++) {
      xwork_data[quartetOffset] = 0.0;
    }
    nNaNs = 0;
    ib = -1;
    c_st.site = &ld_emlrtRSI;
    if ((1 <= x->size[0]) && (x->size[0] > 2147483646)) {
      d_st.site = &f_emlrtRSI;
      b_check_forloop_overflow_error(&d_st);
    }
    for (k = 0; k < b_n; k++) {
      if (muDoubleScalarIsNaN(x_data[k])) {
        i3 = (b_n - nNaNs) - 1;
        idx_data[i3] = k + 1;
        xwork_data[i3] = x_data[k];
        nNaNs++;
      } else {
        ib++;
        idx4[ib] = k + 1;
        x4[ib] = x_data[k];
        if (ib + 1 == 4) {
          quartetOffset = k - nNaNs;
          if (x4[0] <= x4[1]) {
            i1 = 1;
            ib = 2;
          } else {
            i1 = 2;
            ib = 1;
          }
          if (x4[2] <= x4[3]) {
            i3 = 3;
            i4 = 4;
          } else {
            i3 = 4;
            i4 = 3;
          }
          d = x4[i1 - 1];
          d1 = x4[i3 - 1];
          if (d <= d1) {
            d = x4[ib - 1];
            if (d <= d1) {
              perm[0] = (int8_T)i1;
              perm[1] = (int8_T)ib;
              perm[2] = (int8_T)i3;
              perm[3] = (int8_T)i4;
            } else if (d <= x4[i4 - 1]) {
              perm[0] = (int8_T)i1;
              perm[1] = (int8_T)i3;
              perm[2] = (int8_T)ib;
              perm[3] = (int8_T)i4;
            } else {
              perm[0] = (int8_T)i1;
              perm[1] = (int8_T)i3;
              perm[2] = (int8_T)i4;
              perm[3] = (int8_T)ib;
            }
          } else {
            d1 = x4[i4 - 1];
            if (d <= d1) {
              if (x4[ib - 1] <= d1) {
                perm[0] = (int8_T)i3;
                perm[1] = (int8_T)i1;
                perm[2] = (int8_T)ib;
                perm[3] = (int8_T)i4;
              } else {
                perm[0] = (int8_T)i3;
                perm[1] = (int8_T)i1;
                perm[2] = (int8_T)i4;
                perm[3] = (int8_T)ib;
              }
            } else {
              perm[0] = (int8_T)i3;
              perm[1] = (int8_T)i4;
              perm[2] = (int8_T)i1;
              perm[3] = (int8_T)ib;
            }
          }
          idx_data[quartetOffset - 3] = idx4[perm[0] - 1];
          idx_data[quartetOffset - 2] = idx4[perm[1] - 1];
          idx_data[quartetOffset - 1] = idx4[perm[2] - 1];
          idx_data[quartetOffset] = idx4[perm[3] - 1];
          x_data[quartetOffset - 3] = x4[perm[0] - 1];
          x_data[quartetOffset - 2] = x4[perm[1] - 1];
          x_data[quartetOffset - 1] = x4[perm[2] - 1];
          x_data[quartetOffset] = x4[perm[3] - 1];
          ib = -1;
        }
      }
    }
    i4 = (b_n - nNaNs) - 1;
    if (ib + 1 > 0) {
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (ib + 1 == 1) {
        perm[0] = 1;
      } else if (ib + 1 == 2) {
        if (x4[0] <= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
      } else if (x4[0] <= x4[1]) {
        if (x4[1] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }
      c_st.site = &md_emlrtRSI;
      if (ib + 1 > 2147483646) {
        d_st.site = &f_emlrtRSI;
        b_check_forloop_overflow_error(&d_st);
      }
      for (k = 0; k <= ib; k++) {
        i3 = perm[k] - 1;
        quartetOffset = (i4 - ib) + k;
        idx_data[quartetOffset] = idx4[i3];
        x_data[quartetOffset] = x4[i3];
      }
    }
    ib = (nNaNs >> 1) + 1;
    c_st.site = &nd_emlrtRSI;
    for (k = 0; k <= ib - 2; k++) {
      quartetOffset = (i4 + k) + 1;
      i1 = idx_data[quartetOffset];
      i3 = (b_n - k) - 1;
      idx_data[quartetOffset] = idx_data[i3];
      idx_data[i3] = i1;
      x_data[quartetOffset] = xwork_data[i3];
      x_data[i3] = xwork_data[quartetOffset];
    }
    if ((nNaNs & 1) != 0) {
      quartetOffset = i4 + ib;
      x_data[quartetOffset] = xwork_data[quartetOffset];
    }
    i1 = n - nNaNs;
    ib = 2;
    if (i1 > 1) {
      if (n >= 256) {
        quartetOffset = i1 >> 8;
        if (quartetOffset > 0) {
          b_st.site = &hd_emlrtRSI;
          for (ib = 0; ib < quartetOffset; ib++) {
            b_st.site = &id_emlrtRSI;
            merge_pow2_block(idx, x, ib << 8);
          }
          ib = quartetOffset << 8;
          quartetOffset = i1 - ib;
          if (quartetOffset > 0) {
            b_st.site = &jd_emlrtRSI;
            merge_block(&b_st, idx, x, ib, quartetOffset, 2, iwork, xwork);
          }
          ib = 8;
        }
      }
      b_st.site = &kd_emlrtRSI;
      merge_block(&b_st, idx, x, 0, i1, ib, iwork, xwork);
    }
    emxFree_real_T(&st, &xwork);
    emxFree_int32_T(&st, &iwork);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (sortIdx.c) */
