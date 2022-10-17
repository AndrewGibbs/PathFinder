clear all;
close all;
cd /home/andrew/Dropbox/PathFinderInf/src/MEXcompilation;
% cd MEXcompilation;
% SDquadODEulerNEwtonCorrection(p_quad, p_coarse, h0, h_coarse, gCoeffs, freq)
% let's go through each argument in order:
p_quad_type = coder.typeof(1,[Inf 1],[true false]);
p_coarse_type = coder.typeof(1,[Inf 1],[true false]);
h0_type = coder.typeof(1+1i);
h_coarse_type = coder.typeof(1+1i,[Inf 1],[true false]);
gCoeffs_type = coder.typeof(1+1i,[1 Inf],[false true]);
freq_type = coder.typeof(1.0);
thresh_type = coder.typeof(1.0);
its_type = coder.typeof(uint32(1));

codegen SDquadODEulerNEwtonCorrection -args {p_quad_type, p_coarse_type, h0_type, h_coarse_type gCoeffs_type, freq_type, thresh_type, its_type}