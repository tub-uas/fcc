#include <iostream>
#include <cstring>
#include <cmath>

#include "drv_ahrs3dm335.h"

/**
 * [ahrs3dm335::ahrs3dm335 description]
 */
ahrs3dm335::ahrs3dm335() {

}

/**
 * [ahrs3dm335 description]
 */
ahrs3dm335::~ahrs3dm335() {

}

/**
 * [ahrs3dm335::start description]
 * @return [description]
 */
bool ahrs3dm335::start() {
	return init("/dev/ttyACM0",B115200);
}

/**
 * [getHeader description]
 * @return [description]
 */
bool ahrs3dm335::getHeader() {
	uint8_t header[2];
	int32_t i = 0;
	do {
		header[0] = header[1];
		receive(&header[1],1);
		if(header[0] == INS_SYNC_BYTE_1 && header[1] == INS_SYNC_BYTE_2) {
			return true;
		}
		++i;
	} while(i < INS_MAX_HEAD_REQUEST);
	return false;
}

/**
 * [readResponse description]
 * @param _data [description]
 * @param _len  [description]
 */
void ahrs3dm335::readResponse(uint8_t _data[], int32_t _len) {

	if(getHeader()) {
		if(receive(&_data[2],_len-2) == false) {
			std::cerr << "errorCatching message" << std::endl;
		}
		_data[0] = INS_SYNC_BYTE_1;
		_data[1] = INS_SYNC_BYTE_2;
	}
}

/**
 * [isAvailable description]
 * @return [description]
 */
bool ahrs3dm335::isAvailable() {
	uint8_t cmd[]       = INS_PING_CMD;
	uint8_t rsp[]       = INS_PING_RSP;
	uint8_t data[100]   = {0};
	int32_t cmdlen      = sizeof(cmd)/sizeof(uint8_t);
	int32_t rsplen      = sizeof(rsp)/sizeof(uint8_t);

	if(send(cmd,cmdlen) == false) {
		SERIAL_SEND_FAILED
		return false;
	}
	readResponse(data,rsplen);
	for(int32_t i = 0; i < rsplen; ++i) {
		if(data[i] != rsp[i]) {
			std::cerr << "Error Response" << std::endl;
			return false;
		}
	}
	return true;
}

/**
 * [setIdle description]
 * @return [description]
 */
bool ahrs3dm335::setIdle() {
	uint8_t cmd[]       = INS_SET_IDLE_CMD;
	uint8_t rsp[]       = INS_SET_IDLE_RSP;
	uint8_t data[100]   = {0};
	int32_t cmdlen      = sizeof(cmd)/sizeof(uint8_t);
	int32_t rsplen      = sizeof(rsp)/sizeof(uint8_t);
	flushio();
	if(send(cmd,cmdlen) == false) {
		SERIAL_SEND_FAILED
	}
	readResponse(data,rsplen);
	for(int32_t i = 0; i < rsplen; ++i) {
		if(data[i] != rsp[i]) {
			std::cerr << "Error Response" << std::endl;
			return false;
		}
	}
	return true;
}

/**
 * [setResume description]
 * @return [description]
 */
bool ahrs3dm335::setResume() {
	return true;
}

/**
 * [ahrs3dm335::exit description]
 * @return [description]
 */
bool ahrs3dm335::exit() {
	vanish();
	return true;
}

/**
 * [ahrs3dm335::saveAhrsFmt description]
 * @return [description]
 */
bool ahrs3dm335::saveAhrsFmt() {
	uint8_t cmdsave[]   = INS_AHRS_MSG_FMT_SAVE_CMD;
	int32_t cmdlen      = sizeof(cmdsave)/sizeof(uint8_t);

	// SET MSG FORMAT
	if(send(cmdsave,cmdlen) == false) {
		SERIAL_SEND_FAILED
		return false;
	}
	return true;
}

/**
 * [ahrs3dm335::saveGpsFmt description]
 * @return [description]
 */
