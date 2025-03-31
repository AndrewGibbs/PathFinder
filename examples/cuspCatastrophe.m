% This example demonstrates how PathFinder can be used to plot
% cusp / Pearcey catastrophe integral (K=2),
% see for e.g. DLMF Chapter 36 https://dlmf.nist.gov/36

clear all;
close all;

% parameter to save output
savefig = false;

%% determine physical properties of integral
% create the coefficients vector for the canonical integral
phiCoeffs = @(x1, x2) [1 0 x2 x1 0];
% note that the phase has coefficients depending on x and y

% adjustable frequency parameter
freq = 1;

%% determine approximation/sampling parameters
numPixels = 150; % how many pixels in each direction
numQuadPts = 10; % quadrature points per contour

% note that the time taken will scale roughly like
% numPixels^2, and is affected much less by numQuadPts.
% On my laptop (4 workers), with numPixels = 150,
% this code runs in around 45s in Matlab,
% and around 8 minutes in Octave (no parelallisation)

xRange = linspace(-10, 10, numPixels);
yRange = linspace(-10, 2, numPixels);
plotVals = zeros(numPixels); % initialise output to plot

% determines size of image (not number of samples)
imageBaseScale = 1200;

%% sample the catastrophe integral
tic; % we will time how long this section takes 
parfor ix = 1:numPixels % use parallel toolbox if available
    for iy = 1:numPixels
        plotVals(iy, ix) ...
            = PathFinder(pi, 0, ... % angles of valleys
            [], ... % no amplitude function
            phiCoeffs(xRange(ix), yRange(iy)),... % phase coeffs
            freq, ... % frequncy parameter
            numQuadPts, ... % quadrature points per contour
            'infcontour', [true true]); % flag for inf contours
    end
end
fprintf('\nTime taken to evaluate %d integrals:\n %.1fs\n',...
        numPixels^2, round(toc));

%% produce image

% plot the samples of the catastrophe integral
surf(xRange, yRange, abs(plotVals));
view([0 90]);

% use LaTeX formatting if running in Matlab:
if usingOctave
    xlabel('x_1','interpreter','tex');
    ylabel('x_2','interpreter','tex');
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
xWidth = max(xRange) - min(xRange);
yWidth = max(yRange) - min(yRange);
maxWidth = max(xWidth, yWidth);
xScale = xWidth * imageBaseScale / maxWidth;
yScale = yWidth * imageBaseScale / maxWidth;
title('Amplitude of Cusp/Pearcey canonical catastophe integral');

set(gcf, 'Position', [100, 600, xScale, yScale]);
shg;
if savefig
    print('cusp.png', '-dpng', '-r200');
end