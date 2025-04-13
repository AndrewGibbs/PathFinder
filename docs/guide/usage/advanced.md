# Advanced use

## Adjustable parameters

The optional inputs `'plot'`, `'plot graph'` and `'infcontour'` are just three of many adjustable parameters. In fact, all of the algorithm parameters defined in [1, Table 4.1](#references) can be easily modified, if the user wishes to do so. Here is a list of adjustable parameters - each can be adjusted by adding the optional input as a text string, followed by the new value.

|  Parameter |  Meaning |  Default | 
|---|---|---|
|  ```C_ball``` | Governs maximum number of oscillations across each non-oscillatory ball (and hence the ball radius)  |  $2\pi$ |
```N_ball```| Number of rays used when determining the ball radius |  16 |
|```delta_ball```|  Governs when overlapping balls should be amalgamated |  $10^{-3}/(2\max(J-2,1))$, where $J$ is the degree of the polynomial $g$ | 
```delta_ODE```|  Governs the local step size in the ODE solver for SD path tracing | $10^{-1}$ | 
```delta_coarse```|  Tolerance for the increment in the Newton iteration in the SD path tracing | $10^{-2}$   | 
```delta_fine```|  Tolerance for the increment in the Newton iteration in the quadrature | $10^{-13}$  | 
```delta_quad```|  Governs when the contribution from an integral on the quasi-SD deformation is computed | $10^{-16}$  | 
```inf quad rule```|  Determines which quadrature rule is used for the SD contours, from a choice of Gauss-Laguerre ```'laguerre'```, or truncated Gauss-Legendre ```'legendre'``` |  ```'laguerre'``` |
`use mex` | Determines if the MEX codes are to be used for higher performance. Should only be turned off if there is some issue with the MEX compiler, as described above.| `true` |

## Creating a log file

There is also the option to record information about the algorithm at each step. This can be achieved by adding the optional input `'log'`. A log file is then generated, and the name is based on the time and date that the file was created. For example:
```matlab
PathFinder(-1, 1, @(x) x.^2, [1 -0.5 0.5 0 -1 0], 50, 10, 'log');
```


If you want to name it something different, use the option `'log name'` followed by a text string argument with the desired name. For example:
```matlab
PathFinder(-1, 1, @(x) x.^2, [1 -0.5 0.5 0 -1 0], 50, 10, 'log name','el_murad');
```

## Hard-coded quadrature

For efficiency, PathFinder uses hard-coded Gaussian quadrature to evaluate contour integrals. By default, these hard-coded values have been stored for up to 100 points each in the subroutines `src/gauss_quadrature_rules/gausLagHC.m` and `src/gauss_quadrature_rules/gausLegHC.m`, corresponding to Gauss-Laguerre and Gauss-Legendre respectively.

If more points are requested by PathFinder, these are generated from scratch using the Golub-Welsch algorithm, with code supplied by Dirk Laurie (22/6/1998); later edited by Walter Gautschi (4/4/2002).

If desired, you can increase the number of hard-coded points, overwriting the subroutines `gausLagHC` and `gausLegHC`. To do this:
* Change the working directory to `src/gauss_quadrature_rules`
* Open the script(s) `hardCodeQuadratureGaulag` and/or `hardCodeQuadratureGauleg` as required
* Adjust the parameter `maxNumHardCodedPts` as required, and run the script.