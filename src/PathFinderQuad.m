function [z,w] = PathFinderQuad(a, b, phaseIn, freq, nPts, varargin)
%Construct weights and nodes to numerically evaluate an oscillatory
%integral.
%[z,w] = PathFinderQuad(a, b, G, k, N, infContour)
%returns weights w and nodes z for efficient evaluation of oscillatory
%integral of f(z)exp(i*k*g(z))dz from a to b, for analytic f & g.
%
%G is either the coefficients of a polynomial, in standard Matlab
%format: G(1)*X^N + ... + G(N)*X + phaseIn(N+1)
%
%a and b are either finite endpoints, or (in the case where the integral is an infinite contour)
%angles of valleys in the complex plane. The entries of (optional) two-dimensional
%flag infContour flag if the endpoint of the integral is infinite.
%
%k is the frequency parameter of the integral
%
%N is the number of points used per segment of the PathFinder routine.
%
%A large number of optional inputs are available. For more information,
%see
%<a href="matlab:web('www.github.com/AndrewGibbs/PathFinder','-browser')">github.com/AndrewGibbs/PathFinder</a>

    %% preprocessing
    % get first nonzero entry
    first_nonzero_index = find(phaseIn~=0,1,'first');
    phaseIn = phaseIn(first_nonzero_index:end);

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
            plotAll([], [], z, a, b, params.infContour, [], [], [], []);
        end
       return
    end

    if length(phaseIn)<=2 % if linear phase
        % contour can be computed instantly without approximation, reduce to this
        [z,w] = linearPhaseNSD(a,b,freq,phaseIn(1),phaseIn(2),nPts);
        if params.plot
            plotAll([], [], z, a, b, params.infContour, [], [], [], []);
        end
        return;
    end

    %% main algorithm

    %get info about stationary points:
    [phaseHandle, stationaryPoints, valleys] = getInfoFromPhase(phaseIn);

    % get r* parameter used for determining regions of no return
    params.r_star = getRStar(phaseIn);

    % rotate inf valleys if required:
    [a,b,params] = JordanRotate(a,b,valleys,params);
    
    tic;
    %cover each stationary point:
    [covers, ~]...
            = getExteriorBalls(phaseHandle,freq,stationaryPoints,params.infContour,a,b, ...
            params.numOscs, phaseIn, params.ballMergeThresh,params.numRays, ...
            params.interiorBalls, params.imagThresh, params.useMex);
    if params.log.take
        params.log.addToLog(sprintf("Ball construction:\t%fs",toc));
    end
    
    tic;
    %make the contours from each cover:
    contourArray = getContours(phaseIn, covers, valleys, params);
    if params.log.take
        params.log.addToLog(sprintf("Contour coarse construction:\t%fs", toc));
        % also log the number of points in the coarse approximation of each
        % contour:
        for iCount = 1:length(contourArray)
            contPts = length(contourArray(iCount).coarsePath);
            if sign(imag(contourArray(iCount).startPoint))<0
                ipm = '-';
            else
                ipm = '+';
            end
            params.log.addToLog(sprintf("\tContour %d: start point " + ...
                "%.2f%s%.2fi,\tlength %.2f,\t%d pts", ...
                iCount, real(contourArray(iCount).startPoint), ipm,...
                abs(imag(contourArray(iCount).startPoint)), ...
                contourArray(iCount).length, contPts));
        end
    end

    %choose the path from a to b
    tic;
    [QuadIngredients, GraphData] = shortestInfinitePath(a, b, contourArray,...
                                    covers, valleys, params);
    if params.log.take
        params.log.addToLog(sprintf("Dijkstra shortest path:\t%fs",toc));
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
    tic;
    [z, w, netwonIterationData] = makeQuad(QuadIngredients, freq, nPts, phaseHandle, params);
    if params.log.take
        params.log.addToLog(sprintf("Quadrature allocation time:\t%fs",toc));
        for i = 1:length(netwonIterationData)
            newtonSummaryString = [];
            for n = (netwonIterationData{i}.')
                newtonSummaryString = ...
                    [newtonSummaryString, ' ', num2str(n)];
            end
            params.log.addToLog(sprintf( ...
                "\tNewton refinement steps:\t%s", newtonSummaryString));
        end
    end

    %make a plot of what's happened, if requested
    if params.plot
        plotAll(covers, contourArray, z, a, b, params.infContour, stationaryPoints, phaseIn, valleys);
    end

    if params.plotGraph
        finiteEndpoints = [a b];
        finiteEndpoints = finiteEndpoints(~params.infContour)+1i*eps;
        plotGraph(GraphData, covers, finiteEndpoints);
    end
end