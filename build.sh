#! /bin/bash
###########################################################################################
###########################################################################################
# Created by CryptoLions, 2019
#
# Web: https://CryptoLions.io
# Git: https://github.com/CryptoLions/PeerPingData
#
###########################################################################################
###########################################################################################


rm -r ./build/
printf "\t=========== Building PeerPingData Contract [by CryptoLions.io] ===========\n\n"

RED='\033[0;31m'
NC='\033[0m'

CORES=`getconf _NPROCESSORS_ONLN`
mkdir -p build
pushd build &> /dev/null
cmake ../
#exit
make -j${CORES}
popd &> /dev/null

