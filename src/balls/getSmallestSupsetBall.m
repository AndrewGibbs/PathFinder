% find the smallest/largest (determined by 'isLargestBall') ball enclosed
% by the closed contour such that:
% freq*|g(z)-g(\xi)|<numOscs,
% where g is the phase function
 function r = getSmallestSupsetBall(phaseCoeffs, freq, stationaryPoint, ...
                                    numOscs, numRays, isLargestBall, ...
                                    imag_thresh)
    % here the radii are determined by firing a ray in each direction 
    % \theta, and finding r when
    % freq*|g(\xi+r*exp(i\theta))-g(\xi)|=numOscs
    radii = zeros(numRays,1);

    % these rays are determined by splitting 2pi into numRays directions,
    % the following width apart:
    dTheta = 2*pi/double(numRays);

    % loop over all rays
    for iRay=1:numRays
        % get ray direction
        theta = dTheta*double(iRay);

        % get radius, in the sense defined above, using the below
        % rootfinding algorithm
        radii(iRay) = getRGivenTheta(phaseCoeffs, stationaryPoint, ...
                                        numOscs/freq, theta, imag_thresh);

    end

    % choose either the the smallest ball bounding the region, or a the
    % largest ball inside the region
    if isLargestBall
        r = max(radii);
    else
        r = min(radii);
    end
    
    % error checking for infinite or zero radius, incase rootfinder fails
    if isinf(r) || r==0
        error("Could not determine radius of ball, try increasing parameter" + ...
            " 'num rays', (default value is 16)");
    end
end