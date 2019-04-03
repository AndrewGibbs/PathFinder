function delta = deltaEst(g, order, c, r)
%estimates the distance delta, by which polynomial coefficients can change
    theta = linspace(0,2*pi,1000);
    z = c + r*exp(1i*theta);
    U = min(abs(g(z)));
    
    Sum = 1;
    for k = 1:(order-1)
        Sum = Sum + abs(z.^k);
    end
    rho = max(Sum);
    
    delta = U/rho;
end

