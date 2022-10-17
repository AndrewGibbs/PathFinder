function [value,output_index] = inAball(h, cover_centres, cover_radii)
%returns 1 if SD path is in a ball, 0 otherwise
    value = false;
    output_index = 0;
    for index = 1:length(cover_centres)
        if abs(h-cover_centres(index))<cover_radii(index)
            value = true;
            output_index = index;
            break;
        end
    end
end