# `logContourDetails.m`

This subroutine records information about the steepest descent contours, including proxies for their magnitude, and the time taken for their construction.

```matlab
logContourDetails(params, contourArray, timeTaken)
```

## Inputs

* `params` : A struct of information about how to add to the log.
* `contourArray` : An array of [`ContourSD`](ContourSD.md).
* `timeTaken` : Time taken to construct the coarse contour approximation.