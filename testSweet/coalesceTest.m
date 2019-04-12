function passTest = coalesceTest(Npts)
disp('Tests coalesence of cubic stationary point, for range of frequenceies and epsilons');
%tests coalescing stationary points, the most problematic / least stable
% type of problem

if nargin == 0
    Npts = 50;
end
    coalesps = [.1 0.01 0.001 0.0001];
    omegas = [500 1000 10000 100000];

    n = 0;
    for coalesp = coalesps
        n = n + 1;
        fprintf('\ncoalescence: %.3f',coalesp);
        m = 0;
        for freq = omegas
            m = m + 1;
            fprintf('\n\tfreq = %d',freq);
            g = @(x) x.^3/3 - coalesp^2*x;
            Iml = integral(@(x) exp(1i*freq*g(x)),-1,1,'ArrayValued',true,'RelTol',1e-15);
            coeffs = [1/3 0 -coalesp^2 0];
            %[z,w] = quadBodge(-1,1,coeffs,freq,Npts);
            [z,w] = PathFinderQuad(-1,1, coeffs, freq, Npts, false);
            Ipf = sum(w);
            err(n,m) = abs(Ipf-Iml)/abs(Iml);
            fprintf('\tRel err: %e',err(n,m));
        end
    end
    
    MaxErr = max(max(err));
    
    if MaxErr < 1e-5
        passTest = true;
    else
        passTest = false;
    end
end

