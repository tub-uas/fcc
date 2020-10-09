#!/bin/bash
set -e

declare -a ACTIVE_MODULES=("raiIn" "raiOut" "ahrs" "air" "psu" "ctrl" "sFusion" "log" "downlink" "watchdog")

MODULE_DIR=./../modules
BUILD_DIR=/build

BRANCH=$(git branch | grep \* | cut -d ' ' -f2)

echo "----- Running modules on branch $BRANCH ------"

for mod in "${ACTIVE_MODULES[@]}"
do
	echo "$MODULE_DIR/$mod$BUILD_DIR/$mod"
	      $MODULE_DIR/$mod$BUILD_DIR/$mod &
done

echo "----- `basename "$0"` done on branch $BRANCH ------"
