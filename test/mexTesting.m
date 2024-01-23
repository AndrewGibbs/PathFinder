% This function tests that PathFinder produces the same result,
% with and without MEX. Some discrepancies are unavoidable, and the paths
% may not always match, but the output values should agree (up to some
% tolerance).
function isPass = mexTesting(numQuadPts)
    % always expect more agreement than this:
    err_thresh = 1e-14;
    % however we will allow more error at high frequencies, due to rounding
    % errors.

    % this output variable will switch to false in the case of non-agreement:
    isPass = true;
    
    %% fixed parameters:

    % test for test endpoints
    a = -1;
    b = 1;
    
    %% loopable parameters:

    % test at these frequencies:
    freqRange = [100 1000 10000 100000 1000000];

    %radii of complex circles on which stationary points lie
    rArray = logspace(-4,0,20);
    
    %% main loop
    for freq = freqRange
        for P = [2 4 6]
            for r = rArray

                % get the coefficients for the phase function
                polyCoeffs = [1/(P+1) zeros(1,P-1) -r^P 0];
        
                % the MEX output
                IwithMex = PathFinder(a, b, [], polyCoeffs, freq, numQuadPts, ...
                                    'use mex', true);
                
                % the non-MEX output
                IwithoutMex = PathFinder(a, b, [], polyCoeffs, freq, numQuadPts, ...
                                    'use mex', false);
                
                % get relative error:
                Ierr = abs(IwithMex - IwithoutMex) / abs(IwithoutMex);
                
                % account for unavoidable rounding error as we increase freq
                if Ierr>err_thresh*freq
                    isPass = false;
                end
            end
        end
    end
end