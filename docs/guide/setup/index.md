# Installation and setup

After downloading the source code from GitHub, open Matlab/Octave and navigate to the PathFinder folder. Then run ```addPaths.m``` to add all necessary paths to the Matlab search path.

The more computationally expensive parts of PathFinder have been written in C, to compile as MEX functions (Matlab executable). When running Matlab on Windows, this requires [an extra step](#windows). When compiling on Octave, this can also requrie an extra step, depending on your OS; see [here for MacOS](#Mac-Octave-compilation), or [here for Ubuntu and Windows](#Windows-and-Ubuntu-Octave-ompilation).

Compile the MEX codes for your system by running ```compileAll.m```. This works with Octave or Matlab and only needs to be done once for each.


To test the code works, try running
```matlab
PathFinder(-1, 1, @(x) sin(x), [1 0 0], 100, 10, 'plot')
```
This approximates the integral

$$
\int_{-1}^1\sin(x)\exp(\mathrm{i}100x^2)\mathrm{d}x=0,
$$

and will produce a simple plot of the contour deformation.

You could also try running the codes in the 'examples' subfolder.