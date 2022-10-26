Designed to evaluate oscillatory integrals of the form:

$$
\int_{a}^b f(z)\exp(\mathrm{i}\omega g(z)) \mathrm{d}z,
$$

where $g$ is a polynomial, $f$ is analytic, $\omega>0$ is a frequency parameter. The endpoints $a$ and $b$ may be finite or infinite (at a valley). _PathFinder_ works by automatically constructing steepest descent contours, and allocating quadrature points along these contours.

Constructs weights and nodes to numerically evaluate an oscillatory integral. Typical syntax:
```matlab
 [z,w] = PathFinderQuad(a, b, poly_coeffs, freq, num_pts)
 ```
