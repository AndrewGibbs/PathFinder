# `getExteriorBalls.m`

This function performs many important topological operations at an early stage of the PathFinder algorithm, by calling more specialised subroutines. Here is a high level overview:
* Stationary points of the phase function $g$ are determined.
* These stationary points are merged, if they are sufficiently close.
* Balls are placed around each of these stationary points, such that the interior of the ball may be considered *non-oscillatory*.
* Upon creation of each ball, *exits* are placed around the circumference. Any exit inside another ball is immediately deleted.

```matlab
[covers, endPointIndices]...
                = getExteriorBalls(phaseFn, freq, stationaryPointArray, ...
                    isInfEndptArray, a, b, Cosc, phaseCoeffs, ...
                    ballMergeTol, numRays, isInteriorBalls, imagThresh, ...
                    useMex)
```

## Inputs

* `phaseFn`: A function handle for the polynomial phase $g(z)$.
* `freq`: The frequency parameter $\omega$.
* `stationaryPointArray`: Stationary points of $g$, i.e. $\xi$ where $g'(\xi)=0$.
* `isInfEndptArray`: A boolean array of length two, describing if the endpoints $a$ and $b$ are infinite
* `a`: The endpoint $a$. If finite, this is a the position in $\C$; if infinite, this is the complex angle $\theta$ such that $a=\exp(\mathrm{i}\theta)$.
* `b`: The endpoint $b$, defined analogously to $a$ above.
* `Cosc`: The parameter corresponding to the number of oscillations.
* `phaseCoeffs`: Coefficients of the polynomial phase function $g$.
* `ballMergeTol`: Parameter that decides how close stationary points must be to be *merged*.
* `numRays`: The number of angles to divide each ball when determining an appropriate radius. See (#getSmallestSupsetBall) for more information.
* `isInteriorBalls`: Also a parameter used by (#getSmallestSupsetBall).
* `imagThresh`: Size of permitted imaginary component in polynomial rootfinding process, see (#getRGivenTheta).
* `useMex`: Boolean, true if MEX version of rootfinding code is to be used.

## Outputs

* `covers` is a cell array of objects of `Ball` type.
* `endPointIndices` are the indices of the cell array corresponding to balls centred at finite endpoints. For example, if $\{a,b\}$ are finite, `endPointIndices` is $[1,2]$.