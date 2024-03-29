function maxRelErr = airyTest(nQuadPts, outputText)
    % compares Matlab's Airy function approx to PathFinder's (first kind)

    % number of x values to test against
    nxPts = 100;
    % get x points
    xArray = linspace(-5,5,nxPts);

    if outputText
        disp("Testing against (Matlab's) Airy function");
    end

    maxRelErr = 0;
    for x = xArray
        if outputText
            fprintf('x=%.2f\n',x);
        end

        % get Matlab's approximation of Ai(x)
        airyMatlab = airy(0,x);

        % get PathFinder's approximation of Ai(x)
        airyPathFinder = (1/(2i*pi))*PathFinder(-pi/3, pi/3, [], ...
                        -1i*[1/3 0 -x 0], 1, nQuadPts, 'inf contour',...
                        [true true]);

        % compute relative error (assuming Matlab is exact)
        relErr = abs(airyMatlab - airyPathFinder) / airyMatlab;

        if outputText
            fprintf('\trel err=%e\n', relErr);
        end

        % update the max rel error if required
        maxRelErr = max(maxRelErr, relErr);

    end
end