function options = opionalExtras(varargin)
    %allows user to manually adjust default parameters, like plotting etc
    
     if length(varargin)==1 && ~ischar(varargin{1})
        %glitchy Matlab varagin thing, only an issue when this function 
        %call's it's self recursively. Fix it here:
        varargin=varargin{1};
    end
    
    %set defaults:
    options = struct('plot', false, 'infContour', [false false], 'numOscs', 1, ...
        'turbo', true,'plotCovers',false,'plotContours',false,'plotSpecial',false,...
        'contourStartThresh',1e-16,'Hermite',false,'truncation',1.0,...
        'global_solver','Euler','global_step_size',0.1,'max_number_of_ODE_steps',50000,...
        'quad_solver','Euler','quad_step_size',1e-13,'Taylor_terms',4, ...
        'finitePathTruncL',10.0, 'NewtonThresh',1e-8,'NewtonIts',50);
    
    %now adjust them, if requested to
    N = length(varargin);
    for n = 1:N
        if ischar(varargin{n})
           lowerCaseArg=lower(varargin{n});
           switch lowerCaseArg
               case 'plot'
                   options.plot = true;
               case 'plotcovers'
                   options.plotCovers = true;
               case 'plotcontours'
                   options.plotContours = true;
               case 'plotspecial'
                   options.plotSpecial = true;
               case 'infcontour'
                   options.infContour = varargin{n+1};
               case 'numoscs'
                   options.numOscs = varargin{n+1};
               case 'turbo on'
                   options.turbo = true;
               case 'turbo off'
                   options.turbo = false;
               case 'contour thresh'
                   options.contourStartThresh = varargin{n+1};
               case 'hermite'
                   options.Hermite = varargin{n+1};
               case 'global solver'
                   options.global_solver = varargin{n+1};
               case 'global step size'
                   options.global_step_size = varargin{n+1};
               case 'quad solver'
                   options.quad_solver = varargin{n+1};
               case 'quad step size'
                   options.quad_step_size = varargin{n+1};
               case 'taylor terms'
                   options.Taylor_terms = varargin{n+1};
               case 'finite path truncation'
                   options.finitePathTruncL = varargin{n+1};
               case 'newton thresh'
                   options.NewtonThresh = varargin{n+1};
               case 'max newton steps'
                   options.NewtonIts = varargin{n+1};
           end
        end
    end
end

