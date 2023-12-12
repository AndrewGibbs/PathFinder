%% --------------   inputs to the MEX function  ---------------- %
P0 = [0.263560319718142;
   1.413403059106518;
   3.596425771040722;
   7.085810005858834;
  12.640800844275784];
P_rescaled = [0; 20];
h0 = -1;
coarsePath = [-1.000000000000000 + 0.000000000000000i;
            -1.004950495049505 - 0.099504950495050i];
phaseCoeffs = [1;0;0];
freq = 100;
NewtonThresh=1.000000000000000e-13;
NewtonIts=50;

%% --------------   outputs of the MEX function  ---------------- %
h_ = [ -1.000000868298642 - 0.001317800454346i;
 -1.000024969793836 - 0.007066838838024i;
 -1.000161613173595 - 0.017979223175887i;
 -1.000626626648417 - 0.035406863145310i;
 -1.001987482152294 - 0.063078636557031i;];

dhdp_ = [ -0.000006588979387 - 0.004999986975558i;
 -0.000035330665348 - 0.004999625484264i;
 -0.000089838035147 - 0.004997577107620i;
 -0.000176591549163 - 0.004990620191582i;
 -0.000312903153068 - 0.004970383946347i];

Newton_success = [3;3;3;3;4];

%% ------------------- create the MEX function ------------------- %
mex -output SDquadODEulerNEwtonCorrection_myMex -g SDquadODEulerNEwtonCorrection.c;
% the -g argument creates in debug mode

%% -------------------- test the MEX function -------------------- %
[h, dhdp, Newton_success] = SDquadODEulerNEwtonCorrection_myMex(P0,...
        P_rescaled, h0, coarsePath, phaseCoeffs, freq, NewtonThresh,...
        uint32(NewtonIts));
