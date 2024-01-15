function [r] = getRGivenTheta(g_coeffs,xi,C_over_omega,theta,imag_thresh)
%given a ray from \xi, in direction theta, find r at which the ray
%intersects the boundary of the blob |g(\xi)-g(\xi+r*exp(i*theta)|=C/omega

    % set the function g. I could just pass it, but not sure how MEX feels
    % about that.
    g_fn = @(z) polyval(g_coeffs,z);

    % pre-allocate stuff
    N = length(g_coeffs)-1;
    a = complex(zeros(N+1,1));
    a_ = complex(zeros(N+1,1));

    %% follow the algorithm, as written in my notes (and soon, the paper)
    % remember that the indexing of the polynomial coefficients is the
    % opposite in my notes as in Matlab
    a(1) = -g_fn(xi);
    a_(1) = -conj(g_fn(xi));
    d = flip(g_coeffs);
    for k=0:N
        for j=k:N
            a(k+1) = a(k+1) + d(j+1)*nchoosek(j,k)*xi^(j-k)*exp(1i*k*theta);
            a_(k+1) = a_(k+1) + conj(d(j+1))*nchoosek(j,k)*conj(xi^(j-k))*exp(-1i*k*theta);
        end
    end

    % multiply the polynomials together, aka Cauchy product
    coeffs = conv(a,a_);
    coeffs(1) = coeffs(1) - C_over_omega^2;

    %% filter out the roots we care about
    r_roots = roots(flip(coeffs));

    %remove the roots with negative real bits       
    roots_with_positive_real_part = r_roots(real(r_roots)>0);

    % remove the roots with significant imaginary bits
    real_and_positive_roots = roots_with_positive_real_part(abs(imag(roots_with_positive_real_part))<imag_thresh);

    if isempty(real_and_positive_roots)
%         print("Warning - no suitable radii found with current 'imag thresh' parameter (default is 1e-8), attempting a bisection")
    
        guesses = real(sort(real(roots_with_positive_real_part)));
        % no obvious canditates for roots.
        r = planBisection(g_coeffs, xi, C_over_omega, theta, guesses);
    else
        %take the smallest value
        r = min(real(real_and_positive_roots));
    end
end