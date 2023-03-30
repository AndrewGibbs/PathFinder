function SEn_guess = make_SEn_guess(h_n,h_nm1,SP,R2)
    % interpolates between final two points of coarse solve, to approximate
    % steepest entrance
    
    R1 = abs(h_n-SP);
    % get \theta, angle on circle at which line intersects ball
    cos_theta = real((h_n-h_nm1)*(h_n-SP)')/(abs(h_n-h_nm1)*abs(h_n-SP));

    % now use rule of cosines to determine point on circle
    r_vals = roots([1 -2*R1*cos_theta R1^2-R2^2]);
    r_guess = r_vals(r_vals>=0);
    SEn_guess =  h_n + r_guess*(h_nm1-h_n)/abs(h_n-h_nm1);
end