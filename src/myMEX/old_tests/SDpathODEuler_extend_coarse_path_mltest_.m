% cd OneDrive/PathFinder/src/myMEX/

%% compile the function
mex SDpathODEuler_extend_coarse_path_mltest.c;

%% set test params
p_init = [0.0; 0.2];
p_length = 2;
h_init = [-1.0 + 0i; -1.004950495049505-0.099504950495050i];
gCoeffs = [1.0; 0.0; 0.0];
SPs = [0.0+0.0i];
base_step_size = 0.1;
n_max = 50000;
P_new_max = 2.992069701227389;

%% run the code
SDpathODEuler_extend_coarse_path_mltest();
% [p_log_out, h_log_out, success] = SDpathODEuler_extend_coarse_path(p_init, h_init, gCoeffs, SPs, base_step_size, n_max, P_new_max);
display('SDpathODEuler_extend_coarse_path run successfully');