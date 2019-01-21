classdef (Abstract) ComplexCover
    %set in the complex plane, intended to contain all tricky local
    %behaviour of steepest descent paths
    
    %should be convex! but in practice will probably always be a ball
    %anyway
    
    properties
        boundaryLength
        steepestExits
        index %index all covers
        orderSum %sum of all orders of all stationary points inside cover
        exitGrad = 256; %accuracy to compute exit points of cover
        diameter
    end
    
    methods
        yn = isIn(self,point)
        point = boundaryTrace(self,paramVal)
        
        function exits = getSteepestExits(self,g)
            s = linspace(0,1,self.exitGrad);
            s = [s(end) s(1:end-1) s(1) s(2)];
            Im_goB = @(s) imag(g(self.boundaryTrace(s)));
            exits = [];
            for j = 2:(self.exitGrad+1)
                %check if this s corresponds to a local maxima
                if Im_goB(s(j)) > Im_goB(s(j-1)) && Im_goB(s(j)) > Im_goB(s(j+1))
                    exits = [exits self.boundaryTrace(s(j))];
                end
            end
        end
        
        function plot(self)
            s = linspace(0,1,self.exitGrad);
            plot(self.boundaryTrace(s),'.');
        end
    end
end