# Octave installation

## Windows and Linux
For Octave compilation on Windows and Linux, you need the [LAPACK](https://www.netlib.org/lapack/), [LAPACKE](https://www.netlib.org/lapack/lapacke.html) and (BLAS)[https://www.netlib.org/blas/) libraries installed.

## MacOS
When on MacOS, you must make sure `openblas` [is installed](https://formulae.brew.sh/formula/openblas).

Once installed, open the Mac terminal and type
```bash
brew info openblas
```
Now make sure the addresses of the two export flags match those used in line 35 of `compileAll.m`.