bool ahrs3dm335::saveGpsFmt() {
	uint8_t cmdsave[]   = INS_GPS_MSG_FMT_SAVE_CMD;
	int32_t cmdlen      = sizeof(cmdsave)/sizeof(uint8_t);

	// SET MSG FORMAT
	if(send(cmdsave,cmdlen) == false) {
		SERIAL_SEND_FAILED
		return false;
	}
	return true;
}

/**
 * [config description]
 * @return [description]
 */
bool ahrs3dm335::setConfig() {
	flushio();

	setIdle();
	isAvailable();
	setStreamOff();
	configAhrs();
	configGps();
	flushio();
	setStreamOn();
	return true;
}

/**
 * [ahrs3dm335::getConfig description]
 * @return [description]
 */
bool ahrs3dm335::getConfig() {
	setIdle();
	isAvailable();
	return true;
}

/**
 * [configAhrs description]
 * @return [description]
 */
bool ahrs3dm335::configAhrs() {
	// 100 Hz       -> 0x000A
	// Flags        -> 0x1003
	// Acc/GyrFilt  -> 0x0E
	// Mag Filter   -> 0x11
	// Up Comp      -> 0x000A
	// N Comp       -> 0x000A
	// MAG BW       -> 0x01
	// Reserved     -> 0x0000
	uint8_t cmdmsg[]    = INS_AHRS_MSG_FMT_CMD;
	uint8_t cmdcond[]   = INS_AHRS_SIG_COND_CONFIG_CMD;
	uint8_t cmdtime[]   = INS_AHRS_TIMESTAMP_CMD;
	int32_t cmdlen      = sizeof(cmdmsg)/sizeof(uint8_t);

	// SET MSG FORMAT
	if(send(cmdmsg,cmdlen) == false) {
		SERIAL_SEND_FAILED
		return false;
	}

	// SET SIG COND
	cmdlen = sizeof(cmdcond)/sizeof(uint8_t);
	if(send(cmdcond,cmdlen) == false) {
		SERIAL_SEND_FAILED
		return false;
	}
	flushio();

	// SET AHRS TIME
	cmdlen = sizeof(cmdtime)/sizeof(uint8_t);
	if(send(cmdtime,cmdlen) == false) {
		SERIAL_SEND_FAILED
		return false;
	}

	return true;
}

/**
 * [configGPS description]
 * @return [description]
 */
bool ahrs3dm335::configGps() {
	uint8_t cmdmode[]   = INS_GPS_DYNAMIC_MODE_2G_CMD;
	uint8_t cmdmsg[]    = INS_GPS_MSG_CONFIG_READ;

	// SET MODE
	uint8_t cmdlen      = sizeof(cmdmode)/sizeof(uint8_t);
	if(send(cmdmode,cmdlen) == false) {
		SERIAL_SEND_FAILED
		return false;
	}
	flushio();

	// SET MSG FORMAT
	cmdlen = sizeof(cmdmsg)/sizeof(uint8_t);
	if(send(cmdmsg,cmdlen) == false) {
		SERIAL_SEND_FAILED
		return false;
	}

	return true;
}

/**
 * [setStreamOn description]
 * @return [description]
 */
bool ahrs3dm335::setStreamOn() {
	uint8_t cmd[]       = INS_AHRS_GPS_STREAM_ON_CMD;
	uint8_t rsp[]       = INS_AHRS_GPS_STREAM_ON_RSP;
	uint8_t data[100]   = {0};
	int32_t cmdlen      = sizeof(cmd)/sizeof(uint8_t);
	int32_t rsplen      = sizeof(rsp)/sizeof(uint8_t);
	if(send(cmd,cmdlen) == false) {
		SERIAL_SEND_FAILED
	}
	readResponse(data,rsplen);
	for(int32_t i = 0; i < rsplen; ++i) {
		if(data[i] != rsp[i]) {
			std::cerr << "Error Response" << std::endl;
			return false;
		}
	}
	return true;
}

/**
 * [setStreamOff description]
 * @return [description]
 */
