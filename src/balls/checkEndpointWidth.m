% As described in the paper, this is a preliminary step to determine if the
% original integral can be considered non-oscillatory. To achieve this, we
% place temporary balls around both endpoints {a,b}, based on the same critirea
% used to determine radii throughout the algorithm. If the balls overlap,
% this is an indication that there are only a small nunmber of oscillations
% between the endpoints.

function isOverlapping = checkEndpointWidth(a, b, phaseCoeffs, freq, numOscs, ...
                                            numRays, isInteriorBall, imagThresh, ...
                                            useMex)

    % get radii around endpoints, as if they were balls around stationary
    % points
    if useMex
        r_a = get_smallest_supset_ball_mex(phaseCoeffs.', freq, a, numOscs, numRays, ~isInteriorBall, imagThresh);
        r_b = get_smallest_supset_ball_mex(phaseCoeffs.', freq, b, numOscs, numRays, ~isInteriorBall, imagThresh);
    else
        r_a = getSmallestSupsetBall(phaseCoeffs.', freq, a, numOscs, numRays, ~isInteriorBall, imagThresh);
        r_b = getSmallestSupsetBall(phaseCoeffs.', freq, b, numOscs, numRays, ~isInteriorBall, imagThresh);
    end

    % check if the (pretend) balls around the endpoints overlap
    isOverlapping = (abs(b-a)<r_a+r_b);
end