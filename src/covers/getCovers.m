function [covers, intersectionMatrix, clusters, clusterEndpoints, HermiteCandidates, endPointIndices] = getCovers(g,freq,SPs,infContour,a,b,SPorders, Cosc)

    coverIndex = 0;
    endPointBalls = [];
    endPointIndices = [];
    
    maybzEndpoints = [a b];
    for m = [1 2]
       if ~infContour(m)
           coverIndex = coverIndex + 1;
           endPointBalls = [endPointBalls Ball(0,maybzEndpoints(m),g,coverIndex,0)];
           endPointIndices = [endPointIndices coverIndex];
       end
    end
    
    if ~isempty(SPs)>0
        for n = 1:length(SPs)
            coverIndex = coverIndex + 1;
            coversInit(n) = ContourInterior(SPs(n),freq,g,coverIndex,Cosc,SPorders(n));
        end

        %delete exits inside a cover from another mother:

        covers = [num2cell(endPointBalls) num2cell(deleteRedundantExits(coversInit))];
    else
        covers = num2cell(endPointBalls);
    end

    %now determine which covers overlap:
    [intersectionMatrix, clusters, clusterEndpoints] = coverOverlapV2(covers);
    
    HermiteCandidates = getHermiteCandidates(clusters, clusterEndpoints, covers);
    
end