# The idea behind the Numerical Steepest Descent (NSD) method and PathFinder

PathFinder is designed to be used by non-experts, who do not understand how it works. But if you'd like a brief explanation of what's going on underneath - here we briefly outline how PathFinder works.

## Steepest descent methods

Recall that the integral we are interested in is

$$
I[f] = \int_a^b f(z) \mathrm{e}^{\mathrm{i}\omega g(z)} dz.
$$

Steepest descent contours are directed complex contours, along which $\Re g$ is constant and $\Im g$ is strictly increasing. This corresponds to zero oscillation and exponential decay of the integrand. Compared with oscillatory integrals, exponentially decaying integrals are much easier to evaluate numerically. The idea behind the Numerical Steepest Descent is to deform the original contour (from $a$ to $b$) onto a series of steepest descent contours. Typically, these pass through stationary points of $g$, that is $\xi$ where $g'(\xi)=0$. The value of $I[f]$ will remain the same after this deformation, by Cauchy's Theorem. In principle, one can then apply suitable numerical quadrature rules to evaluate the contributions from the steepest descent contours.

For a solid introduction to numerical steepest descent methods, we recommend Chapter five of {cite:p}`DeHuIs:18`.

## Practical considerations

In practice, determining the steepest descent deformation for a given phase function can be complicated, and standard numerical quadrature rules may be inaccurate when multiple coalescing stationary points are present. PathFinder solves both these difficulties, by automating the deformation process and enclosing stationary points in a "non-oscillatory region" in which the integrand undergoes at most a bounded number of oscillations, and in which we do not attempt to trace or integrate along steepest descent contours. Roughly speaking, the non-oscillatory region around each stationary point $\xi$ consists of $z$ such that

$$
\omega|g(z)-g(\xi)|=C_{\mathrm{ball}};
$$

where, roughly speaking, the parameter $C_{\mathrm{ball}}$ corresponds to the number of oscillations inside the region.


## Further algorithmic details

There are several steps to the PathFinder algorithm. A full explanation is given in the JCP paper {cite:p}`PFpaper`. But here is a brief overview of the key steps involved.

* Away from stationary points, PathFinder constructs steepest descent contours using an ODE solver combined with a Newton correction.
* Close to stationary points, where the integrand is non-oscillatory, PathFinder connects the endpoints of different steepest descent contours using straight line contours.
* The contours obtained are used to build a graph, the shortest path through which (connecting the endpoints $a$ and $b$) is chosen via Dijkstra's algorithm. This step uses the code {cite:p}`aryo`.
* Quadrature points are allocated along the contours in the shortest path (Gauss-Legendre for the straight-line contours near the stationary points and Gauss-Laguerre for the steepest descent contours).