function Abits = subBoxPar(subBox,xPts,yPts,Pcoeffs,includeRegion,contoursCentre,freq,Npts,reuseThresh)

        if isempty(subBox.xInds) || isempty(subBox.yInds)
            Abits = [];
            return;
        end
        jCount = 0;
        for j = subBox.xInds
            jCount = jCount + 1;
            ellCount = 0;
            for ell = subBox.yInds
                ellCount = ellCount + 1;
                x = xPts(j);
                y = yPts(ell);
                if includeRegion(x,y)
                    G_xy{1} = @(z) polyval(Pcoeffs(x, y),z);
                    [~, w] = makeQuad(contoursCentre,freq,Npts,G_xy,reuseThresh);
                    Abits(jCount,ellCount) = sum(w);
                else
                    Abits(jCount,ellCount) = 0;
                end
            end
        end
end

