function [z,w] = PathFinderQuad(a, b, phaseIn, freq, Npts, varargin)
%Construct weights and nodes to numerically evaluate an oscillatory
%integral.
%PathFinderQuad(a, b, G, freq, N, infContour)
%returns weights and nodes for efficient evaluation of oscillatory
%integral of f(z)exp(i*k*g(z))dz from a to b, for analytic f & g.
%
%phaseIn is either the coefficients of a polynomial g, or a cell array of
%anonymous functions corresponding to successive derivatives of an analytic
%function g: G = {g, g', g'', ...}
%
%a and b are either finite enpoints, or (in the case where the integral is an infinite contour)
%angles of valleys in the complex plane. The entries of (optional) two-dimensional
%flag infContour flag if the endpoint of the integral is infinite.
%
%k is the frequency parameter of the integral
%
%N is the number of points used per segment of the PathFinder routine

    params = opionalExtras(varargin);
    
    %get info about stationary points:
    [phase_handles, stationaryPoints, stationaryPointsOrders, valleys] = getInfoFromPhase(phaseIn);
    
    %cover each stationary point:
    [covers, intersectionMatrix, clusters, clusterEndpoints, HermiteCandidates, endPointIndices, standardQuadFlag]...
            = getInteriorBalls(phase_handles{1},freq,stationaryPoints,params.infContour,a,b, stationaryPointsOrders, params.numOscs);
        %used to be getCovers(...), new code is almost the same
        
    if standardQuadFlag
        [z, w_, dh] = GQfancy(covers, a, b, endPointIndices(1), endPointIndices(2), intersectionMatrix, Npts);
        w = w_.*exp(1i*freq*phase_handles{1}(z)).*dh;
        if params.plot
            plotAll(covers, [], z, a, b, params.infContour, stationaryPoints);
        end
        return;
    end
    
    %make the contours from each cover:
    %contours = getContours(phase_handles, covers, valleys, clusters, clusterEndpoints, endPointIndices);
    contours = getContours(phaseIn, covers, valleys, clusters, clusterEndpoints, endPointIndices);
    
    %choose the path from a to b
    quadIngredients = shortestInfinitePathV3(contours, covers, intersectionMatrix, valleys, a, b, endPointIndices, params.infContour, HermiteCandidates,clusters);

    %get quadrature points
    [z, w, HermiteInds] = makeQuadV3(quadIngredients, freq, Npts, phase_handles, covers, intersectionMatrix, params);
    
    %make a plot of what's happened, if requested
    if params.plot
        plotAll(covers, contours, z, a, b, params.infContour, stationaryPoints, HermiteInds);
    end
end