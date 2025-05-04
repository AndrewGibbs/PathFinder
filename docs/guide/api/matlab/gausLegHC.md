# `gausLegHC.m`

A lookup function containing many hard-coded values for [Gauss-Legendre quadrature](https://en.wikipedia.org/wiki/Gauss%E2%80%93Laguerre_quadrature).

```matlab
[x, w] = gausLegHC(n)
```

By default, values are stored for $n=1,\ldots,100$ point quadrature rules. If $n$ is provided which exceeds this, [`computeGauss`](computeGauss.md) is called to construct weights and nodes from scratch.

You can adjust the number of hard-coded values to any number you choose by running [`hardCodeQuadratureGauleg`](hardCodeQuadratureGauleg.md); be warned - this will overwrite the function file `gausLegHC.m`

## Inputs

`n` is the number of quadrature points

## Outputs

* `x` : Quadrature nodes
* `w` : Quadrature weights