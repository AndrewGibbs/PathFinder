% Some contour integrals will have a negligable value compared to others.
% This function removes those contours from the sequence, so quadrature
% points are only allocated along non-negligable conoturs.

% Here, information about each contour corresponds to a different
% 'quadrature ingredient'.
function [QuadIngredientArrayOut, maxIntegrand] =...
            fliterPaths(QuadIngredientArray, phaseFunction, freq, thresh)

    % initiliase a vector which stores key points along the deformation,
    % where we expect the largest values of the ingrand to occur.
    usedPoints = [];
    % following assigns an index to each quadrature ingredient, and links
    % this to the points in the above array
    quadIngredientIndices = [];
    % number of points to sample along straight line contours
    num_strln_samples = 3;

    % loop over array of structs describing contours
    quadIndex = 0;
    for quadIngredient = QuadIngredientArray
        quadIndex = quadIndex + 1;
        if ~isempty(quadIngredient{1}) % check ingredient is populated
            
            if strcmp(quadIngredient{1}.type,'infSD')
            % if unbounded SD contour
                usedPoints = [usedPoints quadIngredient{1}.contour.startPoint];
                quadIngredientIndices = [quadIngredientIndices quadIndex];
            elseif strcmp(quadIngredient{1}.type,'finSD')
            % if bounded SD contour
                % add both endpoints, as it's a finite path
                usedPoints = [usedPoints quadIngredient{1}.contour.startPoint...
                                quadIngredient{1}.contour.endPoint];
                % two points, so store index twice
                quadIngredientIndices = [quadIngredientIndices quadIndex quadIndex];
            elseif strcmp(quadIngredient{1}.type,'strLn')
            % if straight line contour
                usedPoints = [usedPoints linspace(quadIngredient{1}.a, ...
                                quadIngredient{1}.b, num_strln_samples)];
                % store index for each point in the below vector
                quadIngredientIndices = [quadIngredientIndices ...
                                        quadIndex*ones(1,num_strln_samples)];
            end
        end
    end

    % get estimate for max value of integrand along deformed path
    maxIntegrand = max(abs(exp(1i*freq*phaseFunction(usedPoints))));
    % reset index counter, now use for quadrature ingredients which aren't
    % discarded:
    quadIndex = 0;
    for iQuadIngredient = 1:length(QuadIngredientArray)
        % filter usedPoints which are relevant to this contour/ingredient
        relevantPoints = usedPoints(quadIngredientIndices == iQuadIngredient);
        keepIngredient = false;

        % if, for any relevantPoints, the integrand is above the threshold,
        % keep the entire integrient
        for iPoints = relevantPoints
            % check if value at key points is non-negligable compared with
            % elsewhere, if so, keep ingredient
            if maxIntegrand*thresh <= abs(exp(1i*freq*phaseFunction(iPoints)))
                keepIngredient = true;
            end
        end

        if keepIngredient
            % add to output
            quadIndex = quadIndex + 1;
            QuadIngredientArrayOut{quadIndex} = QuadIngredientArray{iQuadIngredient};
        end
    end
end