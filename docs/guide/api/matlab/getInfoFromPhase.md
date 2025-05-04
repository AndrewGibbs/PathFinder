# `getInfoFromPhase.m`

Given the coefficients of the phase function $g$, this routine calls several other routines which compute key information. See the outputs below for details about what is computed.

```matlab
[phaseHandle, stationaryPoints, valleys] = getInfoFromPhase(phaseCoeffs)
```

## Inputs

`phaseCoeffs` is an array of coefficients of the polynomial phase function $g$.

## Outputs

* `phaseHandle` : A function handle for the phase function $g$. This is comparatively simple to construct - no mathematics is required.
* `stationaryPoints` : The stationary points of $g$, i.e. points where $g'=0$.
* `valleys` : Valleys of the phase function $g$, i.e. directions in which the exponential decay of the integrand is as fast as possible.