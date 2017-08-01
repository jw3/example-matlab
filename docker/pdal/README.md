PDAL build
===

Use `run.sh` to execute a build in a container linked against a Matlab install.

- env `MATLAB_ROOT` will specify the root of the Matlab installation

#### mods

The mods directory contains scripts that modify the build or runtime environment in some way.

Execute a mod with `mod` and the name of a mod script in the [mods directory](docker/pdal/mods).

`#! docker run --rm -it jwiii/matlab-pdal-build mod dont-use-link-path`

Should result in a banner that indicates what has been applied
```
  *================= Mods =================*
    - set CMAKE_INSTALL_RPATH_USE_LINK_PATH to FALSE in cmake/rpath.cmake
  *========================================*
```

#### see
- https://hub.docker.com/r/pdal/dependencies/
- https://github.com/PDAL/PDAL/blob/master/cmake/examples/hobu-config.sh
