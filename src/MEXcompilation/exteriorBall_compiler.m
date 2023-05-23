% clear all;
% close all;
% cd MEXcompilation;
% radius = get_smallest_supset_ball(g_coeffs, freq, xi, Cosc)
% let's go through each argument in order:
g_coeffs_type = coder.typeof(1.0+1.0i,[Inf 1],[true false]);
freq_type = coder.typeof(1.0);
SP_type = coder.typeof(1.0+1.0i);
order_type = coder.typeof(uint32(1));
C_type = coder.typeof(1.0);
num_rays_type = coder.typeof(uint32(1));
int_ext_yn_type = coder.typeof(true);

codegen get_smallest_supset_ball -args {g_coeffs_type, freq_type, SP_type, C_type, num_rays_type, int_ext_yn_type}