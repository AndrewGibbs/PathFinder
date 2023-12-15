function [Z, W] = getQuad(self,freq,Npts,quad_params)
    self.quadFreq = freq;
    if isinf(self.length)
        %get relevant weighted Gauss quad rule:
        if strcmp(quad_params.inf_quad_rule,'laguerre')
            [P0, Wgauss] = quad_gauss_exp(self.ODEorder, Npts);
        elseif strcmp(quad_params.inf_quad_rule,'legendre')
            % COPIED CODE FROM BELOW, MAKE THIS INTO A FUNCTION 
            IG_start_size = abs(exp(1i*freq*polyval(self.phaseCoeffs,self.startPoint)));
            machine_precision_length = abs(log(quad_params.max_SP_integrand_val*quad_params.contourStartThresh/IG_start_size))/freq;
%                     machine_precision_length = abs(log(quad_params.max_SP_integrand_val*quad_params.contourStartThresh))/freq;
            % now determine truncation parameter, based on optimal
            % truncation vs discretisation of GauLeg:
            optimal_truncation = quad_params.finitePathTruncL*Npts/freq;
            trunc = freq*min(optimal_truncation, machine_precision_length);
            [P0, Wgauss] = gauss_quad(0,trunc,Npts);
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
        [P0, Wgauss] = gauss_quad(0,trunc,Npts);
        P0=flipud(P0);
    end
%            
        % get SPs again (could just store them if they're going to
        % be this useful)
        order = length(self.phaseCoeffs)-1;
        Dpolycoeffs=self.phaseCoeffs(1:(order)).*fliplr(1:(order));

        % if largest p value of coarse solve is less than
        % largest p value of quad, trace further
        if max(P0) > freq*max(self.coarseParam)% global_contour_params.step_size, int64(max_steps_before_fail)
            SPs = roots(Dpolycoeffs);
            max_steps_before_fail = quad_params.max_number_of_ODE_steps;
            if quad_params.mex
                [self.coarseParam, self.coarsePath, success] = ...
                    SDpathODEuler_extend_coarse_path_mex(self.coarseParam, self.coarsePath, self.phaseCoeffs(:), SPs, quad_params.global_step_size, int64(max_steps_before_fail), max(P0)/freq);
            else
                [self.coarseParam, self.coarsePath, success] = ...
                    SDpathODEuler_extend_coarse_path(self.coarseParam, self.coarsePath, self.phaseCoeffs, SPs, quad_params.global_step_size, int64(max_steps_before_fail), max(P0)/freq);
            end
            if ~success
                warning('failed to converge extended contour');
            end
        end
        
        %_mex
        if quad_params.mex
            [h, dhdp, Newton_success] = SDquadODEulerNEwtonCorrection_mex(P0, freq*self.coarseParam, self.ICs(1), self.coarsePath, self.phaseCoeffs(:), freq, quad_params.NewtonThresh, uint32(quad_params.NewtonIts));
        else
            [h, dhdp, Newton_success] = SDquadODEulerNEwtonCorrection(P0, freq*self.coarseParam, self.ICs(1), self.coarsePath, self.phaseCoeffs, freq, quad_params.NewtonThresh, uint32(quad_params.NewtonIts));
        end

        weightWatchers = ones(length(h),1);
        for n = 1:length(h)
            if Newton_success(n) > quad_params.NewtonIts
                warning(['Newton did not converge in ',num2str(quad_params.NewtonIts),' steps']);
                weightWatchers(n) = exp(1i*(freq*self.phaseDerivs{1}(h(n))-1i*P0(n).^self.ODEorder - freq*self.phaseDerivs{1}(self.startPoint)));
            end
        end
        weightWatchers = 1;
    
    if isinf(self.length) && strcmp(quad_params.inf_quad_rule,'laguerre')
        %absorb h'(p) and other constants into weights.
        W= exp(1i*freq*self.phaseDerivs{1}(self.startPoint)).*dhdp.*Wgauss.*weightWatchers;
    else
       W = dhdp.*Wgauss.*exp(1i*freq*self.phaseDerivs{1}(h)).*weightWatchers;
    end
    Z=h;
end