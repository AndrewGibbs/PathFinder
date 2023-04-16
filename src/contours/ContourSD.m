 classdef ContourSD < handle
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
        %some parameters with default settings:
%         coarseTol = 1e-3;
%         fineTol = 1e-13;
        paramPathLength = 100
        minArgDist = pi/2;
%         leavesAnalyticRegion = false
        ICs %intiial conditions
        %quad bits:
        P0
        h = []
        dhdp
        Wgauss
        quadFreq
        polynomial = false
%         finitePathTrunc = 1.0
    end
    
    methods
        function self = ContourSD(startPoint, G, startCover, otherCovers, valleys, clusterIndices, clusterEndpoints, global_contour_params)
            
            %quick check
            if iscell(G)
                self.phaseDerivs = G;
                noReturnEvent = [];
            else
                self.polynomial = true;
                self.phaseCoeffs = G;
                self.phaseDerivs = getHandlesFromCoeffs(G);
                Cnr = getNoReturnConstant(G);
                noReturnEvent = @(p,h) noReturn(h,Cnr,angle(G(1)),valleys);
            end
            
            %construct an instance of this class
            self.startPoint = startPoint;
            self.paramOrder = startCover.orderSum;
            self.startCoverIndex = startCover.index;
%             [self.startClusterIndices, self.intervalEndpoint] = getClusterBuddies(clusterIndices, self.startCoverIndex, clusterEndpoints);
            
            self.ICs = [startPoint; 1i/self.phaseDerivs{2}(startPoint)];
            
            %need coarse path to be longer if there are more stationary
            %points
            
            %new streamlined version of ODE solver, much simpler than orig
            %PathFinder:
            [CPs, CPs_radii] = getBallDeets(otherCovers);
            max_steps_before_fail = global_contour_params.max_number_of_ODE_steps;

            [p_, h_, valley_index_, ball_index_] = SDpathODEuler_v3_mex(self.ICs(1), G, CPs, CPs_radii, valleys.', ...
            global_contour_params.step_size, int64(max_steps_before_fail), global_contour_params.r_star,...
            global_contour_params.NewtonBigThresh, global_contour_params.NewtonThresh);

            [p, self.coarsePath, valley_index, ball_index, Newton_points, Newton_its, Newton_fineal_pt_its] = SDpathODEuler_v4(self.ICs(1), G, CPs, CPs_radii, valleys.',...
            global_contour_params.step_size, int64(max_steps_before_fail), global_contour_params.r_star,...
            global_contour_params.NewtonBigThresh, global_contour_params.NewtonThresh, global_contour_params.log.Newton_its);
            
            % logging of Newton info:
            if global_contour_params.log.take && (global_contour_params.log.Newton_its>0)
                global_contour_params.log.add_to_log(sprintf('Contour from %.2f + %.2fi',real(startPoint),imag(startPoint)));
                for n=1:length(Newton_its)
                    global_contour_params.log.add_to_log(sprintf('\tPoint %.2f + %.2fi had %d Newton iterations',real(Newton_points(n)),imag(Newton_points(n)),Newton_its(n)));
                end
                if ~isempty(ball_index)
                    global_contour_params.log.add_to_log(sprintf('\tFinal point %.2f + %.2fi had %d Newton iterations',real(h_(end)),imag(h_(end)),Newton_fineal_pt_its));
                end
            end

%             plot(self.coarsePath,'-x');
%             hold on;
%             plot(h_,'-o');
%             hold off;
            if isempty(ball_index) %infinite contour
                self.length = inf;
                self.endValley = valleys(valley_index);
            else    %finite 
%                     self.endCoverIndex = otherCovers{ball_index}.index; %the cover which the contour hits
%                     [self.endClusterIndices, self.endClusterIntervalEndpoints] = getClusterBuddies(clusterIndices, self.endCoverIndex, clusterEndpoints);
                
%                     if use_refined_P_val
%                         self.length = P_refined;
%                     else
                self.length = p(end);
%                     end
                self.endValley = [];
                self.endPoint = self.coarsePath(end); % should have
