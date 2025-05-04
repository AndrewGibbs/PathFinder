# `planBisection.m`

If the companion matrix approx fails to find a radius in [getRGivenTheta.m](getRGivenTheta.md), plan B is to use this [bisection approach](https://en.wikipedia.org/wiki/Bisection_method). The initial guesses are the positive real parts from the roots of the companion matrix approach; their imaginary parts were deemed too large in magnitude for them to be trustworthy.

```matlab
[root, isSuccess] = planBisection(phaseCoeffs, xi, numOscsDivByFreq, theta, guesses)
```

## Inputs

* `phaseCoeffs` : An array of coefficients of the polynomial phase function $g$.
* `xi` : The centre of the non-oscillatory ball.
* `numOscsDivByFreq` : This is $C/\omega$ in [getRGivenTheta.m](getRGivenTheta.md).
* `theta` : The angle of the ray.
* `guesses` : Initial guesses to consider for multiple bisection approaches.

## Outputs

* `root` : The result of the bisection method.
* `isSuccess` : Boolean, true if the bisection method found a root.