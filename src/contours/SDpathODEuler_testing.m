function [p_log, h_log, dhdp, valley_index, ball_index] = SDpathODEuler(h0, gCoeffs, SPs, cover_radii, valleys, base_step_size)

%     base_step_size = 0.5;

    %computes NSD path h(p) and h'(p)
    valley_index = [];
    ball_index = [];

    %ODE for path of steepest descent:
    order = length(gCoeffs)-1;
    dgCoeffs = gCoeffs(1:(end-1)).*(order:-1:1);
    ddgCoeffs = dgCoeffs(1:(end-1)).*((order-1):-1:1);
    F = @(h) 1i./(polyval(dgCoeffs,h));

    % may not need this yet - but it's the local error est
    abs_dF = @(h) abs(polyval(ddgCoeffs,h)/(polyval(dgCoeffs,h))^2);

    % get parameters for halting zones
    argBeta = angle(gCoeffs(1));
    Cnr = getNoReturnConstant(gCoeffs);

    halt_euler = @(h) beyondNoReturn(h,Cnr,argBeta,valleys) || inAball(h, SPs, cover_radii);

    % main loop
    h = h0;
    h_log = h0; % just keep this for now, for testing
    p_log = 0.0;
    while ~halt_euler(h)
        step_size = base_step_size*min(1/sqrt(abs_dF(h)),... %aims to keep error roughly constant
                    min(abs(SPs-h))/abs(F(h))); % stops us getting too close to branch
        h = h + step_size*F(h);
        h_log = [h_log h];
        p_log = [p_log p_log(end)+step_size];
    end

    if beyondNoReturn(h,Cnr,argBeta,valleys)
        [~,valley_index] = beyondNoReturn(h,Cnr,argBeta,valleys);
    else
        [~,ball_index] = inAball(h,covers);
    end

    %reconstruct h'(p) using ODE
    dhdp = F(h_log);

end