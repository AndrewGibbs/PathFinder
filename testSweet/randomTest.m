function fullPass = randomTest(tries)

if nargin == 0
    tries = 1;
end

Npts = 25;
Pmax = 5;
freqMax = 10000;
minErr = 1e-5;
numFails = 0;

%randomly choose degree of polynomial:

    for tryNum=1:tries
        ranData{tryNum}.a = -5*rand;
        ranData{tryNum}.b = 5*rand;
        
        ranData{tryNum}.deg = ceil(Pmax*rand());

        ranData{tryNum}.coeffs = 10*rand(ranData{tryNum}.deg,1);
        
        ranData{tryNum}.freq = 10^(log10(freqMax)*rand);
        
        g = @(x) polyval(ranData{tryNum}.coeffs,x);
        
        J = integral(@(x) exp(1i*ranData{tryNum}.freq*g(x)), ranData{tryNum}.a, ranData{tryNum}.b);
        
        fprintf('\n\nTrying:\n a=%.2f, b=%.2f, g(x)=%s', ranData{tryNum}.a, ranData{tryNum}.b, getPolyString(ranData{tryNum}.coeffs));
        
        try
            [~,w] = PathFinderQuad(ranData{tryNum}.a, ranData{tryNum}.b, ranData{tryNum}.coeffs, ranData{tryNum}.freq, Npts);
            I = sum(w);
            ranData{tryNum}.absErr = abs(I-J);
            ranData{tryNum}.pass = true;
            
            if ranData{tryNum}.absErr < minErr
                ranData{tryNum}.accurate = true;
            else
                ranData{tryNum}.accurate = false;
            end
            
        catch
            ranData{tryNum}.pass = false;
            ranData{tryNum}.accurate = false;
        end
        
        if ranData{tryNum}.accurate == false
           numFails = numFails + 1;
           fails{numFails} =  ranData{tryNum};
           fprintf('\nfailed for these parameters');
        else
           fprintf('\nabs error: %e',ranData{tryNum}.absErr);
        end
        
    end

    if numFails > 0
        fullPass = false;
        save('randFailData','fails');
    else
        fullPass = true;
    end
    
    function s = getPolyString(P)
       s = '';
       for n = 1:(length(P)-1)
          s = [s sprintf('%.2fx^%d + ',P(n),length(P)-n)]; 
       end
       s = [s sprintf('%.2f',P(end))];
    end

end

