function vals = cheb_sum(coeffs,x)
%UNTITLED5 Summary of this function goes here
%   Detailed explanation goes here
    N = length(coeffs)-1;
    T_coeffs = flip(coeffs);
    vals = zeros(size(x));
    for n=0:N
        vals = vals + T_coeffs(n+1)*chebyshevT(n,x);
    end
end