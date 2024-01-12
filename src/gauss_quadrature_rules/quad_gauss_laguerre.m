function [x,w] = quad_gauss_laguerre(n)
%function [x,w] = quad_gauss_laguerre(n)
%
%   Return the Gauss-Laguerre quadrature rule with n points.
%
%   References:
%   W. Gautschi, ``Orthogonal Polynomials: Computation and Approximation'',
%       Clarendon Press, Oxford, 2004.

% $Id$

% Use OPQ routine from Gautschi
ab = r_laguerre(n);
[x,w] = compute_gauss(n, ab(:,1), ab(:,2));

