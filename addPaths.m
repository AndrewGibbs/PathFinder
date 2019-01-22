function addPaths()
%paths required for PathFinder2
    %old bits of PathFinder
    addpath('../NSD/src');
    addpath ../NSD/src/pathChoosing;
    addpath ../NSD/src/pathFinding;
    addpath ../NSD/src/quadrature;
        addpath ../NSD/src/quadrature/expansion;
        addpath ../NSD/src/quadrature/quadrules;
        addpath ../NSD/src/quadrature/OPQ;
    addpath ../NSD/src/rootFinding;
    addpath ../NSD/src/singularPoints;
    addpath ../NSD/src/infContours;
    
    %Chebfun
    addpath(genpath('/Users/andrew/chebfun'));
    
    %old bits of inf contour integrals
    addpath /Users/andrew/Dropbox/Andrew-Daan/code/NSD/DaveCode;
end

