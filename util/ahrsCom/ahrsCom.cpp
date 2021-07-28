#include "ahrsCom.h"

#include <iostream>
#include <cstring>

#include "../../driver/drv_can/drv_can.h"

AhrsCom::AhrsCom() {

}

AhrsCom::~AhrsCom() {
	drv_can_close(can_sckt);
}

bool AhrsCom::init() {

	if ((can_sckt = drv_can_open("can0")) < 0) {
		std::cout << "AhrsCom can socket error " << std::endl;
		return false;
	}

	if (drv_can_set_filter(can_sckt, &in_ids[0], CAN_META_AHRS_MSG_NUM) < 0) {
		std::cout << "AhrsCom can filter error " << std::endl;
		return false;
	}

	return true;
}

bool AhrsCom::receive() {

	for (int i=0; i<CAN_META_AHRS_MSG_NUM; i++) {

		can_frame_t frame;
		drv_can_read(can_sckt, &frame);

		// if (frame.can_id != in_ids[i]) {
			// std::cout << "AhrsCom decode error, can id should be "
			        //   << std::hex << in_ids[i] << std::dec << " but is "
			        //   << std::hex << frame.can_id << std::dec << std::endl;
			// return false;
		// }
		// else {
		// 	std::cout << "AhrsCom decode succe, can ids are      "
		// 	          << std::hex << in_ids[i] << std::dec << " but is "
		// 	          << std::hex << frame.can_id << std::dec << std::endl;
		// }

		switch (frame.can_id) {

			case CAN_ID_AHRS_DATA0:
				memcpy(&time, &frame.data[0], sizeof(float));
				memcpy(&acc[0], &frame.data[4], sizeof(float));
				break;

			case CAN_ID_AHRS_DATA1:
				memcpy(&acc[1], &frame.data[0], sizeof(float));
				memcpy(&acc[2], &frame.data[4], sizeof(float));
				break;

			case CAN_ID_AHRS_DATA2:
				memcpy(&gyr[0], &frame.data[0], sizeof(float));
				memcpy(&gyr[1], &frame.data[4], sizeof(float));
				break;

			case CAN_ID_AHRS_DATA3:
				memcpy(&gyr[2], &frame.data[0], sizeof(float));
				memcpy(&mag[0], &frame.data[4], sizeof(float));
				break;

			case CAN_ID_AHRS_DATA4:
				memcpy(&mag[1], &frame.data[0], sizeof(float));
				memcpy(&mag[2], &frame.data[4], sizeof(float));
				break;

			case CAN_ID_AHRS_DATA5:
				memcpy(&att[0], &frame.data[0], sizeof(float));
				memcpy(&att[1], &frame.data[4], sizeof(float));
				break;

			case CAN_ID_AHRS_DATA6:
				memcpy(&att[2], &frame.data[0], sizeof(float));
				memcpy(&temp, &frame.data[4], sizeof(float));
				break;

			case CAN_ID_AHRS_DATA7:
				memcpy(&press, &frame.data[0], sizeof(float));
				break;

			default:
				std::cout << "AhrsCom decode error, unkown ID "
				          << std::hex << frame.can_id << std::dec << std::endl;
				break;
		}

	}

	return true;
}

bool AhrsCom::print() {

	std::cout << "--- " << time << " ---" << std::endl;

	for (int i=0; i<3; i++) {
		std::cout << "acc[" << i << "] " << acc[i] << std::endl;
	}

	for (int i=0; i<3; i++) {
		std::cout << "gyr[" << i << "] " << gyr[i] << std::endl;
	}

	for (int i=0; i<3; i++) {
		std::cout << "mag[" << i << "] " << mag[i] << std::endl;
	}

	for (int i=0; i<3; i++) {
		std::cout << "att[" << i << "] " << att[i] << std::endl;
	}

	std::cout << "temp  " << temp << std::endl;
	std::cout << "press " << press << std::endl;

	return true;
}
