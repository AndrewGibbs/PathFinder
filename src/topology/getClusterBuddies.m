function [budz, budzEndpoint] = getClusterBuddies(clusters, index, clusterEndpoints)
%looks through a list of cluster indices, and returns the one that n is in
if nargin == 2
    clusterEndpoints = [];
    budzEndpoint = [];
end
    budz=[];
    for m=1:length(clusters)
        if ismember(index,clusters{m})
            budz = clusters{m};
            if ~isempty(clusterEndpoints)
                budzEndpoint = clusterEndpoints{m};
            end
            break;
        end
    end
    if isempty(budz)
        error('Couldnt find cluster index');
    end
end

