# `sdPathODEeuler.m`

Uses [forward Euler](https://en.wikipedia.org/wiki/Euler_method) to approximate the steepest descent path $h_\eta(p)$ for $p\in[0,P]$. The approximate path is traced until either it reaches a non-oscillatory ball, or a region of no return.

The function approximates the steepest descent path $h(p)$ by $h_j:=h(p_j)$ at $p_j\in[0,P]$ for $j=1,\ldots,N$, with with initial condition $h_1=\eta$.

As errors can accumulate in forward Euler methods, a [Newton iteration](https://en.wikipedia.org/wiki/Newton%27s_method) is performed every few steps to ensure the approximate path does not get too far from the true path. The cost function is 
$$
C(h_j; p_j) = g(h_j) - \eta - \mathrm{i}p_j,
$$
where $g$ is the polynomial phase function of the original integral.

This follows immediately from the formula for a steepest descent path
$$
g(h_\eta(p)) = h_\eta(0) + \mathrm{i}p.
$$

We don't require high accuracy of the paths $h_\eta$ at this stage, the purpose of this function is to understand the large-scale contour behaviour, how they connect, etc. There is a more accurate refinement of a subset of these SD paths later on, in [sdQuadODEeulerCorrection.m](sdQuadODEeulerCorrection.md), which is used to compute quadrature points along the true steepest descent paths.

There are two ways this algorithm can termine:
1. By entering a non-oscillatory ball. This is determined by [inAball.m](inAball.md)
2. By entering a region of no return. This is determined by [beyondNoReturn.m](beyondNoReturn.md)

For more details, see `cite:p`{PFpaper}

```matlab
[pArrayOut, hArrayOut, valleyIndex, ballIndex] = ...
    sdPathODEeuler(pathStartPoint, phaseCoeffs, stationaryPointArray, ...
        ballRadiiArray, valleysArray, baseStepSize, pointCacheSize, rStar,...
        newtonSmallThreshold, newtonBigThreshold)
```

## Inputs

* `pathStartPoint`: The start point of the SD path $\eta:=h_\eta(0)$.
* `phaseCoeffs`: Coefficients of the phase function $g$.
* `stationaryPointArray`: An array  $\mathcal{P}_{\mathrm{stat}}:=\{\xi:g'(\xi)=0\}$
* `ballRadiiArray` : An array of radii of the balls $\Omega_\xi$, indexed consistently with the centres of the correpsonding stationary points in `stationaryPointArray`.
* `valleysArray` : Array of valleys of the phase function $g$.
* `baseStepSize`: Scales the step in $p$ of the Euler method.
* `pointCacheSize` : The default size of the arrays `pArrayOut` and `hArrayOut`. This will be increased in multiples of `pointCacheSize` if required, and truncated to only contain relevant information at the end of the function.
* `rStar`: A constant dependent on $g$, stored to save repeated computations. This is the solution of a polynomial equation, details are given in section 2.4 of {cite:p}`PFpaper`.
* `newtonSmallThreshold` : The value of the cost function $C(h_j; p_j)$ when an accurate Newton correction is performed. This happens when the final point of an SD path enters a ball - it is impoprtant that this value is very accurate.
* `newtonBigThreshold` : The value of the cost function $C(h_j; p_j)$ when a less accurate Newton correction is performed.

## Outputs

* `pArrayOut`: The values $p_j\in[0,P]$ for $j=1,\ldots,N$ at which $h_j:=h(p_j)$ is approximated.
* `hArrayOut` : The values $h_j:=h(p_j)$ for $j=1,\ldots,N$.
* `valleyIndex` : Index of the valley that $h_\eta(p)$ converges to. Otherwise empty.
* `ballIndex` : Index of the first non-oscillatory ball that $h_\eta(p)$ enters. Otherwise empty.