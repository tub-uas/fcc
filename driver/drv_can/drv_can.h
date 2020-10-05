#ifndef DRV_CAN
#define DRV_CAN

#include <inttypes.h>
#include <linux/can.h>
#include <linux/can/raw.h>

typedef struct can_frame can_frame_t;

int32_t drv_can_open(const char *dev);

int32_t drv_can_send(int32_t sckt, uint8_t id, uint8_t dlc, uint8_t data[]);

int32_t drv_can_send(int32_t sckt, can_frame_t frame);

int32_t drv_can_read(int32_t sckt, can_frame_t *frame);

int32_t drv_can_set_filter(int32_t sckt, uint16_t id_list[], uint32_t id_list_len);

int32_t drv_can_close(int32_t sckt);

#endif	// DRV_CAN
