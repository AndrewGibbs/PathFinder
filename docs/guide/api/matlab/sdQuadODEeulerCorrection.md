# `sdQuadODEeulerCorrection.m`

This subroutine takes a coarse path approximation $h_j$ for $j=1,\ldots, N$, and refines it to produce quadrature nodes which are (to a high accuracy) on the true steepest descent path. The input `pQuad` typically corresponds to Gaussian quadrature nodes on $[0,\infty]$, and this algorithm interpolates between the existing parameter points $p_j$, stored in `pCoarse`, and refines the corresponding points on the path $h_j$ via a Newton iteration.

As in the coarse path approximation, a Newton iteration is used to refine the quadrature points. However, here, this is to a higher accuracy.

The cost function is now, for quadrature point $p^*_j$,

$$
C(h^*_j; p^*_j) = \omega g(h_j) - \eta - \mathrm{i}p^*_j,
$$

where $g$ is the polynomial phase function of the original integral.

This follows immediately from the(frequency-dependent) formula for a steepest descent path

$$
g(h_\eta(p)) = \omega h_\eta(0) + \mathrm{i}p.
$$


```matlab
[hQuadArray, dhdpQuadArray, newtonStepsToConverge] = ...
            sdQuadODEeulerCorrection(pQuad, pCoarse, h0, ...
            hCoarse, phaseCoeffs, freq, newtonThresh, maxNumNewtonIts)
```

## Inputs

* `pQuad` : The points $p$ at which we would like to know $h_\eta(p)$, for our quadrature rule.
* `pCoarse` : The $p$ parameter values from the coarse approximation of the SD path.
* `h0` : The starting point $\eta$.
* `hCoarse` : The points of the coarse path approximation.
* `phaseCoeffs` : The coefficients of the phase function $g$.
* `freq` : The frequency parameter $\omega$ in the original integral.
* `newtonThresh` : The accuracy desired for the residual error in the Newton iteration.
* `maxNumNewtonIts` : The maximum number of Newton iterations permitted for each quadrature point, before giving up.

## Outputs

* `hQuadArray` : Quadrature points $h^*_j$ along the steepest descent path.
* `dhdpQuadArray` : Gradient of the path at each $h^*_j$, approximately $h'_\eta(p^*_j)$. This is required for the Jacobian in the contour integral evaluateion.
* `newtonStepsToConverge` : The number of steps each quadrature point took to converge.