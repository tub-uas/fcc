#pragma once
// MESSAGE DataSFusion PACKING

#define MAVLINK_MSG_ID_DataSFusion 40000


typedef struct __mavlink_datasfusion_t {
 uint64_t time; /*<  System time at publication*/
 float senseTime; /*<  Time of data creation at sensor*/
 float gyrX; /*<  Gyro X-Axis*/
 float gyrY; /*<  Gyro Y-Axis*/
 float gyrZ; /*<  Gyro Z-Axis*/
 float accX; /*<  Accelerometer X-Axis*/
 float accY; /*<  Accelerometer Y-Axis*/
 float accZ; /*<  Accelerometer Z-Axis*/
 float magX; /*<  Magnetometer X-Axis*/
 float magY; /*<  Magnetometer Y-Axis*/
 float magZ; /*<  Magnetometer Z-Axis*/
 float temp; /*<  Temperature*/
 float press; /*<  Barometric pressure*/
 float phi; /*<  Phi*/
 float the; /*<  Theta*/
 float psi; /*<  Psi*/
 float q0; /*<  Quaternion 0*/
 float q1; /*<  Quaternion 1*/
 float q2; /*<  Quaternion 2*/
 float q3; /*<  Quaternion 3*/
 float posN; /*<  Position north estimation*/
 float posE; /*<  Position east estimation*/
 float posD; /*<  Position down estimation*/
 float speedN; /*<  Speed north estimation*/
 float speedE; /*<  Speed east estimation*/
 float speedD; /*<  Speed down estimation*/
 float WindN; /*<  Wind north estimation*/
 float WindE; /*<  Wind east estimation*/
 float WindD; /*<  Wind down estimation*/
 float ssa; /*<  Sideslip angle estimation*/
 float aoa; /*<  Angle of attack estimation*/
 float gamma; /*<  Pathangle estimation*/
 uint8_t alive; /*<  Is message valid?*/
} mavlink_datasfusion_t;

#define MAVLINK_MSG_ID_DataSFusion_LEN 133
#define MAVLINK_MSG_ID_DataSFusion_MIN_LEN 133
#define MAVLINK_MSG_ID_40000_LEN 133
#define MAVLINK_MSG_ID_40000_MIN_LEN 133

