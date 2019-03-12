clear classes;

C = 2; %num of oscillations inside contour parameter
c=.1; %coalescence parameter
infContour = true;
freq = 25;

G = {@(x) x.^3/3-c*x, @(x) x.^2-c};
g = G{1};
SPs = ([-sqrt(c) sqrt(c)]);
order = 3;
valleys = exp(2i*pi*(1/4 + (1:order))/order);
x = linspace(-2.5,2.5,500);
z = x + 1i*x.';

hold off;
for n = 1:length(SPs)
    plot(SPs(n)+eps*1i,'x');
    xlim([-1 1]);
    ylim([-1 1]);
    hold on;
    coversInit(n) = ContourInterior(SPs(n),x,x,freq,g,n,C);
    coversInit(n).plot;
    plot(coversInit(n).steepestExits,'*','MarkerSize',15);
end

%delete exits inside a cover from another mother:
covers = deleteRedundantExits(coversInit);

%now determine which covers overlap:
[intersectionMatrix, clusters, clusterEndpoints] = coverOverlap(coversInit);

contours = [];
 for n = 1:length(covers)
    if ~infContour && ismember(n,[1 2])
        intervalEndpoint = covers(n).centre;
    else
        intervalEndpoint = [];
    end
    for xi = covers(n).steepestExits
        contours = [contours ContourSD(xi,G,covers(n),[covers(1:(n-1)) covers((n+1):end)],valleys,clusters,clusterEndpoints)];
    end
 end
plotAll(covers,contours);