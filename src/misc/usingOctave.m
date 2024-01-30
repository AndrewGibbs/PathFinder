function yn = usingOctave()
% returns true if running in Octave, false otherwise (Matlab)
    try OCTAVE_VERSION;
        yn = true;
    catch ERR % running matlab
        yn = false;
    end
end

