function I = PathFinder(a, b, f, phaseIn, freq, nPts, varargin)
%Construct weights and nodes to numerically evaluate an oscillatory
%integral.
%[z,w] = PathFinder(a, b, f, G, k, N, infContour)
%evaluates the oscillatory
%integral of f(z)exp(i*k*g(z))dz from a to b, for analytic f & g.
%
%G is the coefficients of a polynomial, in standard Matlab
%format: G(1)*X^N + ... + G(N)*X + phaseIn(N+1)
%
%a and b are either finite enpoints, or (in the case where the integral is an infinite contour)
%angles of valleys in the complex plane. The entries of (optional) two-dimensional
%flag infContour flag if the endpoint of the integral is infinite.
%
%k is the frequency parameter of the integral
%
%N is the number of points used per segment of the PathFinder routine.
%
%A large number of optional inputs are available. For more information,
%see
%<a href="matlab:web('www.github.com/AndrewGibbs/PathFinder','-browser')">github.com/AndrewGibbs/PathFinder</a>

    [z,w] = PathFinderQuad(a, b, phaseIn, freq, nPts, varargin{:});

    if isempty(f)
        I = sum(w);
    else
        I = w.'*f(z);
    end

end