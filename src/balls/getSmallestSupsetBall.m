function r = getSmallestSupsetBall(g_coeffs, freq, xi, Cosc,num_rays, take_max, imag_thresh)
%% find the smallest/largest ball enclosed by the closed contour such that
% freq*|g(z)-g(\xi)|<C.

% the default is to take
    radii = zeros(num_rays,1);
    d_theta = 2*pi/double(num_rays);
    for n=1:num_rays
        theta = d_theta*double(n);
        radii(n) = getRGivenTheta(g_coeffs, xi, Cosc/freq, theta, imag_thresh);
        if isinf(radii(n)) && take_max
            radii(n) = 0;
        end
    end

    if take_max
        r = max(radii);
    else
        r = min(radii);
    end
    
    if isinf(r) || r==0
        error("Could not determine radius of ball, try increasing parameter 'num rays', (default value is 16)");
    end
end