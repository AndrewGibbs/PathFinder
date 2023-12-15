cd '/home/andrew/OneDrive/PathFinder/src/myMEX';
addpath ../..;
addPaths;

%% --------------   inputs to the MEX function  ---------------- %

g_coeffs = [1.000000000000000
                           0
          -0.500000000000000
          -1.000000000000000
                           0];
freq =  1000;
xi = -0.500000000000000;
Cosc = 6.283185307179586;
num_rays = uint32(16);
take_max = false;
imag_thresh = 1.000000000000000e-08;

% temp adjustment to trigger bisection:
imag_thresh = 1e-30; 

%% --------------   outputs of the MEX function  ---------------- %

r_ = 0.006243713025860;

%% ---------- create the mex function ---------------------%

mex -output get_smallest_supset_ball_myMex get_smallest_supset_ball.c -lmwlapack;
disp('created mex file');

r = get_smallest_supset_ball_myMex(g_coeffs, freq, xi, Cosc,num_rays, take_max, imag_thresh);

