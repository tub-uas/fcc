#ifndef DRV_LED
#define DRV_LED

#include <inttypes.h>

int32_t drv_led_init();

int32_t drv_led_set_green(uint8_t on);

int32_t drv_led_green_on();

int32_t drv_led_green_off();

int32_t drv_led_set_yellow(uint8_t on);

int32_t drv_led_yellow_on();

int32_t drv_led_yellow_off();

#endif	// DRV_LED
