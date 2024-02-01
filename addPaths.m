function addPaths()
    % add paths required for PathFinder
    pathToRoot = fileparts(which('addPaths.m'));
    pathToSrc = [pathToRoot '/src/'];
    addpath(genpath(pathToSrc));
end