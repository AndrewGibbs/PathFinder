function pass = semiInfTest()
    %tests PathFinderQuad 'works' for a semi-infinite integral, on x^3
    a = -1i;
    b = -1;
    z = PathFinderQuad(a, b, [1 0 0 0], 1, 15, 'infContour', [true false], 'plot');
    pass = true;
    
    %doesn't check for accuracy though
end