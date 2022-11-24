function [G_x,dG_x] = get_derivs_at_x(G, x, N)
% copied out of AsHu for now
    dG_x = complex(zeros(N,1));
    G_x = complex(polyval(G,x));
    d_coeffs = G;
    for n=1:N
        d_coeffs = [0 diff_coeffs(d_coeffs)];
        dG_x(n) = polyval(d_coeffs,x);
    end
end