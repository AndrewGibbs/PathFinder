# `inAball.m`

Given a collection of balls $\Omega_\xi$ for centres $\xi\in\mathcal{P}_{\mathrm{stat}}$, each with radius $r_\xi$, this algorithm determines if

$$
h \in \cup_{\xi\in\mathcal{P}_{\mathrm{stat}}}\Omega_\xi.
$$

This algorithm is used when approximating the steepest descent path $h_\eta(p)$ for increasing values of $p$; we want to terminate the path approximation process if $h_\eta(p)\in \Omega_\xi$ for some $\xi\in\mathcal{P}_{\mathrm{stat}}$.

```matlab
[isInBall, outputIndex] = inAball(h, ballCentres, ballRadii)
```

## Inputs

* `h`: The point being tested, typically the farthest point of the contour being traced.
* `ballCentres`: Array of centres of balls $\xi\in\mathcal{P}_{\mathrm{stat}}$.
* `ballRadii`: Array of radii of balls $r_\xi$ for $\xi\in\mathcal{P}_{\mathrm{stat}}$.

## Outputs

* `isInBall`: Boolean value, true if $h$ is inside of any ball.
* `outputIndex`: If `isInBall`, then this is the index of $\xi$ in `ballCentres`. Otherwise, this value is zero.