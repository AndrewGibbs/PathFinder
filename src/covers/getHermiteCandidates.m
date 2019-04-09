function HermiteCandidates = getHermiteCandidates(clusters, clumpEndpoints, covers)
%determine which covers contain a single non-degenerate stationary point

    HermiteCandidates = [];
    for n=1:length(clusters)
       if length(clusters{n})==1
           m = clusters{n};
          if isempty(clumpEndpoints{n}) && covers{m}.orderSum == 1
              HermiteCandidates = [HermiteCandidates m];
          end
       end
    end
end

