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
            [self.startClusterIndices, self.intervalEndpoint] = getClusterBuddies(clusterIndices, self.startCoverIndex, clusterEndpoints);
            
            self.ICs = [startPoint; 1i/self.phaseDerivs{2}(startPoint)];
            
            %need coarse path to be longer if there are more stationary
            %points
            
            %new streamlined version of ODE solver, much simpler than orig
            %PathFinder:
            if strcmp(global_contour_params.solver,'Euler')
                use_refined_P_val = false;
                [CPs, CPs_radii] = getBallDeets(otherCovers);
                max_steps_before_fail = global_contour_params.max_number_of_ODE_steps;%10000;
                max_retrys = 10;
                success = false;
                num_retrys = 0;
%                 while ~success && num_retrys<max_retrys
%                     tic;
%                     [p, self.coarsePath, valley_index, ball_index, success] = ...
%                         SDpathODEuler_v2_mex(self.ICs(1), G, CPs, CPs_radii, valleys.', ...
%                             global_contour_params.step_size/(2^num_retrys), int64(max_steps_before_fail)*(4^num_retrys), global_contour_params.r_star);
%                     old_coarse_approx_time = toc    
%                     temp_Newton_big_thresh = 10^-4;
%                     tic;
                            [p, self.coarsePath, valley_index, ball_index, success] = SDpathODEuler_v3_mex(self.ICs(1), G, CPs, CPs_radii, valleys.', ...
                            global_contour_params.step_size, int64(max_steps_before_fail), global_contour_params.r_star,...
                            global_contour_params.NewtonBigThresh, global_contour_params.NewtonThresh);
%                     new_coarse_approx_time = toc  
                    if ~isempty(ball_index) && false
                        if length(self.coarsePath) > 1
                        % finite contour - need to check approximation of endpoint is sufficiently accurate
    
                        % guess at point on circumferance of ball where
                        % contour intersects
                            SEn_guess = make_SEn_guess(self.coarsePath(end),length(self.coarsePath(end))-1,otherCovers{ball_index}.centre,otherCovers{ball_index}.radius);
                        % now refine this point, by finding all values on
                        % circle where real part is value of contour
                            [SEn_refined, P_refined, ~] = get_stepest_entrances_on_ball(G, otherCovers{ball_index}.centre, otherCovers{ball_index}.radius,...
                                                                        self.ICs(1), SEn_guess);
                        % check that the new steepest entrance isn't too far from
                        % what we started with
                            max_deviation = global_contour_params.step_size*otherCovers{ball_index}.radius;
                            if abs(self.coarsePath(end)-SEn_refined)<max_deviation %use refined version for Newton solve
                                success = true;
                                SEn_n = SEn_refined;
                                use_refined_P_val = true;
                            else % if not, try to refine with Newton iteration
                                [SEn_n, success] = SE_NEwtonCorrection_mex(p(end), self.coarsePath(end), self.ICs(1), G, ...
                                                    global_contour_params.NewtonThresh, uint32(global_contour_params.NewtonIts),...
                                                    otherCovers{ball_index}.centre, global_contour_params.step_size);
                            end
                            if success
                                self.endPoint = SEn_n;
                            else
                                warning('Steepest descent contour may end in a ball, finer step size is needed to be sure');
                            end
                        else % contour starts in another ball, should be from a finite endpoint
                            success = true;
                            self.endPoint = self.coarsePath;
                        end
                    end
