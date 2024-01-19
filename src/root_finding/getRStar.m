% routine to determine $r_*$, in the notation of the paper (section 2.4).
% The parameter $r_*$ is used to determine 'no return' regions
function rStar = getRStar(phaseCoeffs, theta)

    % we expect real roots, so any roots with a larger imaginary part than
    % this will be discarded.
    imagThresh = 100*eps;

    if nargin == 1
        theta = 0;
    end

    % polynomial phase order is 'J' in the paper
    order = length(phaseCoeffs)-1;

    % if all but leading coefficient are zero, simplifies as follows
    if sum(phaseCoeffs(2:order) == 0)==(order-1)
        rStar = 0;
        return; % leave subroutine early
    end

    % coefficients of polynomrial in $r_*$, order is one less than phase
    starCoeffsFlipLR = zeros(1,order);

    % momentarily, we abandon the matlab convention of indexing polynomial
    % coefficients with the leading term first. This is to be consistent
    % with the notation of the paper, for a net gain in clarity overall.

    % final coefficient of polynomial (corresponds to leading order term)
    starCoeffsFlipLR(end) = order*...
                        abs(phaseCoeffs(1))*min(1/sqrt(2), cos(order*theta));
    
    % make fliiped version of phase coefficients too
    phaseCoeffsFlipLR = fliplr(phaseCoeffs);

    % Make rest of polynomial to solve.
    for j=1:(order-1)
        starCoeffsFlipLR(j+1-1) = -j*abs(phaseCoeffsFlipLR(j+1));
    end

    % now flip back, into Matlab style polynomial coefficient indexing...
    starCoeffs = fliplr(starCoeffsFlipLR);

    % ... so we can solve polynomial for $r_*$
    rStarRoots = roots(starCoeffs);

    % filter out imaginary roots, and make purely real
    realRStarRoots = real(rStarRoots(abs(imag(rStarRoots))<imagThresh));

    % take the value of $r_*$ to be the smallest root
    rStar = min(realRStarRoots(realRStarRoots>0));
    
    if isempty(rStar)
        error("Could not find r_star variable");
    end
end