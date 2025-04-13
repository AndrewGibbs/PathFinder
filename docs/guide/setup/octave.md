# Octave installation

For Octave coimpilation on Windows and Ubuntu, you need the [LAPACKE](https://www.netlib.org/lapack/lapacke.html) library installed.

## MacOS

Make sure `openblas` [is installed](https://formulae.brew.sh/formula/openblas).

Once installed, open the Mac terminal and type
```bash
brew info openblas
```
Now make sure the addresses of the two export flags match those used in line 35 of `compileAll.m`.