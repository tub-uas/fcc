#!/bin/bash
set -e

# This script is called from `/etc/rc.local`
# using `su pi -c '/home/pi/fcc/scripts/autostart.sh &'`

sleep 5
cd /home/pi/fcc/scripts
./init.sh
# ./make.sh
# ./run.sh
