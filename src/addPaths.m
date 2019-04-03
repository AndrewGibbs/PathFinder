function addPaths()
%paths required for PathFinder2
    %old bits of PathFinder
    addpath('../Andrew-Daan/code/NSD/src');
    addpath ../Andrew-Daan/code/NSD/src/pathChoosing;
    addpath ../Andrew-Daan/code/NSD/src/pathFinding;
    addpath ../Andrew-Daan/code/NSD/src/quadrature;
        addpath ../Andrew-Daan/code/NSD/src/quadrature/expansion;
        addpath ../Andrew-Daan/code/NSD/src/quadrature/quadrules;
        addpath ../Andrew-Daan/code/NSD/src/quadrature/OPQ;
    addpath ../Andrew-Daan/code/NSD/src/rootFinding;
    addpath ../Andrew-Daan/code/NSD/src/singularPoints;
    addpath ../Andrew-Daan/code/NSD/src/infContours;
    
    %Chebfun
    addpath(genpath('/Users/andrew/chebfun'));
    
    %old bits of inf contour integrals
%    addpath /Users/andrew/Dropbox/Andrew-Daan/code/NSD/DaveCode;
end

