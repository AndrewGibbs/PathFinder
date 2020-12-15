
classdef ContourInterior < ComplexCover
    %generalisation of the ball class... sort of
    
    properties
        %boundary
        %pseudoCentre
        contourPts = 256
        oscScale = 1
    end
    
    methods
        function self = ContourInterior(pseudoCentre,freq,g,index,constScale, orderSum)
            if nargin == 6
                constScale = 1;
            end
            self.oscScale = constScale;
            
            self.pseudoCentre = pseudoCentre;
            self.index = index;
            c = getLevelContour(pseudoCentre, self.oscScale, g, freq, self.contourPts);
            self.boundary.xdata = real(c);
            self.boundary.ydata = imag(c);
            self.exitGrad = min(self.exitGrad,length(self.boundary.xdata));
            self.steepestExits = self.getSteepestExits(g);
            
            self.boundaryComplex = self.boundary.xdata +1i*self.boundary.ydata;
            
            %to determine diameter, construct matrix of pairwise distances
            %from self to self
            x = self.boundary.xdata; y = self.boundary.ydata;
            R = ((x-x.').^2 + (y-y.').^2);
            self.diameter = max(max(R));
            
            self.orderSum = orderSum;
            self.boundaryComplex = self.boundary.xdata +1i*self.boundary.ydata;
            
            %to determine diameter, construct matrix of pairwise distances
            %from self to self
            x = self.boundary.xdata; y = self.boundary.ydata;
            R = ((x-x.').^2 + (y-y.').^2);
            self.diameter = max(max(R));
            
            self.orderSum = orderSum;
        end
        
        function point = boundaryTrace(self,paramVal)
            pts = length(self.boundary.xdata);
            ptIndex = min(floor(paramVal*pts)+1,pts);
            point = self.boundary.xdata(ptIndex) +1i*self.boundary.ydata(ptIndex);
        end
        
        function yn = isIn(self,z)
            yn = inpolygon(real(z),imag(z),self.boundary.xdata,self.boundary.ydata);
        end
    end
end