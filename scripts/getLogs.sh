#!/bin/bash

BRANCH=$(git branch | grep \* | cut -d ' ' -f2)

echo "----- Checking Wifi devices on branch $BRANCH ------"

# dt=$(date '+%Y-%m-%d-%H-%M-%S');
# echo "----- Current date $dt -----"
#
# mkdir ../old-logs
# mv ../logs ../old-logs/logs-$dt

mkdir -p ../logs
scp -r pi@raspberrypi.local:/home/pi/fcc/logs/* ../logs/

echo "----- `basename "$0"` done on branch $BRANCH ------"
