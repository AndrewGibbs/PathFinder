# `checkEndpointWidth.m`

Determines if an integral over a bounded contour can be considered non-oscillatory.

As described in the paper {cite:p}`PFpaper`, this is a preliminary step to determine if the original integral can be considered non-oscillatory. To achieve this, we place temporary balls around both endpoints $\{a,b\}$, based on the same criteria used to determine radii throughout the algorithm. If the balls overlap, this is an indication that there are only a few oscillations between the endpoints.

```matlab
isOverlapping = checkEndpointWidth(a, b, phaseCoeffs, freq, numOscs, numRays, isInteriorBal, imagThresh, useMex)
```

## Inputs
* `a` and `b` are the endpoints of the original integral
* `phaseCoeffs` is a vector of coefficients of the polynomial phase function in the original integral
* `freq` is the frequency parameter of the original integral
* `numOscs` is the parameter which governs the size of the balls; the larger this value, the more oscillations are permitted inside of the balls.
* `numRays` the number of rays fired from the endpoints $\{a,b\}$ when determining the non-oscillatory ball around them.
* `isInteriorBal` is a boolean flag which determines if the non-oscillatory ball contains the non-oscillatory region, or is contained within it. Practically, it corresponds to choosing the shortest ray (interior) or the longest ray (exterior) which intercepts the boundary of the non-oscillatory region in the bisection method.

## Outputs
* `isOverlapping` is a boolean flag, true if the non-oscillatory balls around the endpoints $a$ and $b$ overlap. 