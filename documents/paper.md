---
title: 'PathFinder: A Matlab/Octave package for oscillatory integration'
tags:
  - Matlab
  - Octave
  - C
  - Oscillatory integrals
  - High-frequency scattering
  - Catastrophe integrals
  - Steepest descent
  - Coalescing saddles
authors:
  - name: Andrew Gibbs
    orcid: 0000-0002-2934-008X
    affiliation: "1"
affiliations:
 - name: University College London, United Kingdom
   index: 1
date: 2nd February 2023
bibliography: joss_refs.bib
---

# Summary

Oscillatory integrals arise in models of a wide range of physical applications, from acoustics to quantum mechanics. `PathFinder` is a Matlab/Octave package for efficient evaluation of oscillatory integrals of the form
\begin{equation}\label{eq:I}
I = \int_a^b f(x) \exp(\mathrm{i}\omega g(x))~\mathrm{d}x,
\end{equation}
where the endpoints $a$ and $b$ can be complex-valued, even infinite; $\omega>0$ is the frequency parameter, $f$ is an entire function and $g$ is a polynomial phase function. The syntax is simple:
```matlab
I = PathFinder(a, b, f, gCoeffs, omega, N);
```
Here, `f` is a function handle representing $f(x)$, `gCoeffs` is a vector of coefficients of $g$, `omega` is the frequency parameter $\omega$ and `N` is a parameter that controls the number of quadrature points used.

`PathFinder` is the first black-box method that can evaluate \autoref{eq:I} accurately, robustly and efficiently for any frequency $\omega$. It will be useful across a range of scientific disciplines, enabling the solution of problems that were previously too computationally expensive, or too mathematically challenging.

# Statement of need

Based on the method of Numerical Steepest Descent, `PathFinder` is an implementation of the algorithm described in @PathFinderPaper, where an earlier version of the code was used to produce numerical experiments. Since these experiments, much of the code has been rewritten in C, interfacing with Matlab/Octave via MEX (Matlab executable) functions. These files can be easily compiled using a single script.

### Ease of use

Standard quadrature rules (midpoint rule, Gauss quadrature, etc) are easy to use, as many open-source implementations are available. However, when applied to \autoref{eq:I}, such methods become prohibitively inefficient for large $\omega$.

On the other hand, several methods exist for the efficient evaluation of oscillatory (large $\omega$) integrals [@DeHuIs:18], but applying these methods often requires an expert understanding of the process and a detailed analysis of the integral; making such methods inaccessible to non-mathematicians. Even with the necessary mathematical understanding, many models may require hundreds or thousands of oscillatory integrals to be evaluated, making detailed analysis of each integral highly challenging or impossible.

Despite being based on complex mathematics [@HuVa:06], `PathFinder` can be easily used by non-mathematicians. The user must simply understand the definitions of the components of \autoref{eq:I}. Clear instructions are provided in the README file and a range of example codes are provided.

### Robustness for coalescing saddle points

We now describe an important problem class that was previously very difficult to model but can now be done in just a few lines of code using `PathFinder`. A _saddle point_ is defined to be any $\xi\in\mathbb{C}$ such that $g'(\xi)=0$. When multiple saddle points are sufficiently near one another, this is commonly referred to as *coalescence*. A broad range of exciting problems have numerical models that require the evaluation of integrals with coalescing saddle points. For example, chemical reactions, rainbows, twinkling starlight, ultrasound pulses, and focusing of sunlight by rippling water (see Chapter 36 of @DLMF for a thorough review).

Just two coalescing saddle points can cause Steepest Descent methods to break down [@HuJuLe:19]. Fortunately, `PathFinder` is robust for any number of coalescing saddle points. This is demonstrated in \autoref{fig:pearcey} and \autoref{fig:swallowtail}, where `PathFinder` has been used to model well-known optics problems with coalescing saddles.

![PathFinder approximation to Pearcey/Cusp Catastrophe integrals [@Pe:46], which contain coalescing saddle points.\label{fig:pearcey}](../examples/cusp.png)

![PathFinder approximation to Swallowtail Catastrophe integrals [@Ar:81], which contain many coalescing saddle points.\label{fig:swallowtail}](../examples/swallowtail.png)

Recently in @OcTeHeGi:24, `PathFinder` was applied to model caustic waves with multiple coalescing saddle points, shedding light on the famous (and unsolved) Popov inflection point problem [@Popov79].

### Comparison with Mathematica's `NIntegrate`

As was explained in @PathFinderPaper, to the author's best knowledge, the only other black-box routine that can efficiently evaluate oscillatory integrals is Mathematica's `NIntegrate` function. This has three major drawbacks when compared against `PathFinder`.
 - `NIntegrate` is not open source; the code cannot be seen or modified, and one must acquire a license to use it. 
 - `NIntegrate` only appears to have a frequency-independent cost for monomial phase functions, i.e., $g(x)=x^\rho$ for $\rho\in\mathbb{N}$; a much narrower class than `PathFinder`, which can evaluate \autoref{eq:I} for any polynomial phase $g$. 
 - It appears that `NIntegrate` requires the integration range to be finite, whereas `PathFinder` can evaluate integrals on an unbounded contour.

# Acknowledgments

I am very grateful for the guidance of Daan Huybrechs and David Hewett throughout the development of this software. I am also grateful for financial support from KU Leuven project C14/15/05 and EPSRC projects EP/S01375X/1, EP/V053868/1.

Some of the code in `PathFinder` relies on other projects. I am grateful to Dimas Aryo whose code is used for the Dijkstra shortest path algorithm. I am also grateful to Dirk Laurie and Walter Gautschi for writing the Golub-Welsch algorithm used to generate Gaussian quadrature rules.

# References