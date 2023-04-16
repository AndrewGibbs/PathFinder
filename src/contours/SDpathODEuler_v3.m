function [p_log_out, h_log_out, valley_index, ball_index, success] = ...
    SDpathODEuler_v3(h0, gCoeffs, SPs, cover_radii, valleys, base_step_size, n_max, r_star,...
    Newton_small_threshold, Newton_big_threshold) %#codegen

    % version three adds error checking at each step
    
    %computes NSD path h(p) and h'(p)
    %excluded_SPs_indices
    valley_index = [];
    ball_index = [];
    success = true;
    if isempty(SPs)
        SPs = inf; % bodge to speed things up further down
        cover_radii = 0;
    end
    for n=1:length(SPs)
        % another bodge to stop stationary points being treated like critical
        % points
        if cover_radii(n)==0% || ismember(n,excluded_SPs_indices)
            SPs(n) = inf;
        end
    end

    g_se = polyval(gCoeffs,h0); % value of g at steepest exit

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

    % main loop
    h = h0;
    p_log = zeros(n_max,1);
    h_log = zeros(n_max,1)+eps*1i;
    p_log(1) = 0;
    h_log(1) = h0;
    n =1;
    while ~halt_euler()
        % get ingreidents which will be used multiple times
        n = n+1;
        dg_h = polyval(dgCoeffs,h);
        ddg_h = polyval(ddgCoeffs,h);

        % Forward Euler step
        F_h = 1i/dg_h;
        p_step_size = base_step_size*min(abs(dg_h^2/ddg_h),min(abs(SPs-h))/abs(F_h));
        h = h + p_step_size*F_h;
        
        % error checking
        g_h = polyval(gCoeffs,h);
%         longitude_err = imag(g_h)-imag(g_se)-p;
%         transverse_err = real(g_h)-real(g_se);
        p = p_log(n-1)+p_step_size;
        Newton_step = get_Newton_step;

        % might as well apply Newton once:
        h = h-Newton_step;

        if abs(Newton_step)>Newton_big_threshold
            %apply newton more times
            Newton_method(Newton_step);
        end

        p_log(n) = p;
        h_log(n) = h;

        
        if halt_euler()
            % beyore actually halting the process, refine this endpoint
            Newton_method();
        end

        if mod(int64(n),int64(n_max))==0 % need to add more points
%             success = false;
%             break
            p_log_copy = p_log;
            h_log_copy = h_log;
            p_log = zeros(n_max+n,1);
            h_log = zeros(n_max+n,1);
            p_log(1:n) = p_log_copy;
            h_log(1:n) = h_log_copy;
        end
    end
    p_log_out = p_log(1:n);
    h_log_out = h_log(1:n);

    if success
        if inAball(h, SPs, cover_radii)
            [~,ball_index] = inAball(h, SPs, cover_radii);
        else
            [~,valley_index] = beyondNoReturn(h,Cnr,argBeta,valleys);
        end
    else
        ball_index = [];
        valley_index = [];
    end


    %% indended functions
    function step = get_Newton_step()
        g_h = polyval(gCoeffs,h);
        dg_h = polyval(dgCoeffs,h);
        step = (g_h-g_se-1i*p)/dg_h;
    end

    function Newton_method(Newton_step)
        if nargin == 0
            Newton_step = get_Newton_step();
        end
        while abs(Newton_step)>Newton_small_threshold
            h = h-Newton_step;
            if abs(Newton_step)>Newton_small_threshold
                Newton_step = get_Newton_step();
            end
        end
    end

    function yn = halt_euler() 
        yn = inAball(h, SPs, cover_radii) || beyondNoReturn_v2(h,valleys,gCoeffs,r_star);
    end
end