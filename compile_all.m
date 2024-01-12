clear all;
close all;
current_path = pwd; % change back to this after compiling everything
s = what('PathFinder');
cd(s.path)
cd src/MEXcompilation/;

%% First, compile path tracing routines as MEX code.
% No non-standard packages are required, so these can be compiled with the 
% % same commands in Matlab and Octave.

% compile 'SDpathODEuler'
mex -output SDpathODEuler_v4_mex SDpathODEuler.c; 

% compile 'SDquadODEulerNEwtonCorrection'
mex -output SDquadODEulerNEwtonCorrection_mex SDquadODEulerNEwtonCorrection.c;

% compile 'SDpathODEuler_extend_coarse_path'
mex -output SDpathODEuler_extend_coarse_path_mex SDpathODEuler_extend_coarse_path.c;

%% compile 'get_smallest_supset_ball', requires LApack
% the stynax for compiling with LApack is different in Matlab and Octave.
% Use the following environment variable to determine if we're running
% Octave.
try OCTAVE_VERSION
  % running Octave
  display("Compiling for Octave MEX");
  mkoctfile --mex -llapacke -llapack -lblas -o get_smallest_supset_ball_mex get_smallest_supset_ball.c
catch ERR % running matlab 
  display("Compiling for Matlab MEX");
  mex -output get_smallest_supset_ball_mex get_smallest_supset_ball.c -lmwlapack;
end

% now switch back to original path
cd(current_path);