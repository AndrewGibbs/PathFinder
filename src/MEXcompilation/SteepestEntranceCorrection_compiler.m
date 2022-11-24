clear all;
close all;
cd /home/andrew/Dropbox/PathFinderInf/src/MEXcompilation;
% cd MEXcompilation;
% SE_NEwtonCorrection(P, SEn0, SEx, gCoeffs, NewtonThresh, NewtonIts, nearby_SP, step_size_adjust)
% let's go through each argument in order:
P_type = coder.typeof(1);
SEn0_type = coder.typeof(1+1i);
SEx_type = coder.typeof(1+1i);
gCoeffs_type = coder.typeof(1+1i,[1 Inf],[false true]);
NewtonThresh_type = coder.typeof(1.0);
NewtonIts_type = coder.typeof(uint32(1));
nearby_SP_type = coder.typeof(1+1i);
step_size_adjust = coder.typeof(1.0);

codegen SE_NEwtonCorrection -args {P_type, SEn0_type, SEx_type, gCoeffs_type, NewtonThresh_type, NewtonIts_type, nearby_SP_type, step_size_adjust}