# `PathFinderQuad.m`

One of the two main functions. This function takes information about the oscillatory integral
$$
I = \int_\gamma f(z)\mathrm{e}^{\mathrm{i}\omega g(z)}\mathrm{d} z
$$
and returns weights $w_j$ and nodes $z_j$ such that
$$
I \approx \sum_{j=1}^N f(z_j)w_j
$$

```matlab
[z,w] = PathFinderQuad(a, b, phaseIn, freq, nPts, varargin)
```

## Inputs
* `a` and `b` are the endpoints of the integration contour $\gamma$.
* `phaseIn` : Coefficients of the polynomial phase function $g$.
* `freq` : The frequency parameter $\omega$.
* `nPts` : The number of quadrature points *per contour*. 
* `varargin` : This function takes many optional inputs, which can modify approximation parameters, and request plots. For more information, see [Usage](../../usage/index.md).

## Outputs
* `z` : Nodes $z_j$.
* `w` : Weights $w_j$.