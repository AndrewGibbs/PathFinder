function [p_log_out, h_log_out, success] = ...
    SDpathODEuler_extend_coarse_path(p_init, h_init, gCoeffs, SPs, base_step_size, n_max, P_new_max) %#codegen
    %computes NSD path h(p) and h'(p)

    %ODE for path of steepest descent:
    order = length(gCoeffs)-1;
    dgCoeffs = gCoeffs(1:(end-1)).*(order:-1:1);
    ddgCoeffs = dgCoeffs(1:(end-1)).*((order-1):-1:1);

    % main loop
    h = h_init(end);
    p_log = zeros(n_max,1);
    h_log = zeros(n_max,1)+eps*1i;
    n =length(p_init);
    p_log(1:n) = p_init;
    h_log(1:n) = h_init;
    success = true;
    while p_log(n)<P_new_max
        n = n+1;
        dg_h = polyval(dgCoeffs,h);
        ddg_h = polyval(ddgCoeffs,h);
        F_h = 1i/dg_h;
        p_step_size = base_step_size*min(abs(dg_h^2/ddg_h),min(abs(SPs-h))/abs(F_h));
        h = h + p_step_size*F_h;

        p_log(n) = p_log(n-1)+p_step_size;
        h_log(n) = h;
        if n==n_max
            success = false;
            break
        end
    end
    p_log_out = p_log(1:n);
    h_log_out = h_log(1:n);

end