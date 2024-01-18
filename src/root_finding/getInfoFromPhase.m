function [phase,stationaryPoints,valleys] = getInfoFromPhase(phaseIn)
%determines stationary points from phase function, which may be
%input as coefficients of a polynomial, or (soon) a cell array of anonymous
%functions

    if isvector(phaseIn)
        [phase,stationaryPoints] = NSDeetsFromPoly(phaseIn);
        order = length(phaseIn)-1;
        valleyRotate = exp(-1i*angle(phaseIn(1))/order);
        valleys = valleyRotate*exp(2i*pi*(1/4 + (1:order))/order);
    else 
        error('Phase input must be array of coefficients of polynomial');
    end
end

