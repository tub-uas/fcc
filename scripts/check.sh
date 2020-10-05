#!/bin/bash
set -e

declare -a ACTIVE_MODULES=("raiIn" "raiOut" "ahrs" "air" "gps" "psu" "ctrl" "sFusion" "log")

MODULE_DIR=./../modules
BUILD_DIR=/build

BRANCH=$(git branch | grep \* | cut -d ' ' -f2)

echo "----- Checking what modules are running on branch $BRANCH ------"

for mod in "${ACTIVE_MODULES[@]}"
do
	if pgrep -x "$mod" > /dev/null
	then
		printf "%-10s %s\n" $mod "running"
	else
		printf "%-10s %s\n" $mod "stopped"
		fi
done

echo "----- `basename "$0"` done on branch $BRANCH ------"
