#include <iostream>
#include <chrono>

#include <string.h>
#include <cmath>
#include <unistd.h>

#include "drv_airdata.h"

/**
 * [airdata::airdata description]
 */
airdata::airdata() {
	mp_airFilterId[0] = AIR_TIME_ID;
	mp_airFilterId[1] = AIR_PRESSURE_ID;
	mp_airFilterId[2] = AIR_DENSVEL_ID;
}

/**
 * [airdata description]
 */
airdata::~airdata() {

}

/**
 * [airdata::start description]
 * @return [description]
 */
bool airdata::start() {


	std::cout << "SET SOCKET ... ";
	if(setSocket() == false) {
		return false;
	}
	std::cout << "[SUCCESS]" << std::endl;

	std::cout << "SET FILTER ... ";
	if(setFilter() == false) {
		return false;
	}

	std::cout << "CALIBRATE SENSOR ... ";
	if(setToIdle() == false) {
		return false;
	}
	setDiffToNull();
	if(isCalibrate() == false) {
		std::cout << "[FAILED]" << std::endl;
	}
	std::cout << "[SUCCESS]" << std::endl;

	std::cout << "START MEASUREMENT ...";
	if(setToRun() == false) {
		return false;
	}
	std::cout << "[SUCCESS]" << std::endl;
	return true;
}

/**
 * [airdata::exit description]
 * @return [description]
 */
bool airdata::exit() {
	setToIdle();
	return true;
}

/**
 * [airdata::setConfig description]
 * @return [description]
 */
bool airdata::setSocket() {
	mp_airSocket = scktCan_open("can0");
	if(mp_airSocket < 0) {
		return false;
	}
	return true;
}

/**
 * [airdata::setFilter description]
 * @return [description]
 */
bool airdata::setFilter() {;
	scktCan_setFilter(mp_airSocket,&mp_airFilterId[0],3);
	return true;
}


/**
 * [airdata::accessData description]
 * @return [description]
 */
bool airdata::accessData() {
	scktCan_read(mp_airSocket,&mp_airData);
	if(mp_airData.can_id == AIR_TIME_ID) {
		mp_time     = convertBytesToUint32_t(mp_airData.data[0],mp_airData.data[1],mp_airData.data[2],mp_airData.data[3]);
		mp_counter  = convertBytesToUint32_t(mp_airData.data[4],mp_airData.data[5],mp_airData.data[6],mp_airData.data[7]);
		return true;
	}
	else if(mp_airData.can_id == AIR_PRESSURE_ID) {
		mp_diff     = convertBytesToFloat(mp_airData.data[0],mp_airData.data[1],mp_airData.data[2],mp_airData.data[3]);
		mp_baro     = convertBytesToFloat(mp_airData.data[4],mp_airData.data[5],mp_airData.data[6],mp_airData.data[7]);

	}
	else if(mp_airData.can_id == AIR_DENSVEL_ID) {
		mp_speed    = convertBytesToFloat(mp_airData.data[0],mp_airData.data[1],mp_airData.data[2],mp_airData.data[3]);
		mp_density  = convertBytesToFloat(mp_airData.data[4],mp_airData.data[5],mp_airData.data[6],mp_airData.data[7]);
	}
	return false;
}

/**
 * [airdata::setToIdle description]
 * @return [description]
 */
bool airdata::setToIdle() {
	scktCanFrame_t canFrame;
	const uint8_t idleCmd[] = {0x01,0x00,0x00,0x00};
	canFrame.can_id     = AIR_CMD_ID;
	canFrame.can_dlc    = 4;
	canFrame.data[0]    = idleCmd[0];
	canFrame.data[1]    = idleCmd[1];
	canFrame.data[2]    = idleCmd[2];
	canFrame.data[3]    = idleCmd[3];
	scktCan_send(mp_airSocket,&canFrame);
	sleep(1);
	return true;
}

/**
 * [airdata::setDiffToNull description]
 * @return [description]
 */
bool airdata::setDiffToNull() {
	scktCanFrame_t canFrame;
	const uint8_t idleCmd[] = {0x03,0x00,0x00,0x00};
	canFrame.can_id     = AIR_CMD_ID;
	canFrame.can_dlc    = 4;
	canFrame.data[0]    = idleCmd[0];
	canFrame.data[1]    = idleCmd[1];
	canFrame.data[2]    = idleCmd[2];
	canFrame.data[3]    = idleCmd[3];
	std::cout << "Calibration in ... 3 seconds" << std::endl;
	sleep(3);
	std::cout << "Calibration ... [ACTIV]" << std::endl;
	scktCan_send(mp_airSocket,&canFrame);
	sleep(14);
	std::cout << "Calibration ... [FINISHED]" << std::endl;
	mp_calib = true;
	return true;
}

/**
 * [airdata::setToRun description]
 * @return [description]
 */
bool airdata::setToRun() {
	scktCanFrame_t canFrame;
	const uint8_t idleCmd[] = {0x02,0x00,0x00,0x00};
	canFrame.can_id     = AIR_CMD_ID;
	canFrame.can_dlc    = 4;
	canFrame.data[0]    = idleCmd[0];
	canFrame.data[1]    = idleCmd[1];
	canFrame.data[2]    = idleCmd[2];
	canFrame.data[3]    = idleCmd[3];
	scktCan_send(mp_airSocket,&canFrame);
	return true;
}
/**
 * [airdata::isCalibrate description]
 * @return [description]
 */
bool airdata::isCalibrate() {
	return mp_calib;
}


/**
 * [airdata::getDiff description]
 * @return [description]
 */
float32_t airdata::getDiff() {
	return mp_diff;
}


/**
 * [getBaro description]
 * @return [description]
 */
float32_t airdata::getBaro() {
	return mp_baro;
}


/**
 * [getSpeed description]
 * @return [description]
 */
float32_t airdata::getSpeed() {
	return mp_speed;
}


/**
 * [airdata::getDensity description]
 * @return [description]
 */
float32_t airdata::getDensity() {
	return mp_density;
}


/**
 * [airdata::getTime description]
 * @return [description]
 */
uint32_t airdata::getTime() {
	return mp_time;
}

/**
 * [airdata::getCounter description]
 * @return [description]
 */
uint32_t airdata::getCounter() {
	return mp_counter;
}


/**
 * [convertBytesToFloat description]
 * @param data [description]
 * @param _len [description]
 */
float32_t airdata::convertBytesToFloat(uint8_t _msb, uint8_t _byte2, uint8_t _byte3, uint8_t _lsb) {
	float32_t temp;
	uint8_t byteTemp[4] = {_msb,_byte2,_byte3,_lsb};
	memcpy(&temp,byteTemp,sizeof(temp));
	return temp;
}

uint32_t airdata::convertBytesToUint32_t(uint8_t _msb, uint8_t _byte2, uint8_t _byte3, uint8_t _lsb) {
	uint32_t temp = 0;
	uint8_t byteTemp[] = {_msb, _byte2, _byte3, _lsb};
	memcpy(&temp,byteTemp, sizeof(temp));
	return temp;
}
