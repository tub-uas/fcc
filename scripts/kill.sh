#!/bin/bash


declare -a ACTIVE_MODULES=("raiIn" "raiOut" "ahrs" "air" "gps" "psu" "ctrl" "sFusion" "log" "downlink" "uplink" "watchdog")

MODULE_DIR=./../modules
BUILD_DIR=/build

BRANCH=$(git branch | grep \* | cut -d ' ' -f2)

echo "----- Killing modules on branch $BRANCH ------"

for mod in "${ACTIVE_MODULES[@]}"
do
	echo "pkill $mod"
	      pkill $mod
done

echo "----- `basename "$0"` done on branch $BRANCH ------"
