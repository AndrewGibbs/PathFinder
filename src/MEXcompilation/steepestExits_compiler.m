% clear all;
% close all;
% cd src/MEXcompilation/;
% SEs = get_stepest_exits_on_ball(g_coeffs,centre,radius)
% let's go through each argument in order:
g_coeffs_type = coder.typeof(1.0+1.0i,[Inf 1],[true false]);
centre_type = coder.typeof(1.0+1.0i);
radius_type = coder.typeof(1.0);

codegen get_stepest_exits_on_ball -args {g_coeffs_type, centre_type, radius_type}