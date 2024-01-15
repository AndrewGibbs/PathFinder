% add pathfinder files to path
run('../addPaths.m');
run('../compile_all.m');
show_text = false;

%% Test 0: test the mex code agrees with the non-mex version
assert(mex_testing());

%% Test 1a: Testing against N.P. Kirk et al. approximations of Pearcey integral, medium N
assert(2e-4>PearceyTest(20,show_text));

%% Test 1b: Same test, higher N
assert(2e-5>PearceyTest(50,show_text));

%% Test 1c: Same test, N so high the Laguerre rule must be derived from scratch
assert(2e-5>PearceyTest(101,show_text));

%% Test 2a: Test against Matlab's approximation of Airy function
assert(1e-6>AiryTest(15,show_text));

%% Test 2b: Same test, higher N
assert(1e-10>AiryTest(30,show_text));

%% Test 2c: Same test, N so high the Laguerre rule must be derived from scratch
assert(1e-10>AiryTest(101,show_text));