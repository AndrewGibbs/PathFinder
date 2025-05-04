# `plotGraph.m`

Produces a visual representation of the planar PathFinder graph. For more information about usage, see [Plotting](../../usage/basic.md#plotting).

```matlab
plotGraph(graphData, ballsArray, finiteEndpoints)
```

## Inputs

* `graphData` : A struct containing key information about the difference nodes of and edges of the graph. Most of this data is created in the shortest path step of the algorithm.
* `ballsArray` : Array of type [Ball](Ball.md).
* `finiteEndpoints` : A boolean array of length two; in each case, true if the first and second endpoints of the original are infinite respectively, otherwise false.