#ifndef WAYPOINT_STORAGE_H
#define WAYPOINT_STORAGE_H

#include <cstdint>

typedef enum {
	HOME=0,
	LOITER,
	THROUGH, // Fichter-Stephan 2020 Flugregelung - alternative Behrens A. Bachelor thesis
	TRACK,
	AROUND,
	NEAR
} wp_type_t;

typedef struct {
	wp_type_t type;
	int32_t idx;
	bool isAutoUpdate;
	bool isCurrent;
	bool isValid;
	double latitude;
	double longitude;
	double altitude;
	double airspeed;
	int32_t param_1;
	int32_t param_2;
	int32_t param_3;
	int32_t param_4;
	int32_t param_5;
} wp_t;

class WaypointStorage {
public:

private:
	
};






#endif // WAYPOINT_STORAGE_H