# `getBallDeets.m`

This function extracts relevant data from a cell array of [`Ball`](Ball.md) objects, in terms of numerical arrays, so that it can be passed to MEX functions.

```matlab
[ballCentres, ballRadii, nonEndpointBallCentres,  nonEndpointBallRadii] = getBallDeets(BallCellArray)
```

## Inputs

* `BallCellArray`, a cell array of objects in the [`Ball`](Ball.md) class.

## Outputs

* `ballCentres`: array of centres of every ball in `BallCellArray`
* `ballRadii`: array of radii of every ball in `BallCellArray`
* `nonEndpointBallCentres`: array of centres of every ball in `BallCellArray`, excluding those in finite endpoints of original integral
* `nonEndpointBallRadii`: array of radii of every ball in `BallCellArray`, excluding those in finite endpoints of original integral