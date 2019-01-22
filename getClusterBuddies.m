function budz = getClusterBuddies(clusters, n)
%looks through a list of cluster indices, and returns the one that n is in
    budz=[];
    for m=1:length(clusters)
        if ismember(n,clusters{m})
            budz = clusters{m};
            break;
        end
    end
    if isempty(budz)
        error('Couldnt find cluster index');
    end
end

