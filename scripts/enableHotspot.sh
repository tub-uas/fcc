#!/bin/bash
set -e

# Caution: Only tested on Dell XPS 13 running Ubuntu 18.04

BRANCH=$(git branch | grep \* | cut -d ' ' -f2)

# Use 'up' to enable the hotspot
# Use 'down' to disable the hotspot

echo "----- Enable Wifi hotspot on branch $BRANCH ------"
echo "nmcli connection up Hotspot"
      nmcli connection up Hotspot

echo "----- `basename "$0"` done on branch $BRANCH ------"
