# PathFinder

[![codecov](https://codecov.io/github/AndrewGibbs/PathFinder/graph/badge.svg?token=AQKOHW4CZJ)](https://codecov.io/github/AndrewGibbs/PathFinder)
[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/AndrewGibbs/PathFinder/HEAD?labpath=examples%2FOctave_notebook_egs.ipynb)
[![status](https://joss.theoj.org/papers/851d659a3a85536bfc6b86de45a1641d/status.svg)](https://joss.theoj.org/papers/851d659a3a85536bfc6b86de45a1641d)
[![CI](https://github.com/AndrewGibbs/PathFinder/actions/workflows/ubuntu.yml/badge.svg)](https://github.com/AndrewGibbs/PathFinder/actions/workflows/ubuntu.yml//badge.svg)
[![CI](https://github.com/AndrewGibbs/PathFinder/actions/workflows/windows.yml/badge.svg)](https://github.com/AndrewGibbs/PathFinder/actions/workflows/windows.yml//badge.svg)


```{include} docs/intro_insert.md

## Acknowledgments

I am very grateful for the guidance and advice of Daan Huybrechs and David Hewett throughout the development of this software. I am also grateful for financial support from KU Leuven project C14/15/05 and EPSRC projects EP/S01375X/1, EP/V053868/.

Some of the code in PathFinder relies on other projects. I am grateful to Dimas Aryo, whose code [[3]](#references) is used for the Dijkstra shortest path algorithm. Copyright information for this code can be found in: `src/shortest_path/dijkstra/license.txt`. I am also grateful to Dirk Laurie and Walter Gautschi for writing the Golub-Welsch algorithm used to generate Gaussian quadrature rules. 
