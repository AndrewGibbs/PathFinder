% add pathfinder files to path
run('../addPaths.m');
run('../compile_all.m');

%% Test 0: test the mex code agrees with the non-mex version
assert(mex_testing());

%% Test 1a: Testing against N.P. Kirk et al. approximations of Pearcey integral, medium N
assert(2e-4>PearceyTest(20,true));

%% Test 1b: Same test, high N
assert(2e-5>PearceyTest(100,true));

%% Test 2a: Test approximation of Airy functionn
assert(AiryTest(thresh,nQuadPts));