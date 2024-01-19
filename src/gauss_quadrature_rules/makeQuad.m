% This routine pieces together all of the quadrature ingredients
% describing the sequence of SD and straight line contours, and allocates
% quadrature points along them.

% z is the complex nodes, w is the complex weights
function [z, w, logOut] = makeQuad(quadIngredients, freq, numPts, phaseFunction, params)

    % initialise blank log of performance data
    logOut = [];
    logOutCount = 0;

    % make sure there are at least two points on each contour
    numPts = max(numPts,2);

    QuadParams = struct(...%'step_size', params.quad_step_size, ...
                    'maxSPintegrandVal', params.maxSPintegrandVal, ...
                    'contourStartThresh', params.contourStartThresh,...
                    'finitePathTruncL',params.finitePathTruncL, ...
                    'maxNumODEsteps',params.maxNumODEsteps,...
                    'NewtonThresh', params.NewtonThresh, ...
                    'NewtonIts', params.NewtonIts,...
                    'globalStepSize', params.globalStepSize, ...
                    'infQuadRule', params.infQuadRule, ...
                    'mex', params.useMex, ...
                    'log', params.log);


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
                   [zTemp, wTempPreadjustment, logOutIterationData] = ...
                                quadIngredients{iQuad}.contour.getQuad(...
                                                freq, numPts, QuadParams);

                   % multiply by +-1 depending on if steepest descent
                   % contour is incoming or outgoing
                   wTemp = wTempPreadjustment*quadIngredients{iQuad}.inOut;

                   % log the newton iterations, if requested
                   if params.log.take
                       logOutCount = logOutCount + 1;
                       logOut{logOutCount} = logOutIterationData;
                   end

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