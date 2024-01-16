 classdef ContourSD %<handle
    %Steepest descent contour object
    
    properties
        startPoint
        endPoint
        startCoverIndex
        endCoverIndex = []
        startClusterIndices
        endClusterIndices = []
        intervalEndpoint = []
        endClusterIntervalEndpoints = []
        coarsePath
        coarseParam
        coarsePathGrad
        length
        endValley %may be unpopulated if finite length
        paramOrder
        ODEorder = 1
        phaseDerivs
        phaseCoeffs
        minArgDist = pi/2;
        ICs
        quadFreq
        polynomial = true
    end
    
    methods
        function self = ContourSD(startPoint, G, startCover, otherCovers, valleys, global_contour_params)
            
            self.phaseCoeffs = G;
            self.phaseDerivs = getHandlesFromCoeffs(G);
            
            %construct an instance of this class
            self.startPoint = startPoint;
            self.startCoverIndex = startCover.index;

            self.ICs = [startPoint; 1i/self.phaseDerivs{2}(startPoint)];
            
            %need coarse path to be longer if there are more stationary
            %points
            
            %new streamlined version of ODE solver, much simpler than orig
            %PathFinder:
            [other_CPs, other_CPs_radii] = getBallDeets(otherCovers);
            max_steps_before_fail = global_contour_params.max_number_of_ODE_steps;

            if global_contour_params.mex
                [p, self.coarsePath, valley_index, other_ball_index] ...
                    = SDpathODEuler_v4_mex(self.ICs(1), G(:), other_CPs(:), other_CPs_radii(:), valleys(:),...
                global_contour_params.step_size, int64(max_steps_before_fail), global_contour_params.r_star,...
                global_contour_params.NewtonThresh, global_contour_params.NewtonBigThresh, int64(global_contour_params.log.Newton_its));
            else
                [p, self.coarsePath, valley_index, other_ball_index] ...
                    = SDpathODEuler_v4(self.ICs(1), G, other_CPs, other_CPs_radii, valleys.',...
                global_contour_params.step_size, int64(max_steps_before_fail), global_contour_params.r_star,...
                global_contour_params.NewtonThresh, global_contour_params.NewtonBigThresh);
            end
            
            % logging of Newton info:
            if global_contour_params.log.take && (global_contour_params.log.Newton_its>0)
                global_contour_params.log.add_to_log(sprintf('Contour from %.2f + %.2fi',real(startPoint),imag(startPoint)));
                for n=1:length(Newton_its)
                    global_contour_params.log.add_to_log(sprintf('\tPoint %.2f + %.2fi had %d Newton iterations',real(Newton_points(n)),imag(Newton_points(n)),Newton_its(n)));
                end
                if ~isempty(other_ball_index)
                    global_contour_params.log.add_to_log(sprintf('\tFinal point %.2f + %.2fi had %d Newton iterations',real(h_(end)),imag(h_(end)),Newton_fineal_pt_its));
                end
            end

            if isempty(other_ball_index) %infinite contour
                self.length = inf;
                self.endValley = valleys(valley_index);
            else    %finite 
                self.length = p(end);
%                     end
                self.endValley = [];
                % adjust for possible index shift of 'other' balls:
                if other_ball_index>=self.startCoverIndex
                    % add one
                    self.endCoverIndex = other_ball_index + 1;
                else
                    % they're the same
                    self.endCoverIndex = other_ball_index;
                end

                self.endPoint = self.coarsePath(end); % should have
%                     been taken care of further up
            end
            self.coarseParam = p;
        end
        
        plot(self,varargin)
        
        [Z, W] = getQuad(self,freq,Npts,quad_params)
    end
end

