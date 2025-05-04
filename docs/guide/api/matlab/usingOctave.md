# `usingOctave.m`

Allows PathFinder to detect if it is being run from Octave. This is necessary because some (non-essential) features do not work in octave.

```matlab
yn = usingOctave()
```

## Outputs

`yn` is boolean output, true if using Octave, false otherwise. 