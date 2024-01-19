function logQuadratureDetails(params, netwonIterationData, quadToc)
    params.log.addToLog(sprintf("Quadrature allocation time:\t%fs",quadToc));
    for i = 1:length(netwonIterationData)
        newtonSummaryString = [];
        for n = (netwonIterationData{i}.')
            newtonSummaryString = ...
                [newtonSummaryString, ' ', num2str(n)];
        end
        params.log.addToLog(sprintf( ...
            "\tNewton refinement steps:\t%s", newtonSummaryString));
    end
end