# `sdPathODEeulerExtendCoarsePath.m`

This subroutine extends steepest descent contour approximation produced by [sdPathODEeuler.m](sdPathODEeuler.md) into the region of no return. This may
be required to allocate a sufficiently large number of quadrature points.

```matlab
[pArrayOut, hArrayOut, success] = ...
    sdPathODEeulerExtendCoarsePath(pIn, hIn, phaseCoeffs, SPs, ...
    baseStepSize, maxPts, pNewMax)
```

All paths $h_\eta(p)$ are initially approximated in [sdPathODEeuler.m](sdPathODEeuler.md), until $p=P$, where the path has reached either another ball, or a region of no return. In the case of the latter, this routine extends this to an approximation to $h(p)$ for $p\leq P'$, where $P'>P$ is now determined by the largest parameter value required by the underlying Gauss Laguerre rule. If there $N$ points approximating the path $h_\eta$ at the start of the routine, there will be $N'>N$ points at the end of the routine. A thorough explanation can be found in {cite:p}`PFpaper`, Section 2.6.2.

## Inputs

* `pIn` : The coarse path parameter points $p_1,\ldots,p_N$.
* `hIn` : The coarse path points $h_1\approx h_\eta(p_1),\ldots,h_N\approx h_\eta(p_N)$.
* `phaseCoeffs` : The coefficients of the phase function $g$.
* `SPs` : An array $\mathcal{P}_{\mathrm{stat}}:=\{\xi:g'(\xi)=0\}$
* `baseStepSize` : Scales the step in $p$ of the Euler method. 
* `maxPts` : The algorithm terminates early when this number of points is reached.
* `pNewMax` : The value $P'$.

## Outputs

* `pArrayOut`: The new values $p_j\in[0,P']$ for $j=1,\ldots,N'$.
* `hArrayOut` : The new values $h_j\approx h_\eta(p_j)$ for $j=1,\ldots,N'$.
* `success` : True if the algorithm did not terminate early, i.e. by reaching `maxPts` points.