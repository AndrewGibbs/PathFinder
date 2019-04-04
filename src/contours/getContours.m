function contours = getContours(G, covers, infContour, valleys, clusters, clusterEndpoints)

    contours = [];
%      for n = 1:length(covers)
%         if ~infContour && ismember(n,[1 2])
%             intervalEndpoint = covers(n).centre;
%         else
%             intervalEndpoint = [];
%         end
%         for xi = covers(n).steepestExits
%             contours = [contours ContourSD(xi,G,covers(n),[covers(1:(n-1)) covers((n+1):end)],valleys,clusters,clusterEndpoints)];
%         end
%      end
     for n = 1:length(covers)
        if ~infContour && ismember(n,[1 2])
            intervalEndpoint = covers{n}.centre;
        else
            intervalEndpoint = [];
        end
        for xi = covers{n}.steepestExits
            contours = [contours ContourSD(xi,G,covers{n},coversComplement(n),valleys,clusters,clusterEndpoints)];
        end
     end
     
     
    function coversOut = coversComplement(n)
        numCovers = length(covers);
        coversOut = [];
        for m=1:(n-1)
            coversOut{m}=covers{m};
        end
        for m=(n+1):numCovers
            coversOut{m-1}=covers{m};
        end
     end

end

