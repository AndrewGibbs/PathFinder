clear all;
close all;
PF_dir = fileparts(which('PathFinder'));
mex_path = [PF_dir '/MEXcompilation/'];

%% First, compile path tracing routines as MEX code.
% No non-standard packages are required, so these can be compiled with the 
% same commands in Matlab and Octave.

% compilation path for the contour-based MEX functions
contours_path = [PF_dir '/contours/'];

% compile 'SDpathODEuler'
mex('-output', [contours_path 'SDpathODEuler_v4_mex'], [mex_path 'SDpathODEuler.c']); 

% compile 'SDquadODEulerNEwtonCorrection'
mex('-output', [contours_path 'SDquadODEulerNEwtonCorrection_mex'], [mex_path 'SDquadODEulerNEwtonCorrection.c']);

% compile 'SDpathODEuler_extend_coarse_path'
mex('-output', [contours_path 'SDpathODEuler_extend_coarse_path_mex'], [mex_path 'SDpathODEuler_extend_coarse_path.c']);
    
%% compile 'get_smallest_supset_ball', requires LApack
% the stynax for compiling with LApack is different in Matlab and Octave.
% Use the following environment variable to determine if we're running
% Octave.

covers_path = [PF_dir '/covers/'];

try OCTAVE_VERSION
  % running Octave
  display("Compiling for Octave MEX");
  mkoctfile('--mex','-llapacke', '-llapack', '-lblas', '-o', [covers_path 'get_smallest_supset_ball_mex'], [mex_path 'get_smallest_supset_ball.c']);
catch ERR % running matlab 
  display("Compiling for Matlab MEX");
  mex('-output',[covers_path 'get_smallest_supset_ball_mex'], [mex_path 'get_smallest_supset_ball.c'], '-lmwlapack');
end