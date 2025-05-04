# `gausLagHC.m`

A lookup function containing many hard-coded values for [Gauss-Laguerre quadrature](https://en.wikipedia.org/wiki/Gauss%E2%80%93Laguerre_quadrature).

```matlab
[x, w] = gausLagHC(n)
```

By default, values are stored for $n=1,\ldots,100$ point quadrature rules. If $n$ is provided which exceeds this, [`quadGaussLaguerre(n)`](quadGaussLaguerre.md) is called to construct weights and nodes from scratch.

You can adjst the number of hard-coded values to any number you choose by running [`hardCodeQuadratureGaulag`](hardCodeQuadratureGaulag.md); be warned - this will overwrite the function file `gausLagHC.m`

## Inputs

`n` is the number of quadrature points

## Outputs

* `x` : Quadrature nodes
* `w` : Quadrature weights