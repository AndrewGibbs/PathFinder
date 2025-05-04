# `harcCodeQuadratureGauleg.m`

This script overwrites the function [`gausLegHC.m`](gausLegHC.md) - so be careful! It should be used when more than one hundred hard-coded points are required, and can potentially improve performance of the PathFinder algorithm in those cases.

The value of `maxNumHardCodedPts` must be adjusted to the desired number of hard-coded quadrature rules, before this script is wrong.