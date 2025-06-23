# `makeQuad.m`

This routine pieces together all the quadrature *ingredients* describing the sequence of SD and straight line contours, and allocates quadrature points along them.

```matlab
[z, w, logOut] = makeQuad(quadIngredients, freq, numPts, phaseFunction, params)
```

## Inputs

* `quadIngredients` : An array of structs, each containing information about a component of the steepest descent deformation.
* `freq` : The frequency parameter $\omega$
* `numPts` : The number of 
* `phaseFunction` : The the phase function $g$
* `params` : A struct of appoximation parameters, many of which are determined in [`optionalExtras`](optionalExtras.md).

## Outputs

* `z` : The quadrature nodes.
* `w` : The quadrature weights.
* `logOut` : Logged information about the number of Newton iterations required for each quadrature point. This is not recorded by default - see [Advanced Usage](../../usage/advanced.md) for more information.