clear all;
close all;
% [value,v_index] = inAball(h, cover_centres, cover_radii)
h_type = coder.typeof(1+1i);
cover_centres_type = coder.typeof(1+1i,[Inf 1],[true false]);
cover_radii_type =coder.typeof(1,[Inf 1],[true false]);

codegen inAball -args {h_type, cover_centres_type, cover_radii_type}