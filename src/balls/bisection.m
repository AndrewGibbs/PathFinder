% bisection method, specifically designed to determine when rays intersect
% contour such that freq*|g(z)-g(\xi)|=numOscs, where g is the phase
% function and \xi is a stationary point.

% This function will only be called when the main rootfinding algorithm
% (which uses a companion matrix approach) fails.

% inside contour f is negative, outside contour f is positive. Looking for
% point c in [a,b] such that f(c)=0.
function [c, numIterations] = bisection(f, a, b, tol)

    % initialise output
    c = NaN;
    numIterations = 0;
    maxNumIts = 1000;
    
    % function to bound error based on width of interval
    err = @(a,b) abs(b-a);
    
    % check we aren't already within prescribed tolerance
    if err(a,b)<=tol
        % take midpoint if no bisection is required
        c = (b+a)/2;
    else
        % next check endpoints aren't roots
        if f(a) == 0
            c = a;
            return
        elseif f(b) == 0
            c = b;
            return;
        end
        
        % get sign at endpoint a, required later on
        if f(a)>0
            sgn = -1;
        else
            sgn = 1;
        end
        
        % initialise error with the guess c
        cErr = err(a,b);

        % main bisection loop
        while cErr>tol
           numIterations = numIterations + 1;

           % take midpoint
           c = a + (b-a)/2;
           % narrow the search window
           if sgn*f(c) > 0
               b = c;
           elseif sgn*f(c) < 0
               a = c;
           else % if exactly zero, unlikely
               break;
           end

           % get estimate for error for current window of c
           cErr = err(a,b);
           
           % make sure while loop cannot run forever
           if numIterations > maxNumIts
               error('failed to bisect');
           end
        end
    end
end