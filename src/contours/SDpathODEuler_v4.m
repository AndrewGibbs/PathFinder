function [p_log_out, h_log_out, valley_index, ball_index, Newton_points, Newton_its, Newton_final_pt_its] = ...
    SDpathODEuler_v4(h0, gCoeffs, SPs, cover_radii, valleys, base_step_size, n_max, r_star,...
    Newton_small_threshold, Newton_big_threshold, Newton_point_count_max) %#codegen

    % version three adds error checking at each step
    if Newton_point_count_max>0
        Newton_log = true;
    else
        Newton_log = false;
    end
    %computes NSD path h(p) and h'(p)
    %excluded_SPs_indices
    valley_index = [];
    ball_index = [];

    if isempty(SPs)
        SPs = inf; % bodge to speed things up further down
        cover_radii = 0;
    end
    for n=1:length(SPs)
        % another bodge to stop endpoints being treated like stationary
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

    % main loop
    h = h0;
    p_log = zeros(n_max,1);
    h_log = zeros(n_max,1)+eps*1i;
    p_log(1) = 0;
    h_log(1) = h0;
    n =1;

    Newton_points = complex(zeros(Newton_point_count_max,1));
    Newton_its = int64(zeros(Newton_point_count_max,1));
    Newton_log_count = 0;
    Newton_final_pt_its = 0;
    
    dg_h = polyval(dgCoeffs,h);
    continue_loop = true;
    log_this_point = false;

    while continue_loop
        % get ingreidents which will be used multiple times
        n = n+1;
        ddg_h = polyval(ddgCoeffs,h);

        % PREVIOUSLY MISSING THIS UPDATE:
        dg_h = polyval(dgCoeffs,h);

        % Forward Euler step
        F_h = 1i/dg_h;
        p_step_size = base_step_size*min(2*abs(dg_h^2/ddg_h),min(abs(SPs-h))/abs(F_h));
        h = h + p_step_size*F_h;
        
        % error checking
        g_h = polyval(gCoeffs,h);
        dg_h = polyval(dgCoeffs,h);
        p = p_log(n-1)+p_step_size;
        Newton_step = get_Newton_step();

        if Newton_log && (Newton_log_count <Newton_point_count_max) && (abs(Newton_step)>Newton_big_threshold)
            log_this_point = true;
            Newton_log_count = Newton_log_count + 1;
        end

        while abs(Newton_step)>Newton_big_threshold
            if Newton_log && (Newton_log_count <Newton_point_count_max)
                Newton_its(Newton_log_count) = Newton_its(Newton_log_count) + 1;
            end
            h = h-Newton_step;
            Newton_step = get_Newton_step();
        end

        if Newton_log && (Newton_log_count <Newton_point_count_max)
            Newton_points(Newton_log_count) = h;
            log_this_point = false;
        end
        % might as well apply Newton once more
        h = h-Newton_step;

        p_log(n) = p;
        h_log(n) = h;

        [inball_yn, in_no_return_yn, endex] = halt_euler();

        continue_loop = ~(inball_yn || in_no_return_yn);

        if inball_yn % only refine endpoint to fine level if in a ball
            % before actually halting the process, refine this endpoint
            Newton_step = get_Newton_step();
            while abs(Newton_step)>Newton_small_threshold
                h = h-Newton_step;
                Newton_step = get_Newton_step();
                if Newton_log
                    Newton_final_pt_its = Newton_final_pt_its + 1;
                end
            end
            % might as well apply Newton once more
            h_log(n) = h-Newton_step;
            ball_index = endex;
        else
            valley_index = endex;
        end

        if mod(int64(n),int64(n_max))==0 % need to add more points
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

    if Newton_log
        Newton_points = Newton_points(1:(Newton_log_count-1));
        Newton_its = Newton_its(1:(Newton_log_count-1));
    end

    %% indented functions
    function step = get_Newton_step()
        g_h = polyval(gCoeffs,h);
        dg_h = polyval(dgCoeffs,h);
        step = (g_h-g_se-1i*p)/dg_h;
    end

    function [inball_yn, in_no_return_yn, index] = halt_euler() 
        [inball_yn, index] = inAball(h, SPs, cover_radii);
        if inball_yn
            in_no_return_yn = false;
        else
            [in_no_return_yn, index] = beyondNoReturn_v2(h,valleys,gCoeffs,r_star);
        end
    end
end