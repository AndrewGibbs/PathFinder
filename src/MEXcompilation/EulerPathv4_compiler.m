% clear all;
% close all;
% cd src/MEXcompilation/;
% cd /home/andrew/Dropbox/PathFinderInf/src/MEXcompilation;
% cd MEXcompilation;
% [p_log_out, h_log_out, valley_index, ball_index] = ...
%     SDpathODEuler_v4(h0, gCoeffs, SPs, cover_radii, valleys, base_step_size, n_max, r_star,...
%     Newton_small_threshold, Newton_big_threshold)
% let's go through each argument in order:
h0_type = coder.typeof(1+1i);
gCoeffs_type = coder.typeof(1+1i,[1 Inf],[false true]);
SPs_type = coder.typeof(1+1i,[Inf 1],[true false]); % same as above
cover_radii_type = coder.typeof(1,[Inf 1],[true false]);
valleys_type = coder.typeof(1+1i,[Inf 1],[true false]);
base_step_size = coder.typeof(1.0);
n_max_type = coder.typeof(int64(1));
excluded_SPs_indices_type = coder.typeof(int64(1),[Inf 1],[true false]);
r_star_type = coder.typeof(1.0);
Newton_threshold_type = coder.typeof(1.0);

codegen SDpathODEuler_v4 -args {h0_type, gCoeffs_type, SPs_type, cover_radii_type, valleys_type, base_step_size, n_max_type, r_star_type, Newton_threshold_type, Newton_threshold_type}