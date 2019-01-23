function I = A(x,y,a,b,Npts, visuals)
%function to ... I'm timing this so I'll comment later +5

    if nargin == 5
        visuals = false;
    end
    polyCoeffs = [2/5 -x/2 0 -y 0 0];
    %D1Coeffs = coeffs(1:(end-1)).*fliplr(1:(end-1));
    order = 5;
    %create derivatives of phase function
    D1polyCoeffs = polyCoeffs(1:order).*fliplr(1:order);
    
    %if two stationary points are this close, make them one
    stationaryPointMinDist=0.001;
    
    g = @(t) polyval(polyCoeffs,t);
    %dgdt = @(t) polyval(D1Coeffs,t);
    
    %use Matlab's roots function to get the data about the stationary
    %points.
    %first factor out the t^2 and compute the roots of what's left:
    stationaryPointsInit = sort([0; roots(D1polyCoeffs(1:4))]);
    distinctCount=0;
    %determine the orders of the cubic points, by checking for repetitions:
    for n = 1:length(stationaryPointsInit)
        if n>1 & abs(stationaryPointsInit(n)-stationaryPointsInit(n-1)) < stationaryPointMinDist
            stationaryPointsOrders(distinctCount)=stationaryPointsOrders(distinctCount)+1;
        else
            distinctCount = distinctCount+1;
            stationaryPoints(distinctCount) = stationaryPointsInit(n);
            stationaryPointsOrders(distinctCount) = 1;
        end
    end
    
    %second derivative
    D2polyCoeffs = D1polyCoeffs(1:(order-1)).*fliplr(1:(order-1));
    D3polyCoeffs = D2polyCoeffs(1:(order-2)).*fliplr(1:(order-2));
    D4polyCoeffs = D3polyCoeffs(1:(order-3)).*fliplr(1:(order-3));
    D5polyCoeffs = D4polyCoeffs(1:(order-4)).*fliplr(1:(order-4));
    D6polyCoeffs = D5polyCoeffs(1:(order-5)).*fliplr(1:(order-5));

    G = {@(x) polyval(polyCoeffs,x),@(x) polyval(D1polyCoeffs,x),@(x) polyval(D2polyCoeffs,x),...
        @(x) polyval(D3polyCoeffs,x),@(x) polyval(D4polyCoeffs,x), @(x) polyval(D5polyCoeffs,x),...
        @(x) polyval(D6polyCoeffs,x), @(x) 0, @(x) 0};

    R = monomialSettleRadius(polyCoeffs);
    %visuals = true;
    if visuals
        [ ~, W ] = NSD45( a, b, 1, Npts, G, 'settleRad', R, 'ainf', 'binf', 'stationary points', stationaryPoints, 'order', stationaryPointsOrders, 'visuals on');
    else
        [ ~, W ] = NSD45( a, b, 1, Npts, G, 'settleRad', R, 'ainf', 'binf', 'stationary points', stationaryPoints, 'order', stationaryPointsOrders);
    end
    I = sum(W);
end

