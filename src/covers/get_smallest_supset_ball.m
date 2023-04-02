function r = get_smallest_supset_ball(g_coeffs, freq, xi, Cosc)
%find the smallest ball containing the blob such that freq*|g(z)-g(\xi)|<C
    num_rays = 16;
    radii = zeros(num_rays,1);
    d_theta = 2*pi/num_rays;
    for n=1:num_rays
        theta = d_theta*num_rays;
        radii(n) = get_r_given_theta(g_coeffs, xi, Cosc/freq, theta);
    end
    r = min(radii);
end