# `computeGauss.m`

Compute the Gaussian rule corresponding to the orthogonal polynomials that are defined by the coefficients alpha and beta, according to the three-term recurrence relation for orthogonal polynomials:

$$
p_i(x) = (x-\alpha_i) p_{i-1}(x) - \beta_i*p_{i-2}(x),
$$
for $i=1\ldots,N$, 
with
$$
p_0(x) = 1, \text{ and } p_0(x) = 0.
$$

```matlab
[x,w] = computeGauss(N, alpha, beta)
```

For more information, see
{cite:p}`gautschi2004orthogonal`.
## Inputs

* `N` : The number of points for the quadrature rule.
* `alpha` and `beta` : Recurrence coefficients.

## Outputs

* `x` : Array of quadrature points
* `w` : Array of quadrature weights.