function plotMain(params, covers, contourArray, z, a, b, stationaryPoints,...
    phaseIn, valleys, GraphData)
    %make a plot of what's happened, if requested
    if params.plot
        plotAll(covers, contourArray, z, a, b, params.infContour, ...
            stationaryPoints, phaseIn, valleys);
    end

    % plot the graph representing the deformation, if requested
    if params.plotGraph
        finiteEndpoints = [a b];
        finiteEndpoints = finiteEndpoints(~params.infContour)+1i*eps;
        % may need to create new plot window if one has been opened
        % already:
        if params.plot
            figure();
        end
        plotGraph(GraphData, covers, finiteEndpoints);
    end
end