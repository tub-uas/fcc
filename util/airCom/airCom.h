#ifndef AIR_COM_H
#define AIR_COM_H

#include <cstdint>
#include <array>

#include "../can_util/can_ids.h"
#include "../can_util/can_meta.h"
#include "../timer/timer.h"

class AirCom {

public:
	AirCom();

	~AirCom();

	bool init();
	bool receive();
	bool print();

	float velocity = 0.0;
	float dynamicPress = 0.0;
	float baroPress = 0.0;
	float density = 0.0;
	float temp  = 0.0;
	float time  = 0.0;

private:
	int can_sckt = -1;

	std::array<uint16_t, CAN_META_AIR_MSG_NUM> in_ids = {CAN_ID_AIR_DATA0,
	                                                     CAN_ID_AIR_DATA1,
	                                                     CAN_ID_AIR_DATA2};

};

#endif  // AIR_COM_H
