% Chooses a suitable sequence of steepest descent and straight line
% contours, which correspond to a deformation of the original integration
% contour from a to b. This is done by representing the key topological
% properties of known quantities as a graph, and then solving a shortest
% path problem.

% Specifically, for this graph:
% balls, exits, entrances, endpoints and valleys are interpreted as nodes.
% steepest descent contours (finite or infinite), and straight line contours
% connecting points inside balls, are represented as edges.
% The approach in this code is to create multiple adjacency matrices
% corresponding to the connections between different types of points (or
% valleys). These adjacency matrices are then combined, and we keep track
% of the different meanings of the different indices. This adjacency matrix
% is used to solve the shortest path problem.

function [Q, graphData] = ...
    shortestInfinitePath(a, b, contours, balls, valleys, params)

%% PART ONE: Get all connections as a result of overlapping/sharing of balls
    exitCount = 0;

    % initialise adjacency matrix for crictical points
    CPsAdjMat = eye(length(balls));

    % here the critical points are effectivel the centres of balls
    numCPs = length(balls);

    % initialise vector storing critical points
    CPs = zeros(1,numCPs);
    numValleys = length(valleys);  

    for iCP = 1:numCPs
        CPs(iCP) = balls{iCP}.centre;
        % link steepest exits to balls
        localNumExits = 0;
        for jExit = balls{iCP}.steepestExits
            exitCount = exitCount + 1;
            %record all steepest exits in a vector
            exits(exitCount) = jExit;
            % count number of steepest exits
            localNumExits = localNumExits + 1;
            
            % for each steepest exit, find out which balls its in
            % and store this info as edges
            for jCP = 1:numCPs
                if balls{jCP}.isIn(jExit)
                    exitsToCPsAdj(exitCount, jCP) = 1;
                end
            end
        end

        localExitsRange = (exitCount-localNumExits+1):(exitCount);
        % now connect the steepest exits on the circumferance with the 
        % centre of this ball
        exitsAdjMat(localExitsRange, localExitsRange) = 1;
        % and connect the steepest exits to all other steepest exits on
        % circumferance of ball
        exitsToCPsAdj(localExitsRange, iCP) = 1;

        % work out which balls overlap with other balls, store the info
        for jCP = 1:numCPs
            % test if balls overlap:
            if abs(balls{iCP}.centre-balls{jCP}.centre) ...
                    < balls{iCP}.radius + balls{jCP}.radius
                % connect balls in adjacncey matrix if they overlap, by
                % connecting all points in/on each ball
                CPsAdjMat(iCP, jCP) = 1;
            end
        end
    end

    % now connect SEs to all other SEs inside the same ball
    for iCP=1:numCPs
        exitInCPlogicalInds = (exitsToCPsAdj(:,iCP) == 1);
        exitsAdjMat(exitInCPlogicalInds, exitInCPlogicalInds) = 1;
    end

    numExits = length(exits);