bool ahrs3dm335::setStreamOff() {
	uint8_t cmd[]       = INS_AHRS_GPS_STREAM_OFF_CMD;
	uint8_t rsp[]       = INS_AHRS_GPS_STREAM_OFF_RSP;
	uint8_t data[100]   = {0};
	int32_t cmdlen      = sizeof(cmd)/sizeof(uint8_t);
	int32_t rsplen      = sizeof(rsp)/sizeof(uint8_t);
	if(send(cmd,cmdlen) == false) {
		SERIAL_SEND_FAILED
	}
	readResponse(data,rsplen);
	for(int32_t i = 0; i < rsplen; ++i) {
		if(data[i] != rsp[i]) {
			std::cerr << "Error Response" << std::endl;
			return false;
		}
	}
	return true;
}



/**
 * [setGpsOn description]
 * @return [description]
 */
bool ahrs3dm335::setGpsOn() {
	return true;
}

/**
 * [setGpsOff description]
 * @return [description]
 */
bool ahrs3dm335::setGpsOff() {
	return true;
}

/**
 * [accessData description]
 * @return [description]
 */
bool ahrs3dm335::accessData() {
	uint8_t device          = 0;
	uint8_t sumLen          = 0;
	// uint8_t descField       = 0;	// unused
	uint8_t payload[1000]   = {0};
	int32_t dataLen         = 0;
	double tmp              = 0.0;
	uint8_t *tmpData        = nullptr;
	if(getHeader()) {
		receive(&device,1);
		receive(&sumLen,1);
		dataLen = static_cast<int32_t>(sumLen);
		receive(payload,dataLen+2);


		switch(device) {

			case INS_AHRS_DESC_SET:


			// TIME Data
			tmpData = scanMsg(payload,0x06,0x0E,dataLen);
			if(tmpData == nullptr) {
				return false;
			}
			mp_timeStamp = convertBytesToTime(tmpData[3],tmpData[2],tmpData[1],tmpData[0]);
			//printf("TimeStamp: %.6f\n",mp_timeStamp);
			// ACC DATA
			tmpData = scanMsg(payload,0x0E,0x04,dataLen);
			if(tmpData == nullptr) {
				return false;
			}
			for(int32_t i = 0; i < 3; ++i) {
				mp_accScl[i] = convertBytesToFloat(tmpData[4*i+3],tmpData[4*i+2],tmpData[4*i+1],tmpData[4*i]);
			}
			//printf("ACC - X: %+.6f  Y: %+.6f  Z: %+.6f\n",mp_accScl[0],mp_accScl[1],mp_accScl[2]);
			// GYR DATA
			tmpData = scanMsg(payload,0x0E,0x05,dataLen);
			if(tmpData == nullptr) {
				return false;
			}
			for(int32_t i = 0; i < 3; ++i) {
				mp_gyrScl[i] = convertBytesToFloat(tmpData[4*i+3],tmpData[4*i+2],tmpData[4*i+1],tmpData[4*i]);
			}
			//printf("GYR - X: %+.6f  Y: %+.6f  Z: %+.6f\n",mp_gyrScl[0],mp_gyrScl[1],mp_gyrScl[2]);
			// MAG DATA
			tmpData = scanMsg(payload,0x0E,0x06,dataLen);
			if(tmpData == nullptr) {
				return false;
			}
			for(int32_t i = 0; i < 3; ++i) {
				mp_magScl[i] = convertBytesToFloat(tmpData[4*i+3],tmpData[4*i+2],tmpData[4*i+1],tmpData[4*i]);
			}
			//printf("MAG - X: %+.6f  Y: %+.6f  Z: %+.6f\n",mp_magScl[0],mp_magScl[1],mp_magScl[2]);
			// QUAT DATA
			tmpData = scanMsg(payload,0x12,0x0A,dataLen);
			if(tmpData == nullptr) {
				return false;
			}


			for(int32_t i = 0; i < 4; ++i) {
				mp_quater[i] = convertBytesToFloat(tmpData[4*i+3],tmpData[4*i+2],tmpData[4*i+1],tmpData[4*i]);
				tmp += mp_quater[i]*mp_quater[i];
			}
			tmp = sqrt(tmp);
			//printf("QUAT - E1: %+.6f  E2: %+.6f  E3: %+.6f  E4: %+.6f\n",mp_quater[0],mp_quater[1],mp_quater[2],mp_quater[3]);

			//printf("QUAT NORM: %+.6f\n",tmp);
			computeQuatToEuler();
			//printf("EULER - PHI: %+.6f  THETA: %+.6f  PSI: %+.6f\n",180.0/3.141*mp_euler[0],180.0/3.141*mp_euler[1],180.0/3.141*mp_euler[2]);
			// BEACON
			tmpData = scanMsg(payload,0x0B,0x0F,sumLen);
			if(tmpData == nullptr) {
				return false;
			}
			mp_beaconStatus = tmpData[0];
			mp_beaconTimeStamp = static_cast<double>(convertBytesToUint32(tmpData[4],tmpData[3],tmpData[2],tmpData[1])) +
		 static_cast<double>(convertBytesToUint32(tmpData[8],tmpData[7],tmpData[6],tmpData[5]))/1000000000.0;
		//printf("BEACON - STATE %03d: %.6lf\n",mp_beaconStatus,mp_beaconTimeStamp);
		break;

		case INS_GPS_DESC_SET:


		// LLH DATA
		tmpData = scanMsg(payload,0x2C,0x03,sumLen);
		if(tmpData != nullptr) {
			mp_gpsLat = convertBytesToDouble(tmpData[7],tmpData[6],tmpData[5],tmpData[4],tmpData[3],tmpData[2],tmpData[1],tmpData[0]);
			mp_gpsLon = convertBytesToDouble(tmpData[15],tmpData[14],tmpData[13],tmpData[12],tmpData[11],tmpData[10],tmpData[9],tmpData[8]);
			mp_gpsMsl = convertBytesToDouble(tmpData[31],tmpData[30],tmpData[29],tmpData[28],tmpData[27],tmpData[26],tmpData[25],tmpData[24]);
			//printf("POS - Lat: %+.6lf  Lon: %+.6lf  Hmsl: %+.6lf\n",mp_gpsLat,mp_gpsLon,mp_gpsMsl);
		}
		else {
			return false;
		}
		// NED VEL DATA
		tmpData = scanMsg(payload,0x24,0x05,sumLen);
		if(tmpData != nullptr) {
			for(int32_t i = 0; i < 3; ++i) {
				mp_gpsVelNed[i] = convertBytesToFloat(tmpData[4*i+3],tmpData[4*i+2],tmpData[4*i+1],tmpData[4*i]);
			}
			mp_gpsGndVel    = convertBytesToFloat(tmpData[19],tmpData[18],tmpData[17],tmpData[16]);
			mp_gpsHeading   = convertBytesToFloat(tmpData[23],tmpData[22],tmpData[21],tmpData[20]);
			//printf("VEL - N: %+.6f  E: %+.6f  D: %+.6f  GS: %+.6f  HD: %+.6f\n",mp_gpsVelNed[0],mp_gpsVelNed[1],mp_gpsVelNed[2],mp_gpsGndVel,mp_gpsHeading);
		}
		else {
			return false;
		}
		// GPS FIX DATA
		tmpData = scanMsg(payload,0x08,0x0B,sumLen);
		if(tmpData != nullptr) {
			mp_fixType = tmpData[0];
			mp_satUsed = tmpData[1];
			mp_validFlag = convertBytesToUint16(tmpData[5],tmpData[4]);
			//printf("FIX - TYPE: %04hhu  SSOL: %03hhu  VALID: %04hhu\n",mp_fixType,mp_satUsed,mp_validFlag);
		}
		else {
			return false;
		}
		break;
		default:
		break;
	}
	}
	return true;
}

