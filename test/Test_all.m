

%% Test 1: Testing against N.P. Kirk et al. approximations of Pearcey integral, medium N
assert(2e-4>PearceyPig(20));

%% Test 2: Same test, high N
assert(2e-5>PearceyPig(100));