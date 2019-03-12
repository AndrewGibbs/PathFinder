clear classes; 
addPaths();

Npts = 5;
C = 1; %num of oscillations inside contour parameter
c=.4; %coalescence parameter
freq = 1000;
aValIndex = 2;
bValIndex = 5;

infContour = true;

SPs = [-c c/2 -.5i*c c*1i];

order = length(SPs)+1;

dgCoeffs = poly(SPs);

dggCoeffs_step1 = ((length(dgCoeffs)-1):-1:1);
ddgCoeffs = dggCoeffs_step1.*dgCoeffs(1:(end-1));

gCoeffs = [dgCoeffs./(order:-1:1) 0];

dgRoots = roots(dgCoeffs);
ddgRoots = roots(ddgCoeffs);

g = @(z)  polyval(gCoeffs,z);
dgdz = @(z)  polyval(dgCoeffs,z);

G = {g, dgdz};

valleys = exp(2i*pi*(1/4 + (1:order))/order);

a = valleys(aValIndex);
b = valleys(bValIndex);

x = linspace(-2.5,2.5,500);
z = x + 1i*x.';

figure(1);
hold off;
for n = 1:length(SPs)
    plot(SPs(n)+eps*1i,'k*');
    xlim([-1 1]);
    ylim([-1 1]);
    hold on;
    coversInit(n) = ContourInterior(SPs(n),x,x,freq,g,n,C);
    coversInit(n).plot;
    %plot(coversInit(n).steepestExits,'k*','MarkerSize',15);
    %legend('\xi','\Gamma_\xi','\zeta_\xi');
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

contourSeq = shortestInfinitePath(contours, covers, intersectionMatrix, valleys, a, b, true);
contoursInSeq = contours(contourSeq);

[z, w] = makeQuad(contoursInSeq, freq, Npts, G);
hold on;
plot(z,'kx');

set(gca,'FontSize',22);
xlabel('Re\{z\}','fontsize',22);
ylabel('Im\{z\}','fontsize',22);
hold off