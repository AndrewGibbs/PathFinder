function [h_quad, dhdp_quad, Newton_success] = SDquadODEulerNEwton(p_quad, h0, gCoeffs, SPs, freq)

    maxIts = 10;
    thresh = 1e-10;
    Newton_success = ones(size(p_quad));

    %ODE for path of steepest descent, make seperate file for this:
    order = length(gCoeffs)-1;
    dgCoeffs = gCoeffs(1:(end-1)).*(order:-1:1);
    ddgCoeffs = dgCoeffs(1:(end-1)).*((order-1):-1:1);
    F = @(h) 1i./(polyval(dgCoeffs,h))/freq;

    freq_times_g_at_se = freq*polyval(gCoeffs,h0);
    % may not need this yet - but it's the local error est. Return this
    % from the same routine as above:
    abs_dF = @(h) abs(polyval(ddgCoeffs,h)/(polyval(dgCoeffs,h))^2);

    % main loop
    h_quad = zeros(size(p_quad))+1i*eps;

    for N=1:length(p_quad)
        % Euler predictor step
%         if N==1
%             h_quad(N) = h0 + p_quad(1)*F(h0);
%         else

        if N == 1
            h_interim = h0;
        else
            h_interim = h_quad(N-1);
        end

        sum_interim_steps = 0;
        while sum_interim_steps < p_quad(N)-p_quad(N-1)
            interim_step_size = base_step_size*min(1/sqrt(abs_dF(h)),... %aims to keep error roughly constant
                    min(abs(SPs-h))/abs(F(h))); % stops us getting too close to branch
            sum_interim_steps = sum_interim_steps + interim_step_size;
            if interim_step_size >= (p_quad(N)-p_quad(N-1)) - sum_interim_steps
                % next step will take us beyond p(N), so reduce the step
                % size, and save the result as h(N)
                reduced_step_size = (p_quad(N)-p_quad(N-1)) - sum_interim_steps;
                h_quad(N) = h_quad(N-1) + reduced_step_size*F(h_quad(N));
            else
                % continue incremental steps
                h_interim = h_interim + interim_step_size*F(h_interim);
            end
        end
%         end

        % Newton corrector step
        for n = 1:maxIts
            h_quad(N) = h_quad(N) - (-freq_times_g_at_se - 1i*p_quad(N) + freq*polyval(gCoeffs,h_quad(N)))/(freq*polyval(dgCoeffs,h_quad(N)));
            err = abs(freq_times_g_at_se+ 1i*p_quad(N) - freq*polyval(gCoeffs,h_quad(N)));
            if err < thresh
                break;
            elseif n==maxIts
                n = inf;
                break;
            end
        end
        Newton_success(N) = n;
    end

    % now get Jacobian
    dhdp_quad = F(h_quad);
end