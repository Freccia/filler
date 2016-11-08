#!/bin/sh
cat filler.log |
sed -E "s/[O|o]/$(tput setaf 1)&$(tput sgr0)/g" |
sed -E "s/[X|x]/$(tput setaf 3)&$(tput sgr0)/g"
