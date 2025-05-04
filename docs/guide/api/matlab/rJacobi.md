# `rJacobi.m`

This subroutine generates the first $n$ recurrence coefficients for monic [Jacobi polynomials](https://en.wikipedia.org/wiki/Jacobi_polynomials) with parameters 
$a$ and $b$. These polynomials are orthogonal on $[-1, 1]$ relative to the
weight function 

$$
w(t) = (1 - t)^a (1 + t)^b.
$$

The $n$ $\alpha$-coefficients are stored in the first column, and the 
$n$ $\beta$-coefficients in the second column of the $n \times 2$ array `ab`.

The call `ab = rJacobi(n, a)` is the same as `ab = rJacobi(n, a, a)`, and  
`ab = rJacobi(n)` is the same as `ab = rJacobi(n, 0, 0)`.


```matlab
ab=rJacobi(N,a,b)
```

## Inputs

* `N` : The number of quadrature points.
* `a` : The first power in the above equation, $a$.
* `b` : The second power in the above equation, $b$.

## Outputs

`ab` is an $n \times 2$ array `ab` of recurrence coefficients.