Designed to solve integrals of the form:

![equation](http://latex.codecogs.com/gif.latex?%5Cint_%5Cgamma%20f%28z%29%5Cmathrm%7Be%7D%5E%7B%5Cmathrm%7Bi%7D%5Comega%20g%28z%29%7D%5Cmathrm%7Bd%7Dz)


Constructs weights and nodes to numerically evaluate an oscillatory integral.
```matlab
 PathFinderQuad(a, b, G, freq, N)
 ```
 returns weights and nodes for efficient evaluation of oscillatory
 integral of f(z)exp(i*k*g(z))dz from a to b, for analytic f & g.
 
 phaseIn is either the coefficients of a polynomial g
 
 a and b are either finite enpoints, or (in the case where the integral is an infinite contour)
 angles of valleys in the complex plane. The entries of (optional) two-dimensional
 flag infContour flag if the endpoint of the integral is infinite.
 
 k is the frequency parameter of the integral
 
 N is the number of points used per segment of the PathFinder routine
