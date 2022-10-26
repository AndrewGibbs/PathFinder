classdef Ball < ComplexCover
    %Ball in complex plane
    
    properties
        radius
        centre
    end
    
    methods
        function self = Ball(r,c,g_coeffs,index,orderSum)
            self.radius = r;
            self.centre = c;
            self.pseudoCentre = c;
            self.index = index;
            self.orderSum = orderSum;
            self.boundaryLength = 2*pi*r;
            self.diameter = r;
            self.boundary.xdata = [c];
            self.boundary.ydata = [c];
            self.exitGrad = 32*max(self.orderSum,1);
            
            if r>0
                if nargin>2
                    %self.steepestExits = self.getSteepestExits(@(x) polyval(g_coeffs,x)); % used
                    %to be polyval g, now it's just coeffs
                    self.steepestExits = get_stepest_exits_on_ball_mex(g_coeffs.',c,r).';
                end
            else
                self.steepestExits = c;
            end
            s = linspace(0,1,self.exitGrad);
            self.boundaryComplex = self.boundaryTrace(s);
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
                point = self.centre+1i*eps;
            end
        end
        
    end
end

