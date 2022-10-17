function [h_quad, dhdp_quad, Newton_success] = SDquadODEulerNEwtonCorrection(p_quad, p_coarse, h0, h_coarse, gCoeffs, freq, NewtonThresh, NewtonIts)

    p_coarse = p_coarse*freq;

    h_quad = zeros(size(p_quad))+1i*eps;
    Newton_success = ones(size(p_quad));
    freq_times_g_at_se = freq*polyval(gCoeffs,h0);
    order = length(gCoeffs)-1;
    dgCoeffs = gCoeffs(1:(end-1)).*(order:-1:1);
    F = @(h) 1i./(polyval(dgCoeffs,h))/freq;

    for N=1:length(p_quad)

        % linearly interpolate coarse solve for initial guess
        [p_below,coarse_index] = max(p_coarse(p_coarse<=p_quad(N)));
        %p_coarse should always contain a zero, so this shouldn't return a
        %blank.
        
        % get intermediate step size
        dp = p_quad(N)-p_below;
        h_quad(N) = h_coarse(coarse_index) + dp*F(h_coarse(coarse_index));

        % Newton corrector step
        for n = 1:NewtonIts
            h_quad(N) = h_quad(N) - (-freq_times_g_at_se - 1i*p_quad(N) + freq*polyval(gCoeffs,h_quad(N)))/(freq*polyval(dgCoeffs,h_quad(N)));
            err = abs(freq_times_g_at_se+ 1i*p_quad(N) - freq*polyval(gCoeffs,h_quad(N)));
            if err < NewtonThresh
                Newton_success(N) = n;
                break;
            elseif n==NewtonIts
                Newton_success(N) = n+1;
%                 n = uint32(inf);
                break;
            end
        end
%         if newton_fail
%             Newton_success(N) = uint32(inf);
%         else
%             Newton_success(N) = n;
%         end
    end

    % now get Jacobian
    dhdp_quad = F(h_quad);
end