#ifndef AHRS_COM_H
#define AHRS_COM_H

#include <cstdint>
#include <array>

#include "../can_util/can_ids.h"
#include "../can_util/can_meta.h"
#include "../timer/timer.h"

class AhrsCom {

public:
	AhrsCom();

	~AhrsCom();

	bool init();
	bool receive();
	bool print();

	std::array<float, 3> acc = {};
	std::array<float, 3> gyr = {};
	std::array<float, 3> mag = {};
	std::array<float, 3> att = {};
	float temp  = 0.0;
	float press = 0.0;
	float time  = 0.0;

private:
	int can_sckt = -1;

	std::array<uint16_t, CAN_META_AHRS_MSG_NUM> in_ids = {CAN_ID_AHRS_DATA0,
	                                                      CAN_ID_AHRS_DATA1,
	                                                      CAN_ID_AHRS_DATA2,
	                                                      CAN_ID_AHRS_DATA3,
	                                                      CAN_ID_AHRS_DATA4,
	                                                      CAN_ID_AHRS_DATA5,
	                                                      CAN_ID_AHRS_DATA6,
	                                                      CAN_ID_AHRS_DATA7};

};

#endif  // AHRS_COM_H
