function options = optionalExtras(freq,order,varargin)
    %allows user to manually adjust default parameters, like plotting etc
    
     if length(varargin)==1 && ~ischar(varargin{1})
        %glitchy Matlab varagin thing, only an issue when this function 
        %call's it's self recursively. Fix it here:
        varargin=varargin{1};
    end
    
    %set defaults:
%         'quad_step_size',1e-13, ...
    options = struct('plot', false, 'plot_graph',false,...
        'infContour', [false false], 'numOscs', 2*pi, ...
        'contourStartThresh',1e-16,'num_rays',uint32(16),...
        'global_step_size',0.1,'max_number_of_ODE_steps',50000,...
        'inf_quad_rule','laguerre',...
        'NewtonThresh',10^(-13),'NewtonBigThresh',1e-2,'NewtonIts',50,...
        'ball_clump_thresh',0.1/(2*max(order-2,1)), 'finitePathTruncL',10.0,...
        'interior_balls', true,'imag_thresh', 1e-8, 'use_mex', true);
    options.log.take = false;
    options.log.Newton_its = 0;
    
    %now adjust them, if requested to
    N = length(varargin);
    found_options = zeros(N,1);
    for n = 1:N
        if ischar(varargin{n})
           lowerCaseArg=lower(varargin{n});
           switch lowerCaseArg
               case 'plot'
                   options.plot = true;
                   found_options(n) = 1;
               case 'plotcovers'
                   options.plotCovers = true;
                   found_options(n) = 1;
               case 'plotcontours'
                   options.plotContours = true;
                   found_options(n) = 1;
               case 'plotspecial'
                   options.plotSpecial = true;
                   found_options(n) = 1;
               case 'infcontour'
                   options.infContour = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'inf contour'
                   options.infContour = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'c_ball'
                   options.numOscs = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'delta_quad'
                   options.contourStartThresh = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'delta_ode'
                   options.global_step_size = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'quad step size'
                   options.quad_step_size = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'taylor terms'
                   options.Taylor_terms = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'finite path truncation'
                   options.finitePathTruncL = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'delta_fine'
                   options.NewtonThresh = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'delta_coarse'
                   options.NewtonBigThresh = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'max newton steps'
                   options.NewtonIts = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'log'
                   options.log = init_log();
                   found_options(n) = 1;
               case 'log name'
                   its = options.log.Newton_its;
                   options.log = init_log(varargin{n+1});
                   options.log.Newton_its = its;
                   found_options(n:(n+1)) = 1;
               case 'n_ball'
                   options.num_rays = uint32(varargin{n+1});
                   found_options(n:(n+1)) = 1;
               case 'inf quad rule'
                   options.inf_quad_rule = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'log newton'
                   options.log.Newton_its = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'use interior balls'
                   options.interior_balls = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'plot graph'
                   options.plot_graph = true;
                   found_options(n) = 1;
               case 'imag thresh'
                   options.imag_thresh = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'delta_ball'
                   options.ball_clump_thresh = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'use mex'
                   options.use_mex = varargin{n+1};
                   found_options(n:(n+1)) = 1;
           end
        end
    end

    if sum(found_options)<N
        error(sprintf("Optional input '%s' not found",varargin{find(found_options==0,1)}));
    end
end

