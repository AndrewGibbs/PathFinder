function r_star = getRStar(g_coeffs,theta)
    if nargin == 1
        theta = 0;
    end

    % function which computes the r_* parameter, used for determining no
    % return regions
    rho = length(g_coeffs)-1;
    if sum(g_coeffs(2:rho) == 0)==(rho-1) % if all but first coefficient are zero
        r_star = 0;
        return; % leave subroutine early
    end
    star_coeffs_lr = zeros(1,rho-1+1); % order is one lower, but add one for zero index

    % make final coefficient of polynomial
    star_coeffs_lr(end) = rho*abs(g_coeffs(1))*min(1/sqrt(2),cos(rho*theta));

    % too confusing to work with anything else - fliplr for now, then flip
    % back. Make rest of polynomial to solve.
    g_coeffs_lr = fliplr(g_coeffs);
    for j=1:(rho-1)
        star_coeffs_lr(j+1-1) = -j*abs(g_coeffs_lr(j+1));
    end
    star_coeffs = fliplr(star_coeffs_lr);
    % solve polynomial for r*
    star_roots = roots(star_coeffs);
    % filter out imaginary roots, and make purely real
    real_roots = real(star_roots(abs(imag(star_roots))<100*eps));
    r_star = min(real_roots(real_roots>0));
    if isempty(r_star)
        error("Could not find r_star variable");
    end
end