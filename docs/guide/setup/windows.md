# Windows setup

If compiling in **Matlab on Windows**, first [download the MinGW-w64 Compiler](https://uk.mathworks.com/help/matlab/matlab_external/install-mingw-support-package.html). Then make sure it is set to default, by typing
```
mex -setup C
```
into the Matlab terminal and following on-screen instructions. Now run
`CompileAll.m`

In Octave, this shouldn't be an issue, as MinGW-w64 compiler is used by default.