function pass = QuadraticTest(Npts)
if nargin == 0
    Npts = 20;
end

n = 1;

    for ab={[-1 0],[-1 1],[0 1]}
        a = ab{1}(1);
        b = ab{1}(2);
        f = @(x) x.^4;
        for freq = 10.^[2 3 4]
            [z w] = PathFinderQuad(a, b, [1 0 0], freq, Npts);
            J = f(z).'*w;
            I = integral(@(x) f(x).*exp(1i*freq*x.^2),a, b);
            err(n) = abs(I-J);
            fprintf('\nfreq:%d\terr:%e',freq,err(n));
            n = n+1;
        end
    end
    
    if max(err)<1e-7
        pass = true;
    else
        pass = false;
    end
end