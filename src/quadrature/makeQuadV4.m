function [z, w, HermiteInds] = makeQuadV4(quadInfo, freq, Npts, g, params)

    Npts = max(Npts,2); % TO DO: check this is still necessary

    quad_params = struct('step_size', params.quad_step_size, ...
                    'max_SP_integrand_val', params.max_SP_integrand_val, 'contourStartThresh', params.contourStartThresh,...
                    'finitePathTruncL',params.finitePathTruncL,'max_number_of_ODE_steps',params.max_number_of_ODE_steps,...
                    'NewtonThresh', params.NewtonThresh, 'NewtonIts', params.NewtonIts,...
                    'global_step_size',params.global_step_size, 'inf_quad_rule',params.inf_quad_rule);


    %make a corretion for standard Gauss, which has a different weight
    %function:
    sgw = @(z) exp(1i*freq*g(z));
    z = []; w = []; HermiteInds = [];

    for n = 1:length(quadInfo)
        if ~isempty(quadInfo{n})
            switch quadInfo{n}.type
                case {'infSD','finSD'}
                   [z_, w__] = quadInfo{n}.contour.getQuad(freq,Npts, quad_params);
                   w_ = w__*quadInfo{n}.inOut;
                case 'strLn'
                   [z_, w__, dh_] = gauss_quad_complex(quadInfo{n}.a,quadInfo{n}.b,ceil(quadInfo{n}.Nscale*Npts));
                   w_ = w__.*sgw(z_).*dh_;
            end
        end

        %add to the total quadrature
        z = [z; z_]; 
        w = [w; w_];

    end