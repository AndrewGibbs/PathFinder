function isPass = testInputCheck()
    %tests that PathFinder complains when the wrong inputs are provided

    isPass = true;

    % first input, left endpoint:
    try
        PathFinder([0 0], 1, @(x) x.^2, [1 -0.5 0.5 0 -1 0], 50, 10);
        isPass = false;
    end

    % second input, right endpoint:
    try
        PathFinder(-1, [0 0], @(x) x.^2, [1 -0.5 0.5 0 -1 0], 50, 10);
        isPass = false;
    end

    % third input, function handle
    try
        PathFinder(-1, 1, 'oops', [1 -0.5 0.5 0 -1 0], 50, 10);
        isPass = false;
    end

    % fourth input, vector of coefficients
    try
        PathFinder(-1, 1, @(x) x.^2, rand(2), 50, 10);
        isPass = false;
    end

    % fifth input, frequency
    try
        PathFinder(-1, 1, @(x) x.^2, [1 -0.5 0.5 0 -1 0], [1 1], 10);
        isPass = false;
    end

    % sixth input, number of points
    try
        PathFinder(-1, 1, @(x) x.^2, [1 -0.5 0.5 0 -1 0], 50, -10);
        isPass = false;
    end
end