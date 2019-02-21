function [contoursOut] = getSDtopology(G,SPs_init,order,a,b,visuals,infCountour, freq)
%determines a sequence of contours in complex plane, which can subsequently
%be used to generate multiple quadrature routines
    ballRadScale = .5;
    valleys = exp(2i*pi*(1/4 + (1:order))/order);
    stationaryPointMinDist = 1e-4; %merge balls if stationary points are this close
    
    ballIndex = 1;
    if ~infCountour
       for endpoint = [a b]
           endPointBalls(ballIndex) = Ball(0,endpoint,G{1},ballIndex,0);%IntervalEndPoint(endpoint,G{1},0);
           ballIndex = ballIndex + 1;
       end
    end
    
    %sort and contain stationary points
    if ~isempty(SPs_init)
        
        [SPs, SPorders, clumpWidth] = sortStationaryPoints(SPs_init,stationaryPointMinDist);
        
        SPorders = 2;
        
        for n = 1:length(SPs)
            %ballsInit(n) = Ball(ballRad+clumpWidth(n),SPs(n),G{1},ballIndex,SPorders(n));
            ballRad = (ballRadScale+clumpWidth(n))/(freq^(1/(SPorders(n)+1)));
            ballsInit(n) = Ball(ballRad,SPs(n),G{1},ballIndex,SPorders(n));
            ballIndex = ballIndex + 1;
        end
    else
        ballsInit = [];
    end
    
    
    %crude algorithm which clumps balls together when they overlap
    balls = [endPointBalls deleteRedundantExits(ballsInit)];
    %balls = ballsInit;

    %get adjacency info for overlapping covers/balls
    [intersectionMatrix, clusters, clusterEndpoints] = ballOverlap(balls);
    
    %now construct the contours
    contours = [];
    for n = 1:length(balls)
        if ~infCountour && ismember(n,[1 2])
            intervalEndpoint = balls(n).centre;
        else
            intervalEndpoint = [];
        end
        for xi = balls(n).steepestExits
            contours = [contours ContourSD(xi,G,balls(n),[balls(1:(n-1)) balls((n+1):end)],valleys,clusters,clusterEndpoints)];
        end
    end
    contours = deleteRedudantContours(contours);
    
    contourSeq = shortestInfinitePath(contours, balls, intersectionMatrix, valleys, a, b, infCountour);
    
    contoursOut = contours(contourSeq);
    
    if visuals
        plotAll(balls,contoursOut);
    end
    
end

