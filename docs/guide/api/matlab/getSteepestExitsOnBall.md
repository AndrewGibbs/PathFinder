# `getSteepestExitsOnBall.m`

Determines the *exits* on a ball, by reformulating as a trigonometric polynomial
rootfinding problem. *Exits* are introduced in {cite:p}`PFpaper`, but this algorithm is not described there. An explanation of this algorithm can be found in [these extra notes](../../theory/rootfinding.md#finding-the-exits-on-the-circumference-of-the-ball).

```matlab
SEs = getSteepestExitsOnBall(phaseCoeffs, centre, radius)
```

## Inputs

* `phaseCoeffs` : Array of coefficients of the phase function $g$.
* `centre` : Centre of the non-oscillatory ball.
* `radius` : Radius of the non-oscillatory ball.

## Outputs

* `SEs` : An array of exits on the circumference of the non-oscillatory ball.