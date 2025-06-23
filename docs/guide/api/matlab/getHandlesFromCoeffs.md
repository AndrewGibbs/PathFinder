# `getHandlesFromCoeffs.m`

Computes polynomial coefficients of derivatives of a polynomial, for all non-vanishing derivatives. For example, if given a vector of length $5$, this corresponds to a degree $4$ polynomial, which will have $4$ non-vanishing derivatives, the function will return $5$ vectors of length $5,\ldots,1$ corresponding to coefficients of degrees $4,\ldots,0$. Coefficient vectors are in the [usual Matlab format](https://uk.mathworks.com/help/matlab/ref/polyval.html), with the highest degree coefficient first.

```matlab
polyDerivCoeffsCellArray = getHandlesFromCoeffs(polyCoeffs)
```

## Inputs
`polyCoeffs` is the coefficients of the polynomial phase function $g$.

## Outputs

`polyDerivCoeffsCellArray` is a cell array of coefficient vectors of polynomial coefficients.