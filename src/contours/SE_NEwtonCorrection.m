function [SEn_n, Newton_success] = SE_NEwtonCorrection(P, SEn0, SEx, gCoeffs, NewtonThresh, NewtonIts, nearby_SP, step_size_adjust)

    max_deviation = step_size_adjust*abs(SEn0-nearby_SP);
    Newton_success = false;
    g_at_SEx = polyval(gCoeffs,SEx);
    order = length(gCoeffs)-1;
    dgCoeffs = gCoeffs(1:(end-1)).*(order:-1:1);
    SEn_n = SEn0;

    for n = 1:NewtonIts
        err = g_at_SEx + 1i*P - polyval(gCoeffs,SEn_n);
        % check if residual error is small enough to suggest convergence
        if abs(err) < NewtonThresh
            Newton_success = true;
            break
        end
        % get step which will take us to new point
        Newton_step = err/(polyval(dgCoeffs,SEn_n));
        % get next approx of steepest entrance
        SEn_n = SEn_n + Newton_step;
        % check this step isn't too big
        if abs(Newton_step)>max_deviation % this check is actually not essential
%             Newton_success = false;
            break;
        end
        % check distance from where we started isn't too big
        if abs(SEn_n-SEn0)>max_deviation
%             Newton_success = false;
            break;
        end
    end
end