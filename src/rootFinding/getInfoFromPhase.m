function [phase,stationaryPoints,stationaryPointsOrders,valleys] = getInfoFromPhase(phaseIn)
%determines stationary points from phase function, which may be
%input as coefficients of a polynomial, or (soon) a cell array of anonymous
%functions

stationaryPointMinDist = .001;

    if isvector(phaseIn)
        [phase,stationaryPoints,stationaryPointsOrders] = NSDeetsFromPoly(phaseIn, stationaryPointMinDist);
        order = length(phaseIn)-1;
        valleyRotate = exp(-1i*angle(phaseIn(1))/order);
        valleys = valleyRotate*exp(2i*pi*(1/4 + (1:order))/order);
    elseif iscell(phaseIn) %user has given anonymous function cell array
        error('Have not yet coded this on latest version of PathFinder');
    else 
        error('Phase input must be either cell array of anonymous functions, or coefficients of polynomial');
    end
end

