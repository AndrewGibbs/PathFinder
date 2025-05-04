# `linearPhaseNSD.m`

In the special case where $g$ is an affine function $g(z)=m z + n$, and the endpoints of the original integral $a,b$ are finite, this function which produces steepest descent contours. This is a simple special case where the steepest descent deformation consists of two parallel straight lines, and therefore does not require the PathFinder algorithm for robustness, as there are no stationary points present.

Mathematically, this should be interpreted as:

$$
\int_a^b f(z) \mathrm{e}^{\mathrm{i}\omega [mz+c]}\mathrm{d}z \approx \sum_{j=1}^N f(z_j)w_j
$$


```matlab
[z,w] = linearPhaseNSD(a, b, freq, m, c, numPts)
```

## Inputs

* `a` and `b` are the finite endpoints of the contour integral.
* `freq` : The frequency parameter $\omega$.
* `m` : The linear coefficient $m$.
* `c` : The constant coefficient $c$.
* `numPts` : The number of quadrature points per contour. This will be half of $N$.

## Outputs

* `z` : Quadrature nodes.
* `w` : Quadrature weights.