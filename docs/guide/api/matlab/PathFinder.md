# `PathFinder.m`

One of the two main functions. This function takes information about the oscillatory integral
$$
I = \int_\gamma f(z)\mathrm{e}^{\mathrm{i}\omega g(z)}\mathrm{d} z
$$
and returns an approximation to $I$. This is essentially a wrapper for the quadrature rule [PathFinderQuad.m](PathFinderQuad.md), which applies it to the integral with $f$.

```matlab
I = PathFinder(a, b, f, phaseIn, freq, nPts, varargin)
```

## Inputs
* `a` and `b` are the endpoints of the integration contour $\gamma$.
*  `f` : A functon handle representation of $f(z)$. If left blank `f=[]`, then PathFinder assumes $f(z)=1$.
* `phaseIn` : Coefficients of the polynomial phase function $g$.
* `freq` : The frequency parameter $\omega$.
* `nPts` : The number of quadrature points *per contour*. 
* `varargin` : This function takes many optional inputs, which can modify approximation parameters, and request plots. For more information, see [Usage](../../usage/index.md).

## Outputs
* `z` : Nodes $z_j$.
* `w` : Weights $w_j$.