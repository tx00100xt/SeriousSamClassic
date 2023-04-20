#!/bin/bash

NCPU=`cat /proc/cpuinfo |grep vendor_id |wc -l`

if [[ $NCPU -eq 0 ]]
then
  let NCPU='4'
else
  let NCPU=$NCPU
fi

echo "Will build with 'make -j$NCPU' ... please edit this script if incorrect."

set -e
set -x

rm -rf cmake-build

mkdir $_
cd $_
cp -vfr ../Entities/PlayerWeapons_old.es ../Entities/PlayerWeapons.es

#cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_FLAGS=-m32 -DCMAKE_CXX_FLAGS=-m32 ..
#ninja

# This is the eventual path for amd64.
#cmake -DCMAKE_BUILD_TYPE=Debug ..

# Right now we force x86, though...
# for old x86 distros use:
# cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_FLAGS=-mmmx -DCMAKE_CXX_FLAGS=-mmmx -DUSE_I386_NASM_ASM=TRUE .. $1 $2
if [ -n "$2" ]
then
cmake -DCMAKE_BUILD_TYPE=Release -DUSE_I386_NASM_ASM=FALSE .. $1 $2
else
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_FLAGS=-m32 -DCMAKE_CXX_FLAGS=-m32 -DUSE_I386_NASM_ASM=TRUE .. $1
fi

echo "ECC first"
make ecc
echo "Then the rest..."
make -j$NCPU

cp -vfr Debug/*.so ../../Bin
cp -vfr ecc ../../Bin
cp -vfr DedicatedServer ../../Bin
cp -vfr SeriousSam ../../Bin
cp -vfr MakeFONT ../../Bin
