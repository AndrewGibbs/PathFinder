% This example construct a polynomial whose coefficients
% are the first few digits of pi.
% First we will see how the contour deformation changes as
% we increase the frequency.
% Next we compare Matlab/Octave's built in 'integral' routine against
% PathFinder, for a range of frequencies. Note that Matlab
% uses an adaptive Simpson's rule, which will become slow
% at high frequencies. 
% We observe that the digits of agreement between the two methods
% drops for sufficiently high frequency. Meanwhile, Matlab/Octave's
% CPU time is increasing, wheras PathFinder's is roughly fixed.

%% set up the integral
phaseCoeffs = [3 1 4 1 5 9 2];

f = @(x) pi*x - pi*x.^3;

numQuadPts = 25;

% endpoints
a = -1;
b = 1;

%% produce a plot of the PathFinder deformation for a few frequencies

freqs = [1 10 500];
numFreqs = length(freqs);
figure(1);
for ifreq = 1:numFreqs
    subplot(1,numFreqs, ifreq);
    PathFinder(a, b, f, phaseCoeffs, freqs(ifreq), numQuadPts, 'plot');
    title(sprintf('freq=%d',freqs(ifreq)));
end
set(gcf, 'Position', [100, 600, 1400, 400]);

if usingOctave()
      axes('Position', [0 0 1 1], 'Visible', 'off');
      text(0.5, 0.97, 'PathFinder deformation for a range of frequencies', 'HorizontalAlignment', 'center', ...
          'FontSize', 20, 'FontWeight', 'bold');
  else
      sgtitle('PathFinder deformation for a range of frequencies','fontsize',20);
end

%% compare performance against Matlab

numReps = 100; % how many times to repeat timing test

% surpress warnings as Matlab begins to struggle:
warning('off', 'MATLAB:integral:MaxIntervalCountReached');

% create header of table:
if usingOctave()
    usingSoftware = 'Octave';
else
    usingSoftware = 'Matlab';
end

fprintf(['\nFrequency\t|PathFinder time (s)\t|%s time (s)\t', ...
    '|Digits of agreement\n', ...
    '--------------------------------------------',...
    '-----------------------------------------\n'], usingSoftware);

% loop over a range of frequencies
for freq = [10 50 100 500 1000 5000 10000]

    % get PathFinder approximation
    tic;
    for n=1:numReps % repeat several times
        Ipf = PathFinder(a, b, f, phaseCoeffs, freq, numQuadPts); 
    end
    tpf = toc/numReps;

    % get Matlab's approximation
    integrand = @(x) f(x).*exp(1i*freq*polyval(phaseCoeffs, x));
    tic;
    if usingOctave()
        for n=1:numReps % repeat several times
            Iml = integral(@(x) real(integrand(x)), a, b) ...
                + 1i*integral(@(x) imag(integrand(x)), a, b);
        end
    else
        for n=1:numReps % repeat several times
            Iml = integral(integrand, a, b);
        end
    end
    tml = toc/numReps;

    % count the number of digits that the approximations agree
    digitsAgreement = round(max(0, -log10(abs(Ipf-Iml)/abs(Iml))));

    % print to the table
    fprintf('|%d\t\t|%.2e\t\t|%.2e\t\t|%d\n', ...
            freq, tpf, tml, digitsAgreement);

end