function [z,w] = quadBodge(a,b,gCoeffs,freq,Npts)

    dgCoeffs_step1 = ((length(gCoeffs)-1):-1:1);
    dgCoeffs = dgCoeffs_step1.*gCoeffs(1:(end-1));
    
    SPs = roots(dgCoeffs);
    
    g = @(x) polyval(gCoeffs,x);
    dgdz = @(x) polyval(dgCoeffs,x);
    G = {g, dgdz};
    
    order = length(gCoeffs)-1;
    
    valleys = exp(2i*pi*(1/4 + (1:order))/order);
    
    infContour = false;
    C = 1;
    
    coverIndex = 1;
    if ~infContour
       for endpoint = [a b]
           endPointBalls(coverIndex) = Ball(0,endpoint,G{1},coverIndex,0);
           coverIndex = coverIndex + 1;
       end
    else
        endPointBalls = [];
    end
    
    x = linspace(-2,2,2000);
    z = x + 1i*x.';
    
    for n = 1:length(SPs)
        coversInit(n) = ContourInterior(SPs(n),x,x,freq,g,coverIndex,C);
        coverIndex = coverIndex + 1;
    end

    %delete exits inside a cover from another mother:
    covers = [num2cell(endPointBalls) num2cell(deleteRedundantExits(coversInit))];

    %now determine which covers overlap:
    [intersectionMatrix, clusters, clusterEndpoints] = coverOverlapV2(covers);

    contours = [];
    
     for n = 1:length(covers)
        if ~infContour && ismember(n,[1 2])
            intervalEndpoint = covers{n}.centre;
        else
            intervalEndpoint = [];
        end
        for xi = covers{n}.steepestExits
            contours = [contours ContourSD(xi,G,covers{n},coversComplement(n),valleys,clusters,clusterEndpoints)];
        end
     end
     
    contourSeq = shortestInfinitePathV2(contours, covers, intersectionMatrix, valleys, a, b, infContour);
    contoursInSeq = contours(contourSeq);

    [z, w] = makeQuad(contoursInSeq, freq, Npts, G, false, [a b]);
    
    function coversOut = coversComplement(n)
        numCovers = length(covers);
        for m=1:(n-1)
            coversOut{m}=covers{m};
        end
        for m=(n+1):numCovers
            coversOut{m-1}=covers{m};
        end
    end
    
end
