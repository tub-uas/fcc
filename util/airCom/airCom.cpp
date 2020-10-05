#include "airCom.h"

#include <iostream>
#include <cstring>

#include "../../driver/drv_can/drv_can.h"

AirCom::AirCom() {

}

AirCom::~AirCom() {
	drv_can_close(can_sckt);
}

bool AirCom::init() {

	if ((can_sckt = drv_can_open("can0")) < 0) {
		std::cout << "AirCom can socket error " << std::endl;
		return false;
	}

	if (drv_can_set_filter(can_sckt, &in_ids[0], CAN_META_AHRS_MSG_NUM) < 0) {
		std::cout << "AirCom can filter error " << std::endl;
		return false;
	}

	return true;
}

bool AirCom::receive() {

	for (int i=0; i<CAN_META_AIR_MSG_NUM; i++) {

		can_frame_t frame;
		drv_can_read(can_sckt, &frame);

		if (frame.can_id != in_ids[i]) {
			std::cout << "AirCom decode error, can id should be " << frame.can_id
			          << " but is " << in_ids[i] << std::endl;
			return false;
		}

		switch (frame.can_id) {

			case CAN_ID_AIR_DATA0:
				memcpy(&dynamicPress, &frame.data[0], sizeof(float));
				memcpy(&velocity, &frame.data[4], sizeof(float));
				break;

			case CAN_ID_AIR_DATA1:
				memcpy(&density, &frame.data[0], sizeof(float));
				memcpy(&baroPress, &frame.data[4], sizeof(float));
				break;

			case CAN_ID_AIR_DATA2:
				memcpy(&temp, &frame.data[0], sizeof(float));
				memcpy(&time, &frame.data[4], sizeof(float));
				break;

			default:
				std::cout << "AirCom decode error, unkown ID" << std::endl;
				break;
		}

	}

	return true;
}

bool AirCom::print() {

	std::cout << "--- " << time << " ---" << std::endl;

	std::cout << "dynamicPress " << dynamicPress << std::endl;
	std::cout << "velocity     " << velocity << std::endl;
	std::cout << "density      " << density << std::endl;
	std::cout << "baroPress    " << baroPress << std::endl;
	std::cout << "temp         " << temp << std::endl;

	return true;
}
