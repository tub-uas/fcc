#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <cstdint>
#include "../driver/drv_serial/drv_serial.h"
#include "../newModules/downlink/mavlink/alxSys/mavlink.h"


drv_serial com;
uint8_t read_message(mavlink_message_t *msg);
int main(void) {

	com.init("/dev/ttyUSB1",B115200);
	mavlink_message_t msg;


	mavlink_status_t status;
	sleep(2);
	while(1) {
		uint8_t rx;
		if(com.receive(&rx,1)) {
			//printf("%02x\n",rx);
		}
		else {
			usleep(1000);
		}

		if(mavlink_parse_char(MAVLINK_COMM_0,rx,&msg,&status)) {
			printf("rx packet SYS: %d, COMP: %d, LEN: %d, MSG ID: %d\n",msg.sysid,msg.compid,msg.len,msg.msgid);
		}

	}

	return 0;
}



uint8_t read_message(mavlink_message_t *msg) {

	uint8_t cp;
	mavlink_status_t status;
	uint8_t msgRx = true;

	uint8_t rx = com.receive(&cp,1);
	if(rx == true) {
		msgRx = mavlink_parse_char(0,cp,msg,&status);
		//printf("msgRx %d",msgRx);
		printf("RX msg from serial ID #%d (sys:%d|comp:%d:\n",msg->msgid,msg->sysid,msg->compid);
	}

	if(msgRx) {
		printf("RX msg from serial ID #%d (sys:%d|comp:%d:\n",msg->msgid,msg->sysid,msg->compid);
		uint8_t buffer[500];
		uint32_t msgLen = mavlink_msg_to_send_buffer(buffer,msg);
		if(msgLen > 500) {
			std::cout << "error msglen" << std::endl;
		} else {
			for(int i = 0; i < msgLen; ++i) {
				uint8_t v = buffer[i];
			}
		}
	}
	return msgRx;

}
