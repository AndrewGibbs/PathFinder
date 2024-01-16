function point = boundaryTrace(self,paramVal)
    if self.radius>0
        point = self.centre + ...
                self.radius*cos(paramVal*2*pi) + ...
                self.radius*1i*sin(paramVal*2*pi);
    else
        point = self.centre+1i*eps;
    end
end