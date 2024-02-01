function isPass = plotTest()
%Tests that PathFinder can produce plots without causing an error
    isPass = true;
    try
        PathFinder(-1, 1, @(x) x.^2, [1 -0.5 0.5 0 -1 0], 50, 10, 'plot');
    
        PathFinder(-1, 1, @(x) x.^2, [1 -0.5 0.5 0 -1 0], 50, 10, 'plot graph');
    
        % check plotting for both plot types
        PathFinder(-1, 1, @(x) x.^2, [1 -0.5 0.5 0 -1 0], 50, 10, 'plot','plot graph');
    
        % check plot for linear phase
        PathFinder(-1, 1, @(x) x.^2, [1 0], 50, 10,  'plot','plot graph');

    catch ERR
        isPass = false;
    end
    close all;
end