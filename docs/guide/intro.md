# PathFinder Documentation

PathFinder is a Matlab/Octave toolbox for the numerical evaluation of highly oscillatory integrals. Specifically, PathFinder can efficiently evaluate integrals of the form

$$
I = \int_{a}^b f(z)\exp(\mathrm{i}\omega g(z)) \mathrm{d}z
$$

where $g$ is a polynomial, $f$ is entire (analytic everywhere in $\mathbb{C}$), $\omega>0$ is a frequency parameter, and the endpoints $a$ and $b$ may be finite or infinite. Further, it is assumed that $I$ is a convergent integral and that $|f(z)|$ grows sub-exponentially as $|z|\to\infty$.

PathFinder is based on steepest descent contour deformation, but it can be easily used without a deep understanding of the underlying mathematics; it is sufficient to understand the conditions in the previous paragraph. This document intends to provide a full explanation of **how to use PathFinder**. For a full explanation of the underlying mathematics, the interested reader is referred to {cite:p}`PFpaper`.