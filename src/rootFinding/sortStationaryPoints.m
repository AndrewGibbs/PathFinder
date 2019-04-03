function [stationaryPoints,stationaryPointsOrders,clumpWidth] = sortStationaryPoints(stationaryPointsInit,stationaryPointMinDist)
%determines order of stationary points and groups nearby points
    
    if nargin == 1
        %if two stationary points are this close, make them one
        stationaryPointMinDist=1E-4;
    end
    
    stationaryPointsInit=sort(stationaryPointsInit);
    
    clumpIndex = 1:length(stationaryPointsInit);
    m_clumped = [];
    
    clump = cell(length(stationaryPointsInit),1);
    
    for n = 1:length(stationaryPointsInit)
        clump{n} = stationaryPointsInit(n);
    end
    
    for n=1:length(clump)
        for m=n+1:length(clump)
            if min(abs(clump{n}-stationaryPointsInit(m))) < stationaryPointMinDist
                %move point m into clump n
                clump{m} = clump{m}(clump{m}~=stationaryPointsInit(m));
                clump{n} = [clump{n} stationaryPointsInit(m)];
            end
        end
    end
    
%     for n = 1:length(stationaryPointsInit)
%         if ~(ismember(n,m_clumped))
%             clump{n} = stationaryPointsInit(n);
%         end
%         for m = n+1:length(stationaryPointsInit)
%             if abs(stationaryPointsInit(n)-stationaryPointsInit(m)) < stationaryPointMinDist
%                 clumpIndex(m) = clumpIndex(n);
%                 clump{clumpIndex(m)} = [clump{clumpIndex(m)} stationaryPointsInit(m)];
%                 m_clumped = [m_clumped m];
%             end
%         end
%     end
    
    SPcount = 0;
    for n=1:length(clump)
       if ~isempty(clump{n})
           SPcount = SPcount + 1;
           stationaryPoints(SPcount) = mean(clump{n});
           stationaryPointsOrders(SPcount) = length(clump{n});
           clumpWidth(SPcount) = max(max(abs(clump{n}-clump{n}.')));
       end
    end
    
%     distinctCount=0;
%     %determine the orders of the stationary points, by checking for repetitions:
%     for n = 1:length(stationaryPointsInit)
%         if n>1 & abs(stationaryPointsInit(n)-stationaryPointsInit(n-1)) < stationaryPointMinDist
%             stationaryPointsOrders(distinctCount)=stationaryPointsOrders(distinctCount)+1;
%         else
%             distinctCount = distinctCount+1;
%             stationaryPoints(distinctCount) = stationaryPointsInit(n);
%             stationaryPointsOrders(distinctCount) = 1;
%         end
%     end
end

