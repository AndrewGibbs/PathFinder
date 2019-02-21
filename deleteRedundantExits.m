function coversOut = deleteRedundantExits(coversIn)
%sometimes, the steepest exit from a cover will start off inside of another
%ball. These get confusing and will cause errors later, so this function
%deletes them before contours are created.
if isempty(coversIn)
    coversOut = [];
    return;
end
numCovers = length(coversIn);
coversOut = coversIn;

    for m=1:numCovers
        for x = coversIn(m).steepestExits
            %checking all exits of all covers
            for n=[1:(m-1) (m+1):numCovers]
                if coversIn(n).isIn(x)
                    %delete this exit, if it's in another cover
                    coversOut(m).steepestExits(coversOut(m).steepestExits==x) = [];
                end
            end
        end
    end
end