#define MAVLINK_MSG_ID_DataSFusion_CRC 36
#define MAVLINK_MSG_ID_40000_CRC 36



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DataSFusion { \
    40000, \
    "DataSFusion", \
    33, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_datasfusion_t, time) }, \
         { "senseTime", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_datasfusion_t, senseTime) }, \
         { "gyrX", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_datasfusion_t, gyrX) }, \
         { "gyrY", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_datasfusion_t, gyrY) }, \
         { "gyrZ", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_datasfusion_t, gyrZ) }, \
         { "accX", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_datasfusion_t, accX) }, \
         { "accY", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_datasfusion_t, accY) }, \
         { "accZ", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_datasfusion_t, accZ) }, \
         { "magX", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_datasfusion_t, magX) }, \
         { "magY", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_datasfusion_t, magY) }, \
         { "magZ", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_datasfusion_t, magZ) }, \
         { "temp", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_datasfusion_t, temp) }, \
         { "press", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_datasfusion_t, press) }, \
         { "phi", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_datasfusion_t, phi) }, \
         { "the", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_datasfusion_t, the) }, \
         { "psi", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_datasfusion_t, psi) }, \
         { "q0", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_datasfusion_t, q0) }, \
         { "q1", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_datasfusion_t, q1) }, \
         { "q2", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_datasfusion_t, q2) }, \
         { "q3", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_datasfusion_t, q3) }, \
         { "posN", NULL, MAVLINK_TYPE_FLOAT, 0, 84, offsetof(mavlink_datasfusion_t, posN) }, \
         { "posE", NULL, MAVLINK_TYPE_FLOAT, 0, 88, offsetof(mavlink_datasfusion_t, posE) }, \
         { "posD", NULL, MAVLINK_TYPE_FLOAT, 0, 92, offsetof(mavlink_datasfusion_t, posD) }, \
         { "speedN", NULL, MAVLINK_TYPE_FLOAT, 0, 96, offsetof(mavlink_datasfusion_t, speedN) }, \
         { "speedE", NULL, MAVLINK_TYPE_FLOAT, 0, 100, offsetof(mavlink_datasfusion_t, speedE) }, \
         { "speedD", NULL, MAVLINK_TYPE_FLOAT, 0, 104, offsetof(mavlink_datasfusion_t, speedD) }, \
         { "WindN", NULL, MAVLINK_TYPE_FLOAT, 0, 108, offsetof(mavlink_datasfusion_t, WindN) }, \
         { "WindE", NULL, MAVLINK_TYPE_FLOAT, 0, 112, offsetof(mavlink_datasfusion_t, WindE) }, \
         { "WindD", NULL, MAVLINK_TYPE_FLOAT, 0, 116, offsetof(mavlink_datasfusion_t, WindD) }, \
         { "ssa", NULL, MAVLINK_TYPE_FLOAT, 0, 120, offsetof(mavlink_datasfusion_t, ssa) }, \
         { "aoa", NULL, MAVLINK_TYPE_FLOAT, 0, 124, offsetof(mavlink_datasfusion_t, aoa) }, \
         { "gamma", NULL, MAVLINK_TYPE_FLOAT, 0, 128, offsetof(mavlink_datasfusion_t, gamma) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 132, offsetof(mavlink_datasfusion_t, alive) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DataSFusion { \
    "DataSFusion", \
    33, \
    {  { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_datasfusion_t, time) }, \
         { "senseTime", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_datasfusion_t, senseTime) }, \
         { "gyrX", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_datasfusion_t, gyrX) }, \
         { "gyrY", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_datasfusion_t, gyrY) }, \
         { "gyrZ", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_datasfusion_t, gyrZ) }, \
         { "accX", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_datasfusion_t, accX) }, \
         { "accY", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_datasfusion_t, accY) }, \
         { "accZ", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_datasfusion_t, accZ) }, \
         { "magX", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_datasfusion_t, magX) }, \
         { "magY", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_datasfusion_t, magY) }, \
         { "magZ", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_datasfusion_t, magZ) }, \
         { "temp", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_datasfusion_t, temp) }, \
         { "press", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_datasfusion_t, press) }, \
         { "phi", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_datasfusion_t, phi) }, \
         { "the", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_datasfusion_t, the) }, \
         { "psi", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_datasfusion_t, psi) }, \
         { "q0", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_datasfusion_t, q0) }, \
         { "q1", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_datasfusion_t, q1) }, \
         { "q2", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_datasfusion_t, q2) }, \
         { "q3", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_datasfusion_t, q3) }, \
         { "posN", NULL, MAVLINK_TYPE_FLOAT, 0, 84, offsetof(mavlink_datasfusion_t, posN) }, \
         { "posE", NULL, MAVLINK_TYPE_FLOAT, 0, 88, offsetof(mavlink_datasfusion_t, posE) }, \
         { "posD", NULL, MAVLINK_TYPE_FLOAT, 0, 92, offsetof(mavlink_datasfusion_t, posD) }, \
         { "speedN", NULL, MAVLINK_TYPE_FLOAT, 0, 96, offsetof(mavlink_datasfusion_t, speedN) }, \
         { "speedE", NULL, MAVLINK_TYPE_FLOAT, 0, 100, offsetof(mavlink_datasfusion_t, speedE) }, \
         { "speedD", NULL, MAVLINK_TYPE_FLOAT, 0, 104, offsetof(mavlink_datasfusion_t, speedD) }, \
         { "WindN", NULL, MAVLINK_TYPE_FLOAT, 0, 108, offsetof(mavlink_datasfusion_t, WindN) }, \
         { "WindE", NULL, MAVLINK_TYPE_FLOAT, 0, 112, offsetof(mavlink_datasfusion_t, WindE) }, \
         { "WindD", NULL, MAVLINK_TYPE_FLOAT, 0, 116, offsetof(mavlink_datasfusion_t, WindD) }, \
         { "ssa", NULL, MAVLINK_TYPE_FLOAT, 0, 120, offsetof(mavlink_datasfusion_t, ssa) }, \
         { "aoa", NULL, MAVLINK_TYPE_FLOAT, 0, 124, offsetof(mavlink_datasfusion_t, aoa) }, \
         { "gamma", NULL, MAVLINK_TYPE_FLOAT, 0, 128, offsetof(mavlink_datasfusion_t, gamma) }, \
         { "alive", NULL, MAVLINK_TYPE_UINT8_T, 0, 132, offsetof(mavlink_datasfusion_t, alive) }, \
         } \
}
#endif

