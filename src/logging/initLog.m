% If the user has requested to log performance of various PathFinder
% routines, this routine creates a struct with all of the relevant
% information.
function LogStruct = initLog(filename)

    % default file name 
    if nargin == 0
        filename = ['log',datestr(now, 0),'.txt'];
    end

    % get path to logs directory
    s = what('PathFinder');
    logPath = [s.path '/log/'];

    % write some details at the top of the file
    fid = fopen(fullfile(logPath, filename), 'w');
    fprintf(fid, 'PathFinder log, %s\n', datestr(now, 0));
    fclose(fid);

    % store important information, so the log file can be added to later
    LogStruct = struct('path', logPath, 'filename', filename,...
                        'take',true,...
                        'addToLog', @(s) addToLog(s, logPath, filename));

    % indented function, which is stored in log structure.
    function addToLog(s, logPath_, filename_)
        fid_ = fopen(fullfile(logPath_, filename_), 'a');
        fprintf(fid_, '\n%s', s);
        fclose(fid_);
    end
end