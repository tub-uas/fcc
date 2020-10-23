#!/bin/bash
set -e

BRANCH=$(git branch | grep \* | cut -d ' ' -f2)

echo "----- Checking Wifi devices on branch $BRANCH ------"

printf  "%-20s %-30s %-20s\n" "--IP address--" "--lease name--" "--MAC address--"

leasefile=/var/lib/misc/dnsmasq.leases

for interface in `iw dev | grep Interface | cut -f 2 -s -d" "`
do
	# for each interface, get mac addresses of connected stations/clients
	maclist=`iw dev $interface station dump | grep Station | cut -f 2 -s -d" "`
	# for each mac address in that list...
	for mac in $maclist
	do
		# If a DHCP lease has been given out by dnsmasq, save it.
		ip="UNKN"
		host=""
		ip=`cat $leasefile | cut -f 2,3,4 -s -d" " | grep $mac | cut -f 2 -s -d" "`
		host=`cat $leasefile | cut -f 2,3,4 -s -d" " | grep $mac | cut -f 3 -s -d" "`
		# ... show the mac address:
		printf "  %-20s %-30s %-20s\n" "$ip" "$host" "$mac"
	done
done

echo "----- `basename "$0"` done on branch $BRANCH ------"
