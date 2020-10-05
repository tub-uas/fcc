#include "raiCom.h"

#include <iostream>
#include <cstring>

#include "../../driver/drv_can/drv_can.h"

RaiCom::RaiCom() {

}

RaiCom::~RaiCom() {
	drv_can_close(can_sckt);
}

bool RaiCom::init() {

	if ((can_sckt = drv_can_open("can0")) < 0) {
		std::cout << "RaiCom can socket error " << std::endl;
		return false;
	}

	if (drv_can_set_filter(can_sckt, &in_ids[0], CAN_META_RAI_MSG_NUM) < 0) {
		std::cout << "RaiCom can filter error " << std::endl;
		return false;
	}

	return true;
}

bool RaiCom::receive() {

	for (int i=0; i<CAN_META_RAI_MSG_NUM; i++) {

		can_frame_t frame;
		drv_can_read(can_sckt, &frame);

		if (frame.can_id != in_ids[i]) {
			std::cout << "RaiCom decode error, can id should be " << frame.can_id
			          << " but is " << in_ids[i] << std::endl;
			return false;
		}

		if (i == (CAN_META_RAI_MSG_NUM-1)) {
			memcpy(&time, &frame.data[0], sizeof(float));
			break;
		}

		for (int j=0; j<CAN_META_RAI_CHNL_PER_MSG; j++) {

			uint16_t pwm = frame.data[2*j+1] << 8 | frame.data[2*j];
			int idx = CAN_META_RAI_CHNL_PER_MSG*(frame.can_id-CAN_ID_RAI_DATA0)+j;

			if (pwm > 2200 || pwm < 800) {
				std::cout << "RaiCom receive error, pwm out of bounds " << pwm
				          << " at channel " << idx << std::endl;
				return false;
			}

			channel[idx] = pwm;
		}
	}

	return true;
}


bool RaiCom::send(std::array<uint16_t, CAN_META_RAI_CHNL_NUM> channel, float time) {

	for (int i=0; i<CAN_META_RAI_MSG_NUM; i++) {

		can_frame_t frame;
		frame.can_id = out_ids[i];
		frame.can_dlc = 8;

		if (i == (CAN_META_RAI_MSG_NUM-1)) {
			frame.can_dlc = 4;
			memcpy(&frame.data[0], &time, sizeof(float));
			drv_can_send(can_sckt, frame);
			break;
		}

		for (int j=0; j<CAN_META_RAI_CHNL_PER_MSG; j++) {

			uint16_t pwm = channel[CAN_META_RAI_CHNL_PER_MSG*i+j];

			if (pwm > 2200 || pwm < 800) {
				std::cout << "RaiCom send error, pwm out of bounds " << pwm
				          << " at channel " << CAN_META_RAI_CHNL_PER_MSG*i+j << std::endl;
				return false;
			}

			memcpy(&frame.data[2*j], &pwm, sizeof(uint16_t));
		}

		drv_can_send(can_sckt, frame);
	}

	return true;
}

bool RaiCom::send() {

	for (int i=0; i<CAN_META_RAI_MSG_NUM; i++) {

		can_frame_t frame;
		frame.can_id = out_ids[i];
		frame.can_dlc = 8;

		if (i == (CAN_META_RAI_MSG_NUM-1)) {
			frame.can_dlc = 4;
			memcpy(&frame.data[0], &time, sizeof(float));
			drv_can_send(can_sckt, frame);
			break;
		}

		for (int j=0; j<CAN_META_RAI_CHNL_PER_MSG; j++) {

			uint16_t pwm = channel[CAN_META_RAI_CHNL_PER_MSG*i+j];

			if (pwm > 2200 || pwm < 800) {
				std::cout << "RaiCom send error, pwm out of bounds " << pwm
				          << " at channel " << CAN_META_RAI_CHNL_PER_MSG*i+j << std::endl;
				return false;
			}

			memcpy(&frame.data[2*j], &pwm, sizeof(uint16_t));
		}

		drv_can_send(can_sckt, frame);
	}

	return true;
}

bool RaiCom::print() {
	return print(channel, time);
}

bool RaiCom::print(std::array<uint16_t, CAN_META_RAI_CHNL_NUM> channel, float time) {

	std::cout << "--- " << time << " ---" << std::endl;

	for (int i=0; i<CAN_META_RAI_CHNL_NUM; i++) {
		std::cout << i << " " << channel[i] << std::endl;
	}

	return true;
}
