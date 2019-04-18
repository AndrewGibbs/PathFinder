function x = ray(f, a, scale, dir)
if nargin == 3
    dir = 1;
end
%follows ray to edge of contour
    N = 10;
    crappyGuess = true;
    count = 0;
    while crappyGuess == true
        guess = a + dir*linspace(0,scale,N);
        isNegative = f(guess) < 0;
        if sum(isNegative) == N
            scale = scale*2;
        elseif sum(isNegative) == 0
            scale = scale/2;
        else
            crappyGuess = false;
        end
        count = count + 1;
        if count>100
            error('failed to find a ray');
        end
    end
    
    inds = 1:N;
    firstPositive = inds(~isNegative);
    a = guess(firstPositive(1)-1);
    b = guess(firstPositive(1));
    
    x = bisection(f, a, b);
end