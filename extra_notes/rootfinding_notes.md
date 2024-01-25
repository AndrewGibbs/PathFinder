# Construction of Coefficients for Polynomial Root-finding Problems in PathFinder

### Outline
In the original paper about the PathFinder algorithm [[1]](#references), the derivation of some root-finding procedures were deemed too trivial to include. Unfortunately, these derivations are not trivial enough to explain within the comments of the code, so full details are given here, for anyone who wants interested in fully understanding the algorithm/code.

Following the notation [[1]](#references), we write the polynomial phase function as

$$
g(z) = \sum_{j=0}^J \alpha_j z^j.
$$

We use $\xi$ to denote the center of a complex ball, which is usually a stationary point.

### Finding the Intersection of Rays with the Boundary of the Non-oscillatory Region
In section 2.2 of the paper [[1]](#references), we discuss the procedure for choosing the balls around the stationary points. This can be broken down into several smaller root-finding problems, of the following form: Given $\theta$ and $\xi$, find $r>0$ such that

$$
\omega\left|g(\xi+r\mathrm{e}^{\mathrm{i} \theta})-g(\xi)\right|=C_{\mathrm{ball}}.
$$

Since $g$ is a polynomial, the function

$$
G(r) := \omega\left|g(\xi+r\mathrm{e}^{\mathrm{i} \theta})-g(\xi)\right|^2-\left(\frac{C_{\mathrm{ball}}}{\omega}\right)^2
$$

is also a polynomial, with roots satisfying the previous equation. The coefficients of the polynomial $G$ can be obtained as follows:

First, find the coefficients of the polynomial inside the absolute value sign in the root-finding problem. Binomially expand as follows:

$$
g(\xi+r\mathrm{e}^{\mathrm{i} \theta}) = \sum_{k=0}^J r^k\left[\mathrm{e}^{\mathrm{i} k \theta}\sum_{j=k}^J \alpha_j\left(\begin{array}{c} j\\k \end{array}\right)\xi^{j-k}\right].
$$

Now, the coefficients can be expressed as:

$$ a_0 := -g(\xi)+\sum_{j=0}^J \alpha_j \xi^{j}; $$

$$ a_k := \mathrm{e}^{\mathrm{i} k \theta}\sum_{j=k}^J \alpha_j\left(\begin{array}{c} j\\k \end{array}\right)\xi^{j-k}, \text{ for } k=1,\ldots,J. $$

Using these coefficients, the function $G(r)$ can be expressed as:

$$ G(r) = \sum_{\ell=0}^{2J} b_jr^k, $$

where

$$ b_0 := |a_0|^2 -\left(\frac{C_{\mathrm{ball}}}{\omega}\right)^2; $$

$$ b_j=\sum_{\ell=0}^{j}a_\ell\overline{a}_{j-\ell}, \text{ for } j=1,\ldots,2J. $$

In the PathFinder subroutine `getRGivenTheta`, polynomial root-finding algorithms, specifically Matlab's `roots` command, are used to find the roots of the polynomial $G$.

### Finding the Exits on the Circumference of the Ball
In section 2.3 of the PathFinder paper [[1]](#references), it is mentioned that the exits are determined using a trigonometric root-finding procedure. The radius of the ball $r$ is fixed, and we are looking for local maxima (in $\theta$) of $\Im g(\xi+r\mathrm{e}^{\mathrm{i} \theta})$. The approach is to represent $\Im g(\xi+r\mathrm{e}^{\mathrm{i} \theta})$ exactly in terms of a finite Fourier basis.

First, construct the trigonometric polynomial in $\theta$ from the coefficients obtained earlier:

$$ g(\xi+r\mathrm{e}^{\mathrm{i} \theta}) = \sum_{k=0}^J c_k\mathrm{e}^{\mathrm{i} k \theta}, $$

where

$$ c_k:=\sum_{j=k}^Jr^k \alpha_j\left(\begin{array}{c} j\\k \end{array}\right)\xi^{j-k}, \text{ for } k=0,\ldots,J. $$

Now, find coefficients for the derivatives in terms of this Fourier basis:

$$ \Im\left[g(\xi+r\mathrm{e}^{\mathrm{i} \theta})\right] = \sum_{k=0}^J \Im [c_k]\cos(k\theta) + \Re[c_k]\sin(k\theta), $$

$$ \frac{\partial}{\partial\theta}\Im\left[g(\xi+r\mathrm{e}^{\mathrm{i} \theta})\right] = \sum_{k=0}^Ja_k\cos(k\theta)+b_k\sin(k\theta), $$

$$ \frac{\partial^2}{\partial\theta^2}\Im\left[g(\xi+r\mathrm{e}^{\mathrm{i} \theta})\right] = \sum_{k=0}^Ja'_k\cos(k\theta)+b'_k\sin(k\theta). $$



Note that the coefficients $a_k$ and $b_k$ have a different meaning here to the previous section - we have abused notation to be consistent with local variable names within the code.

Now, the roots of the first derivative can be found using the root-finding algorithm, for e.g. [[2]](#references), and the maxima can be filtered out using the second derivative test.

In PathFinder, this is done in the subroutine `getSteepestExitsOnBall`, where the coefficients $a_k$, $b_k$, $a'_k$, and $b'_k$ are represented by the vectors `a`, `b`, `da`, and `db` respectively.

## References
[1] A. Gibbs, D. P. Hewett, D. Huybrechs, *Numerical evaluation of oscillatory integrals via automated steepest descent path deformation*, to appear J. Comput. Phys. (2024).

[2] J. P. Boyd, *Computing the zeros, maxima and inflection points of Chebyshev, Legendre and Fourier series: solving transcendental equations by spectral interpolation and polynomial rootfinding*, J. Eng. Math., 56 (2006), pp. 203–219.
