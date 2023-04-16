function contours = getContours(G, covers, valleys, clusters, clusterEndpoints, endPointIndices, params)
% G can be phase handles, or the original coefficients
    global_contour_params = struct( ...
        'step_size', params.global_step_size, 'max_number_of_ODE_steps', params.max_number_of_ODE_steps,...
        'NewtonThresh',params.NewtonThresh, 'NewtonIts', params.NewtonIts,'r_star',params.r_star,...
        'NewtonBigThresh',params.NewtonBigThresh,'log',params.log) ;
    contours = [];
     for n = 1:length(covers)
        if ismember(n,endPointIndices)%~infContour && ismember(n,[1 2])
            intervalEndpoint = covers{n}.centre;
        else
            intervalEndpoint = [];
        end
        for xi = covers{n}.steepestExits
            contours = [contours ContourSD(xi,G,covers{n},coversComplement(n),valleys,clusters,clusterEndpoints,global_contour_params)];
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

