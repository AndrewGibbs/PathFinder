# `gaussQuadComplex`

Given a straight line segment $\gamma\subset\mathbb{C}$ with endpoints $a$ and $b$, this subtroutine produces a Gauss Legendre quadrature rule
$$
\sum_{j=1}^N w_j f(z_j) \approx \int_\gamma f(z) \mathrm{d}z .
$$

```matlab
[z,w,dz] = gaussQuadComplex(a,b,numPts)
```

## Inputs

* `a` and `b` : The endpoints of the straight line segment $\gamma$.
* `numPts` : The number of quadrature points, $N$ in the above approximation.

## Outputs

* `z` : The quadrature points $z_j$.
* `w` : The quadrature weights $w_j$.
* `dz` : An array of identical unit length complex numbers corresponding to the complex argument of $b-a$. 