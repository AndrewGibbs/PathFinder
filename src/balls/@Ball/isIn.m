% given a Ball object (self),
% determine if a point is inside the ball, or not
function yn = isIn(self,point)
        yn = abs(point-self.centre)<self.radius;
end