# `bisection.m`

This is a bisection method, specifically designed to determine when rays intersect a
contour such that $\omega|g(z)-g(\xi)|=C$, where $g$ is the phase function, $\omega$ is the frequency parameter and $\xi$ is a stationary point.

The function to minimise is therefore

$$
f(r) = \omega|g(\xi + r\mathrm{e}^{\mathrm{i}\theta})-g(\xi)| - C,
$$

and we're seeking $f(r)=0$ for some $r\in[a,b]$ (here $a$ and $b$ are **not** the original integration endpoints.)

This function will only be called when the main rootfinding algorithm (which uses a companion matrix approach) fails.

```matlab
[r, numIterations] = bisection(f, a, b, tol)
```
## Inputs
* `f` is the function $f$ defined above
* `a` and `b` correspond to the search range $[a,b]$
* `tol` is the parameter which determines when the bisection method will halt, specifically when $|f(c)|<$`tol`.

## Outputs
* `c` is the zero of $f$, as defined above.
* `numIterations` is the number of iterations that the bisection method ran for.