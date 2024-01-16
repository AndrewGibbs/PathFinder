% This function tests that PathFinder produces the same result,
% as Matlab's built in adaptive integration routine.

% can only be run for low frequency problems, as Matlab's routine won't
% converge at high frequencies.

function max_err = coalescenceTesting(numPts,show_text)

    % init the output max err variable
    max_err = 0;

    % however we will allow more error at high frequencies, due to rounding
    % errors.
    
    %% fixed parameters:

    % test for test endpoints
    a = -1;
    b = 1;
    
    %% loopable parameters:

    % test at these frequencies:
    freq_range = 10.^[1 2 3];

    %radii of complex circles on which stationary points lie
    r_range = logspace(-4,0,20);
    
    %% main loop
    for freq = freq_range
        if show_text
            fprintf('freq=%d\n',freq);
        end
        for P=[2 4 6]
            if show_text
                fprintf('\tdegree=%d\n',P);
            end
            for r=r_range
                if show_text
                    fprintf('\t\tr=%d\n',r);
                end

                % get the coefficients for the phase function
                poly_coeffs = [1/(P+1) zeros(1,P-1) -r^P 0];
        
                % the PathFinder output
                I_PF = PathFinder(a,b,[],poly_coeffs,freq,numPts,'use mex',true);
                
                % the non-MEX output
                I_ML = integral(@(x) exp(1i*freq*polyval(poly_coeffs,x)),a,b);
                
                % get relative error:
                Ierr = abs(I_PF-I_ML)/abs(I_ML);

                if show_text
                    fprintf('\t\trel err=%.2e\n',Ierr);
                end
                
                % account for unavoidable rounding error as we increase freq
                max_err = max(max_err,Ierr);
            end
        end
    end
end