%% PART TWO: Get all connections which result from contours

    % now determine which steepest exits connect with which valleys (or
    % possibly, steepest exits)
    exitsToValleysAdj = zeros(exitCount, numValleys);
    contourCount = 0;
    exitsToEntrsAdj = [];
    entrsToCPsAdj = [];
    entrs = [];
    finitePathIndices = [];

    numEntrs = 0;
    % get number of steepest entrances
    for iContour = 1:length(contours)
      contour = contours(iContour);
        if ~isinf(contour.length)
            % each finite contour will have one steepest entrance
            numEntrs = numEntrs + 1;
        end
    end

    % initialise these adjacency matrices
    entrsToCPsAdj = zeros(numEntrs, numCPs);
    exitsToEntrsAdj = zeros(numExits, numEntrs);

    numEntrs = 0;
    for iContour = 1:length(contours)
      contour = contours(iContour);
        contourCount = contourCount + 1;
        if isinf(contour.length) % infinite contour
            exitIndex = find(exits == contour.startPoint);
            endValleyIndex = find(valleys==contour.endValley);
            % connect exit to valley
            exitsToValleysAdj(exitIndex, endValleyIndex) = 1;
        else % finite contour
            numEntrs = numEntrs + 1;
            entrs(numEntrs) = contour.endPoint;
            exitIndex = find(exits==contour.startPoint);
            % connect exit to entrance
            exitsToEntrsAdj(exitIndex, numEntrs) = 1;
            % below 2xN matrix records that this is a special link, 
            % via a finite contour:
            finitePathIndices = [finitePathIndices; exitIndex numEntrs]; 
            % should be two per row
            endCPindex = contour.endCoverIndex;
            entrsToCPsAdj(numEntrs, endCPindex) = 1;
            % now link to every steepest exit that the stationary point linked to 
            % the critical point at the centre of the ball at the end of the contour
            exitsToEntrsAdj(exitsToCPsAdj(:,endCPindex)==1, numEntrs) = 1;
        end
        exitsToContoursVec(exitIndex) = contourCount;
    end

    %% PART THREE: combine all this stuff to build the full adjacency matrix:
    %diagonal blocks:
    % CPsAdjMat
    % exitsAdjMat
    % an identity matrix for the valleys
    %five non-zero non-diagonal blocks:
    % exitsToCPsAdj
    % exitsToValleysAdj
    % entrsToCPsAdj
    % exitsToEntrsAdj

    % initialise full adjacency matrix:
    adjMat = eye(numCPs+numExits+numEntrs+numValleys);

    % Compute ranges of relevant indices. This will be quite useful.
    CPsRange = 1:numCPs;
    exitsRange = (numCPs+1):(numCPs+numExits);
    entrsRange = (numCPs+numExits+1):(numCPs+numExits+numEntrs);
    valleysRange = (numCPs+numExits+numEntrs+1):(numCPs+numExits+numEntrs+numValleys);

    % now allocate diagonal blocks:
    adjMat(CPsRange,CPsRange) = CPsAdjMat;
    adjMat(exitsRange,exitsRange) = exitsAdjMat;
    % valleys are never directly connected by a single contour, thus we can
    % skip this step for valleys

    % now allocate the non-diagonal blocks:
    adjMat(exitsRange,CPsRange) = exitsToCPsAdj;
    adjMat(exitsRange,valleysRange) = exitsToValleysAdj;
    adjMat(exitsRange,entrsRange) = exitsToEntrsAdj;
    adjMat(entrsRange,CPsRange)= entrsToCPsAdj;

    % later it will be useful to group these points together:
    CPsAndExitsAndEntrs = [CPs exits entrs];

    % now do one final loop over SPs, to connect any points inside that
    % ball
    for iCP = 1:numCPs

        % initialise with points on boundary of ball
        indicesInNthBallClosure = [];
        for jExit = balls{iCP}.steepestExits
            indicesInNthBallClosure = ...
                [indicesInNthBallClosure find(jExit==CPsAndExitsAndEntrs)];
        end

        % now add all indices for points in interior of ball to same vector
        for jPoint = 1:length(CPsAndExitsAndEntrs)
            if balls{iCP}.isIn(CPsAndExitsAndEntrs(jPoint))
                indicesInNthBallClosure = [indicesInNthBallClosure jPoint];
            end
        end

        % connect all points in/on the same ball
        for p = indicesInNthBallClosure
            for q = indicesInNthBallClosure
                adjMat(p,q) = 1;
            end
        end
    end

    % now convert to symmetric logical form
    adjMat = (adjMat+adjMat')>0;

    %% determine which indices correspond to which endpoints
    ab = [a b];
    endPointIndices = zeros(1,2);
    for iEndpoint = 1:2
        % if contour is infinite
        if params.infContour(iEndpoint)
            % loop over all valleys and check which one matches
            for m = 1:numValleys
                if abs(ab(iEndpoint) - valleys(m)) < 10*eps
                    % match the enpoint index to that of the valley
                    endPointIndices(iEndpoint) = ...
                        numCPs + numExits + numEntrs + m;
                    break
                end
            end
        else % finite contour
            for m=1:numExits
                % loop over all exits and check which one matches
                if abs(ab(iEndpoint)-exits(m)) < 10*eps
                    % match endpoint to that of exit
                    endPointIndices(iEndpoint) = numCPs + m;
                    break;
                end
            end
        end
    end

    if min(endPointIndices) <= 0
        error('Could not find endpoints in valleys or steepest exits');
    end

    %% now compute shortest path and allocate quadrature 'ingredients'

    % get shortest path, using adjacency matrix and Dijkstra's algorithm:
     [~, seq] = dijkstra(adjMat*1, endPointIndices(2), endPointIndices(1));

     % I've included a couple of redundant maps below, commented out, for
     % completeness - I think it makes the full process clearer, of how the
     % indices are arranged.

%    allToCPmap = @(n) n;
     allToExitMap = @(n) n-numCPs;
     allToEntrMap = @(n) n-numCPs-numExits;
%    allToValleyMap = @(n) n-numCPs-numExits-numEntrs;

     % store this stuff in a struct for plotting later, if desired:
     graphData = struct('adj_mat', adjMat, 'points', CPsAndExitsAndEntrs, ...
                        'CPs', CPs, 'SExs', exits, 'SEns', entrs, ...
                        'valleys', valleys, 'shortest_path', seq);
    
    % Now, turn the path, which is currently a sequence of indices corresponding
    % to centres, entrances, exits and valleys, into instructions for quadrature.
    % In the below comments, any 'ball' can also refer to a 'finite endpoint'

    for iNode=1:(length(seq)-1)
        % now categorise every type of interaction
        startIndex = seq(iNode);
        endIndex = seq(iNode+1);

        % if contour starts on ball (endpoint) and ends in valley
        if ismember(startIndex, exitsRange) && ismember(endIndex, valleysRange)
            startExitIndex = allToExitMap(startIndex);
            % inf contour from steepest exit to valley
            Q{iNode}.type = 'infSD';
            Q{iNode}.inOut = 1;
            Q{iNode}.contour = contours(exitsToContoursVec(startExitIndex));

        % if contour starts in a valley and ends on a ball
        elseif ismember(startIndex,valleysRange) && ismember(endIndex, exitsRange)
            endExitIndex = allToExitMap(endIndex);
            % as above, reversed case
            Q{iNode}.type = 'infSD';
            Q{iNode}.inOut = -1;
            Q{iNode}.contour = contours(exitsToContoursVec(endExitIndex));

        % if contour descends from a ball to another ball
        elseif ismember(startIndex, exitsRange) && ismember(endIndex, entrsRange) ...
                && ismember([allToExitMap(startIndex) ...
                    allToEntrMap(endIndex)],finitePathIndices,'rows')
            %finite contour, from steepest exit to steepest entrance
            Q{iNode}.type = 'finSD';
            Q{iNode}.inOut = 1;
            Q{iNode}.contour = contours(exitsToContoursVec(allToExitMap(startIndex)));

        % if contour ascends from a ball to another ball
        elseif ismember(endIndex, exitsRange) && ismember(startIndex, entrsRange) ...
                && ismember([allToExitMap(endIndex) ...
                    allToEntrMap(startIndex)],finitePathIndices,'rows')
            % as above, reversed case
            Q{iNode}.type = 'finSD';
            Q{iNode}.inOut = -1;
            Q{iNode}.contour = contours(exitsToContoursVec(allToExitMap(endIndex)));

        % else - nodes must be two points on or inside ball, so a straight 
        % line contour can be used to connect these two, as inside the ball
        % we only have mild oscillations
        else
            % can use straight lines here
            if CPsAndExitsAndEntrs(startIndex) ~= CPsAndExitsAndEntrs(endIndex)
                Q{iNode}.type = 'strLn';
                Q{iNode}.a = CPsAndExitsAndEntrs(startIndex);
                Q{iNode}.b = CPsAndExitsAndEntrs(endIndex);
                Q{iNode}.Nscale = 1;
            end
        end
    end
end