function ChebAij = Aij3(aValley,bValley,Pcoeffs,freq,Npts,degs,range, includeRegion)
if nargin == 7
    includeRegion =@(x,y) true;
end
reuseThresh = inf;

    deltaInit = .1;

    if ~isequal(range(1:2),range(3:4))
        error('Range must be square');
    end
    
    domainWidth = range(2) - range(1);
    sqrtSubDomainsInit = ceil(domainWidth/deltaInit);
    deltaInit = domainWidth/sqrtSubDomainsInit;
    
    xSubDom = linspace(range(1),range(2),sqrtSubDomainsInit+1);
    ySubDom = linspace(range(3),range(4),sqrtSubDomainsInit+1);
    
    %get 2nd kind Chebyshev nodes to use with Chebfun2D
    xPts = ChebyshevRoots( degs(1), 'Un', range(1:2) );
    yPts = ChebyshevRoots( degs(2), 'Un', range(3:4) );
    
    ell = 1;
    oneToNumPoints = 1:length(xPts);
    for n=1:sqrtSubDomainsInit
        xInBoxInds = oneToNumPoints(xPts>=xSubDom(n) & xPts<xSubDom(n+1));
        for m=1:sqrtSubDomainsInit
            yInBoxInds = oneToNumPoints(yPts>=ySubDom(m) & yPts<ySubDom(m+1));
            subBox(ell) = struct('xL',xSubDom(n),'xR',xSubDom(n+1),...
                                 'yL',ySubDom(m),'yR',ySubDom(m+1),...
                                 'xInds',xInBoxInds,'yInds',yInBoxInds);
            ell = ell + 1;
        end
    end

    %evaluate contour integral A(x,y) at Chebyshev nodes
    Avals = NaN(length(xPts),length(yPts));
    numBoxes = length(subBox);
    parfor n =1:numBoxes
        PcoeffsPar = Pcoeffs;
        if mod(n,floor(numBoxes/100))==0
            fprintf('\n%.2f%%',100*(n/numBoxes));
        end
        xCentre = mean([subBox(n).xL,subBox(n).xR]);
        yCentre = mean([subBox(n).yL,subBox(n).yR]);
        [GCentre, SPs_init, order] = NSDeetsFromPoly(PcoeffsPar(xCentre, yCentre), 1e-16); %have set clumping to be the same
        contoursCentre = getSDtopology(GCentre,SPs_init,sum(order)+1,aValley,bValley,false);
        makeQuad(contoursCentre,freq,Npts,GCentre{1}); %initialise the quadrature
        Abits{n} = subBoxPar(subBox(n),xPts,yPts,Pcoeffs,includeRegion,contoursCentre,freq,Npts,reuseThresh);
        
    end
    
    %now piece it back together
    for n =1:numBoxes
       Avals(subBox(n).xInds,subBox(n).yInds) = Abits{n}; 
    end
    
    %approximate by 2D Chebfun
    ChebAij = chebfun2(Avals,[range(1) range(2) range(3) range(4)]);
end