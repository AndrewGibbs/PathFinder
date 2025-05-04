# `logQuadratureDetails.m`

Records key information about the construction of the quadrature points in the final stage of PathFinder.

```matlab
logQuadratureDetails(params, netwonIterationData, quadToc)
```

## Inputs

* `params` : Information about which information is to be logged.
* `netwonIterationData` : Information about the number of Newton iterations each quadrature point needed to converge.
* `quadToc` : The time taken to construct the quadrature points, given the coarse path approximations.