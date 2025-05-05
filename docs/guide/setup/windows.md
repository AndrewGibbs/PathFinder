# Matlab setup

If using Linux or MacOS, it should be sufficient to run
```matlab
CompileAll.m
```
This should compile all necessary binaries.

If using **Matlab on Windows**, an additional step is needed before compilation. First [download the MinGW-w64 Compiler](https://uk.mathworks.com/help/matlab/matlab_external/install-mingw-support-package.html). Then make sure it is set to default, by typing
```matlab
mex -setup C
```
into the Matlab terminal and following on-screen instructions. Now run
`CompileAll.m`

In Octave, this shouldn't be an issue, as MinGW-w64 compiler is used by default. There are, however, other potential issues within octave, which we address on the next page.