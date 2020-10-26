#include "drv_serial.h"

#include <unistd.h>
#include <cstdio>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <strings.h>

drv_serial::drv_serial() {

}

drv_serial::~drv_serial() {
	if (!vanish()) {
		perror("ERROR: Serial driver destructor failed (vanish)");
	}
}

bool drv_serial::init(const char *_devPath, int32_t _baudRate) {

	mp_devPath  = _devPath;
	mp_baudRate = _baudRate;

	if (access() && config()) {
		return true;
	} else {
		perror("ERROR: Serial driver init failed");
		return false;
	}
}

bool drv_serial::access() {

	mp_fileDesc = open(mp_devPath, O_RDWR|O_NOCTTY);

	if(mp_fileDesc < 0) {
		perror("ERROR: Serial driver cant access (open)");
		return false;
	}
	return true;
}

bool drv_serial::config() {

	tcgetattr(mp_fileDesc, &mp_oldio);
	mp_newio = mp_oldio;

	bzero(&mp_newio,sizeof(serialio_t));

	//set the baud rate
	if (!setBaud()) {
		perror("ERROR: Serial driver cant set baudrate (config)");
		return false;
	}

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
	if (!flushio()) {
		return false;
	}

	//attempt to apply settings
	if(tcsetattr(mp_fileDesc, TCSANOW, &mp_newio) < 0) {
		perror("ERROR: Serial driver cant apply settings (config)");
		return false;
	}
	return true;
}


bool drv_serial::vanish() {

	if (!flushio()) {
		return false;
	}

	if(tcsetattr(mp_fileDesc,TCSANOW,&mp_oldio) < 0) {
		return false;
	}

	if(close(mp_fileDesc) < 0) {
		return false;
	}
	return true;
}


bool drv_serial::send(uint8_t _data[], int32_t _len) {

	if (!flushio()) {
		return false;
	}

	int32_t bytes = write(mp_fileDesc, _data, _len);

	if(bytes != _len) {
		perror("ERROR: Serial driver cant send");
		return false;
	}
	return true;
}

bool drv_serial::receive(uint8_t _data[], int32_t _len) {
	int32_t bytes = read(mp_fileDesc, _data, _len);
	if(bytes != _len) {
		perror("ERROR: Serial driver cant receive");
		return false;
	}
	return true;
}

int32_t drv_serial::getBaudout() {
	return cfgetospeed(&mp_newio);
}

int32_t drv_serial::getBaudin() {
	return cfgetispeed(&mp_newio);
}

bool drv_serial::setBaud() {

	cfsetispeed(&mp_newio,B115200);
	cfsetospeed(&mp_newio,B115200);

	if(getBaudout() != mp_baudRate) {
		return false;
	}

	if(getBaudin() != mp_baudRate) {
		return false;
	}

	return true;
}

bool drv_serial::flushio() {
	if(tcflush(mp_fileDesc,TCIOFLUSH) < 0) {
		perror("ERROR: Serial driver cant flush");
		return false;
	}
	return true;
}
