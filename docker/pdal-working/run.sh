#!/bin/bash

readonly matlab="${MATLAB_ROOT:-/usr/local/MATLAB}"

docker run --rm -it --add-host="$HOSTNAME:172.17.0.1" -v "$matlab":/matlab "$@"
