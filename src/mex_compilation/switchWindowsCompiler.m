function switchWindowsCompiler()

    full_message = evalc('mex -setup C');
    disp('full_message:');
    disp(full_message);
    mex_string = strrep(full_message, 'For MinGW64 Compiler (C):  ', '');
    disp('mex_string:');
    disp(mex_string);
    eval(mex_string);
    
    % Get a list of installed compilers
%     compilers = mex.getCompilerConfigurations('C');
%     
%     % Find the MinGW-w64 compiler
%     mingw_compiler = [];
%     disp(length(compilers));
%     for i = 1:length(compilers)
%         disp(compilers(i).Name);
%         if contains(compilers(i).Name, 'MinGW-w64')
%             mingw_compiler = compilers(i);
%             break;
%         end
%     end
%     
%     if isempty(mingw_compiler)
%         error('MinGW-w64 compiler not found.');
%     else
%         % Set MinGW-w64 as the active compiler
%         mex('-setup', mingw_compiler.MexOpt);
%         disp('MinGW-w64 compiler set successfully.');
%     end
end
