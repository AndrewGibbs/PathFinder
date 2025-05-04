# `plotAll.m`

The main plotting routine for PathFinder, used to produce its lovely plots. For more information about usage, see [Plotting](../../usage/basic.md#plotting).

```matlab
plotAll(balls, contours, quadPoints, a, b, infContour, stationaryPoints, polyCoeffs, valleys)
```

## Inputs

* `balls` : An array of type [`Ball`](Ball.md).
* `contours` : An array of type [`ContourSD`](ContourSD.md).
* `quadPoints` : An array of complex-valued quadrature points used in the final approximation.
* `a` and `b`: The endpoints of the original integral.
* `infContour` : Information about which of `a` and `b` correspond to unbounded endpoints (in which case they should not be plotted).
* `stationaryPoints` : An array of stationary points, where the phase function $g'$ vanishes.
* `polyCoeffs` : Coefficients of the polynomial phase function $g$.
* `valleys` : A vector of unitary complex values pointing towards the valleys of the phase function $g$.