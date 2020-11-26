# FCC Scripts
This directory contains bash scripts that make life easier. They automate a lot of the setup, make and run process.

## General
Make sure that the scripts are executable (if you edit them, they become not executable anymore). In order to make all scripts in this directory executable, use `chmod +x *`.

`cmake.sh`, `make.sh`, `run.sh`, `status.sh`, `kill.sh` and `nice.sh` contain a list of module names that they operate on called `ACTIVE_MODULES`. Edit this list in order to control which modules each script should operate on.

## Description
Here you can find a short description of what each script does:
- `autostart.sh` gets executed on RaspberryPi startup. It is called from `/etc/rc.local` using `su pi -c '/home/pi/fcc/scripts/autostart.sh &'` automatically every time the RaspberryPi boots.
- `cmake.sh` removes all existing build directories, creates new build directories and runs `cmake` in each of them. Next step would then be to run `make` in all build directories (see `make.sh`).
- `enableHotspot.sh` enables a local WiFi hotspot on Ubuntu. This is way the RaspberryPi can connect to the WiFi hotspots computer and get accessed via SSH (makes life a lot easier than having to plug in the Ethernet cable every time).
- `getLogs.sh` copies all log files from the RaspberryPi `logs` directory into the local `logs` directory using Secure Copy (SCP). Make sure that the `logs` directory is located at `/home/pi/fcc/logs` on the RaspberryPi, otherwise edit the path in the script.
- `hotspot.sh` lists all currently via WiFi connected devices.
- `init.sh` initializes the RaspberryPi hardware. Gets run by `autostart.sh`.
- `kill.sh` stopps modules.
- `make.sh` builds modules using `make`.
- `nice.sh` increases priority of modules in scheduler system.
- `run.sh` starts modules.
- `status.sh` lists the status (`stopped` or `running`) of modules and contents of `logs` directory.
- `terminals.sh` opens a second terminal window in [terminator](https://wiki.ubuntuusers.de/Terminator/) and fills in `ssh` commands. Simply press `enter` in order to connect.

## Usage
1. Open a terminal on your local machine. Navigate into the `scripts` directory and ensure that all scripts are executable (see above).
2. Run `enableHotspot.sh` to turn on the local hotspot.
3. Run `hotspot.sh` repeatedly to check that RaspberryPi shows up in connected devices. This can take a while.
4. Connect via `ssh`:
	- Run `terminals.sh` to automatically open a second terminal and prepare `ssh` connection commands. When both terminals are open and have their connection commands prepared simply press `enter` in order to connect.
	- or simply connect via `ssh pi@raspberrypi.local`. The password is `avsoft`.
5. You will automatically be redirected into the `scripts` directory on the RaspberryPi when connecting via `ssh` (this is done by `cd fcc/scripts` in `/home/pi/.bashrc`).
6. If you are starting clean or have done big changes, run `cmake.sh`.
7. Then run `make.sh`. Depending on how much new code there is, this might take a while.
8. After compilation is done, you can use `run.sh` to start the modules.
9. Use `status.sh` to check whether all modules you wanted to start are actually running. You can also check whether a new logfile directory was created (the name of that directory is made up of the current date and time) and whether it is growing in size.
10. In order to stop execution of the modules run `kill.sh`. This will stop all modules (and close the current logfiles).
11. Before disconnecting power, shutdown the RaspberryPi using `sudo shutdown now`.
