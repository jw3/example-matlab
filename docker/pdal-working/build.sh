#!/bin/bash

readonly the_services=(\
/matlab/bin/glnxa64/libcrypto.so.1 \
/matlab/bin/glnxa64/libcrypto.so.1.0.0 \
/matlab/bin/glnxa64/libssl.so.1 \
/matlab/bin/glnxa64/libssl.so.1.0.0 \
)

for f in "${the_services[@]}"; do mv "$f" "$f.hacked"; done;

cmake \
  -DBUILD_PLUGIN_CPD=OFF \
  -DBUILD_PLUGIN_MBIO=OFF \
  -DBUILD_PLUGIN_GREYHOUND=OFF \
  -DBUILD_PLUGIN_HEXBIN=OFF \
  -DBUILD_PLUGIN_ICEBRIDGE=OFF \
  -DBUILD_PLUGIN_MRSID=OFF \
  -DBUILD_PLUGIN_NITF=OFF \
  -DBUILD_PLUGIN_OCI=OFF \
  -DBUILD_PLUGIN_PCL=OFF \
  -DBUILD_PLUGIN_PGPOINTCLOUD=OFF \
  -DBUILD_PLUGIN_SQLITE=OFF \
  -DBUILD_PLUGIN_RIVLIB=OFF \
  -DBUILD_PLUGIN_PYTHON=OFF \
  -DCMAKE_INSTALL_PREFIX=/usr \
  -DENABLE_CTEST=OFF \
  -DWITH_LAZPERF=OFF \
  -DWITH_LASZIP=OFF \
  -DWITH_TESTS=ON \
  -DWITH_PDAL_JNI=OFF \
  -DCMAKE_BUILD_TYPE=Release \
  -DBUILD_PLUGIN_MATLAB=ON \
  -DMATLAB_FIND_DEBUG=ON \
  .. \
&& make -j 5 \
&& make install
