# Troubleshooting

If there are any compilation issues:
* Please raise an issue on the GitHub issues page, stating your Matlab/Octave version and operating system.
* Until the problem is fixed, set the optional argument `'use mex'` to `false` in future PathFinder calls to avoid the use of MEX functions. More information about how to provide optional arguments is given in (#../usage/advanced).