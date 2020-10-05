#ifndef AVSOFT_DRV_AIRDATA_H
#define AVSOFT_DRV_AIRDATA_H

#include "../drv_scktCan/drv_scktCan.h"
#include <cstdint>

typedef float float32_t;

#define AIR_BASE_ID     (0x090)
#define AIR_TIME_ID     (AIR_BASE_ID)
#define AIR_PRESSURE_ID (AIR_BASE_ID+1)
#define AIR_DENSVEL_ID  (AIR_BASE_ID+2)

#define AIR_CMD_ID      (0x080)

#define AIR_CALIBLEN    1000

typedef union {
	float32_t air_data[2];
	uint8_t air_raw[8];
} air_data_t;

class airdata
{
public:
	airdata();
	~airdata();

	bool start();
	bool exit();

	bool setSocket();
	bool setFilter();
	bool setBias();

	bool accessData();
	bool isUpdate();
	bool isAvailable();
	bool isCalibrate();
	bool setToIdle();
	bool setToRun();
	bool setDiffToNull();

	uint32_t getTime();
	uint32_t getCounter();
	float32_t getDiff();
	float32_t getBaro();
	float32_t getSpeed();
	float32_t getDensity();

	float32_t convertBytesToFloat(uint8_t _msb, uint8_t _byte2, uint8_t _byte3, uint8_t _lsb);
	uint32_t convertBytesToUint32_t(uint8_t _msb, uint8_t _byte2, uint8_t _byte3, uint8_t _lsb);

private:
	bool            mp_calib;
	int32_t         mp_airSocket;
	scktCanFrame_t  mp_airData;
	uint32_t        mp_airFilterId[3];

	uint32_t        mp_time;
	uint32_t        mp_counter;
	float32_t       mp_diff;
	float32_t       mp_baro;
	float32_t       mp_density;
	float32_t       mp_speed;

};

#endif // AVSOFT_DRV_AIRDATA_H
