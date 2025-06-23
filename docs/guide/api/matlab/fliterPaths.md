# `fliterPaths.md`

Some contour integrals will have a negligible value compared to others.
This function removes those contours from the sequence, so quadrature points are only allocated along non-negligable conoturs.

Here, information about each contour corresponds to a different *quadrature ingredient* stored in `QuadIngredientArray`. This is an array of structs, each corresponding to a steepest descent path, or straight line segment, which forms the path deformation of $\gamma$.

Each component of `QuadIngredientArray` is measured at a few points to estimate its magnitude. Steepest descent paths are measured at their largest / first point, whereas straight line segments are measured at their endpoints *and* the stationary points of the balls that they intersect. A path is considered negligable if its estimated magnitude is sufficiently small compared with the largest estimated magnitude.



```matlab
[QuadIngredientArrayOut, maxIntegrand] =...
            fliterPaths(QuadIngredientArray, phaseFunction, freq, thresh)
```

## Inputs

* `QuadIngredientArray` : An array of structs, each corresponding to a steepest descent path, or straight line segment, which forms the path deformation of $\gamma$,
* `phaseFunction` : The phase function $g$ of the original integral.
* `freq` : The frequency $\omega$ of the original integral.
* `thresh` : The threshold below which integrals are considered negligable.

## Outputs

* `QuadIngredientArrayOut` : A subset of `QuadIngredientArray`, consisting only of non-negligable paths.
* `maxIntegrand` : The largest estimated value of all the steepest descent paths.