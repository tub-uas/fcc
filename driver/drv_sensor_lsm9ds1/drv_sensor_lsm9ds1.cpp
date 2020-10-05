#include <iostream>
#include <string.h>
#include <unistd.h>

#include "drv_sensor_lsm9ds1.h"
/**
 * [Sensor_lsm9ds1::Sensor_lsm9ds1 description]
 */
Sensor_lsm9ds1::Sensor_lsm9ds1() {
	mp_lsmFilterId[0] = IMU_TIME_ID;
	mp_lsmFilterId[1] = IMU_ACCXY_ID;
	mp_lsmFilterId[2] = IMU_ACCZ_GYRX_ID;
	mp_lsmFilterId[3] = IMU_GYRYZ_ID;
	mp_lsmFilterId[4] = IMU_MAGXY_ID;
	mp_lsmFilterId[5] = IMU_MAGZ_PHI_ID;
	mp_lsmFilterId[6] = IMU_THETA_PSI_ID;
}

/**
 * [Sensor_lsm9ds1 description]
 */
Sensor_lsm9ds1::~Sensor_lsm9ds1() {
	exit();
}

/**
 * [Sensor_lsm9ds1::start description]
 * @return [description]
 */
bool Sensor_lsm9ds1::start() {
	std::cout << "SET SOCKET ... ";
	if(setSocket() == false) {
		return false;
	}
	std::cout << "[SUCCESS]" << std::endl;

	std::cout << "SET FILTER ... ";
	if(setFilter() == false) {
		return false;
	}
	std::cout << "[SUCCESS]" << std::endl;

	std::cout << "START MEASUREMENT ... ";
	if(setToRun() == false) {
		return false;
	}
	std::cout << "[SUCCESS]" << std::endl;
	return true;
}

/**
 * [Sensor_lsm9ds1::exit description]
 * @return [description]
 */
bool Sensor_lsm9ds1::exit() {
	if(setToIdle() == false) {
		return false;
	}
}

/**
 * [Sensor_lsm9ds1::setSocket description]
 * @return [description]
 */
bool Sensor_lsm9ds1::setSocket() {
	mp_lsmSocket = scktCan_open("can0");
	if(mp_lsmSocket < 0) {
		return false;
	}
	return true;
}

/**
 * [Sensor_lsm9ds1::setFilter description]
 * @return [description]
 */
bool Sensor_lsm9ds1::setFilter() {
	scktCan_setFilter(mp_lsmSocket,&mp_lsmFilterId[0],7);
	return true;
}

/**
 * [Sensor_lsm9ds1::setToIdle description]
 * @return [description]
 */
bool Sensor_lsm9ds1::setToIdle() {
	scktCanFrame_t canFrame;
	const uint8_t idleCmd[] = {0x01,0x00,0x00,0x00};
	canFrame.can_id     = IMU_CMD_ID;
	canFrame.can_dlc    = 4;
	canFrame.data[0]    = idleCmd[0];
	canFrame.data[1]    = idleCmd[1];
	canFrame.data[2]    = idleCmd[2];
	canFrame.data[3]    = idleCmd[3];
	scktCan_send(mp_lsmSocket,&canFrame);
	sleep(5);
	return true;
}

/**
 * [Sensor_lsm9ds1::setToRun description]
 * @return [description]
 */
bool Sensor_lsm9ds1::setToRun() {
	scktCanFrame_t canFrame;
	const uint8_t idleCmd[] = {0x02,0x00,0x00,0x00};
	canFrame.can_id     = IMU_CMD_ID;
	canFrame.can_dlc    = 4;
	canFrame.data[0]    = idleCmd[0];
	canFrame.data[1]    = idleCmd[1];
	canFrame.data[2]    = idleCmd[2];
	canFrame.data[3]    = idleCmd[3];
	scktCan_send(mp_lsmSocket,&canFrame);
	sleep(3);
	return true;
}

/**
 * [Sensor_lsm9ds1::accessData description]
 * @return [description]
 */
bool Sensor_lsm9ds1::accessData() {
	scktCan_read(mp_lsmSocket,&mp_lsmData);
	switch(mp_lsmData.can_id) {
		case IMU_TIME_ID:
		mp_time     = convertBytesToUint32_t(mp_lsmData.data[0],mp_lsmData.data[1],mp_lsmData.data[2],mp_lsmData.data[3]);
		mp_counter  = convertBytesToUint32_t(mp_lsmData.data[4],mp_lsmData.data[5],mp_lsmData.data[6],mp_lsmData.data[7]);
		break;

		case IMU_ACCXY_ID:
		mp_lsmAcc[0]    = convertBytesToFloat(mp_lsmData.data[0],mp_lsmData.data[1],mp_lsmData.data[2],mp_lsmData.data[3]);
		mp_lsmAcc[1]    = convertBytesToFloat(mp_lsmData.data[4],mp_lsmData.data[5],mp_lsmData.data[6],mp_lsmData.data[7]);
		break;

		case IMU_ACCZ_GYRX_ID:
		mp_lsmAcc[2]    = convertBytesToFloat(mp_lsmData.data[0],mp_lsmData.data[1],mp_lsmData.data[2],mp_lsmData.data[3]);
		mp_lsmGyr[0]    = convertBytesToFloat(mp_lsmData.data[4],mp_lsmData.data[5],mp_lsmData.data[6],mp_lsmData.data[7]);
		break;

		case IMU_GYRYZ_ID:
		mp_lsmGyr[1]    = convertBytesToFloat(mp_lsmData.data[0],mp_lsmData.data[1],mp_lsmData.data[2],mp_lsmData.data[3]);
		mp_lsmGyr[2]    = convertBytesToFloat(mp_lsmData.data[4],mp_lsmData.data[5],mp_lsmData.data[6],mp_lsmData.data[7]);
		break;

		case IMU_MAGXY_ID:
		mp_lsmMag[0]    = convertBytesToFloat(mp_lsmData.data[0],mp_lsmData.data[1],mp_lsmData.data[2],mp_lsmData.data[3]);
		mp_lsmMag[1]    = convertBytesToFloat(mp_lsmData.data[4],mp_lsmData.data[5],mp_lsmData.data[6],mp_lsmData.data[7]);
		break;

		case IMU_MAGZ_PHI_ID:
		mp_lsmMag[2]    = convertBytesToFloat(mp_lsmData.data[0],mp_lsmData.data[1],mp_lsmData.data[2],mp_lsmData.data[3]);
		mp_lsmEul[0]    = convertBytesToFloat(mp_lsmData.data[4],mp_lsmData.data[5],mp_lsmData.data[6],mp_lsmData.data[7]);
		break;

		case IMU_THETA_PSI_ID:
		mp_lsmEul[1]    = convertBytesToFloat(mp_lsmData.data[0],mp_lsmData.data[1],mp_lsmData.data[2],mp_lsmData.data[3]);
		mp_lsmEul[2]    = convertBytesToFloat(mp_lsmData.data[4],mp_lsmData.data[5],mp_lsmData.data[6],mp_lsmData.data[7]);
		break;
	}
}


