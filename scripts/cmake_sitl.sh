#!/bin/bash
set -e

declare -a ACTIVE_MODULES=("ctrl" "sFusion" "log" "downlink" "watchdog")
declare -a ACTIVE_SITL_MODULES=("raiIn" "raiOut" "ahrs" "air" "gps" "psu")

MODULE_DIR=./../modules
BUILD_DIR=/build

BRANCH=$(git branch | grep \* | cut -d ' ' -f2)

echo "----- Cleaning modules on branch $BRANCH ------"

for mod in "${ACTIVE_MODULES[@]}"
do
	echo "rm -rf $MODULE_DIR/$mod$BUILD_DIR"
	      rm -rf $MODULE_DIR/$mod$BUILD_DIR
done

for mod in "${ACTIVE_SITL_MODULES[@]}"
do
	echo "rm -rf $MODULE_DIR/$mod$BUILD_DIR"
	      rm -rf $MODULE_DIR/$mod$BUILD_DIR
done

echo "----- Cmaking modules on branch $BRANCH ------"

for mod in "${ACTIVE_MODULES[@]}"
do
	echo "mkdir $MODULE_DIR/$mod$BUILD_DIR"
	      mkdir $MODULE_DIR/$mod$BUILD_DIR
	echo "cmake -S $MODULE_DIR/$mod -B $MODULE_DIR/$mod$BUILD_DIR"
	      cmake -S $MODULE_DIR/$mod -B $MODULE_DIR/$mod$BUILD_DIR
done

echo "----- Cmaking modules on branch $BRANCH ------"

IP=$1
for mod in "${ACTIVE_SITL_MODULES[@]}"
do
	echo "mkdir $MODULE_DIR/$mod$BUILD_DIR"
	      mkdir $MODULE_DIR/$mod$BUILD_DIR
	echo "cmake -S $MODULE_DIR/$mod -B $MODULE_DIR/$mod$BUILD_DIR -DSITL=1 -DIP=$IP"
	      cmake -S $MODULE_DIR/$mod -B $MODULE_DIR/$mod$BUILD_DIR -DSITL=1 -DIP="$IP"
done



echo "----- `basename "$0"` done on branch $BRANCH ------"
