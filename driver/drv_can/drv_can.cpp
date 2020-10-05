#include "drv_can.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <inttypes.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <linux/can/raw.h>


int32_t drv_can_open(const char *dev) {

	int32_t sckt;
	if ((sckt = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
		perror("ERROR: CAN driver open (socket)");
		return -1;
	}

	struct ifreq ifr;
	strcpy(ifr.ifr_name, dev);
	ioctl(sckt, SIOCGIFINDEX, &ifr);

	struct sockaddr_can addr;
	memset(&addr, 0, sizeof(addr));
	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	if (bind(sckt, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
		perror("ERROR: CAN driver open (bind)");
		return -2;
	}

	return sckt;
}

int32_t drv_can_send(int32_t sckt, uint8_t id, uint8_t dlc, uint8_t data[]) {

	can_frame_t frame;
	frame.can_id = id;
	frame.can_dlc = dlc;

	memcpy(frame.data, data, sizeof(frame.data));

	return drv_can_send(sckt, frame);
}

int32_t drv_can_send(int32_t sckt, can_frame_t frame) {

	if (write(sckt, &frame, sizeof(can_frame_t)) != sizeof(can_frame_t)) {
		perror("ERROR: CAN driver send (write)");
		return -1;
	}

	return 0;
}

int32_t drv_can_read(int32_t sckt, can_frame_t *frame) {

	if (read(sckt, frame, sizeof(can_frame_t)) < 0) {
		perror("ERROR: CAN driver read");
		return -1;
	}

	return 0;
}

int32_t drv_can_set_filter(int32_t sckt, uint16_t id_list[], uint32_t id_list_len) {

	struct can_filter filter[id_list_len];

	for (uint32_t i=0; i<id_list_len; i++) {
		filter[i].can_id = id_list[i];
		filter[i].can_mask = CAN_SFF_MASK;
	}

	if (setsockopt(sckt, SOL_CAN_RAW, CAN_RAW_FILTER, &filter, sizeof(filter))) {
		perror("ERROR: CAN driver filter (setsockopt)");
		return -1;
	}

	return 0;
}

int32_t drv_can_close(int32_t sckt) {

	if (close(sckt) < 0) {
		perror("ERROR: CAN driver close");
		return -1;
	}

	return 0;
}
