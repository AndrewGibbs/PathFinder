# `Ball.m`

A class corresponding to non-oscillatory balls. This contains the simple geometric information about a ball $\Omega_\xi$ in the complex plane $\mathbb{C}$.

## Properties
* `radius`: Radius of the ball $\Omega_\xi$
* `centre`: Position $\xi\in\mathbb{C}$ of centre of ball $\Omega_\xi$
* `index`: Unique index of ball, typically corresponding to position in array down the stack.

## Methods

These methods are stored in their own Matlab files.

* `isIn(self, point)`: returns `True` if `point` is in the ball.
* `boundaryTrace(self, paramArray)`: returns points on the circumferance of the circle, where `paramArray` is an array of angles in radians.