function [phaseHandle, stationaryPoints] = NSDeetsFromPoly(polyCoeffs)
%returns all the relevant info needed by NSD given only the coefficients of
%the polynomial
    
    polyCoeffs = polyCoeffs(:).';

    order = length(polyCoeffs)-1;
    
    Dpolycoeffs=polyCoeffs(1:(order)).*fliplr(1:(order));
    stationaryPointsInit = sort(roots(Dpolycoeffs));
    stationaryPoints = stationaryPointsInit.';
    
    phaseHandle = @(z) polyval(polyCoeffs,z);
    
end