/**
 * [getXacc description]
 * @return [description]
 */
float ahrs3dm335::getXacc() {
	return mp_accScl[0];
}

/**
 * [getYacc description]
 * @return [description]
 */
float ahrs3dm335::getYacc() {
	return mp_accScl[1];
}

/**
 * [getZacc description]
 * @return [description]
 */
float ahrs3dm335::getZacc() {
	return mp_accScl[2];
}

/**
 * [getXgyr description]
 * @return [description]
 */
float ahrs3dm335::getXgyr() {
	return mp_gyrScl[0];
}
/**
 * [getYgyr description]
 * @return [description]
 */
float ahrs3dm335::getYgyr() {
	return mp_gyrScl[1];
}

/**
 * [getZgyr description]
 * @return [description]
 */
float ahrs3dm335::getZgyr() {
	return mp_gyrScl[2];
}

/**
 * [getXmag description]
 * @return [description]
 */
float ahrs3dm335::getXmag() {
	return mp_magScl[0];
}

/**
 * [getYmag description]
 * @return [description]
 */
float ahrs3dm335::getYmag() {
	return mp_magScl[1];
}

/**
 * [getZmag description]
 * @return [description]
 */
float ahrs3dm335::getZmag() {
	return mp_magScl[2];
}

// GET ATTITUDE

