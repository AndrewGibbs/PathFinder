function yn = checkEndpointWidth(a,b,g_coeffs,freq,Cosc,num_rays,int_balls_yn,imag_thresh, use_mex)

    % get radii around endpoints, as if they were to be balls
    if use_mex
        r_a = get_smallest_supset_ball_mex(g_coeffs.', freq, a, Cosc, num_rays,~int_balls_yn,imag_thresh);
        r_b = get_smallest_supset_ball_mex(g_coeffs.', freq, b, Cosc, num_rays,~int_balls_yn,imag_thresh);
    else
        r_a = getSmallestSupsetBall(g_coeffs.', freq, a, Cosc, num_rays,~int_balls_yn,imag_thresh);
        r_b = getSmallestSupsetBall(g_coeffs.', freq, b, Cosc, num_rays,~int_balls_yn,imag_thresh);
    end

    % check if the (pretend) balls overlap
    yn = (abs(b-a)<r_a+r_b);
end