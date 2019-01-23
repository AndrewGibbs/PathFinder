function I = A1(x,y,a,b,Npts, visuals)
%function to ... I'm timing this so I'll comment later +5

    if nargin == 5
        visuals = false;
    end
    polyCoeffs = [1/4 0 -x/2 -y 0];
    %D1Coeffs = coeffs(1:(end-1)).*fliplr(1:(end-1));

    

    R = monomialSettleRadius(polyCoeffs);
    %visuals = true;
    if visuals
        [ ~, W ] = PathFinder( a, b, 1, Npts, [], 'settleRad', R, 'ainf', 'binf',  'gpolycoeffs', polyCoeffs, 'visuals on');
    else
        [ ~, W ] = PathFinder( a, b, 1, Npts, [], 'settleRad', R, 'ainf', 'binf', 'gpolycoeffs', polyCoeffs);
    end
    I = sum(W);
end

