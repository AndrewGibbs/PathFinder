function logMexUsage(params)
    % record to log file if MEX code is being used
    if params.useMex
        params.log.addToLog(sprintf("Using mex code"));
    else
        params.log.addToLog(sprintf("Not using mex code"));
    end
end