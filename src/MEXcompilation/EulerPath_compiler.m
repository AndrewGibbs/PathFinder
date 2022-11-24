clear all;
close all;
cd /home/andrew/Dropbox/PathFinderInf/src/MEXcompilation;
% cd MEXcompilation;
%SDpathODEuler(h0, gCoeffs, SPs, cover_radii, valleys, base_step_size)
%SDpathODEuler_v2(h0, gCoeffs, SPs, cover_radii, valleys, base_step_size, n_max, r_star)
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

% codegen SDpathODEuler -args {h0_type, gCoeffs_type, SPs_type, cover_radii_type, valleys_type, base_step_size, n_max_type, excluded_SPs_indices_type}
codegen SDpathODEuler_v2 -args {h0_type, gCoeffs_type, SPs_type, cover_radii_type, valleys_type, base_step_size, n_max_type, r_star_type}