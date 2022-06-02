#!/bin/bash

NCPU=`cat /proc/cpuinfo |grep vendor_id |wc -l`
let NCPU=$NCPU
echo "Will build with 'make -j$NCPU' ... please edit this script if incorrect."

set -e
set -x

rm -rf cmake-build

mkdir $_
cd $_
cp -vfr ../Entities/PlayerWeaponsHD.es ../Entities/PlayerWeapons.es

#cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_FLAGS=-m32 -DCMAKE_CXX_FLAGS=-m32 ..
#ninja

# This is the eventual path for amd64.
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo .. $1 $2

# Right now we force x86, though...
#cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_FLAGS=-m32 -DCMAKE_CXX_FLAGS=-m32 ..
echo "ECC first"
make ecc
echo "Then the rest..."
make -j$NCPU

cp -vfr Debug/libEntities.so ../../Mods/XPLUS/Bin
cp -vfr Debug/libGame.so ../../Mods/XPLUS/Bin
