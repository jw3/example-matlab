matlab examples
===

Some examples of using the Matlab libraries with cmake and c++

### Matlab configuration notes

- Set `Matlab_ROOT_DIR` to point cmake to the right installation
- Ensure that `matlab` is found on the PATH when executing, as the wrapper call uses the cmd line .. as strange as that is
- FindMatlab.cmake actually calls `matlab` to identify the version number of the application, failing if it cant
  - So in other words your license needs to be available to run CMake
- Turn on `MATLAB_FIND_DEBUG` for help
  - `set(MATLAB_FIND_DEBUG true)`
- FindMatlab.cmake uses a hardcoded list of version numbers when it searches for matlab
  - You can add a new version with `MATLAB_ADDITIONAL_VERSIONS`
- Matlab shared libraries are not versioned and may conflict with system libraries when linking
- It appears `R2015b` may not have the linking issues that `R2017a` has
- It also appears that using the standard matlab finder resolves linking issues all together?
  - or at least hacking libs out of path is not needed anyways 


### Adding all current Matlab versions to CMake 3.5.1

If on Ubuntu 16.04 and CMake 3.5.1, only versions up to `"R2015b=8.6"` will be found by default ([source](https://github.com/Kitware/CMake/blob/v3.5.1/Modules/FindMatlab.cmake#L231-L246))

To add versions up to the latest as of 08/2017, add this before find_library.

- 
  ```
    set(MATLAB_ADDITIONAL_VERSIONS 
        "R2017a=9.2"
        "R2016b=9.1"
        "R2016a=9.0")
  ```

### See
- https://cmake.org/cmake/help/v3.5/module/FindMatlab.html
- https://github.com/Kitware/CMake/blob/v3.5.1/Modules/FindMatlab.cmake
