function [root, found_a_root] = plan_b_isection(g_coeffs, xi, C_over_omega, theta, guesses)
    tol = 1e-8; % bisection tolerance
    % define the polynomial g
    g = @(x) polyval(g_coeffs,x);
    % and the 'polynomial' which we are seeking the root of
    G = @(r) abs(g(xi+r*exp(1i*theta))-g(xi)).^2-C_over_omega^2;
    % note that G(0)<0

    % add a couple of extra extremities to the guesses, just incase
    guesses = [0; guesses; max(guesses)*2];
    found_a_root = false;
    root = inf;
    
    for n=2:length(guesses)
        if G(guesses(n))>0 % look for a sign change
            found_a_root = true;
            root = bisection(G, guesses(n-1), guesses(n), tol);
            break; % no need to keep looking
        end
    end
    
%     if ~found_a_root
%         print('Warning - no roots found after bisection, treating radius at this angle as inf');
%     end
end