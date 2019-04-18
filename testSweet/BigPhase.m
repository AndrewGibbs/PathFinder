function pass = BigPhase()

    sigma_tilde = -2.33811;
    freq = 1;

    %x = 0; y = 1;
    Yregion = @(y,x) y>-x.^3/6;
    xCount = 0;
    X = linspace(-2,2,10);
    for x = X
        xCount = xCount + 1;
        yCount = 0;
        for y = X
            yCount = yCount + 1;
            sigma = sigma_tilde* 3*sqrt(2)/5;
            P = @ (x,y) [4*sqrt(2)/15 0 0 -x/2 0 0 0 0 0 -y sigma 0 0 0 0 0];
            if Yregion(y,x)
                [z,w] = PathFinderQuad(exp(1i*9*pi/30), exp(1i*5*pi/30), P(x,y), freq, 15, 'infContour', [true true]);
                 A(xCount,yCount) = sum(w);
            else
                 A(yCount,xCount) = 0;
            end

        end
        fprintf('\n%d',xCount);
    end

    surf(X,X,real(A));
    view(0,90);
    
    pass = true;
end