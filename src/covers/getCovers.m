function [covers, intersectionMatrix, clusters, clusterEndpoints, HermiteCandidates] = getCovers(g,freq,SPs,infContour,a,b,SPorders)

    Cosc = 1;
    
    coverIndex = 1;
    if ~infContour
       for endpoint = [a b]
           endPointBalls(coverIndex) = Ball(0,endpoint,g,coverIndex,0);
           coverIndex = coverIndex + 1;
       end
    else
        endPointBalls = [];
    end
    
    %coversInit = [];
    if ~isempty(SPs)>0
        for n = 1:length(SPs)
            coversInit(n) = ContourInterior(SPs(n),freq,g,coverIndex,Cosc,SPorders(n));
            coverIndex = coverIndex + 1;
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