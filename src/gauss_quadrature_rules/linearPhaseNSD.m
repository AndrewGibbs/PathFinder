% simple function which produces steepest descent contours for linear
% phase function, with finite endpoints.

% It is assumed that the phase function is of the form g(x)=mx+c.
% As usual, the endpoints are {a,b}.
function [z,w] = linearPhaseNSD(a, b, freq, m, c, numPts)

    % define the phase function in terms of the two coefficients
    g = @(z) m*z + c;

    % get the Gauss Laguerre points
    [pGauLag, wGauLag] = gausLagHC(numPts);

    % get quadrature nodes for the steepest descent paths from the first 
    % endpoint a, and the second endpoint b
    za = a+1i*pGauLag/(freq*m);
    zb = b+1i*pGauLag/(freq*m);
    
    % get quadrature weights for first and second contour respectively
    wa =  wGauLag*1i*exp(1i*freq*g(a))/(freq*m);
    wb = -wGauLag*1i*exp(1i*freq*g(b))/(freq*m);
    % note the minus sign for the second *incoming* contour

    % piece everything together as a quadrature rule which can output
    z = [za; zb];
    w = [wa; wb];
end