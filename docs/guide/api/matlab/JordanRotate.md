# `JordanRotate.m`

It is possible that the user can provide unbounded endpoints $a$ and/or $b$ which do not precisely correspond to valleys, but still enjoy exponential decay. This subroutine relies on ideas from [Jordan's Lemma](https://en.wikipedia.org/wiki/Jordan%27s_lemma): the complex argument of unbounded endpoints can be rotated a little without affecting the value of the integral. When possible, the subroutine rotates the argument of unbounded endpoints $a,b$ to the nearest valley of the phase function $g$.

```matlab
[a,b] = JordanRotate(a,b,valleys,Params)
```

Note that only infinite endpoints are rotated - as this does not change the value of the integral.

## Inputs

* `a` and `b`: The original endpoints, before rotation.
* `valleys`: The valleys of the polynomial phase function $g$.
* `Params`: A Matlab struct of parameters, including information about which endpoints are infinite.

## Outputs

* `a` and `b`: The endpoints after rotation.