#!/bin/bash
set -e

BRANCH=$(git branch | grep \* | cut -d ' ' -f2)

# Use 'down' to disable the hotspot

echo "----- Enable Wifi hotspot on branch $BRANCH ------"
echo "nmcli connection up Hotspot"
      nmcli connection up Hotspot

echo "----- `basename "$0"` done on branch $BRANCH ------"
