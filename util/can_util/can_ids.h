#ifndef CAN_IDS_H
#define CAN_IDS_H

/****************** SYS/PRIO ******************/

#define CAN_ID_SYS_REQ_ALIVE    0x001

#define CAN_ID_SYS_FCC_ALIVE    0x010
#define CAN_ID_SYS_RAI_ALIVE    0x011
#define CAN_ID_SYS_AHRS_ALIVE   0x012
#define CAN_ID_SYS_AIR_ALIVE    0x013
#define CAN_ID_SYS_GPS_ALIVE    0x014
#define CAN_ID_SYS_PWR_ALIVE    0x015
#define CAN_ID_SYS_TELE_ALIVE   0x016
#define CAN_ID_SYS_LIGHTS_ALIVE 0x017

// #define CAN_ID_SYS_FCC_FAIL
// #define CAN_ID_SYS_RAI_FAIL
// #define CAN_ID_SYS_AHRS_FAIL
// #define CAN_ID_SYS_AIR_FAIL
// #define CAN_ID_SYS_GPS_FAIL
// #define CAN_ID_SYS_PWR_FAIL
// #define CAN_ID_SYS_TELE_FAIL
// #define CAN_ID_SYS_LIGHTS_FAIL


/****************** FCC ******************/
#define CAN_ID_FCC_DATA0     0x130
#define CAN_ID_FCC_DATA1     0x131
#define CAN_ID_FCC_DATA2     0x132
#define CAN_ID_FCC_DATA3     0x133


/****************** RAI ******************/
#define CAN_ID_RAI_DATA0     0x1A0
#define CAN_ID_RAI_DATA1     0x1A1
#define CAN_ID_RAI_DATA2     0x1A2
#define CAN_ID_RAI_DATA3     0x1A3


/****************** AHRS ******************/
#define CAN_ID_AHRS_DATA0    0x200
#define CAN_ID_AHRS_DATA1    0x201
#define CAN_ID_AHRS_DATA2    0x202
#define CAN_ID_AHRS_DATA3    0x203
#define CAN_ID_AHRS_DATA4    0x204
#define CAN_ID_AHRS_DATA5    0x205
#define CAN_ID_AHRS_DATA6    0x206
#define CAN_ID_AHRS_DATA7    0x207


/****************** AIR ******************/
#define CAN_ID_AIR_STATE     0x2BD
#define CAN_ID_AIR_DATA0     0x2C0
#define CAN_ID_AIR_DATA1     0x2C1
#define CAN_ID_AIR_DATA2     0x2C2


/****************** GPS ******************/
#define CAN_ID_GPS_DATA0     0x330
#define CAN_ID_GPS_DATA1     0x331
#define CAN_ID_GPS_DATA2     0x332
#define CAN_ID_GPS_DATA3     0x333
#define CAN_ID_GPS_DATA4     0x334
#define CAN_ID_GPS_DATA5     0x335
#define CAN_ID_GPS_DATA6     0x336
#define CAN_ID_GPS_DATA7     0x337
#define CAN_ID_GPS_DATA8     0x338


/****************** PSU ******************/
#define CAN_ID_PSU_DATA0   0x3F0
#define CAN_ID_PSU_DATA1   0x3F1
#define CAN_ID_PSU_DATA2   0x3F2
#define CAN_ID_PSU_DATA3   0x3F3
#define CAN_ID_PSU_DATA4   0x3F4


/****************** TELE/LOG ******************/


/****************** LIGHTS ******************/


/****************** AUX ******************/


#endif // CAN_IDS_H
