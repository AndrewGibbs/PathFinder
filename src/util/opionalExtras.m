function options = opionalExtras(varargin)
    %allows user to manually adjust default parameters, like plotting etc
    
     if length(varargin)==1 && ~ischar(varargin{1})
        %glitchy Matlab varagin thing, only an issue when this function 
        %call's it's self recursively. Fix it here:
        varargin=varargin{1};
    end
    
    %set defaults:
    options = struct('plot', false, 'infContour', [false false], 'numOscs', 1);
    
    %now adjust them, if requested to
    N = length(varargin);
    for n = 1:N
        if ischar(varargin{n})
           lowerCaseArg=lower(varargin{n});
           switch lowerCaseArg
               case 'plot'
                   options.plot = true;
               case 'infcontour'
                   options.infContour = varargin{n+1};
               case 'numoscs'
                   options.numOscs = varargin{n+1};
           end
        end
    end
end

