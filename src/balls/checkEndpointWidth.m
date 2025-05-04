function isOverlapping = checkEndpointWidth(a, b, phaseCoeffs, freq, numOscs, ...
                                            numRays, isInteriorBall, imagThresh, ...
                                            useMex)

% Inputs:
%   a and b are the (finite) endpoints of the contour
%   phaseCoeffs is a vector of coefficients of the polynomial phase
%   freq is the frequency parameter
%   numOscs is a constant parameter which determines the number of
%   oscillations inside of each ball.
%   numRays is a parameter used to determine the radii of each ball, see getSmallestSupsetBallMex
%   isInteriorBall is another parameter used to determine the radii.

    % get radii around endpoints, as if they were balls around stationary
    % points
    if useMex
        r_a = getSmallestSupsetBallMex(phaseCoeffs.', freq, a, numOscs, numRays, ~isInteriorBall, imagThresh);
        r_b = getSmallestSupsetBallMex(phaseCoeffs.', freq, b, numOscs, numRays, ~isInteriorBall, imagThresh);
    else
        r_a = getSmallestSupsetBall(phaseCoeffs.', freq, a, numOscs, numRays, ~isInteriorBall, imagThresh);
        r_b = getSmallestSupsetBall(phaseCoeffs.', freq, b, numOscs, numRays, ~isInteriorBall, imagThresh);
    end

    % check if the (pretend) balls around the endpoints overlap
    isOverlapping = (abs(b-a)<r_a+r_b);
end