#

Given a ray from $\xi$, in direction $\theta$, find $r$ at which the ray
intersects the boundary of the closed contour bounding the non-oscillatory
region, i.e.:

$$
|g(\xi)-g(\xi+r\exp(\mathrm{i}\theta)|=C/\omega
$$

This algorithm is **not** explained in {cite:p}`PFpaper`. An explanation can be found in [these extra notes](../../theory/rootfinding.md#finding-the-intersection-of-rays-with-the-boundary-of-the-non-oscillatory-region).

```matlab
r = getRGivenTheta(phaseCoeffs, centre, cballOverOmega, theta, imag_thresh)
```

## Inputs

* `phaseCoeffs` : The coefficients of the phase function $g$.
* `centre` : The centre of the ball $\xi$.
* `cballOverOmega` : The value of $C/\omega$ above.
* `theta` : The angle $\theta$ of the ray.
* `imag_thresh` : The tolerance for an imaginary part of a radius before it should be considered purely imaginary, and thus *not* a valid radius.

## Outputs

`r` is he length $r$ of the ray, such that the above equation holds.