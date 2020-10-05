/**
 * @Author: Arnold Freitas
 * @Date:   2019-07-09
 * @Last modified by:   Arnold Freitas
 * @Last modified time: 2019-08-12
 */

#include "encoder.h"


// for RUNTIME TESTS use following function inside function "telemetry_run"
/*void creat_random_global_values_runtime(void){
	// this function define randome values for global variables
	double pi = 3.1415926535;
	global_IAS = (float)(rand()) / ((float)(RAND_MAX/250));
	global_GND_s = (float)(rand()) / ((float)(RAND_MAX/250));
	global_Latitude = (double)(rand()) / ((double)(RAND_MAX/pi));
	global_Longitude = (double)(rand()) / ((double)(RAND_MAX/(2*pi)));
	global_Altitude_Baro = (float)(rand()) / ((float)(RAND_MAX/1000));
	global_Vspeed = (float)(rand()) / ((float)(RAND_MAX/250));
	global_Pitch = (float)(rand()) / ((float)(RAND_MAX/(pi/2)));
	global_Roll = (float)(rand()) / ((float)(RAND_MAX/(pi/2)));
	global_Heading = (float)(rand()) / ((float)(RAND_MAX/(2*pi)));
	global_FlightTime = (double)(rand()) / ((double)(RAND_MAX/10000));
}*/

// PORT SETTINGS PART
// Identify the port which contains the FTDI_FT230X_Basic_UART radio reciever
const char * encoder_identify_usb(void){

	FILE *fp; // File Variable for Linux Skript
	char path[1035]; // variable to save outputs of Linux Skript
	const char *comp1 = "FTDI_FT230X_Basic_UART"; // String for Comparison
	const char *comp2 = "/dev/tty"; // String for Comparison
	char  dev[13]; // String to save after output of skript
	int16_t i; // index of char to analise output of skript

	// Execute the bash skript to return all usb port status
	fp = popen("sh identify_usb", "r");
	if (fp == NULL) {
		printf("Failed to run command\n" );
		exit(1);
	}
	// Beispiel /dev/ttyUSB0 - FTDI_FT230X_Basic_UART_DN04JCR4

	/* Read the output a line at a time - output it*/
	while (fgets(path, sizeof(path)-1, fp) != NULL) {
		// Compare the output of skript with comparison strings
		if ((strstr(path, comp1) != NULL) && (strstr(path, comp2) != NULL)){
				printf("%s\n", path);
				// save the path of device to dev
				for (i = 0; i < sizeof(path)-1; i++){
					if (path[i] == ' '){
						break;
					}else {
							dev[i] = path[i];
					}
				}
		}
	}

	// save dev to output
	const char * ret_dev = dev;
	/* close */
	pclose(fp);

	return ret_dev;
}

int16_t encoder_open_device(const char * device){

	int16_t fd = open(device, O_RDWR | O_NOCTTY | O_NDELAY); // init port
	// analise if port was open
	if (fd == -1) {
		printf("Error! Port: %s could not be open. Error: %s\n",device, strerror(errno));
		return -1;
	}
	printf("%s open succesfully!\n", device);

	return fd;
}

int16_t port_config(int16_t  fd){
	struct termios SerialPortSettings;
	tcgetattr(fd, &SerialPortSettings);

	SerialPortSettings.c_cflag &= ~PARENB; // Clear parity bit, disabling parity (most common)
	SerialPortSettings.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication (most common)
	SerialPortSettings.c_cflag |= CS8; // 8 bits per byte (most common)
	SerialPortSettings.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control (most common)
	SerialPortSettings.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)

	SerialPortSettings.c_lflag &= ~ICANON;
	SerialPortSettings.c_lflag &= ~ECHO; // Disable echo
	SerialPortSettings.c_lflag &= ~ECHOE; // Disable erasure
	SerialPortSettings.c_lflag &= ~ECHONL; // Disable new-line echo
	SerialPortSettings.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP

	SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
	SerialPortSettings.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes

	cfmakeraw(&SerialPortSettings);

	SerialPortSettings.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
	SerialPortSettings.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed

	// Set in/out baud rate to be 57600
	cfsetispeed(&SerialPortSettings, B57600);
	cfsetospeed(&SerialPortSettings, B57600);

	tcflush(fd, TCIOFLUSH); // clean buffer before use
	tcsetattr(fd,TCSANOW,&SerialPortSettings);   // set new attributs

	if((tcsetattr(fd,TCSANOW,&SerialPortSettings)) != 0){ /* Set the attributes to the termios structure*/
			/* Check if attributes were set*/
		printf("\n  ERROR ! in Setting attributes");
		return -1;
	}else{
		printf("\n  BaudRate = 57600 \n  StopBits = 1 \n  Parity   = none\n");
			return 0;
	}
}

