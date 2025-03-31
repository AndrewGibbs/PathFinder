% Short example code used to produce the example plots in the README.md
% file.

clear all;
close all;

% parameter to save output
savefig = false;

% endpoints
a = -1;
b = 1;

% keep freq small, for a more interesting plot
freq = 50;

% coefficients of the phase function
phaseCoeffs = [1 -0.5 0.5 0 -1 0];

% number of quadrature points
numPts = 25;

% plot contour deformation
figure(1);
PathFinder(a, b, [], phaseCoeffs, freq, numPts, 'plot');
if savefig
    print('eg_contour_def.png', '-dpng', '-r100');
end

% plot graph
figure(2);
PathFinder(a, b, [], phaseCoeffs, freq, numPts, 'plot graph');
if savefig
    print('eg_graph.png', '-dpng', '-r100');
end