% This example demonstrates how PathFinder can be used to plot
% swallowtail catastrophe integral (K=3),
% see for e.g. DLMF Chapter 36 https://dlmf.nist.gov/36

clear all;
close all;

%% determine physical properties of integral
% create the coefficients vector for the canonical integral
phiCoeffs = @(x1, x2, x3) [1 0 x3 x2 x1 0];
% note that the phase has coefficients depending on x and y

% adjustable frequency parameter
freq = 1;

% choose points in the x3 direction 
zRange = [-10 -5 0 5];

%% determine approximation/sampling parameters
numPixels = 150; % how many pixels in each direction
numQuadPts = 10; % quadrature points per contour

% note that the time taken will scale roughly like
% numPixels^2, and is affected much less by numQuadPts.
% On my laptop (4 workers), with numPixels = 150,
% this code runs in around 4 minutes in Matlab,
% and around 45 minutes in Octave (no parelallisation)

xRange = linspace(-20, 30, numPixels);
yRange = linspace(-20, 20, numPixels);
plotVals = zeros(numPixels); % initialise output to plot

% determines size of image (not number of samples)
imageBaseScale = 1400;

% produce an image for each x3 slice
plotCount = 0;
for x3 = zRange
plotCount = plotCount + 1;

%% sample the catastrophe integral
tic; % we will time how long this section takes 
parfor ix = 1:numPixels % use parallel toolbox if available
    for iy = 1:numPixels
        plotVals(iy, ix) ...
            = PathFinder(pi, 0, ... % angles of valleys
            [], ... % no amplitude function
            phiCoeffs(xRange(ix), yRange(iy), x3),... % phase coeffs
            freq, ... % frequncy parameter
            numQuadPts, ... % quadrature points per contour
            'infcontour', [true true]); % flag for inf contours
    end
end
fprintf('\nTime taken to evaluate %d integrals at z=%.1f:\n %.1fs\n',...
        numPixels^2, x3, round(toc));

%% produce image

% plot the samples of the catastrophe integral
subplot(2,2,plotCount)
surf(xRange, yRange, abs(plotVals));
view([0 90]);

% use LaTeX formatting if running in Matlab:
if usingOctave
    xlabel('x_1');
    ylabel('x_2');
else
    set(groot, 'defaultAxesTickLabelInterpreter', 'latex'); 
    set(groot, 'defaulttextinterpreter', 'latex');
    set(groot, 'defaultLegendInterpreter', 'latex');
    xlabel('$x_1$');
    ylabel('$x_2$');
end

% further formatting:
shading interp;
set(gca,'YDir','normal');
colorbar('TickLabelInterpreter', 'latex', 'FontSize', 20);
set(gca,'FontSize',20);
colormap('jet');
axis equal;
axis tight;

% title for subplot
if usingOctave
    title(sprintf('x_=%.1f$', x3));
else
    title(sprintf('$x_3=%.1f$', x3),'Interpreter','latex');
end

end

xWidth = max(xRange) - min(xRange);
yWidth = max(yRange) - min(yRange);
maxWidth = max(xWidth, yWidth);
xScale = xWidth * imageBaseScale / maxWidth;
yScale = yWidth * imageBaseScale / maxWidth;

if ~usingOctave
    sgtitle('Amplitude of Swallowtail Catastrophe',...
        'fontsize',20);
end

set(gcf, 'Position', [100, 600, xScale, yScale]);
shg;
print('swallowtail.png', '-dpng', '-r200');