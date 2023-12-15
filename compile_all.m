clear all;
close all;
addpath(genpath('src'));
current_path = pwd; % change back to this after compiling everything
s = what('PathFinder');
cd(s.path)
cd src/MEXcompilation/;

% compile 'SDpathODEuler'
mex -output SDpathODEuler_v4_mex SDpathODEuler.c; 

% compile 'SDquadODEulerNEwtonCorrection'
mex -output SDquadODEulerNEwtonCorrection_mex SDquadODEulerNEwtonCorrection.c;

% compile 'SDpathODEuler_extend_coarse_path'
mex -output SDpathODEuler_extend_coarse_path_mex SDpathODEuler_extend_coarse_path.c;

% compile 'get_smallest_supset_ball', requires LApack
mex -output get_smallest_supset_ball_mex get_smallest_supset_ball.c -lmwlapack;

cd(current_path);