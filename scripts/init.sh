#!/bin/bash
set -e

BRANCH=$(git branch | grep \* | cut -d ' ' -f2)

echo "----- Setting CPU mode on branch $BRANCH ------"

echo -n "From mode: "
cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
sudo sh -c "echo performance > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor"
echo -n "to mode:   "
cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor

echo "----- `basename "$0"` done on branch $BRANCH ------"