// based on crc16 CCITT code
uint16_t Checksum(message_t this_message){
 /* Set Data Parity */
 unsigned char x;
 unsigned short crc = 0xFFFF; // HEX reference to checksum to 65535
 // make sure that all bits in crc are equal "1"
 unsigned char * data;
 uint16_t length;

 data = (unsigned char *)&this_message.this_message_ID;
 length = 16; // Fix data size
 while (length--){ // iteration to length of message_ID
	 x = crc >> 8 ^ *data++;
	 x ^= x>>4;
	 crc = (crc << 8) ^ ((unsigned short)(x << 12)) ^ ((unsigned short)(x <<5)) ^ ((unsigned short)x);
	}

 data = (unsigned char *)&this_message.this_IAS;
 length = 32; // Fix data size
 while (length--){
	 x = crc >> 8 ^ *data++;
	 x ^= x>>4;
	 crc = (crc << 8) ^ ((unsigned short)(x << 12)) ^ ((unsigned short)(x <<5)) ^ ((unsigned short)x);
	}

	data = (unsigned char *)&this_message.this_GND_s;
	length = 32; // Fix data size
	while (length--){
		x = crc >> 8 ^ *data++;
		x ^= x>>4;
		crc = (crc << 8) ^ ((unsigned short)(x << 12)) ^ ((unsigned short)(x <<5)) ^ ((unsigned short)x);
	 }

 return crc;
}

void write_message(int16_t fd, message_t this_message){
	int n_written = 0; // vairable for written bytes in buffer
	message_t * buff; // define variable for buffer
	buff = &this_message; // set buffer equals message
	int16_t len = sizeof(this_message); // define length of message

			n_written = write( fd, buff, 66); // write message to device
			printf("%d %f %f %f %lf %lf %f %f %f %f %lf %d\n",this_message.this_message_ID,
			this_message.this_IAS, this_message.this_GND_s,
				 this_message.this_Latitude,
				 this_message.this_Longitude,
				 this_message.this_Altitude_Baro,
				 this_message.this_Vspeed,
				 this_message.this_Pitch,
				 this_message.this_Roll,
				 this_message.this_Heading,
				 this_message.this_FlightTime,
				 this_message.this_CS_parity);
			// printf("%d  %d\n\n",n_written, len);
}

void telemetry_run(int16_t fd, message_t this_message){

	int16_t i = 0; // set variable for index
	float32_t process_time; // variable time to process one iteration
	clock_t now_t, end_t; // variable time to calc bagin and end of iteration

	now_t = clock(); // get clock at begin of loop processing
	// creat_random_global_values_runtime(); //for runtime test only
	write_message(fd, this_message); // send message
	i++; // add to define next message id
	end_t = clock(); // get clock at end of loop processing
	process_time = (float32_t)((end_t - now_t)); // Calculate time for processing loop
	// printf("%f\n",process_time ); // uncomment to see Calculated time-delay
	usleep(fabs(200000-process_time)); // Calculate time delay and sleep before next loop

}

// MAIN
/* int main(int argc, char const *argv[]) {
	char * device; //device = "/dev/ttyUSB1"; // for tests reasons
	int16_t fd;

	// device = encoder_identify_usb();
	device = "/dev/ttyUSB1"; // for tests reasons
	fd =encoder_open_device(device); // open device
	port_config(fd); // CONFIG PORT

	telemtetry_run(fd); // send messages


	close(fd); // close device
	return 0;
}*/
