function contours = getContours(G, covers, valleys, clusters, clusterEndpoints, endPointIndices)

    contours = [];
     for n = 1:length(covers)
        if ismember(n,endPointIndices)%~infContour && ismember(n,[1 2])
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

