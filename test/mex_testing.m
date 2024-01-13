% This function tests that PathFinder produces the same result,
% with and without MEX. Some discrepancies are unavoidable, and the paths
% may not always match, but the output values should agree (up to some
% tolerance).
function pass_tf = mex_testing()
    % always expect more agreement than this:
    err_thresh = 1e-14;
    % however we will allow more error at high frequencies, due to rounding
    % errors.

    % this output variable will switch to false in the case of non-agreement:
    pass_tf = true;
    
    %% fixed parameters:

    % test for test endpoints
    a = -1;
    b = 1;
    
    % this many quadrature points
    N = 50;
    
    %% loopable parameters:

    % test at these frequencies:
    freq_range = [100 1000 10000 100000 1000000];

    %radii of complex circles on which stationary points lie
    r_range = logspace(-4,0,20);
    
    %% main loop
    for freq = freq_range
        for P=[2 4 6]
            for r=r_range

                % get the coefficients for the phase function
                poly_coeffs = [1/(P+1) zeros(1,P-1) -r^P 0];
        
                % the MEX output
                I_mex = PathFinder(a,b,[],poly_coeffs,freq,N,'use mex',true);
                
                % the non-MEX output
                I_nomex = PathFinder(a,b,[],poly_coeffs,freq,N,'use mex',false);
                
                % get relative error:
                Ierr = abs(I_mex-I_nomex)/abs(I_nomex);
                
                % account for unavoidable rounding error as we increase freq
                if Ierr>err_thresh*freq
                    pass_tf = false;
                end
            end
        end
    end
end