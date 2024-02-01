function addPaths()
    % add paths required for PathFinder
    pathToRoot = fileparts(which('addPaths.m'));
    pathToSrc = [pathToRoot '/src/'];
    addpath(pathToRoot);
    addpath(genpath(pathToSrc));
end