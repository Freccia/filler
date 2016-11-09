#!/bin/bash

rm filler.log filler.trace
make -C .. re
mv ../lfabbro.filler players

./filler_vm -f maps/$1 -p1 players/$2 -p2 players/$3 | 
sed -E "s/[O|o]/$(tput setaf 1)&$(tput sgr0)/g" | 
sed -E "s/[X|x]/$(tput setaf 3)&$(tput sgr0)/g"
