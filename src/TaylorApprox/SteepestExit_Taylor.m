function h = SteepestExit_Taylor(p,x,G,freq, M)
% copied out of AsHu for now
    p = p(:);
    if M>6
        error('Havent coded this many terms yet');
    end
    N = M+1; % max deriv needed
%     M = 4; % max Taylor term
    [~,dG_x] = get_derivs_at_x(G, x, N);

    % Taylor coefficients:
    a = zeros(M,1);
    a(1) = 1i/(freq*dG_x(1));
    if M>1
        a(2) = 0.5*dG_x(2)/(freq^2*dG_x(1)^3);
    end
    if M>2
        a(3) = 1i/(freq^3*6*dG_x(1)^5) * (dG_x(1)*dG_x(3) - 3*dG_x(2)^2);
    end
    if M>3
        a(4) = (-1/24)*(1/dG_x(1)^7)*(1/freq^4) * (dG_x(4)*dG_x(1)^2 - 10*dG_x(1)*dG_x(2)*dG_x(3) + 15*dG_x(2)^3);
    end
    if M>4
        a(5) = (1i/factorial(5))*(1/freq^5) * (105*dG_x(2)^4 - 105*dG_x(1)*dG_x(2)^2*dG_x(3) ...
            + 15*dG_x(1)^2*dG_x(2)*dG_x(4) + dG_x(1)^2*(10*dG_x(3)^2 - dG_x(1)*dG_x(5)))/dG_x(1)^9;
    end
    % from below were generated in Mathematica, and it's increasingly
    % likely that they are wrong as the coefficient index grows...
    if M>5
        a(6) = (1/factorial(6))*(1/freq^6)*(1/dG_x(1)^11)*(945*dG_x(2)^5 - 1260*dG_x(1)*dG_x(2)^3*dG_x(3) + 210*dG_x(1)^2*dG_x(2)^2*dG_x(4) ...
            - 7*dG_x(1)^2*dG_x(2)*(-40*dG_x(3)^2 + 3*dG_x(1)*dG_x(5)) + dG_x(1)^3*(-35*dG_x(3)*dG_x(4) + dG_x(1)*dG_x(6)));
    end
    % now combine everything
    h = x + (p.^(1:M))*a(1:M);

end