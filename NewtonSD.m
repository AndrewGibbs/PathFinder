function [success, x_n] = NewtonSD(x_n,G,p,r,xi,thresh)
%Quick Newton iteration to find zeros of G
    maxIts = 10;
    for n = 1:maxIts
        x_n = x_n - (-G{1}(xi) - 1i*p^r + G{1}(x_n))/G{2}(x_n);
        err = abs(G{1}(xi) + 1i*p^r - G{1}(x_n));
        if err < thresh
            success = true;
            return
        end
    end
    success = false;
    x_n =[];
end