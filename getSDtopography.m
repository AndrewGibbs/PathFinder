function contoursOut = getSDtopography(G,SPs_init,order,aValley,bValley,visuals)
%determines a sequence of contours in complex plane, which can subsequently
%be used to generate multiple quadrature routines
    ballRad = .35;
    valleys = exp(2i*pi*(1/4 + (1:order))/order);
    
    [SPs, SPorders, clumpWidth] = sortStationaryPoints(SPs_init,ballRad);
    %roots at +-1
    ballIndex = 1;
    for n = 1:length(SPs)
        ballsInit(n) = Ball(ballRad+clumpWidth(n),SPs(n),G{1},ballIndex,SPorders(n));
        ballIndex = ballIndex + 1;
    end
    
    %crude algorithm which clumps balls together when they overlap
    balls = ballsInit;
    for n=1:length(ballsInit)
        balls = ballClump(balls, G{1});
    end
    %have to loop it incase new balls overlap too... definately a more
    %elegant way to do this!

    contours = [];
    for n = 1:length(balls)
        for xi = balls(n).steepestExits
            contours = [contours ContourSD(xi,balls(n).orderSum,G,balls(n),[balls(1:(n-1)) balls((n+1):end)],valleys)];
        end
    end

    contourSeq = shortestInfinitePath(contours, balls, valleys, aValley, bValley);
    
    contoursOut = contours(contourSeq);
    
    if visuals
        plotAll(balls,contoursOut);
    end
    
end

