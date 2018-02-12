#!/usr/bin/env bash

readonly projdir=$(basename "$PWD")
readonly basedir="$PWD"/..
readonly matlabroot="${MATLAB_ROOT:-/usr/local/MATLAB}"

build() {
    local entdir="$PWD"
    cd "$basedir"

    if [[ "$1" != "quick" ]]; then
        rm -rf build
        mkdir build
    fi

    cd build
    cmake -DMatlab_ROOT_DIR="$matlabroot" ..
    make -j6

    if [ $? == 0 ]; then echo "!!!!!!!!!!!! build success !!!!!!!!!!!!"
    else echo "xXxXxXxXxXxXx --- build failed--- xXxXxXxXxXxXx"; exit 1
    fi

    cd "$entdir"

    if [[ "$1" == "example" ]]; then example; fi
}

driver() {
    build "$1"

    cd $basedir/build

    export LD_LIBRARY_PATH="$PWD/mcc/with-mex:/lib/:/usr/local/lib:/lib/x86_64-linux-gnu:/usr/lib:/usr/lib/x86_64-linux-gnu:$matlabroot/runtime/glnxa64:$matlabroot/bin/glnxa64"
    echo "$LD_LIBRARY_PATH"

    ./mcc/mcc-example-driver
}

if [[ ! -z "$@" ]]; then "$@"; else driver; fi
