function I = PathFinder(a, b, f, phaseIn, freq, nPts, varargin)
%Numerically evaluates an oscillatory integral.
%I = PathFinder(a, b, f, G, k, N) evaluates the integral
% of f(z)exp(i*k*g(z))dz from a to b, for analytic f & polynomial g.
%
% f is a vectorised function handle, or f=[] if f(z)=1.
%
% G is a vector of polynomial coefficients, in standard Matlab
% format: G(1)*X^P + ... + G(P)*X + G(N+1), where the coefficients are complex
%
% a and b are either finite endpoints (complex valued) or (in the case where the integral is 
% an infinite contour) angles of valleys in the complex plane.
%
% k (real or complex) is the frequency parameter of the integral
%
% N (real, positive, integer) is the number of points used per segment of the PathFinder routine.
%
% A large number of optional inputs are available.  These are needed if the 
% endpoints are infinite, for example. For more information, see
% <a href="matlab:web('www.github.com/AndrewGibbs/PathFinder','-browser')">github.com/AndrewGibbs/PathFinder</a>
%
% PathFinder is provided under an MIT license, for more details see
% LICENSE in the root directory, or on the github page linked above.

    checkInputs(a, b, f, phaseIn, freq, nPts);

    [z,w] = PathFinderQuad(a, b, phaseIn, freq, nPts, varargin{:});

    if isempty(f)
        I = sum(w);
    else
        I = w.'*f(z);
    end

end