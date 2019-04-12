classdef ContourInterior < ComplexCover
    %generalisation of the ball class... sort of
    
    properties
        boundary
        pseudoCentre
    end
    
    methods
        function self = ContourInterior(pseudoCentre,realRange,imagRange,freq,g,index,constScale, orderSum)
            if nargin == 6
                constScale = 1;
            end
            self.pseudoCentre = pseudoCentre;
            self.index = index;
            Z = realRange(:).' + imagRange(:)*1i;
            contourFix = @(z) freq*abs(g(pseudoCentre)-g(z));
            c = contourc(realRange,imagRange,contourFix(Z),[constScale constScale]);
            c_split = contourdata(c);
            foundOurGuy = false;
            openFlag = false;
            for n = 1:length(c_split)
               %put a test here to check that contour is closed
               if c_split(n).isopen
                   openFlag = true;
               end
               if inpolygon(real(pseudoCentre),imag(pseudoCentre),c_split(n).xdata,c_split(n).ydata)...
                        && ~c_split(n).isopen
                   self.boundary = c_split(n);
                   foundOurGuy = true;
               end
            end
            if ~foundOurGuy && openFlag
                error('Could not determine contours, but at least one was open. Try a bigger region.');
            end
            self.exitGrad = min(self.exitGrad,length(self.boundary.xdata));
            self.steepestExits = self.getSteepestExits(g);
            
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