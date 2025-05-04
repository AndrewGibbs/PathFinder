# `ContourSD.m`

A Matlab class designed to represent steepest descent contours. Recall that a steepest descent contour $h_\eta(p)$ starts at the point $h_\eta(0)=\eta$, and follows the path such that $g(h_\eta(p))=\mathrm{i}p$. Along such a path, the integrand of our original integral is exponentially decaying as $p$ increases.

These contours can be finite or infinite, but in practice they must be approximated for finite values of $p$.

## Properties

* `startPoint`: Start of approximate contour, i.e. an *exit*. This is denoted $\eta$ in {cite:p}`PFpaper`.
* `endPoint`: End of approximate contour.
* `startCoverIndex`: Index of the ball in which contour starts.
* `endCoverIndex`: (Possible) index of ball where contour ends. Can be blank.
* `coarsePath`: Array of complex points approximating contour $h_\eta$.
* `coarseParam`: Parameter $p>0$ in $h_\eta(p)$, corresponding to above array.
* `length`: max value of the parameter $p$, can be infinite for infinite paths.
* `endValley`: (Possible) valley where path converges. Can be blank.
* `phaseCoeffs`: Coefficients of polynomial phase function $g$.
* `phaseDerivs`: Coefficients of derivatives of polynomial phase function $g'$.
* `ICs`: initial conditions for ODE solve, $(h_\eta(0), h_\eta'(0))$

## Methods

### `plot`

This plots the approximate contour.

### `getQuad`

This produces a quadrature rule along a given contour.

```matlab
[hArray, wArray, newtonSuccess] = getQuad(self, freq, numPts, QuadParams)
```

#### Inputs

* `freq`: The frequency parameter $\omega$
* `numPts`: The number of desired quadrataure points along the contour, $N$.
* `QuadParams`: A structure containing parameters for the quadrature rule; the approximation of the quadrature points, the type of quadrature, etc.

#### Outputs

* `hArray`: $N$ quadrature points
* `wArray`: $N$ quadrature weights
* `newtonSuccess`: a boolean array of length $N$, each entry is true if the Newton iteration converged for the corresponding quadrature point.