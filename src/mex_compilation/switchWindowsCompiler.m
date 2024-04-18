function switchWindowsCompiler()
    % Get a list of installed compilers
    compilers = mex.getCompilerConfigurations('C');
    
    % Find the MinGW-w64 compiler
    mingw_compiler = [];
    for i = 1:numel(compilers)
        disp(compilers(1).Name);
        if contains(compilers(i).Name, 'MinGW-w64')
            mingw_compiler = compilers(i);
            break;
        end
    end
    
    if isempty(mingw_compiler)
        error('MinGW-w64 compiler not found.');
    else
        % Set MinGW-w64 as the active compiler
        mex('-setup', mingw_compiler.MexOpt);
        disp('MinGW-w64 compiler set successfully.');
    end
end