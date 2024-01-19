function logContourDetails(params, contourArray, timeTaken)
    params.log.addToLog(sprintf("Contour coarse construction:\t%fs", timeTaken));
    % also log the number of points in the coarse approximation of each
    % contour:
    for iCount = 1:length(contourArray)
        contPts = length(contourArray(iCount).coarsePath);
        if sign(imag(contourArray(iCount).startPoint))<0
            ipm = '-';
        else
            ipm = '+';
        end
        params.log.addToLog(sprintf("\tContour %d: start point " + ...
            "%.2f%s%.2fi,\tlength %.2f,\t%d pts", ...
            iCount, real(contourArray(iCount).startPoint), ipm,...
            abs(imag(contourArray(iCount).startPoint)), ...
            contourArray(iCount).length, contPts));
    end
end