/**
 * @brief Pack a datasfusion message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time  System time at publication
 * @param senseTime  Time of data creation at sensor
 * @param gyrX  Gyro X-Axis
 * @param gyrY  Gyro Y-Axis
 * @param gyrZ  Gyro Z-Axis
 * @param accX  Accelerometer X-Axis
 * @param accY  Accelerometer Y-Axis
 * @param accZ  Accelerometer Z-Axis
 * @param magX  Magnetometer X-Axis
 * @param magY  Magnetometer Y-Axis
 * @param magZ  Magnetometer Z-Axis
 * @param temp  Temperature
 * @param press  Barometric pressure
 * @param phi  Phi
 * @param the  Theta
 * @param psi  Psi
 * @param q0  Quaternion 0
 * @param q1  Quaternion 1
 * @param q2  Quaternion 2
 * @param q3  Quaternion 3
 * @param posN  Position north estimation
 * @param posE  Position east estimation
 * @param posD  Position down estimation
 * @param speedN  Speed north estimation
 * @param speedE  Speed east estimation
 * @param speedD  Speed down estimation
 * @param WindN  Wind north estimation
 * @param WindE  Wind east estimation
 * @param WindD  Wind down estimation
 * @param ssa  Sideslip angle estimation
 * @param aoa  Angle of attack estimation
 * @param gamma  Pathangle estimation
 * @param alive  Is message valid?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_datasfusion_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time, float senseTime, float gyrX, float gyrY, float gyrZ, float accX, float accY, float accZ, float magX, float magY, float magZ, float temp, float press, float phi, float the, float psi, float q0, float q1, float q2, float q3, float posN, float posE, float posD, float speedN, float speedE, float speedD, float WindN, float WindE, float WindD, float ssa, float aoa, float gamma, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataSFusion_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, gyrX);
    _mav_put_float(buf, 16, gyrY);
    _mav_put_float(buf, 20, gyrZ);
    _mav_put_float(buf, 24, accX);
    _mav_put_float(buf, 28, accY);
    _mav_put_float(buf, 32, accZ);
    _mav_put_float(buf, 36, magX);
    _mav_put_float(buf, 40, magY);
    _mav_put_float(buf, 44, magZ);
    _mav_put_float(buf, 48, temp);
    _mav_put_float(buf, 52, press);
    _mav_put_float(buf, 56, phi);
    _mav_put_float(buf, 60, the);
    _mav_put_float(buf, 64, psi);
    _mav_put_float(buf, 68, q0);
    _mav_put_float(buf, 72, q1);
    _mav_put_float(buf, 76, q2);
    _mav_put_float(buf, 80, q3);
    _mav_put_float(buf, 84, posN);
    _mav_put_float(buf, 88, posE);
    _mav_put_float(buf, 92, posD);
    _mav_put_float(buf, 96, speedN);
    _mav_put_float(buf, 100, speedE);
    _mav_put_float(buf, 104, speedD);
    _mav_put_float(buf, 108, WindN);
    _mav_put_float(buf, 112, WindE);
    _mav_put_float(buf, 116, WindD);
    _mav_put_float(buf, 120, ssa);
    _mav_put_float(buf, 124, aoa);
    _mav_put_float(buf, 128, gamma);
    _mav_put_uint8_t(buf, 132, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataSFusion_LEN);
#else
    mavlink_datasfusion_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.gyrX = gyrX;
    packet.gyrY = gyrY;
    packet.gyrZ = gyrZ;
    packet.accX = accX;
    packet.accY = accY;
    packet.accZ = accZ;
    packet.magX = magX;
    packet.magY = magY;
    packet.magZ = magZ;
    packet.temp = temp;
    packet.press = press;
    packet.phi = phi;
    packet.the = the;
    packet.psi = psi;
    packet.q0 = q0;
    packet.q1 = q1;
    packet.q2 = q2;
    packet.q3 = q3;
    packet.posN = posN;
    packet.posE = posE;
    packet.posD = posD;
    packet.speedN = speedN;
    packet.speedE = speedE;
    packet.speedD = speedD;
    packet.WindN = WindN;
    packet.WindE = WindE;
    packet.WindD = WindD;
    packet.ssa = ssa;
    packet.aoa = aoa;
    packet.gamma = gamma;
    packet.alive = alive;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataSFusion_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataSFusion;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DataSFusion_MIN_LEN, MAVLINK_MSG_ID_DataSFusion_LEN, MAVLINK_MSG_ID_DataSFusion_CRC);
}

/**
 * @brief Pack a datasfusion message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time  System time at publication
 * @param senseTime  Time of data creation at sensor
 * @param gyrX  Gyro X-Axis
 * @param gyrY  Gyro Y-Axis
 * @param gyrZ  Gyro Z-Axis
 * @param accX  Accelerometer X-Axis
 * @param accY  Accelerometer Y-Axis
 * @param accZ  Accelerometer Z-Axis
 * @param magX  Magnetometer X-Axis
 * @param magY  Magnetometer Y-Axis
 * @param magZ  Magnetometer Z-Axis
 * @param temp  Temperature
 * @param press  Barometric pressure
 * @param phi  Phi
 * @param the  Theta
 * @param psi  Psi
 * @param q0  Quaternion 0
 * @param q1  Quaternion 1
 * @param q2  Quaternion 2
 * @param q3  Quaternion 3
 * @param posN  Position north estimation
 * @param posE  Position east estimation
 * @param posD  Position down estimation
 * @param speedN  Speed north estimation
 * @param speedE  Speed east estimation
 * @param speedD  Speed down estimation
 * @param WindN  Wind north estimation
 * @param WindE  Wind east estimation
 * @param WindD  Wind down estimation
 * @param ssa  Sideslip angle estimation
 * @param aoa  Angle of attack estimation
 * @param gamma  Pathangle estimation
 * @param alive  Is message valid?
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_datasfusion_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time,float senseTime,float gyrX,float gyrY,float gyrZ,float accX,float accY,float accZ,float magX,float magY,float magZ,float temp,float press,float phi,float the,float psi,float q0,float q1,float q2,float q3,float posN,float posE,float posD,float speedN,float speedE,float speedD,float WindN,float WindE,float WindD,float ssa,float aoa,float gamma,uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataSFusion_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, gyrX);
    _mav_put_float(buf, 16, gyrY);
    _mav_put_float(buf, 20, gyrZ);
    _mav_put_float(buf, 24, accX);
    _mav_put_float(buf, 28, accY);
    _mav_put_float(buf, 32, accZ);
    _mav_put_float(buf, 36, magX);
    _mav_put_float(buf, 40, magY);
    _mav_put_float(buf, 44, magZ);
    _mav_put_float(buf, 48, temp);
    _mav_put_float(buf, 52, press);
    _mav_put_float(buf, 56, phi);
    _mav_put_float(buf, 60, the);
    _mav_put_float(buf, 64, psi);
    _mav_put_float(buf, 68, q0);
    _mav_put_float(buf, 72, q1);
    _mav_put_float(buf, 76, q2);
    _mav_put_float(buf, 80, q3);
    _mav_put_float(buf, 84, posN);
    _mav_put_float(buf, 88, posE);
    _mav_put_float(buf, 92, posD);
    _mav_put_float(buf, 96, speedN);
    _mav_put_float(buf, 100, speedE);
    _mav_put_float(buf, 104, speedD);
    _mav_put_float(buf, 108, WindN);
    _mav_put_float(buf, 112, WindE);
    _mav_put_float(buf, 116, WindD);
    _mav_put_float(buf, 120, ssa);
    _mav_put_float(buf, 124, aoa);
    _mav_put_float(buf, 128, gamma);
    _mav_put_uint8_t(buf, 132, alive);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DataSFusion_LEN);
#else
    mavlink_datasfusion_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.gyrX = gyrX;
    packet.gyrY = gyrY;
    packet.gyrZ = gyrZ;
    packet.accX = accX;
    packet.accY = accY;
    packet.accZ = accZ;
    packet.magX = magX;
    packet.magY = magY;
    packet.magZ = magZ;
    packet.temp = temp;
    packet.press = press;
    packet.phi = phi;
    packet.the = the;
    packet.psi = psi;
    packet.q0 = q0;
    packet.q1 = q1;
    packet.q2 = q2;
    packet.q3 = q3;
    packet.posN = posN;
    packet.posE = posE;
    packet.posD = posD;
    packet.speedN = speedN;
    packet.speedE = speedE;
    packet.speedD = speedD;
    packet.WindN = WindN;
    packet.WindE = WindE;
    packet.WindD = WindD;
    packet.ssa = ssa;
    packet.aoa = aoa;
    packet.gamma = gamma;
    packet.alive = alive;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DataSFusion_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DataSFusion;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DataSFusion_MIN_LEN, MAVLINK_MSG_ID_DataSFusion_LEN, MAVLINK_MSG_ID_DataSFusion_CRC);
}

/**
 * @brief Encode a datasfusion struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param datasfusion C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_datasfusion_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_datasfusion_t* datasfusion)
{
    return mavlink_msg_datasfusion_pack(system_id, component_id, msg, datasfusion->time, datasfusion->senseTime, datasfusion->gyrX, datasfusion->gyrY, datasfusion->gyrZ, datasfusion->accX, datasfusion->accY, datasfusion->accZ, datasfusion->magX, datasfusion->magY, datasfusion->magZ, datasfusion->temp, datasfusion->press, datasfusion->phi, datasfusion->the, datasfusion->psi, datasfusion->q0, datasfusion->q1, datasfusion->q2, datasfusion->q3, datasfusion->posN, datasfusion->posE, datasfusion->posD, datasfusion->speedN, datasfusion->speedE, datasfusion->speedD, datasfusion->WindN, datasfusion->WindE, datasfusion->WindD, datasfusion->ssa, datasfusion->aoa, datasfusion->gamma, datasfusion->alive);
}

/**
 * @brief Encode a datasfusion struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param datasfusion C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_datasfusion_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_datasfusion_t* datasfusion)
{
    return mavlink_msg_datasfusion_pack_chan(system_id, component_id, chan, msg, datasfusion->time, datasfusion->senseTime, datasfusion->gyrX, datasfusion->gyrY, datasfusion->gyrZ, datasfusion->accX, datasfusion->accY, datasfusion->accZ, datasfusion->magX, datasfusion->magY, datasfusion->magZ, datasfusion->temp, datasfusion->press, datasfusion->phi, datasfusion->the, datasfusion->psi, datasfusion->q0, datasfusion->q1, datasfusion->q2, datasfusion->q3, datasfusion->posN, datasfusion->posE, datasfusion->posD, datasfusion->speedN, datasfusion->speedE, datasfusion->speedD, datasfusion->WindN, datasfusion->WindE, datasfusion->WindD, datasfusion->ssa, datasfusion->aoa, datasfusion->gamma, datasfusion->alive);
}

/**
 * @brief Send a datasfusion message
 * @param chan MAVLink channel to send the message
 *
 * @param time  System time at publication
 * @param senseTime  Time of data creation at sensor
 * @param gyrX  Gyro X-Axis
 * @param gyrY  Gyro Y-Axis
 * @param gyrZ  Gyro Z-Axis
 * @param accX  Accelerometer X-Axis
 * @param accY  Accelerometer Y-Axis
 * @param accZ  Accelerometer Z-Axis
 * @param magX  Magnetometer X-Axis
 * @param magY  Magnetometer Y-Axis
 * @param magZ  Magnetometer Z-Axis
 * @param temp  Temperature
 * @param press  Barometric pressure
 * @param phi  Phi
 * @param the  Theta
 * @param psi  Psi
 * @param q0  Quaternion 0
 * @param q1  Quaternion 1
 * @param q2  Quaternion 2
 * @param q3  Quaternion 3
 * @param posN  Position north estimation
 * @param posE  Position east estimation
 * @param posD  Position down estimation
 * @param speedN  Speed north estimation
 * @param speedE  Speed east estimation
 * @param speedD  Speed down estimation
 * @param WindN  Wind north estimation
 * @param WindE  Wind east estimation
 * @param WindD  Wind down estimation
 * @param ssa  Sideslip angle estimation
 * @param aoa  Angle of attack estimation
 * @param gamma  Pathangle estimation
 * @param alive  Is message valid?
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_datasfusion_send(mavlink_channel_t chan, uint64_t time, float senseTime, float gyrX, float gyrY, float gyrZ, float accX, float accY, float accZ, float magX, float magY, float magZ, float temp, float press, float phi, float the, float psi, float q0, float q1, float q2, float q3, float posN, float posE, float posD, float speedN, float speedE, float speedD, float WindN, float WindE, float WindD, float ssa, float aoa, float gamma, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DataSFusion_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, gyrX);
    _mav_put_float(buf, 16, gyrY);
    _mav_put_float(buf, 20, gyrZ);
    _mav_put_float(buf, 24, accX);
    _mav_put_float(buf, 28, accY);
    _mav_put_float(buf, 32, accZ);
    _mav_put_float(buf, 36, magX);
    _mav_put_float(buf, 40, magY);
    _mav_put_float(buf, 44, magZ);
    _mav_put_float(buf, 48, temp);
    _mav_put_float(buf, 52, press);
    _mav_put_float(buf, 56, phi);
    _mav_put_float(buf, 60, the);
    _mav_put_float(buf, 64, psi);
    _mav_put_float(buf, 68, q0);
    _mav_put_float(buf, 72, q1);
    _mav_put_float(buf, 76, q2);
    _mav_put_float(buf, 80, q3);
    _mav_put_float(buf, 84, posN);
    _mav_put_float(buf, 88, posE);
    _mav_put_float(buf, 92, posD);
    _mav_put_float(buf, 96, speedN);
    _mav_put_float(buf, 100, speedE);
    _mav_put_float(buf, 104, speedD);
    _mav_put_float(buf, 108, WindN);
    _mav_put_float(buf, 112, WindE);
    _mav_put_float(buf, 116, WindD);
    _mav_put_float(buf, 120, ssa);
    _mav_put_float(buf, 124, aoa);
    _mav_put_float(buf, 128, gamma);
    _mav_put_uint8_t(buf, 132, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataSFusion, buf, MAVLINK_MSG_ID_DataSFusion_MIN_LEN, MAVLINK_MSG_ID_DataSFusion_LEN, MAVLINK_MSG_ID_DataSFusion_CRC);
#else
    mavlink_datasfusion_t packet;
    packet.time = time;
    packet.senseTime = senseTime;
    packet.gyrX = gyrX;
    packet.gyrY = gyrY;
    packet.gyrZ = gyrZ;
    packet.accX = accX;
    packet.accY = accY;
    packet.accZ = accZ;
    packet.magX = magX;
    packet.magY = magY;
    packet.magZ = magZ;
    packet.temp = temp;
    packet.press = press;
    packet.phi = phi;
    packet.the = the;
    packet.psi = psi;
    packet.q0 = q0;
    packet.q1 = q1;
    packet.q2 = q2;
    packet.q3 = q3;
    packet.posN = posN;
    packet.posE = posE;
    packet.posD = posD;
    packet.speedN = speedN;
    packet.speedE = speedE;
    packet.speedD = speedD;
    packet.WindN = WindN;
    packet.WindE = WindE;
    packet.WindD = WindD;
    packet.ssa = ssa;
    packet.aoa = aoa;
    packet.gamma = gamma;
    packet.alive = alive;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataSFusion, (const char *)&packet, MAVLINK_MSG_ID_DataSFusion_MIN_LEN, MAVLINK_MSG_ID_DataSFusion_LEN, MAVLINK_MSG_ID_DataSFusion_CRC);
#endif
}

/**
 * @brief Send a datasfusion message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_datasfusion_send_struct(mavlink_channel_t chan, const mavlink_datasfusion_t* datasfusion)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_datasfusion_send(chan, datasfusion->time, datasfusion->senseTime, datasfusion->gyrX, datasfusion->gyrY, datasfusion->gyrZ, datasfusion->accX, datasfusion->accY, datasfusion->accZ, datasfusion->magX, datasfusion->magY, datasfusion->magZ, datasfusion->temp, datasfusion->press, datasfusion->phi, datasfusion->the, datasfusion->psi, datasfusion->q0, datasfusion->q1, datasfusion->q2, datasfusion->q3, datasfusion->posN, datasfusion->posE, datasfusion->posD, datasfusion->speedN, datasfusion->speedE, datasfusion->speedD, datasfusion->WindN, datasfusion->WindE, datasfusion->WindD, datasfusion->ssa, datasfusion->aoa, datasfusion->gamma, datasfusion->alive);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataSFusion, (const char *)datasfusion, MAVLINK_MSG_ID_DataSFusion_MIN_LEN, MAVLINK_MSG_ID_DataSFusion_LEN, MAVLINK_MSG_ID_DataSFusion_CRC);
#endif
}

#if MAVLINK_MSG_ID_DataSFusion_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_datasfusion_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time, float senseTime, float gyrX, float gyrY, float gyrZ, float accX, float accY, float accZ, float magX, float magY, float magZ, float temp, float press, float phi, float the, float psi, float q0, float q1, float q2, float q3, float posN, float posE, float posD, float speedN, float speedE, float speedD, float WindN, float WindE, float WindD, float ssa, float aoa, float gamma, uint8_t alive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_float(buf, 8, senseTime);
    _mav_put_float(buf, 12, gyrX);
    _mav_put_float(buf, 16, gyrY);
    _mav_put_float(buf, 20, gyrZ);
    _mav_put_float(buf, 24, accX);
    _mav_put_float(buf, 28, accY);
    _mav_put_float(buf, 32, accZ);
    _mav_put_float(buf, 36, magX);
    _mav_put_float(buf, 40, magY);
    _mav_put_float(buf, 44, magZ);
    _mav_put_float(buf, 48, temp);
    _mav_put_float(buf, 52, press);
    _mav_put_float(buf, 56, phi);
    _mav_put_float(buf, 60, the);
    _mav_put_float(buf, 64, psi);
    _mav_put_float(buf, 68, q0);
    _mav_put_float(buf, 72, q1);
    _mav_put_float(buf, 76, q2);
    _mav_put_float(buf, 80, q3);
    _mav_put_float(buf, 84, posN);
    _mav_put_float(buf, 88, posE);
    _mav_put_float(buf, 92, posD);
    _mav_put_float(buf, 96, speedN);
    _mav_put_float(buf, 100, speedE);
    _mav_put_float(buf, 104, speedD);
    _mav_put_float(buf, 108, WindN);
    _mav_put_float(buf, 112, WindE);
    _mav_put_float(buf, 116, WindD);
    _mav_put_float(buf, 120, ssa);
    _mav_put_float(buf, 124, aoa);
    _mav_put_float(buf, 128, gamma);
    _mav_put_uint8_t(buf, 132, alive);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataSFusion, buf, MAVLINK_MSG_ID_DataSFusion_MIN_LEN, MAVLINK_MSG_ID_DataSFusion_LEN, MAVLINK_MSG_ID_DataSFusion_CRC);
#else
    mavlink_datasfusion_t *packet = (mavlink_datasfusion_t *)msgbuf;
    packet->time = time;
    packet->senseTime = senseTime;
    packet->gyrX = gyrX;
    packet->gyrY = gyrY;
    packet->gyrZ = gyrZ;
    packet->accX = accX;
    packet->accY = accY;
    packet->accZ = accZ;
    packet->magX = magX;
    packet->magY = magY;
    packet->magZ = magZ;
    packet->temp = temp;
    packet->press = press;
    packet->phi = phi;
    packet->the = the;
    packet->psi = psi;
    packet->q0 = q0;
    packet->q1 = q1;
    packet->q2 = q2;
    packet->q3 = q3;
    packet->posN = posN;
    packet->posE = posE;
    packet->posD = posD;
    packet->speedN = speedN;
    packet->speedE = speedE;
    packet->speedD = speedD;
    packet->WindN = WindN;
    packet->WindE = WindE;
    packet->WindD = WindD;
    packet->ssa = ssa;
    packet->aoa = aoa;
    packet->gamma = gamma;
    packet->alive = alive;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DataSFusion, (const char *)packet, MAVLINK_MSG_ID_DataSFusion_MIN_LEN, MAVLINK_MSG_ID_DataSFusion_LEN, MAVLINK_MSG_ID_DataSFusion_CRC);
#endif
}
#endif

#endif

// MESSAGE DataSFusion UNPACKING


/**
 * @brief Get field time from datasfusion message
 *
 * @return  System time at publication
 */
