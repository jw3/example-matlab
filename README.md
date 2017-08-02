matlab examples
===

Some examples of using the Matlab libraries with cmake and c++

### configuration notes

If cmake does not want to find your installed matlab, take a look at the list of versions it is looking for.

For example, if on Ubuntu 16.04 and CMake 3.5.1, you will not have some of the latest releases included.

- https://github.com/Kitware/CMake/blob/v3.5.1/Modules/FindMatlab.cmake#L231-L246

You can add a new version with `MATLAB_ADDITIONAL_VERSIONS`

  `set(MATLAB_ADDITIONAL_VERSIONS "R2017a=9.2")` 

### See
- https://cmake.org/cmake/help/v3.3/module/FindMatlab.html
- https://github.com/Kitware/CMake/blob/master/Modules/FindMatlab.cmake
