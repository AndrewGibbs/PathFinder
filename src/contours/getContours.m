function contours = getContours(G, covers, valleys, endPointIndices, params)
% G can be phase handles, or the original coefficients
    global_contour_params = struct( ...
        'step_size', params.global_step_size, 'max_number_of_ODE_steps', params.max_number_of_ODE_steps,...
        'NewtonThresh',params.NewtonThresh, 'NewtonIts', params.NewtonIts,'r_star',params.r_star,...
        'NewtonBigThresh',params.NewtonBigThresh,'log',params.log,'mex',params.use_mex) ;
    %contours = [];
    contour_count = 0;
     for n = 1:length(covers)
        if ismember(n,endPointIndices)%~infContour && ismember(n,[1 2])
            intervalEndpoint = covers{n}.centre;
        else
            intervalEndpoint = [];
        end
        for xi = covers{n}.steepestExits
            [CPs, CPs_radii] = getBallDeets(coversComplement(n));
            SPs = CPs(CPs_radii>0);
            cover_radii = CPs_radii(CPs_radii>0);
            if ~inAball(xi, SPs, cover_radii)
                contour_count = contour_count + 1;
                %contours = [contours ContourSD(xi,G,covers{n},coversComplement(n),valleys,global_contour_params)];
                contours(contour_count) = ContourSD(xi,G,covers{n},coversComplement(n),valleys,global_contour_params);
            end
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

