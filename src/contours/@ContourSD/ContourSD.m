%Steepest descent contour object, containing information about coarse 
% contour approximation, and information needed to produce quadrature
classdef ContourSD
    
    properties
        startPoint % start of approximate contour, steepest exit
        endPoint % end of approximate contour
        startCoverIndex % index of the ball in which contour starts
        endCoverIndex = [] % (possible) index of ball where contour ends
        coarsePath % array of complex points approximating contour
        coarseParam % parameter p in h(p), corresponding to above array
        length % max value of the parameter p, can be infinite for infinite paths
        endValley = []% (possible) valley where path converges
        phaseCoeffs % coefficients of phase function
        phaseDerivs % coefficients of derivatives of phase function
        ICs % initial conditions for ODE solve, (h(0), h'(0))
    end
    
    methods
        % ------------------------ constructor  ------------------------- %
        function self = ContourSD(startPoint, G, startCover, otherCovers, ...
                        valleys, ContourParams)
            
            % allocate coefficients for phase and derivs
            self.phaseCoeffs = G;
            self.phaseDerivs = getHandlesFromCoeffs(G);
            
            % allocate initial conditions for contour
            self.startPoint = startPoint;
            self.startCoverIndex = startCover.index;
            self.ICs = [startPoint; 1i/self.phaseDerivs{2}(startPoint)];
            
            % get information about the other balls (not the one where
            % this contour starts).
            [otherCPs, otherCPsRadii] = getBallDeets(otherCovers);
            maxStepsBeforeFail = ContourParams.maxNumODEsteps;

            % approximate the path using Euler-Newton predictor-corrector
            % will/won't use MEX function, as required.
            if ContourParams.mex
                [self.coarseParam, self.coarsePath, valley_index, other_ball_index] ...
                    = sdPathODEeulerMex(self.ICs(1), G(:), otherCPs(:), otherCPsRadii(:), valleys(:),...
                ContourParams.stepSize, int64(maxStepsBeforeFail), ContourParams.rStar,...
                ContourParams.NewtonThresh, ContourParams.NewtonBigThresh);
            else
                [self.coarseParam, self.coarsePath, valley_index, other_ball_index] ...
                    = SDpathODEuler_v4(self.ICs(1), G, otherCPs, otherCPsRadii, valleys.',...
                ContourParams.stepSize, int64(maxStepsBeforeFail), ContourParams.rStar,...
                ContourParams.NewtonThresh, ContourParams.NewtonBigThresh);
            end

            if isempty(other_ball_index)
            % if contour is infinite

                %thus, infinite length
                self.length = inf;
                % record index of valley where contour converges
                self.endValley = valleys(valley_index);
            else    
            % otherwise, contour is finite 

                % get information about the end of the path
                self.length = self.coarseParam(end);
                self.endPoint = self.coarsePath(end);

                % adjust for possible index shift of 'other' balls:
                if other_ball_index>=self.startCoverIndex
                    % add one
                    self.endCoverIndex = other_ball_index + 1;
                else
                    % they're the same
                    self.endCoverIndex = other_ball_index;
                end

            end
        end
        
        % --------------- prototypes for other methods  ------------------ %

        % contour plotting method
        plot(self,varargin)
        
        % routine to allocate quadrature nodes
        [z, w, newtonIts] = getQuad(self, freq, Npts, quad_params)
    end
end

