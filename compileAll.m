PFdir = fileparts(which('PathFinder.m'));
mexPath = [PFdir '/mex_compilation/'];

%% First, compile path tracing routines as MEX code.
% No non-standard packages are required, so these can be compiled with the 
% same commands in Matlab and Octave.

% compilation path for the contour-based MEX functions
contoursPath = [PFdir '/contours/'];

% compile 'sdPathODEeuler'
mex('-output', [contoursPath 'sdPathODEeulerMex'], ...
    [mexPath 'sd_path_ode_euler.c']); 

% compile 'sdQuadODEeulerCorrection'
mex('-output', [contoursPath 'sdQuadODEeulerCorrectionMex'], ...
    [mexPath 'sd_quad_ode_euler_correction.c']);

% compile 'sdPathODEeulerExtendCoarsePath'
mex('-output', [contoursPath 'sdPathODEeulerExtendCoarsePathMex'], ...
    [mexPath 'sd_path_ode_euler_extend_coarse_path.c']);
    
%% compile 'get_smallest_supset_ball', requires LApack
% the stynax for compiling with LApack is different in Matlab and Octave.
% Use the following environment variable to determine if we're running
% Octave.

coversPath = [PFdir '/balls/'];

if usingOctave()
  display("Compiling for Octave MEX");
  if ismac
        mkoctfile(...%'--mex','-llapacke', '-llapack', '-lblas', '-o', ...
        '--mex','-o',[coversPath 'getSmallestSupsetBallMex'], [mexPath 'get_smallest_supset_ball.c'],...
        '-I/opt/homebrew/opt/openblas/include','-L/opt/homebrew/opt/openblas/lib','-lopenblas');
  else
      mkoctfile('--mex','-llapacke', '-llapack', '-lblas', '-o', ...
      [coversPath 'getSmallestSupsetBallMex'], [mexPath 'get_smallest_supset_ball.c']);
  end
else
  display("Compiling for Matlab MEX");
  mex('-output',[coversPath 'getSmallestSupsetBallMex'], ...
      [mexPath 'get_smallest_supset_ball.c'], '-lmwlapack');
end
