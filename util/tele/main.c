/**
 * @Author: Arnold Freitas
 * @Date:   2019-07-09
 * @Last modified by:   Arnold Freitas
 * @Last modified time: 2019-08-12
 */

 // Compile wiht: gcc main.c -o encoder_run
 // execute: sudo ./encoder_run

#include "encoder.h"

int main(void) {

	const char *device; // variable for device path
	int16_t fd; // Variable for Device

	device = encoder_identify_usb(); // identify usb path
	device = "/dev/ttyUSB1"; // for runtime tests
	fd =encoder_open_device(device); // open device
	port_config(fd); // Configurate PORT

	telemetry_run(fd); // send messages


	close(fd); // close device
	return 0;
}
