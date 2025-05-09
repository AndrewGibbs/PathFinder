# `beyondNoReturn.m`

This is the Matlab version of a routine which is typically run as compiled C code. The idea is based on the idea of *the region of no return*, which is outlined in section 3.2 of {cite:p}`PFpaper`. This subroutine identifies when a steepest descent contour has reached such a region in the complex plane, after which it can never leave.

```matlab
[value, vIndex] = beyondNoReturn(h,valleys,phaseCoeffs,rStar)
```

The *no return* regions can be seen around the edges of the following image:
 ![Example](../../../examples/eg_contour_def.png)

## Inputs
* `h`: The steepest point that has been traced along the steepest descent path
* `valleys`: Valleys of the polynomial phase function $g$
* `phaseCoeffs`: Coefficients of the polynomial phase function $g$.
* `rStar`: A constant dependent on $g$, stored to save repeated computations. This is the solution of a polynomial equation, details are given in section 2.4 of {cite:p}`PFpaper`.

## Outputs

* `value`: `true` if inside the region of no return, `false` otherwise.
* `vIndex`: The index of the limiting valley of the particular segment of the no return region.
 This will be blank if `value = false`, i.e. not in the region of no return.