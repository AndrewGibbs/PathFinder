# `Ball.m`

A class corresponding to non-oscillatory balls.

## Properties
* `radius`: Radius of the ball
* `centre`: Position of centre of ball
* `index`: Unique index of ball, likely corresponding to position in array down the stack.

## Methods

These methods are stored in their own Matlab files.

* `isIn(self, point)`: returns `True` if `point` is in the ball.
* `boundaryTrace(self, paramArray)`: returns points on the circumferance of the circle, where `paramArray` is an array of angles in radians.