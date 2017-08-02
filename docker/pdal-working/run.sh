#!/bin/bash

readonly image="${1:-jwiii/example-matlab}"
readonly matlab="${MATLAB_ROOT:-/usr/local/MATLAB}"


docker run --rm -it -v "$matlab":/matlab:ro "$image"
