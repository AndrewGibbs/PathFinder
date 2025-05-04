# `quadGaussLaguerre.m`

Via the [Golub-Welsch](https://en.wikipedia.org/wiki/Gaussian_quadrature#The_Golub-Welsch_algorithm) algorithm, this subroutine constructs and returns an $n$-point [Gauss-Laguerre](https://en.wikipedia.org/wiki/Gauss%E2%80%93Laguerre_quadrature) rule.

```matlab
[x,w] = quadGaussLaguerre(n)
```

## Inputs

`n` is the number of weights and nodes required.

## Outputs

* `x` : Gauss-Laguerre nodes.
* `w` :  Gauss-Laguerre weights.