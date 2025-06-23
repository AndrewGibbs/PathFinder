# `shortestInfinitePath.m`

Chooses a suitable sequence of steepest descent and straight line contours, which correspond to a deformation of the original integration contour from $a$ to $b$. This is done by representing the key topological properties of known quantities as a graph, and then solving a shortest
 path problem.

Specifically, for this graph:
balls, exits, entrances, endpoints and valleys are interpreted as nodes. Steepest descent contours (finite or infinite), and straight line contours connecting points inside balls, are represented as edges.
 The approach in this code is to create multiple [adjacency matrices](https://en.wikipedia.org/wiki/Adjacency_matrix) corresponding to the connections between different types of points (or
 valleys). These adjacency matrices are then combined, and we keep track
 of the different meanings of the different indices. This adjacency matrix
 is used to solve the shortest path problem.

 For more information, see {cite:p}`PFpaper`.

```matlab
[Q, graphData] = shortestInfinitePath(a, b, contours, balls, valleys, params)
```

## Inputs

* `a` and `b` : The enepoindts of the original contour.
* `contours` : An array of type [ContourSD.m](ContourSD.md)
* `balls` : An array of type [Ball.m](Ball.md)
* `valleys` : An array of valleys.
* `params` : A struct of approximation parameters.

## Outputs

* `Q` : Struct of quadrature ingredients, which contains all of the information about the chosen path deformation. From this, quadrature points are subsequently constructed.
* `graphData` : Simplified struct, used for plotting.