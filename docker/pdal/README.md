PDAL
===

Out of the box, linking issues with Matlab


#### see
- https://hub.docker.com/r/pdal/dependencies/
- https://github.com/PDAL/PDAL/blob/master/cmake/examples/hobu-config.sh


#### Attempt 1

Execution with either 

- `bin/pdal_filters_matlab_test`
- or the same with env `LD_PRELOAD=/lib/x86_64-linux-gnu/libcrypto.so.1.0.0:/lib/x86_64-linux-gnu/libssl.so.1.0.0`
- then add xerces to `LD_PRELOAD` `$LD_PRELOAD:/usr/lib/x86_64-linux-gnu/libxerces-c-3.1.so`

```
root@439a042719c4:/PDAL/build# bin/pdal_filters_matlab_test 
[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from MatlabFilterTest
[ RUN      ] MatlabFilterTest.simple_fetch
/matlab/bin/glnxa64/MATLAB: symbol lookup error: /matlab/bin/glnxa64/libmwopcmodel.so: undefined symbol: _ZN11xercesc_3_111InputSource11setEncodingEPKDs
unknown file: Failure
C++ exception with description "unable to initialize Matlab!" thrown in the test body.
[  FAILED  ] MatlabFilterTest.simple_fetch (564 ms)
[ RUN      ] MatlabFilterTest.logical
(matlab.log filters.matlab Debug) filters.matlab source=[31 bytes], 
 processing 1065 points.
```

#### Attempt 2
