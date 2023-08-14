function plot(self,varargin)
    s = linspace(0,1,self.exitGrad);
    plot(self.boundaryTrace(s), varargin{:});
end