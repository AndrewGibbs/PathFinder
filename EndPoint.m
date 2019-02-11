classdef EndPoint < ComplexCover
    %Ball in complex plane
    
    properties
        radius
        centre
    end
    
    methods
        function self = Ball(c,g,index,orderSum)
            self.radius = 0;
            self.centre = c;
            self.index = index;
            self.orderSum = orderSum;
            self.boundaryLength = 0;
            self.diameter = 0;
            
            if r>0
                if nargin>2
                    self.steepestExits = self.getSteepestExits(g);
                end
            else
                self.steepestExits = c;
            end
        end
        
        function yn = isIn(self,point)
            yn = abs(point-self.centre)<self.radius;
        end
        
        function point = boundaryTrace(self,paramVal)
            if self.radius>0
                point = self.centre + ...
                        self.radius*cos(paramVal*2*pi) + ...
                        self.radius*1i*sin(paramVal*2*pi);
            else
                point = self.centre;
            end
        end
        
    end
end

