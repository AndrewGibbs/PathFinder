# `optionalExtras.m`

Called before any mathematical steps in the PathFinder algorithm, this allows the user to modify default approximation parameters. It also records information about plots that have been requested. For more details of what can be modified, see [Advanced usage](../../usage/advanced.md).

```matlab
options = optionalExtras(order,varargin)
```

## Inputs

* `order` : The degree of the polynomial phase function. This is a mandatory input, because it is required to compute the default parameter `ballMergeThresh`. 
* `varargin` : A cell array of optional inputs to be modified.

## Outputs

`options` : a cell array of approximation parameters, and other information, to be used for PathFinder.