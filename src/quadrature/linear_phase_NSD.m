function [z,w] = linear_phase_NSD(a,b,freq,m,c,N)
    g = @(z) m*z + c;
    [p_,w_] = quad_gauss_laguerre(N);
    z_1 = a+1i*p_/(freq*m);
    z_2 = b+1i*p_/(freq*m);
    w_1 = w_*1i*exp(1i*freq*g(a))/(freq*m);
    w_2 = -w_*1i*exp(1i*freq*g(b))/(freq*m);
    z = [z_1; z_2];
    w = [w_1; w_2];
end