#!/bin/sh
mkdir -p libsdl ;
cd libsdl ;
../SDL2/configure --prefix=`pwd`  ;
make ;
make install
