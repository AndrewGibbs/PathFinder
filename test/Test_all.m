% add pathfinder files to path
run('../addPaths.m');

%% Test 1a: Testing against N.P. Kirk et al. approximations of Pearcey integral, medium N
assert(2e-4>PearceyPig(20));

%% Test 1b: Same test, high N
assert(2e-5>PearceyPig(100));

%% Test 2a: test the mex stuff