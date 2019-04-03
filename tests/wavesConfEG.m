clear classes;
clc;

addPaths();

coalesps = [.1 0.01 0.001 0.0001];
omegas = [500 1000 10000 100000];
Npts = 5;

for coalesp = coalesps
    fprintf('\ncoalescence: %.3f',coalesp);
    for freq = omegas
        fprintf('\n\tfreq = %d',freq);
        g = @(x) x.^3/3 - coalesp^2*x;
        Iml = integral(@(x) exp(1i*freq*g(x)),-1,1,'ArrayValued',true,'RelTol',1e-12);
        coeffs = [1/3 0 -coalesp^2 0];
        [z,w] = quadBodge(-1,1,coeffs,freq,Npts);
        Ipf = sum(w);
        fprintf('\tRel err: %e',abs(Ipf-Iml)/abs(Iml));
    end
end