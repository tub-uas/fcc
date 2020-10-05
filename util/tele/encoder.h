/**
 * @Author: Arnold Freitas
 * @Date:   2019-07-09
 * @Last modified by:   Arnold Freitas
 * @Last modified time: 2019-08-12
 */

#ifndef ENCODER_H
#define ENCODER_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <sys/time.h>
	#include <time.h>
	#include <termios.h>
	#include <fcntl.h>
	#include <unistd.h>
	#include <errno.h>
	#include <string.h>
	#include <math.h>

	// Globale Konstanten Deff
	#define CEST (+2);

	// Declaration of the variables

	// extern float32_t global_IAS;
	// extern float32_t global_GND_s;
	// extern float64_t global_Latitude;
	// extern float64_t global_Longitude;
	// extern float32_t global_Altitude_Baro;
	// extern float32_t global_Vspeed;
	// extern float32_t global_Pitch;
	// extern float32_t global_Roll;
	// extern float32_t global_Heading;
	// extern float64_t global_FlightTime;

	// Message Protocol
	typedef struct {
	uint16_t this_message_ID;
	float32_t this_IAS;
	float32_t this_GND_s;
	float64_t this_Latitude;
	float64_t this_Longitude;
	float32_t this_Altitude_Baro;
	float32_t this_Vspeed;
	float32_t this_Pitch;
	float32_t this_Roll;
	float32_t this_Heading;
	float64_t this_FlightTime;
	uint16_t this_CS_parity;
}message_t ;

	// Funktionsdeklaration

// void creat_random_global_values_runtime(void); // generate randome values for tests

const char *encoder_identify_usb(void);

int16_t encoder_open_device(const char *);

int16_t port_config(int16_t);

uint16_t Checksum(message_t);

void write_message(int16_t, message_t);

void telemetry_run(int16_t, message_t);

#endif // ENCODER_H
