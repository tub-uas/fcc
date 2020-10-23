#ifndef GPS_COM_H
#define GPS_COM_H

#include <cstdint>
#include <array>

#include "../can_util/can_ids.h"
#include "../can_util/can_meta.h"
#include "../timer/timer.h"

class GpsCom {

public:
	GpsCom();

	~GpsCom();

	bool init();
	bool receive();
	bool print();

	float time;
	uint8_t second;
	uint8_t minute;
	uint8_t hour;
	uint8_t day;
	uint8_t month;
	uint16_t year;
	uint8_t fix;
	uint8_t fix_mode;
	uint8_t sats_in_view;
	uint8_t sats_in_use;
	float latitude;
	float longitude;
	float altitude;
	float speed;
	float cog;
	float dop_h;
	float dop_p;
	float dop_v;
	float variation;
	uint8_t valid;
	std::array<float, 3> mag = {};

private:
	int can_sckt = -1;

	std::array<uint16_t, CAN_META_GPS_MSG_NUM> in_ids = {CAN_ID_GPS_DATA0,
	                                                     CAN_ID_GPS_DATA1,
	                                                     CAN_ID_GPS_DATA2,
	                                                     CAN_ID_GPS_DATA3,
	                                                     CAN_ID_GPS_DATA4,
	                                                     CAN_ID_GPS_DATA5,
	                                                     CAN_ID_GPS_DATA6,
	                                                     CAN_ID_GPS_DATA7,
	                                                     CAN_ID_GPS_DATA8};

};

#endif  // GPS_COM_H