static inline uint64_t mavlink_msg_datasfusion_get_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field senseTime from datasfusion message
 *
 * @return  Time of data creation at sensor
 */
static inline float mavlink_msg_datasfusion_get_senseTime(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field gyrX from datasfusion message
 *
 * @return  Gyro X-Axis
 */
static inline float mavlink_msg_datasfusion_get_gyrX(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field gyrY from datasfusion message
 *
 * @return  Gyro Y-Axis
 */
static inline float mavlink_msg_datasfusion_get_gyrY(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field gyrZ from datasfusion message
 *
 * @return  Gyro Z-Axis
 */
static inline float mavlink_msg_datasfusion_get_gyrZ(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field accX from datasfusion message
 *
 * @return  Accelerometer X-Axis
 */
static inline float mavlink_msg_datasfusion_get_accX(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field accY from datasfusion message
 *
 * @return  Accelerometer Y-Axis
 */
static inline float mavlink_msg_datasfusion_get_accY(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field accZ from datasfusion message
 *
 * @return  Accelerometer Z-Axis
 */
static inline float mavlink_msg_datasfusion_get_accZ(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field magX from datasfusion message
 *
 * @return  Magnetometer X-Axis
 */
static inline float mavlink_msg_datasfusion_get_magX(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field magY from datasfusion message
 *
 * @return  Magnetometer Y-Axis
 */
static inline float mavlink_msg_datasfusion_get_magY(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field magZ from datasfusion message
 *
 * @return  Magnetometer Z-Axis
 */
static inline float mavlink_msg_datasfusion_get_magZ(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field temp from datasfusion message
 *
 * @return  Temperature
 */
static inline float mavlink_msg_datasfusion_get_temp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field press from datasfusion message
 *
 * @return  Barometric pressure
 */
static inline float mavlink_msg_datasfusion_get_press(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field phi from datasfusion message
 *
 * @return  Phi
 */
static inline float mavlink_msg_datasfusion_get_phi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field the from datasfusion message
 *
 * @return  Theta
 */
static inline float mavlink_msg_datasfusion_get_the(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field psi from datasfusion message
 *
 * @return  Psi
 */
static inline float mavlink_msg_datasfusion_get_psi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field q0 from datasfusion message
 *
 * @return  Quaternion 0
 */
static inline float mavlink_msg_datasfusion_get_q0(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  68);
}

/**
 * @brief Get field q1 from datasfusion message
 *
 * @return  Quaternion 1
 */
static inline float mavlink_msg_datasfusion_get_q1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  72);
}

/**
 * @brief Get field q2 from datasfusion message
 *
 * @return  Quaternion 2
 */
static inline float mavlink_msg_datasfusion_get_q2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  76);
}

/**
 * @brief Get field q3 from datasfusion message
 *
 * @return  Quaternion 3
 */
static inline float mavlink_msg_datasfusion_get_q3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  80);
}

/**
 * @brief Get field posN from datasfusion message
 *
 * @return  Position north estimation
 */
static inline float mavlink_msg_datasfusion_get_posN(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  84);
}

/**
 * @brief Get field posE from datasfusion message
 *
 * @return  Position east estimation
 */
static inline float mavlink_msg_datasfusion_get_posE(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  88);
}

/**
 * @brief Get field posD from datasfusion message
 *
 * @return  Position down estimation
 */
static inline float mavlink_msg_datasfusion_get_posD(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  92);
}

/**
 * @brief Get field speedN from datasfusion message
 *
 * @return  Speed north estimation
 */
static inline float mavlink_msg_datasfusion_get_speedN(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  96);
}

/**
 * @brief Get field speedE from datasfusion message
 *
 * @return  Speed east estimation
 */
static inline float mavlink_msg_datasfusion_get_speedE(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  100);
}

