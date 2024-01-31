function checkInputs(a, b, f, phaseIn, freq, nPts)
    % Check if a and b are scalars
    if ~isscalar(a) || ~isscalar(b)
        error(['First and second inputs must be scalars, ' ...
            'describing the integration domain']);
    end

    % Check if f is either an empty vector or a function handle
    if ~(isempty(f) || isa(f, 'function_handle'))
        error(['Third input represents non-exponential part -' ...
            ' must be either an empty vector or a function handle.']);
    end

    % Check if phaseIn is a vector
    if ~isvector(phaseIn)
        error('Fourth input must be a vector of phase coefficients.');
    end

    % Check if freq is a scalar
    if ~isscalar(freq) || ~isreal(freq) || freq<=0
        error('Fifth input must be positive scalar describing frequency.');
    end

    % Check if nPts is an integer
    if mod(nPts,1)~=0 || nPts<=0
        error('nPts must be a positive integer.');
    end

end