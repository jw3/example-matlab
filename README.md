matlab examples
===

Some examples of matlab mcr development

### Configuration

Dependency management provided by Conan https://conan.io/

### finding matlab

The matlab mcr compilation can use the MCR or a full install.

Setting the CMake arg `Matlab_ROOT_DIR` to the root of an installation will short-circuit the slower default matlab module search.

### testing matlab

Examples are shown using the Catch2 library https://github.com/catchorg/Catch2

### earlier version

Previously the examples were based on matlab engine, the little bit that was there can be found in [end-of-engine](https://github.com/jw3/example-matlab/releases/tag/end-of-engine)
