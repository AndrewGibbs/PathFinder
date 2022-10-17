clear all;
close all;
% [value,v_index] = beyondNoReturn(h,Cnr,argBeta,V)
h_type = coder.typeof(1+1i);
Cnr_type = coder.typeof(1);
argBeta_type = coder.typeof(1+1i);
V_type = coder.typeof(1+1i,[Inf 1],[true false]);

codegen beyondNoReturn -args {h_type, Cnr_type, argBeta_type, V_type}