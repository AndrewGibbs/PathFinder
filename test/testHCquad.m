function isPass = testHCquad()
% tests that the hard-coded quadrature returns something sensible
    isPass = true;

    % initialise weights and nodes, incase they aren't assigned
    x = [];
    w = [];
    for n=1:150

        % first check Gauss Laguerre hard-coded quadrature
        try
            [x, w] = gausLagHC(n);
        catch
            isPass = false;
        end

        if length(x) ~= n || length(w) ~= n
            isPass = false;
        end

        % now check Gauss Legendre hard-coded quadrature
        try
            [x, w] = gausLegHC(n);
        catch
            isPass = false;
        end

        if length(x) ~= n || length(w) ~= n
            isPass = false;
        end
    end

end