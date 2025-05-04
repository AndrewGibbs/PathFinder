#

If the user has requested to log performance of various PathFinder  routines, this routine creates a struct with all of the relevant information.

The file is stored in `.log`. For more information about how to create logs, see [Advanced usage](../../usage/advanced.md). 

```matlab
LogStruct = initLog(filename)
```

## Inputs

`filename` is the name of the log file to be created. 

## Outputs

`LogStruct` is a struct with all of the necessary information for creating and adding to the log file.