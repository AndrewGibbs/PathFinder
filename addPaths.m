function addPaths()
    % add paths required for PathFinder
    %addpath(genpath('src'));
    path_to_root = fileparts(which('addPaths.m'));
    path_to_src = [path_to_root '/src/'];
    addpath(genpath(path_to_src));
    %addpath(".");
end