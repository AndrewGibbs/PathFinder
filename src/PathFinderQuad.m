function [z,w] = PathFinderQuad(a, b, phaseIn, freq, nPts, varargin)
% Construct weights and nodes to numerically evaluate an oscillatory
% integral.
%[z,w] = PathFinderQuad(a, b, G, k, N)
% Here the parameters are the same as for 'PathFinder', except there is no
% function handle input, and the weights and nodes are output.
%
% See also PathFinder

% PathFinder is provided under an MIT license, for more details see
% LICENSE in the root directory.

    %% preprocessing
    % get first nonzero entry
    firstNonzeroPhaseIndex = find(phaseIn~=0,1,'first');
    phaseIn = phaseIn(firstNonzeroPhaseIndex:end);

    %% set parameters
    params = optionalExtras(length(phaseIn)-1,varargin);

    %% special cases
    % check if standard quadrature is appropriate, if so, do that & terminate early
    if ((~params.infContour(1)) && (~params.infContour(2)) ...
        && checkEndpointWidth(a, b, phaseIn, freq, params.numOscs,...
            params.numRays, params.interiorBalls, params.imagThresh, params.useMex)) ||...
            (length(phaseIn)==1)

        [z, w_, dh_] = gaussQuadComplex(a,b,nPts);
        sgw = @(z) exp(1i*freq*polyval(phaseIn,z));
        w = w_.*dh_.*sgw(z);

       if params.plot
            plotAll([], [], z, a, b, params.infContour, [], [], []);
        end
       return
    end

    if length(phaseIn)<=2 % if linear phase
        if sum(params.infContour)>0
            error(['Unbounded contour will not converge for linear phase if' ...
                ' amplitude function is entire.']);
        end
        % contour can be computed instantly without approximation, reduce to this
        [z,w] = linearPhaseNSD(a,b,freq,phaseIn(1),phaseIn(2),nPts);
        if params.plot
            plotAll([], [], z, a, b, params.infContour, [], [], []);
        end
        return;
    end

    %% main algorithm

    if params.log.take
        logMexUsage(params);
    end

    %get info about stationary points:
    [phaseHandle, stationaryPoints, valleys] = getInfoFromPhase(phaseIn);

    % get r* parameter used for determining regions of no return
    params.rStar = getRStar(phaseIn);

    % rotate inf valleys if required:
    [a,b,params] = JordanRotate(a,b,valleys,params);
    
    coverTic = tic;
    %cover each stationary point:
    [covers, ~]...
            = getExteriorBalls(phaseHandle,freq,stationaryPoints,params.infContour,a,b, ...
            params.numOscs, phaseIn, params.ballMergeThresh,params.numRays, ...
            params.interiorBalls, params.imagThresh, params.useMex);
    if params.log.take
        params.log.addToLog(sprintf("Ball construction:\t%fs",toc(coverTic)));
    end
    
    contourTic = tic;
    %make the contours from each cover:
    contourArray = getContours(phaseIn, covers, valleys, params);
    if params.log.take
        logContourDetails(params, contourArray, toc(contourTic));
    end

    %choose the path from a to b
    GraphTic = tic;
    [QuadIngredients, GraphData] = shortestInfinitePath(a, b, contourArray,...
                                    covers, valleys, params);
    if params.log.take
        params.log.addToLog(sprintf("Dijkstra shortest path:\t%fs",toc(GraphTic)));
    end
    
    if params.contourStartThresh==0
        params.maxSPintegrandVal = inf;
    else
        % filter out SD contours which are of much smaller value, or empty
        [QuadIngredients, params.maxSPintegrandVal] = fliterPaths(QuadIngredients, phaseHandle, freq, params.contourStartThresh);
        if isinf(params.maxSPintegrandVal)
            error("Integral is infinite");
        elseif params.maxSPintegrandVal>1E16
            warning("Integral is greater than 1e16");
        elseif params.maxSPintegrandVal<1E-16
            warning("Integral is less than 1e-16");
        end
    end

    %get quadrature points
    quadTic = tic;
    [z, w, netwonIterationData] = makeQuad(QuadIngredients, freq, nPts, ...
                                            phaseHandle, params);
    if params.log.take
        logQuadratureDetails(params, netwonIterationData, toc(quadTic));
    end

    %make a plot of what's happened, if requested
    if params.plot
        plotAll(covers, contourArray, z, a, b, params.infContour, stationaryPoints, phaseIn, valleys);
    end

    % plot the graph representing the deformation, if requested
    if params.plotGraph
        finiteEndpoints = [a b];
        finiteEndpoints = finiteEndpoints(~params.infContour)+1i*eps;
        plotGraph(GraphData, covers, finiteEndpoints);
    end
end