function options = optionalExtras(order,varargin)
    %allows user to manually adjust default parameters, like plotting etc
    
     if length(varargin)==1 && ~ischar(varargin{1})
        % due to Matlab convention, need a workaround when there is a
        % single element in cell array:
        varargin=varargin{1};
    end
    
    %set defaults:
    options = struct('plot', false, 'plotGraph',false,...
            'infContour', [false false], 'numOscs', 2*pi, ...
            'contourStartThresh', 1e-16, 'numRays',uint32(16),...
            'globalStepSize', 0.1, 'maxNumODEsteps',50000,...
            'infQuadRule', 'laguerre', 'NewtonThresh', 10^(-13),...
            'NewtonBigThresh', 1e-2, 'NewtonIts',50,...
            'ballMergeThresh', 0.1/(2*max(order-2,1)), ...
            'finitePathTruncL', 10.0, 'interiorBalls', true, ...
            'imagThresh', 1e-8, 'useMex', true);
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
                   options.globalStepSize = varargin{n+1};
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
               case 'max euler steps'
                   options.maxNumODEsteps = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'log'
                   options.log = initLog();
                   found_options(n) = 1;
               case 'log name'
                   its = options.log.Newton_its;
                   options.log = initLog(varargin{n+1});
                   options.log.Newton_its = its;
                   found_options(n:(n+1)) = 1;
               case 'n_ball'
                   options.numRays = uint32(varargin{n+1});
                   found_options(n:(n+1)) = 1;
               case 'inf quad rule'
                   options.infQuadRule = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'log newton'
                   options.log.Newton_its = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'use interior balls'
                   options.interiorBalls = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'plot graph'
                   options.plotGraph = true;
                   found_options(n) = 1;
               case 'imag thresh'
                   options.imagThresh = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'delta_ball'
                   options.ballMergeThresh = varargin{n+1};
                   found_options(n:(n+1)) = 1;
               case 'use mex'
                   options.useMex = varargin{n+1};
                   found_options(n:(n+1)) = 1;
           end
        end
    end

    if sum(found_options)<N
        error(sprintf("Optional input '%s' not found",string(varargin{find(found_options==0,1)})));
    end
end

