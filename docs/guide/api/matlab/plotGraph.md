# `plotGraph.m`

Produces a visual representation of the planar PathFinder graph. For more information about usage, see [Plotting](../../usage/basic.md#plotting).

```matlab
plotGraph(graphData, ballsArray, finiteEndpoints)
```

## Inputs

* `graphData` : An array of structs containing key information about the nodes and edges of the graph. Most of this data is created in the [`shortestInfinitePath.m`](shortestInfinitePath.md) routine.
* `ballsArray` : Array of type [Ball](Ball.md).
* `finiteEndpoints` : A boolean array of length two; in each case, true if the first and second endpoints of the original are infinite respectively, otherwise false.