/**
 * @brief Get field speedD from datasfusion message
 *
 * @return  Speed down estimation
 */
static inline float mavlink_msg_datasfusion_get_speedD(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  104);
}

/**
 * @brief Get field WindN from datasfusion message
 *
 * @return  Wind north estimation
 */
static inline float mavlink_msg_datasfusion_get_WindN(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  108);
}

/**
 * @brief Get field WindE from datasfusion message
 *
 * @return  Wind east estimation
 */
static inline float mavlink_msg_datasfusion_get_WindE(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  112);
}

/**
 * @brief Get field WindD from datasfusion message
 *
 * @return  Wind down estimation
 */
static inline float mavlink_msg_datasfusion_get_WindD(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  116);
}

/**
 * @brief Get field ssa from datasfusion message
 *
 * @return  Sideslip angle estimation
 */
static inline float mavlink_msg_datasfusion_get_ssa(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  120);
}

/**
 * @brief Get field aoa from datasfusion message
 *
 * @return  Angle of attack estimation
 */
static inline float mavlink_msg_datasfusion_get_aoa(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  124);
}

/**
 * @brief Get field gamma from datasfusion message
 *
 * @return  Pathangle estimation
 */
static inline float mavlink_msg_datasfusion_get_gamma(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  128);
}

/**
 * @brief Get field alive from datasfusion message
 *
 * @return  Is message valid?
 */
