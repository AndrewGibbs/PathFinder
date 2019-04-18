function Z = getLevelContour(xi,C,g,freq, N)

    N = max(N,32);
    Ncirc = 8;
    failCount = 1000;
    
    %plot level curve of:
    G = @(z) freq*abs(g(z)-g(xi))-C;
    
    %send out a ray (travelling in +ve real direction) first:
    Z(1) = ray(G, xi, freq);
    rayLength = abs(Z-xi);
    circleRad = 2*pi*rayLength/N;
    
    theta = linspace(0,2*pi,Ncirc);
    %theta(end) = [];
    open = true;
    
    j = 1;
    while open && j<failCount
        circle_j = Z(j) + circleRad*exp(1i*theta);
        positiveCircum = G(circle_j)>0;
        inds = 1:(Ncirc-1);
        signChange = inds(positiveCircum(1:(end-1)) ~= positiveCircum(2:end));
        contEdge = [];
        for n = signChange
            contEdge = [contEdge bisection(G, circle_j(n), circle_j(n+1))];
        end
    
        if length(contEdge)>2
            %only want the two inner elements of this vector, most likely
            %two contours are kissing
            [~,minInd] = mink(abs(contEdge-xi),2);
            contEdge = contEdge(minInd);
        end
        if j>1
            [~,maxInd] = max(abs(contEdge-Z(j-1)));
            j = j+1;
            Z(j) = contEdge(maxInd);
        else
            j = j+1;
            Z(j) = contEdge(1);
        end       
        
        if j>2 && isIn(Z(1),Z(j))
            open = false;
        end
    end
    
    if open
        warning('failed to find contour, trying slower method');
        Z = levelSetFailsafe(xi,C,g,freq,N);
    end
    
    %now check that stationary point actually lies inside this contour:
    if ~inpolygon(real(xi),imag(xi),real(Z),imag(Z))
        warning('Stationary point not inside of contour! Trying slower method...');
        Z = levelSetFailsafe(xi,C,g,freq,N);
    end
    
    function yn = isIn(x,y)
        yn = abs(y-x)<=circleRad;
    end
end