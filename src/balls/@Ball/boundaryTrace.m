% given a Ball object, and some points in [0,1] parametrising the
% circumferance, map to the circumferance.
function pointsOnCircle = boundaryTrace(self,paramArray)
    % if ball has positive radius
    if self.radius>0
        % plot points on complex circumferance
        pointsOnCircle = self.centre + ...
                self.radius*cos(paramArray*2*pi) + ...
                self.radius*1i*sin(paramArray*2*pi);
    else
        % otherwise just return single point at centre
        pointsOnCircle = self.centre+1i*eps;
    end
end