static inline uint8_t mavlink_msg_datasfusion_get_alive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  132);
}

/**
 * @brief Decode a datasfusion message into a struct
 *
 * @param msg The message to decode
 * @param datasfusion C-struct to decode the message contents into
 */
static inline void mavlink_msg_datasfusion_decode(const mavlink_message_t* msg, mavlink_datasfusion_t* datasfusion)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    datasfusion->time = mavlink_msg_datasfusion_get_time(msg);
    datasfusion->senseTime = mavlink_msg_datasfusion_get_senseTime(msg);
    datasfusion->gyrX = mavlink_msg_datasfusion_get_gyrX(msg);
    datasfusion->gyrY = mavlink_msg_datasfusion_get_gyrY(msg);
    datasfusion->gyrZ = mavlink_msg_datasfusion_get_gyrZ(msg);
    datasfusion->accX = mavlink_msg_datasfusion_get_accX(msg);
    datasfusion->accY = mavlink_msg_datasfusion_get_accY(msg);
    datasfusion->accZ = mavlink_msg_datasfusion_get_accZ(msg);
    datasfusion->magX = mavlink_msg_datasfusion_get_magX(msg);
    datasfusion->magY = mavlink_msg_datasfusion_get_magY(msg);
    datasfusion->magZ = mavlink_msg_datasfusion_get_magZ(msg);
    datasfusion->temp = mavlink_msg_datasfusion_get_temp(msg);
    datasfusion->press = mavlink_msg_datasfusion_get_press(msg);
    datasfusion->phi = mavlink_msg_datasfusion_get_phi(msg);
    datasfusion->the = mavlink_msg_datasfusion_get_the(msg);
    datasfusion->psi = mavlink_msg_datasfusion_get_psi(msg);
    datasfusion->q0 = mavlink_msg_datasfusion_get_q0(msg);
    datasfusion->q1 = mavlink_msg_datasfusion_get_q1(msg);
    datasfusion->q2 = mavlink_msg_datasfusion_get_q2(msg);
    datasfusion->q3 = mavlink_msg_datasfusion_get_q3(msg);
    datasfusion->posN = mavlink_msg_datasfusion_get_posN(msg);
    datasfusion->posE = mavlink_msg_datasfusion_get_posE(msg);
    datasfusion->posD = mavlink_msg_datasfusion_get_posD(msg);
    datasfusion->speedN = mavlink_msg_datasfusion_get_speedN(msg);
    datasfusion->speedE = mavlink_msg_datasfusion_get_speedE(msg);
    datasfusion->speedD = mavlink_msg_datasfusion_get_speedD(msg);
    datasfusion->WindN = mavlink_msg_datasfusion_get_WindN(msg);
    datasfusion->WindE = mavlink_msg_datasfusion_get_WindE(msg);
    datasfusion->WindD = mavlink_msg_datasfusion_get_WindD(msg);
    datasfusion->ssa = mavlink_msg_datasfusion_get_ssa(msg);
    datasfusion->aoa = mavlink_msg_datasfusion_get_aoa(msg);
    datasfusion->gamma = mavlink_msg_datasfusion_get_gamma(msg);
    datasfusion->alive = mavlink_msg_datasfusion_get_alive(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DataSFusion_LEN? msg->len : MAVLINK_MSG_ID_DataSFusion_LEN;
        memset(datasfusion, 0, MAVLINK_MSG_ID_DataSFusion_LEN);
    memcpy(datasfusion, _MAV_PAYLOAD(msg), len);
#endif
}
