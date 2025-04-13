# PathFinder

[![codecov](https://codecov.io/github/AndrewGibbs/PathFinder/graph/badge.svg?token=AQKOHW4CZJ)](https://codecov.io/github/AndrewGibbs/PathFinder)
[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/AndrewGibbs/PathFinder/HEAD?labpath=examples%2FOctave_notebook_egs.ipynb)
[![status](https://joss.theoj.org/papers/851d659a3a85536bfc6b86de45a1641d/status.svg)](https://joss.theoj.org/papers/851d659a3a85536bfc6b86de45a1641d)
[![CI](https://github.com/AndrewGibbs/PathFinder/actions/workflows/ubuntu.yml/badge.svg)](https://github.com/AndrewGibbs/PathFinder/actions/workflows/ubuntu.yml//badge.svg)
[![CI](https://github.com/AndrewGibbs/PathFinder/actions/workflows/windows.yml/badge.svg)](https://github.com/AndrewGibbs/PathFinder/actions/workflows/windows.yml//badge.svg)
[![Documentation Status](https://img.shields.io/badge/docs-published-success)](https://andrewgibbs.github.io/PathFinder/)


PathFinder is a Matlab/Octave toolbox for the numerical evaluation of highly oscillatory integrals. Specifically, PathFinder can efficiently evaluate integrals of the form

$$
I = \int_{a}^b f(z)\exp(\mathrm{i}\omega g(z)) \mathrm{d}z
$$

where $g$ is a polynomial, $f$ is entire (analytic everywhere in $\mathbb{C}$), $\omega>0$ is a frequency parameter, and the endpoints $a$ and $b$ may be finite or infinite. Further, it is assumed that $I$ is a convergent integral and that $|f(z)|$ grows sub-exponentially as $|z|\to\infty$.

PathFinder is based on steepest descent contour deformation, but it can be easily used without a deep understanding of the underlying mathematics; it is sufficient to understand the conditions in the previous paragraph.

For information about installation, syntax and how to contribute, please refer to [the full documentation](https://andrewgibbs.github.io/PathFinder/).

## Acknowledgments

I am very grateful for the guidance and advice of Daan Huybrechs and David Hewett throughout the development of this software. I am also grateful for financial support from KU Leuven project C14/15/05 and EPSRC projects EP/S01375X/1, EP/V053868/.

Some of the code in PathFinder relies on other projects. I am grateful to Dimas Aryo, whose code [[3]](#references) is used for the Dijkstra shortest path algorithm. Copyright information for this code can be found in: `src/shortest_path/dijkstra/license.txt`. I am also grateful to Dirk Laurie and Walter Gautschi for writing the Golub-Welsch algorithm used to generate Gaussian quadrature rules. 
