function L = listdijkstra(L,W,s,d)

index=size(W,1);
while index>0
    if W(2,d)==W(size(W,1),d)
        L=[L s];
        index=0;
    else
        index2=size(W,1);
        while index2>0
            if W(index2,d)<W(index2-1,d)
%                 L=[L W(index2,1)]; % previous cause of bug
                % fix from discussion section of this algorithm:
                if W(index2,1)==s
                    L = [L 1];
                else
                    L=[L W(index2,1)];
                end 
                L=listdijkstra(L,W,s,W(index2,1));
                index2=0;
            else
                index2=index2-1;
            end
            index=0;
        end
    end
end