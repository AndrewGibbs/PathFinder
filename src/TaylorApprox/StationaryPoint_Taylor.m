function [h_p,h_m] = StationaryPoint_Taylor(p,x,G)
% copied out of AsHu for now
    p = p(:);
    N = 5; % max deriv needed
    M = 4; % max Taylor term
    % to avoid recomputing the p^j matrix, precompute here
    p_mat = (p.^(1:M));
    [~,dG_x] = get_derivs_at_x(G, x, N);

    % Taylor coefficients:
    a_p(1) = sqrt(2i/dG_x(2));
    a_p(2) = -1i/3*dG_x(3)/dG_x(2)^2; % done up to here
    a_p(3) = sqrt(2i/dG_x(2))*1i/(36*dG_x(3)^3) * (5*dG_x(3)^2 - 3*dG_x(2)*dG_x(4));
    a_p(4) = 1/27*1/dG_x(2)^5 * (40*dG_x(3)^3-45*dG_x(4)*dG_x(3)*dG_x(2) +9*dG_x(5)*dG_x(2)^2);

    % make the coefficients for both cases
    a_m = a_p;
    a_m(2) = -a_m(2);
    a_m(4) = -a_m(4);

    h_p = x + p_mat*a_p;
    h_m = x + p_mat*a_m;
end