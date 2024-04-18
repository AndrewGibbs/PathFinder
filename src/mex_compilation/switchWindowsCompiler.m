% When running tests on GitHub CI,
% we can install mingw64 compiler easily enough, but actually
% switching to the compiler is tricky, as there is no Matlab one-liner to
% do this. This function locates the relevant compiler and switches
% automatically, using regular expressions.
function switchWindowsCompiler()

    full_message = evalc('mex -setup C');
    disp('full_message:');
    disp(full_message);

    startSubstr = 'mex';
    endSubstr = 'mingw64.xml';
    
    % Regular expression pattern to capture substring between start and end
    pattern = strcat('(', startSubstr, '.*?', endSubstr, ')');
    
    % Extract substring using regular expression
    extracted = regexp(full_message, pattern, 'tokens', 'once');

    % get shortest string, which will be the one we want
    min_length = inf;
    for n=1:length(extracted)
        disp(extracted{n});
        if length(extracted{n}) < min_length
            min_length_ind = n;
            min_length = length(extracted{n});
        end
    end
    mex_string = extracted{min_length_ind};
    
    disp('mex_string:');
    disp(mex_string);
    eval(mex_string);
end
