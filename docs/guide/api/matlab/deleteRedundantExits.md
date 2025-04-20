# `deleteRedundantExits.m`

Sometimes, the *exit* from a *non-oscillatory ball* will start off inside another ball. These lead to creation of unnecessary short contours, and needless computations later on. This function deletes *exits* from the balls which start off inside the other balls, before contours are created.

```matlab
ballsOut = deleteRedundantExits(ballsIn)
```

## Inputs

`ballsIn` is a cell array of `Ball` objects. Specifically, this is the collection of balls *before* the exits have been deleted.

## Outputs

`ballsOut` is a cell array of `Ball` objects. This is the collection of balls `ballsIn`, *after* the exits have been deleted.