function isPass = logTest()
%Tests that PathFinder can produce a log file without causing an error 
    isPass = true;
%     try
    % check basic logging
    PathFinder(-1, 1, @(x) x.^2, [1 -0.5 0.5 0 -1 0], 50, 10, 'log');

    % check logging with user-specified filename
    PathFinder(-1, 1, @(x) x.^2, [1 -0.5 0.5 0 -1 0], 50, 10, 'log',...
        'log name', 'loggletest');
%     catch ERR
%         isPass = false;
%     end
    close all;
end