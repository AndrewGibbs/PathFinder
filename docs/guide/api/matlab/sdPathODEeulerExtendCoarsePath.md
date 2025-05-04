# `sdPathODEeulerExtendCoarsePath.m`

This subroutine extends steepest descent contour approximation produced by [sdPathODEeuler.m](sdPathODEeuler.md) into the region of no return. This may
be required to allocate a sufficiently large number of quadrature points.

```matlab
[pArrayOut, hArrayOut, success] = ...
    sdPathODEeulerExtendCoarsePath(pIn, hIn, phaseCoeffs, SPs, ...
    baseStepSize, maxPts, pNewMax)
```

## Inputs

* `pIn` : The coarse path parameter points $p_1,\ldots,p_N$.
* `hIn` : The coarse path points $h_1,\ldots,h_N$.
* `phaseCoeffs` : The coefficients of the phase function $g$.
* `SPs` : An array  $\mathcal{P}_{\mathrm{stat}}:=\{\xi:g'(\xi)=0\}$
* `baseStepSize` : Scales the step in $p$ of the Euler method. 
* `maxPts` : The algorithm terminates early when this number of points is reached.
* `pNewMax` : The value of the parameter $p$ such that we wish to extend $h(p)$ to.

## Outputs

* `pArrayOut`: The new values $p_j\in[0,P]$ for $j=1,\ldots,N$ at which $h_j:=h(p_j)$ is approximated.
* `hArrayOut` : The new values $h_j:=h(p_j)$ for $j=1,\ldots,N$.
* `success` : True if the algorithm did not terminate early, i.e. by reaching `maxPts` points.