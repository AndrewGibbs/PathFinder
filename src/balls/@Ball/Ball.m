classdef Ball
    % Ball in complex plane, typically centred at (or close to) a
    % stationary point
    
    properties % defining the ball
        radius % use convention that endpoints are balls with zero radius
        centre
        index % each ball has a unique integer index
        steepestExits % points on circumferance at which imaginary part of
                      % phase is maximal
    end
    
    methods
        % constructor
        function self = Ball(r,c,g_coeffs,index)
            % allocate basic properties
            self.radius = r;
            self.centre = c;
            self.index = index;
            
            % steepest exits must be computed by rootfinding
            if r>0 % i.e. not an endpoint
                self.steepestExits = ...
                    unique(getSteepestExitsOnBall(g_coeffs.',c,r).');
            else % if zero radius
                % default to a single steepest exit at centre
                self.steepestExits = c;
            end
        end

        % other methods
        yn = isIn(self,point) % check if point is in ball
        point = boundaryTrace(self,paramVal) % get points on circumferance
        
    end
end

