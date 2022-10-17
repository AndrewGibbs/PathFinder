clear all;
close all;
cd /home/andrew/Dropbox/PathFinderInf/src/MEXcompilation;
% cd MEXcompilation;
% radius = get_interior_ball(g_coeffs, freq, SP, order, C)
% let's go through each argument in order:
g_coeffs_type = coder.typeof(1.0+1.0i,[Inf 1],[true false]);
freq_type = coder.typeof(1.0);
SP_type = coder.typeof(1.0+1.0i);
order_type = coder.typeof(uint32(1));
C_type = coder.typeof(1.0);

codegen get_interior_ball -args {g_coeffs_type, freq_type, SP_type, order_type, C_type}