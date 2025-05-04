# switchWindowsCompiler

When running tests on GitHub CI, we can install mingw64 compiler easily enough, but actually switching to the compiler is tricky, as there is no Matlab one-liner to
 do this. This function locates the relevant compiler and switches  automatically, using regular expressions.

```matlab
switchWindowsCompiler()
```