% add pathfinder files to path
addpath('..');
addPaths;
compileAll;
show_text = false;

%% Test 0: test the mex code agrees with the non-mex version
assert(mexTesting(50));

%% Test 1a: Testing against N.P. Kirk et al. approximations of Pearcey integral, medium N
assert(2e-4>pearceyTest(20,show_text));

%% Test 1b: Same test, higher N
assert(2e-5>pearceyTest(50,show_text));

%% Test 1c: Same test, N so high the Laguerre rule must be derived from scratch
assert(2e-5>pearceyTest(101,show_text));

%% Test 2a: Test against Matlab's approximation of Airy function
assert(1e-6>airyTest(15,show_text));

%% Test 2b: Same test, higher N
assert(1e-10>airyTest(50,show_text));

%% Test 2c: Same test, N so high the Laguerre rule must be derived from scratch
assert(1e-10>airyTest(101,show_text));

%% Test 3a: Test coalescence, low N
assert(1e-4>coalescenceTesting(25,show_text));

%% Test 3b: Test coalescence, high N
assert(1e-12>coalescenceTesting(75,show_text));

%% Test 3c: Test coalescence, extra high N
assert(1e-12>coalescenceTesting(101,show_text));

%% Test 4: Test linear phase special case works
assert(abs(PathFinder(-1,1,[],[1 0],100,100)+0.010127312822195)<1e-14);

%% Test 5: Test plotting
assert(plotTest());

%% Test 6: Test logging
assert(logTest());

%% Test 7: Check that the input checks are correct
assert(testInputCheck());

%% Test 8: Check the auto-generated hard-coded quadrature works
assert(testHCquad());