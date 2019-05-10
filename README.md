Designed to solve integrals of the form:

![equation](http://latex.codecogs.com/gif.latex?%5Cint_%5Cgamma%20f%28z%29%5Cmathrm%7Be%7D%5E%7B%5Cmathrm%7Bi%7D%5Comega%20g%28z%29%7D%5Cmathrm%7Bd%7Dz)


Constructs weights and nodes to numerically evaluate an oscillatory integral.
```matlab
 [z,w] = PathFinderQuad(a, b, G, k, N)
 ```
 Returns weights and nodes for efficient evaluation of oscillatory
 integral of f(z)exp(i*k*g(z))dz from a to b, for analytic f & g.
 
 G is the coefficients of a polynomial g in vector form, with the coefficient of the highest power first
 
 a and b are either finite enpoints, or (in the case where the integral is an infinite contour)
 angles of valleys in the complex plane. The entries of (optional) two-dimensional
 flag infContour flag if the endpoint of the integral is infinite. For example, if a contour has a semi-infinite contour, from the origin to a valley at exp(i*pi/4), we would type
 ```matlab
 PathFinderQuad(0, exp(i*pi/4), G, k, N, 'infContour', [false true])
 ```
 
 k is the frequency parameter of the integral
 
 N is the number of points used per segment of the PathFinder routine
