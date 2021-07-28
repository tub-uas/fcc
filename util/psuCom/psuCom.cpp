#include "psuCom.h"

#include <iostream>
#include <cstring>

#include "../../driver/drv_can/drv_can.h"

PsuCom::PsuCom() {

}

PsuCom::~PsuCom() {
	drv_can_close(can_sckt);
}

bool PsuCom::init() {

	if ((can_sckt = drv_can_open("can0")) < 0) {
		std::cout << "PsuCom can socket error " << std::endl;
		return false;
	}

	if (drv_can_set_filter(can_sckt, &in_ids[0], CAN_META_PSU_MSG_NUM) < 0) {
		std::cout << "PsuCom can filter error " << std::endl;
		return false;
	}

	return true;
}

bool PsuCom::receive() {

	for (int i=0; i<CAN_META_PSU_MSG_NUM; i++) {

		can_frame_t frame;
		drv_can_read(can_sckt, &frame);

		// if (frame.can_id != in_ids[i]) {
			// std::cout << "PsuCom decode error, can id should be "
			        //   << std::hex << in_ids[i] << std::dec << " but is "
			        //   << std::hex << frame.can_id << std::dec << std::endl;
			// return false;
		// }

		switch (frame.can_id) {

			case CAN_ID_PSU_DATA0:
				memcpy(&mainVolt, &frame.data[0], sizeof(float));
				memcpy(&mainCurr, &frame.data[4], sizeof(float));
				break;

			case CAN_ID_PSU_DATA1:
				memcpy(&mainPow, &frame.data[0], sizeof(float));
				memcpy(&pwrVolt, &frame.data[4], sizeof(float));
				break;

			case CAN_ID_PSU_DATA2:
				memcpy(&pwrCurr, &frame.data[0], sizeof(float));
				memcpy(&pwrPow, &frame.data[4], sizeof(float));
				break;

			case CAN_ID_PSU_DATA3:
				memcpy(&sysVolt, &frame.data[0], sizeof(float));
				memcpy(&sysCurr, &frame.data[4], sizeof(float));
				break;

			case CAN_ID_PSU_DATA4:
				memcpy(&sysPow, &frame.data[0], sizeof(float));
				memcpy(&time, &frame.data[4], sizeof(float));
				break;

			default:
				std::cout << "PsuCom decode error, unkown ID "
				          << std::hex << frame.can_id << std::dec << std::endl;
				break;
		}

	}

	return true;
}

bool PsuCom::print() {

	std::cout << "--- " << time << " ---" << std::endl;

	std::cout << "mainVolt  " << mainVolt << std::endl;
	std::cout << "mainCurr " << mainCurr << std::endl;
	std::cout << "mainPow " << mainPow << std::endl;
	std::cout << "pwrVolt  " << pwrVolt << std::endl;
	std::cout << "pwrCurr " << pwrCurr << std::endl;
	std::cout << "pwrPow " << pwrPow << std::endl;
	std::cout << "sysVolt  " << sysVolt << std::endl;
	std::cout << "sysCurr " << sysCurr << std::endl;
	std::cout << "sysPow " << sysPow << std::endl;

	return true;
}
