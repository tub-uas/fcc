#include "gpsCom.h"

#include <iostream>
#include <cstring>

#include "../../driver/drv_can/drv_can.h"

GpsCom::GpsCom() {

}

GpsCom::~GpsCom() {
	drv_can_close(can_sckt);
}

bool GpsCom::init() {

	if ((can_sckt = drv_can_open("can0")) < 0) {
		std::cout << "GpsCom can socket error " << std::endl;
		return false;
	}

	if (drv_can_set_filter(can_sckt, &in_ids[0], CAN_META_GPS_MSG_NUM) < 0) {
		std::cout << "GpsCom can filter error " << std::endl;
		return false;
	}

	return true;
}

bool GpsCom::receive() {

	for (int i=0; i<CAN_META_GPS_MSG_NUM; i++) {

		can_frame_t frame;
		drv_can_read(can_sckt, &frame);

		if (frame.can_id != in_ids[i]) {
			std::cout << "GpsCom decode error, can id should be "
			          << std::hex << in_ids[i] << std::dec << " but is "
			          << std::hex << frame.can_id << std::dec << std::endl;
			return false;
		}
		// else {
		// 	std::cout << "GpsCom decode succe, can ids are      "
		// 	          << std::hex << in_ids[i] << std::dec << " but is "
		// 	          << std::hex << frame.can_id << std::dec << std::endl;
		// }

		switch (frame.can_id) {

			case CAN_ID_GPS_DATA0:
				memcpy(&time, &frame.data[0], sizeof(float));
				memcpy(&cog, &frame.data[4], sizeof(float));
				break;

			case CAN_ID_GPS_DATA1:
				memcpy(&second, &frame.data[0], sizeof(uint8_t));
				memcpy(&minute, &frame.data[1], sizeof(uint8_t));
				memcpy(&hour, &frame.data[2], sizeof(uint8_t));
				memcpy(&day, &frame.data[3], sizeof(uint8_t));
				memcpy(&month, &frame.data[4], sizeof(uint8_t));
				memcpy(&year, &frame.data[5], sizeof(uint16_t));
				break;

			case CAN_ID_GPS_DATA2:
				memcpy(&fix, &frame.data[0], sizeof(float));
				memcpy(&fix_mode, &frame.data[1], sizeof(float));
				memcpy(&sats_in_use, &frame.data[2], sizeof(float));
				memcpy(&sats_in_view, &frame.data[3], sizeof(float));
				memcpy(&valid, &frame.data[4], sizeof(float));
				break;

			case CAN_ID_GPS_DATA3:
				memcpy(&latitude, &frame.data[0], sizeof(float));
				memcpy(&longitude, &frame.data[4], sizeof(float));
				break;

			case CAN_ID_GPS_DATA4:
				memcpy(&altitude, &frame.data[0], sizeof(float));
				memcpy(&speed, &frame.data[4], sizeof(float));
				break;

			case CAN_ID_GPS_DATA5:
				memcpy(&dop_h, &frame.data[0], sizeof(float));
				memcpy(&dop_p, &frame.data[4], sizeof(float));
				break;

			case CAN_ID_GPS_DATA6:
				memcpy(&dop_v, &frame.data[0], sizeof(float));
				memcpy(&variation, &frame.data[4], sizeof(float));
				break;

			case CAN_ID_GPS_DATA7:
				memcpy(&mag[0], &frame.data[0], sizeof(float));
				memcpy(&mag[1], &frame.data[4], sizeof(float));
				break;

			case CAN_ID_GPS_DATA8:
				memcpy(&mag[2], &frame.data[0], sizeof(float));
				break;

			default:
				std::cout << "GpsCom decode error, unkown ID "
				          << std::hex << frame.can_id << std::dec << std::endl;
				break;
		}

	}

	return true;
}

bool GpsCom::print() {

	std::cout << "--- " << time << " ---" << std::endl;

	std::cout << "second        " << second << std::endl;
	std::cout << "minute        " << minute << std::endl;
	std::cout << "hour          " << hour << std::endl;
	std::cout << "day           " << day << std::endl;
	std::cout << "month         " << month << std::endl;
	std::cout << "year          " << year << std::endl;
	std::cout << "fix           " << fix << std::endl;
	std::cout << "fix_mode      " << fix_mode << std::endl;
	std::cout << "sats_in_view  " << sats_in_view << std::endl;
	std::cout << "sats_in_use   " << sats_in_use << std::endl;
	std::cout << "latitude      " << latitude << std::endl;
	std::cout << "longitude     " << longitude << std::endl;
	std::cout << "altitude      " << altitude << std::endl;
	std::cout << "speed         " << speed << std::endl;
	std::cout << "cog           " << cog << std::endl;
	std::cout << "dop_h         " << dop_h << std::endl;
	std::cout << "dop_p         " << dop_p << std::endl;
	std::cout << "dop_v         " << dop_v << std::endl;
	std::cout << "variation     " << variation << std::endl;
	std::cout << "valid         " << valid << std::endl;

	for (int i=0; i<3; i++) {
		std::cout << "mag[" << i << "] " << mag[i] << std::endl;
	}

	return true;
}
