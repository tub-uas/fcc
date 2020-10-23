#!/bin/bash
set -e

declare -a ACTIVE_MODULES=("raiIn" "ahrs" "air" "gps" "psu")

BRANCH=$(git branch | grep \* | cut -d ' ' -f2)

echo "----- Running modules on branch $BRANCH ------"

for mod in "${ACTIVE_MODULES[@]}"
do
	PID=$(pgrep $mod)
	echo "sudo renice -n -20 -p $PID"
	      sudo renice -n -20 -p $PID
done

echo "----- `basename "$0"` done on branch $BRANCH ------"

# ip -d -s link show can0
# sysbench --test=cpu --cpu-max-prime=1000000 --num-threads=8 run
