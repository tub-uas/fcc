# Flight Control Computer (FCC)

![Build](https://github.com/tub-uas/fcc/workflows/build/badge.svg)

This repository contains the code running on the Flight Control Computer (FCC). It controlls and communicates the rest of the flight system via CAN (Controller Area Network).

## General
TODO

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


#### System
TODO
- TODO some sort of visual graph

## Hardware
We are only supporting RaspberryPis. Currently we are using a standard RaspberryPi 3 Model B. It is connected to a custom build shield (hat) that provides power and communication over the CAN Bus.

RaspberryPi with CAN interface shield:
![](docs/rpi_side.jpg)
![](docs/rpi_top.jpg)
RaspberryPi mounted in complete stack:
![](docs/stack.jpg)

For more information about the shield have a look at the [`mfs-hardware`](https://github.com/tub-uas/mfs-hardware) repository.

## Flightmodes
TODO

## Dynamics and Control
We are using the following body coordinate system:
![](docs/coordinate_system.jpg)

## Styleguide
TODO
