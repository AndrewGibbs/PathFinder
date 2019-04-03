classdef IntervalEndPoint < Ball
    
    properties
        %all inhereted
    end
    
    methods
        function obj = IntervalEndPoint(z,g,ballIndex)
            obj = obj@Ball(0,z,g,ballIndex,0);
        end
        
    end
end