%                     been taken care of further up
            end
            self.coarseParam = p;
        end
        
        function plot(self)
            grayColor = [.7 .7 .7];
            plot(self.coarsePath,'.:','Color',grayColor,'MarkerSize',4.5);
        end
        
        function [Z, W] = getQuad(self,freq,Npts,quad_params)
            self.quadFreq = freq;
            if isinf(self.length)
                %get relevant weighted Gauss quad rule:
                if strcmp(quad_params.inf_quad_rule,'laguerre')
                    [self.P0, self.Wgauss] = quad_gauss_exp(self.ODEorder, Npts);
                elseif strcmp(quad_params.inf_quad_rule,'legendre')
                    % COPIED CODE FROM BELOW, MAKE THIS INTO A FUNCTION 
                    IG_start_size = abs(exp(1i*freq*polyval(self.phaseCoeffs,self.startPoint)));
                    machine_precision_length = abs(log(quad_params.max_SP_integrand_val*quad_params.contourStartThresh/IG_start_size))/freq;
                    % now determine truncation parameter, based on optimal
                    % truncation vs discretisation of GauLeg:
                    optimal_truncation = quad_params.finitePathTruncL*Npts/freq;
                    trunc = freq*min(optimal_truncation, machine_precision_length);
                    [self.P0, self.Wgauss] = gauss_quad(0,trunc,Npts);
                else
                    error("Optional argument 'inf quad rule' must be either 'laguerre' or 'legendre'");
                end
                %scale by frequency and add zero
            else % finite path
                % determine the truncation parameter, based on when
                % integrand reaches machine precision:
                IG_start_size = abs(exp(1i*freq*polyval(self.phaseCoeffs,self.startPoint)));
                machine_precision_length = abs(log(quad_params.max_SP_integrand_val*quad_params.contourStartThresh/IG_start_size))/freq;
                % now determine truncation parameter, based on optimal
                % truncation vs discretisation of GauLeg:
                optimal_truncation = quad_params.finitePathTruncL*Npts/freq;
                % now combine all of these, accounting for p/\omega
                % scaling:
                trunc = freq*min([self.length, optimal_truncation, machine_precision_length]);
                [self.P0, self.Wgauss] = gauss_quad(0,trunc,Npts);
                self.P0=flipud(self.P0);
            end
%            
                % get SPs again (could just store them if they're going to
                % be this useful)
                order = length(self.phaseCoeffs)-1;
                Dpolycoeffs=self.phaseCoeffs(1:(order)).*fliplr(1:(order));

                % if largest p value of coarse solve is less than
                % largest p value of quad, trace further
                if max(self.P0) > freq*max(self.coarseParam)% global_contour_params.step_size, int64(max_steps_before_fail)
                    SPs = roots(Dpolycoeffs);
                    max_steps_before_fail = quad_params.max_number_of_ODE_steps;
                    [self.coarseParam, self.coarsePath, success] = ...
                        SDpathODEuler_extend_coarse_path_mex(self.coarseParam, self.coarsePath, self.phaseCoeffs, SPs, quad_params.global_step_size, int64(max_steps_before_fail), max(self.P0)/freq);
                    if ~success
                        warning('failed to converge extended contour');
                    end
                end

                [self.h, self.dhdp, Newton_success] = SDquadODEulerNEwtonCorrection_mex(self.P0, freq*self.coarseParam, self.ICs(1), self.coarsePath, self.phaseCoeffs, freq, quad_params.NewtonThresh, uint32(quad_params.NewtonIts));

                weightWatchers = ones(length(self.h),1);
                for n = 1:length(self.h)
                    if Newton_success(n) > quad_params.NewtonIts
                        warning(['Newton did not converge in ',num2str(quad_params.NewtonIts),' steps']);
                        weightWatchers(n) = exp(1i*(freq*self.phaseDerivs{1}(self.h(n))-1i*self.P0(n).^self.ODEorder - freq*self.phaseDerivs{1}(self.startPoint)));
                    end
                end
                weightWatchers = 1;
            
            if isinf(self.length) && strcmp(quad_params.inf_quad_rule,'laguerre')
                %absorb h'(p) and other constants into weights.
                W= exp(1i*freq*self.phaseDerivs{1}(self.startPoint)).*self.dhdp.*self.Wgauss.*weightWatchers;
            else
               W = self.dhdp.*self.Wgauss.*exp(1i*freq*self.phaseDerivs{1}(self.h)).*weightWatchers;
            end
            Z=self.h;
        end
         
        function [Z, W] = reuseQuad(self, G, errThresh)
            if nargin == 2
                errThresh = inf;
            end
            if ~isinf(errThresh) %tweak old SD path using Newton iteration
                Zold=self.h;
                p = self.P0;
                Z = NaN(size(Zold));
                dZdp = Z;
                for n = 1:length(Zold) %#ok<CPROPLC> %iterate over all quad points
                    [success, z_new] = NewtonSD(Zold(n),G,p(n),1,self.startPoint,1,errThresh);
                    if success
                        Z(n) = z_new;
                        dZdp(n) =  1i./G{2}(Z(n));
                    else
                        Z = Zold;
                        dZdp = self.dhdp;
                        warning('Failed to iterate to true SD path');
                        n = length(Zold) +1;
                        break;
                    end
                    clear z_new;
                end
            else
                Z = self.h;
                dZdp = self.dhdp;
            end
            g = G{1};
            if isinf(self.length)
                weightWatchers = exp(1i*(self.quadFreq*g(Z)-1i*self.P0.^self.ODEorder - self.quadFreq*g(self.startPoint)));
                %absorb h'(p) and other constants into weights.
%                 W = (1/(self.quadFreq^(1/self.ODEorder)))*exp(1i*self.quadFreq*g(self.startPoint))...
%                     .*dZdp.*self.Wgauss.*weightWatchers;
                W = exp(1i*self.quadFreq*g(self.startPoint)).*dZdp.*self.Wgauss.*weightWatchers;
            else
                W = dZdp.*self.Wgauss.*exp(1i*self.quadFreq*g(Z)) ;
            end
            
        end
    end
end

