# `logQuadratureDetails.m`

Records key information about the construction of the quadrature points in the final stage of PathFinder.

```matlab
logQuadratureDetails(params, netwonIterationData, quadToc)
```

## Inputs

* `params` : A struct containing information about which information is to be logged.
* `netwonIterationData` : An array containing information about the number of Newton iterations each quadrature point needed to converge.
* `quadToc` : An array, containing the times taken to construct the quadrature points, given the coarse path approximations.