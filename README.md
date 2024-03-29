# Flight Control Computer (FCC)

![Build](https://github.com/tub-uas/fcc/workflows/build/badge.svg)
![Tests](https://github.com/tub-uas/fcc/workflows/tests/badge.svg)

This repository contains the code running on the Flight Control Computer (FCC). It controls and communicates with the rest of the flight system via CAN (Controller Area Network).

## General
Use the readme and scripts in the `scripts/` directory to compile, run and manage the code. You might need to install some dependencies, such as `boost` (a C++ library) and `wiringpi`.

*Boost installation*
```
$ sudo apt-get install libboost-all-dev
```

*Wiring Pi installation*
```
$ wget https://project-downloads.drogon.net/wiringpi-latest.deb
$ sudo dpkg -i wiringpi-latest.deb
```

## Architecture

#### Directories
General overview of sub-directories. For more information consult `README.md` file in each sub-directory.
- `.github` contains GitHub workflow scripts (`.yml`).  
- `depend` contains all dependencies that are needed in order to build and run the code.
- `docs` contains documentation related files.
- `driver` contains hardware drivers used by `util` and `modules`.
- `logs` contains logfiles.
- `modules` contains the software modules that communicate with each other using Fast-DDS.
- `scripts` contains scripts for fast and efficient system management.
- `tests` contains unit and integration tests.
- `util` contains utility functions used by `driver` and `modules`.


#### Layout
TODO
- TODO some sort of visual graph

## Operating System

Start by setting up a "normal" RaspberryPi system. Then, follow the steps below:

- The RaspberryPi is running a Linux kernel with Rreempt-RT. Please follow [this](https://lemariva.com/blog/2019/09/raspberry-pi-4b-preempt-rt-kernel-419y-performance-test) tutorial in order to compile und upload the kernel to the RaspberryPi.

- In order to install Fast-RTPS follow [this](https://github.com/eProsima/Fast-DDS#manual-installation). Ensure that you have all [dependencies](https://fast-dds.docs.eprosima.com/en/latest/installation/sources/sources_linux.html) installed.

- For Mavlink have a look at [this](https://mavlink.io/en/getting_started/installation.html) tutorial.

- To install the CAN driver and CAN utils use this tutorial [here](https://www.beyondlogic.org/adding-can-controller-area-network-to-the-raspberry-pi/). But put these two lines

```
# Enable can (dtparam=spi=on must be set)
dtoverlay=mcp2515-can0,oscillator=16000000,interrupt=25,spimaxfrequency=2000000
# spimaxfrequency is optional to reduce or increase spi speed if errors occur on bus lane
```
into your `/boot/config.txt` and these
```
auto can0  
iface can0 can static  
	bitrate 500000  
```
into your `/etc/network/interfaces`.

- In order to get rid the locale errors, put `export LC_ALL=C` at the bottom of the `.bashrc` in the home directory and reboot.

## Hardware
We are currently using a RaspberryPi 3 (and 4) Model B. It is connected to a custom build shield (hat) that provides power and communication over the CAN bus.

RaspberryPi with CAN interface shield:
![](docs/rpi_side.jpg)
![](docs/rpi_top.jpg)
RaspberryPi mounted in complete stack:
![](docs/stack.jpg)

For more information about the shield and the rest of the custom hardware, have a look at the [`mfs-hardware`](https://github.com/tub-uas/mfs-hardware) repository.

## Operation
We are currently supporting 3x 3 Flightmodes `Mode`. Flightfunction `Func` selects which 3 Flightmodes are active. So on total we could theoretically support 9 different actual modes.

The 3 possible states `Mode` can be in are `MANUAL` `AUTNOMOUS` and `EXPERIMENTAL`. The 3 possible states `Func` are divided in `FCT_0` `FCT_1` and `FCT_2`. The `AUTONOMOUS` mode is build on the `MANUAL` mode. This means, if `AUTONOMOUS` mode is active, all `MANUAL` functions are active as well. `EXPERIMENTAL` mode and functions are free to use and not determined to a specific behaviour yet.


| Flightmode / Flightfunction | FCT_0            | FCT_1                           | FCT_2                             |
|:---------------------------:|:--------------:|:-----------------------------:|:-------------------------------:|
| MANUAL                       | Manual control | Attitude control        | Height, velocity and course control |
| AUTONOMOUS                       | Mission | Tracker             | Advanced  |
| EXPERIMENTAL                       | TBA | TBA | TBA     |

In addition to above presented modes / functions the pilot can decide whether the control output from the RaspberryPi should actually be used as control input to the aircraft or whether the aircraft should directly be controlled (without going through the RaspberryPi) from pilot commands. This is in addition to the "Manual control" option as seen in the table above where the signals are send through the RaspberryPi but not being modified. This is controlled via software running on the RAI board. We will call this pilot-overwrite.


## Dynamics and Control
We are using the following body coordinate system:
![](docs/coordinate_system.jpg)

The `default` orientation coordinate system of the stack is the following:
![](docs/stack_coordinates.jpg)

Because the stack is turned onto its left side inside the Hype aircraft, the `hype` coordinate system is slightly different. While `x` stays the same `y` becomes `z` and `z` becomes `-y`.


## Styleguide

In general, follow the [Google C++](https://google.github.io/styleguide/cppguide.html) and the [PEP8 Python](https://www.python.org/dev/peps/pep-0008/) style guides. Where deemed sensible and / or necessary, diverge from these guides.
