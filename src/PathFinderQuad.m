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
    
    %get info about stationary points:
    [phase_handles, stationaryPoints, stationaryPointsOrders, valleys] = getInfoFromPhase(phaseIn);

    params = opionalExtras(varargin);

    % rotate inf valleys if required:
    [a,b,params] = Jordan_rotate(a,b,valleys,params);
    
    %cover each stationary point:
    [covers, intersectionMatrix, clusters, clusterEndpoints, HermiteCandidates, endPointIndices, standardQuadFlag]...
            = getInteriorBalls(phase_handles{1},freq,stationaryPoints,params.infContour,a,b, stationaryPointsOrders, ...
            params.numOscs, params.Hermite, phaseIn);
        %used to be getCovers(...), new code is almost the same

    % test this new guy out
    tic;
    get_interior_ball_mex(phaseIn.', freq, stationaryPoints(1), uint32(stationaryPointsOrders(1)), params.numOscs);
    new_time = toc;
        
%     if standardQuadFlag
%         [z, w_, dh] = GQfancy(covers, a, b, endPointIndices(1), endPointIndices(2), intersectionMatrix, Npts);
%         w = w_.*exp(1i*freq*phase_handles{1}(z)).*dh;
%         if params.plot
%             plotAll(covers, [], z, a, b, params.infContour, stationaryPoints, [], phaseIn);
%         end
%         return;
%     end
    
    %make the contours from each cover:
    %contours = getContours(phase_handles, covers, valleys, clusters, clusterEndpoints, endPointIndices);
    contours = getContours(phaseIn, covers, valleys, clusters, clusterEndpoints, endPointIndices, params);

    %choose the path from a to b
    quadIngredients = shortestInfinitePathV4(a,b,contours, covers, valleys, params);
%     quadIngredients = shortestInfinitePathV3(contours, covers, intersectionMatrix, valleys, a, b, endPointIndices, params.infContour, HermiteCandidates,clusters);
    
    % filter out SD contours which are of much smaller value, or empty
    [quadIngredients, params.max_SP_integrand_val] = fliter_paths_v2(quadIngredients, phase_handles{1}, freq, params.contourStartThresh);

    if params.contourStartThresh==0
        %fliter_paths(quadIngredients, covers, intersectionMatrix, phase_handles{1}, freq, params.contourStartThresh);
        params.max_SP_integrand_val = inf;
    end

    % refine the endpoints of the finite paths (not at SEs), as these need
    % to connect exactly to straight line contours inside of balls, but
    % currently these are based on coarse approximations.
    quadIngredients = refine_finite_endpoints(quadIngredients, phaseIn, freq, params);

    %get quadrature points
%     [z, w, HermiteInds] = makeQuadV3(quadIngredients, freq, Npts, phase_handles, covers, intersectionMatrix, params);
    [z, w, HermiteInds] = makeQuadV4(quadIngredients, freq, Npts, phase_handles{1}, params);

    %make a plot of what's happened, if requested
    if params.plot
        plotAll(covers, contours, z, a, b, params.infContour, stationaryPoints, HermiteInds, phaseIn);
    elseif params.plotCovers
        plotCovers(covers);
    elseif params.plotContours
        plotContours(contours,[a b stationaryPoints],quadIngredients)
    elseif params.plotSpecial
        coverinds = [3,4];
        plotUsed(covers, coverinds, contours([1,2,4,5]),z);
    end
end