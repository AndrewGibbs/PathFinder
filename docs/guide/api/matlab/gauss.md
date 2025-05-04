# `gauss.m`

Produces a [[Gauss quadrature rule](https://en.wikipedia.org/wiki/Gaussian_quadrature)] for an orthogonal polynomial with a given [three term recurrence](https://en.wikipedia.org/wiki/Orthogonal_polynomials#Recurrence_relation).

Given a weight function $w$ encoded by the $n \times 2$ array `ab` of the 
first $n$ recurrence coefficients for the associated orthogonal
polynomials — the first column of `ab` containing the $n$ $\alpha$-coefficients, 
and the second column the $n$ $\beta$-coefficients — the call:

```matlab
xw = GAUSS(n, ab)
```

generates the nodes and weights $xw$ of the $n$-point Gauss quadrature 
rule for the weight function $w$.

## Inputs

* `n` : The number of weights and nodes required.
* `ab` : The first column of `ab` contains the $n$ $\alpha$ recurrence coefficients, 
and the second column the $n$ contains $\beta$ recurrence coefficients

## Outputs

* `xw` : A $n \times 2$ array. The nodes (in increasing order) are stored in the first column, and the $n$ corresponding weights are stored in the second column.