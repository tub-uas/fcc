#ifndef RAI_COM_H
#define RAI_COM_H

#include <cstdint>
#include <array>

#include "../can_util/can_ids.h"
#include "../can_util/can_meta.h"
#include "../timer/timer.h"

class RaiCom {

public:
	RaiCom();

	~RaiCom();

	bool init();
	bool receive();
	bool send(std::array<uint16_t, CAN_META_RAI_CHNL_NUM> channel, float time);
	bool send();
	bool print();
	bool print(std::array<uint16_t, CAN_META_RAI_CHNL_NUM> channel, float time);

	std::array<uint16_t, CAN_META_RAI_CHNL_NUM> channel = {};
	float time = 0.0;

private:
	int can_sckt = -1;

	std::array<uint16_t, CAN_META_RAI_MSG_NUM> in_ids = {CAN_ID_RAI_DATA0,
	                                                     CAN_ID_RAI_DATA1,
	                                                     CAN_ID_RAI_DATA2,
	                                                     CAN_ID_RAI_DATA3};

	std::array<uint16_t, CAN_META_RAI_MSG_NUM> out_ids = {CAN_ID_FCC_DATA0,
	                                                      CAN_ID_FCC_DATA1,
	                                                      CAN_ID_FCC_DATA2,
	                                                      CAN_ID_FCC_DATA3};

};

#endif  // RAI_COM_H
