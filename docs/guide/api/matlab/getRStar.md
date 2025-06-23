# `getRStar.m`

Routine to determine $r_*$, as described in {cite:p}`PFpaper`, section 2.4. The parameter $r_*$ is used to determine *no return* regions at later stages of the algorithm.

```matlab
rStar = getRStar(phaseCoeffs, theta)
```

## Inputs
* `phaseCoeffs` : The coefficients of the phase function $g$.
* `theta` : Adjusts the polynomial equation to be solved, based on the leading order coefficient of $g$.

## Outputs

`rStar` is $r_*$