%                     num_retrys = num_retrys + 1;
%                 end
%                 if ~success
%                     max_retrys = 10;
%                     for n=1:max_retrys
%                         warning(sprintf('Euluer solve did not converge in time for this path, retrying step size %e and %d steps',...
%                             global_contour_params.step_size*2^(-n), max_steps_before_fail*4^n));
%                             [p, self.coarsePath, valley_index, ball_index, success] = ...
%                                 SDpathODEuler_v2_mex(self.ICs(1), G, CPs, CPs_radii, valleys.', ...
%                                 global_contour_params.step_size*2^(-n), int64(max_steps_before_fail*4^n), global_contour_params.r_star);
%                         if success && ~isempty(ball_index)
%                                                 SEn_guess = make_SEn_guess(self.coarsePath(end),self.coarsePath(end-1),otherCovers{ball_index}.centre,otherCovers{ball_index}.radius);
%                         [SEn_refined, P_refined, ~] = get_stepest_entrances_on_ball(G, otherCovers{ball_index}.centre, otherCovers{ball_index}.radius,...
%                                                                 self.ICs(1), SEn_guess);
% %                             max_deviation = step_size_adjust*otherCovers{ball_index}.radius;
%                             if abs(self.coarsePath(end)-SEn_refined)<max_deviation %use refined version for Newton solve
%                                 success = true;
%                                 SEn_n = SEn_refined;
%                                 use_refined_P_val = true;
%                             else
%                                 [SEn_n, success] = SE_NEwtonCorrection_mex(p(end), self.coarsePath(end),...
%                                                 self.ICs(1), G, global_contour_params.NewtonThresh, uint32(global_contour_params.NewtonIts),...
%                                                 otherCovers{ball_index}.centre, global_contour_params.step_size);
%                             end
%                             if success
%                                 self.endPoint = SEn_n;
%                             else
%                                 warning('Steepest descent contour may end in a ball, finer step size is needed to be sure');
%                             end
%                         end
%                         if success
%                             break;
%                         end
%                     end
%                 end
                
                if isempty(ball_index) %infinite contour
                    self.length = inf;
                    self.endValley = valleys(valley_index);
                else    %finite 
                    self.endCoverIndex = otherCovers{ball_index}.index; %the cover which the contour hits
                    [self.endClusterIndices, self.endClusterIntervalEndpoints] = getClusterBuddies(clusterIndices, self.endCoverIndex, clusterEndpoints);
                    
                    if use_refined_P_val
                        self.length = P_refined;
                    else
                        self.length = p(end);
                    end
                    self.endValley = [];
                    self.endPoint = self.coarsePath(end); % should have
%                     been taken care of further up
                end
                self.coarseParam = p;


            elseif strcmp(global_contour_params.solver,'ODE45')
                
                order = length(valleys);
                
                self.paramPathLength = self.paramPathLength^(order+1);
%                 tic;
                [p, self.coarsePath, self.coarsePathGrad] = SDpathODE(self.paramPathLength, self.phaseDerivs{2}, 1, self.ICs(1)+eps*1i, global_contour_params.step_size, noReturnEvent);
%                 RK_time = toc;
                %add the first p=0 to the above, just incase we stray
                %immediately into a NaN:
                p = [0; p];
                self.coarsePath = [self.ICs(1); self.coarsePath];
                self.coarsePathGrad = [self.ICs(2); self.coarsePathGrad];
                
                %check if path isin any of the covers, truncate it if it is
                
                contourInCover = zeros(size(self.coarsePath));
                contourNaNcover = zeros(size(self.coarsePath));
                
                for cover = otherCovers
                    if iscell(cover)
                        cover = cover{1};
                    end
                    contourInCover_yn = zeros(size(self.coarsePath));
                    contourInCover_yn = contourInCover_yn + cover.isIn(self.coarsePath);
                    contourInCover = max( contourInCover , contourInCover_yn.*cover.index);
                    contourNaNcover = max( contourNaNcover , isnan(self.coarsePath) );
                    %NaNs are typically a sign of passing through another
                    %stationary point, although this will only happen if
                    %inside another ComplexCover anyway
                end
                
                %now piece these infos together to decide where the contour
                %should end:
                
                contourEndIndex = min([find(contourInCover,true),find(contourNaNcover,true)]);
                %find(contourInOutOfAnalDomain_yn,true)]
                
                if isempty(contourEndIndex) %infinite contour
                    self.length = inf;
                    self.endValley = getValleyOfNoReturn(self.coarsePath(end),valleys);
                else    %finite contour
                    if ~self.leavesAnalyticRegion
                        self.endCoverIndex = contourInCover(contourEndIndex); %the cover which the contour hits
                        [self.endClusterIndices, self.endClusterIntervalEndpoints] = getClusterBuddies(clusterIndices, self.endCoverIndex, clusterEndpoints);
                    end
                        %contourEndIndex = max(contourEndIndex-1,1); %take one off, to be sure of ending before it hits
                        contourEndIndex = max(contourEndIndex,2);
                    self.length = p(contourEndIndex);
                    self.coarsePath = self.coarsePath(1:contourEndIndex);
                    self.endValley = [];
                    self.endPoint = self.coarsePath(contourEndIndex);
                end
            end
        end
        
        function plot(self)
