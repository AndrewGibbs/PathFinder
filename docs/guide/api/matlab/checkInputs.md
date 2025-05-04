# `checkInputs.m`

Immediately after PathFinder is called, this subroutine checks that all of the inputs are the correct data type, etc.

If the wrong data type is provided, this function returns an error.

```matlab
checkInputs(a, b, f, phaseIn, freq, nPts)
```

## Inputs
* `a` and `b` are the endpoints of the integral. These should be complex scalars.
* `f`: A function handle corresponding to $f(z)$ in the original integral.
* `phaseIn` : An array of coefficients of the phase function $g$.
* `freq` : The frequency parameter $\omega$. This should be a scalar.
* `nPts` : The number of quadrature points per contour. This should be an integer.