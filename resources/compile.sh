#!/bin/bash
rm filler.log filler.trace
make -C .. re
mv ../lfabbro.filler players
