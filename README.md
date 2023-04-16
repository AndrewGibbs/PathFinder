# PathFinder

PathFinder is a Matlab toolbox for the automatic evaluation of highly oscillatory integrals, where the phase is a polynomial.

## Integrals which can be approximated by PathFinder
Specifically, these are assumed to have the following form:

$$
I[f] = \int_{a}^b f(z)\exp(\mathrm{i}\omega g(z)) \mathrm{d}z,
$$

where $g$ is a polynomial, $f$ is analytic, $\omega>0$ is a large frequency parameter. The endpoints $a$ and $b$ may be finite or infinite (at a complex valley).

## Idea behind Numerical steepest descent and PathFinder

Steepest descent contours are directed complex contours, along which $\Re g$ is constant and $\Im g$ is strictly increasing. This corresponds to zero oscillation and exponential decay of the integrand. Compared with oscillatory integrals, exponentially decaying integrals are much easier to evaluate numerically. The idea behind steepest descent is to deform the original contour (from $a$ to $b$) onto a series of steepest descent contours. The value of $I[f]$ will remain the same after this deformation, by Cauchy's Theorem.

* Close to stationary points of $g$, that is $\xi$ where $g'(\xi)=0$, the integrand of $I[f]$ is non-oscillatory, so *PathFinder* uses standard quadrature along straight line contours.
* Away from stationary points, *PathFinder* constructs steepest descent contours using an ODE solve.
* A ssuitable sequence of these paths is chosen via Dijkstra's algorithm
* Quadrature points are allocated along these contours

## Basic usage
Typical syntax, when a and b are finite:
```matlab
 [z,w] = PathFinderQuad(a, b, poly_coeffs, freq, num_pts);
 ```
 ### Allowing $a$ and/or $b$ to be infinite
 If, for example, a is infinite, and b is finite, replace a by the argument of the contour at infinity, and write
 ```matlab
 [z,w] = PathFinderQuad(a, b, poly_coeffs, freq, num_pts,'infContour', [true false]);
 ```

 ### Plotting
 To produce a plot of the steepest descent deformation, use
```matlab
 [z,w] = PathFinderQuad(a, b, poly_coeffs, freq, num_pts,'plot');
 ```

 ## Adjustable parameters

### The non-oscillatory parameter $C$
 The _non-oscillatory_ regions are defined to be the smallest ball centred at $\xi$, which contains the region $$\omega|g(\xi)-g(z)|\leq C.$$ The parameter $C$ can be adjusted, as follows:
 ```matlab
 C = 2;
 [z,w] = PathFinderQuad(a, b, poly_coeffs, freq, num_pts,'numOscs',C);
 ```
 The default is $C=1$. Increasing $C$ means that standard quadrature (Gauss Legendre) will be used to evaluate an increased number of wavelengths in each integral.
