function [covers, intersectionMatrix, clusters, clusterEndpoints] = getCovers(g,freq,SPs,infContour,a,b)

    x = linspace(-2.5,2.5,500);
    C = 1;
    
    coverIndex = 1;
    if ~infContour
       for endpoint = [a b]
           endPointBalls(coverIndex) = Ball(0,endpoint,g,coverIndex,0);
           coverIndex = coverIndex + 1;
       end
    else
        endPointBalls = [];
    end
    
    for n = 1:length(SPs)
        coversInit(n) = ContourInterior(SPs(n),x,x,freq,g,coverIndex,C);
        coverIndex = coverIndex + 1;
    end

    %delete exits inside a cover from another mother:
    
    covers = [num2cell(endPointBalls) num2cell(deleteRedundantExits(coversInit))];

    %now determine which covers overlap:
    [intersectionMatrix, clusters, clusterEndpoints] = coverOverlapV2(covers);
    
end