function [c,count] = bisection(f, a, b)

tol = 1e-4;
L = abs(b-a);
% rayDir = (b-a)/L;
% ray = @(s) a + s*(b-a);

%inside contour f is negative, outside contour f is positive

err = @(a,b) min(abs(f(a)),abs(f(b))); 
if f(a) == 0
    c = a;
    return
elseif f(b) == 0
    c = b;
    return;
end

if f(a)>0
    f = @(x) -f(x);
end

c_err = inf;
count = 0;
while c_err>tol
   c = a + (b-a)/2;
   if f(c) > 0
       b = c;
   elseif f(c) < 0
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