%given a ray from \xi, in direction theta, find r at which the ray
%intersects the boundary of the closed contour bounding the non-oscillatory
%region, i.e.:
% |g(\xi)-g(\xi+r*exp(i*theta)|=C/omega


% In this code, a few standard Matlab coding conventions are broken, so
% that the code closely resembles the math in extra_notes.pdf

function r = getRGivenTheta(phaseCoeffs, centre, cballOverOmega, theta, imag_thresh)

    phaseHandle = @(z) polyval(phaseCoeffs,z);

    % pre-allocate coefficients vectors
    order = length(phaseCoeffs)-1;
    a = complex(zeros(order+1,1));
    a_ = complex(zeros(order+1,1));

    %% follow the algorithm, as written in my notes
    % remember that the indexing of the polynomial coefficients is the
    % opposite in my notes as in Matlab. Allocate coefficients vectors as
    % in 'extra_notes'.
    a(1) = -phaseHandle(centre);
    a_(1) = conj(a(1));
    flipPhaseCoeffs = flip(phaseCoeffs);
    for k=0:order
        for j=k:order
            a(k+1) = a(k+1) + ...
                flipPhaseCoeffs(j+1)*nchoosek(j,k)...
                *centre^(j-k)*exp(1i*k*theta);
            a_(k+1) = conj(a(k+1));
        end
    end

    % multiply the polynomials together, aka Cauchy product
    coeffs = conv(a,a_);
    coeffs(1) = coeffs(1) - cballOverOmega^2;

    %% filter out the roots we care about
    rRoots = roots(flip(coeffs));

    %remove the roots with negative real part       
    rootsWithPositiveRealPart = rRoots(real(rRoots)>0);

    % remove the roots with significant imaginary part
    realAndPositiveRoots = ...
        rootsWithPositiveRealPart(abs(imag(rootsWithPositiveRealPart))<imag_thresh);

    if isempty(realAndPositiveRoots)
        % No obvious canditates for roots. Use real parts of complex roots
        % as initial guess in a bisection method, to find roots.
        guesses = real(sort(real(rootsWithPositiveRealPart)));
        r = planBisection(phaseCoeffs, centre, cballOverOmega, theta, guesses);
    else
        %take the smallest positive real value of r
        r = min(real(realAndPositiveRoots));
    end
end