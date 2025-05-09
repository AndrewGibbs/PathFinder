# `getSmallestSupsetBall`

As part of the algorithm, we determine *non-oscillatory* balls. These are chosen roughly such that

$$
\omega|g(z)-g(\xi)| \leq C_{\mathrm{ball}}
$$

where $\xi$ is the centre of the ball, and $z$ is any point inside the ball. Clearly the region $\Omega$ where this holds is not a ball - we choose either the smallest ball containing $\Omega$, or the largest ball inside $\Omega$, determined by `isLargestBall`.

This subroutine finds a single non-oscillatory ball. Specifically, given the centre of the ball, and information about the phase and frequency, the algorithm determines the radius.

```matlab
r = getSmallestSupsetBall(phaseCoeffs, freq, stationaryPoint, ...
                                    numOscs, numRays, isLargestBall, ...
                                    imag_thresh)
```

## Inputs

* `phaseCoeffs`: Coefficients of the phase function $g$
* `freq`: Frequency parameter $\omega$
* `stationaryPoint`: The stationary point $\xi$ at the centre of the ball
* `numOscs`: An approximate number of oscillations permitted inside of the ball, denoted $C_{\mathrm{ball}}$
* `numRays`: The number of angles at which the rootfinding algorithm `getRGivenTheta` is performed.
* `isLargestBall`: Boolean parameter, if true, we choose the largest ball at which the cost function is minimised.
* `imag_thresh`: A threshold for which roots are considered to be imaginary.

## Outputs

`r` is the radius of the ball.