#!/bin/bash
set -e

BRANCH=$(git branch | grep \* | cut -d ' ' -f2)

echo "----- Opening new terminal on branch $BRANCH ------"

xdotool type "sshpass -p \"avsoft\" ssh -o StrictHostKeyChecking=no pi@raspberrypi.local"
xdotool key ctrl+shift+e
xdotool type "sshpass -p \"avsoft\" ssh -o StrictHostKeyChecking=no pi@raspberrypi.local"

echo "----- `basename "$0"` done on branch $BRANCH ------"
