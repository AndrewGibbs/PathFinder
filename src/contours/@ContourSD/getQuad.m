% Routine which allocates quadrature nodes and weights for evaluation of a
% contour integral.

function [hArray, wArray] = getQuad(self, freq, numPts, QuadParams)
% the two outputs are the complex quadrature nodes and weights respectively

    % if the contour is unbounded
    if isinf(self.length)
        %get relevant weighted Gauss quad rule:
        if strcmp(QuadParams.inf_quad_rule,'laguerre')
            % get Gauss Laguerre weights and nodes
            [gaussNodes, gaussWeights] = gausLagHC(numPts);
        elseif strcmp(QuadParams.inf_quad_rule,'legendre')
            % We will use truncated Gauss Legendre. First, determine the
            % truncation point, see paper for details.

            % Estimate the size of the integrand at the start of the
            % contour integral.
            integrandStartSize = ...
                abs(exp(1i*freq*polyval(self.phaseCoeffs,self.startPoint)));

            % Estimate how far along the contour (in terms of
            % parametrisation variable) the integrand drops below machine
            % precision (which can be modified by used)
            machinePrecisionLength = ...
                abs(log(QuadParams.max_SP_integrand_val*...
                QuadParams.contourStartThresh/integrandStartSize))/freq;

            % now determine truncation parameter, based on optimal
            % truncation vs discretisation of GauLeg:
            optimalTruncation = QuadParams.finitePathTruncL*numPts/freq;
            trunc = freq*min(optimalTruncation, machinePrecisionLength);
            % get (scaled) Gauss Legendre weights and nodes
            [gaussNodes, gaussWeights] = gauss_quad(0,trunc,numPts);
        else
            error("Optional argument 'inf quad rule' must " + ...
                    "be either 'laguerre' or 'legendre'");
        end
    else % finite path
        % In the case of a finite (bounded) contour, we use truncated Gauss
        % Legendre (as above) but now there is a third max value, based on
        % the length of the contour
        integrandStartSize = ... 
            abs(exp(1i*freq*polyval(self.phaseCoeffs,self.startPoint)));
        machinePrecisionLength = ...
                    abs(log(QuadParams.max_SP_integrand_val*...
                    QuadParams.contourStartThresh/integrandStartSize))/freq;
        % optimal truncation is now based on finite path length
        optimalTruncation = QuadParams.finitePathTruncL*numPts/freq;
        % now combine all of these, accounting for p/\omega
        % scaling:
        trunc = freq*min([self.length, optimalTruncation, ...
                            machinePrecisionLength]);
        % get (scaled) Gauss Legendre weights and nodes
        [gaussNodes, gaussWeights] = gauss_quad(0,trunc,numPts);
        gaussNodes=flipud(gaussNodes);
    end

    % if largest p value of coarse solve is less than
    % largest p value of quad, trace further so we have a good initial
    % guess for the refinement/corrector step later
    if max(gaussNodes) > freq*max(self.coarseParam)
        % get polynomial order from length of phase coefficients
        order = length(self.phaseCoeffs)-1;
        % get coefficients of derivative of phase
        diffPhaseCoeffs=self.phaseCoeffs(1:(order)).*fliplr(1:(order));
        % get stationary points
        stationaryPoints = roots(diffPhaseCoeffs);
        % extend the coarse path, using mex function if specified
        if QuadParams.mex
            [self.coarseParam, self.coarsePath, success] = ...
                SDpathODEuler_extend_coarse_path_mex(self.coarseParam, ...
                self.coarsePath, self.phaseCoeffs(:), stationaryPoints, ...
                QuadParams.global_step_size, ...
                int64(QuadParams.max_number_of_ODE_steps), max(gaussNodes)/freq);
        else
            [self.coarseParam, self.coarsePath, success] = ...
                SDpathODEuler_extend_coarse_path(self.coarseParam, ...
                self.coarsePath, self.phaseCoeffs, stationaryPoints, ...
                QuadParams.global_step_size, ...
                int64(QuadParams.max_number_of_ODE_steps), max(gaussNodes)/freq);
        end
        if ~success
            warning('failed to converge extended contour');
        end
    end
    
    % using coarse path, interpolate for initial guess, and refine/correct
    % using Newton iteration to get the quadrature points
    if QuadParams.mex
        [hArray, jacobianArray, NewtonSuccess] = ...
            SDquadODEulerNEwtonCorrection_mex(gaussNodes, ...
            freq*self.coarseParam, self.ICs(1), self.coarsePath, ...
            self.phaseCoeffs(:), freq, QuadParams.NewtonThresh, ...
            uint32(QuadParams.NewtonIts));
    else
        [hArray, jacobianArray, NewtonSuccess] = ...
            SDquadODEulerNEwtonCorrection(gaussNodes, ...
            freq*self.coarseParam, self.ICs(1), self.coarsePath, ...
            self.phaseCoeffs, freq, QuadParams.NewtonThresh, ...
            uint32(QuadParams.NewtonIts));
    end

    % the points in hArray above will be the quadrature nodes
    % construct quadrature weights using Jacobian dhdp
    if isinf(self.length) && strcmp(QuadParams.inf_quad_rule,'laguerre')
        wArray= exp(1i*freq*self.phaseDerivs{1}(self.startPoint)).*jacobianArray.*gaussWeights;
    else
       % for Gauss Legendre, need to explicitly include the phase function
       wArray = jacobianArray.*gaussWeights.*exp(1i*freq*self.phaseDerivs{1}(hArray));
    end
end