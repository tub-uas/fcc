#ifndef AVSOFT_DRV_SENSOR_LSM9DS1_H
#define AVSOFT_DRV_SENSOR_LSM9DS1_H

#include "drv_scktCan.h"
#include <cstdint>
typedef float float32_t;

#define IMU_BASE_ID        (0x070)
#define IMU_TIME_ID        (IMU_BASE_ID)
#define IMU_ACCXY_ID       (IMU_BASE_ID+1)
#define IMU_ACCZ_GYRX_ID   (IMU_BASE_ID+2)
#define IMU_GYRYZ_ID       (IMU_BASE_ID+3)
#define IMU_MAGXY_ID       (IMU_BASE_ID+4)
#define IMU_MAGZ_PHI_ID    (IMU_BASE_ID+5)
#define IMU_THETA_PSI_ID   (IMU_BASE_ID+6)

#define IMU_CMD_ID          (0x060)


class Sensor_lsm9ds1
{
public:
	Sensor_lsm9ds1();
	~Sensor_lsm9ds1();

	bool start();
	bool exit();

	bool setSocket();
	bool setFilter();

	bool setToIdle();
	bool setToRun();


	bool accessData();

	uint32_t getTime();
	uint32_t getCounter();

	float32_t getAccX();
	float32_t getAccY();
	float32_t getAccZ();

	float32_t getGyrX();
	float32_t getGyrY();
	float32_t getGyrZ();

	float32_t getMagX();
	float32_t getMagY();
	float32_t getMagZ();

	float32_t getPhi();
	float32_t getTheta();
	float32_t getPsi();

private:

	int32_t         mp_lsmSocket;
	scktCanFrame_t  mp_lsmData;
	uint32_t        mp_lsmFilterId[7];


	uint32_t mp_time;
	uint32_t mp_counter;

	float32_t mp_lsmAcc[3]  = {0.0,0.0,0.0};
	float32_t mp_lsmGyr[3]  = {0.0,0.0,0.0};
	float32_t mp_lsmMag[3]  = {0.0,0.0,0.0};
	float32_t mp_lsmEul[3]  = {0.0,0.0,0.0};

	float convertBytesToFloat(uint8_t _msb, uint8_t _byte2, uint8_t _byte3, uint8_t _lsb);
	uint32_t convertBytesToUint32_t(uint8_t _msb, uint8_t _byte2, uint8_t _byte3, uint8_t _lsb);
};



#endif // AVSOFT_DRV_SENSOR_LSM9DS1_H
