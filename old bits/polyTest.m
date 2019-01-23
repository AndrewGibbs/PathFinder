%test a general polynomial case, for Dave

%changes to make:
    % get Freud quads from Daan
    % actually test some of these
     
%% play-with-able parameters:
freq=1; %stick to low frequency regime for now
Npts=20; %number of quadrature points per SD path
polyCoeffs = [1 3 1 -2 1]; %a_1*x^N + ... a_N*x + a_{N+1}, if a:=polyCoeffs %[1 3 1 -2 1] was cool
aValleyIndex=1; %index of valley to start in 
bValleyIndex=2; %index of valley to end in 

%% ----------------------------------------------------------------------------------------- %%
addpath ../..;
StandardPaths;
%make the polynomial
order = length(polyCoeffs)-1;
fprintf('\nPhase is an order %d polynomial',order);
%first derivative
D1polyCoeffs = polyCoeffs(1:order).*fliplr(1:order);
%second derivative
D2polyCoeffs = D1polyCoeffs(1:(order-1)).*fliplr(1:(order-1));

G = {@(x) polyval(polyCoeffs,x),@(x) polyval(D1polyCoeffs,x),@(x) polyval(D2polyCoeffs,x)};

%% ----------------------------------------------------------------------------------------- %%
%some quick error tests:
if aValleyIndex==bValleyIndex
    error('Start and end valleys are the same, choose something more interesting');
end
if max(aValleyIndex,bValleyIndex)>order
    error(sprintf('There are only %d valleys', order));
end
%% ----------------------------------------------------------------------------------------- %%

% now choose the infinite endpoints:
valleys = exp(1i*pi*(1 + 4*(1:order))/(2*order));
a=valleys(aValleyIndex); b=valleys(bValleyIndex);

%this radius could be considered artificial infinity, outside of which all SD
%paths won't deviate much from a straight line
R = monomialSettleRadius(polyCoeffs)+rand;
fprintf('\nSettled radius = %.1f\n',R);

close; %close figure, if there is one
[ X, W ] = NSD45( a, b, freq, Npts, G, 'analytic', true, 'visuals on', ...
                    'settleRad', R, 'ainf', 'binf');
         %second row are all options for infinite endpoints
display('pink line is chosen path, blue line is discarded path(s)');
         %now time it (without making visuals)
tic;
NSD45( a, b, freq, Npts, G, 'analytic', true, ...
                    'settleRad', R, 'ainf', 'binf');
T=toc;
fprintf('\nTook %f seconds',T);