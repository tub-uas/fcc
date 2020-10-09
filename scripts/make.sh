#!/bin/bash
set -e

declare -a ACTIVE_MODULES=("raiIn" "raiOut" "ahrs" "air" "psu" "ctrl" "sFusion" "downlink" "watchdog")

MODULE_DIR=./../modules
BUILD_DIR=/build

BRANCH=$(git branch | grep \* | cut -d ' ' -f2)

echo "----- Compiling modules on branch $BRANCH ------"

for mod in "${ACTIVE_MODULES[@]}"
do
	echo "make -C $MODULE_DIR/$mod$BUILD_DIR -j4"
	      make -C $MODULE_DIR/$mod$BUILD_DIR -j4
done

echo "----- `basename "$0"` done on branch $BRANCH ------"
