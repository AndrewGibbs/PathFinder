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
        'contourStartThresh',0.0,'Hermite',true);
    
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
           end
        end
    end
end

