# `getContours.m`

This subroutine loops over all non-oscillatory balls, and approximates the *steepest descent contours* from the *exits* of each ball. For a full description of the underlying mathematical processes, see Section 2.2 and 2.3 of {cite:p}`PFpaper`.

```matlab
contours = getContours(phase_coeffs, balls, valleys, params)
```

## Inputs

* `phase_coeffs`: Coefficients of the phase function $g$
* `balls`: A cell array of type [`Ball`](Ball.md)
* `valleys`: Directions of the valleys, stored as an array of numbers on the complex unit circle.
* `params`: A Matlab structure containing many user-specified parameters which are used for subsequent calculations.

## Outputs

`contours`: A cell array of instances of [`ContourSD`](ContourSD.md)