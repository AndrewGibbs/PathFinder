# How to contribute

If you would like to contribute to PathFinder, there are two main ways to do it:
1. Raise an issue making your suggestion.
2. Fork the main repository, make the change yourself, and create a pull request. Changes will only be accepted if all tests in `test/Test_all.m` pass; it is advisable that you run these tests locally before creating a pull request.

## Suggestions for contributions

* We are particularly keen to learn about applications of PathFinder. If you have an example that you have used for a project, we would love to hear about it. Better still - you could upload something related into the `examples` subfolder.
* Contributions to the documentation are very welcome. We would welcome any feedback, if any of it is unclear.
* We are certainly interested in bug fixes and performance improvements. Any modification which changes the core algorithm significantly, or changes the scope of the problems which can be solved, may be better suited to a new project, perhaps using or adapting existing PathFinder code. If you are considering a major change such as this, please let us know, and we would be happy to advise.

## Reporting bugs

If you manage to break PathFinder, or find any kind of bug, please create an issue. Your issue should contain:
* A minimal working example. Ideally, this would contain a snippet of the form
`PathFinder(a,b,f,g_coeffs,freq,N)`
where all of the inputs are given in full 16-digit precision.
* Please state if you are using Octave or Matlab, and which operating system you are using.
* Please report the error message you get. If the code crashes, it would be helpful if you are able to tell us roughly where in the code (file, line number) this happens.

## Development guidelines

We try to follow the standard [Matlab style guide](https://www.ee.columbia.edu/~marios/matlab/MatlabStyle1p5.pdf) for Matlab code, and the [C syntax style](https://cs50.readthedocs.io/style/c/) for the C code used to generate the MEX functions. However, we are not too strict about this, so please do not let this deter you from making a contribution!

When making changes, we suggest periodically running `test/Test_all.m`, to check that your changes haven't broken features elsewhere.