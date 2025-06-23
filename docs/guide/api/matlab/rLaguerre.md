# `rLaguerre.m`

`ab = rLaguerre(n, a)` generates the first $n$ recurrence coefficients for the monic generalized [Laguerre polynomials](https://en.wikipedia.org/wiki/Laguerre_polynomials) 
with parameter $a$. These polynomials are orthogonal on $[0, \infty)$ relative 
to the weight function

$$
w(t) = t^a e^{-t}.
$$

The $n$ $\alpha$-coefficients are stored in the first column, and the 
$n$ $\beta$-coefficients in the second column of the $n \times 2$ array `ab`.

The call `ab = rLaguerre(n)` is the same as `ab = rLaguerre(n, 0)`.

```matlab
ab=rLaguerre(N,a)
```

## Inputs

* `N` : The number of quadrature points.
* `a` : The power in the above equation, $a$.

## Outputs

`ab` is an $n \times 2$ array `ab` of recurrence coefficients.