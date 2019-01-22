function contoursOut = deleteRedudantContours(contoursIn)
%removes all contours which start and end in the same cluster

    contoursOut = [];
    for C = contoursIn
        if ~isempty(C.endCoverIndex) %if finite
            if ~ismember(C.endCoverIndex,C.startClusterIndices)
                contoursOut = [contoursOut C];
            end
        end
    end
end

