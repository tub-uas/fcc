#ifndef CAN_META_H
#define CAN_META_H

/****************** SYS/PRIO ******************/


/****************** FCC ******************/
// See RAI for meta data info. RAI and FCC share the same protocol and therefore
// also share their meta data info.

/****************** RAI ******************/
#define CAN_META_RAI_MSG_NUM      4
#define CAN_META_RAI_CHNL_NUM     12
#define CAN_META_RAI_CHNL_PER_MSG 4


/****************** AHRS ******************/
#define CAN_META_AHRS_MSG_NUM  8
#define CAN_META_AHRS_AXIS_NUM 3


/****************** AIR ******************/
#define CAN_META_AIR_MSG_NUM 3

/****************** GPS ******************/


/****************** PSU ******************/
#define CAN_META_PSU_MSG_NUM 5


/****************** TELE/LOG ******************/


/****************** LIGHTS ******************/


/****************** AUX ******************/


#endif // CAN_META_H
