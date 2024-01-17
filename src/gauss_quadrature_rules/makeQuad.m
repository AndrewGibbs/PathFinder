% This routine pieces together all of the quadrature ingredients
% describing the sequence of SD and straight line contours, and allocates
% quadrature points along them.

% z is the complex nodes, w is the complex weights
function [z, w] = makeQuad(quadIngredients, freq, numPts, phaseFunction, params)

    % make sure there are at least two points on each contour
    numPts = max(numPts,2);

    QuadParams = struct(...%'step_size', params.quad_step_size, ...
                    'max_SP_integrand_val', params.max_SP_integrand_val, 'contourStartThresh', params.contourStartThresh,...
                    'finitePathTruncL',params.finitePathTruncL,'max_number_of_ODE_steps',params.max_number_of_ODE_steps,...
                    'NewtonThresh', params.NewtonThresh, 'NewtonIts', params.NewtonIts,...
                    'global_step_size',params.global_step_size, 'inf_quad_rule',params.inf_quad_rule,'mex',params.use_mex);


    % make a corretion for standard Gauss on the straight line contours,
    % which has a different weight function:
    sgw = @(z) exp(1i*freq*phaseFunction(z));

    % initialise nodes and weights
    z = [];
    w = [];

    for iQuad = 1:length(quadIngredients)
        if ~isempty(quadIngredients{iQuad})
            switch quadIngredients{iQuad}.type
                case {'infSD','finSD'}
                    %if steepest descent contour
                   [zTemp, wTempPreadjustment] = ...
                                quadIngredients{iQuad}.contour.getQuad(...
                                                freq, numPts, QuadParams);

                   % multiply by +-1 depending on if steepest descent
                   % contour is incoming or outgoing
                   wTemp = wTempPreadjustment*quadIngredients{iQuad}.inOut;

                case 'strLn'
                    % if straight line contour, inside ball
                    [zTemp, wTempPreadjustment, dh] = gaussQuadComplex(...
                                        quadIngredients{iQuad}.a,...
                                        quadIngredients{iQuad}.b,...
                                        ceil(quadIngredients{iQuad}.Nscale*numPts));
                    % the code 'Nscale*numPts' gives the option of scales
                    % the number of points inside balls if requested

                    % account for extra direction and exponential term in
                    % weights here
                    wTemp = wTempPreadjustment.*sgw(zTemp).*dh;
            end
        end

        % merge to the total quadrature rule
        z = [z; zTemp]; 
        w = [w; wTemp];
    end
end