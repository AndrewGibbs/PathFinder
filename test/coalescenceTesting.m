% This function tests that PathFinder produces the same result,
% as Matlab's built in adaptive integration routine.

% can only be run for low frequency problems, as Matlab's routine won't
% converge at high frequencies.

function maxErr = coalescenceTesting(numQuadPts, showText)

    try OCTAVE_VERSION;
        isOctave = true;
    catch ERR
        isOctave = false;
    end

    % init the output max err variable
    maxErr = 0;

    % however we will allow more error at high frequencies, due to rounding
    % errors.
    
    %% fixed parameters:

    % test for test endpoints
    a = -1;
    b = 1;
    
    %% loopable parameters:

    % test at these frequencies:
    if isOctave
        % Octave numerical integrator starts to fail at higher freqs
        freqRange = [50 100 250];
    else
        freqRange = 10.^[1 2 3];
    end

    %radii of complex circles on which stationary points lie
    rArray = logspace(-4, 0, 20);
    
    %% main loop
    for freq = freqRange
        if showText
            fprintf('freq=%d\n', freq);
        end
        for P = [2 4 6]
            if showText
                fprintf('\tdegree=%d\n', P);
            end
            for r = rArray
                if showText
                    fprintf('\t\tr=%d\n', r);
                end

                % get the coefficients for the phase function
                poly_coeffs = [1/(P+1) zeros(1,P-1) -r^P 0];
        
                % the PathFinder output
                I_PF = PathFinder(a, b, [], poly_coeffs, freq, numQuadPts, 'use mex', true);
                
                % Compute the non-MEX output. 
                % Octave requires the integrand to be split into real and 
                % imaginary parts.
                I_ML = integral(@(x) real(exp(1i*freq*polyval(poly_coeffs,x))),a,b) ...
                      + integral(@(x) imag(exp(1i*freq*polyval(poly_coeffs,x))),a,b);
                
                % get relative error:
                Ierr = abs(I_PF - I_ML)/abs(I_ML);

                if showText
                    fprintf('\t\trel err=%.2e\n', Ierr);
                end
                
                % account for unavoidable rounding error as we increase freq
                maxErr = max(maxErr, Ierr);
            end
        end
    end
end