# `bisection.m`

This is a bisection method, specifically designed to determine when rays intersect a
contour such that $\omega|g(z)-g(\xi)|=C$, where $g$ is the phase function, $\omega$ is the frequency parameter and $\xi$ is a stationary point.

The function to minimise is therefore
$$
f(c) = \omega|g(\xi + r\mathrm{e}^{\mathrm{i}\theta})-g(\xi)| - C,
$$
and we're seeking $f(c)=0$ for some $c\in[a,b]$

This function will only be called when the main rootfinding algorithm (which uses a companion matrix approach) fails.

```matlab
[c, numIterations] = bisection(f, a, b, tol)
```
## Inputs
* `f` is the function $f$ defined above
* `a` and `b` correspond to the search range $[a,b]$
* `tol` is the parameter which determines when the bisection method will halt, specifically when $|f(c)|<$`tol`.

## Outputs
* `c` is the zero of $f$, as defined above.
* `numIterations` is the number of iterations that the bisection method ran for.