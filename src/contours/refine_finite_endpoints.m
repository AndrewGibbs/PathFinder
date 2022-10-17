function quadIngredients = refine_finite_endpoints(quadIngredients, gCoeffs, freq, params)
    for n=1:length(quadIngredients)
        if strcmp(quadIngredients{n}.type, 'finSD')
            P_end_coarse = freq*quadIngredients{n}.contour.coarseParam(end);
            h0 = quadIngredients{n}.contour.startPoint;
            h_end_coarse = quadIngredients{n}.contour.endPoint;
            % keep P fixed, but refine the endpoint so it's consistent with
            % contour where quadrature will live
            [h_end_fine, ~, Newton_success] = ...
                SDquadODEulerNEwtonCorrection_mex(P_end_coarse, freq*quadIngredients{n}.contour.coarseParam, h0, quadIngredients{n}.contour.coarsePath, gCoeffs, freq, params.NewtonThresh, uint32(params.NewtonIts));
            if n>1 && strcmp(quadIngredients{n-1}.type,'strLn') && quadIngredients{n}.inOut == -1 && quadIngredients{n}.contour.endPoint==quadIngredients{n-1}.b
                % finite endpoint connects to previous straight line
                quadIngredients{n-1}.b = h_end_fine;
            elseif n<length(quadIngredients) && strcmp(quadIngredients{n+1}.type,'strLn')  && quadIngredients{n}.inOut == 1 && quadIngredients{n}.contour.endPoint==quadIngredients{n+1}.a
                % finite endpoint connects to next straight line
                quadIngredients{n+1}.a = h_end_fine;
%             else
%                 error('Cannot match refined endpoint of finite path');
            end
        end
    end
end