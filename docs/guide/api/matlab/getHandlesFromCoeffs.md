# `getHandlesFromCoeffs.m`

Computes polynomial coefficients of derivatives of a polynomial, for all non-vanishing derivatives. For example, if given a vector of length 5, this corresponds to a degree for polynomial, which will have four non-vanishing derivaties, the function will return four vectors of length three, two and one. Coefficient vectors are in the usual matlab format, with the highest degree coefficient first.

```matlab
polyDerivCoeffsCellArray = getHandlesFromCoeffs(polyCoeffs)
```

## Inputs
`polyCoeffs` is the coefficients of the polynomial phase function $g$.

## Outputs

`polyDerivCoeffsCellArray` is a cell array of coefficient vectors of polynomial coefficients.