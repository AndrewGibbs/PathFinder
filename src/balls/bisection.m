function [c,count] = bisection(f, a, b, tol)

% L = abs(b-a);
% rayDir = (b-a)/L;
% ray = @(s) a + s*(b-a);
c = NaN;
%inside contour f is negative, outside contour f is positive

% err = @(a,b) min(abs(f(a)),abs(f(b)));
err = @(a,b) abs(b-a);
if err(a,b)<=tol
    % take midpoint if no bisection is required
    c = (b+a)/2;
    count = 0;
else
    if f(a) == 0
        c = a;
        return
    elseif f(b) == 0
        c = b;
        return;
    end
    
    if f(a)>0
        %f = @(x) -f(x);
        sgn = -1;
    else
        sgn = 1;
    end
    
    c_err = err(a,b);
    count = 0;
    while c_err>tol
       c = a + (b-a)/2;
       if sgn*f(c) > 0
           b = c;
       elseif sgn*f(c) < 0
           a = c;
       else
           break;
       end
       c_err = err(a,b);
       count = count + 1;
       if count > 1000
           error('failed to bisect');
       end
    end
end