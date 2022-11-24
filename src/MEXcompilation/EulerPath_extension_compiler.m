clear all;
close all;
cd /home/andrew/Dropbox/PathFinderInf/src/MEXcompilation;
% cd MEXcompilation;
%SDpathODEuler_extend_coarse_path(self.coarseParam, self.coarsePath, self.phaseCoeffs, SPs, quad_params.global_step_size, int64(max_steps_before_fail), max(self.P0)/freq);
% let's go through each argument in order:
coarseParam_type = coder.typeof(1,[Inf 1],[true false]);
coarsePath_type = coder.typeof(1+1i,[Inf 1],[true false]);
phaseCoeffs_type = coder.typeof(1+1i,[1 Inf],[false true]);
SPs_type = coder.typeof(1+1i,[Inf 1],[true false]); % same as above
step_size_type = coder.typeof(1.0);
n_max_type = coder.typeof(int64(1));
P_new_max_type = coder.typeof(1.0);

codegen SDpathODEuler_extend_coarse_path -args {coarseParam_type, coarsePath_type, phaseCoeffs_type, SPs_type, step_size_type, n_max_type, P_new_max_type}