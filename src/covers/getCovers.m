function [covers, intersectionMatrix, clusters, clusterEndpoints] = getCovers(g,freq,SPs,infCountour)

    x = linspace(-2.5,2.5,500);
    C = 1;
    
    if ~infCountour
       for endpoint = [a b]
           endPointBalls(ballIndex) = Ball(0,endpoint,G{1},ballIndex,0);%IntervalEndPoint(endpoint,G{1},0);
           ballIndex = ballIndex + 1;
       end
    else
        endPointBalls = [];
    end
    
    for n = 1:length(SPs)
        coversInit(n) = ContourInterior(SPs(n),x,x,freq,g,n,C);
    end

    %delete exits inside a cover from another mother:
    covers = deleteRedundantExits(coversInit);

    %now determine which covers overlap:
    [intersectionMatrix, clusters, clusterEndpoints] = coverOverlap(coversInit);
    
end