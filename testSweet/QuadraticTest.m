function pass = QuadraticTest(Npts)
    if nargin == 0
        Npts = 50;
    end
    n = 1;
    for freq = 10.^[2 4 6 8]
        [z w] = PathFinderQuad(-1, 1, [1 0 0], freq, Npts, false);
        I = integral(@(x) exp(1i*freq*x.^2),-1,1);
        err(n) = abs(I-sum(w))/abs(I);
        fprintf('\nfreq:%d\terr:%e',freq,err(n));
        n = n+1;
    end
    pass = true;
end