%             if nargin == 1
%                 linestyle ='-.k';
%             end
%             if nargin <= 2
%                 linewidth = 1.0;
%             end
            grayColor = [.7 .7 .7];
            plot(self.coarsePath,'.:','Color',grayColor,'MarkerSize',4.5);
        end
        
        function [Z, W] = getQuad(self,freq,Npts,quad_params)% should absorb Turbo into quad struct
            self.quadFreq = freq;
            if isinf(self.length)
                %get relevant weighted Gauss quad rule:
                [self.P0, self.Wgauss] = quad_gauss_exp(self.ODEorder, Npts);
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
            
            if strcmp(quad_params.solver,'ODE45')
                [~, self.h, self.dhdp] = SDpathODE(self.P0, self.phaseDerivs{2}, freq, self.ICs(1), quad_params.step_size);
            elseif strcmp(quad_params.solver,'Euler')
%                 tic;
                % get SPs again (could just store them if they're going to
                % be this useful)
                order = length(self.phaseCoeffs)-1;
                Dpolycoeffs=self.phaseCoeffs(1:(order)).*fliplr(1:(order));
%                 SPs = sort(roots(Dpolycoeffs));
%                 [self.h, self.dhdp, Newton_success] = SDquadODEulerNEwton(self.P0, self.ICs(1), self.phaseCoeffs, SPs, freq);

                % if largest p value of coarse solve is less than
                % largest p value of quad, trace further.

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
%                 Euler_time = toc;

                weightWatchers = ones(length(self.h),1);
                for n = 1:length(self.h)
                    if Newton_success(n) > quad_params.NewtonIts
                        warning(['Newton did not converge in ',num2str(quad_params.NewtonIts),' steps']);
                        weightWatchers(n) = exp(1i*(freq*self.phaseDerivs{1}(self.h(n))-1i*self.P0(n).^self.ODEorder - freq*self.phaseDerivs{1}(self.startPoint)));
                    end
                end
                weightWatchers = 1;
            elseif strcmp(quad_params.solver,'Taylor')%(p,x,G,freq)
                self.h = SteepestExit_Taylor(self.P0, self.ICs(1), self.phaseCoeffs, freq, quad_params.Taylor_terms);
                self.dhdp = 1i./(freq*self.phaseDerivs{2}(self.h));
            end
            
            %this adjusts for small deviations from the path:
            if strcmp(quad_params.solver,'ODE45') || strcmp(quad_params.solver,'Taylor')
                tic;
                if quad_params.turbo
                    weightWatchers = 1;%./weightWatchers;
                    errThresh = 1e-12;
                    Zold=self.h;
                    Z = NaN(size(Zold));
                    dZdp = Z;
                    NewtonSuccess = true;
                    for n = 1:length(Zold) %#ok<CPROPLC> %iterate over all quad points
                        [success, z_new] = NewtonSD(Zold(n),self.phaseDerivs,self.P0(n),1,self.startPoint,freq,errThresh);
                        if success
                            Z(n) = z_new;
                            dZdp(n) =  1i./(freq*self.phaseDerivs{2}(Z(n)));
                        else
                            NewtonSuccess = false;
                            break;
                        end
                        clear z_new;
                    end
                    if NewtonSuccess
                        self.h = Z;
                        self.dhdp = dZdp;
                    end
                else
                    NewtonSuccess = false;
                end
                Newton_time = toc;
                
                if ~NewtonSuccess
                    weightWatchers = exp(1i*(freq*self.phaseDerivs{1}(self.h)-1i*self.P0.^self.ODEorder - freq*self.phaseDerivs{1}(self.startPoint)));
                end
            end
            
            if isinf(self.length)
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

