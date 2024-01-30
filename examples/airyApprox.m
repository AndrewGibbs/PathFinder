% This example uses PathFinder to compute 
% an approximation to the Airy function and its derivative,
% via the integral representation. See e.g. DLMF 9.5.4-9.5.5.

clear all;
close all;

% number of points to be used in each contour approximation:
numQuadPts = 15;

% range to test approximations:
rangeSize = 100;
xRange = linspace(-5,5,rangeSize);

%% step one: create the approximation functions

% get PathFinder's approximation of Ai(x)
AiPF = @(x) (1/(2i*pi))*PathFinder(-pi/3, pi/3, [], ...
                -1i*[1/3 0 -x 0], 1, numQuadPts, ...
                'inf contour',[true true]);

% get PathFinder's approximation of Ai'(x)
dAiPF = @(x) (1/(2i*pi))*PathFinder(-pi/3, pi/3, ...
                @(t) - t, ...
                -1i*[1/3 0 -x 0], 1, numQuadPts, ...
                'inf contour',[true true]);


% get PathFinder's approximation of Bi(x)
BiPF = @(x) (1/(2*pi))*PathFinder(pi, pi/3, [], ...
                -1i*[1/3 0 -x 0], 1, numQuadPts, ...
                'inf contour',[true true])...
            + ...
            (1/(2*pi))*PathFinder(pi, -pi/3, [], ...
                -1i*[1/3 0 -x 0], 1, numQuadPts, ...
                'inf contour',[true true]);

% get PathFinder's approximation of Bi'(x)
dBiPF = @(x) (1/(2*pi))*PathFinder(pi, pi/3, @(t) - t, ...
                -1i*[1/3 0 -x 0], 1, numQuadPts, ...
                'inf contour',[true true])...
            + ...
            (1/(2*pi))*PathFinder(pi, -pi/3, @(t) - t, ...
                -1i*[1/3 0 -x 0], 1, numQuadPts, ...
                'inf contour',[true true]);


%% step two: test the approximation and plot

AiryHandles = {AiPF, dAiPF, BiPF, dBiPF};
if usingOctave()
    AiryTitles = ["$Ai(x)$", "Ai'(x)$",...
              "$Bi(x)$", "Bi'(x)$" ];
else
    AiryTitles = ["$\mathrm{Ai}(x)$", "$\mathrm{Ai}'(x)$",...
                  "$\mathrm{Bi}(x)$", "$\mathrm{Bi}'(x)$" ];
end

% loop over all four Airy variants
figure(1);
for ia = 0:3
    approxVals = zeros(rangeSize,1);
    for iz = 1:rangeSize
        approxVals(iz) = AiryHandles{ia+1}(xRange(iz));
    end
    subplot(2, 2, ia+1);
    plot(xRange, real(approxVals), ...
        xRange, airy(ia,xRange),...
        '--','LineWidth', 2);

    if usingOctave()
        xlabel('x');
    else
        xlabel('$x$');
    end

    title(AiryTitles{ia+1});
    
    legend('PathFinder','Matlab','Location','best');

    if ~usingOctave
        set(groot, 'defaultAxesTickLabelInterpreter', 'latex'); 
        set(groot, 'defaulttextinterpreter', 'latex');
        set(groot, 'defaultLegendInterpreter', 'latex');
    end

    set(gca,'FontSize',20);
end
sgtitle('Comparison between PathFinder and Matlab approx of Airy functions');

set(gcf, 'Position', [100, 600, 1000, 800]);

%% step two: plot PathFinder's contour deformation for Ai(x)
figure(2);
% modified version of above function handle
numSubPlots = 3;
xDefRange = linspace(-5,5,numSubPlots^2);
for n=1:numSubPlots^2
    subplot(numSubPlots, numSubPlots, n);
    aiTestVal = (1/(2i*pi))*PathFinder(-pi/3, pi/3, [], ...
                    -1i*[1/3 0 -xDefRange(n) 0], 1, numQuadPts, ...
                    'inf contour',[true true],'plot');
    title(sprintf('Ai(%.4f)',xDefRange(n)));
end
set(gcf, 'Position', [700, 600, 1000, 1000]);
sgtitle('PathFinder deformation for a range of values of x');