/**
 * [getQuaternion description]
 */
void ahrs3dm335::getQuaternion(float _quater[4]) {
	for(int32_t i = 0; i < 4; ++i) {
		_quater[i] = mp_quater[i];
	}
}

/**
 * [computeQuatToEuler description]
 */
void ahrs3dm335::computeQuatToEuler() {
	float sinr_cosp = +2.0 * (mp_quater[0]*mp_quater[1] + mp_quater[2]*mp_quater[3]);
	float cosr_cosp = +1.0 -2.0*(mp_quater[1]*mp_quater[1] + mp_quater[2]*mp_quater[2]);
	mp_euler[0] = atan2(sinr_cosp,cosr_cosp);

	float sinp = +2.0 *(mp_quater[0]*mp_quater[2]-mp_quater[3]*mp_quater[1]);
	if(fabs(sinp) >= 1.0) {
		mp_euler[1] = copysign(3.141/2.0,sinp);
	}
	else {
		mp_euler[1] = asin(sinp);
	}

	float siny_cosp = +2.0 *(mp_quater[0]*mp_quater[3] + mp_quater[1]*mp_quater[2]);
	float cosy_cosp = +1.0 - 2.0*(mp_quater[2]*mp_quater[2] + mp_quater[3]*mp_quater[3]);
	mp_euler[2] = atan2(siny_cosp,cosy_cosp);
}

/**
 * [getEulerAngles description]
 */
void ahrs3dm335::getEulerAngles(float euler[3]) {
	for(uint32_t i=0; i<3; i++) {
		euler[i] = mp_euler[i];
	}
}

float ahrs3dm335::getTimeStamp() {
	return mp_timeStamp;
}

// GET GPS

double ahrs3dm335::getGpsTimeStamp() {
	return mp_beaconTimeStamp;
}

/**
 * [getGPSlat description]
 * @return [description]
 */
double ahrs3dm335::getGpsLat() {
	return mp_gpsLat;
}

/**
 * [getGPSlon description]
 * @return [description]
 */
double ahrs3dm335::getGpsLon() {
	return mp_gpsLon;
}

/**
 * [getGPSmsl description]
 * @return [description]
 */
double ahrs3dm335::getGpsMsl() {
	return mp_gpsMsl;
}

/**
 * [getGPSvel description]
 * @return [description]
 */
double ahrs3dm335::getGpsGndVel() {
	return mp_gpsGndVel;
}

void ahrs3dm335::getGpsVelNed(double _vned[3]) {
	for(int i = 0; i < 3; ++i) {
		_vned[i] = mp_gpsVelNed[i];
	}
}

/**
 * [ahrs3dm335::getGpsHeading description]
 * @return [description]
 */
double ahrs3dm335::getGpsHeading() {
	return mp_gpsHeading;
}

// SET ERRORS

/**
 * [getErrFromFile description]
 * @return [description]
 */
bool ahrs3dm335::getErrFromFile() {
	return true;
}

/**
 * [setBiasErrAcc description]
 * @return [description]
 */
bool ahrs3dm335::setBiasErrAcc() {
	return true;
}

/**
 * [ahrs3dm335::setBiasErrGyr description]
 * @return [description]
 */
bool ahrs3dm335::setBiasErrGyr() {
	return true;
}

/**
 * [ahrs3dm335::setScalingErr description]
 * @return [description]
 */
bool ahrs3dm335::setScalingErr() {
	return true;
}

/**
 * [computeCheckSum description]
 */
