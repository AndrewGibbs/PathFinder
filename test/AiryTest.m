function isPass = AiryTest(thresh,nQuadPts)
    % compares Matlab's Airy function approx to PathFinder's (first kind)
    % number of x values to test against
    nxPts = 1000;
    xArray = linspace(-5,5,nxPts);

    % variable which will switch to false when test fails
    isPass = true;

    for x = xArray

        % get Matlab's approximation of Ai(x)
        airyMatlab = airy(1,x);

        % get PathFinder's approximation of Ai(x)
        airyPathFinder = PathFinder(-pi/3, pi/3, [], -1i*[1/3 0 -x 0], 1, nQuadPts, 'inf contour', [true true]);

        % compute relative error (assuming Matlab is exact)
        relErr = abs(airyMatlab - airyPathFinder)/airyMatlab;

        % check that the error is below the specified value
        if relErr>thresh
            % if not, the fail the test
            isPass = false;
            break;
        end
    end
end