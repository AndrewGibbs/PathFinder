clear all;
close all;
cd /home/andrew/Dropbox/PathFinderInf/src/MEXcompilation;
% cd MEXcompilation;
% SDquadODEulerNEwton(p_quad, h0, gCoeffs, freq)
% let's go through each argument in order:
p_quad_type = coder.typeof(1,[Inf 1],[true false]);
h0_type = coder.typeof(1+1i);
gCoeffs_type = coder.typeof(1+1i,[1 Inf],[false true]);
freq_type = coder.typeof(1.0);

codegen SDquadODEulerNEwton -args {p_quad_type, h0_type, gCoeffs_type, freq_type}