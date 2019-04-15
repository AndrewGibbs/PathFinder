function pass = LinearTest(Npts)
    if nargin == 0
        Npts = 10;
    end
    n = 1;
    f = @(x) sin(sin(x));
    for freq = 10.^[2 3 4]
        [z w] = PathFinderQuad(-1, 1, [1 0], freq, Npts, false);
        J = f(z).'*w;
        I = integral(@(x) f(x).*exp(1i*freq*x),-1,1);
        err(n) = abs(I-J)/abs(I);
        fprintf('\nfreq:%d\terr:%e',freq,err(n));
        n = n+1;
    end
    pass = true;
end