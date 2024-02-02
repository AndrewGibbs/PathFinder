% This script produces a 'missing plot' of the contour integral $A_32(x,y)$ 
% from 'Contour integral solutions of the parabolic wave equation', 
% by D.P. Hewett a, J.R. Ockendon b, V.P. Smyshlyaev, 2018. 
% The purpose is to include this plot in the PathFinder 
% JOSS paper.

% This script is designed to run in Matlab - it has not been tested in
% Octave.

clear all;
close all;

% number of points in each direction for grid
xNumPts = 10000;
yNumPts = 1000;

% number of points used to evaluate each contour integral
numPts = 25;

% phase coeffs, which vary in R^2
gCoeffs = @(x,y) [2/5 -x/2 0 -y 0 0];

% valleys
a = 9*pi/10;
b = pi/2;

% wavenumber scaling for conversion from PWE to Helmholtz
kScale = [1/5 3/5];

A32 = @(x,y) PathFinder(a, b, [], gCoeffs(x,y), 1, numPts, 'infcontour', ...
    [true true]);

% make grid of points
x = linspace(-10, 10, xNumPts);
y = linspace(-10, 10, yNumPts);
[X, Y] = meshgrid(x, y);
Agrid = zeros(xNumPts, yNumPts);

% start parallel pool and timer
gcp;
tic;
parfor ix = 1:xNumPts
    for iy = 1:yNumPts
        % get value at each point
        Agrid(ix,iy) = A32(X(iy, ix), Y(iy, ix));
    end
end

% swap the x&y axes back for plotting
Agrid = Agrid.';

% record CPU time
main_CPU_time = toc

% set neat LaTeX plotting formats
set(groot, 'defaultAxesTickLabelInterpreter', 'latex'); 
set(groot, 'defaulttextinterpreter', 'latex');
set(groot, 'defaultLegendInterpreter', 'latex');

% plot the PWE solution
plt = surf(x, y, (abs(Agrid)));
view([0 90]);
set(plt,'linestyle','none');
shading interp;
xlabel('$x$');
ylabel('$y$');
%bn ~ Mari, 10th Nov, 2022
set(gca,'FontSize', 20);
colorbar('TickLabelInterpreter', 'latex', 'FontSize', 20);
colormap('jet');
set(gcf, 'Position',  [100, 100, 700, 700]);
pause(1);
axis equal;
pause(1);
axis square;
pause(1);
print('-dpng',['A32','.png'], '-r200');