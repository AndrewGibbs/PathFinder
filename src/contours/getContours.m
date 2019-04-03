function contours = getContours(G, covers, infContour, valleys, clusters, clusterEndpoints)

    contours = [];
     for n = 1:length(covers)
        if ~infContour && ismember(n,[1 2])
            intervalEndpoint = covers(n).centre;
        else
            intervalEndpoint = [];
        end
        for xi = covers(n).steepestExits
            contours = [contours ContourSD(xi,G,covers(n),[covers(1:(n-1)) covers((n+1):end)],valleys,clusters,clusterEndpoints)];
        end
     end
end

