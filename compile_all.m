clear all;
close all;
addpath(genpath('src'));
current_path = pwd; % change back to this after compiling everything
s = what('PathFinder');
cd(s.path)
cd src/MEXcompilation/;

% addpath(genpath('src/MEXcompilation'));
EulerPathv4_compiler;
% SteepestEntranceCorrection_compiler;
EulerPath_extension_compiler;
steepestExits_compiler;
exteriorBall_compiler;
EulerCorrection_compiler;

cd(current_path);