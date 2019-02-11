function [contoursOut] = getSDtopology(G,SPs_init,order,a,b,visuals,infCountour)
%determines a sequence of contours in complex plane, which can subsequently
%be used to generate multiple quadrature routines
    ballRad = .5;
    valleys = exp(2i*pi*(1/4 + (1:order))/order);
    stationaryPointMinDist = 1e-4; %merge balls if stationary points are this close
    
    [SPs, SPorders, clumpWidth] = sortStationaryPoints(SPs_init,stationaryPointMinDist);
    %roots at +-1
    ballIndex = 1;
    if ~infCountour
       for endpoint = [a b]
           endPointBalls(ballIndex) = Ball(0,endpoint,G{1},ballIndex,0);
           ballIndex = ballIndex + 1;
       end
    end
    for n = 1:length(SPs)
        ballsInit(n) = Ball(ballRad+clumpWidth(n),SPs(n),G{1},ballIndex,SPorders(n));
        ballIndex = ballIndex + 1;
    end
    
    %crude algorithm which clumps balls together when they overlap
    balls = [endPointBalls deleteRedundantExits(ballsInit)];
    %balls = ballsInit;
    
    %get adjacency info for overlapping covers/balls
    [intersectionMatrix, clusters] = ballOverlap(balls);
    
    %now construct the contours
    contours = [];
    for n = 1:length(balls)
        for xi = balls(n).steepestExits
            contours = [contours ContourSD(xi,balls(n).orderSum,G,balls(n),[balls(1:(n-1)) balls((n+1):end)],valleys,clusters)];
        end
    end
    contours = deleteRedudantContours(contours);
    
    contourSeq = shortestInfinitePath(contours, balls, intersectionMatrix, valleys, a, b, infCountour);
    
    contoursOut = contours(contourSeq);
    
    if visuals
        plotAll(balls,contoursOut);
    end
    
end

