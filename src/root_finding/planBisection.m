% if the companion matrix approx fails to find a radius, plan B is to use
% this bisection approach. The guesses are the positive real parts from the
% roots of the companion matrix approach; their imaginary parts were
% deemed too large in magnitude for them to be trustworthy.
function [root, isSuccess] = planBisection(phaseCoeffs, xi, numOscsDivByFreq, theta, guesses)

    tol = 1e-8; % bisection tolerance

    % define the polynomial phase as a function handle
    phaseHandle = @(x) polyval(phaseCoeffs,x);
    % and the 'polynomial' which we are seeking the root of
    bisecFnHandle = @(r) abs(phaseHandle(xi+r*exp(1i*theta))-phaseHandle(xi)).^2-numOscsDivByFreq^2;

    % add a couple of extra extremities to the guesses to be safe
    guesses = [0; guesses; max(guesses)*2];

    % initialise bisection parameters
    isSuccess = false;
    root = inf;
    
    % loop over all possible guess intervals, and try bisection on each one
    for n=2:length(guesses)
        % we know that bisecFnHandle(0)<0
        if bisecFnHandle(guesses(n))>0 % look for a sign change
            isSuccess = true;
            % now zoom in on the root using bisection method
            root = bisection(bisecFnHandle, guesses(n-1), guesses(n), tol);
            break; % no need to keep looking
        end
    end
    
end