function plot(self,varargin)
    % plotting function designed specifically for balls

    % s will parametrise the circumference
    s = linspace(0,1,self.exitGrad);
    plot(self.boundaryTrace(s), varargin{:});
end