# `sdQuadODEeulerCorrection.m`

Once the paths have been approximated, and a suitable subsequence of paths has been selected as the deformation of the original path $\gamma$, we must allocate quadrature points along this deformation. At this point, we have only a coarse approximation along this deformation, at certain points, which do not have any particular meaning - they were chosen as part of the forward Euler routine, but do not necessarily correspond to a quadrature rule.

Therefore, this routine does two things:
* Interpolates between points on the coarse path, at points corresponding to a quadrature rule.
* Improves the accuracy at these meaningful points, thus improving the accuracy of the underlying quadrature rule.

This subroutine takes a coarse path approximation $h_j$ for $j=1,\ldots, N$, and refines it to produce quadrature nodes which are (to a high accuracy) on the true steepest descent path. The input `pQuad` typically corresponds to Gaussian quadrature nodes on $[0,\infty)$, and this algorithm [interpolates linearly](https://en.wikipedia.org/wiki/Linear_interpolation) between the existing parameter points $p_j$, stored in `pCoarse`, and refines the corresponding approximate $h_j\approx h_\eta(p_j)$ via a Newton iteration, to a more accurate approximation at specified points $h^*_i\approx h_\eta(p_i^*)$, for $i=1,\ldots,N^*$.


```matlab
[hQuadArray, dhdpQuadArray, newtonStepsToConverge] = ...
            sdQuadODEeulerCorrection(pQuad, pCoarse, h0, ...
            hCoarse, phaseCoeffs, freq, newtonThresh, maxNumNewtonIts)
```

As in the coarse path approximation, a Newton iteration is used to refine the quadrature points. However, here, this is to a higher accuracy.

The cost function is now, for quadrature point $p^*_i$,

$$
C(h^*_i; p^*_i) = \omega g(h^*_i) - \eta - \mathrm{i}p^*_i,
$$

where $g$ is the polynomial phase function of the original integral.

This follows immediately from the(frequency-dependent) formula for a steepest descent path

$$
g(h_\eta(p)) = \omega h_\eta(0) + \mathrm{i}p.
$$

More information about this process can be found in {cite:p}`PFpaper`

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

* `hQuadArray` : Quadrature points $h^*_i$ along the steepest descent path.
* `dhdpQuadArray` : Gradient of the path at each $h^*_i$, approximately $h'_\eta(p_i^*)$. This is required for the Jacobian in the contour integral evaluation.
* `newtonStepsToConverge` : The number of steps each quadrature point took to converge.