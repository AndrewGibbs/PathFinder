function ChebAij = Aij2(aValley,bValley,Pcoeffs,freq,Npts,degs,range)
%Aij(aValley,bValley,Pcoeffs,freq,Npts,degs,range)
%approximates A(x,y) = int_C exp(i*freq*P(z,x,y)) dz, where C is an infinite
%contour from aValley to bValley in the complex plane, P is a polynomial
%with (x,y)-dependent coefficients in vector form, given by Pcoeffs(x,y).
%Approximation uses 2D Chebfun with degs = [m n], where m and n are orders
%of approx in x and y directions respectively. Each Chebyshev node is
%approximated using PathFinder with Npts weights and nodes, over 
%range = [xMin xMax yMin yMax] \subset R^2.
 % -------------- example parameters: --------------------------------------
    %parameters of contour integral:
%     aValley = exp(9i*pi/8); %start of contour
%     bValley = exp(1i*pi/8); %end of contour
%     Pcoeffs = @(X,Y) [1/4 0 -X/2 -Y 0]; %coeffs of polynomial phase
%     Npts = 12;
%     degs = [5 5];
%     range = [-10 10 -10 10];
    % -------------------------------------------------------------------------
% on a macbook pro with two cores, with degs = [100 100], takes around 40
% mins
    
    %get 2nd kind Chebyshev nodes to use with Chebfun2D
    xPts = ChebyshevRoots( degs(1), 'Un', range(1:2) );
    yPts = ChebyshevRoots( degs(2), 'Un', range(3:4) );
    
    for i=1:length(xPts)
        for j = 1:length(yPts)
            PcoeffsXY{i,j} = Pcoeffs(xPts(i),yPts(j));
        end
    end
    
    %evaluate contour integral A(x,y) at Chebyshev nodes
    Avals = zeros(length(xPts),length(yPts));
    for i=1:length(xPts) % ** this line can be parfor **
        fprintf('\n%d',i);
        Avec = zeros(1,length(yPts));
        for j = 1:length(yPts) %can be parfor
            Avec(j) = contourPoly2(aValley,bValley,PcoeffsXY{i,j},freq,Npts);
        end
        Avals(i,:) = Avec;
    end
    %approximate by 2D Chebfun
    ChebAij = chebfun2(Avals,[range(1) range(2) range(3) range(4)]);
end