/**
 * [Sensor_lsm9ds1::getTime description]
 * @return [description]
 */
uint32_t Sensor_lsm9ds1::getTime() {
	return mp_time;
}

/**
 * [Sensor_lsm9ds1::getCounter description]
 * @return [description]
 */
uint32_t Sensor_lsm9ds1::getCounter() {
	return mp_counter;
}

/**
 * [Sensor_lsm9ds1::getAccX description]
 * @return [description]
 */
float32_t Sensor_lsm9ds1::getAccX() {
	return mp_lsmAcc[0];
}

/**
 * [Sensor_lsm9ds1::getAccY description]
 * @return [description]
 */
float32_t Sensor_lsm9ds1::getAccY() {
	return mp_lsmAcc[1];
}

/**
 * [Sensor_lsm9ds1::getAccZ description]
 * @return [description]
 */
float32_t Sensor_lsm9ds1::getAccZ() {
	return mp_lsmAcc[2];
}

/**
 * [Sensor_lsm9ds1::getGyrX description]
 * @return [description]
 */
float32_t Sensor_lsm9ds1::getGyrX() {
	return mp_lsmGyr[0];
}

/**
 * [Sensor_lsm9ds1::getGyrX description]
 * @return [description]
 */
float32_t Sensor_lsm9ds1::getGyrY() {
	return mp_lsmGyr[1];
}

/**
 * [Sensor_lsm9ds1::getGyrX description]
 * @return [description]
 */
float32_t Sensor_lsm9ds1::getGyrZ() {
	return mp_lsmGyr[2];
}

/**
 * [Sensor_lsm9ds1::getMagX description]
 * @return [description]
 */
float32_t Sensor_lsm9ds1::getMagX() {
	return mp_lsmMag[0];
}

/**
 * [Sensor_lsm9ds1::getMagY description]
 * @return [description]
 */
float32_t Sensor_lsm9ds1::getMagY() {
	return mp_lsmMag[1];
}

/**
 * [Sensor_lsm9ds1::getMagZ description]
 * @return [description]
 */
float32_t Sensor_lsm9ds1::getMagZ() {
	return mp_lsmMag[2];
}

/**
 * [Sensor_lsm9ds1::getPhi description]
 * @return [description]
 */
float32_t Sensor_lsm9ds1::getPhi() {
	return mp_lsmEul[0];
}

/**
 * [Sensor_lsm9ds1::getTheta description]
 * @return [description]
 */
float32_t Sensor_lsm9ds1::getTheta() {
	return mp_lsmEul[1];
}

/**
 * [Sensor_lsm9ds1::getPsi description]
 * @return [description]
 */
float32_t Sensor_lsm9ds1::getPsi() {
	return mp_lsmEul[2];
}



/**
 * [Sensor_lsm9ds1::convertBytesToFloat description]
 * @param  _msb   [description]
 * @param  _byte2 [description]
 * @param  _byte3 [description]
 * @param  _lsb   [description]
 * @return        [description]
 */
float Sensor_lsm9ds1::convertBytesToFloat(uint8_t _msb, uint8_t _byte2, uint8_t _byte3, uint8_t _lsb) {
 	float temp;
 	uint8_t byteTemp[4] = {_msb,_byte2,_byte3,_lsb};
 	memcpy(&temp,byteTemp,sizeof(temp));
 	return temp;
 }

/**
 * [Sensor_lsm9ds1::convertBytesToUint32_t description]
 * @param  _msb   [description]
 * @param  _byte2 [description]
 * @param  _byte3 [description]
 * @param  _lsb   [description]
 * @return        [description]
 */
 uint32_t Sensor_lsm9ds1::convertBytesToUint32_t(uint8_t _msb, uint8_t _byte2, uint8_t _byte3, uint8_t _lsb) {
 	uint32_t temp = 0;
 	uint8_t byteTemp[] = {_msb, _byte2, _byte3, _lsb};
 	memcpy(&temp,byteTemp, sizeof(temp));
 	return temp;
 }
