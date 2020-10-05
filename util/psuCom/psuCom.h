#ifndef PSU_COM_H
#define PSU_COM_H

#include <cstdint>
#include <array>

#include "../can_util/can_ids.h"
#include "../can_util/can_meta.h"
#include "../timer/timer.h"

class PsuCom {

public:
	PsuCom();

	~PsuCom();

	bool init();
	bool receive();
	bool print();

	float mainVolt  = 0.0;
	float mainCurr = 0.0;
	float mainPow = 0.0;
	float pwrVolt = 0.0;
	float pwrCurr = 0.0;
	float pwrPow = 0.0;
	float sysVolt = 0.0;
	float sysCurr = 0.0;
	float sysPow = 0.0;
	float time  = 0.0;

private:
	int can_sckt = -1;

	std::array<uint16_t, CAN_META_PSU_MSG_NUM> in_ids = {CAN_ID_PSU_DATA0,
	                                                     CAN_ID_PSU_DATA1,
	                                                     CAN_ID_PSU_DATA2,
	                                                     CAN_ID_PSU_DATA3,
	                                                     CAN_ID_PSU_DATA4};

};

#endif  // PSU_COM_H