void ahrs3dm335::computeCheckSum(uint8_t _data[], int32_t _len) {
	uint8_t chkByte1 = 0;
	uint8_t chkByte2 = 0;
	// uint16_t chksum = 0;	// unused
	for(int32_t i = 0; i < _len; ++i) {
		chkByte1 += _data[i];
		chkByte2 += chkByte1;
	}
	mp_chkByte1 = chkByte1;
	mp_chkByte2 = chkByte2;
	printf("BYTE1 0x%02X BYTE2 0x%02X\n",chkByte1,chkByte2);
}

/**
 * [convertBytesToFloat description]
 * @param data [description]
 * @param _len [description]
 */
float ahrs3dm335::convertBytesToFloat(uint8_t _msb, uint8_t _byte2, uint8_t _byte3, uint8_t _lsb) {
	float temp;
	uint8_t byteTemp[4] = {_msb,_byte2,_byte3,_lsb};
	memcpy(&temp,byteTemp,sizeof(temp));
	return temp;
}

/**
 * [ahrs3dm335::convertBytesToFloat description]
 * @param _msb   [description]
 * @param _byte2 [description]
 * @param _byte3 [description]
 * @param _byte4 [description]
 * @param _byte5 [description]
 * @param _byte6 [description]
 * @param _byte7 [description]
 * @param _lsb   [description]
 */
double ahrs3dm335::convertBytesToDouble(uint8_t _msb, uint8_t _byte2, uint8_t _byte3, uint8_t _byte4, uint8_t _byte5, uint8_t _byte6, uint8_t _byte7, uint8_t _lsb) {
	double temp;
	uint8_t byteTemp[8] = {_msb,_byte2,_byte3,_byte4,_byte5,_byte6,_byte7,_lsb};
	memcpy(&temp,byteTemp,sizeof(temp));
	return temp;
}

/**
 * [ahrs3dm335::scanMsg description]
 * @param  data   [description]
 * @param  _fLen  [description]
 * @param  _fdesc [description]
 * @return        head of data - if not found return nullptr
 */
float ahrs3dm335::convertBytesToTime(uint8_t _msb, uint8_t _byte2, uint8_t _byte3, uint8_t _lsb) {
	uint32_t temp;
	uint8_t byteTemp[4] = {_msb,_byte2,_byte3,_lsb};
	memcpy(&temp,byteTemp,sizeof(temp));

	return static_cast<float>(temp)/62500;
}

/**
 * [convertBytesToUint16 description]
 * @param  _msb [description]
 * @param  _lsb [description]
 * @return      [description]
 */
uint16_t ahrs3dm335::convertBytesToUint16(uint8_t _msb, uint8_t _lsb) {
	uint16_t temp;
	uint8_t byteTemp[2] = {_msb,_lsb};
	memcpy(&temp,byteTemp,sizeof(temp));
	return temp;
}

/**
 * [ahrs3dm335::convertBytesToUint32 description]
 * @param  _msb   [description]
 * @param  _byte2 [description]
 * @param  _byte3 [description]
 * @param  _lsb   [description]
 * @return        [description]
 */
uint32_t ahrs3dm335::convertBytesToUint32(uint8_t _msb, uint8_t _byte2, uint8_t _byte3, uint8_t _lsb) {
	uint32_t temp;
	uint8_t byteTemp[4] = {_msb,_byte2,_byte3,_lsb};
	memcpy(&temp,byteTemp,sizeof(temp));
	return temp;
}

/**
 * [ahrs3dm335::scanMsg description]
 * @param  _data  [description]
 * @param  _flen  [description]
 * @param  _fdesc [description]
 * @param  _len   [description]
 * @return        [description]
 */
uint8_t *ahrs3dm335::scanMsg(uint8_t _data[],uint8_t _flen, uint8_t _fdesc, int32_t _len) {
	uint8_t tmp[2] = {0};
	for(int32_t i = 0; i < _len; ++i) {
		tmp[0] = tmp[1];
		tmp[1] = _data[i];
		if(tmp[0] == _flen && tmp[1] == _fdesc) {
			return &_data[i+1];
		}
	}
	return nullptr;
}
