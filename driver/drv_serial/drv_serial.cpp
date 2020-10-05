#include <unistd.h>
#include <cstdio>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <strings.h>

#include "drv_serial.h"


drv_serial::drv_serial() {

}

/**
 * [drv_serial description]
 */
drv_serial::~drv_serial() {
	vanish();
}

/**
 * [init description]
 * @param  _devPath [description]
 * @param  baudRate [description]
 * @return          [description]
 */
bool drv_serial::init(const char *_devPath, int32_t _baudRate) {

	mp_devPath  = _devPath;
	mp_baudRate = _baudRate;
	if(access()) {
		if(config()) {
			return true;
		}
		return false;
	}
	return false;
}

/**
 * [open description]
 * @return [description]
 */
bool drv_serial::access() {
	mp_fileDesc = open(mp_devPath, O_RDWR|O_NOCTTY);
	if(mp_fileDesc < 0) {
		printf("open failed\n");
		errorHandler(ERR_OPEN);
		return false;
	}
	return true;
}

bool drv_serial::config() {

	tcgetattr(mp_fileDesc, &mp_oldio);
	mp_newio = mp_oldio;

	bzero(&mp_newio,sizeof(serialio_t));
	//set the baud rate
	if(!setBaud()) {
		printf("set baudrate failed\n");
	};


	//set the number of data bits.
	mp_newio.c_cflag &= ~CSIZE; // Mask the character size bits
	mp_newio.c_cflag |= CS8;

	//set the number of stop bits to 1
	mp_newio.c_cflag &= ~CSTOPB;

	//Set parity to None
	mp_newio.c_cflag &=~PARENB;

	//set for non-canonical (raw processing, no echo, etc.)
	mp_newio.c_iflag = IGNPAR; // ignore parity check close_port(int
		mp_newio.c_oflag = 0; // raw output
		mp_newio.c_lflag = 0; // raw input

		//Time-Outs -- won't work with NDELAY option in the call to open
		mp_newio.c_cc[VMIN] = 0;  // block reading until RX x characers. If x = 0,
		// it is non-blocking.
		mp_newio.c_cc[VTIME] = 1;  // Inter-Character Timer -- i.e. timeout= x*.1 s

		//Set local mode and enable the receiver
		mp_newio.c_cflag |= (CLOCAL | CREAD);

		//purge serial port buffers
		flushio();
		//attempt to apply settings
		if(tcsetattr(mp_fileDesc, TCSANOW, &mp_newio) < 0) {
			return false;
		}
		return true;

}

/**
 * [close description]
 * @return [description]
 */
bool drv_serial::vanish() {

	flushio();
	if(tcsetattr(mp_fileDesc,TCSANOW,&mp_oldio) < 0) {
		return false;
	}

	if(close(mp_fileDesc) < 0) {
		return false;
	}
	return true;
}

/**
 * [send description]
 * @param  _data [description]
 * @param  _len  [description]
 * @return       [description]
 */
bool drv_serial::send(uint8_t _data[], int32_t _len) {
	flushio();
	int32_t bytes = write(mp_fileDesc, _data, _len);
	
	if(bytes != _len) {
		printf("bytes %d len %d\n",bytes,_len);
		return false;
	}
	return true;

}

/**
 * [read description]
 * @param  _data [description]
 * @param  _len  [description]
 * @return       [description]
 */
bool drv_serial::receive(uint8_t _data[], int32_t _len) {
	int32_t bytes = read(mp_fileDesc, _data, _len);
	if(bytes != _len) {
		return false;
	}
	return true;
}

/**
 * [drv_serial::getBaud description]
 * @return [description]
 */
int32_t drv_serial::getBaudout() {

	return cfgetospeed(&mp_newio);
}

int32_t drv_serial::getBaudin() {

	return cfgetispeed(&mp_newio);
}
/**
 * [drv_serial::setBaud description]
 * @return [description]
 */
bool drv_serial::setBaud() {

	cfsetispeed(&mp_newio,B115200);
	cfsetospeed(&mp_newio,B115200);
	if(getBaudout() != mp_baudRate) {
		errorHandler(ERR_SETBAUD);
		return false;
	}
	if(getBaudin() != mp_baudRate) {
		errorHandler(ERR_SETBAUD);
		return false;
	}
	return true;

}

/**
 * [drv_serial::flushio description]
 */
void drv_serial::flushio() {
	if(tcflush(mp_fileDesc,TCIOFLUSH) < 0) {
		errorHandler(ERR_IOFLUSH);
	}
}

void drv_serial::errorHandler(int32_t _errorCode) {
	switch (_errorCode) {
		case ERR_OPEN:

		break;
		case ERR_GETBAUD:

		break;

		case ERR_SETBAUD:

		break;

		case ERR_IOFLUSH:

		break;

		default:

		break;
	}
}
