#!/bin/bash

NCPU=`sysctl -n hw.ncpu`
echo "Will build with 'make -j$NCPU' ... please edit this script if incorrect."

set -e
set -x

rm -rf cmake-build
mkdir $_
cd $_
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_OSX_ARCHITECTURES=i386 -DUSE_I386_NASM_ASM=TRUE -DUSE_SYSTEM_SDL2=FALSE .. $1
make -j$NCPU

