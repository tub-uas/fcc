#include "drv_led.h"

#include <stdlib.h>
#include <stdio.h>

#ifdef __arm__
#include <wiringPi.h>
#endif

#define GREEN_LED  22
#define YELLOW_LED 23

int32_t drv_led_init() {
#ifdef __arm__
	wiringPiSetup();
	pinMode(GREEN_LED, OUTPUT);
	pinMode(YELLOW_LED, OUTPUT);
#endif
	return 0;
}

int32_t drv_led_set_green(uint8_t on) {
	if (on) {
		return drv_led_green_on();
	} else {
		return drv_led_green_off();
	}
}

int32_t drv_led_green_on() {
#ifdef __arm__
	digitalWrite(GREEN_LED, HIGH);
#endif
	return 0;
}

int32_t drv_led_green_off() {
#ifdef __arm__
	digitalWrite(GREEN_LED, LOW);
#endif
	return 0;
}

int32_t drv_led_set_yellow(uint8_t on) {
	if (on) {
		return drv_led_yellow_on();
	} else {
		return drv_led_yellow_off();
	}
}

int32_t drv_led_yellow_on() {
#ifdef __arm__
	digitalWrite(YELLOW_LED, HIGH);
#endif
	return 0;
}

int32_t drv_led_yellow_off() {
#ifdef __arm__
	digitalWrite(YELLOW_LED, LOW);
#endif
	return 0;
}

// // g++ drv_led.c -lwiringPi
//
// int main(void) {
//
// 	drv_led_init();
//
// 	while (1) {
// 		drv_led_set_yellow(0);
// 		drv_led_set_green(1);
// 		delay(500);
// 		drv_led_set_yellow(1);
// 		drv_led_set_green(0);
// 		delay(500);
// 	}
//
// 	return 0;
// }
