#!/bin/bash

readonly the_services=(\
/matlab/bin/glnxa64/libcrypto.so.1 \
/matlab/bin/glnxa64/libcrypto.so.1.0.0 \
/matlab/bin/glnxa64/libcurl.so.4 \
/matlab/bin/glnxa64/libcurl.so.4.3.0 \
/matlab/bin/glnxa64/libssl.so.1 \
/matlab/bin/glnxa64/libssl.so.1.0.0 \
/matlab/bin/glnxa64/libtiff.so.5 \
/matlab/bin/glnxa64/libtiff.so.5.0.5 \
/matlab/bin/glnxa64/libxerces-c.so \
/matlab/bin/glnxa64/libxerces-c-3.1.so \
/matlab/bin/glnxa64/libxml2.so.2 \
/matlab/bin/glnxa64/libxml2.so.2.9.2)

enable() {
  for f in "${the_services[@]}"; do mv "$f" "$f.hacked"; done;
}

disable() {
  for f in "${the_services[@]}"; do mv "$f.hacked" "$f"; done;
}


"$@"
