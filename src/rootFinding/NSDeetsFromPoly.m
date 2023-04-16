function [G,stationaryPoints] = NSDeetsFromPoly(polyCoeffs, stationaryPointMinDist)
%returns all the relevant info needed by NSD given only the coefficients of
%the polynomial
    
    polyCoeffs = polyCoeffs(:).';
    
%     if nargin == 1
%         %if two stationary points are this close, make them one
%         stationaryPointMinDist=0.001;
%     end

    order = length(polyCoeffs)-1;
    
    %use Matlab's roots function to get the data about the stationary
    %points.
    
    Dpolycoeffs=polyCoeffs(1:(order)).*fliplr(1:(order));
    stationaryPointsInit = sort(roots(Dpolycoeffs));
    stationaryPoints = stationaryPointsInit.';
    
%     if ~isempty(stationaryPointsInit)
%         %now sort stationary points, and group nearby stationary points:
%         [stationaryPoints,stationaryPointsOrders] = sortStationaryPoints(stationaryPointsInit,stationaryPointMinDist);
%     else
%         stationaryPoints = [];
%         stationaryPointsOrders = [];
%     end
    
    G = getHandlesFromCoeffs(polyCoeffs);
    
end

