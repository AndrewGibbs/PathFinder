%clear all;
%close all;
PF_dir = fileparts(which('PathFinder.m'));
mex_path = [PF_dir '/mex_compilation/'];

%% First, compile path tracing routines as MEX code.
% No non-standard packages are required, so these can be compiled with the 
% same commands in Matlab and Octave.

% compilation path for the contour-based MEX functions
contours_path = [PF_dir '/contours/'];

% compile 'sdPathODEeuler'
mex('-output', [contours_path 'sdPathODEeulerMex'], [mex_path 'sd_path_ode_euler.c']); 

% compile 'sdQuadODEeulerCorrection'
mex('-output', [contours_path 'sdQuadODEeulerCorrectionMex'], [mex_path 'sd_quad_ode_euler_correction.c']);

% compile 'sdPathODEeulerExtendCoarsePath'
mex('-output', [contours_path 'sdPathODEeulerExtendCoarsePathMex'], [mex_path 'sd_path_ode_euler_extend_coarse_path.c']);
    
%% compile 'get_smallest_supset_ball', requires LApack
% the stynax for compiling with LApack is different in Matlab and Octave.
% Use the following environment variable to determine if we're running
% Octave.

covers_path = [PF_dir '/balls/'];

if usingOctave()
  display("Compiling for Octave MEX");
  mkoctfile('--mex','-llapacke', '-llapack', '-lblas', '-o', [covers_path 'getSmallestSupsetBallMex'], [mex_path 'get_smallest_supset_ball.c']);
else
  display("Compiling for Matlab MEX");
  mex('-output',[covers_path 'getSmallestSupsetBallMex'], [mex_path 'get_smallest_supset_ball.c'], '-lmwlapack');
end