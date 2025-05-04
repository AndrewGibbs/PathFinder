# `plotMain.m`

This is the main plotting function, which calls either of [`plotAll`](plotAll.md) (for standard PathFinder plots) and [`plotGraph`](plotGraph.md) (for graph plots) as required.

```matlab
plotMain(params, covers, contourArray, z, a, b, stationaryPoints,...
    phaseIn, valleys, GraphData)
```

## Inputs

* `params` : The main struct of parameters which contains plotting information, about which types of plots are requested.
* `covers` : An array of type [`Ball`](Ball.md).
* `contourArray` : An array of type [`ContourSD`](ContourSD.md).
* `z` : The quadrature points.
* `a` and `b` : The endpoints of the original integral.
* `stationaryPoints` : Stationary points of the phase function $g$. Significantly, they are the centres of each non-oscillatory ball.
* `phaseIn` : The phase function $g$.
* `valleys` : The valleys of the phase function $g$.
* `GraphData` : Adjacency and other information about the underlying graph, obtained earlier in the algorithm.